// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
    this->class_inheritance.push_back(129);
    this->experience = 1;
    this->hostile = true;
    this->x = 0;
    this->y = 0;
    this->alive = true;
    this->resurrect = true;
    this->pick_level = 10;
    this->pickable = true;
    this->pick_hostile = true;
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
    this->pick_level = original.pick_level;
    this->pickable = original.pickable;
    this->pick_hostile = original.pick_hostile;
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
    this->pick_level = original.pick_level;
    this->pickable = original.pickable;
    this->pick_hostile = original.pick_hostile;
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
    std::swap(this->pick_level, original.pick_level);
    std::swap(this->pickable, original.pickable);
    std::swap(this->pick_hostile, original.pick_hostile);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Creature::fork() const
  {
    return (Object*)(new Creature(*this));
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
    this->pick_level = original.pick_level;
    this->pickable = original.pickable;
    this->pick_hostile = original.pick_hostile;
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
    this->pick_level = original.pick_level;
    this->pickable = original.pickable;
    this->pick_hostile = original.pick_hostile;
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
    std::swap(this->pick_level, original.pick_level);
    std::swap(this->pickable, original.pickable);
    std::swap(this->pick_hostile, original.pick_hostile);
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
    if (this->pick_level != other.pick_level)  return false;
    if (this->pickable != other.pickable)  return false;
    if (this->pick_hostile != other.pick_hostile)  return false;
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
   * Interact, but do not fight, with the creature
   * 
   * @param  nearby  Party members nearby
   */
  void Creature::interact(std::vector<Character*>& nearby)
  {
    (void) nearby;
    std::flush(std::cout
	       << "\033[01;3" << this->record.colour << "m"
	       << this->record.name << "\033[21;39m"
	       << " has nothing to say."
	       << std::endl);
  }
  
  /**
   * Successfully pick pockey the creature
   * 
   * @return  The stolen item, null is there is nothing to steal
   */
  Item* Creature::pickPocket()
  {
    std::vector<size_t> indices = std::vector<size_t>();
    for (size_t i = 0, n = this->record.inventory.personal.size(); i < n; i++)
      if ((this->record.inventory.personal[i]))
	indices.push_back(i);
    
    if (indices.size() == 0)
      return nullptr;
    
    Die die = Die(indices.size());
    int i = indices[die.roll() - 1];
    Item* rc = this->record.inventory.personal[i];
    this->record.inventory.personal[i] = nullptr;
    return rc;
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
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<int>()(this->pick_level);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<bool>()(this->pickable);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->pick_hostile);
    return rc;
  }
  
}

