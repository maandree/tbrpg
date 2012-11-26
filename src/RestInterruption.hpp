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
#ifndef __RESTINTERRUPTION__
#define __RESTINTERRUPTION__


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
   * A possible rest interruption
   */
  class RestInterruption
  {
  public:
    /**
     * Descrion of the area
     */
    std::string description;
    
    /**
     * Whether you may rest in the area without renting a room
     */
    bool may_rest;
    
    /**
     * The radius of the area, in metres, the party starts at origo
     */
    float area;
    
    /**
     * Roads to other major areas in the area
     */
    Road[] roads;
    
    /**
     * Entrance to other areas in the area
     */
    Entrance[] connections;
    
    /**
     * Items in the area
     */
    std::vector<Item> items;
    
    /**
     * Creatures in the area
     */
    std::vector<Creature> creatures;
    
    /**
     * Which major area to which  the area belongs
     */
    MapMajor is_in;
    
    /**
     * Possible rest interruptions
     */
    RestInterruption[] interruptions;
    
    
    
    /**
     * Construction
     */
    RestInterruption();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RestInterruption(const RestInterruption& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RestInterruption(RestInterruption& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    RestInterruption(RestInterruption&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~RestInterruption();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RestInterruption& operator =(const RestInterruption& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RestInterruption& operator =(RestInterruption& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual RestInterruption& operator =(RestInterruption&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(RestInterruption& self, const RestInterruption& original);
  
  };
}


#endif//__RESTINTERRUPTION__
