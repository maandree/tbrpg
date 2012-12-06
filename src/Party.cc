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
#include "Party.hpp"


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
  Party::Party() : Object()
  {
    this->class_inheritance.push_back(8);
    ////TODO implement constructor
    //this->reputation = 0;
    //this->characters = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Party::Party(const Party& original) : Object(original)
  {
    (void) original;
    this->reputation = original.reputation;
    this->characters = original.characters;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Party::Party(Party& original) : Object(original)
  {
    (void) original;
    this->reputation = original.reputation;
    this->characters = original.characters;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Party::Party(Party&& original) : Object(original)
  {
    (void) original;
    std::swap(this->reputation, original.reputation);
    std::swap(this->characters, original.characters);
  }
  
  
  
  /**
   * Destructor
   */
  Party::~Party()
  {
    ////TODO implement destructor
    //delete this->characters;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Party& Party::operator =(const Party& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->reputation = original.reputation;
    this->characters = original.characters;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Party& Party::operator =(Party& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->reputation = original.reputation;
    this->characters = original.characters;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Party& Party::operator =(Party&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->reputation, original.reputation);
    std::swap(this->characters, original.characters);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Party::operator ==(const Party& other) const
  {
    if (this->reputation != other.reputation)  return false;
    if (this->characters != other.characters)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Party::operator !=(const Party& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Party::__copy__(Party& self, const Party& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Party::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<int>()(reputation);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<std::vector<Character>>()(characters);
    return rc;
  }
  
}

