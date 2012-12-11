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
   * Destructor
   */
  GamePlay::~GamePlay()
  {
    // do nothing
  }
  
  
  /**
   * Play the next round, it may be an AI's turn
   * 
   * @return  Whether there is a next turn
   */
  bool GamePlay::next()
  {
    std::vector<std::string> actions = {};
    std::vector<bool (*)(GamePlay*)> functions = {};
    
    #define __add(cmd, f)      		 \
      actions.push_back("examine map");  \
      functions.push_back(f)
    &&&&&&&&&&&&&&&&
    __add("examine map");
    __add("examine area");
    __add("examine party");
    __add("examine inventory");
    __add("turn undead");
    __add("turn undead off");
    __add("find traps");
    __add("find traps off");
    __add("stealth");
    __add("stealth off");
    __add("pick pocket");
    __add("disarm");
    __add("unlock");
    __add("bash");
    __add("specials");
    __add("talk");
    __add("cast");
    __add("attack");
    __add("weapon");
    __add("quiver");
    __add("rest");
    __add("!");
    __add(".");
    __add("quit");
    
    #undef __add
    
    int index = promptIndex(":: ", actions);
    if (index >= 0)
      return functions[index](this);
    
    return true;
  }
  
}

