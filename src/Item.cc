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
#include "Item.hpp"


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
  Item::Item()
  {
    //TODO implement constructor
    //id = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Item::Item(const Item& original)
  {
    this->id = original.id;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Item::Item(Item& original)
  {
    this->id = original.id;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Item::Item(Item&& original)
  {
    std::move(this->id, original.id);
  }
  
  
  
  /**
   * Destructor
   */
  Item::~Item()
  {
    //TODO implement destructor
    //delete id;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Item& Item::operator =(const Item& original)
  {
    this->id = original.id;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Item& Item::operator =(Item& original)
  {
    this->id = original.id;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Item& Item::operator =(Item&& original)
  {
    std::move(this->id, original.id);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Item::__copy__(Item& self, const Item& original);
  {
    left = right;
  }
  
}

