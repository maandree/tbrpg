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
#include "MapMinor.hpp"


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
  MapMinor::MapMinor() : _MapMinor()
  {
    this->class_inheritance.push_back(67);
    ////TODO implement constructor
    //this->description = nullptr;
    //this->may_rest = false;
    //this->area = 0;
    //this->roads = nullptr;
    //this->connections = nullptr;
    //this->items = nullptr;
    //this->creatures = nullptr;
    //this->is_in = nullptr;
    //this->interruptions = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMinor::MapMinor(const MapMinor& original) : _MapMinor(original)
  {
    (void) original;
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->roads = original.roads;
    this->connections = original.connections;
    this->items = original.items;
    this->creatures = original.creatures;
    this->is_in = original.is_in;
    this->interruptions = original.interruptions;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMinor::MapMinor(MapMinor& original) : _MapMinor(original)
  {
    (void) original;
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->roads = original.roads;
    this->connections = original.connections;
    this->items = original.items;
    this->creatures = original.creatures;
    this->is_in = original.is_in;
    this->interruptions = original.interruptions;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  MapMinor::MapMinor(MapMinor&& original) : _MapMinor(original)
  {
    (void) original;
    std::swap(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::swap(this->area, original.area);
    std::swap(this->roads, original.roads);
    std::swap(this->connections, original.connections);
    std::swap(this->items, original.items);
    std::swap(this->creatures, original.creatures);
    std::swap(this->is_in, original.is_in);
    std::swap(this->interruptions, original.interruptions);
  }
  
  
  
  /**
   * Destructor
   */
  MapMinor::~MapMinor()
  {
    ////TODO implement destructor
    //delete this->description;
    //delete this->roads;
    //delete this->connections;
    //delete this->items;
    //delete this->creatures;
    //delete this->is_in;
    //delete this->interruptions;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMinor& MapMinor::operator =(const MapMinor& original)
  {
    (void) original;
    _MapMinor::__copy__((_MapMinor&)*this, (_MapMinor&)original);    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->roads = original.roads;
    this->connections = original.connections;
    this->items = original.items;
    this->creatures = original.creatures;
    this->is_in = original.is_in;
    this->interruptions = original.interruptions;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMinor& MapMinor::operator =(MapMinor& original)
  {
    (void) original;
    _MapMinor::__copy__((_MapMinor&)*this, (_MapMinor&)original);    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->roads = original.roads;
    this->connections = original.connections;
    this->items = original.items;
    this->creatures = original.creatures;
    this->is_in = original.is_in;
    this->interruptions = original.interruptions;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  MapMinor& MapMinor::operator =(MapMinor&& original)
  {
    (void) original;
    std::swap((_MapMinor&)*this, (_MapMinor&)original);    std::swap(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::swap(this->area, original.area);
    std::swap(this->roads, original.roads);
    std::swap(this->connections, original.connections);
    std::swap(this->items, original.items);
    std::swap(this->creatures, original.creatures);
    std::swap(this->is_in, original.is_in);
    std::swap(this->interruptions, original.interruptions);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool MapMinor::operator ==(const MapMinor& other) const
  {
    if ((_MapMinor&)(*this) != (_MapMinor&)other)  return false;
    if (this->description != other.description)  return false;
    if (this->may_rest != other.may_rest)  return false;
    if (this->area != other.area)  return false;
    if (this->roads != other.roads)  return false;
    if (this->connections != other.connections)  return false;
    if (this->items != other.items)  return false;
    if (this->creatures != other.creatures)  return false;
    if (this->is_in != other.is_in)  return false;
    if (this->interruptions != other.interruptions)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool MapMinor::operator !=(const MapMinor& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void MapMinor::__copy__(MapMinor& self, const MapMinor& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t MapMinor::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<_MapMinor>()(*this);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<std::string>()(description);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<bool>()(may_rest);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<float>()(area);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<std::vector<Road>>()(roads);
    rc = (rc * 13) ^ (rc >> (sizeof(size_t) << 2) * 13);
    rc += std::hash<std::vector<Entrance>>()(connections);
    rc = (rc * 17) ^ (rc >> (sizeof(size_t) << 2) * 17);
    rc += std::hash<std::vector<Item>>()(items);
    rc = (rc * 19) ^ (rc >> (sizeof(size_t) << 2) * 19);
    rc += std::hash<std::vector<Creature>>()(creatures);
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<MapMajor>()(is_in);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<std::vector<RestInterruption>>()(interruptions);
    return rc;
  }
  
}

