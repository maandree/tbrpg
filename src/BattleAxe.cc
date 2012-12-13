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
#include "BattleAxe.hpp"


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
  BattleAxe::BattleAxe() : OneHandedMelee()
  {
    this->class_inheritance.push_back(43);
    this->name = "battle axe";
    this->weapon_group = &AXE;
    this->speed_factor = 7;
    this->damage_die = 8;
    this->damage_dice = 1;
    this->damage_type = {SLASHING};
    this->weight = 3175;
    this->unit_value = 450;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BattleAxe::BattleAxe(const BattleAxe& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  BattleAxe::BattleAxe(BattleAxe& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  BattleAxe::BattleAxe(BattleAxe&& original) : OneHandedMelee(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* BattleAxe::fork() const
  {
    return (Object*)(new BattleAxe(*this));
  }
  
  
  
  /**
   * Destructor
   */
  BattleAxe::~BattleAxe()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  BattleAxe& BattleAxe::operator =(const BattleAxe& original)
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
  BattleAxe& BattleAxe::operator =(BattleAxe& original)
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
  BattleAxe& BattleAxe::operator =(BattleAxe&& original)
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
  bool BattleAxe::operator ==(const BattleAxe& other) const
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
  bool BattleAxe::operator !=(const BattleAxe& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void BattleAxe::__copy__(BattleAxe& self, const BattleAxe& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t BattleAxe::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<OneHandedMelee>()(*this);
    return rc;
  }
  
}

