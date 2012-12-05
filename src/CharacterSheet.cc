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
#include "CharacterSheet.hpp"


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
  CharacterSheet::CharacterSheet() : Object()
  {
    ////TODO implement constructor
    //this->name = nullptr;
    //this->biography = nullptr;
    //this->colour = 0;
    //this->alignment = 0;
    //this->portrait = nullptr;
    //this->female = false;
    //this->experience = nullptr;
    //this->level = nullptr;
    //this->class_abondoned = nullptr;
    //this->proficiencies = nullptr;
    //this->affected_by = nullptr;
    //this->inventory = nullptr;
    //this->abilities = nullptr;
    //this->spells = nullptr;
    //this->race = nullptr;
    this->racial_enemy = nullptr;
    //this->prestige = nullptr;
    //this->specialisation = nullptr;
    //this->special_abilities = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(const CharacterSheet& original) : Object(original)
  {
    (void) original;
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
  CharacterSheet::CharacterSheet(CharacterSheet& original) : Object(original)
  {
    (void) original;
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
  CharacterSheet::CharacterSheet(CharacterSheet&& original) : Object(original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->biography, original.biography);
    std::swap(this->colour, original.colour);
    std::swap(this->alignment, original.alignment);
    std::swap(this->portrait, original.portrait);
    std::swap(this->female, original.female);
    std::swap(this->experience, original.experience);
    std::swap(this->level, original.level);
    std::swap(this->class_abondoned, original.class_abondoned);
    std::swap(this->proficiencies, original.proficiencies);
    std::swap(this->affected_by, original.affected_by);
    std::swap(this->inventory, original.inventory);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->race, original.race);
    std::swap(this->racial_enemy, original.racial_enemy);
    std::swap(this->prestige, original.prestige);
    std::swap(this->specialisation, original.specialisation);
    std::swap(this->special_abilities, original.special_abilities);
  }
  
  
  
  /**
   * Destructor
   */
  CharacterSheet::~CharacterSheet()
  {
    ////TODO implement destructor
    //delete this->name;
    //delete this->biography;
    //delete this->portrait;
    //delete this->experience;
    //delete this->level;
    //delete this->class_abondoned;
    //delete this->proficiencies;
    //delete this->affected_by;
    //delete this->inventory;
    //delete this->abilities;
    //delete this->spells;
    //delete this->race;
    //delete this->racial_enemy;
    //delete this->prestige;
    //delete this->specialisation;
    //delete this->special_abilities;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CharacterSheet& CharacterSheet::operator =(const CharacterSheet& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
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
  CharacterSheet& CharacterSheet::operator =(CharacterSheet& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
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
  CharacterSheet& CharacterSheet::operator =(CharacterSheet&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->name, original.name);
    std::swap(this->biography, original.biography);
    std::swap(this->colour, original.colour);
    std::swap(this->alignment, original.alignment);
    std::swap(this->portrait, original.portrait);
    std::swap(this->female, original.female);
    std::swap(this->experience, original.experience);
    std::swap(this->level, original.level);
    std::swap(this->class_abondoned, original.class_abondoned);
    std::swap(this->proficiencies, original.proficiencies);
    std::swap(this->affected_by, original.affected_by);
    std::swap(this->inventory, original.inventory);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->race, original.race);
    std::swap(this->racial_enemy, original.racial_enemy);
    std::swap(this->prestige, original.prestige);
    std::swap(this->specialisation, original.specialisation);
    std::swap(this->special_abilities, original.special_abilities);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool CharacterSheet::operator ==(const CharacterSheet& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void CharacterSheet::__copy__(CharacterSheet& self, const CharacterSheet& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t CharacterSheet::hash() const
  {
    return (size_t)this;
  }
  
}

