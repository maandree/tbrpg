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
#ifndef __ENTRANCE__
#define __ENTRANCE__


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
   * Connection between map areas
   */
  class Entrance
  {
  public:
    /**
     * Whether the object is locked
     */
    bool locked;
    
    /**
     * The lowest value needed from 1D20 roll, with modifiers, to be able to pick the lock
     */
    int pick_level;
    
    /**
     * The lowest value needed from 1D20 roll, with modifiers, to be able to bash the lock
     */
    int bash_level;
    
    /**
     * Whether the lock is pickable
     */
    bool pickable;
    
    /**
     * Whether the lock is bashable
     */
    bool bashable;
    
    
    
    /**
     * Construction
     */
    Entrance();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(const Entrance& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(Entrance& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(Entrance&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Entrance();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Entrance& operator =(const Entrance& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Entrance& operator =(Entrance& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Entrance& operator =(Entrance&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Entrance& self, const Entrance& original);
  
  };
}


#endif//__ENTRANCE__
