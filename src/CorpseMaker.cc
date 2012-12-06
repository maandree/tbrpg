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
#include "CorpseMaker.hpp"


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
  CorpseMaker::CorpseMaker() : Object()
  {
    this->class_inheritance.push_back(78);
    ////TODO implement constructor
    //this->strenght_weight = nullptr;
    //this->strenght18_weight = nullptr;
    //this->constitution_weight = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(const CorpseMaker& original) : Object(original)
  {
    (void) original;
    this->strenght_weight = original.strenght_weight;
    this->strenght18_weight = original.strenght18_weight;
    this->constitution_weight = original.constitution_weight;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(CorpseMaker& original) : Object(original)
  {
    (void) original;
    this->strenght_weight = original.strenght_weight;
    this->strenght18_weight = original.strenght18_weight;
    this->constitution_weight = original.constitution_weight;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(CorpseMaker&& original) : Object(original)
  {
    (void) original;
    std::swap(this->strenght_weight, original.strenght_weight);
    std::swap(this->strenght18_weight, original.strenght18_weight);
    std::swap(this->constitution_weight, original.constitution_weight);
  }
  
  
  
  /**
   * Destructor
   */
  CorpseMaker::~CorpseMaker()
  {
    ////TODO implement destructor
    //delete this->strenght_weight;
    //delete this->strenght18_weight;
    //delete this->constitution_weight;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(const CorpseMaker& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->strenght_weight = original.strenght_weight;
    this->strenght18_weight = original.strenght18_weight;
    this->constitution_weight = original.constitution_weight;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(CorpseMaker& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->strenght_weight = original.strenght_weight;
    this->strenght18_weight = original.strenght18_weight;
    this->constitution_weight = original.constitution_weight;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(CorpseMaker&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->strenght_weight, original.strenght_weight);
    std::swap(this->strenght18_weight, original.strenght18_weight);
    std::swap(this->constitution_weight, original.constitution_weight);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool CorpseMaker::operator ==(const CorpseMaker& other) const
  {
    if (this->strenght_weight != other.strenght_weight)  return false;
    if (this->strenght18_weight != other.strenght18_weight)  return false;
    if (this->constitution_weight != other.constitution_weight)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool CorpseMaker::operator !=(const CorpseMaker& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void CorpseMaker::__copy__(CorpseMaker& self, const CorpseMaker& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t CorpseMaker::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<int[]>()(strenght_weight);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<int[]>()(strenght18_weight);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<int[]>()(constitution_weight);
    return rc;
  }
  
}

