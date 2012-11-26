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
#include "RestInterruption.hpp"


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
  RestInterruption::RestInterruption()
  {
    //TODO implement constructor
    //description = nullptr;
    //may_rest = false;
    //area = nullptr;
    //roads = nullptr;
    //connections = nullptr;
    //items = nullptr;
    //creatures = nullptr;
    //is_in = nullptr;
    //interruptions = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RestInterruption::RestInterruption(const RestInterruption& original)
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
  RestInterruption::RestInterruption(RestInterruption& original)
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
  RestInterruption::RestInterruption(RestInterruption&& original)
  {
    std::move(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::move(this->area, original.area);
    std::move(this->roads, original.roads);
    std::move(this->connections, original.connections);
    std::move(this->items, original.items);
    std::move(this->creatures, original.creatures);
    std::move(this->is_in, original.is_in);
    std::move(this->interruptions, original.interruptions);
  }
  
  
  
  /**
   * Destructor
   */
  RestInterruption::~RestInterruption()
  {
    //TODO implement destructor
    //delete description;
    //delete area;
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
  RestInterruption& RestInterruption::operator =(const RestInterruption& original)
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
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RestInterruption& RestInterruption::operator =(RestInterruption& original)
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
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  RestInterruption& RestInterruption::operator =(RestInterruption&& original)
  {
    std::move(this->description, original.description);
    std::swap(this->may_rest, original.may_rest);
    std::move(this->area, original.area);
    std::move(this->roads, original.roads);
    std::move(this->connections, original.connections);
    std::move(this->items, original.items);
    std::move(this->creatures, original.creatures);
    std::move(this->is_in, original.is_in);
    std::move(this->interruptions, original.interruptions);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void RestInterruption::__copy__(RestInterruption& self, const RestInterruption& original);
  {
    left = right;
  }
  
}

