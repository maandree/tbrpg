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
#include "SharedMemory.hpp"


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
  SharedMemory::SharedMemory() : Object()
  {
    this->class_inheritance.push_back(145);
    ////TODO implement constructor
    //this->map = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SharedMemory::SharedMemory(const SharedMemory& original) : Object(original)
  {
    (void) original;
    this->map = original.map;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SharedMemory::SharedMemory(SharedMemory& original) : Object(original)
  {
    (void) original;
    this->map = original.map;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SharedMemory::SharedMemory(SharedMemory&& original) : Object(original)
  {
    (void) original;
    std::swap(this->map, original.map);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* SharedMemory::fork() const
  {
    return (Object*)(new SharedMemory(*this));
  }
  
  
  
  /**
   * Destructor
   */
  SharedMemory::~SharedMemory()
  {
    ////TODO implement destructor
    //delete this->map;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SharedMemory& SharedMemory::operator =(const SharedMemory& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->map = original.map;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SharedMemory& SharedMemory::operator =(SharedMemory& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->map = original.map;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SharedMemory& SharedMemory::operator =(SharedMemory&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->map, original.map);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool SharedMemory::operator ==(const SharedMemory& other) const
  {
    if (this->map != other.map)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool SharedMemory::operator !=(const SharedMemory& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void SharedMemory::__copy__(SharedMemory& self, const SharedMemory& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t SharedMemory::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::unordered_map<std::string, void*>>()(this->map);
    return rc;
  }
  
}

