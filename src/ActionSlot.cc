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
#include "ActionSlot.hpp"
  
  
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
   * Construction
   * 
   * @param  typeID  The ID of the slot type
   */
  ActionSlot::ActionSlot(char typeID)
  {
    this->id = typeID;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlot::ActionSlot(const ActionSlot& original)
  {
    this->id = original.id;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlot::ActionSlot(ActionSlot& original)
  {
    this->id = original.id;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlot::ActionSlot(ActionSlot&& original)
  {
    std::swap(this->id, original.id);
  }
  
  
  
  /**
   * Destructor
   */
  ActionSlot::~ActionSlot()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ActionSlot& ActionSlot::operator =(const ActionSlot& original)
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
  ActionSlot& ActionSlot::operator =(ActionSlot& original)
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
  ActionSlot& ActionSlot::operator =(ActionSlot&& original)
  {
    std::swap(this->id, original.id);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ActionSlot::operator ==(const ActionSlot& other) const
  {
    return this->id == other.id;
  }
  
  
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ActionSlot::hash() const
  {
    return (size_t)(this->id);
  }
  
}

