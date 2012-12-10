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
#include "Bolt.hpp"


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
  Bolt::Bolt() : Ammunition()
  {
    this->class_inheritance.push_back(75);
    this->name = "bolt";
    this->damage_type = PIERCING;
    this->damage_die = 6;
    this->damage_dice = 1;
    this->damage_bonus = 0;
    this->usable_with = PROTOTYPE(Crossbow);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bolt::Bolt(const Bolt& original) : Ammunition(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bolt::Bolt(Bolt& original) : Ammunition(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Bolt::Bolt(Bolt&& original) : Ammunition(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Bolt::~Bolt()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bolt& Bolt::operator =(const Bolt& original)
  {
    Ammunition::__copy__((Ammunition&)*this, (Ammunition&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bolt& Bolt::operator =(Bolt& original)
  {
    Ammunition::__copy__((Ammunition&)*this, (Ammunition&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Bolt& Bolt::operator =(Bolt&& original)
  {
    std::swap((Ammunition&)*this, (Ammunition&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Bolt::operator ==(const Bolt& other) const
  {
    if ((Ammunition&)(*this) != (Ammunition&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Bolt::operator !=(const Bolt& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Bolt::__copy__(Bolt& self, const Bolt& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Bolt::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Ammunition>()(*this);
    return rc;
  }
  
}

