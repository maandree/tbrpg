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
  RangedWeapon::RangedWeapon()
  {
    //TODO implement constructor
    //contains = nullptr;
    //contain_limit = nullptr;
    //weight_modifier = nullptr;
    //can_contain = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(const RangedWeapon& original)
  {
    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon& original)
  {
    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RangedWeapon::RangedWeapon(RangedWeapon&& original)
  {
    std::move(this->contains, original.contains);
    std::move(this->contain_limit, original.contain_limit);
    std::move(this->weight_modifier, original.weight_modifier);
    std::move(this->can_contain, original.can_contain);
  }
  
  
  
  /**
   * Destructor
   */
  RangedWeapon::~RangedWeapon()
  {
    //TODO implement destructor
    //delete contains;
    //delete contain_limit;
    //delete weight_modifier;
    //delete can_contain;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RangedWeapon& RangedWeapon::operator =(const RangedWeapon& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
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
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
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
    std::move((Weapon)*this, (Weapon)original);
    std::move((Weapon)*this, (Weapon)original);
    std::move((Weapon)*this, (Weapon)original);
    std::move((Weapon)*this, (Weapon)original);    std::move(this->contains, original.contains);
    std::move(this->contain_limit, original.contain_limit);
    std::move(this->weight_modifier, original.weight_modifier);
    std::move(this->can_contain, original.can_contain);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void RangedWeapon::__copy__(RangedWeapon& self, const RangedWeapon& original);
  {
    left = right;
  }
  
}

