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
  MapMinor::MapMinor()
  {
    ////TODO implement constructor
    //this->description = nullptr;
    //this->may_rest = false;
    //this->area = 0;
    //this->road_count = 0;
    //this->connection_count = 0;
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
  MapMinor::MapMinor(const MapMinor& original)
  {
    (void) original;
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->road_count = original.road_count;
    this->connection_count = original.connection_count;
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
  MapMinor::MapMinor(MapMinor& original)
  {
    (void) original;
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->road_count = original.road_count;
    this->connection_count = original.connection_count;
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
  MapMinor::MapMinor(MapMinor&& original)
  {
    (void) original;
    std::swap(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::swap(this->area, original.area);
    std::swap(this->road_count, original.road_count);
    std::swap(this->connection_count, original.connection_count);
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
    //delete description;
    //delete roads;
    //delete connections;
    //delete items;
    //delete creatures;
    //delete is_in;
    //delete interruptions;
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
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->road_count = original.road_count;
    this->connection_count = original.connection_count;
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
    this->description = original.description;
    this->may_rest = original.may_rest;
    this->area = original.area;
    this->road_count = original.road_count;
    this->connection_count = original.connection_count;
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
    std::swap(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::swap(this->area, original.area);
    std::swap(this->road_count, original.road_count);
    std::swap(this->connection_count, original.connection_count);
    std::swap(this->roads, original.roads);
    std::swap(this->connections, original.connections);
    std::swap(this->items, original.items);
    std::swap(this->creatures, original.creatures);
    std::swap(this->is_in, original.is_in);
    std::swap(this->interruptions, original.interruptions);
    return *this;
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
    return (size_t)this;
  }
  
}

