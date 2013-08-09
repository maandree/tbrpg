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
#include "ThrowingDagger.hpp"


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
  ThrowingDagger::ThrowingDagger() : Throwing()
  {
    this->class_inheritance.push_back(57);
    this->name = "throwing dagger";
    this->weapon_group = &SMALL_SWORDS;
    this->rate_of_fire = 2;
    this->speed_factor = 2;
    this->damage_die = 4;
    this->damage_dice = 1;
    this->damage_type = {PIERCING};
    this->weight = 450;
    this->unit_value = 90;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThrowingDagger::ThrowingDagger(const ThrowingDagger& original) : Throwing(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThrowingDagger::ThrowingDagger(ThrowingDagger& original) : Throwing(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ThrowingDagger::ThrowingDagger(ThrowingDagger&& original) : Throwing(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* ThrowingDagger::fork() const
  {
    return (Object*)(new ThrowingDagger(*this));
  }
  
  
  
  /**
   * Destructor
   */
  ThrowingDagger::~ThrowingDagger()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThrowingDagger& ThrowingDagger::operator =(const ThrowingDagger& original)
  {
    Throwing::__copy__((Throwing&)*this, (Throwing&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThrowingDagger& ThrowingDagger::operator =(ThrowingDagger& original)
  {
    Throwing::__copy__((Throwing&)*this, (Throwing&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ThrowingDagger& ThrowingDagger::operator =(ThrowingDagger&& original)
  {
    std::swap((Throwing&)*this, (Throwing&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ThrowingDagger::operator ==(const ThrowingDagger& other) const
  {
    if ((Throwing&)(*this) != (Throwing&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool ThrowingDagger::operator !=(const ThrowingDagger& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void ThrowingDagger::__copy__(ThrowingDagger& self, const ThrowingDagger& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ThrowingDagger::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Throwing>()(*this);
    return rc;
  }
  
}

