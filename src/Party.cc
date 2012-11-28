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
  Party::Party()
  {
    ////TODO implement constructor
    //this->reputation = 0;
    //this->characters = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Party::Party(const Party& original)
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
  Party::Party(Party& original)
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
  Party::Party(Party&& original)
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
    this->reputation = original.reputation;
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
    this->reputation = original.reputation;
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
    std::swap(this->reputation, original.reputation);
    std::swap(this->characters, original.characters);
    return *this;
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
    return (size_t)this;
  }
  
}

