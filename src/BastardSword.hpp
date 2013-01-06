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
#ifndef __GUARD_BASTARDSWORD_HPP__
#define __GUARD_BASTARDSWORD_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "LargeSword.hpp"



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
   * Bastard sword item class
   */
  class BastardSword: public LargeSword
  {
  public:
    /**
     * Construction
     */
    BastardSword();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    BastardSword(const BastardSword& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    BastardSword(BastardSword& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    BastardSword(BastardSword&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~BastardSword();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual BastardSword& operator =(const BastardSword& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual BastardSword& operator =(BastardSword& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual BastardSword& operator =(BastardSword&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const BastardSword& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const BastardSword& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(BastardSword& self, const BastardSword& original);
    
    
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
  class hash<tbrpg::BastardSword>
  {
  public:
    size_t operator()(const tbrpg::BastardSword& elem) const
    {
      return dynamic_cast<tbrpg::BastardSword*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::BastardSword*>
  {
  public:
    size_t operator()(tbrpg::BastardSword* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<tbrpg::BastardSword*>(elem)->hash();
    }
  };
}


#endif//__GUARD_BASTARDSWORD_HPP__

