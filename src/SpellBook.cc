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
#include "SpellBook.hpp"


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
  SpellBook::SpellBook() : Object()
  {
    this->class_inheritance.push_back(26);
    ////TODO implement constructor
    //this->learned = nullptr;
    //this->memorised = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(const SpellBook& original) : Object(original)
  {
    (void) original;
    this->learned = original.learned;
    this->memorised = original.memorised;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook& original) : Object(original)
  {
    (void) original;
    this->learned = original.learned;
    this->memorised = original.memorised;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook&& original) : Object(original)
  {
    (void) original;
    std::swap(this->learned, original.learned);
    std::swap(this->memorised, original.memorised);
  }
  
  
  
  /**
   * Destructor
   */
  SpellBook::~SpellBook()
  {
    ////TODO implement destructor
    //delete this->learned;
    //delete this->memorised;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(const SpellBook& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->learned = original.learned;
    this->memorised = original.memorised;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(SpellBook& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->learned = original.learned;
    this->memorised = original.memorised;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(SpellBook&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->learned, original.learned);
    std::swap(this->memorised, original.memorised);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool SpellBook::operator ==(const SpellBook& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void SpellBook::__copy__(SpellBook& self, const SpellBook& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t SpellBook::hash() const
  {
    return (size_t)this;
  }
  
}

