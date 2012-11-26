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
#ifndef __RANGEDWEAPON__
#define __RANGEDWEAPON__


#include <stdlib.h>
#include <algorithm>


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
   * Ranged weapon item class
   */
  class RangedWeapon: Weapon
  {
  public:
    /**
     * Items contained by the container
     */
    std::vector<Item> contains;
    
    /**
     * Number of items that can be put in the container
     */
    int contain_limit;
    
    /**
     * Weight multiplier
     */
    float weight_modifier;
    
    /**
     * Items that can be put inside the container
     */
    Item[] can_contain;
    
    
    
    /**
     * Construction
     */
    RangedWeapon();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RangedWeapon(const RangedWeapon& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RangedWeapon(RangedWeapon& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    RangedWeapon(RangedWeapon&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~RangedWeapon();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RangedWeapon& operator =(const RangedWeapon& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RangedWeapon& operator =(RangedWeapon& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual RangedWeapon& operator =(RangedWeapon&& original);
    
  };
}


#endif//__RANGEDWEAPON__
