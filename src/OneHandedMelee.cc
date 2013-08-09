// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "OneHandedMelee.hpp"


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
  OneHandedMelee::OneHandedMelee() : MeleeWeapon()
  {
    this->class_inheritance.push_back(48);
    this->hands = 1;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  OneHandedMelee::OneHandedMelee(const OneHandedMelee& original) : MeleeWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  OneHandedMelee::OneHandedMelee(OneHandedMelee& original) : MeleeWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  OneHandedMelee::OneHandedMelee(OneHandedMelee&& original) : MeleeWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* OneHandedMelee::fork() const
  {
    return (Object*)(new OneHandedMelee(*this));
  }
  
  
  
  /**
   * Destructor
   */
  OneHandedMelee::~OneHandedMelee()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  OneHandedMelee& OneHandedMelee::operator =(const OneHandedMelee& original)
  {
    MeleeWeapon::__copy__((MeleeWeapon&)*this, (MeleeWeapon&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  OneHandedMelee& OneHandedMelee::operator =(OneHandedMelee& original)
  {
    MeleeWeapon::__copy__((MeleeWeapon&)*this, (MeleeWeapon&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  OneHandedMelee& OneHandedMelee::operator =(OneHandedMelee&& original)
  {
    std::swap((MeleeWeapon&)*this, (MeleeWeapon&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool OneHandedMelee::operator ==(const OneHandedMelee& other) const
  {
    if ((MeleeWeapon&)(*this) != (MeleeWeapon&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool OneHandedMelee::operator !=(const OneHandedMelee& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void OneHandedMelee::__copy__(OneHandedMelee& self, const OneHandedMelee& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t OneHandedMelee::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<MeleeWeapon>()(*this);
    return rc;
  }
  
}

