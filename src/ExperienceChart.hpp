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
#ifndef __GUARD_EXPERIENCECHART_HPP__
#define __GUARD_EXPERIENCECHART_HPP__
#ifdef  CIRCULAR_EXPERIENCECHART
#include "ExperienceChart.circular"
#endif//CIRCULAR_EXPERIENCECHART


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "Spell.hpp"


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
   * Experience chart
   */
  class ExperienceChart
  {
  public:
    /**
     * Required experience for each level
     */
    int* experience;
    
    /**
     * The number of sides of the dice to roll that determines the hit points gained when a level is reached
     */
    char* hit_point_die;
    
    /**
     * The number of dice to roll that determines the hit points gained when a level is reached
     */
    char* hit_point_dice;
    
    /**
     * Hit points gained when a level is reached
     */
    int* hit_point_bonus;
    
    /**
     * The number of wizard spells that can be selected for learning when a level is reached
     */
    int* selectable_wizard;
    
    /**
     * The number of priest spells that can be selected for learning when a level is reached
     */
    int* selectable_priest;
    
    /**
     * Spells that are learned to when a level is reached
     */
    std::vector<Spell>* new_spells;
    
    /**
     * The number of proficiencies that that can be allocated when a level is reached
     */
    int* proficiencies;
    
    
    
    /**
     * Construction
     */
    ExperienceChart();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ExperienceChart(const ExperienceChart& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ExperienceChart(ExperienceChart& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    ExperienceChart(ExperienceChart&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~ExperienceChart();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ExperienceChart& operator =(const ExperienceChart& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ExperienceChart& operator =(ExperienceChart& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual ExperienceChart& operator =(ExperienceChart&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(ExperienceChart& self, const ExperienceChart& original);
    
    
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
  class hash<tbrpg::ExperienceChart>
  {
  public:
    size_t operator()(const tbrpg::ExperienceChart& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_EXPERIENCECHART_HPP__
