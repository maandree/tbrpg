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
#ifndef __RACE__
#define __RACE__


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
   * Race class
   */
  class Race
  {
  public:
    /**
     * Minimum starting hit points
     */
    int hit_points;
    
    /**
     * THAC0
     */
    int thac0;
    
    /**
     * Lore bonus
     */
    int lore_bonus;
    
    /**
     * Allowed alignments
     */
    bool[] alignments;
    
    /**
     * Whether the character can learn spells from scrolls
     */
    bool learn_from_scroll;
    
    /**
     * The number of proficiencies scores that may be assigned to each weapon proficiency for new level 1 characters
     */
    char proficiencies_each;
    
    /**
     * The class's experience chart
     */
    ExperienceChart experience_chart;
    
    /**
     * The class's spell progression chart
     */
    SpellProgression spell_progression;
    
    /**
     * Abilties
     */
    AbilityBonus abilities;
    
    /**
     * Lower abilty bounds
     */
    Abilites lower_limits;
    
    /**
     * Special abilities
     */
    Spell[] special_abilties;
    
    /**
     * Usable items
     */
    Item[] can_use;
    
    /**
     * Proficiency chart
     */
    std::unorderd_map<WeaponGroup, Proficiencies[]> proficiency_chart;
    
    /**
     * Weapon used when the character has his left hand free but is holding a shield
     */
    Weapon default_one_hand;
    
    /**
     * Weapon used when the character has both his hands free
     */
    Weapon default_two_hand;
    
    
    
    /**
     * Construction
     */
    Race();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Race(const Race& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Race(Race& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Race(Race&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Race();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Race& operator =(const Race& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Race& operator =(Race& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Race& operator =(Race&& original);
    
  };
}


#endif//__RACE__
