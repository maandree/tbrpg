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
#ifndef __GUARD_TEXTSCROLL_HPP__
#define __GUARD_TEXTSCROLL_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Item.hpp"




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
   * Text scroll item class
   */
  class TextScroll: public Item
  {
  public:
    /**
     * Construction
     */
    TextScroll();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    TextScroll(const TextScroll& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    TextScroll(TextScroll& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    TextScroll(TextScroll&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~TextScroll();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual TextScroll& operator =(const TextScroll& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual TextScroll& operator =(TextScroll& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual TextScroll& operator =(TextScroll&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(TextScroll& self, const TextScroll& original);
    
    
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
  class hash<tbrpg::TextScroll>
  {
  public:
    size_t operator()(const tbrpg::TextScroll& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_TEXTSCROLL_HPP__
