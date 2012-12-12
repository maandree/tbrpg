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
#include "BodyArmour.hpp"


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
  BodyArmour::BodyArmour() : Item()
  {
    this->class_inheritance.push_back(33);
    this->wizard_magic_use = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BodyArmour::BodyArmour(const BodyArmour& original) : Item(original)
  {
    this->wizard_magic_use = original.wizard_magic_use;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BodyArmour::BodyArmour(BodyArmour& original) : Item(original)
  {
    this->wizard_magic_use = original.wizard_magic_use;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  BodyArmour::BodyArmour(BodyArmour&& original) : Item(original)
  {
    std::swap(this->wizard_magic_use, original.wizard_magic_use);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* BodyArmour::fork() const
  {
    return (Object*)(new BodyArmour(*this));
  }
  
  
  
  /**
   * Destructor
   */
  BodyArmour::~BodyArmour()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BodyArmour& BodyArmour::operator =(const BodyArmour& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->wizard_magic_use = original.wizard_magic_use;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BodyArmour& BodyArmour::operator =(BodyArmour& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->wizard_magic_use = original.wizard_magic_use;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  BodyArmour& BodyArmour::operator =(BodyArmour&& original)
  {
    std::swap((Item&)*this, (Item&)original);
    std::swap(this->wizard_magic_use, original.wizard_magic_use);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool BodyArmour::operator ==(const BodyArmour& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    if (this->wizard_magic_use != other.wizard_magic_use)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool BodyArmour::operator !=(const BodyArmour& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void BodyArmour::__copy__(BodyArmour& self, const BodyArmour& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t BodyArmour::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->wizard_magic_use);
    return rc;
  }
  
}

