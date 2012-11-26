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
#ifndef __ABILITYCHART__
#define __ABILITYCHART__


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
   * Ability chart
   */
  class AbilityChart
  {
  public:
    /**
     * Spell name
     */
    std::string name;
    
    /**
     * Spell description
     */
    std::string description;
    
    /**
     * Whether the spell is a wizard spell
     */
    bool wizard;
    
    /**
     * Whether the spell is a priest spell
     */
    bool priest;
    
    /**
     * Spell level
     */
    char level;
    
    /**
     * Saving, 0 for none, 1 for half and 2 for negation
     */
    char saving;
    
    /**
     * Whether the spell's range is touching
     */
    bool touch;
    
    /**
     * Whether the spell's range, negative for touch without zero
     */
    float range;
    
    /**
     * Casting time
     */
    char casting_time;
    
    /**
     * Duration modifier
     */
    char duration;
    
    /**
     * Duration die side count
     */
    char duration_die;
    
    /**
     * Duration die count
     */
    char duration_dice;
    
    /**
     * Area of effect
     */
    std::string effect_area;
    
    /**
     * Magic shool
     */
    MagicSchool school;
    
    
    
    /**
     * Construction
     */
    AbilityChart();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    AbilityChart(const AbilityChart& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    AbilityChart(AbilityChart& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    AbilityChart(AbilityChart&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~AbilityChart();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual AbilityChart& operator =(const AbilityChart& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual AbilityChart& operator =(AbilityChart& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual AbilityChart& operator =(AbilityChart&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(AbilityChart& self, const AbilityChart& original);
  
  };
}


#endif//__ABILITYCHART__
