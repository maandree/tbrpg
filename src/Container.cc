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
#include "Container.hpp"


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
  Container::Container()
  {
    //TODO implement constructor
    //learned = nullptr;
    //memorised = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(const Container& original)
  {
    this->learned = original.learned;
    this->memorised = original.memorised;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(Container& original)
  {
    this->learned = original.learned;
    this->memorised = original.memorised;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(Container&& original)
  {
    std::move(this->learned, original.learned);
    std::move(this->memorised, original.memorised);
  }
  
  
  
  /**
   * Destructor
   */
  Container::~Container()
  {
    //TODO implement destructor
    //delete learned;
    //delete memorised;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Container& Container::operator =(const Container& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->learned = original.learned;
    this->memorised = original.memorised;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Container& Container::operator =(Container& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->learned = original.learned;
    this->memorised = original.memorised;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Container& Container::operator =(Container&& original)
  {
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);    std::move(this->learned, original.learned);
    std::move(this->memorised, original.memorised);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Container::__copy__(Container& self, const Container& original);
  {
    left = right;
  }
  
}

