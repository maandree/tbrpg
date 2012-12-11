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
  }
  
  /**
   * Copy construction
   */
  GamePlay::GamePlay(const GamePlay& original)
  {
    this->game = original.game;
  }
  
  /**
   * Destructor
   */
  GamePlay::~GamePlay()
  {
    // do nothing
  }
  
  /**
   * Copy operator
   */
  GamePlay& GamePlay::operator =(const GamePlay& original)
  {
    this->game = original.game;
    return *this;
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
    // TODO quick magic
    
    #undef __add
    
    for (;;)
      {
	int index = promptIndex(":: ", actions);
	if (index >= 0)
	  {
	    char r = (this->*functions[index])();
	    if (r == 2)
	      continue;
	    if (r == 0)
	      return false;
	  }
	else
	  std::flush(std::cout << "Type . to wait one turn" << std::endl);
      }
    
    return true;
  }
  
  
  /**
   * Action: quit
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_quit()
  {
    return 0;
  }
  
  /**
   * Action: wait one turn
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_wait()
  {
    return 1;
  }
  
  /**
   * Action: redo last action by any party member
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_redo()
  {
    return 2;
  }
  
  /**
   * Action: rest
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_rest()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: select ammunition to use from the quiver
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_quiver()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: select weapon to use from the quick weapons
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_weapon()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: attack
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_attack()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: cast non-quick spell
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_cast()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: talk
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_talk()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: list special usable abilities
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_specials()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: bash a lock
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_bash()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: pick a lock
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_pick_lock()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: disarm a trap
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_disarm()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: pick pocket
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_pick_pocket()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn on stealth mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_stealth()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn off stealth mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_stealth_off()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn on find traps mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_find_traps()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn off find traps mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_find_traps_off()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn on turn undead mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_turn_undead()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: turn off turn undead mode
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_turn_undead_off()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: examine inventory
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_inventory()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: examine party
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_party()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: examine world map
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_map()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
  /**
   * Action: examine area
   *
   * @return  0 for stop playing, 1 for continue playing, 2 for one mor time
   */
  char GamePlay::action_area()
  {
    std::flush(std::cout << "Not implement..." << std::endl);
    return 2;
  }
  
}

