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
    this->next_player %= this->players.size();
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
    if (this->players[this->next_player]->stealth_on)
      std::cout << "You will have to turn off Stealth Mode." << std::endl;
    else if (this->players[this->next_player]->find_traps_on)
      std::cout << "You will have to turn off Find Traps." << std::endl;
    else if (this->players[this->next_player]->turn_undead_on)
      std::cout << "You will have to turn off Turn Undead." << std::endl;
    else if (gathered() == false)
      std::cout << "You must gather you party before resting." << std::endl;
    else if (this->players[0]->area->may_rest == false)
      std::cout << "May not rest here, either find an inn or rest outside." << std::endl;
    else
      {
	std::cout << "Not implement..." << std::endl; // TODO
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
    this->players[0]->selectQuiver();
    return 2;
  }
  
  /**
   * Action: select weapon to use from the quick weapons
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_weapon()
  {
    this->players[0]->selectWeapon();
    return 2;
  }
  
  /**
   * Action: attack
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one more time
   */
  char GamePlay::action_attack()
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
    
    /*
    for (Creature& creature : this->position->creatures)
      if (creature.hostile && creature.alive && (((Character&)creature).alive == 1))
	{
          for (Item* item : creature.record.inventory.personal)
	    if (item != nullptr)
	      this->position->items.push_back((Item&)*item);
	  creature.alive = false;
	  std::flush(std::cout << "You have killed \033[3" << creature.record.colour << "m" << creature.record.name << "\033[39m." << std::endl);
          return 1;
	}
    */
    std::cout << "There is no hostile nearby." << std::endl; // TODO
    return 2;
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
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
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
    
    std::cout << "Not implement..." << std::endl; // TODO
    return 2;
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

