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
#ifndef __GUARD_ABILITIES_HPP__
#define __GUARD_ABILITIES_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>




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
   * Ability scores
   */
  class Abilities
  {
  public:
    /**
     * The strength, excluding extra for 18
     */
    short strength;
    
    /**
     * Extra strength for strength 18
     */
    short strength18;
    
    /**
     * The constitution
     */
    short constitution;
    
    /**
     * The dexterity
     */
    short dexterity;
    
    /**
     * The intelligence
     */
    short intelligence;
    
    /**
     * The wisdom
     */
    short wisdom;
    
    /**
     * The charisma
     */
    short charisma;
    
    
    
    /**
     * Construction
     */
    Abilities();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Abilities(const Abilities& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Abilities(Abilities& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Abilities(Abilities&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Abilities();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Abilities& operator =(const Abilities& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Abilities& operator =(Abilities& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Abilities& operator =(Abilities&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operation ==(const Abilities& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Abilities& self, const Abilities& original);
    
    
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
  class hash<tbrpg::Abilities>
  {
  public:
    size_t operator()(const tbrpg::Abilities& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_ABILITIES_HPP__
