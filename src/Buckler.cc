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
#include "Buckler.hpp"


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
  Buckler::Buckler() : Shield()
  {
    this->class_inheritance.push_back(68);
    this->name = "buckler";
    this->protect_melee[PIERCING] = false;
    this->protect_missile = false;
    this->weight = 1350;
    this->unit_value = 75;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Buckler::Buckler(const Buckler& original) : Shield(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Buckler::Buckler(Buckler& original) : Shield(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Buckler::Buckler(Buckler&& original) : Shield(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Buckler::fork() const
  {
    return (Object*)(new Buckler(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Buckler::~Buckler()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Buckler& Buckler::operator =(const Buckler& original)
  {
    Shield::__copy__((Shield&)*this, (Shield&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Buckler& Buckler::operator =(Buckler& original)
  {
    Shield::__copy__((Shield&)*this, (Shield&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Buckler& Buckler::operator =(Buckler&& original)
  {
    std::swap((Shield&)*this, (Shield&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Buckler::operator ==(const Buckler& other) const
  {
    if ((Shield&)(*this) != (Shield&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Buckler::operator !=(const Buckler& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Buckler::__copy__(Buckler& self, const Buckler& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Buckler::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Shield>()(*this);
    return rc;
  }
  
}

