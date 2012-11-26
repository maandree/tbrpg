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
#ifndef __GUARD_CHARACTER_HPP__
#define __GUARD_CHARACTER_HPP__
#ifdef  CIRCULAR_CHARACTER
#include "Character.circular"
#endif//CIRCULAR_CHARACTER


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "CharacterSheet.hpp"


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
   * Character
   */
  class Character
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
    Character();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Character(const Character& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Character(Character& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Character(Character&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Character();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(const Character& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(Character& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Character& operator =(Character&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Character& self, const Character& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Character>
  {
  public:
    size_t operator()(const tbrpg::Character& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_CHARACTER_HPP__
