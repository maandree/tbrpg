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
#include "Gauntlets.hpp"


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
  Gauntlets::Gauntlets() : Item()
  {
    this->class_inheritance.push_back(99);
    this->name = "gauntlets";
    this->weight = 500;
    this->unit_value = 75;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Gauntlets::Gauntlets(const Gauntlets& original) : Item(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Gauntlets::Gauntlets(Gauntlets& original) : Item(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Gauntlets::Gauntlets(Gauntlets&& original) : Item(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Gauntlets::fork() const
  {
    return (Object*)(new Gauntlets(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Gauntlets::~Gauntlets()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Gauntlets& Gauntlets::operator =(const Gauntlets& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Gauntlets& Gauntlets::operator =(Gauntlets& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Gauntlets& Gauntlets::operator =(Gauntlets&& original)
  {
    std::swap((Item&)*this, (Item&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Gauntlets::operator ==(const Gauntlets& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Gauntlets::operator !=(const Gauntlets& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Gauntlets::__copy__(Gauntlets& self, const Gauntlets& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Gauntlets::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    return rc;
  }
  
}

