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
#ifndef __CREATURE__
#define __CREATURE__


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
   * A creature in the area
   */
  class Creature: Character
  {
  public:
    /**
     * The number of sides on the dice to roll to determine whether your sleeps is being interrupted
     */
    char interrupt_die;
    
    /**
     * The number dice to roll to determine whether your sleeps is being interrupted
     */
    char interrupt_dice;
    
    /**
     * The highest value for at which your gets interrupted, use 0 for never, and 255 for always
     */
    unsigned char interrupt_risk;
    
    /**
     * Creatures that will be summoned
     */
    Creature[] creatures;
    
    
    
    /**
     * Construction
     */
    Creature();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Creature(const Creature& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Creature(Creature& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Creature(Creature&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Creature();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Creature& operator =(const Creature& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Creature& operator =(Creature& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Creature& operator =(Creature&& original);
    
  };
}


#endif//__CREATURE__
