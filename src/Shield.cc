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
#include "Shield.hpp"


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
  Shield::Shield() : RightHandItem()
  {
    this->name = "shield";
    this->armour_class_modifiers[SLASHING] = -1;
    this->armour_class_modifiers[PIERCING] = -1;
    this->armour_class_modifiers[BLUDGEONING] = -1;
    this->protect_melee[SLASHING] = true;
    this->protect_melee[PIERCING] = true;
    this->protect_melee[BLUDGEONING] = true;
    this->protect_missile = true;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Shield::Shield(const Shield& original) : RightHandItem(original)
  {
    this->protect_missile = original.protect_missile;
    this->protect_melee = original.protect_melee;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Shield::Shield(Shield& original) : RightHandItem(original)
  {
    this->protect_missile = original.protect_missile;
    this->protect_melee = original.protect_melee;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Shield::Shield(Shield&& original) : RightHandItem(original)
  {
    std::swap(this->protect_missile, original.protect_missile);
    std::swap(this->protect_melee, original.protect_melee);
  }
  
  
  
  /**
   * Destructor
   */
  Shield::~Shield()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Shield& Shield::operator =(const Shield& original)
  {
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    this->protect_missile = original.protect_missile;
    this->protect_melee = original.protect_melee;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Shield& Shield::operator =(Shield& original)
  {
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    this->protect_missile = original.protect_missile;
    this->protect_melee = original.protect_melee;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Shield& Shield::operator =(Shield&& original)
  {
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap(this->protect_missile, original.protect_missile);
    std::swap(this->protect_melee, original.protect_melee);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Shield::operator ==(const Shield& other) const
  {
    if ((RightHandItem&)(*this) != (RightHandItem&)other)  return false;
    if (this->protect_missile != other.protect_missile)  return false;
    if (this->protect_melee != other.protect_melee)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Shield::operator !=(const Shield& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Shield::__copy__(Shield& self, const Shield& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Shield::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<RightHandItem>()(*this);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<bool>()(protect_missile);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<std::unordered_map<DamageType, bool>>()(protect_melee);
    return rc;
  }
  
}

