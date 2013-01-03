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
#include "MapMajor.hpp"


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
  MapMajor::MapMajor() : Object()
  {
    this->class_inheritance.push_back(131);
    this->name = "";
    this->visible = false;
    this->visited = false;
    this->visitable = true;
    this->detectable = true;
    this->minors = {};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(const MapMajor& original) : Object(original)
  {
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
    this->minors = original.minors;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(MapMajor& original) : Object(original)
  {
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
    this->minors = original.minors;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(MapMajor&& original) : Object(original)
  {
    std::swap(this->name, original.name);
    std::swap(this->visible, original.visible);
    std::swap(this->visited, original.visited);
    std::swap(this->visitable, original.visitable);
    std::swap(this->detectable, original.detectable);
    std::swap(this->minors, original.minors);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* MapMajor::fork() const
  {
    return (Object*)(new MapMajor(*this));
  }
  
  
  
  /**
   * Destructor
   */
  MapMajor::~MapMajor()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMajor& MapMajor::operator =(const MapMajor& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
    this->minors = original.minors;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMajor& MapMajor::operator =(MapMajor& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
    this->minors = original.minors;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  MapMajor& MapMajor::operator =(MapMajor&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->name, original.name);
    std::swap(this->visible, original.visible);
    std::swap(this->visited, original.visited);
    std::swap(this->visitable, original.visitable);
    std::swap(this->detectable, original.detectable);
    std::swap(this->minors, original.minors);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool MapMajor::operator ==(const MapMajor& other) const
  {
    if (this->name != other.name)  return false;
    if (this->visible != other.visible)  return false;
    if (this->visited != other.visited)  return false;
    if (this->visitable != other.visitable)  return false;
    if (this->detectable != other.detectable)  return false;
    if (this->minors != other.minors)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool MapMajor::operator !=(const MapMajor& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void MapMajor::__copy__(MapMajor& self, const MapMajor& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t MapMajor::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->visible);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<bool>()(this->visited);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<bool>()(this->visitable);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<bool>()(this->detectable);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::vector<_MapMinor>>()(this->minors);
    return rc;
  }
  
}

