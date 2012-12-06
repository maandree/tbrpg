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
#ifndef __GUARD_THROWING_HPP__
#define __GUARD_THROWING_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "RangedWeapon.hpp"
#include "hash.h"


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
   * Throwing weapon item class
   */
  class Throwing: public RangedWeapon
  {
  public:
    /**
     * Construction
     */
    Throwing();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Throwing(const Throwing& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Throwing(Throwing& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Throwing(Throwing&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Throwing();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Throwing& operator =(const Throwing& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Throwing& operator =(Throwing& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Throwing& operator =(Throwing&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Throwing& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Throwing& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Throwing& self, const Throwing& original);
    
    
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
  class hash<tbrpg::Throwing>
  {
  public:
    size_t operator()(const tbrpg::Throwing& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_THROWING_HPP__

