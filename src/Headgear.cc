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
#include "Headgear.hpp"


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
  Headgear::Headgear()
  {
    //TODO implement constructor
    //hands = nullptr;
    //speed_factor = nullptr;
    //hit_bonus = nullptr;
    //damage_die = nullptr;
    //damage_dice = nullptr;
    //damage_bonus = nullptr;
    //melee = false;
    //damage_type = nullptr;
    //weapon_group = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(const Headgear& original)
  {
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
  Headgear::Headgear(Headgear& original)
  {
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
  Headgear::Headgear(Headgear&& original)
  {
    std::move(this->hands, original.hands);
    std::move(this->speed_factor, original.speed_factor);
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_die, original.damage_die);
    std::move(this->damage_dice, original.damage_dice);
    std::move(this->damage_bonus, original.damage_bonus);
    std::swap(this->melee, original.melee);
    std::move(this->damage_type, original.damage_type);
    std::move(this->weapon_group, original.weapon_group);
  }
  
  
  
  /**
   * Destructor
   */
  Headgear::~Headgear()
  {
    //TODO implement destructor
    //delete hands;
    //delete speed_factor;
    //delete hit_bonus;
    //delete damage_die;
    //delete damage_dice;
    //delete damage_bonus;
    //delete damage_type;
    //delete weapon_group;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(const Headgear& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hands = original.hands;
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
  Headgear& Headgear::operator =(Headgear& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hands = original.hands;
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
  Headgear& Headgear::operator =(Headgear&& original)
  {
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);    std::move(this->hands, original.hands);
    std::move(this->speed_factor, original.speed_factor);
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_die, original.damage_die);
    std::move(this->damage_dice, original.damage_dice);
    std::move(this->damage_bonus, original.damage_bonus);
    std::swap(this->melee, original.melee);
    std::move(this->damage_type, original.damage_type);
    std::move(this->weapon_group, original.weapon_group);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Headgear::__copy__(Headgear& self, const Headgear& original);
  {
    left = right;
  }
  
}

