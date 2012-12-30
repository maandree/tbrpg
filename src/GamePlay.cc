// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "GamePlay.hpp"


/**
 * Text based roll playing game
 * 
 * DD2387 Program construction with C++
 * Laboration 3
 * 
 * @author  Mattias Andrée <maandree@kth.se>
 */
namespace tbrpg
{
  /**
   * Construction
   * 
   * @param  senario  The game senario
   */
  GamePlay::GamePlay(Senario& senario)
  {
    this->calc = Calculator();
    this->calc.rules = senario.rules;
    this->game = senario;
    this->players = {};
    this->next_player = 0;
    
    for (Character* player : senario.party.characters)
      {
	GameCharacter* gamechar = new GameCharacter();
	this->players.push_back(gamechar);
	
	gamechar->character = player;
	gamechar->area = &(senario.map.start);
      }
    
    this->attack_dice = Dice(senario.rules.attack_roll_dice,
			     senario.rules.attack_roll_die);
  }
  
  /**
   * Destructor
   */
  GamePlay::~GamePlay()
  {
    for (GameCharacter* player : this->players)
      delete player;
  }
  
  
  /**
   * Play the next round, it may be an AI's turn
   * 
   * @return  Whether there is a next turn
   */
  bool GamePlay::next()
  {
    std::vector<std::string> actions = {};
    std::vector<char (GamePlay::*)()> functions = {};
    
    #define __add(cmd, f)      		 \
      actions.push_back(cmd);            \
      functions.push_back(&GamePlay::f)
    
    __add("examine map", action_map);
    __add("examine area", action_area);
    __add("examine party", action_party);
    __add("examine inventory", action_inventory);
    __add("turn undead", action_turn_undead);
    __add("turn undead off", action_turn_undead_off);
    __add("find traps", action_find_traps);
    __add("find traps off", action_find_traps_off);
    __add("stealth", action_stealth);
    __add("stealth off", action_stealth_off);
    __add("pick pocket", action_pick_pocket);
    __add("disarm", action_disarm);
    __add("unlock", action_pick_lock);
    __add("bash", action_bash);
    __add("specials", action_specials);
    __add("talk", action_talk);
    __add("cast", action_cast);
    __add("attack", action_attack);
    __add("weapon", action_weapon);
    __add("quiver", action_quiver);
    __add("rest", action_rest);
    __add("!", action_redo);
    __add(".", action_wait);
    __add("quit", action_quit);
    
    // TODO special abilities
    // TODO quick spells
    // TODO travel
    
    #undef __add
    
    GameCharacter* player = this->players[this->next_player];
    
    if (player->turns == 0)
      for (;;)
	{
	  std::stringstream ss;
	  ss << "\033[01;3" << (char)('0' + player->character->record.colour) << 'm'
	     << player->character->record.name
	     << "\033[21;39m:: ";
	  
	  int index = promptIndex(ss.str(), actions);
	  if (index >= 0)
	    {
	      if (functions[index] != &GamePlay::action_redo)
		this->last_function = functions[index];
	      char r = (this->*functions[index])();
	      std::flush(std::cout);
	      if (r == 2)
		continue;
	      if (r == 0)
		return false;
	    }
	  else
	    std::flush(std::cout << "Type . to wait one turn" << std::endl);
	}
    
    if ((player->turns))
      player->turns--;
    this->next_player++;
    if (this->next_player == (long)(this->players.size()))
      {
	this->next_player = 0;
	for (GameCharacter* p : this->players)
	  if ((p->character->fatigue += 1) >= 24 * 60)
	    std::flush(std::cout << "033[01;3" << p->character->record.colour << "m"
				 << p->character->record.name
				 << "\033[21;39m is tired."
				 << std::endl);
      }
    return true;
  }
  
  
  /**
   * Gets whether the party is gathered
   * 
   * @return  Whether the party is gathered
   */
  bool GamePlay::gathered() const
  {
    MapMinor* area = this->players[0]->area;
    
    for (size_t i = 1, n = this->players.size(); i < n; i++)
      if (this->players[i]->area != area)
	return false;
    
    return true;
  }
  
  
  /**
   * Action: quit
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_quit()
  {
    return 0;
  }
  
  /**
   * Action: wait one turn
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_wait()
  {
    return 1;
  }
  
  /**
   * Action: redo last action by any party member
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_redo()
  {
    return (this->*(this->last_function))();
  }
  
  /**
   * Action: rest
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_rest()
  {
    int monstercount = 0;
    for (Creature& creature : this->players[this->next_player]->area->creatures)
      if (creature.hostile && creature.alive && (((Character&)creature).alive == 1))
	monstercount++;
    
    if (monstercount > 0)
      std::cout << "You may not rest while in combat." << std::endl;
    else if (gathered() == false)
      std::cout << "You must gather you party before resting." << std::endl;
    else if (this->players[this->next_player]->stealth_on)
      std::cout << "You will have to turn off Stealth Mode." << std::endl;
    else if (this->players[this->next_player]->find_traps_on)
      std::cout << "You will have to turn off Find Traps." << std::endl;
    else if (this->players[this->next_player]->turn_undead_on)
      std::cout << "You will have to turn off Turn Undead." << std::endl;
    else
      if (this->players[0]->area->rest())
	{
          if (this->players[0]->area->may_rest == false)
	    {
              std::flush(std::cout << "May not rest here, either find an inn or rest outside." << std::endl);
	      std::flush(std::cerr << "\033[02msenario error: may_rest flag is of, but rest was allowed.\033[22m" << std::endl);
	      return 2;
	    }
	  std::cout << "Your party have slept for 8 hours (48 rounds)." << std::endl;
	  for (GameCharacter* player : this->players)
	    {
	      player->character->hit_points += (480 / this->game.rules.rest_healing_turns)
		                                    * this->game.rules.rest_healing;
	      if (player->character->hit_points > player->character->record.hit_points)
		player->character->hit_points = player->character->record.hit_points;
	      player->character->fatigue = 0;
	      
	      player->character->record.spells.memorised = player->character->record.spells.selected;
	    }
	}
    return 2;
  }
  
  /**
   * Action: select ammunition to use from the quiver
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_quiver()
  {
    this->players[this->next_player]->selectQuiver();
    return 2;
  }
  
  /**
   * Action: select weapon to use from the quick weapons
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_weapon()
  {
    this->players[this->next_player]->selectWeapon();
    return 2;
  }
  
  /**
   * Action: attack
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_attack()
  {
    GameCharacter* player = this->players[this->next_player];
    
    if (player->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (player->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::vector<Creature> attackable = std::vector<Creature>();
    
    for (Creature& creature : player->area->creatures)
      if (creature.hostile && creature.alive && (((Character&)creature).alive == 1))
	attackable.push_back(creature);
    
    if (attackable.size() == 0)
      {
	std::cout << "There are no hostiles nearby." << std::endl;
	return 2;
      }
    
    long target = 0;
    
    if (attackable.size() > 1)
      {
	std::vector<std::string> targets = std::vector<std::string>();
	for (Creature& creature : attackable)
	  targets.push_back(creature.record.name);
	
	target = promptMenu("Select target:", targets);
      }
    
    if (target < 0)
      return 2;
    
    // TODO right hand weapon support
    
    Weapon* weapon = player->character->record.inventory.left_hand[player->weapon];
    if (weapon == nullptr)
      {
	if (player->character->record.inventory.right_hand == nullptr)
	  weapon = &(player->character->record.prestige[0].default_one_hand); /* TODO document that the first prestige is used*/
	else
	  weapon = &(player->character->record.prestige[0].default_two_hands);
      }
    player->turns += weapon->speed_factor;
    
    Ammunition* quiver = nullptr;
    if (*weapon >= PROTOTYPE(RangedWeapon))
      {
	quiver = player->character->record.inventory.quiver[player->quiver];
	if ((quiver == nullptr) || ((quiver->usable_with <= *weapon) == false))
	  {
	    std::cout << "You need to select a quiver for your weapon" << std::endl;
	    return 2;
	  }
      }
    
    Weapon* _targetweapon = attackable[target].record.inventory.left_hand[0]; /* TODO dual weapon */
    Weapon targetweapon = _targetweapon != nullptr ? *_targetweapon
                        : attackable[target].record.inventory.right_hand != nullptr
                        ? attackable[target].record.prestige[0].default_one_hand
                        : attackable[target].record.prestige[0].default_two_hands;
    
    DamageType damagetype = weapon->damage_type[0];
    if (weapon->damage_type.size() > 0)
      {
	Die dmgtypedie = Die(weapon->damage_type.size());
	damagetype = weapon->damage_type[(long)(dmgtypedie.roll())];
      }
    
    Item* diminish = nullptr;
    if ((quiver))
      diminish = quiver;
    else if (weapon->quantity_limit > 1) /* throw weapon */
      diminish = weapon;
    
    if ((diminish))
      if (--(diminish->quantity) == 0)
	{
	  if ((quiver))
	    {
	      player->character->record.inventory.quiver[player->quiver] = nullptr;
	      std::cout << "You have now run out of your selected quiver." << std::endl;
	    }
	  else
	    {
	      player->character->record.inventory.left_hand[player->weapon] = nullptr;
	      std::cout << "You have now run out of your selected throwing weapon." << std::endl;
	    }
	}
    
    int backstabMultiplier = 1;
    if ((player->stealth_on) && weapon->melee)
    {
      player->stealth_on = false;
      backstabMultiplier *= this->calc.getBackstabMultiplier(*(player->character));
    }
    
    int totaldamage = 0;
    int attacks = this->calc.getHalfAttacks(*(player->character), *weapon);
    
    while (attacks >= 0)
      {
	int thac0 = this->calc.getTHAC0(*(player->character), *weapon, quiver);
	int ac = this->calc.getArmourClass(attackable[target], damagetype, !(weapon->melee), targetweapon);
	int rollmod = 0;
	
	if (player->character->record.racial_enemy != nullptr)
	  {
	    if (attackable[target].record.race >= *(player->character->record.racial_enemy))
	      {
		rollmod += 4; /* TODO make racial enemy bonus/penality a customisable rule */
		std::cout << "Racial enemy bonus" << std::endl;
	      }
	    else
	      {
		rollmod -= 4;
		std::cout << "Racial enemy penality" << std::endl;
 	      }
	  }
	
	int roll = this->attack_dice.roll();
	std::cout << "Attack roll: " << roll << " versus " << thac0 << " - " << ac << ": ";
	
	if (roll <= this->game.rules.critical_miss)
	  {
	    std::cout << "Critical miss" << std::endl;
	    player->turns += 10; /* TODO make customisable */
	    player->stealth_on = false;
	    return 1;
	  }
	
	bool hit = roll + rollmod >= thac0 - ac;
	int multiplier = (roll >= this->game.rules.critical_hit) ? 2 : 1; /* TODO make customisable */
	if (multiplier == 2)
	  {
	    std::cout << "Critical hit" << std::endl;
	    hit = true;
	  }
	else if (hit)
	  std::cout << "Hit" << std::endl;
	else
	  std::cout << "Miss" << std::endl;
	multiplier *= backstabMultiplier;
	
	Dice damagedice = Dice(weapon->damage_dice, weapon->damage_die);
	int damage = this->calc.getDamageBonus(*(player->character), *weapon, quiver);
	std::cout << "Damage: " << damage << std::endl;
	totaldamage += damage;
      }
    
    std::cout << "Total damage: " << totaldamage << std::endl;
    attackable[target].hit_points -= totaldamage;
    if (attackable[target].hit_points <= -(this->game.rules.critical_death))
      {
	((Character&)(attackable[target])).alive = -1;
	std::cout << "Critical death inflicated on target." << std::endl;
      }
    else if (attackable[target].hit_points <= 0)
      {
	((Character&)(attackable[target])).alive = 0;
	std::cout << "Death inflicated on target." << std::endl;
      }
    else
      return 1;
    
    #define __drop(X)				\
      if (X != nullptr)				\
	{					\
	  player->area->items.push_back(X);	\
	  X = nullptr;				\
	}//
    
    #define __drops(X)					\
      for (size_t i = 0, n = X.size(); i < n; i++)	\
	__drop(X[i])
    
    __drops(attackable[target].record.inventory.left_hand);
    __drop(attackable[target].record.inventory.right_hand);
    __drops(attackable[target].record.inventory.quiver);
    __drops(attackable[target].record.inventory.quick_items);
    __drop(attackable[target].record.inventory.headgear);
    __drop(attackable[target].record.inventory.amulet);
    __drops(attackable[target].record.inventory.rings);
    __drop(attackable[target].record.inventory.body);
    __drop(attackable[target].record.inventory.gauntlets);
    __drop(attackable[target].record.inventory.girdle);
    __drop(attackable[target].record.inventory.boots);
    __drop(attackable[target].record.inventory.cloak);
    __drops(attackable[target].record.inventory.personal);
    
    #undef __drop
    #undef __drops
    
    return 1;
  }
  
  /**
   * Action: cast non-quick spell
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_cast()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: talk
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_talk()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::vector<Creature> talkable = std::vector<Creature>();
    for (Creature& creature : this->players[this->next_player]->area->creatures)
      if ((creature.hostile == false) && creature.alive && (((Character&)creature).alive == 1))
	talkable.push_back(creature);
    
    if (talkable.size() == 0)
      {
	std::cout << "There is no one nearby to talk to." << std::endl;
	return 2;
      }
    
    long target = 0;
    
    if (talkable.size() > 1)
      {
	std::vector<std::string> targets = std::vector<std::string>();
	for (Creature& creature : talkable)
	  targets.push_back(creature.record.name);
	
	target = promptMenu("Select target:", targets);
      }
    
    if (target < 0)
      return 2; 
    
    std::vector<Character*> here = std::vector<Character*>();
    MapMinor* location = this->players[this->next_player]->area;
    
    for (GameCharacter* p : this->players)
      if (p->area == location)
	here.push_back(p->character);
    
    talkable[target].interact(here);
    
    return 1;
  }
  
  /**
   * Action: list special usable abilities
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_specials()
  {
    std::cout << "You have no special abilties." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: bash a lock
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_bash()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::vector<Lockable*> locks = std::vector<Lockable*>();
    std::vector<std::string> names = std::vector<std::string>();
    
    for (Entrance& entrance : this->players[this->next_player]->area->connections)
      if (entrance >= PROTOTYPE(Door))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Door*>(&entrance)));
	  std::stringstream ss;
	  ss << "Door (" << entrance.direction << ")";
	  names.push_back(ss.str());
	}
    
    for (Item* item : this->players[this->next_player]->area->items)
      if (*item >= PROTOTYPE(EnvironmentContainer))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Item*>(item)));
	  std::stringstream ss;
	  ss << "Container (" << item->name << ")";
	  names.push_back(ss.str());
	}
    
    long target = promptMenu("Select target:", names);
    if (target < 0)
      return 2;
    this->players[this->next_player]->turns += 1; /* TODO document time and make customisable */
    
    Lockable* lock = locks[target];
    
    if (lock->locked == false)
      std::cout << "Not locked." << std::endl;
    else
      {
	/* TODO document that only response you get is the roll and modifer, not the level or possibility */
	int roll = this->attack_dice.roll();
	int level = lock->bash_level;
	float mod = this->calc.getBashing(*(this->players[this->next_player]->character));
	bool possible = lock->bashable;
	int total = (int)(roll * mod + 0.5);
	bool success = possible && (total >= level);
	
	std::cout << "Roll: " << roll << std::endl;
	std::cout << "Multiplier: " << (int)(mod * 100. + 0.5) << " %" << std::endl;
	std::cout << "Total: " << total << std::endl;
	
	std::cout << (success ? "Success." : "Failure.") << std::endl;
	
	lock->locked = success;
      }
    
    return 1;
  }
  
  /**
   * Action: pick a lock
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_pick_lock()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: disarm a trap
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_disarm()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: pick pocket
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_pick_pocket()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: turn on stealth mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_stealth()
  {
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->stealth_on == false)
      std::cout << "You already have Stealth activated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: turn off stealth mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_stealth_off()
  {
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->stealth_on == false)
      std::cout << "You already have Stealth Mode deactivated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: turn on find traps mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_find_traps()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You already have Find Traps activated." << std::endl;
	return 2;
      }
    std::cout << "Not implement..." << std::endl; // TODO
    return 1;
  }
  
  /**
   * Action: turn off find traps mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_find_traps_off()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->find_traps_on == false)
      std::cout << "You already have Find Traps deactivated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: turn on turn undead mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_turn_undead()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You already have Turn Undead activated." << std::endl;
	return 2;
      }
    std::cout << "Not implement..." << std::endl; // TODO
    return 1;
  }
  
  /**
   * Action: turn off turn undead mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_turn_undead_off()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    
    if (this->players[this->next_player]->turn_undead_on == false)
      std::cout << "You already have Turn Undead deactivated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: examine inventory
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_inventory()
  {
    if (this->players[this->next_player]->stealth_on)
      {
	std::cout << "You will have to turn off Stealth Mode." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->find_traps_on)
      {
	std::cout << "You will have to turn off Find Traps." << std::endl;
	return 2;
      }
    if (this->players[this->next_player]->turn_undead_on)
      {
	std::cout << "You will have to turn off Turn Undead." << std::endl;
	return 2;
      }
    
    std::cout << "Not implement..." << std::endl; // TODO
    
    this->players[this->next_player]->turns += 10;
    return 1;
  }
  
  /**
   * Action: examine party
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_party()
  {
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: examine world map
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_map()
  {
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
  }
  
  /**
   * Action: examine area
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_area()
  {
    /*
    std::cout << this->position->description << std::endl << std::endl;
    
    for (Entrance& connection : this->position->connections)
      std::cout << connection.direction << " → " << connection.description << std::endl;
    if (this->position->connections.size() > 0)
      std::cout << std::endl;
    
    for (Road& road : this->position->roads)
      std::cout << road.direction << std::endl;
    if (this->position->roads.size() > 0)
      std::cout << std::endl;
    
    for (Item& item : this->position->items)
      std::cout << item.name << std::endl;
    if (this->position->items.size() > 0)
      std::cout << std::endl;
    
    for (Creature& creature : this->position->creatures)
      std::cout << creature.record.name << std::endl;
    if (this->position->creatures.size() > 0)
      std::cout << std::endl;
    
    std::flush(std::cout);
    */
    return 2; // TODO
  }
  
}

