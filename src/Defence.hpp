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
#ifndef __DEFENCE__
#define __DEFENCE__


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
   * Defence class
   */
  class Defence
  {
  public:
    /**
     * Hit bonus
     */
    int hit_bonus;
    
    /**
     * Damage bonus
     */
    int damage_bonus;
    
    /**
     * Weight carry limit in grams
     */
    int carry_limit;
    
    /**
     * Bashing chance
     */
    float bashing;
    
    /**
     * Missile attack bonus
     */
    int missile_attack_bonus;
    
    /**
     * Armour class bonus
     */
    int armour_class_bonus;
    
    /**
     * Hit point bonus
     */
    int hit_point_bonus;
    
    /**
     * Resurrectability
     */
    float resurrectability;
    
    /**
     * Reaction bonus
     */
    int reaction_bonus;
    
    /**
     * Spell level limit
     */
    char spell_level_limit;
    
    /**
     * Chance to learn spell
     */
    float spell_learn;
    
    /**
     * Maximum learned spells per limit
     */
    char max_spells_level;
    
    /**
     * Lore bonus
     */
    int lore_bonus;
    
    /**
     * Resistance against magic bonus
     */
    float magic_defence_bonus;
    
    /**
     * Chance to fail spell casting
     */
    float spell_failure;
    
    /**
     * Extra spell slots per spell level
     */
    int[] bonus_spells;
    
    /**
     * Morale bonus
     */
    int morale;
    
    /**
     * Luck bonus
     */
    int luck;
    
    /**
     * Detect secret door bonus
     */
    float detect_doors;
    
    
    
    /**
     * Construction
     */
    Defence();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Defence(const Defence& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Defence(Defence& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Defence(Defence&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Defence();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Defence& operator =(const Defence& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Defence& operator =(Defence& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Defence& operator =(Defence&& original);
    
  };
}


#endif//__DEFENCE__
