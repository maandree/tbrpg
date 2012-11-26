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
    ////TODO implement constructor
    //this->rate_of_fire = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(const RangedWeapon& original) : Weapon(original)
  {
    (void) original;
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon& original) : Weapon(original)
  {
    (void) original;
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon&& original) : Weapon(original)
  {
    (void) original;
    //std::swap(this->rate_of_fire, original.rate_of_fire);
  }
  
  
  
  /**
   * Destructor
   */
  RangedWeapon::~RangedWeapon()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RangedWeapon& RangedWeapon::operator =(const RangedWeapon& original)
  {
    (void) original;
    Weapon::__copy__((Weapon&)*this, (Weapon&)original);    this->rate_of_fire = original.rate_of_fire;
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
    (void) original;
    Weapon::__copy__((Weapon&)*this, (Weapon&)original);    this->rate_of_fire = original.rate_of_fire;
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
    (void) original;
    //std::move((Weapon&)*this, (Weapon&)original);    //std::swap(this->rate_of_fire, original.rate_of_fire);
    return *this;
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
    return (size_t)this;
  }
  
}

