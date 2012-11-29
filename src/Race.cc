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
#include "Race.hpp"


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
  Race::Race()
  {
    ////TODO implement constructor
    //this->allowed_classes = nullptr;
    //this->bonuses = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(const Race& original)
  {
    (void) original;
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race& original)
  {
    (void) original;
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race&& original)
  {
    (void) original;
    std::swap(this->allowed_classes, original.allowed_classes);
    std::swap(this->bonuses, original.bonuses);
  }
  
  
  
  /**
   * Destructor
   */
  Race::~Race()
  {
    ////TODO implement destructor
    //delete this->allowed_classes;
    //delete this->bonuses;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(const Race& original)
  {
    (void) original;
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(Race& original)
  {
    (void) original;
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Race& Race::operator =(Race&& original)
  {
    (void) original;
    std::swap(this->allowed_classes, original.allowed_classes);
    std::swap(this->bonuses, original.bonuses);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Race::operation ==(const Race& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Race::__copy__(Race& self, const Race& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Race::hash() const
  {
    return (size_t)this;
  }
  
}

