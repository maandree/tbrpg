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
#include "LightCrossbow.hpp"


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
  LightCrossbow::LightCrossbow() : Crossbow()
  {
    this->class_inheritance.push_back(65);
    this->name = "light crossbow";
    this->speed_factor = 7;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LightCrossbow::LightCrossbow(const LightCrossbow& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LightCrossbow::LightCrossbow(LightCrossbow& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  LightCrossbow::LightCrossbow(LightCrossbow&& original) : Crossbow(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* LightCrossbow::fork() const
  {
    return (Object*)(new LightCrossbow(*this));
  }
  
  
  
  /**
   * Destructor
   */
  LightCrossbow::~LightCrossbow()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LightCrossbow& LightCrossbow::operator =(const LightCrossbow& original)
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
  LightCrossbow& LightCrossbow::operator =(LightCrossbow& original)
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
  LightCrossbow& LightCrossbow::operator =(LightCrossbow&& original)
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
  bool LightCrossbow::operator ==(const LightCrossbow& other) const
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
  bool LightCrossbow::operator !=(const LightCrossbow& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void LightCrossbow::__copy__(LightCrossbow& self, const LightCrossbow& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t LightCrossbow::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Crossbow>()(*this);
    return rc;
  }
  
}

