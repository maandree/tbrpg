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
#include "WeaponGroup.hpp"


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
  WeaponGroup::WeaponGroup() : Object()
  {
    this->class_inheritance.push_back(15);
    ////TODO implement constructor
    //this->name = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(const WeaponGroup& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(WeaponGroup& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(WeaponGroup&& original) : Object(original)
  {
    (void) original;
    std::swap(this->name, original.name);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* WeaponGroup::fork() const
  {
    return new WeaponGroup(*this);
  }
  
  
  
  /**
   * Destructor
   */
  WeaponGroup::~WeaponGroup()
  {
    ////TODO implement destructor
    //delete this->name;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(const WeaponGroup& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(WeaponGroup& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(WeaponGroup&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->name, original.name);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool WeaponGroup::operator ==(const WeaponGroup& other) const
  {
    if (this->name != other.name)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool WeaponGroup::operator !=(const WeaponGroup& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void WeaponGroup::__copy__(WeaponGroup& self, const WeaponGroup& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t WeaponGroup::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    return rc;
  }
  
}

