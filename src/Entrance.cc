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
#include "Entrance.hpp"


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
  Entrance::Entrance() : Object()
  {
    this->class_inheritance.push_back(125);
    this->usable = true;
    this->description = "";
    this->direction = "";
    this->leads_to = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(const Entrance& original) : Object(original)
  {
    this->usable = original.usable;
    this->description = original.description;
    this->direction = original.direction;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance& original) : Object(original)
  {
    this->usable = original.usable;
    this->description = original.description;
    this->direction = original.direction;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance&& original) : Object(original)
  {
    std::swap(this->usable, original.usable);
    std::swap(this->description, original.description);
    std::swap(this->direction, original.direction);
    std::swap(this->leads_to, original.leads_to);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Entrance::fork() const
  {
    return (Object*)(new Entrance(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Entrance::~Entrance()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(const Entrance& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->usable = original.usable;
    this->description = original.description;
    this->direction = original.direction;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(Entrance& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->usable = original.usable;
    this->description = original.description;
    this->direction = original.direction;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(Entrance&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->usable, original.usable);
    std::swap(this->description, original.description);
    std::swap(this->direction, original.direction);
    std::swap(this->leads_to, original.leads_to);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Entrance::operator ==(const Entrance& other) const
  {
    if (this->usable != other.usable)  return false;
    if (this->description != other.description)  return false;
    if (this->direction != other.direction)  return false;
    if (this->leads_to != other.leads_to)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Entrance::operator !=(const Entrance& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Entrance::__copy__(Entrance& self, const Entrance& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Entrance::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<bool>()(this->usable);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->description);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::string>()(this->direction);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<_MapMinor*>()(this->leads_to);
    return rc;
  }
  
}

