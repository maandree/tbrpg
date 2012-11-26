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
#ifndef __INVENTORY__
#define __INVENTORY__


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
   * Character inventory class
   */
  class Inventory
  {
  public:
    /**
     * Strength chart
     */
    AbilityBonus[] strength;
    
    /**
     * Strength 18/* chart
     */
    AbilityBonus[] strength18;
    
    /**
     * Dexterity chart
     */
    AbilityBonus[] dexterity;
    
    /**
     * Constitution chart
     */
    AbilityBonus[] constitution;
    
    /**
     * Intelligence chart
     */
    AbilityBonus[] intelligence;
    
    /**
     * Wisdom chart
     */
    AbilityBonus[] wisdom;
    
    /**
     * Charisma chart
     */
    AbilityBonus[] charisma;
    
    
    
    /**
     * Construction
     */
    Inventory();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(const Inventory& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(Inventory& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(Inventory&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Inventory();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Inventory& operator =(const Inventory& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Inventory& operator =(Inventory& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Inventory& operator =(Inventory&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Inventory& self, const Inventory& original);
  
  };
}


#endif//__INVENTORY__
