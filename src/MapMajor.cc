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
  MapMajor::MapMajor()
  {
    ////TODO implement constructor
    //this->name = nullptr;
    //this->visible = false;
    //this->visited = false;
    //this->visitable = false;
    //this->detectable = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(const MapMajor& original)
  {
    (void) original;
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(MapMajor& original)
  {
    (void) original;
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  MapMajor::MapMajor(MapMajor&& original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->visible, original.visible);
    std::swap(this->visited, original.visited);
    std::swap(this->visitable, original.visitable);
    std::swap(this->detectable, original.detectable);
  }
  
  
  
  /**
   * Destructor
   */
  MapMajor::~MapMajor()
  {
    ////TODO implement destructor
    //delete name;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MapMajor& MapMajor::operator =(const MapMajor& original)
  {
    (void) original;
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
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
    (void) original;
    this->name = original.name;
    this->visible = original.visible;
    this->visited = original.visited;
    this->visitable = original.visitable;
    this->detectable = original.detectable;
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
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->visible, original.visible);
    std::swap(this->visited, original.visited);
    std::swap(this->visitable, original.visitable);
    std::swap(this->detectable, original.detectable);
    return *this;
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
    return (size_t)this;
  }
  
}

