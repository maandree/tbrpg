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
#include "ThiefAbilities.hpp"


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
  ThiefAbilities::ThiefAbilities() : Object()
  {
    this->class_inheritance.push_back(5);
    this->find_traps = 0;
    this->open_locks = 0;
    this->pick_pockets = 0;
    this->stealth = 0;
    this->limit = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(const ThiefAbilities& original) : Object(original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    this->limit = original.limit;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(ThiefAbilities& original) : Object(original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    this->limit = original.limit;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(ThiefAbilities&& original) : Object(original)
  {
    std::swap(this->find_traps, original.find_traps);
    std::swap(this->open_locks, original.open_locks);
    std::swap(this->pick_pockets, original.pick_pockets);
    std::swap(this->stealth, original.stealth);
    std::swap(this->limit, original.limit);
  }
  
  
  
  /**
   * Destructor
   */
  ThiefAbilities::~ThiefAbilities()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(const ThiefAbilities& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    this->limit = original.limit;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(ThiefAbilities& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    this->limit = original.limit;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(ThiefAbilities&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->find_traps, original.find_traps);
    std::swap(this->open_locks, original.open_locks);
    std::swap(this->pick_pockets, original.pick_pockets);
    std::swap(this->stealth, original.stealth);
    std::swap(this->limit, original.limit);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ThiefAbilities::operator ==(const ThiefAbilities& other) const
  {
    if (this->find_traps != other.find_traps)  return false;
    if (this->open_locks != other.open_locks)  return false;
    if (this->pick_pockets != other.pick_pockets)  return false;
    if (this->stealth != other.stealth)  return false;
    if (this->limit != other.limit)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool ThiefAbilities::operator !=(const ThiefAbilities& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void ThiefAbilities::__copy__(ThiefAbilities& self, const ThiefAbilities& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ThiefAbilities::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(find_traps);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(open_locks);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(pick_pockets);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<int>()(stealth);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<int>()(limit);
    return rc;
  }
  
}

