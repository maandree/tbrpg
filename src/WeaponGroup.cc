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
#include "WeaponGroup.hpp"


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
  WeaponGroup::WeaponGroup()
  {
    ////TODO implement constructor
    //this->name = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(const WeaponGroup& original)
  {
    (void) original;
    this->name = original.name;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(WeaponGroup& original)
  {
    (void) original;
    this->name = original.name;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  WeaponGroup::WeaponGroup(WeaponGroup&& original)
  {
    (void) original;
    std::swap(this->name, original.name);
  }
  
  
  
  /**
   * Destructor
   */
  WeaponGroup::~WeaponGroup()
  {
    ////TODO implement destructor
    //delete name;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(const WeaponGroup& original)
  {
    (void) original;
    this->name = original.name;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(WeaponGroup& original)
  {
    (void) original;
    this->name = original.name;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  WeaponGroup& WeaponGroup::operator =(WeaponGroup&& original)
  {
    (void) original;
    std::swap(this->name, original.name);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void WeaponGroup::__copy__(WeaponGroup& self, const WeaponGroup& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t WeaponGroup::hash() const
  {
    return (size_t)this;
  }
  
}

