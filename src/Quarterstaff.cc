// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Quarterstaff.hpp"


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
  Quarterstaff::Quarterstaff() : TwoHandedMelee()
  {
    this->class_inheritance.push_back(55);
    ////TODO implement constructor
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Quarterstaff::Quarterstaff(const Quarterstaff& original) : TwoHandedMelee(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Quarterstaff::Quarterstaff(Quarterstaff& original) : TwoHandedMelee(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Quarterstaff::Quarterstaff(Quarterstaff&& original) : TwoHandedMelee(original)
  {
    (void) original;

  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Quarterstaff::fork() const
  {
    return (Object*)(new Quarterstaff(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Quarterstaff::~Quarterstaff()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Quarterstaff& Quarterstaff::operator =(const Quarterstaff& original)
  {
    (void) original;
    TwoHandedMelee::__copy__((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Quarterstaff& Quarterstaff::operator =(Quarterstaff& original)
  {
    (void) original;
    TwoHandedMelee::__copy__((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Quarterstaff& Quarterstaff::operator =(Quarterstaff&& original)
  {
    (void) original;
    std::swap((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Quarterstaff::operator ==(const Quarterstaff& other) const
  {
    if ((TwoHandedMelee&)(*this) != (TwoHandedMelee&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Quarterstaff::operator !=(const Quarterstaff& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Quarterstaff::__copy__(Quarterstaff& self, const Quarterstaff& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Quarterstaff::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<TwoHandedMelee>()(*this);
    return rc;
  }
  
}

