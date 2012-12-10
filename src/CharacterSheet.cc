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
    this->class_inheritance.push_back(22);
    this->racial_enemy = nullptr;
    this->name = "the nameless one";
    this->biography = "";
    this->hit_points = 8;
    this->colour = 5;
    this->alignment = 6;
    this->portrait = "";
    this->female = false;
    this->experience = {};
    this->level = {};
    this->class_abondoned = {};
    this->proficiencies = std::unordered_map<WeaponGroup, int>();
    this->affected_by = {};
    this->inventory = Inventory();
    this->abilities = AbilityBonus();
    this->spells = SpellBook();
    this->race = Race();
    this->prestige = {};
    this->specialisation = GENERAL_MAGE;
    this->special_abilities = {};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(const CharacterSheet& original) : Object(original)
  {
    this->name = original.name;
    this->biography = original.biography;
    this->hit_points = original.hit_points;
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
    this->name = original.name;
    this->biography = original.biography;
    this->hit_points = original.hit_points;
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
    std::swap(this->name, original.name);
    std::swap(this->biography, original.biography);
    std::swap(this->hit_points, original.hit_points);
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* CharacterSheet::fork() const
  {
    return new CharacterSheet(*this);
  }
  
  
  
  /**
   * Destructor
   */
  CharacterSheet::~CharacterSheet()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CharacterSheet& CharacterSheet::operator =(const CharacterSheet& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->biography = original.biography;
    this->hit_points = original.hit_points;
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
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->biography = original.biography;
    this->hit_points = original.hit_points;
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
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->name, original.name);
    std::swap(this->biography, original.biography);
    std::swap(this->hit_points, original.hit_points);
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
    if (this->name != other.name)  return false;
    if (this->biography != other.biography)  return false;
    if (this->hit_points != other.hit_points)  return false;
    if (this->colour != other.colour)  return false;
    if (this->alignment != other.alignment)  return false;
    if (this->portrait != other.portrait)  return false;
    if (this->female != other.female)  return false;
    if (this->experience != other.experience)  return false;
    if (this->level != other.level)  return false;
    if (this->class_abondoned != other.class_abondoned)  return false;
    if (this->proficiencies != other.proficiencies)  return false;
    if (this->affected_by != other.affected_by)  return false;
    if (this->inventory != other.inventory)  return false;
    if (this->abilities != other.abilities)  return false;
    if (this->spells != other.spells)  return false;
    if (this->race != other.race)  return false;
    if (this->racial_enemy != other.racial_enemy)  return false;
    if (this->prestige != other.prestige)  return false;
    if (this->specialisation != other.specialisation)  return false;
    if (this->special_abilities != other.special_abilities)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool CharacterSheet::operator !=(const CharacterSheet& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->biography);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->hit_points);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<char>()(this->colour);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<char>()(this->alignment);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::string>()(this->portrait);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<bool>()(this->female);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<int>>()(this->experience);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<char>>()(this->level);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<bool>>()(this->class_abondoned);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::unordered_map<WeaponGroup, int>>()(this->proficiencies);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<Spell>>()(this->affected_by);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<Inventory>()(this->inventory);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<AbilityBonus>()(this->abilities);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<SpellBook>()(this->spells);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<Race>()(this->race);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Race*>()(this->racial_enemy);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<Class>>()(this->prestige);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<MagicSchool>()(this->specialisation);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<Spell>>()(this->special_abilities);
    return rc;
  }
  
}

