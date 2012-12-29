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
    this->class_inheritance.push_back(29);
    this->learned = {};
    this->selected = {};
    this->memorised = {};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(const SpellBook& original) : Object(original)
  {
    this->learned = original.learned;
    this->selected = original.selected;
    this->memorised = original.memorised;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook& original) : Object(original)
  {
    this->learned = original.learned;
    this->selected = original.selected;
    this->memorised = original.memorised;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook&& original) : Object(original)
  {
    std::swap(this->learned, original.learned);
    std::swap(this->selected, original.selected);
    std::swap(this->memorised, original.memorised);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* SpellBook::fork() const
  {
    return (Object*)(new SpellBook(*this));
  }
  
  
  
  /**
   * Destructor
   */
  SpellBook::~SpellBook()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(const SpellBook& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->learned = original.learned;
    this->selected = original.selected;
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
    Object::__copy__((Object&)*this, (Object&)original);
    this->learned = original.learned;
    this->selected = original.selected;
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
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->learned, original.learned);
    std::swap(this->selected, original.selected);
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
    if (this->learned != other.learned)  return false;
    if (this->selected != other.selected)  return false;
    if (this->memorised != other.memorised)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool SpellBook::operator !=(const SpellBook& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<Spell>>()(this->learned);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<Spell>>()(this->selected);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::vector<Spell>>()(this->memorised);
    return rc;
  }
  
}

