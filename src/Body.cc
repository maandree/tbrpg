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
#include "Body.hpp"


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
  Body::Body() : Item()
  {
    this->class_inheritance.push_back(28);
    this->name = "the body of ";
    this->weight = 90000;
    this->unit_value = -1;
    this->character = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Body::Body(const Body& original) : Item(original)
  {
    this->character = original.character;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Body::Body(Body& original) : Item(original)
  {
    this->character = original.character;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Body::Body(Body&& original) : Item(original)
  {
    std::swap(this->character, original.character);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Body::fork() const
  {
    return new Body(*this);
  }
  
  
  
  /**
   * Destructor
   */
  Body::~Body()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Body& Body::operator =(const Body& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->character = original.character;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Body& Body::operator =(Body& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->character = original.character;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Body& Body::operator =(Body&& original)
  {
    std::swap((Item&)*this, (Item&)original);
    std::swap(this->character, original.character);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Body::operator ==(const Body& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    if (this->character != other.character)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Body::operator !=(const Body& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Body::__copy__(Body& self, const Body& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Body::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Character>()(*(this->character));
    return rc;
  }
  
}

