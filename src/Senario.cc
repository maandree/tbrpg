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
#include "Senario.hpp"


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
  Senario::Senario() : Object()
  {
    this->class_inheritance.push_back(142);
    ////TODO implement constructor
    //this->rules = nullptr;
    //this->party = nullptr;
    //this->map = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Senario::Senario(const Senario& original) : Object(original)
  {
    (void) original;
    this->rules = original.rules;
    this->party = original.party;
    this->map = original.map;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Senario::Senario(Senario& original) : Object(original)
  {
    (void) original;
    this->rules = original.rules;
    this->party = original.party;
    this->map = original.map;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Senario::Senario(Senario&& original) : Object(original)
  {
    (void) original;
    std::swap(this->rules, original.rules);
    std::swap(this->party, original.party);
    std::swap(this->map, original.map);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Senario::fork() const
  {
    return new Senario(*this);
  }
  
  
  
  /**
   * Destructor
   */
  Senario::~Senario()
  {
    ////TODO implement destructor
    //delete this->rules;
    //delete this->party;
    //delete this->map;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Senario& Senario::operator =(const Senario& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->rules = original.rules;
    this->party = original.party;
    this->map = original.map;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Senario& Senario::operator =(Senario& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->rules = original.rules;
    this->party = original.party;
    this->map = original.map;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Senario& Senario::operator =(Senario&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->rules, original.rules);
    std::swap(this->party, original.party);
    std::swap(this->map, original.map);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Senario::operator ==(const Senario& other) const
  {
    if (this->rules != other.rules)  return false;
    if (this->party != other.party)  return false;
    if (this->map != other.map)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Senario::operator !=(const Senario& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Senario::__copy__(Senario& self, const Senario& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Senario::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<RuleSet>()(this->rules);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Party>()(this->party);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<Map>()(this->map);
    return rc;
  }
  
}

