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
#include "Character.hpp"


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
   */
  Character::Character()
  {
    //TODO implement constructor
    //name = nullptr;
    //biography = nullptr;
    //colour = nullptr;
    //alignment = nullptr;
    //portrait = nullptr;
    //female = false;
    //experience = nullptr;
    //level = nullptr;
    //class_abondoned = nullptr;
    //proficiencies = nullptr;
    //affected_by = nullptr;
    //inventory = nullptr;
    //abilities = nullptr;
    //spells = nullptr;
    //race = nullptr;
    //racial_enemy = nullptr;
    //prestige = nullptr;
    //specialisation = nullptr;
    //special_abilities = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(const Character& original)
  {
    this->name = original.name;
    this->biography = original.biography;
    this->colour = original.colour;
    this->alignment = original.alignment;
    this->portrait = original.portrait;
    this->female = original.female;
    this->experience = original.experience;
    this->level = original.level;
    this->class_abondoned = original.class_abondoned;
    this->proficiencies = original.proficiencies;
    this->affected_by = original.affected_by;
    this->inventory = original.inventory;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->race = original.race;
    this->racial_enemy = original.racial_enemy;
    this->prestige = original.prestige;
    this->specialisation = original.specialisation;
    this->special_abilities = original.special_abilities;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(Character& original)
  {
    this->name = original.name;
    this->biography = original.biography;
    this->colour = original.colour;
    this->alignment = original.alignment;
    this->portrait = original.portrait;
    this->female = original.female;
    this->experience = original.experience;
    this->level = original.level;
    this->class_abondoned = original.class_abondoned;
    this->proficiencies = original.proficiencies;
    this->affected_by = original.affected_by;
    this->inventory = original.inventory;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->race = original.race;
    this->racial_enemy = original.racial_enemy;
    this->prestige = original.prestige;
    this->specialisation = original.specialisation;
    this->special_abilities = original.special_abilities;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(Character&& original)
  {
    std::move(this->name, original.name);
    std::move(this->biography, original.biography);
    std::move(this->colour, original.colour);
    std::move(this->alignment, original.alignment);
    std::move(this->portrait, original.portrait);
    std::swap(this->female, original.female);
    std::move(this->experience, original.experience);
    std::move(this->level, original.level);
    std::move(this->class_abondoned, original.class_abondoned);
    std::move(this->proficiencies, original.proficiencies);
    std::move(this->affected_by, original.affected_by);
    std::move(this->inventory, original.inventory);
    std::move(this->abilities, original.abilities);
    std::move(this->spells, original.spells);
    std::move(this->race, original.race);
    std::move(this->racial_enemy, original.racial_enemy);
    std::move(this->prestige, original.prestige);
    std::move(this->specialisation, original.specialisation);
    std::move(this->special_abilities, original.special_abilities);
  }
  
  
  
  /**
   * Destructor
   */
  Character::~Character()
  {
    //TODO implement destructor
    //delete name;
    //delete biography;
    //delete colour;
    //delete alignment;
    //delete portrait;
    //delete experience;
    //delete level;
    //delete class_abondoned;
    //delete proficiencies;
    //delete affected_by;
    //delete inventory;
    //delete abilities;
    //delete spells;
    //delete race;
    //delete racial_enemy;
    //delete prestige;
    //delete specialisation;
    //delete special_abilities;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Character& Character::operator =(const Character& original)
  {
    this->name = original.name;
    this->biography = original.biography;
    this->colour = original.colour;
    this->alignment = original.alignment;
    this->portrait = original.portrait;
    this->female = original.female;
    this->experience = original.experience;
    this->level = original.level;
    this->class_abondoned = original.class_abondoned;
    this->proficiencies = original.proficiencies;
    this->affected_by = original.affected_by;
    this->inventory = original.inventory;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->race = original.race;
    this->racial_enemy = original.racial_enemy;
    this->prestige = original.prestige;
    this->specialisation = original.specialisation;
    this->special_abilities = original.special_abilities;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Character& Character::operator =(Character& original)
  {
    this->name = original.name;
    this->biography = original.biography;
    this->colour = original.colour;
    this->alignment = original.alignment;
    this->portrait = original.portrait;
    this->female = original.female;
    this->experience = original.experience;
    this->level = original.level;
    this->class_abondoned = original.class_abondoned;
    this->proficiencies = original.proficiencies;
    this->affected_by = original.affected_by;
    this->inventory = original.inventory;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->race = original.race;
    this->racial_enemy = original.racial_enemy;
    this->prestige = original.prestige;
    this->specialisation = original.specialisation;
    this->special_abilities = original.special_abilities;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Character& Character::operator =(Character&& original)
  {
    std::move(this->name, original.name);
    std::move(this->biography, original.biography);
    std::move(this->colour, original.colour);
    std::move(this->alignment, original.alignment);
    std::move(this->portrait, original.portrait);
    std::swap(this->female, original.female);
    std::move(this->experience, original.experience);
    std::move(this->level, original.level);
    std::move(this->class_abondoned, original.class_abondoned);
    std::move(this->proficiencies, original.proficiencies);
    std::move(this->affected_by, original.affected_by);
    std::move(this->inventory, original.inventory);
    std::move(this->abilities, original.abilities);
    std::move(this->spells, original.spells);
    std::move(this->race, original.race);
    std::move(this->racial_enemy, original.racial_enemy);
    std::move(this->prestige, original.prestige);
    std::move(this->specialisation, original.specialisation);
    std::move(this->special_abilities, original.special_abilities);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Character::__copy__(Character& self, const Character& original);
  {
    left = right;
  }
  
}

