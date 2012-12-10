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
#include "Ranger.hpp"


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
  Ranger::Ranger() : Warrior()
  {
    this->class_inheritance.push_back(108);
    ////TODO implement constructor
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(const Ranger& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(Ranger& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(Ranger&& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Ranger::fork() const
  {
    return (Object*)(new Ranger(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Ranger::~Ranger()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ranger& Ranger::operator =(const Ranger& original)
  {
    (void) original;
    Warrior::__copy__((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ranger& Ranger::operator =(Ranger& original)
  {
    (void) original;
    Warrior::__copy__((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Ranger& Ranger::operator =(Ranger&& original)
  {
    (void) original;
    std::swap((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Ranger::operator ==(const Ranger& other) const
  {
    if ((Warrior&)(*this) != (Warrior&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Ranger::operator !=(const Ranger& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Ranger::__copy__(Ranger& self, const Ranger& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Ranger::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Warrior>()(*this);
    return rc;
  }
  
}

