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
  CharacterSheet::CharacterSheet()
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
    //this->racial_enemy = nullptr;
    //this->prestige = nullptr;
    //this->specialisation = nullptr;
    //this->special_abilities = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(const CharacterSheet& original)
  {
    (void) original;
    //this->name = original.name;
    //this->biography = original.biography;
    //this->colour = original.colour;
    //this->alignment = original.alignment;
    //this->portrait = original.portrait;
    //this->female = original.female;
    //this->experience = original.experience;
    //this->level = original.level;
    //this->class_abondoned = original.class_abondoned;
    //this->proficiencies = original.proficiencies;
    //this->affected_by = original.affected_by;
    //this->inventory = original.inventory;
    //this->abilities = original.abilities;
    //this->spells = original.spells;
    //this->race = original.race;
    //this->racial_enemy = original.racial_enemy;
    //this->prestige = original.prestige;
    //this->specialisation = original.specialisation;
    //this->special_abilities = original.special_abilities;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(CharacterSheet& original)
  {
    (void) original;
    //this->name = original.name;
    //this->biography = original.biography;
    //this->colour = original.colour;
    //this->alignment = original.alignment;
    //this->portrait = original.portrait;
    //this->female = original.female;
    //this->experience = original.experience;
    //this->level = original.level;
    //this->class_abondoned = original.class_abondoned;
    //this->proficiencies = original.proficiencies;
    //this->affected_by = original.affected_by;
    //this->inventory = original.inventory;
    //this->abilities = original.abilities;
    //this->spells = original.spells;
    //this->race = original.race;
    //this->racial_enemy = original.racial_enemy;
    //this->prestige = original.prestige;
    //this->specialisation = original.specialisation;
    //this->special_abilities = original.special_abilities;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(CharacterSheet&& original)
  {
    (void) original;
    ////std::move(this->name, original.name);
    ////std::move(this->biography, original.biography);
    ////std::swap(this->colour, original.colour);
    ////std::swap(this->alignment, original.alignment);
    ////std::move(this->portrait, original.portrait);
    ////std::swap(this->female, original.female);
    ////std::move(this->experience, original.experience);
    ////std::move(this->level, original.level);
    ////std::move(this->class_abondoned, original.class_abondoned);
    ////std::move(this->proficiencies, original.proficiencies);
    ////std::move(this->affected_by, original.affected_by);
    ////std::move(this->inventory, original.inventory);
    ////std::move(this->abilities, original.abilities);
    ////std::move(this->spells, original.spells);
    ////std::move(this->race, original.race);
    ////std::move(this->racial_enemy, original.racial_enemy);
    ////std::move(this->prestige, original.prestige);
    ////std::move(this->specialisation, original.specialisation);
    ////std::move(this->special_abilities, original.special_abilities);
  }
  
  
  
  /**
   * Destructor
   */
  CharacterSheet::~CharacterSheet()
  {
    ////TODO implement destructor
    //delete name;
    //delete biography;
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
  CharacterSheet& CharacterSheet::operator =(const CharacterSheet& original)
  {
    (void) original;
    //this->name = original.name;
    //this->biography = original.biography;
    //this->colour = original.colour;
    //this->alignment = original.alignment;
    //this->portrait = original.portrait;
    //this->female = original.female;
    //this->experience = original.experience;
    //this->level = original.level;
    //this->class_abondoned = original.class_abondoned;
    //this->proficiencies = original.proficiencies;
    //this->affected_by = original.affected_by;
    //this->inventory = original.inventory;
    //this->abilities = original.abilities;
    //this->spells = original.spells;
    //this->race = original.race;
    //this->racial_enemy = original.racial_enemy;
    //this->prestige = original.prestige;
    //this->specialisation = original.specialisation;
    //this->special_abilities = original.special_abilities;
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
    //this->name = original.name;
    //this->biography = original.biography;
    //this->colour = original.colour;
    //this->alignment = original.alignment;
    //this->portrait = original.portrait;
    //this->female = original.female;
    //this->experience = original.experience;
    //this->level = original.level;
    //this->class_abondoned = original.class_abondoned;
    //this->proficiencies = original.proficiencies;
    //this->affected_by = original.affected_by;
    //this->inventory = original.inventory;
    //this->abilities = original.abilities;
    //this->spells = original.spells;
    //this->race = original.race;
    //this->racial_enemy = original.racial_enemy;
    //this->prestige = original.prestige;
    //this->specialisation = original.specialisation;
    //this->special_abilities = original.special_abilities;
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
    ////std::move(this->name, original.name);
    ////std::move(this->biography, original.biography);
    ////std::swap(this->colour, original.colour);
    ////std::swap(this->alignment, original.alignment);
    ////std::move(this->portrait, original.portrait);
    ////std::swap(this->female, original.female);
    ////std::move(this->experience, original.experience);
    ////std::move(this->level, original.level);
    ////std::move(this->class_abondoned, original.class_abondoned);
    ////std::move(this->proficiencies, original.proficiencies);
    ////std::move(this->affected_by, original.affected_by);
    ////std::move(this->inventory, original.inventory);
    ////std::move(this->abilities, original.abilities);
    ////std::move(this->spells, original.spells);
    ////std::move(this->race, original.race);
    ////std::move(this->racial_enemy, original.racial_enemy);
    ////std::move(this->prestige, original.prestige);
    ////std::move(this->specialisation, original.specialisation);
    ////std::move(this->special_abilities, original.special_abilities);
    return *this;
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

