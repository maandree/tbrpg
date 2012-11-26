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
#ifndef __CHARACTER__
#define __CHARACTER__


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
   * Character
   */
  class Character
  {
  public:
    /**
     * The name of the character
     */
    std::string name;
    
    /**
     * The character's biography
     */
    std::string biography;
    
    /**
     * The character's name colouration
     */
    char colour;
    
    /**
     * The character's alignment
     */
    char alignment;
    
    /**
     * The character's portrait in printable data
     */
    std::string portrait;
    
    /**
     * Whether the characters is female
     */
    bool female;
    
    /**
     * The character's experiences for its classes
     */
    int[] experience;
    
    /**
     * The character's levels for its classes
     */
    char[] level;
    
    /**
     * For each of the character's classes, whether the class is abondoned by dual classing
     */
    bool[] class_abondoned;
    
    /**
     * The character's weapon proficiencies
     */
    std::unorderd_map<WeaponGroup, int> proficiencies;
    
    /**
     * Spells the character is affected by
     */
    std::vector<Spell> affected_by;
    
    /**
     * The character's inventory
     */
    Inventory inventory;
    
    /**
     * The character's abilities
     */
    AbiltyBonus abilities;
    
    /**
     * The character's spell book
     */
    SpellBook spells;
    
    /**
     * The character's race
     */
    Race race;
    
    /**
     * The character's racial enemy
     */
    Race racial_enemy;
    
    /**
     * The character's prestige classes
     */
    Class[] prestige;
    
    /**
     * The character's magic school specialisation
     */
    MagicSchool specialisation;
    
    /**
     * The character's special abilities
     */
    std::vector<Spell> special_abilities;
    
    
    
    /**
     * Construction
     */
    Character();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Character(const Character& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Character(Character& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Character(Character&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Character();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(const Character& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(Character& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Character& operator =(Character&& original);
    
  };
}


#endif//__CHARACTER__
