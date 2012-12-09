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
#include "MagicSchool.hpp"


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
  MagicSchool::MagicSchool() : Object()
  {
    this->class_inheritance.push_back(20);
    ////TODO implement constructor
    //this->name = nullptr;
    //this->coluration = nullptr;
    //this->practicer = nullptr;
    //this->opposite = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(const MagicSchool& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(MagicSchool& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(MagicSchool&& original) : Object(original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->coluration, original.coluration);
    std::swap(this->practicer, original.practicer);
    std::swap(this->opposite, original.opposite);
  }
  
  
  
  /**
   * Destructor
   */
  MagicSchool::~MagicSchool()
  {
    ////TODO implement destructor
    //delete this->name;
    //delete this->coluration;
    //delete this->practicer;
    //delete this->opposite;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(const MagicSchool& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(MagicSchool& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(MagicSchool&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->name, original.name);
    std::swap(this->coluration, original.coluration);
    std::swap(this->practicer, original.practicer);
    std::swap(this->opposite, original.opposite);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool MagicSchool::operator ==(const MagicSchool& other) const
  {
    if (this->name != other.name)  return false;
    if (this->coluration != other.coluration)  return false;
    if (this->practicer != other.practicer)  return false;
    if (this->opposite != other.opposite)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool MagicSchool::operator !=(const MagicSchool& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void MagicSchool::__copy__(MagicSchool& self, const MagicSchool& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t MagicSchool::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->coluration);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::string>()(this->practicer);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<MagicSchool>>()(this->opposite);
    return rc;
  }
  
}

