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
#include "BastardSword.hpp"


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
  BastardSword::BastardSword() : LargeSword()
  {
    this->name = "bastard sword";
    this->speed_factor = 8;
    this->damage_die = 4;
    this->damage_dice = 2;
    this->damage_type = {SLASHING};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BastardSword::BastardSword(const BastardSword& original) : LargeSword(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BastardSword::BastardSword(BastardSword& original) : LargeSword(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  BastardSword::BastardSword(BastardSword&& original) : LargeSword(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  BastardSword::~BastardSword()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BastardSword& BastardSword::operator =(const BastardSword& original)
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
  BastardSword& BastardSword::operator =(BastardSword& original)
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
  BastardSword& BastardSword::operator =(BastardSword&& original)
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
  bool BastardSword::operator ==(const BastardSword& other) const
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
  bool BastardSword::operator !=(const BastardSword& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void BastardSword::__copy__(BastardSword& self, const BastardSword& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t BastardSword::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<LargeSword>()(*this);
    return rc;
  }
  
}

