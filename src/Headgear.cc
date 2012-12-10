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
#include "Headgear.hpp"


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
  Headgear::Headgear() : Item()
  {
    this->class_inheritance.push_back(13);
    ////TODO implement constructor
    //this->critical_hit_protection = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(const Headgear& original) : Item(original)
  {
    (void) original;
    this->critical_hit_protection = original.critical_hit_protection;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(Headgear& original) : Item(original)
  {
    (void) original;
    this->critical_hit_protection = original.critical_hit_protection;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(Headgear&& original) : Item(original)
  {
    (void) original;
    std::swap(this->critical_hit_protection, original.critical_hit_protection);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Headgear::fork() const
  {
    return new Headgear(*this);
  }
  
  
  
  /**
   * Destructor
   */
  Headgear::~Headgear()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(const Headgear& original)
  {
    (void) original;
    Item::__copy__((Item&)*this, (Item&)original);    this->critical_hit_protection = original.critical_hit_protection;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(Headgear& original)
  {
    (void) original;
    Item::__copy__((Item&)*this, (Item&)original);    this->critical_hit_protection = original.critical_hit_protection;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(Headgear&& original)
  {
    (void) original;
    std::swap((Item&)*this, (Item&)original);    std::swap(this->critical_hit_protection, original.critical_hit_protection);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Headgear::operator ==(const Headgear& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    if (this->critical_hit_protection != other.critical_hit_protection)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Headgear::operator !=(const Headgear& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Headgear::__copy__(Headgear& self, const Headgear& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Headgear::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->critical_hit_protection);
    return rc;
  }
  
}

