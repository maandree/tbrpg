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
#include "CharacterCreator.hpp"


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
   * Constructor
   * 
   * @param  rules  The game's rules
   */
  CharacterCreator::CharacterCreator(const RuleSet& rules)
  {
    this->ruleset = rules;
  }
  
  /**
   * Destructor
   */
  CharacterCreator::~CharacterCreator()
  {
  }
  
  
  
  /**
   * Create a character sheet
   * 
   * @return  A character sheet
   */
  CharacterSheet create() const
  {
    // bool female
    // Race race
    // std::vector<Class> prestige
    // std::vector<bool> class_abondoned
    // std::vector<int> experience
    // std::vector<char> level
    // MagicSchool specialisation
    // char alignment
    // AbilityBonus abilities
    // std::unordered_map<WeaponGroup, int> proficiencies
    // Race racial_enemy
    // SpellBook spells
    // std::string portrait
    // char colour
    // std::string name
  }
  
}

