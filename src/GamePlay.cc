// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
  #define __forbid_stealth()							\
    if (this->players[0][this->next_player]->stealth_on)			\
      {										\
	std::cout << "You will have to turn off Stealth Mode." << std::endl;	\
	return 2;								\
      }//
      
  #define __forbid_find_trap()							\
    if (this->players[0][this->next_player]->find_traps_on)			\
      {										\
	std::cout << "You will have to turn off Find Traps." << std::endl; 	\
	return 2;								\
      }//
      
  #define __forbid_turn_undead()						\
    if (this->players[0][this->next_player]->turn_undead_on)			\
      {										\
	std::cout << "You will have to turn off Turn Undead." << std::endl;	\
	return 2;								\
      }//
      
  #define __forbid_bard_song()							\
    if (this->players[0][this->next_player]->bard_song_on)			\
      {										\
	std::cout << "You will have to turn off Bard Song." << std::endl;	\
	return 2;								\
      }//
  
  
  
  /**
   * Construction
   * 
   * @param  senario  The game senario
   */
  GamePlay::GamePlay(Senario* senario)
  {
    this->calc = new Calculator();
    if ((senario))
      this->calc->rules = senario->rules;
    this->game = senario;
    this->players = new std::vector<GameCharacter*>();
    this->next_player = 0;
  
    if ((senario))
      for (Character* player : senario->party->characters)
	{
	  GameCharacter* gamechar = new GameCharacter();
	  this->players->push_back(gamechar);
	  
	  gamechar->character = player;
	  gamechar->area = senario->map->start;
	}
    
    if ((senario))
      this->attack_dice = new Dice(senario->rules->attack_roll_dice,
				   senario->rules->attack_roll_die);
    else
      this->attack_dice = nullptr;
  }
  
  
  /**
   * Destructor
   */
  GamePlay::~GamePlay()
  {
    for (GameCharacter* player : *(this->players))
      delete player;
    delete this->players;
    delete this->calc;
    if ((this->attack_dice))
      delete this->attack_dice;
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
    __add("bard song", action_bard_song);
    __add("bard song off", action_bard_song_off);
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
    __add("travel", action_travel);
    __add("!", action_redo);
    __add(".", action_wait);
    __add("quit", action_quit);
    
    // TODO special abilities
    // TODO quick spells
    // TODO cheats (obviously)
    
    #undef __add
    
    GameCharacter* player = (*(this->players))[this->next_player];
    
    if ((player->turns == 0) && (player->character->alive == 1))
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
	      break;
	    }
	  else
	    std::flush(std::cout << "Type . to wait one turn" << std::endl);
	}
    
    (*(this->players))[this->next_player]->character->fatigue++;
    if ((player->turns))
      player->turns--;
    if (++(this->next_player) == (long)(this->players->size()))
      {
	this->next_player = 0;
	for (GameCharacter* p : *(this->players))
	  if ((p->character->fatigue += 1) >= 24 * 60)
	    std::flush(std::cout << "033[01;3" << (char)((int)'0' + p->character->record.colour) << "m"
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
    MapMinor* area = this->players[0][0]->area;
    
    for (size_t i = 1, n = this->players->size(); i < n; i++)
      if (this->players[0][i]->area != area)
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
    for (Creature* creature : (*(this->players))[this->next_player]->area->creatures)
      if (creature->hostile && creature->alive && (dynamic_cast<Character*>(creature)->alive == 1))
	monstercount++;
    
    if (monstercount > 0)
      std::cout << "You may not rest while in combat." << std::endl;
    else if (gathered() == false)
      std::cout << "You must gather you party before resting." << std::endl;
    else if (this->players[0][this->next_player]->stealth_on)
      std::cout << "You will have to turn off Stealth Mode." << std::endl;
    else if (this->players[0][this->next_player]->find_traps_on)
      std::cout << "You will have to turn off Find Traps." << std::endl;
    else if (this->players[0][this->next_player]->turn_undead_on)
      std::cout << "You will have to turn off Turn Undead." << std::endl;
    else if (this->players[0][this->next_player]->bard_song_on)
      std::cout << "You will have to turn off Bard Song." << std::endl;
    else
      if (this->players[0][0]->area->rest())
	{
          if (this->players[0][0]->area->may_rest == false)
	    {
              std::flush(std::cout << "May not rest here, either find an inn or rest outside." << std::endl);
	      std::flush(std::cerr << "\033[02msenario error: may_rest flag is of, but rest was allowed.\033[22m" << std::endl);
	      return 2;
	    }
	  std::cout << "Your party have slept for 8 hours (48 rounds)." << std::endl;
	  for (GameCharacter* player : this->players[0])
	    {
	      player->character->hit_points += (480 / this->game->rules->rest_healing_turns)
		                                    * this->game->rules->rest_healing;
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
    this->players[0][this->next_player]->selectQuiver();
    return 2;
  }
  
  /**
   * Action: select weapon to use from the quick weapons
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_weapon()
  {
    this->players[0][this->next_player]->selectWeapon();
    return 2;
  }
  
  /**
   * Action: attack
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_attack()
  {
    GameCharacter* player = this->players[0][this->next_player];
    
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::vector<Creature*> attackable = std::vector<Creature*>();
    
    for (Creature* creature : player->area->creatures)
      if (creature->hostile && creature->alive && (dynamic_cast<Character*>(creature)->alive == 1))
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
	for (Creature* creature : attackable)
	  targets.push_back(creature->record.name);
	
	target = promptMenu("Select target:", targets);
      }
    
    if (target < 0)
      return 2;
    
    // TODO right hand weapon support
    
    Weapon* weapon = player->character->record.inventory.left_hand[player->weapon];
    if (weapon == nullptr)
      {
	if (player->character->record.inventory.right_hand == nullptr)
	  weapon = &(player->character->record.prestige[0]->default_one_hand); /* TODO document that the first prestige is used*/
	else
	  weapon = &(player->character->record.prestige[0]->default_two_hands);
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
    
    Weapon* _targetweapon = attackable[target]->record.inventory.left_hand[0]; /* TODO dual weapon */
    Weapon& targetweapon = _targetweapon != nullptr ? *_targetweapon
      			 : (attackable[target]->record.inventory.right_hand != nullptr
                         ? attackable[target]->record.prestige[0]->default_one_hand
			 : attackable[target]->record.prestige[0]->default_two_hands);
    
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
      backstabMultiplier *= this->calc->getBackstabMultiplier(*(player->character));
    }
    
    int totaldamage = 0;
    int attacks = this->calc->getHalfAttacks(*(player->character), *weapon);
    
    while (attacks >= 0)
      {
	int thac0 = this->calc->getTHAC0(*(player->character), *weapon, quiver);
	int ac = this->calc->getArmourClass(*(attackable[target]), damagetype, !(weapon->melee), targetweapon);
	int rollmod = 0;
	
	if (player->character->record.racial_enemy != nullptr)
	  {
	    if (*(attackable[target]->record.race) >= *(player->character->record.racial_enemy))
	      {
		rollmod += 4; /* XXX make racial enemy bonus/penality a customisable rule */
		std::cout << "Racial enemy bonus" << std::endl;
	      }
	    else
	      {
		rollmod -= 4;
		std::cout << "Racial enemy penality" << std::endl;
 	      }
	  }
	
	int roll = this->attack_dice->roll();
	std::cout << "Attack roll: " << roll << " versus " << thac0 << " - " << ac << ": ";
	
	if (roll <= this->game->rules->critical_miss)
	  {
	    std::cout << "Critical miss" << std::endl;
	    player->turns += 10; /* XXX make customisable */
	    player->stealth_on = false;
	    return 1;
	  }
	
	bool hit = roll + rollmod >= thac0 - ac;
	int multiplier = (roll >= this->game->rules->critical_hit) ? 2 : 1; /* XXX make customisable */
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
	int damage = this->calc->getDamageBonus(*(player->character), *weapon, quiver);
	std::cout << "Damage: " << damage << std::endl;
	totaldamage += damage;
      }
    
    std::cout << "Total damage: " << totaldamage << std::endl;
    attackable[target]->hit_points -= totaldamage;
    if (attackable[target]->hit_points <= -(this->game->rules->critical_death)) /* TODO delete nealy and not resurrectable */
      {
	dynamic_cast<Character*>(attackable[target])->alive = -1;
	std::cout << "Critical death inflicated on target." << std::endl;
      }
    else if (attackable[target]->hit_points <= 0)
      {
	dynamic_cast<Character*>(attackable[target])->alive = 0;
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
    
    __drops(attackable[target]->record.inventory.left_hand);
    __drop (attackable[target]->record.inventory.right_hand);
    __drops(attackable[target]->record.inventory.quiver);
    __drops(attackable[target]->record.inventory.quick_items);
    __drop (attackable[target]->record.inventory.headgear);
    __drop (attackable[target]->record.inventory.amulet);
    __drops(attackable[target]->record.inventory.rings);
    __drop (attackable[target]->record.inventory.body);
    __drop (attackable[target]->record.inventory.gauntlets);
    __drop (attackable[target]->record.inventory.girdle);
    __drop (attackable[target]->record.inventory.boots);
    __drop (attackable[target]->record.inventory.cloak);
    __drops(attackable[target]->record.inventory.personal);
    
    #undef __drop
    #undef __drops
    
    // TODO gain experience add new levels
    
    return 1;
  }
  
  /**
   * Action: cast non-quick spell
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_cast()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::cout << "Not implement..." << std::endl; // TODO cast
    return 2;
  }
  
  /**
   * Action: talk
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_talk()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::vector<Creature*> talkable = std::vector<Creature*>();
    for (Creature* creature : this->players[0][this->next_player]->area->creatures)
      if ((creature->hostile == false) && creature->alive && (dynamic_cast<Character*>(creature)->alive == 1))
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
	for (Creature* creature : talkable)
	  targets.push_back(creature->record.name);
	
	target = promptMenu("Select target:", targets);
      }
    
    if (target < 0)
      return 2; 
    
    std::vector<Character*> here = std::vector<Character*>();
    MapMinor* location = this->players[0][this->next_player]->area;
    
    for (GameCharacter* p : this->players[0])
      if (p->area == location)
	here.push_back(p->character);
    
    talkable[target]->interact(here);
    
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
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::vector<Lockable*> locks = std::vector<Lockable*>();
    std::vector<std::string> names = std::vector<std::string>();
    
    for (Entrance* entrance : this->players[0][this->next_player]->area->connections)
      if (*entrance >= PROTOTYPE(Door))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Door*>(entrance)));
	  std::stringstream ss;
	  ss << "Door (" << entrance->direction << ")";
	  names.push_back(ss.str());
	}
    
    for (Item* item : this->players[0][this->next_player]->area->items)
      if (*item >= PROTOTYPE(EnvironmentContainer))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Item*>(item)));
	  std::stringstream ss;
	  ss << "Container (" << item->name << ")";
	  names.push_back(ss.str());
	}
    
    if (names.size() == 0)
      {
	std::cout << "There is nothing to bash." << std::endl;
	return 2;
      }
    
    long target = promptMenu("Select target:", names);
    if (target < 0)
      return 2;
    this->players[0][this->next_player]->turns += 1; /* XXX document time and make customisable */
    
    Lockable* lock = locks[target];
    
    if (lock->locked == false)
      std::cout << "Not locked." << std::endl;
    else if (lock->bashable == false)
      {
	std::cout << "Not possible." << std::endl;
	return 2;
      }
    else
      {
	int roll = this->attack_dice->roll();
	int level = lock->bash_level;
	float mod = this->calc->getBashing(*(this->players[0][this->next_player]->character));
	int total = (int)(roll * mod + 0.5);
	bool success = total >= level;
	
	std::cout << "Roll: " << roll << std::endl;
	std::cout << "Multiplier: " << (int)(mod * 100. + 0.5) << " %" << std::endl;
	std::cout << "Total: " << total << std::endl;
	/* do not print level */
	
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
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::vector<Lockable*> locks = std::vector<Lockable*>();
    std::vector<std::string> names = std::vector<std::string>();
    
    for (Entrance* entrance : this->players[0][this->next_player]->area->connections)
      if (*entrance >= PROTOTYPE(Door))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Door*>(entrance)));
	  std::stringstream ss;
	  ss << "Door (" << entrance->direction << ")";
	  names.push_back(ss.str());
	}
    
    for (Item* item : this->players[0][this->next_player]->area->items)
      if (*item >= PROTOTYPE(EnvironmentContainer))
	{
	  locks.push_back(dynamic_cast<Lockable*>(static_cast<Item*>(item)));
	  std::stringstream ss;
	  ss << "Container (" << item->name << ")";
	  names.push_back(ss.str());
	}
    
    if (names.size() == 0)
      {
	std::cout << "There is nothing to pick." << std::endl;
	return 2;
      }
    
    long target = promptMenu("Select target:", names);
    if (target < 0)
      return 2;
    this->players[0][this->next_player]->turns += 1; /* XXX document time and make customisable */
    
    Lockable* lock = locks[target];
    
    if (lock->locked == false)
      std::cout << "Not locked." << std::endl;
    else if (lock->pickable == false)
      {
	std::cout << "Not possible." << std::endl;
	return 2;
      }
    else
      {
	int roll = this->attack_dice->roll();
	int level = lock->pick_level;
	float mod = this->calc->getPicking(*(this->players[0][this->next_player]->character));
	int total = (int)(roll * mod + 0.5);
	bool success = total >= level;
	
	std::cout << "Roll: " << roll << std::endl;
	std::cout << "Multiplier: " << (int)(mod * 100. + 0.5) << " %" << std::endl;
	std::cout << "Total: " << total << std::endl;
	/* do not print level */
	
	std::cout << (success ? "Success." : "Failure.") << std::endl;
	
	lock->locked = success;
      }
    
    return 1;
  }
  
  /**
   * Action: disarm a trap
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_disarm()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::cout << "Not implement..." << std::endl; // TODO disarm
    return 2;//...
  }
  
  /**
   * Action: pick pocket
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_pick_pocket()
  {
    long slot = -1;
    
    {
      long _slot = 0;
      for (Item* item : this->players[0][this->next_player]->character->record.inventory.personal)
	if (item == nullptr)
	  {
	    slot = _slot;
	    break;
	  }
	else
	  _slot++;
    }
    
    if (slot < 0)
      {
	std::cout << "Your inventory is full." << std::endl;
	return 2;
      }
    
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::vector<Creature*> pickable = std::vector<Creature*>();
    for (Creature* creature : this->players[0][this->next_player]->area->creatures)
      if ((creature->hostile == false) && creature->alive && (dynamic_cast<Character*>(creature)->alive == 1))
	pickable.push_back(creature);
    
    if (pickable.size() == 0)
      {
	std::cout << "There is no one nearby to pick pocket." << std::endl;
	return 2;
      }
    
    long target = 0;
    
    if (pickable.size() > 1)
      {
	std::vector<std::string> targets = std::vector<std::string>();
	for (Creature* creature : pickable)
	  targets.push_back(creature->record.name);
	
	target = promptMenu("Select target:", targets);
      }
    
    if (target < 0)
      return 2;
    
    if (pickable[target]->pickable == false)
      {
	std::cout << "Not possible." << std::endl;
	return 2;
      }
    
    int level = pickable[target]->pick_level;
    int roll = this->attack_dice->roll();
    float mod = this->calc->getStealing(*(this->players[0][this->next_player]->character));
    
    if ((int)(roll * mod + 0.5) >= level)
      {
	Item* stole = pickable[target]->pickPocket();
	if ((stole))
	  {
	    std::cout << "Stole: " << stole->name << std::endl;
	    this->players[0][this->next_player]->character->record.inventory.personal[slot] = stole;
	  }
	else
	  std::cout << "Target has noting to steal." << std::endl;
      }
    else
      {
	if ((pickable[target]->hostile = pickable[target]->pick_hostile))
	  std::cout << "Failure: Target became hostile." << std::endl;
	else
	  std::cout << "Failure: Target remains friendly." << std::endl;
      }
    
    return 1;
  }
  
  /**
   * Action: turn on stealth mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_stealth()
  {
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    if (this->players[0][this->next_player]->stealth_on == false)
      std::cout << "You already have Stealth activated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO stealth
    return 2;
  }
  
  /**
   * Action: turn off stealth mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_stealth_off()
  {
    if (this->players[0][this->next_player]->stealth_on == false)
      std::cout << "You already have Stealth Mode deactivated." << std::endl;
    else
      std::cout << "Not implemented..." << std::endl; // TODO stealth off
    return 2;
  }
  
  /**
   * Action: turn on find traps mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_find_traps()
  {
    __forbid_stealth();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    if (this->players[0][this->next_player]->find_traps_on)
      {
	std::cout << "You already have Find Traps activated." << std::endl;
	return 2;
      }
    std::cout << "Not implemented..." << std::endl; // TODO find traps
    return 2;//1;
  }
  
  /**
   * Action: turn off find traps mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_find_traps_off()
  {
    if (this->players[0][this->next_player]->find_traps_on == false)
      std::cout << "You already have Find Traps deactivated." << std::endl;
    else
      std::cout << "Not implement..." << std::endl; // TODO find traps off
    return 2;
  }
  
  /**
   * Action: turn on turn undead mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_turn_undead()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_bard_song();
    
    if (this->players[0][this->next_player]->turn_undead_on)
      {
	std::cout << "You already have Turn Undead activated." << std::endl;
	return 2;
      }
    std::cout << "Not implemented..." << std::endl; // TODO turn undead
    return 2;//1;
  }
  
  /**
   * Action: turn off turn undead mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_turn_undead_off()
  {
    if (this->players[0][this->next_player]->turn_undead_on == false)
      std::cout << "You already have Turn Undead deactivated." << std::endl;
    else
      std::cout << "Not implemented..." << std::endl; // TODO turn undead off
    return 2;
  }
  
  /**
   * Action: turn on bard song mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_bard_song()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    
    if (this->players[0][this->next_player]->bard_song_on)
      {
	std::cout << "You already have Bard Song activated." << std::endl;
	return 2;
      }
    std::cout << "Not implemented..." << std::endl; // TODO bard song
    return 2;//1;
  }
  
  /**
   * Action: turn off bard song mode
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_bard_song_off()
  {
    if (this->players[0][this->next_player]->bard_song_on == false)
      std::cout << "You already have Bard Song deactivated." << std::endl;
    else
      std::cout << "Not implemented..." << std::endl; // TODO bard song off
    return 2;
  }
  
  /**
   * Action: examine inventory
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_inventory()
  {
    __forbid_stealth();
    __forbid_find_trap();
    __forbid_turn_undead();
    __forbid_bard_song();
    
    std::cout << "Not implement..." << std::endl; // TODO inventory
    
    this->players[0][this->next_player]->turns += 10; /* XXX make customisable */
    return 1;
  }
  
  /**
   * Action: examine party
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_party()
  {
    std::cout << "Reputation: " << this->game->party->reputation << std::endl << std::endl;
    
    std::cout << "Party members:" << std::endl;
    long pindex = 0;
    for (GameCharacter* character : *(this->players))
      {
	Character* c = character->character;
	std::cout << "\033[";
	if (pindex++ == this->next_player)
	  std::cout << "01;";
	std::cout << "3" << (char)((int)'0' + c->record.colour) << "m"
		  << c->record.name << "\033[39m ";
	
	if (c->protagonist)  std::cout << "(P)";
	if (c->alive == 0)   std::cout << "(D)";
	if (c->alive < 0)    std::cout << "(DD)";
	
	std::cout << " (" << c->hit_points << "/" << c->record.hit_points << ")";
	std::cout << "\033[21m" << std::endl;
	/*
	  bool turn_undead_on = character->turn_undead_on;
	  bool find_traps_on = character->find_traps_on;
	  bool stealth_on = character->stealth_on;
	  bool bard_song_on = character->bard_song_on;
	  c->fatigue
	  c->extra_attacks
	*/
	/*
	  c->record. .....
	  std::string name;
	  std::string biography;
	  char alignment;
	  std::string portrait;
	  bool female;
	  std::vector<int> experience;
	  std::vector<char> level;
	  std::vector<bool> class_abondoned;
	  std::unordered_map<WeaponGroup, int> proficiencies;
	  std::vector<Spell> affected_by;
	  AbilityBonus abilities;
	  SpellBook spells;
	  Race race;
	  Race* racial_enemy;
	  std::vector<Class> prestige;
	  MagicSchool specialisation;
	  std::vector<Spell> special_abilities;
	*/
      }
    
    std::cout << std::endl
	      << "Empty party slots: " << (this->game->rules->party_size - this->players->size())
	      << std::endl << std::endl;
    
    // TODO examine character, reform party
    
    std::cout << "(P)   = Protagonist" << std::endl;
    std::cout << "(#/#) = Hit points of max hit points:" << std::endl;
    std::cout << "(D)   = Dead" << std::endl;
    std::cout << "(DD)  = Permanenty dead" << std::endl;
    
    return 2;
  }
  
  /**
   * Action: examine world map
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_map()
  {
    std::unordered_map<MapMajor*, int> distmap = std::unordered_map<MapMajor*, int>();
    for (MapMajor* mmajor : *(this->game->map->majors))
      distmap[mmajor] = -1;
    delete this->findDistances(this->players[0][this->next_player]->area, distmap, nullptr);
    
    for (MapMajor* major : *(this->game->map->majors))
      if (major->visible)
	{
	  std::cout << major->name;
	  if (major == this->players[0][this->next_player]->area->is_in)
	    std::cout << " (you are here)";
	  else
	    {
	      if (distmap.at(major) < 0)
		std::cout << " (not reachable)";
	      else if (major->visited == false)
		std::cout << " (not visited)";
	      if (major->visitable == false)
		std::cout << " (not visitable)";
	      if (distmap.at(major) >= 0)
		std::cout << " (distance: " << ((distmap.at(major) + 500) / 1000) << " km)";
	    }
	  std::cout << std::endl;
	}
    
    return 2;
  }
  
  /**
   * Action: examine area
   * 
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_area()
  {
    std::cout << this->players[0][this->next_player]->area->description << std::endl << std::endl;
    
    for (Entrance* connection : this->players[0][this->next_player]->area->connections)
      std::cout << "Entrance: " << connection->direction << " → " << connection->description << std::endl;
    if (this->players[0][this->next_player]->area->connections.size() > 0)
      std::cout << std::endl;
    
    for (Road* road : this->players[0][this->next_player]->area->roads)
      std::cout << "Road direction: " << road->direction << std::endl;
    if (this->players[0][this->next_player]->area->roads.size() > 0)
      std::cout << std::endl;
    
    for (Item* item : this->players[0][this->next_player]->area->items)
      std::cout << "On the ground: " << item->name << std::endl;
    if (this->players[0][this->next_player]->area->items.size() > 0)
      std::cout << std::endl;
    
    for (Creature* creature : this->players[0][this->next_player]->area->creatures)
      if (creature->alive && (dynamic_cast<Character*>(creature)->alive == 1))
	std::cout << creature->record.name << (creature->hostile ? " (hostile)" : " (friendly)") << std::endl;
    if (this->players[0][this->next_player]->area->creatures.size() > 0)
      std::cout << std::endl;
    
    std::flush(std::cout);
    return 2;
  }
  
  /**
   * Action: travel to another area
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_travel()
  {
    // TODO check that you can outrun hostiles
    
    std::vector<Entrance*> entrances = std::vector<Entrance*>();
    std::vector<Road*> roads = std::vector<Road*>();
    std::vector<std::string> names = std::vector<std::string>();
    
    for (Entrance* entrance : this->players[0][this->next_player]->area->connections)
      {
	std::stringstream ss;
	ss << "Entrance: " << entrance->direction << " → " << entrance->description;
	names.push_back(ss.str());
	entrances.push_back(entrance);
      }
    
    for (Road* road : this->players[0][this->next_player]->area->roads)
      {
	std::stringstream ss;
	ss << "Road: " << road->direction;
	names.push_back(ss.str());
	roads.push_back(road);
      }
    
    long target = promptMenu("Where do you want to go?", names);
    if (target < 0)
      return 2;
    
    if ((size_t)target < entrances.size())
      {
	Entrance* entrance = entrances[target];
	if (entrance->usable == false)
	  std::cout << "Not possible." << std::endl;
	else if ((*entrance >= PROTOTYPE(Door)) && static_cast<Door*>(entrance)->locked)
	  std::cout << "It's locked." << std::endl;
	else
	  this->players[0][this->next_player]->area = static_cast<MapMinor*>(entrance->leads_to);
      }
    else
      {
	target -= entrances.size();
	Road* road = roads[target];
	if (gathered() == false)
	  std::cout << "You must gather your party before venturing forth." << std::endl;
	else
	  {
	    MapMajor* major = static_cast<MapMinor*>(road->leads_to)->is_in;
	    if (major->detectable && !(major->visible))
	      major->visible = true;
	    
	    names = std::vector<std::string>();
	    std::vector<MapMajor*> majors = std::vector<MapMajor*>();
	    
	    std::unordered_map<MapMajor*, int> distmap = std::unordered_map<MapMajor*, int>();
	    for (MapMajor* mmajor : *(this->game->map->majors))
	      distmap[mmajor] = -1;
	    std::unordered_map<MapMajor*, MapMinor*> where = std::unordered_map<MapMajor*, MapMinor*>();
	    auto map = this->findDistances(this->players[0][this->next_player]->area, distmap, &where);
	    
	    for (MapMajor* mmajor : *(this->game->map->majors))
	      if (mmajor->visible)
		{
		  majors.push_back(mmajor);
		  std::stringstream ss;
		  ss << mmajor->name;
		  if (mmajor == this->players[0][this->next_player]->area->is_in)
		    ss << " (you are here)";
		  else
		    {
		      if (distmap.at(mmajor) < 0)
			ss << " (not reachable)";
		      else if (mmajor->visited == false)
			ss << " (not visited)";
		      if (mmajor->visitable == false)
			ss << " (not visitable)";
		      if (distmap.at(mmajor) >= 0)
			ss << " (distance: " << ((distmap.at(mmajor) + 500) / 1000) << " km)";
		      if (mmajor == major)
			ss << " (neighbouring)";
		    }
		  names.push_back(ss.str());
		}
	    
	    long target = promptMenu("Where do you want to go?", names);
	    if ((target < 0) || (majors[target] == this->players[0][this->next_player]->area->is_in))
	      {
		delete map;
		return 2;
	      }
	    
	    MapMajor* mmajor = majors[target];
	    
	    if ((mmajor->visitable == false) || (distmap.at(mmajor) < 0))
	      {
		delete map;
		std::cout << "Dude, I just told you, you cannot travel there right now!" << std::endl;
		return 2;
	      }
	    
	    std::vector<Road*> path = std::vector<Road*>();
	    this->findPath(map, where[mmajor], path);
	    delete map;
	    MapMinor* mminor = static_cast<MapMinor*>(path[path.size() - 1]->leads_to);
	    
	    /* TODO get travel time */
	    /* TODO support waylay */
	    
	    for (GameCharacter* gamechar : *(this->players))
	      gamechar->area = mminor;
	    mmajor->visited = true;
	  }
      }
    
    return 1;
  }
  
  
  /**
   * Find the distances to all map major
   * 
   * @param   start    The start minor area
   * @param   distmap  Map to fill with distances to majors
   * @param   where    Map major to map minor map
   * @return           Walk path mapping
   */
  std::unordered_map<MapMinor*, MapMinor*>* GamePlay::findDistances(MapMinor* start,
								    std::unordered_map<MapMajor*, int>& distmap,
								    std::unordered_map<MapMajor*, MapMinor*>* where) const
  {
    /* Dijkstra's algorithm [XXX c++ does not have a proper priority queue so we use vector] */
    
    std::unordered_map<MapMinor*, bool>       explored =     std::unordered_map<MapMinor*, bool>();
    std::unordered_map<MapMinor*, int>        distance =     std::unordered_map<MapMinor*, int>();
    std::unordered_map<MapMinor*, MapMinor*>* previous = new std::unordered_map<MapMinor*, MapMinor*>();
    
    #define __ensure(M, K, V, W)  \
      M.insert(std::pair<MapMinor*, V>((MapMinor*)(K), W))
    
    for (const MapMajor* major : *(this->game->map->majors))
      for (const _MapMinor* _minor : *(major->minors))
	{
	  const MapMinor* minor = static_cast<const MapMinor*>(_minor);
	  __ensure(distance, minor, int, 0);
	  __ensure(explored, minor, bool, false);
	  __ensure((*previous), minor, MapMinor*, nullptr);
	}
    
    explored[start] = true;
    (*previous)[start] = start;
    distmap[(MapMajor*)(start->is_in)] = 0;
    
    std::vector<MapMinor*> set = std::vector<MapMinor*>();
    set.push_back(start);
    
    while ((set.size()))
      {
	int index = 0;
	int best = -1;
	int i = 0;
	for (MapMinor* element : set)
	  {
	    if (explored[element] && ((best < 0) || (distance[element] < best)))
	      {
		index = i;
		best = distance[element];
	      }
	    i++;
	  }
	MapMinor* u = set[index];
	set.erase(set.begin() + index);
	if (explored[u] == false)
	  break;
	
        #define __update()							\
	  if ((explored[v] == false) || (candidate < distance[v]))		\
	    {									\
	      distance[v] = candidate;						\
	      explored[v] = true;						\
	      (*previous)[v] = u;						\
	      if ((distmap[v->is_in] < 0) || (candidate < distmap[v->is_in]))	\
		{								\
		  distmap[v->is_in] = candidate;				\
		  if (where != nullptr)						\
		    (*where)[v->is_in] = v;					\
		}								\
	      bool exists = false;						\
	      for (MapMinor* element : set)					\
		if (element == v)						\
		  {								\
		    exists = true;						\
		    break;							\
		  }								\
	      if (exists == false)						\
		set.push_back(v);						\
	    }//
	
	for (Road* road : u->roads)
	  {
	    int candidate = distance[u] + road->first_distance + road->last_distance;
	    MapMinor* v = static_cast<MapMinor*>(road->leads_to);
	    __update();
	  }
	int candidate = distance[u];
	for (Entrance* entrance : u->connections)
	  {
	    MapMinor* v = static_cast<MapMinor*>(entrance->leads_to);
	    __update();
	  }
	
	#undef __update
      }
    
    #undef __ensure
    
    return previous;
  }
  
  
  /**
   * Find the path to a area
   * 
   * @param  mapping  Walk path mapping
   * @param  end      The target minor area
   * @param  path     Vector to fill with the path
   */
  void GamePlay::findPath(const std::unordered_map<MapMinor*, MapMinor*>* mapping,
			  MapMinor* end, std::vector<Road*>& path) const
  {
    std::vector<MapMinor*> rev = std::vector<MapMinor*>();
    {
      MapMinor* prev = end;
      rev.push_back(end);
      while (mapping->at(prev) != prev)
	rev.push_back(prev = mapping->at(prev));
    }
    for (size_t i = 1; i < rev.size(); i++)
      {
	MapMinor* u = rev[i];
	MapMinor* v = rev[i - 1];
	bool done = false;
	for (Entrance* entrance : u->connections)
	  if (v == static_cast<MapMinor*>(entrance->leads_to))
	    {
	      done = true;
	      break;
	    }
	if (done == false)
	  for (Road* road : u->roads)
	    if (v == static_cast<MapMinor*>(road->leads_to))
	      {
		path.push_back(road);
		break;
	      }
      }
  }
  
  
  
  #undef __forbid_stealth
  #undef __forbid_find_trap
  #undef __forbid_turn_undead
  #undef __forbid_bard_song
}

