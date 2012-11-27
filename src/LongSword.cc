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
#include "LongSword.hpp"


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
  LongSword::LongSword() : LargeSword()
  {
    ////TODO implement constructor
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(const LongSword& original) : LargeSword(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(LongSword& original) : LargeSword(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  LongSword::LongSword(LongSword&& original) : LargeSword(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  LongSword::~LongSword()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(const LongSword& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(LongSword& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  LongSword& LongSword::operator =(LongSword&& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void LongSword::__copy__(LongSword& self, const LongSword& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t LongSword::hash() const
  {
    return (size_t)this;
  }
  
}
