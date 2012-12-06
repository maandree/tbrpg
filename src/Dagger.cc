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
#include "Dagger.hpp"


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
  Dagger::Dagger() : OneHandedMelee()
  {
    this->name = "dagger";
    this->speed_factor = 2;
    this->damage_die = 4;
    this->damage_dice = 1;
    this->damage_type = {PIERCING};
    this->bonuses.defence.melee = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Dagger::Dagger(const Dagger& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Dagger::Dagger(Dagger& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Dagger::Dagger(Dagger&& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Dagger::~Dagger()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Dagger& Dagger::operator =(const Dagger& original)
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
  Dagger& Dagger::operator =(Dagger& original)
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
  Dagger& Dagger::operator =(Dagger&& original)
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
  bool Dagger::operator ==(const Dagger& other) const
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
  bool Dagger::operator !=(const Dagger& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Dagger::__copy__(Dagger& self, const Dagger& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Dagger::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<OneHandedMelee>()(*this);
    return rc;
  }
  
}

