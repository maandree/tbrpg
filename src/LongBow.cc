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
#include "LongBow.hpp"


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
  LongBow::LongBow() : Bow()
  {
    this->class_inheritance.push_back(66);
    this->name = "long bow";
    this->speed_factor = 8;
    this->hit_bonus = 1;
    this->weight = 1350;
    this->unit_value = 7500;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongBow::LongBow(const LongBow& original) : Bow(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongBow::LongBow(LongBow& original) : Bow(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  LongBow::LongBow(LongBow&& original) : Bow(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* LongBow::fork() const
  {
    return (Object*)(new LongBow(*this));
  }
  
  
  
  /**
   * Destructor
   */
  LongBow::~LongBow()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongBow& LongBow::operator =(const LongBow& original)
  {
    Bow::__copy__((Bow&)*this, (Bow&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongBow& LongBow::operator =(LongBow& original)
  {
    Bow::__copy__((Bow&)*this, (Bow&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  LongBow& LongBow::operator =(LongBow&& original)
  {
    std::swap((Bow&)*this, (Bow&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool LongBow::operator ==(const LongBow& other) const
  {
    if ((Bow&)(*this) != (Bow&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool LongBow::operator !=(const LongBow& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void LongBow::__copy__(LongBow& self, const LongBow& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t LongBow::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Bow>()(*this);
    return rc;
  }
  
}

