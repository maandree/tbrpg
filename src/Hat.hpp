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
#ifndef __GUARD_HAT_HPP__
#define __GUARD_HAT_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Headgear.hpp"




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
   * Hat item class
   */
  class Hat: public Headgear
  {
  public:
    /**
     * Construction
     */
    Hat();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Hat(const Hat& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Hat(Hat& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Hat(Hat&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Hat();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Hat& operator =(const Hat& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Hat& operator =(Hat& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Hat& operator =(Hat&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Hat& self, const Hat& original);
    
  };
}


#endif//__GUARD_HAT_HPP__
