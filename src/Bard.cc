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
#include "Bard.hpp"


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
  Bard::Bard() : Rogue()
  {
    this->class_inheritance.push_back(105);
    ////TODO implement constructor
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(const Bard& original) : Rogue(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(Bard& original) : Rogue(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(Bard&& original) : Rogue(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Bard::~Bard()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bard& Bard::operator =(const Bard& original)
  {
    (void) original;
    Rogue::__copy__((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bard& Bard::operator =(Bard& original)
  {
    (void) original;
    Rogue::__copy__((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Bard& Bard::operator =(Bard&& original)
  {
    (void) original;
    std::swap((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Bard::operator ==(const Bard& other) const
  {
    if ((Rogue&)(*this) != (Rogue&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Bard::operator !=(const Bard& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Bard::__copy__(Bard& self, const Bard& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Bard::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Rogue>()(*this);
    return rc;
  }
  
}

