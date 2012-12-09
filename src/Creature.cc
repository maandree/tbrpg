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
#include "Creature.hpp"


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
  Creature::Creature() : Character()
  {
    this->class_inheritance.push_back(69);
    this->experience = 1;
    this->hostile = true;
    this->x = 0;
    this->y = 0;
    this->alive = true;
    this->resurrect = true;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(const Creature& original) : Character(original)
  {
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
    this->experience = original.experience;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(Creature& original) : Character(original)
  {
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
    this->experience = original.experience;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(Creature&& original) : Character(original)
  {
    std::swap(this->hostile, original.hostile);
    std::swap(this->x, original.x);
    std::swap(this->y, original.y);
    std::swap(this->alive, original.alive);
    std::swap(this->resurrect, original.resurrect);
    std::swap(this->experience, original.experience);
  }
  
  
  
  /**
   * Destructor
   */
  Creature::~Creature()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Creature& Creature::operator =(const Creature& original)
  {
    Character::__copy__((Character&)*this, (Character&)original);
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
    this->experience = original.experience;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Creature& Creature::operator =(Creature& original)
  {
    Character::__copy__((Character&)*this, (Character&)original);
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
    this->experience = original.experience;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Creature& Creature::operator =(Creature&& original)
  {
    std::swap((Character&)*this, (Character&)original);
    std::swap(this->hostile, original.hostile);
    std::swap(this->x, original.x);
    std::swap(this->y, original.y);
    std::swap(this->alive, original.alive);
    std::swap(this->resurrect, original.resurrect);
    std::swap(this->experience, original.experience);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Creature::operator ==(const Creature& other) const
  {
    if ((Character&)(*this) != (Character&)other)  return false;
    if (this->hostile != other.hostile)  return false;
    if (this->x != other.x)  return false;
    if (this->y != other.y)  return false;
    if (this->alive != other.alive)  return false;
    if (this->resurrect != other.resurrect)  return false;
    if (this->experience != other.experience)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Creature::operator !=(const Creature& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Creature::__copy__(Creature& self, const Creature& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Creature::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Character>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->hostile);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<float>()(this->x);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<float>()(this->y);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<bool>()(this->alive);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<bool>()(this->resurrect);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<int>()(this->experience);
    return rc;
  }
  
}

