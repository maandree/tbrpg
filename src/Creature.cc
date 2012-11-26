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
    ////TODO implement constructor
    //this->hostile = false;
    //this->x = 0;
    //this->y = 0;
    //this->alive = false;
    //this->resurrect = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(const Creature& original) : Character(original)
  {
    (void) original;
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(Creature& original) : Character(original)
  {
    (void) original;
    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(Creature&& original) : Character(original)
  {
    (void) original;
    //std::swap(this->hostile, original.hostile);
    //std::swap(this->x, original.x);
    //std::swap(this->y, original.y);
    //std::swap(this->alive, original.alive);
    //std::swap(this->resurrect, original.resurrect);
  }
  
  
  
  /**
   * Destructor
   */
  Creature::~Creature()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Creature& Creature::operator =(const Creature& original)
  {
    (void) original;
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
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
    (void) original;
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);
    Character::__copy__((Character&)*this, (Character&)original);    this->hostile = original.hostile;
    this->x = original.x;
    this->y = original.y;
    this->alive = original.alive;
    this->resurrect = original.resurrect;
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
    (void) original;
    //std::move((Character&)*this, (Character&)original);
    //std::move((Character&)*this, (Character&)original);
    //std::move((Character&)*this, (Character&)original);
    //std::move((Character&)*this, (Character&)original);
    //std::move((Character&)*this, (Character&)original);    //std::swap(this->hostile, original.hostile);
    //std::swap(this->x, original.x);
    //std::swap(this->y, original.y);
    //std::swap(this->alive, original.alive);
    //std::swap(this->resurrect, original.resurrect);
    return *this;
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
    return (size_t)this;
  }
  
}

