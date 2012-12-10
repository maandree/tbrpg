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
#include "Defence.hpp"


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
  Defence::Defence() : Object()
  {
    this->class_inheritance.push_back(4);
    this->melee = 0;
    this->missile = 0;
    this->fire = 0;
    this->cold = 0;
    this->lightning = 0;
    this->acid = 0;
    this->poison = 0;
    this->physical = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(const Defence& original) : Object(original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(Defence& original) : Object(original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(Defence&& original) : Object(original)
  {
    std::swap(this->melee, original.melee);
    std::swap(this->missile, original.missile);
    std::swap(this->fire, original.fire);
    std::swap(this->cold, original.cold);
    std::swap(this->lightning, original.lightning);
    std::swap(this->acid, original.acid);
    std::swap(this->poison, original.poison);
    std::swap(this->physical, original.physical);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Defence::fork() const
  {
    return (Object*)(new Defence(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Defence::~Defence()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Defence& Defence::operator =(const Defence& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Defence& Defence::operator =(Defence& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Defence& Defence::operator =(Defence&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->melee, original.melee);
    std::swap(this->missile, original.missile);
    std::swap(this->fire, original.fire);
    std::swap(this->cold, original.cold);
    std::swap(this->lightning, original.lightning);
    std::swap(this->acid, original.acid);
    std::swap(this->poison, original.poison);
    std::swap(this->physical, original.physical);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Defence::operator ==(const Defence& other) const
  {
    if (this->melee != other.melee)  return false;
    if (this->missile != other.missile)  return false;
    if (this->fire != other.fire)  return false;
    if (this->cold != other.cold)  return false;
    if (this->lightning != other.lightning)  return false;
    if (this->acid != other.acid)  return false;
    if (this->poison != other.poison)  return false;
    if (this->physical != other.physical)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Defence::operator !=(const Defence& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Defence::__copy__(Defence& self, const Defence& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Defence::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->melee);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->missile);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<float>()(this->fire);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<float>()(this->cold);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<float>()(this->lightning);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<float>()(this->acid);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<float>()(this->poison);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<float>()(this->physical);
    return rc;
  }
  
}

