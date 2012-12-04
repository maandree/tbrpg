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
#include "Halfling.hpp"


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
  Halfling::Halfling() : Race()
  {
    this->name = "halfling";
    this->bonuses.bonuses.detect_doors = 0.05;
    this->bonuses.bonuses.magic_defence_bonus = 0.75;
    this->bonuses.defence.poison = 0.75;
    this->bonuses.abilities.dexterity = 1;
    this->bonuses.abilities.strength = -1;
    this->bonuses.thief_abilities.find_traps = 5;
    this->bonuses.thief_abilities.open_locks = 5;
    this->bonuses.thief_abilities.pick_pockets = 5;
    this->bonuses.thief_abilities.stealth = 15;
    
    this->allowed_classes =
      {{Fighter()},
       {Thief()},
       {Cleric()},
       {Mage()}, {Sorcerer()},
       {Fighter(), Thief()}, {Fighter(), Cleric()}, {Fighter(), Druid()}, {Fighter(), Mage()},
       {Mage(), Cleric()},
       {Fighter(), Mage(), Thief()},
       {Fighter(), Mage(), Cleric()}};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Halfling::Halfling(const Halfling& original) : Race(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Halfling::Halfling(Halfling& original) : Race(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Halfling::Halfling(Halfling&& original) : Race(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Halfling::~Halfling()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Halfling& Halfling::operator =(const Halfling& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Halfling& Halfling::operator =(Halfling& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Halfling& Halfling::operator =(Halfling&& original)
  {
    (void) original;

    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Halfling::operator ==(const Halfling& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Halfling::__copy__(Halfling& self, const Halfling& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Halfling::hash() const
  {
    return (size_t)this;
  }
  
}

