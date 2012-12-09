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
   * Constructor
   */
  Spell::Spell() : Object()
  {
    this->class_inheritance.push_back(21);
    ////TODO implement constructor
    //this->name = nullptr;
    //this->description = nullptr;
    //this->wizard = false;
    //this->priest = false;
    //this->level = 0;
    //this->saving = 0;
    //this->touch = false;
    //this->range = 0;
    //this->casting_time = 0;
    //this->duration = 0;
    //this->duration_die = 0;
    //this->duration_dice = 0;
    //this->effect_area = nullptr;
    //this->offensiveness = 0;
    //this->school = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(const Spell& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->offensiveness = original.offensiveness;
    this->school = original.school;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->offensiveness = original.offensiveness;
    this->school = original.school;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell&& original) : Object(original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->description, original.description);
    std::swap(this->wizard, original.wizard);
    std::swap(this->priest, original.priest);
    std::swap(this->level, original.level);
    std::swap(this->saving, original.saving);
    std::swap(this->touch, original.touch);
    std::swap(this->range, original.range);
    std::swap(this->casting_time, original.casting_time);
    std::swap(this->duration, original.duration);
    std::swap(this->duration_die, original.duration_die);
    std::swap(this->duration_dice, original.duration_dice);
    std::swap(this->effect_area, original.effect_area);
    std::swap(this->offensiveness, original.offensiveness);
    std::swap(this->school, original.school);
  }
  
  
  
  /**
   * Destructor
   */
  Spell::~Spell()
  {
    ////TODO implement destructor
    //delete this->name;
    //delete this->description;
    //delete this->effect_area;
    //delete this->school;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(const Spell& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->offensiveness = original.offensiveness;
    this->school = original.school;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->offensiveness = original.offensiveness;
    this->school = original.school;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->name, original.name);
    std::swap(this->description, original.description);
    std::swap(this->wizard, original.wizard);
    std::swap(this->priest, original.priest);
    std::swap(this->level, original.level);
    std::swap(this->saving, original.saving);
    std::swap(this->touch, original.touch);
    std::swap(this->range, original.range);
    std::swap(this->casting_time, original.casting_time);
    std::swap(this->duration, original.duration);
    std::swap(this->duration_die, original.duration_die);
    std::swap(this->duration_dice, original.duration_dice);
    std::swap(this->effect_area, original.effect_area);
    std::swap(this->offensiveness, original.offensiveness);
    std::swap(this->school, original.school);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Spell::operator ==(const Spell& other) const
  {
    if (this->name != other.name)  return false;
    if (this->description != other.description)  return false;
    if (this->wizard != other.wizard)  return false;
    if (this->priest != other.priest)  return false;
    if (this->level != other.level)  return false;
    if (this->saving != other.saving)  return false;
    if (this->touch != other.touch)  return false;
    if (this->range != other.range)  return false;
    if (this->casting_time != other.casting_time)  return false;
    if (this->duration != other.duration)  return false;
    if (this->duration_die != other.duration_die)  return false;
    if (this->duration_dice != other.duration_dice)  return false;
    if (this->effect_area != other.effect_area)  return false;
    if (this->offensiveness != other.offensiveness)  return false;
    if (this->school != other.school)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Spell::operator !=(const Spell& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Spell::__copy__(Spell& self, const Spell& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Spell::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->description);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<bool>()(this->wizard);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<bool>()(this->priest);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<char>()(this->level);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<char>()(this->saving);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<bool>()(this->touch);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<float>()(this->range);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<char>()(this->casting_time);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<char>()(this->duration);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<char>()(this->duration_die);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<char>()(this->duration_dice);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::string>()(this->effect_area);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<signed char>()(this->offensiveness);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<MagicSchool>()(this->school);
    return rc;
  }
  
}

