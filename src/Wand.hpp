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
#ifndef __GUARD_WAND_HPP__
#define __GUARD_WAND_HPP__
#ifdef  CIRCULAR_WAND
#include "Wand.circular"
#endif//CIRCULAR_WAND


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "QuickItem.hpp"




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
   * Wand, rod and magic staff item class
   */
  class Wand: public QuickItem
  {
  public:
    /**
     * Construction
     */
    Wand();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Wand(const Wand& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Wand(Wand& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Wand(Wand&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Wand();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Wand& operator =(const Wand& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Wand& operator =(Wand& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Wand& operator =(Wand&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Wand& self, const Wand& original);
    
    
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
  class hash<tbrpg::Wand>
  {
  public:
    size_t operator()(const tbrpg::Wand& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_WAND_HPP__
