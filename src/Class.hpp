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
#ifndef __GUARD_CLASS_HPP__
#define __GUARD_CLASS_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "ExperienceChart.hpp"
#include "AbilityBonus.hpp"
#include "Spell.hpp"
#include "Item.hpp"
#include "WeaponGroup.hpp"
#include "Weapon.hpp"
#include "Weapon.hpp"


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
   * Prestige class
   */
  class Class
  {
  public:
    /**
     * Minimum starting hit points
     */
    //int hit_points;
    
    /**
     * THAC0
     */
    //int thac0;
    
    /**
     * Lore bonus
     */
    //int lore_bonus;
    
    /**
     * Allowed alignments
     */
    //bool* alignments;
    
    /**
     * Whether the character can learn spells from scrolls
     */
    //bool learn_from_scroll;
    
    /**
     * The number of proficiencies scores that may be assigned to each weapon proficiency for new level 1 characters
     */
    //char proficiencies_each;
    
    /**
     * The class's experience chart
     */
    //ExperienceChart experience_chart;
    
    /**
     * The class's spell progression chart
     */
    //SpellProgression spell_progressio n;
    
    /**
     * Abilties
     */
    //AbilityBonus abilities;
    
    /**
     * Lower abilty bounds
     */
    //Abilites lower_limits;
    
    /**
     * Special abilities
     */
    //Spell* special_abilties;
    
    /**
     * Usable items
     */
    //Item* can_use;
    
    /**
     * Proficiency chart
     */
    //std::unordered_map<WeaponGroup, Proficiencies*> proficiency_chart;
    
    /**
     * Weapon used when the character has his left hand free but is holding a shield
     */
    //Weapon default_one_hand;
    
    /**
     * Weapon used when the character has both his hands free
     */
    //Weapon default_two_hand;
    
    
    
    /**
     * Construction
     */
    Class();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Class(const Class& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Class(Class& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Class(Class&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Class();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Class& operator =(const Class& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Class& operator =(Class& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Class& operator =(Class&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Class& self, const Class& original);
    
  };
}


#endif//__GUARD_CLASS_HPP__
