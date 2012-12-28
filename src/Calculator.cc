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
#include "Calculator.hpp"


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
  Calculator::Calculator() : Object()
  {
    this->class_inheritance.push_back(144);
    ////TODO implement constructor
    //this->rules = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(const Calculator& original) : Object(original)
  {
    (void) original;
    this->rules = original.rules;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator& original) : Object(original)
  {
    (void) original;
    this->rules = original.rules;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator&& original) : Object(original)
  {
    (void) original;
    std::swap(this->rules, original.rules);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Calculator::fork() const
  {
    return (Object*)(new Calculator(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Calculator::~Calculator()
  {
    ////TODO implement destructor
    //delete this->rules;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(const Calculator& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->rules = original.rules;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(Calculator& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->rules = original.rules;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(Calculator&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->rules, original.rules);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Calculator::operator ==(const Calculator& other) const
  {
    if (this->rules != other.rules)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Calculator::operator !=(const Calculator& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Calculator::__copy__(Calculator& self, const Calculator& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Calculator::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<RuleSet>()(this->rules);
    return rc;
  }
  
}

