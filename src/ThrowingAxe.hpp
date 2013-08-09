// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __GUARD_THROWINGAXE_HPP__
#define __GUARD_THROWINGAXE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Throwing.hpp"
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
   * Throwing axe item class
   */
  class ThrowingAxe: public Throwing
  {
  public:
    /**
     * Construction
     */
    ThrowingAxe();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ThrowingAxe(const ThrowingAxe& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ThrowingAxe(ThrowingAxe& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    ThrowingAxe(ThrowingAxe&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~ThrowingAxe();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ThrowingAxe& operator =(const ThrowingAxe& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ThrowingAxe& operator =(ThrowingAxe& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual ThrowingAxe& operator =(ThrowingAxe&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const ThrowingAxe& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const ThrowingAxe& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(ThrowingAxe& self, const ThrowingAxe& original);
    
    
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
  class hash<tbrpg::ThrowingAxe>
  {
  public:
    size_t operator()(const tbrpg::ThrowingAxe& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::ThrowingAxe*>
  {
  public:
    size_t operator()(tbrpg::ThrowingAxe* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_THROWINGAXE_HPP__

