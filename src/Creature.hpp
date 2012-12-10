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
#ifndef __GUARD_CREATURE_HPP__
#define __GUARD_CREATURE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Character.hpp"
#include "hash.hpp"


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
   * A creature in the area
   */
  class Creature: public Character
  {
  public:
    /**
     * Whether the creature is hostile
     */
    bool hostile;
    
    /**
     * The creatures horizontal position in metres, the parties starts at 0
     */
    float x;
    
    /**
     * The creatures vertical position in metres, the parties starts at 0
     */
    float y;
    
    /**
     * Whether the creature is alive, the game senario is allowed to have it dead and the set it to live to simulate the creature being new
     */
    bool alive;
    
    /**
     * Whether the creature is resurrected when the party leaves the area
     */
    bool resurrect;
    
    /**
     * the experience gain for killing the creature
     */
    int experience;
    
    
    
    /**
     * Construction
     */
    Creature();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Creature(const Creature& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Creature(Creature& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Creature(Creature&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Creature();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Creature& operator =(const Creature& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Creature& operator =(Creature& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Creature& operator =(Creature&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Creature& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Creature& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Creature& self, const Creature& original);
    
    
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
  class hash<tbrpg::Creature>
  {
  public:
    size_t operator()(const tbrpg::Creature& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Creature*>
  {
  public:
    size_t operator()(tbrpg::Creature* elem) const
    {
       return elem->hash();
    }
  };
}


#endif//__GUARD_CREATURE_HPP__

