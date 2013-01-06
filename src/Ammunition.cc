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
#include "Ammunition.hpp"


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
  Ammunition::Ammunition() : Item()
  {
    this->class_inheritance.push_back(11);
    this->quantity_limit = 20;
    this->hit_bonus = 0;
    this->damage_die = 2;
    this->damage_dice = 1;
    this->damage_bonus = 0;
    this->usable_with = RangedWeapon();
    this->damage_type = PIERCING;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(const Ammunition& original) : Item(original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->usable_with = original.usable_with;
    this->damage_type = original.damage_type;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition& original) : Item(original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->usable_with = original.usable_with;
    this->damage_type = original.damage_type;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition&& original) : Item(original)
  {
    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_die, original.damage_die);
    std::swap(this->damage_dice, original.damage_dice);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->usable_with, original.usable_with);
    std::swap(this->damage_type, original.damage_type);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Ammunition::fork() const
  {
    return (Object*)(new Ammunition(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Ammunition::~Ammunition()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ammunition& Ammunition::operator =(const Ammunition& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->usable_with = original.usable_with;
    this->damage_type = original.damage_type;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ammunition& Ammunition::operator =(Ammunition& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->usable_with = original.usable_with;
    this->damage_type = original.damage_type;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Ammunition& Ammunition::operator =(Ammunition&& original)
  {
    std::swap((Item&)*this, (Item&)original);
    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_die, original.damage_die);
    std::swap(this->damage_dice, original.damage_dice);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->usable_with, original.usable_with);
    std::swap(this->damage_type, original.damage_type);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Ammunition::operator ==(const Ammunition& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    if (this->hit_bonus != other.hit_bonus)  return false;
    if (this->damage_die != other.damage_die)  return false;
    if (this->damage_dice != other.damage_dice)  return false;
    if (this->damage_bonus != other.damage_bonus)  return false;
    if (this->usable_with != other.usable_with)  return false;
    if (this->damage_type != other.damage_type)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Ammunition::operator !=(const Ammunition& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Ammunition::__copy__(Ammunition& self, const Ammunition& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Ammunition::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->hit_bonus);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<char>()(this->damage_die);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<char>()(this->damage_dice);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<int>()(this->damage_bonus);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<RangedWeapon>()(this->usable_with);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<DamageType>()(this->damage_type);
    return rc;
  }
  
}

