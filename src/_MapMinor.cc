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
#include "_MapMinor.hpp"


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
  _MapMinor::_MapMinor() : Object()
  {
    this->class_inheritance.push_back(126);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  _MapMinor::_MapMinor(const _MapMinor& original) : Object(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  _MapMinor::_MapMinor(_MapMinor& original) : Object(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  _MapMinor::_MapMinor(_MapMinor&& original) : Object(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* _MapMinor::fork() const
  {
    return (Object*)(new _MapMinor(*this));
  }
  
  
  
  /**
   * Destructor
   */
  _MapMinor::~_MapMinor()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  _MapMinor& _MapMinor::operator =(const _MapMinor& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  _MapMinor& _MapMinor::operator =(_MapMinor& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  _MapMinor& _MapMinor::operator =(_MapMinor&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool _MapMinor::operator ==(const _MapMinor& other) const
  {
    (void) other;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool _MapMinor::operator !=(const _MapMinor& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void _MapMinor::__copy__(_MapMinor& self, const _MapMinor& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t _MapMinor::hash() const
  {
    size_t rc = 0;
    return rc;
  }
  
}

