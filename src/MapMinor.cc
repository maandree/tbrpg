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
    this->class_inheritance.push_back(127);
    this->may_rest = true;
    this->area = 100;
    this->description = "";
    this->is_in = PROTOTYPE(MapMajor());
    this->roads = {};
    this->connections = {};
    this->items = {};
    this->creatures = {};
    this->interruptions = {};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMinor::MapMinor(const MapMinor& original) : _MapMinor(original)
  {
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* MapMinor::fork() const
  {
    return (Object*)(new MapMinor(*this));
  }
  
  
  
  /**
   * Destructor
   */
  MapMinor::~MapMinor()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMinor& MapMinor::operator =(const MapMinor& original)
  {
    _MapMinor::__copy__((_MapMinor&)*this, (_MapMinor&)original);
    this->description = original.description;
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
    _MapMinor::__copy__((_MapMinor&)*this, (_MapMinor&)original);
    this->description = original.description;
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
    std::swap((_MapMinor&)*this, (_MapMinor&)original);
    std::swap(this->description, original.description);
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
   * Resting function
   * 
   * @return  Whether the party successfully slept
   */
  bool MapMinor::rest()
  {
    if (this->may_rest == false)
      {
	std::cout << "May not rest here, either find an inn or rest outside." << std::endl;
	return false;
      }
    
    for (RestInterruption& interruption : this->interruptions)
      if (Dice(interruption.interrupt_dice, interruption.interrupt_die).roll() <= interruption.interrupt_risk)
	{
	  int monsters = 0;
	  for (Creature& creature : interruption.creatures)
	    {
	      this->creatures.push_back(Creature(creature));
	      monsters++;
	    }
	  
	  if (monsters == 0)
	    std::cout << "You woke up by a terrifing vivid nightmare." << std::endl;
	  else
	    std::cout << "You woke up monsters." << std::endl;
	  return false;
	}
    
    return true;
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
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<_MapMinor>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->description);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<bool>()(this->may_rest);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<float>()(this->area);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::vector<Road>>()(this->roads);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::vector<Entrance>>()(this->connections);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<std::vector<Item*>>()(this->items);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<Creature>>()(this->creatures);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<MapMajor>()(this->is_in);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<RestInterruption>>()(this->interruptions);
    return rc;
  }
  
}

