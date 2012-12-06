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
#include "Door.hpp"


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
  Door::Door() : Entrance(), Lockable()
  {
    this->class_inheritance.push_back(74);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Door::Door(const Door& original) : Entrance(original), Lockable(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Door::Door(Door& original) : Entrance(original), Lockable(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Door::Door(Door&& original) : Entrance(original), Lockable(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Door::~Door()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Door& Door::operator =(const Door& original)
  {
    Entrance::__copy__((Entrance&)*this, (Entrance&)original);
    Lockable::__copy__((Lockable&)*this, (Lockable&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Door& Door::operator =(Door& original)
  {
    Entrance::__copy__((Entrance&)*this, (Entrance&)original);
    Lockable::__copy__((Lockable&)*this, (Lockable&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Door& Door::operator =(Door&& original)
  {
    std::swap((Entrance&)*this, (Entrance&)original);
    std::swap((Lockable&)*this, (Lockable&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Door::operator ==(const Door& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Door::__copy__(Door& self, const Door& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Door::hash() const
  {
    return (size_t)this;
  }
  
}

