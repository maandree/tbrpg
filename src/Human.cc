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
#include "Human.hpp"


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
  Human::Human() : Race()
  {
    this->dualclass_level = 4;
    
    this->allowed_classes =
      {{Fighter()}, {Ranger()}, {Paladin()},
       {Cleric()}, {Druid()},
       {Mage()}, {Sorcerer()},
       {Thief()}, {Bard()},
       {Fighter(), Thief()}, {Fighter(), Cleric()}, {Fighter(), Druid()}, {Fighter(), Mage()},
       {Ranger(), Cleric()},
       {Thief(), Cleric()}, {Thief(), Mage()},
       {Fighter(), Mage(), Thief()}, {Fighter(), Mage(), Cleric()}};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Human::Human(const Human& original) : Race(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Human::Human(Human& original) : Race(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Human::Human(Human&& original) : Race(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Human::~Human()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Human& Human::operator =(const Human& original)
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
  Human& Human::operator =(Human& original)
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
  Human& Human::operator =(Human&& original)
  {
    (void) original;

    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Human::operator ==(const Human& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Human::__copy__(Human& self, const Human& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Human::hash() const
  {
    return (size_t)this;
  }
  
}

