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
#ifndef __MAGICSCHOOL__
#define __MAGICSCHOOL__


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
   * Magic school class
   */
  class MagicSchool
  {
  public:
    /**
     * Current hit points
     */
    int hit_points;
    
    /**
     * Alive status, 0 for dead, 1 for alive, −1 for beyond ressurection
     */
    char alive;
    
    /**
     * Current morale
     */
    int morale;
    
    /**
     * Current intoxication level
     */
    int intoxication;
    
    /**
     * Number of turns since the character last slept with consideration for long travels
     */
    int fatigue;
    
    /**
     * The character sheet
     */
    CharacterSheet record;
    
    
    
    /**
     * Construction
     */
    MagicSchool();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(const MagicSchool& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(MagicSchool& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(MagicSchool&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~MagicSchool();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(const MagicSchool& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(MagicSchool& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(MagicSchool&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(MagicSchool& self, const MagicSchool& original);
  
  };
}


#endif//__MAGICSCHOOL__
