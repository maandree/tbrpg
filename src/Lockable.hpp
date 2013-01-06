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
#ifndef __GUARD_LOCKABLE_HPP__
#define __GUARD_LOCKABLE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



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
   * Lockable object
   */
  class Lockable
  {
  public:
    /**
     * Whether the object is locked
     */
    bool locked;
    
    /**
     * The lowest value needed from an attack roll, with modifiers, to be able to pick the lock
     */
    int pick_level;
    
    /**
     * The lowest value needed from an attack roll, with modifiers, to be able to bash the lock
     */
    int bash_level;
    
    /**
     * Whether the lock is pickable
     */
    bool pickable;
    
    /**
     * Whether the lock is bashable
     */
    bool bashable;
    
    
    
    /**
     * Construction
     */
    Lockable();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Lockable(const Lockable& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Lockable(Lockable& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Lockable(Lockable&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Lockable();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Lockable& operator =(const Lockable& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Lockable& operator =(Lockable& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Lockable& operator =(Lockable&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Lockable& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Lockable& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Lockable& self, const Lockable& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    virtual size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Lockable>
  {
  public:
    size_t operator()(const tbrpg::Lockable& elem) const
    {
      return dynamic_cast<Lockable*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::Lockable*>
  {
  public:
    size_t operator()(tbrpg::Lockable* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<Lockable*>(elem)->hash();
    }
  };
}


#endif//__GUARD_LOCKABLE_HPP__

