// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "RangedWeapon.hpp"


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
  RangedWeapon::RangedWeapon() : Weapon()
  {
    this->class_inheritance.push_back(31);
    this->rate_of_fire = 1;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(const RangedWeapon& original) : Weapon(original)
  {
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon& original) : Weapon(original)
  {
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon&& original) : Weapon(original)
  {
    std::swap(this->rate_of_fire, original.rate_of_fire);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* RangedWeapon::fork() const
  {
    return (Object*)(new RangedWeapon(*this));
  }
  
  
  
  /**
   * Destructor
   */
  RangedWeapon::~RangedWeapon()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RangedWeapon& RangedWeapon::operator =(const RangedWeapon& original)
  {
    Weapon::__copy__((Weapon&)*this, (Weapon&)original);
    this->rate_of_fire = original.rate_of_fire;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RangedWeapon& RangedWeapon::operator =(RangedWeapon& original)
  {
    Weapon::__copy__((Weapon&)*this, (Weapon&)original);
    this->rate_of_fire = original.rate_of_fire;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  RangedWeapon& RangedWeapon::operator =(RangedWeapon&& original)
  {
    std::swap((Weapon&)*this, (Weapon&)original);
    std::swap(this->rate_of_fire, original.rate_of_fire);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool RangedWeapon::operator ==(const RangedWeapon& other) const
  {
    if ((Weapon&)(*this) != (Weapon&)other)  return false;
    if (this->rate_of_fire != other.rate_of_fire)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool RangedWeapon::operator !=(const RangedWeapon& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void RangedWeapon::__copy__(RangedWeapon& self, const RangedWeapon& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t RangedWeapon::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Weapon>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<char>()(this->rate_of_fire);
    return rc;
  }
  
}

