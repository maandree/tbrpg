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
  AbilityBonus::AbilityBonus() : Object()
  {
    this->class_inheritance.push_back(25);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(const AbilityBonus& original) : Object(original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    this->defence = original.defence;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus& original) : Object(original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    this->defence = original.defence;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus&& original) : Object(original)
  {
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->thief_abilities, original.thief_abilities);
    std::swap(this->saving_throws, original.saving_throws);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->effects, original.effects);
    std::swap(this->defence, original.defence);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityBonus::~AbilityBonus()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityBonus& AbilityBonus::operator =(const AbilityBonus& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    this->defence = original.defence;
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
    Object::__copy__((Object&)*this, (Object&)original);
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    this->defence = original.defence;
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
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->thief_abilities, original.thief_abilities);
    std::swap(this->saving_throws, original.saving_throws);
    std::swap(this->abilities, original.abilities);
    std::swap(this->spells, original.spells);
    std::swap(this->effects, original.effects);
    std::swap(this->defence, original.defence);
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
    if (this->bonuses != other.bonuses)  return false;
    if (this->thief_abilities != other.thief_abilities)  return false;
    if (this->saving_throws != other.saving_throws)  return false;
    if (this->abilities != other.abilities)  return false;
    if (this->spells != other.spells)  return false;
    if (this->effects != other.effects)  return false;
    if (this->defence != other.defence)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool AbilityBonus::operator !=(const AbilityBonus& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<Bonuses>()(bonuses);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<ThiefAbilities>()(thief_abilities);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<SavingThrows>()(saving_throws);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<Abilities>()(abilities);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<SpellBook>()(spells);
    rc = (rc * 13) ^ (rc >> (sizeof(size_t) << 2) * 13);
    rc += std::hash<std::vector<Spell>>()(effects);
    rc = (rc * 17) ^ (rc >> (sizeof(size_t) << 2) * 17);
    rc += std::hash<Defence>()(defence);
    return rc;
  }
  
}

