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
#ifndef __MAP__
#define __MAP__


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
   * The world map
   */
  class Map
  {
  public:
    /**
     * Whether the creature is hostile
     */
    bool hostile;
    
    /**
     * The creatures horizontal position in metres, the parties starts at 0
     */
    float x;
    
    /**
     * The creatures vertical position in metres, the parties starts at 0
     */
    float y;
    
    /**
     * Whether the creature is alive, the game senario is allowed to have it dead and the set it to live to simulate the creature being new
     */
    boolean alive;
    
    /**
     * Whether the creature is resurrected when the party leaves the area
     */
    boolean resurrect;
    
    
    
    /**
     * Construction
     */
    Map();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Map(const Map& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Map(Map& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Map(Map&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Map();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Map& operator =(const Map& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Map& operator =(Map& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Map& operator =(Map&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Map& self, const Map& original);
  
  };
}


#endif//__MAP__
