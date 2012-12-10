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
#include "Weapon.hpp"


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
  Weapon::Weapon() : RightHandItem()
  {
    this->class_inheritance.push_back(12);
    ////TODO implement constructor
    //this->hands = 0;
    //this->speed_factor = 0;
    //this->hit_bonus = 0;
    //this->damage_die = 0;
    //this->damage_dice = 0;
    //this->damage_bonus = 0;
    //this->melee = false;
    //this->damage_type = nullptr;
    //this->weapon_group = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Weapon::Weapon(const Weapon& original) : RightHandItem(original)
  {
    (void) original;
    this->hands = original.hands;
    this->speed_factor = original.speed_factor;
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->melee = original.melee;
    this->damage_type = original.damage_type;
    this->weapon_group = original.weapon_group;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Weapon::Weapon(Weapon& original) : RightHandItem(original)
  {
    (void) original;
    this->hands = original.hands;
    this->speed_factor = original.speed_factor;
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->melee = original.melee;
    this->damage_type = original.damage_type;
    this->weapon_group = original.weapon_group;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Weapon::Weapon(Weapon&& original) : RightHandItem(original)
  {
    (void) original;
    std::swap(this->hands, original.hands);
    std::swap(this->speed_factor, original.speed_factor);
    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_die, original.damage_die);
    std::swap(this->damage_dice, original.damage_dice);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->melee, original.melee);
    std::swap(this->damage_type, original.damage_type);
    std::swap(this->weapon_group, original.weapon_group);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Weapon::fork() const
  {
    return new Weapon(*this);
  }
  
  
  
  /**
   * Destructor
   */
  Weapon::~Weapon()
  {
    ////TODO implement destructor
    //delete this->damage_type;
    //delete this->weapon_group;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Weapon& Weapon::operator =(const Weapon& original)
  {
    (void) original;
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);    this->hands = original.hands;
    this->speed_factor = original.speed_factor;
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->melee = original.melee;
    this->damage_type = original.damage_type;
    this->weapon_group = original.weapon_group;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Weapon& Weapon::operator =(Weapon& original)
  {
    (void) original;
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);    this->hands = original.hands;
    this->speed_factor = original.speed_factor;
    this->hit_bonus = original.hit_bonus;
    this->damage_die = original.damage_die;
    this->damage_dice = original.damage_dice;
    this->damage_bonus = original.damage_bonus;
    this->melee = original.melee;
    this->damage_type = original.damage_type;
    this->weapon_group = original.weapon_group;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Weapon& Weapon::operator =(Weapon&& original)
  {
    (void) original;
    std::swap((RightHandItem&)*this, (RightHandItem&)original);    std::swap(this->hands, original.hands);
    std::swap(this->speed_factor, original.speed_factor);
    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_die, original.damage_die);
    std::swap(this->damage_dice, original.damage_dice);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->melee, original.melee);
    std::swap(this->damage_type, original.damage_type);
    std::swap(this->weapon_group, original.weapon_group);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Weapon::operator ==(const Weapon& other) const
  {
    if ((RightHandItem&)(*this) != (RightHandItem&)other)  return false;
    if (this->hands != other.hands)  return false;
    if (this->speed_factor != other.speed_factor)  return false;
    if (this->hit_bonus != other.hit_bonus)  return false;
    if (this->damage_die != other.damage_die)  return false;
    if (this->damage_dice != other.damage_dice)  return false;
    if (this->damage_bonus != other.damage_bonus)  return false;
    if (this->melee != other.melee)  return false;
    if (this->damage_type != other.damage_type)  return false;
    if (this->weapon_group != other.weapon_group)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Weapon::operator !=(const Weapon& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Weapon::__copy__(Weapon& self, const Weapon& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Weapon::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<RightHandItem>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<char>()(this->hands);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<char>()(this->speed_factor);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<int>()(this->hit_bonus);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<char>()(this->damage_die);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<char>()(this->damage_dice);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<int>()(this->damage_bonus);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<bool>()(this->melee);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<DamageType>>()(this->damage_type);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<WeaponGroup>()(this->weapon_group);
    return rc;
  }
  
}

