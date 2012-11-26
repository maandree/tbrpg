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
#ifndef __GUARD_REPUTATIONCHART_HPP__
#define __GUARD_REPUTATIONCHART_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>




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
   * Reputation chart
   */
  class ReputationChart
  {
  public:
    /**
     * Reaction adjustment for each reputation
     */
    //int* reaction_adjustment;
    
    /**
     * Whether the party is wanted for each reputation
     */
    //bool* wanted;
    
    /**
     * Penalty for killing a innocent for each reputation
     */
    //int* killing_innocent;
    
    /**
     * Penalty for injuring a innocent for each reputation
     */
    //int* injuring_innocent;
    
    /**
     * Penalty for stealing for each reputation
     */
    //int* stealing;
    
    /**
     * Penalty for killing a guard for each reputation
     */
    //int* killing_guard;
    
    /**
     * Donation needed to increase reputation for each reputation, zero for not possible
     */
    //int* donation_needed;
    
    /**
     * Price multiplier for each reputation
     */
    //float* price_adjustment;
    
    /**
     * Reaction form good aligned for each reputation
     */
    //int* good_reaction;
    
    /**
     * Reaction form neutral aligned for each reputation
     */
    //int* neutral_reaction;
    
    /**
     * Reaction form evil aligned for each reputation
     */
    //int* evil_reaction;
    
    /**
     * Reputation for each alignment of the protagonist
     */
    //char* alignment_reputation;
    
    
    
    /**
     * Construction
     */
    ReputationChart();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ReputationChart(const ReputationChart& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ReputationChart(ReputationChart& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    ReputationChart(ReputationChart&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~ReputationChart();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ReputationChart& operator =(const ReputationChart& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ReputationChart& operator =(ReputationChart& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual ReputationChart& operator =(ReputationChart&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(ReputationChart& self, const ReputationChart& original);
    
  };
}


#endif//__GUARD_REPUTATIONCHART_HPP__
