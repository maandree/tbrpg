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
#include "Sling.hpp"


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
  Sling::Sling() : RangedWeapon()
  {
    this->name = "sling";
    this->weapon_group = MISSILE_WEAPONS;
    this->hands = 1;
    this->rate_of_fire = 1;
    this->speed_factor = 6;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Sling::Sling(const Sling& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Sling::Sling(Sling& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Sling::Sling(Sling&& original) : RangedWeapon(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Sling::~Sling()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Sling& Sling::operator =(const Sling& original)
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
  Sling& Sling::operator =(Sling& original)
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
  Sling& Sling::operator =(Sling&& original)
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
  bool Sling::operator ==(const Sling& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Sling::__copy__(Sling& self, const Sling& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Sling::hash() const
  {
    return (size_t)this;
  }
  
}

