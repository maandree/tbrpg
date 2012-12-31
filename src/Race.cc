// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Race.hpp"


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
  Race::Race() : Object()
  {
    this->class_inheritance.push_back(20);
    this->name = "?";
    this->allowed_classes = {};
    this->bonuses = AbilityBonus();
    this->dualclass_level = 0x7FFF;
    this->specialisations = {GENERAL_MAGE, ABJURATION, ALTERATION,
			     CONJURATION, DIVINATION, ENCHANTMENT,
			     ILLUSION, INVOCATION, NECROMANCY};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(const Race& original) : Object(original)
  {
    this->name = original.name;
    this->allowed_classes = original.allowed_classes;
    this->dualclass_level = original.dualclass_level;
    this->specialisations = original.specialisations;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race& original) : Object(original)
  {
    this->name = original.name;
    this->allowed_classes = original.allowed_classes;
    this->dualclass_level = original.dualclass_level;
    this->specialisations = original.specialisations;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race&& original) : Object(original)
  {
    std::swap(this->name, original.name);
    std::swap(this->allowed_classes, original.allowed_classes);
    std::swap(this->dualclass_level, original.dualclass_level);
    std::swap(this->specialisations, original.specialisations);
    std::swap(this->bonuses, original.bonuses);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Race::fork() const
  {
    return (Object*)(new Race(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Race::~Race()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(const Race& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->allowed_classes = original.allowed_classes;
    this->dualclass_level = original.dualclass_level;
    this->specialisations = original.specialisations;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(Race& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->allowed_classes = original.allowed_classes;
    this->dualclass_level = original.dualclass_level;
    this->specialisations = original.specialisations;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Race& Race::operator =(Race&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->name, original.name);
    std::swap(this->allowed_classes, original.allowed_classes);
    std::swap(this->dualclass_level, original.dualclass_level);
    std::swap(this->specialisations, original.specialisations);
    std::swap(this->bonuses, original.bonuses);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Race::operator ==(const Race& other) const
  {
    if (this->name != other.name)  return false;
    if (this->allowed_classes != other.allowed_classes)  return false;
    if (this->dualclass_level != other.dualclass_level)  return false;
    if (this->specialisations != other.specialisations)  return false;
    if (this->bonuses != other.bonuses)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Race::operator !=(const Race& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Race::__copy__(Race& self, const Race& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Race::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<std::vector<Class>>>()(this->allowed_classes);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<short>()(this->dualclass_level);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<MagicSchool>>()(this->specialisations);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<AbilityBonus>()(this->bonuses);
    return rc;
  }
  
}

