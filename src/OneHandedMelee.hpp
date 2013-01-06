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
#ifndef __GUARD_ONEHANDEDMELEE_HPP__
#define __GUARD_ONEHANDEDMELEE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "MeleeWeapon.hpp"
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
   * One-handed melée weapon item class
   */
  class OneHandedMelee: public MeleeWeapon
  {
  public:
    /**
     * Construction
     */
    OneHandedMelee();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    OneHandedMelee(const OneHandedMelee& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    OneHandedMelee(OneHandedMelee& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    OneHandedMelee(OneHandedMelee&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~OneHandedMelee();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual OneHandedMelee& operator =(const OneHandedMelee& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual OneHandedMelee& operator =(OneHandedMelee& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual OneHandedMelee& operator =(OneHandedMelee&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const OneHandedMelee& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const OneHandedMelee& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(OneHandedMelee& self, const OneHandedMelee& original);
    
    
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
  class hash<tbrpg::OneHandedMelee>
  {
  public:
    size_t operator()(const tbrpg::OneHandedMelee& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::OneHandedMelee*>
  {
  public:
    size_t operator()(tbrpg::OneHandedMelee* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_ONEHANDEDMELEE_HPP__

