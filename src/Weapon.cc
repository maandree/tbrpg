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
   * Destructor
   */
  Weapon::~Weapon()
  {
    ////TODO implement destructor
    //delete damage_type;
    //delete weapon_group;
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
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
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
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
    RightHandItem::__copy__((RightHandItem&)*this, (RightHandItem&)original);
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
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
    std::swap((RightHandItem&)*this, (RightHandItem&)original);
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
    return (size_t)this;
  }
  
}

