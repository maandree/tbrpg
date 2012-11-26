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
#ifndef __GUARD_RESTINTERRUPTION_HPP__
#define __GUARD_RESTINTERRUPTION_HPP__
#ifdef  CIRCULAR_RESTINTERRUPTION
#include "RestInterruption.circular"
#endif//CIRCULAR_RESTINTERRUPTION


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "Creature.hpp"


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
    Creature* creatures;
    
    
    
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
  class hash<tbrpg::RestInterruption>
  {
  public:
    size_t operator()(const tbrpg::RestInterruption& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_RESTINTERRUPTION_HPP__
