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
#include "Map.hpp"


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
  Map::Map() : Object()
  {
    this->class_inheritance.push_back(130);
    this->start = MapMinor();
    this->majors = {};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(const Map& original) : Object(original)
  {
    this->start = original.start;
    this->majors = original.majors;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(Map& original) : Object(original)
  {
    this->start = original.start;
    this->majors = original.majors;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(Map&& original) : Object(original)
  {
    std::swap(this->start, original.start);
    std::swap(this->majors, original.majors);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Map::fork() const
  {
    return (Object*)(new Map(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Map::~Map()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Map& Map::operator =(const Map& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->start = original.start;
    this->majors = original.majors;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Map& Map::operator =(Map& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->start = original.start;
    this->majors = original.majors;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Map& Map::operator =(Map&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->start, original.start);
    std::swap(this->majors, original.majors);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Map::operator ==(const Map& other) const
  {
    if (this->start != other.start)  return false;
    if (this->majors != other.majors)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Map::operator !=(const Map& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Map::__copy__(Map& self, const Map& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Map::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<MapMinor>()(this->start);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<MapMajor>>()(this->majors);
    return rc;
  }
  
}

