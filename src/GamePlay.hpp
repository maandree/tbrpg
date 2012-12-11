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
#ifndef __GUARD_GAMEPLAY_HPP__
#define __GUARD_GAMEPLAY_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Senario.hpp"
#include "prompter.hpp"


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
   * Game play class
   */
  class GamePlay
  {
  protected:
    /**
     * The game senario
     */
    Senario& game
    
    
  public:
    /**
     * Construction
     * 
     * @param  senario  The game senario
     */
    GamePlay(Senario& senario);
    
    /**
     * Destructor
     */
    virtual ~GamePlay();
    
    
    /**
     * Play the next round, it may be an AI's turn
     * 
     * @return  Whether there is a next turn
     */
    bool next();
    
  };
}


#endif//__GUARD_GAMEPLAY_HPP__

