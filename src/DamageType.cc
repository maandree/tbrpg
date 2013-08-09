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
#include "DamageType.hpp"


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
   * 
   * @param  damageTypeName  The name of the damage type
   */
  DamageType::DamageType(std::string damageTypeName) : Object()
  {
    this->class_inheritance.push_back(14);
    this->name = damageTypeName;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  DamageType::DamageType(const DamageType& original) : Object(original)
  {
    this->name = original.name;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  DamageType::DamageType(DamageType& original) : Object(original)
  {
    this->name = original.name;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  DamageType::DamageType(DamageType&& original) : Object(original)
  {
    std::swap(this->name, original.name);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* DamageType::fork() const
  {
    return (Object*)(new DamageType(*this));
  }
  
  
  
  /**
   * Destructor
   */
  DamageType::~DamageType()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  DamageType& DamageType::operator =(const DamageType& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  DamageType& DamageType::operator =(DamageType& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  DamageType& DamageType::operator =(DamageType&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->name, original.name);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool DamageType::operator ==(const DamageType& other) const
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
  bool DamageType::operator !=(const DamageType& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void DamageType::__copy__(DamageType& self, const DamageType& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t DamageType::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    return rc;
  }
  
}

