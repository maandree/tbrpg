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
#include "LongSword.hpp"


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
  LongSword::LongSword() : LargeSword()
  {
    this->class_inheritance.push_back(46);
    this->name = "long sword";
    this->speed_factor = 5;
    this->damage_die = 8;
    this->damage_dice = 1;
    this->damage_type = {SLASHING};
    this->weight = 1800;
    this->unit_value = 1450;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(const LongSword& original) : LargeSword(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(LongSword& original) : LargeSword(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(LongSword&& original) : LargeSword(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* LongSword::fork() const
  {
    return (Object*)(new LongSword(*this));
  }
  
  
  
  /**
   * Destructor
   */
  LongSword::~LongSword()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(const LongSword& original)
  {
    LargeSword::__copy__((LargeSword&)*this, (LargeSword&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(LongSword& original)
  {
    LargeSword::__copy__((LargeSword&)*this, (LargeSword&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(LongSword&& original)
  {
    std::swap((LargeSword&)*this, (LargeSword&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool LongSword::operator ==(const LongSword& other) const
  {
    if ((LargeSword&)(*this) != (LargeSword&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool LongSword::operator !=(const LongSword& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void LongSword::__copy__(LongSword& self, const LongSword& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t LongSword::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<LargeSword>()(*this);
    return rc;
  }
  
}

