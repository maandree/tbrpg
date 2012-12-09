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
#include "BluntWeapon.hpp"


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
  BluntWeapon::BluntWeapon() : OneHandedMelee()
  {
    this->class_inheritance.push_back(41);
    this->weapon_group = &BLUNT_WEAPONS;
    this->damage_type = {BLUDGEONING};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BluntWeapon::BluntWeapon(const BluntWeapon& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BluntWeapon::BluntWeapon(BluntWeapon& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  BluntWeapon::BluntWeapon(BluntWeapon&& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  BluntWeapon::~BluntWeapon()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BluntWeapon& BluntWeapon::operator =(const BluntWeapon& original)
  {
    OneHandedMelee::__copy__((OneHandedMelee&)*this, (OneHandedMelee&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BluntWeapon& BluntWeapon::operator =(BluntWeapon& original)
  {
    OneHandedMelee::__copy__((OneHandedMelee&)*this, (OneHandedMelee&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  BluntWeapon& BluntWeapon::operator =(BluntWeapon&& original)
  {
    std::swap((OneHandedMelee&)*this, (OneHandedMelee&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool BluntWeapon::operator ==(const BluntWeapon& other) const
  {
    if ((OneHandedMelee&)(*this) != (OneHandedMelee&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool BluntWeapon::operator !=(const BluntWeapon& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void BluntWeapon::__copy__(BluntWeapon& self, const BluntWeapon& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t BluntWeapon::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<OneHandedMelee>()(*this);
    return rc;
  }
  
}

