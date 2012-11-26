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
#ifndef __CHARACTERSHEET__
#define __CHARACTERSHEET__


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
   * Character sheet
   */
  class CharacterSheet
  {
  public:
    /**
     * Allowed classes for the race
     */
    Class[][] allowed_classes;
    
    /**
     * Bonuses for the race
     */
    AbilityBonus bonuses;
    
    
    
    /**
     * Construction
     */
    CharacterSheet();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(const CharacterSheet& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(CharacterSheet& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(CharacterSheet&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~CharacterSheet();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(const CharacterSheet& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(CharacterSheet& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(CharacterSheet&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(CharacterSheet& self, const CharacterSheet& original);
  
  };
}


#endif//__CHARACTERSHEET__
