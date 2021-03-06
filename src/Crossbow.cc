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
#include "Crossbow.hpp"


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
  Crossbow::Crossbow() : RangedWeapon()
  {
    this->class_inheritance.push_back(62);
    this->name = "crossbow";
    this->weapon_group = &MISSILE_WEAPONS;
    this->hands = 2;
    this->rate_of_fire = 1;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Crossbow::Crossbow(const Crossbow& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Crossbow::Crossbow(Crossbow& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Crossbow::Crossbow(Crossbow&& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Crossbow::fork() const
  {
    return (Object*)(new Crossbow(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Crossbow::~Crossbow()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Crossbow& Crossbow::operator =(const Crossbow& original)
  {
    RangedWeapon::__copy__((RangedWeapon&)*this, (RangedWeapon&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Crossbow& Crossbow::operator =(Crossbow& original)
  {
    RangedWeapon::__copy__((RangedWeapon&)*this, (RangedWeapon&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Crossbow& Crossbow::operator =(Crossbow&& original)
  {
    std::swap((RangedWeapon&)*this, (RangedWeapon&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Crossbow::operator ==(const Crossbow& other) const
  {
    if ((RangedWeapon&)(*this) != (RangedWeapon&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Crossbow::operator !=(const Crossbow& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Crossbow::__copy__(Crossbow& self, const Crossbow& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Crossbow::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<RangedWeapon>()(*this);
    return rc;
  }
  
}

