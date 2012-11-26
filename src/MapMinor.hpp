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
#ifndef __MAPMINOR__
#define __MAPMINOR__


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
   * Map area
   */
  class MapMinor
  {
  public:
    /**
     * Whether the entrance can be used
     */
    bool usable;
    
    /**
     * A description of what you see
     */
    std::string description;
    
    /**
     * The direction to the entrace
     */
    std::string direction;
    
    /**
     * The area to which the entrance leads
     */
    MapMinor leads_to;
    
    
    
    /**
     * Construction
     */
    MapMinor();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(const MapMinor& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(MapMinor& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(MapMinor&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~MapMinor();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MapMinor& operator =(const MapMinor& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MapMinor& operator =(MapMinor& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual MapMinor& operator =(MapMinor&& original);
    
  };
}


#endif//__MAPMINOR__
