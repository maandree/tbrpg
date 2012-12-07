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
  Character::Character() : Object()
  {
    this->class_inheritance.push_back(19);
    this->hit_points = 8;
    this->alive = 1;
    this->morale = 0;
    this->intoxication = 0;
    this->fatigue = 0;
    this->extra_attacks = 0;
    this->record = CharacterSheet();
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Character::Character(const Character& original) : Object(original)
  {
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
  Character::Character(Character& original) : Object(original)
  {
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
  Character::Character(Character&& original) : Object(original)
  {
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
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Character& Character::operator =(const Character& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
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
    Object::__copy__((Object&)*this, (Object&)original);
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
    std::swap((Object&)*this, (Object&)original);
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
    if (this->hit_points != other.hit_points)  return false;
    if (this->alive != other.alive)  return false;
    if (this->morale != other.morale)  return false;
    if (this->intoxication != other.intoxication)  return false;
    if (this->fatigue != other.fatigue)  return false;
    if (this->extra_attacks != other.extra_attacks)  return false;
    if (this->record != other.record)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Character::operator !=(const Character& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(hit_points);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<char>()(alive);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(morale);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<int>()(intoxication);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<int>()(fatigue);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<char>()(extra_attacks);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<CharacterSheet>()(record);
    return rc;
  }
  
}

