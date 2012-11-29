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
#include "AbilityBonus.hpp"


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
  AbilityBonus::AbilityBonus()
  {
    ////TODO implement constructor
    //this->bonuses = nullptr;
    //this->thief_abilities = nullptr;
    //this->saving_throws = nullptr;
    //this->abilities = nullptr;
    //this->spells = nullptr;
    //this->effects = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(const AbilityBonus& original)
  {
    (void) original;
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus& original)
  {
    (void) original;
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus&& original)
  {
    (void) original;
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->thief_abilities, original.thief_abilities);
    std::swap(this->saving_throws, original.saving_throws);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->effects, original.effects);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityBonus::~AbilityBonus()
  {
    ////TODO implement destructor
    //delete this->bonuses;
    //delete this->thief_abilities;
    //delete this->saving_throws;
    //delete this->abilities;
    //delete this->spells;
    //delete this->effects;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityBonus& AbilityBonus::operator =(const AbilityBonus& original)
  {
    (void) original;
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityBonus& AbilityBonus::operator =(AbilityBonus& original)
  {
    (void) original;
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  AbilityBonus& AbilityBonus::operator =(AbilityBonus&& original)
  {
    (void) original;
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->thief_abilities, original.thief_abilities);
    std::swap(this->saving_throws, original.saving_throws);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->effects, original.effects);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool AbilityBonus::operator ==(const AbilityBonus& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void AbilityBonus::__copy__(AbilityBonus& self, const AbilityBonus& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t AbilityBonus::hash() const
  {
    return (size_t)this;
  }
  
}

