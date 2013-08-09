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
#include "Fists.hpp"


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
  Fists::Fists() : TwoHandedMelee()
  {
    this->class_inheritance.push_back(53);
    this->name = "fists";
    this->weapon_group = &BLUNT_WEAPONS;
    this->speed_factor = 2;
    this->damage_die = 2;
    this->damage_dice = 2;
    this->damage_type = {BLUDGEONING};
    this->bonuses.defence.melee = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Fists::Fists(const Fists& original) : TwoHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Fists::Fists(Fists& original) : TwoHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Fists::Fists(Fists&& original) : TwoHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Fists::fork() const
  {
    return (Object*)(new Fists(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Fists::~Fists()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Fists& Fists::operator =(const Fists& original)
  {
    TwoHandedMelee::__copy__((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Fists& Fists::operator =(Fists& original)
  {
    TwoHandedMelee::__copy__((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Fists& Fists::operator =(Fists&& original)
  {
    std::swap((TwoHandedMelee&)*this, (TwoHandedMelee&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Fists::operator ==(const Fists& other) const
  {
    if ((TwoHandedMelee&)(*this) != (TwoHandedMelee&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Fists::operator !=(const Fists& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Fists::__copy__(Fists& self, const Fists& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Fists::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<TwoHandedMelee>()(*this);
    return rc;
  }
  
}

