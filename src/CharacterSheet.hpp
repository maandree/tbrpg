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
#ifndef __GUARD_CHARACTERSHEET_HPP__
#define __GUARD_CHARACTERSHEET_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "WeaponGroup.hpp"
#include "Spell.hpp"
#include "Inventory.hpp"
#include "SpellBook.hpp"
#include "Race.hpp"
#include "Race.hpp"
#include "Class.hpp"
#include "MagicSchool.hpp"
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
   * Character sheet
   */
  class CharacterSheet
  {
  public:
    /**
     * The name of the character
     */
    //std::string name;
    
    /**
     * The character's biography
     */
    //std::string biography;
    
    /**
     * The character's name colouration
     */
    //char colour;
    
    /**
     * The character's alignment
     */
    //char alignment;
    
    /**
     * The character's portrait in printable data
     */
    //std::string portrait;
    
    /**
     * Whether the characters is female
     */
    //bool female;
    
    /**
     * The character's experiences for its classes
     */
    //int* experience;
    
    /**
     * The character's levels for its classes
     */
    //char* level;
    
    /**
     * For each of the character's classes, whether the class is abondoned by dual classing
     */
    //bool* class_abondoned;
    
    /**
     * The character's weapon proficiencies
     */
    //std::unordered_map<WeaponGroup, int> proficiencies;
    
    /**
     * Spells the character is affected by
     */
    //std::vector<Spell> affected_by;
    
    /**
     * The character's inventory
     */
    //Inventory inventory;
    
    /**
     * The character's abilities
     */
    //AbiltyBonus abilities;
    
    /**
     * The character's spell book
     */
    //SpellBook spells;
    
    /**
     * The character's race
     */
    //Race race;
    
    /**
     * The character's racial enemy
     */
    //Race racial_enemy;
    
    /**
     * The character's prestige classes
     */
    //Class* prestige;
    
    /**
     * The character's magic school specialisation
     */
    //MagicSchool specialisation;
    
    /**
     * The character's special abilities
     */
    //std::vector<Spell> special_abilities;
    
    
    
    /**
     * Construction
     */
    CharacterSheet();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(const CharacterSheet& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(CharacterSheet& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    CharacterSheet(CharacterSheet&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~CharacterSheet();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(const CharacterSheet& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(CharacterSheet& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual CharacterSheet& operator =(CharacterSheet&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(CharacterSheet& self, const CharacterSheet& original);
    
  };
}


#endif//__GUARD_CHARACTERSHEET_HPP__
