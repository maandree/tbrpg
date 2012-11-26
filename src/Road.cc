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
#include "Road.hpp"


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
  Road::Road()
  {
    //TODO implement constructor
    //name = nullptr;
    //visible = false;
    //visited = false;
    //visitable = false;
    //detectable = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Road::Road(const Road& original)
  {
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
  Road::Road(Road& original)
  {
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
  Road::Road(Road&& original)
  {
    std::move(this->name, original.name);
    std::swap(this->visible, original.visible);
    std::swap(this->visited, original.visited);
    std::swap(this->visitable, original.visitable);
    std::swap(this->detectable, original.detectable);
  }
  
  
  
  /**
   * Destructor
   */
  Road::~Road()
  {
    //TODO implement destructor
    //delete name;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Road& Road::operator =(const Road& original)
  {
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
  Road& Road::operator =(Road& original)
  {
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
  Road& Road::operator =(Road&& original)
  {
    std::move(this->name, original.name);
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
  static void Road::__copy__(Road& self, const Road& original);
  {
    left = right;
  }
  
}

