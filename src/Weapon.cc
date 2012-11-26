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
  Weapon::Weapon()
  {
    //TODO implement constructor
    //hit_bonus = nullptr;
    //damage_die = nullptr;
    //damage_dice = nullptr;
    //damage_bonus = nullptr;
    //usable_with = nullptr;
    //damage_type = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Weapon::Weapon(const Weapon& original)
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
  Weapon::Weapon(Weapon& original)
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
  Weapon::Weapon(Weapon&& original)
  {
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_die, original.damage_die);
    std::move(this->damage_dice, original.damage_dice);
    std::move(this->damage_bonus, original.damage_bonus);
    std::move(this->usable_with, original.usable_with);
    std::move(this->damage_type, original.damage_type);
  }
  
  
  
  /**
   * Destructor
   */
  Weapon::~Weapon()
  {
    //TODO implement destructor
    //delete hit_bonus;
    //delete damage_die;
    //delete damage_dice;
    //delete damage_bonus;
    //delete usable_with;
    //delete damage_type;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Weapon& Weapon::operator =(const Weapon& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hit_bonus = original.hit_bonus;
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
  Weapon& Weapon::operator =(Weapon& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hit_bonus = original.hit_bonus;
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
  Weapon& Weapon::operator =(Weapon&& original)
  {
    std::move((RightHandItem)*this, (RightHandItem)original);
    std::move((RightHandItem)*this, (RightHandItem)original);
    std::move((RightHandItem)*this, (RightHandItem)original);
    std::move((RightHandItem)*this, (RightHandItem)original);
    std::move((RightHandItem)*this, (RightHandItem)original);
    std::move((RightHandItem)*this, (RightHandItem)original);    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_die, original.damage_die);
    std::move(this->damage_dice, original.damage_dice);
    std::move(this->damage_bonus, original.damage_bonus);
    std::move(this->usable_with, original.usable_with);
    std::move(this->damage_type, original.damage_type);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Weapon::__copy__(Weapon& self, const Weapon& original);
  {
    left = right;
  }
  
}

