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
    ////TODO implement constructor
    //this->hit_bonus = 0;
    //this->damage_die = 0;
    //this->damage_dice = 0;
    //this->damage_bonus = 0;
    //this->usable_with = nullptr;
    //this->damage_type = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(const Ammunition& original) : Item(original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_die = original.damage_die;
    //this->damage_dice = original.damage_dice;
    //this->damage_bonus = original.damage_bonus;
    //this->usable_with = original.usable_with;
    //this->damage_type = original.damage_type;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition& original) : Item(original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_die = original.damage_die;
    //this->damage_dice = original.damage_dice;
    //this->damage_bonus = original.damage_bonus;
    //this->usable_with = original.usable_with;
    //this->damage_type = original.damage_type;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition&& original) : Item(original)
  {
    (void) original;
    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_die, original.damage_die);
    ////std::swap(this->damage_dice, original.damage_dice);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::move(this->usable_with, original.usable_with);
    ////std::move(this->damage_type, original.damage_type);
  }
  
  
  
  /**
   * Destructor
   */
  Ammunition::~Ammunition()
  {
    ////TODO implement destructor
    //delete usable_with;
    //delete damage_type;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ammunition& Ammunition::operator =(const Ammunition& original)
  {
    (void) original;
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);    //this->hit_bonus = original.hit_bonus;
    //this->damage_die = original.damage_die;
    //this->damage_dice = original.damage_dice;
    //this->damage_bonus = original.damage_bonus;
    //this->usable_with = original.usable_with;
    //this->damage_type = original.damage_type;
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
    (void) original;
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);
    //Item::__copy__((Item&)*this, (Item&)original);    //this->hit_bonus = original.hit_bonus;
    //this->damage_die = original.damage_die;
    //this->damage_dice = original.damage_dice;
    //this->damage_bonus = original.damage_bonus;
    //this->usable_with = original.usable_with;
    //this->damage_type = original.damage_type;
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
    (void) original;
    ////std::move((Item&)*this, (Item&)original);
    ////std::move((Item&)*this, (Item&)original);
    ////std::move((Item&)*this, (Item&)original);
    ////std::move((Item&)*this, (Item&)original);
    ////std::move((Item&)*this, (Item&)original);
    ////std::move((Item&)*this, (Item&)original);    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_die, original.damage_die);
    ////std::swap(this->damage_dice, original.damage_dice);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::move(this->usable_with, original.usable_with);
    ////std::move(this->damage_type, original.damage_type);
    return *this;
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
    return (size_t)this;
  }
  
}

