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
#include "Mace.hpp"


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
  Mace::Mace() : BluntWeapon()
  {
    this->class_inheritance.push_back(34);
    this->name = "mace";
    this->speed_factor = 7;
    this->damage_die = 6;
    this->damage_dice = 1;
    this->damage_bonus = 1;
    this->weight = 3600;
    this->unit_value = 1000;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(const Mace& original) : BluntWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(Mace& original) : BluntWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(Mace&& original) : BluntWeapon(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Mace::fork() const
  {
    return (Object*)(new Mace(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Mace::~Mace()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mace& Mace::operator =(const Mace& original)
  {
    BluntWeapon::__copy__((BluntWeapon&)*this, (BluntWeapon&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mace& Mace::operator =(Mace& original)
  {
    BluntWeapon::__copy__((BluntWeapon&)*this, (BluntWeapon&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Mace& Mace::operator =(Mace&& original)
  {
    std::swap((BluntWeapon&)*this, (BluntWeapon&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Mace::operator ==(const Mace& other) const
  {
    if ((BluntWeapon&)(*this) != (BluntWeapon&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Mace::operator !=(const Mace& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Mace::__copy__(Mace& self, const Mace& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Mace::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<BluntWeapon>()(*this);
    return rc;
  }
  
}

