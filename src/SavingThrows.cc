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
#include "SavingThrows.hpp"


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
  SavingThrows::SavingThrows() : Object()
  {
    this->class_inheritance.push_back(6);
    ////TODO implement constructor
    //this->breath = 0;
    //this->paralyze_poison_death = 0;
    //this->petrification_polymorph = 0;
    //this->rod_staff_wand = 0;
    //this->spell = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(const SavingThrows& original) : Object(original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows& original) : Object(original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows&& original) : Object(original)
  {
    (void) original;
    std::swap(this->breath, original.breath);
    std::swap(this->paralyze_poison_death, original.paralyze_poison_death);
    std::swap(this->petrification_polymorph, original.petrification_polymorph);
    std::swap(this->rod_staff_wand, original.rod_staff_wand);
    std::swap(this->spell, original.spell);
  }
  
  
  
  /**
   * Destructor
   */
  SavingThrows::~SavingThrows()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(const SavingThrows& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->breath, original.breath);
    std::swap(this->paralyze_poison_death, original.paralyze_poison_death);
    std::swap(this->petrification_polymorph, original.petrification_polymorph);
    std::swap(this->rod_staff_wand, original.rod_staff_wand);
    std::swap(this->spell, original.spell);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool SavingThrows::operator ==(const SavingThrows& other) const
  {
    if (this->breath != other.breath)  return false;
    if (this->paralyze_poison_death != other.paralyze_poison_death)  return false;
    if (this->petrification_polymorph != other.petrification_polymorph)  return false;
    if (this->rod_staff_wand != other.rod_staff_wand)  return false;
    if (this->spell != other.spell)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool SavingThrows::operator !=(const SavingThrows& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void SavingThrows::__copy__(SavingThrows& self, const SavingThrows& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t SavingThrows::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<int>()(breath);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<int>()(paralyze_poison_death);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<int>()(petrification_polymorph);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<int>()(rod_staff_wand);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<int>()(spell);
    return rc;
  }
  
}

