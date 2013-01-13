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
#ifndef __GUARD_INVENTORYEXAMINOR_HPP__
#define __GUARD_INVENTORYEXAMINOR_HPP__


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include "GameCharacter.hpp"


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
   * Inventory examinor
   */
  class InventoryExaminor: public Object
  {
  public:
    /**
     * Construction
     */
    InventoryExaminor();
        
    
    
    /**
     * Destructor
     */
    virtual ~InventoryExaminor();
    
    
    
    /**
     * Examine a characters inventory
     * 
     * @param  character   The index of the active character
     * @param  characters  The party members
     */
    virtual void examine(long character, std::vector<GameCharacter*>* characters) const;
    
  };
}


#endif//__GUARD_INVENTORYEXAMINOR_HPP__

