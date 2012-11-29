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
#include "Character.hpp"


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
  Character::Character()
  {
    ////TODO implement constructor
    //this->hit_points = 0;
    //this->alive = 0;
    //this->morale = 0;
    //this->intoxication = 0;
    //this->fatigue = 0;
    //this->extra_attacks = 0;
    //this->record = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(const Character& original)
  {
    (void) original;
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->extra_attacks = original.extra_attacks;
    this->record = original.record;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(Character& original)
  {
    (void) original;
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->extra_attacks = original.extra_attacks;
    this->record = original.record;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(Character&& original)
  {
    (void) original;
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->alive, original.alive);
    std::swap(this->morale, original.morale);
    std::swap(this->intoxication, original.intoxication);
    std::swap(this->fatigue, original.fatigue);
    std::swap(this->extra_attacks, original.extra_attacks);
    std::swap(this->record, original.record);
  }
  
  
  
  /**
   * Destructor
   */
  Character::~Character()
  {
    ////TODO implement destructor
    //delete this->record;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Character& Character::operator =(const Character& original)
  {
    (void) original;
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->extra_attacks = original.extra_attacks;
    this->record = original.record;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Character& Character::operator =(Character& original)
  {
    (void) original;
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->extra_attacks = original.extra_attacks;
    this->record = original.record;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Character& Character::operator =(Character&& original)
  {
    (void) original;
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->alive, original.alive);
    std::swap(this->morale, original.morale);
    std::swap(this->intoxication, original.intoxication);
    std::swap(this->fatigue, original.fatigue);
    std::swap(this->extra_attacks, original.extra_attacks);
    std::swap(this->record, original.record);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Character::operator ==(const Character& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Character::__copy__(Character& self, const Character& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Character::hash() const
  {
    return (size_t)this;
  }
  
}

