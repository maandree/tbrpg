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
#ifndef __GUARD_DRUID_HPP__
#define __GUARD_DRUID_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Priest.hpp"




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
   * The druid cass
   */
  class Druid: public Priest
  {
  public:
    /**
     * Construction
     */
    Druid();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Druid(const Druid& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Druid(Druid& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Druid(Druid&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Druid();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Druid& operator =(const Druid& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Druid& operator =(Druid& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Druid& operator =(Druid&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Druid& self, const Druid& original);
    
  };
}


#endif//__GUARD_DRUID_HPP__
