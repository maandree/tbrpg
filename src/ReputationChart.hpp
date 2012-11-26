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
#ifndef __REPUTATIONCHART__
#define __REPUTATIONCHART__


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
   * Reputation chart
   */
  class ReputationChart
  {
  public:
    /**
     * The number of sides on the dice to roll at the attack roll
     */
    char attack_roll_die;
    
    /**
     * The number of dice to roll at the attack roll
     */
    char attack_roll_dice;
    
    /**
     * The minimum attack roll needed for a critical hit
     */
    char critical_hit;
    
    /**
     * The maximum attack roll needed for a critical miss
     */
    char critical_miss;
    
    /**
     * The reputation chart
     */
    ReputationChart reputation_chart;
    
    /**
     * The ability chart
     */
    AbilityChart ability_chart;
    
    /**
     * The inventory prototype, basiclly it defines how many slots there is in the inventory
     */
    Inventory inventory_prototype;
    
    /**
     * All spells, very useful for when new characters selects spells, or to restrict imported characters
     */
    Spell[] spells;
    
    /**
     * Races in the game that new charactes can chooses
     */
    Race[] races;
    
    
    
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


#endif//__REPUTATIONCHART__
