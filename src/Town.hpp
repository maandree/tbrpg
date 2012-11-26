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
#ifndef __TOWN__
#define __TOWN__


#include <stdlib.h>
#include <algorithm>


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
   * Town outdoors environment
   */
  class Town: public  MapMinor
  {
  public:
    /**
     * Construction
     */
    Town() : MapMinor();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Town(const Town& original) : MapMinor(original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Town(Town& original) : MapMinor(original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Town(Town&& original) : MapMinor(original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Town();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Town& operator =(const Town& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Town& operator =(Town& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Town& operator =(Town&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Town& self, const Town& original);
  
  };
}


#endif//__TOWN__
