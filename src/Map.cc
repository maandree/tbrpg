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
  Map::Map()
  {
    ////TODO implement constructor
    //this->start = nullptr;
    //this->majors = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(const Map& original)
  {
    (void) original;
    this->start = original.start;
    this->majors = original.majors;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(Map& original)
  {
    (void) original;
    this->start = original.start;
    this->majors = original.majors;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Map::Map(Map&& original)
  {
    (void) original;
    std::swap(this->start, original.start);
    std::swap(this->majors, original.majors);
  }
  
  
  
  /**
   * Destructor
   */
  Map::~Map()
  {
    ////TODO implement destructor
    //delete this->start;
    //delete this->majors;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Map& Map::operator =(const Map& original)
  {
    (void) original;
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
    (void) original;
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
    (void) original;
    std::swap(this->start, original.start);
    std::swap(this->majors, original.majors);
    return *this;
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
    return (size_t)this;
  }
  
}

