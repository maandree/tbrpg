// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "HalfOrc.hpp"


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
  HalfOrc::HalfOrc() : Race()
  {
    this->class_inheritance.push_back(115);
    this->name = "half-orc";
    this->bonuses.abilities.strength = 1;
    this->bonuses.abilities.constitution = 1;
    this->bonuses.abilities.intelligence = -1;
    this->bonuses.abilities.charisma = -1;
    
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Cleric)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Mage)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Sorcerer)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Cleric)}));
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HalfOrc::HalfOrc(const HalfOrc& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HalfOrc::HalfOrc(HalfOrc& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  HalfOrc::HalfOrc(HalfOrc&& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* HalfOrc::fork() const
  {
    return (Object*)(new HalfOrc(*this));
  }
  
  
  
  /**
   * Destructor
   */
  HalfOrc::~HalfOrc()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  HalfOrc& HalfOrc::operator =(const HalfOrc& original)
  {
    Race::__copy__((Race&)*this, (Race&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  HalfOrc& HalfOrc::operator =(HalfOrc& original)
  {
    Race::__copy__((Race&)*this, (Race&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  HalfOrc& HalfOrc::operator =(HalfOrc&& original)
  {
    std::swap((Race&)*this, (Race&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool HalfOrc::operator ==(const HalfOrc& other) const
  {
    if ((Race&)(*this) != (Race&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool HalfOrc::operator !=(const HalfOrc& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void HalfOrc::__copy__(HalfOrc& self, const HalfOrc& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t HalfOrc::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Race>()(*this);
    return rc;
  }
  
}

