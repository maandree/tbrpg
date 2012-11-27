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
#ifndef __GUARD_HEAVYCROSSBOW_HPP__
#define __GUARD_HEAVYCROSSBOW_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Crossbow.hpp"




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
   * Heavy crossbow item class
   */
  class HeavyCrossbow: public Crossbow
  {
  public:
    /**
     * Construction
     */
    HeavyCrossbow();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    HeavyCrossbow(const HeavyCrossbow& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    HeavyCrossbow(HeavyCrossbow& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    HeavyCrossbow(HeavyCrossbow&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~HeavyCrossbow();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual HeavyCrossbow& operator =(const HeavyCrossbow& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual HeavyCrossbow& operator =(HeavyCrossbow& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual HeavyCrossbow& operator =(HeavyCrossbow&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(HeavyCrossbow& self, const HeavyCrossbow& original);
    
    
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
  class hash<tbrpg::HeavyCrossbow>
  {
  public:
    size_t operator()(const tbrpg::HeavyCrossbow& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_HEAVYCROSSBOW_HPP__