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
#include "LeatherArmour.hpp"


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
  LeatherArmour::LeatherArmour() : BodyArmour()
  {
    this->class_inheritance.push_back(83);
    this->name = "leather armour";
    this->armour_class = 8;
    this->armour_class_modifiers[PIERCING] = 2;
    this->wizard_magic_use = true;
    this->weight = 6400;
    this->unit_value = 450;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LeatherArmour::LeatherArmour(const LeatherArmour& original) : BodyArmour(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LeatherArmour::LeatherArmour(LeatherArmour& original) : BodyArmour(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  LeatherArmour::LeatherArmour(LeatherArmour&& original) : BodyArmour(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* LeatherArmour::fork() const
  {
    return (Object*)(new LeatherArmour(*this));
  }
  
  
  
  /**
   * Destructor
   */
  LeatherArmour::~LeatherArmour()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LeatherArmour& LeatherArmour::operator =(const LeatherArmour& original)
  {
    BodyArmour::__copy__((BodyArmour&)*this, (BodyArmour&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LeatherArmour& LeatherArmour::operator =(LeatherArmour& original)
  {
    BodyArmour::__copy__((BodyArmour&)*this, (BodyArmour&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  LeatherArmour& LeatherArmour::operator =(LeatherArmour&& original)
  {
    std::swap((BodyArmour&)*this, (BodyArmour&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool LeatherArmour::operator ==(const LeatherArmour& other) const
  {
    if ((BodyArmour&)(*this) != (BodyArmour&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool LeatherArmour::operator !=(const LeatherArmour& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void LeatherArmour::__copy__(LeatherArmour& self, const LeatherArmour& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t LeatherArmour::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<BodyArmour>()(*this);
    return rc;
  }
  
}

