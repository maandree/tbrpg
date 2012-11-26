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
#ifndef __BONUSES__
#define __BONUSES__


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
   * Bonuses
   */
  class Bonuses
  {
  public:
    /**
     * Reaction adjustment for each reputation
     */
    int[] reaction_adjustment;
    
    /**
     * Whether the party is wanted for each reputation
     */
    bool[] wanted;
    
    /**
     * Penalty for killing a innocent for each reputation
     */
    int[] killing_innocent;
    
    /**
     * Penalty for injuring a innocent for each reputation
     */
    int[] injuring_innocent;
    
    /**
     * Penalty for stealing for each reputation
     */
    int[] stealing;
    
    /**
     * Penalty for killing a guard for each reputation
     */
    int[] killing_guard;
    
    /**
     * Donation needed to increase reputation for each reputation, zero for not possible
     */
    int[] donation_needed;
    
    /**
     * Price multiplier for each reputation
     */
    float[] price_adjustment;
    
    /**
     * Reaction form good aligned for each reputation
     */
    int[] good_reaction;
    
    /**
     * Reaction form neutral aligned for each reputation
     */
    int[] neutral_reaction;
    
    /**
     * Reaction form evil aligned for each reputation
     */
    int[] evil_reaction;
    
    /**
     * Reputation for each alignment of the protagonist
     */
    char[] alignment_reputation;
    
    
    
    /**
     * Construction
     */
    Bonuses();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Bonuses(const Bonuses& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Bonuses(Bonuses& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Bonuses(Bonuses&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Bonuses();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Bonuses& operator =(const Bonuses& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Bonuses& operator =(Bonuses& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Bonuses& operator =(Bonuses&& original);
    
  };
}


#endif//__BONUSES__
