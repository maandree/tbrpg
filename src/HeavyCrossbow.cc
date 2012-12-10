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
#include "HeavyCrossbow.hpp"


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
  HeavyCrossbow::HeavyCrossbow() : Crossbow()
  {
    this->class_inheritance.push_back(64);
    this->name = "heavy crossbow";
    this->speed_factor = 10;
    this->damage_bonus = 2;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HeavyCrossbow::HeavyCrossbow(const HeavyCrossbow& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HeavyCrossbow::HeavyCrossbow(HeavyCrossbow& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  HeavyCrossbow::HeavyCrossbow(HeavyCrossbow&& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* HeavyCrossbow::fork() const
  {
    return new HeavyCrossbow(*this);
  }
  
  
  
  /**
   * Destructor
   */
  HeavyCrossbow::~HeavyCrossbow()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  HeavyCrossbow& HeavyCrossbow::operator =(const HeavyCrossbow& original)
  {
    Crossbow::__copy__((Crossbow&)*this, (Crossbow&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  HeavyCrossbow& HeavyCrossbow::operator =(HeavyCrossbow& original)
  {
    Crossbow::__copy__((Crossbow&)*this, (Crossbow&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  HeavyCrossbow& HeavyCrossbow::operator =(HeavyCrossbow&& original)
  {
    std::swap((Crossbow&)*this, (Crossbow&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool HeavyCrossbow::operator ==(const HeavyCrossbow& other) const
  {
    if ((Crossbow&)(*this) != (Crossbow&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool HeavyCrossbow::operator !=(const HeavyCrossbow& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void HeavyCrossbow::__copy__(HeavyCrossbow& self, const HeavyCrossbow& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t HeavyCrossbow::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Crossbow>()(*this);
    return rc;
  }
  
}

