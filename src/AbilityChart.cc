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
#include "AbilityChart.hpp"


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
  AbilityChart::AbilityChart() : Object()
  {
    this->class_inheritance.push_back(22);
    ////TODO implement constructor
    //this->strength = nullptr;
    //this->strength18 = nullptr;
    //this->dexterity = nullptr;
    //this->constitution = nullptr;
    //this->intelligence = nullptr;
    //this->wisdom = nullptr;
    //this->charisma = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(const AbilityChart& original) : Object(original)
  {
    (void) original;
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart& original) : Object(original)
  {
    (void) original;
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart&& original) : Object(original)
  {
    (void) original;
    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->constitution, original.constitution);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityChart::~AbilityChart()
  {
    ////TODO implement destructor
    //delete this->strength;
    //delete this->strength18;
    //delete this->dexterity;
    //delete this->constitution;
    //delete this->intelligence;
    //delete this->wisdom;
    //delete this->charisma;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(const AbilityChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(AbilityChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(AbilityChart&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->constitution, original.constitution);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool AbilityChart::operator ==(const AbilityChart& other) const
  {
    if (this->strength != other.strength)  return false;
    if (this->strength18 != other.strength18)  return false;
    if (this->dexterity != other.dexterity)  return false;
    if (this->constitution != other.constitution)  return false;
    if (this->intelligence != other.intelligence)  return false;
    if (this->wisdom != other.wisdom)  return false;
    if (this->charisma != other.charisma)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool AbilityChart::operator !=(const AbilityChart& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void AbilityChart::__copy__(AbilityChart& self, const AbilityChart& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t AbilityChart::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<AbilityBonus[]>()(strength);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<AbilityBonus[]>()(strength18);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<AbilityBonus[]>()(dexterity);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<AbilityBonus[]>()(constitution);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<AbilityBonus[]>()(intelligence);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<AbilityBonus[]>()(wisdom);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<AbilityBonus[]>()(charisma);
    return rc;
  }
  
}

