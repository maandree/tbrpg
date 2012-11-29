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
#include "Thief.hpp"


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
  Thief::Thief() : Rogue()
  {
    this->thac0 = 23;
    this->lore_bonus = 3;
    this->lower_limits.dexterity = 9;
    this->abilities.bonuses.detect_doors = 0.15;
    this->alignments[8] = false;
    this->abilities.thief_abilities.find_traps = 5;
    this->abilities.thief_abilities.open_locks = 10;
    this->abilities.thief_abilities.pick_pockets = 15;
    this->abilities.thief_abilities.stealth = 10;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Thief::Thief(const Thief& original) : Rogue(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Thief::Thief(Thief& original) : Rogue(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Thief::Thief(Thief&& original) : Rogue(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Thief::~Thief()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Thief& Thief::operator =(const Thief& original)
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
  Thief& Thief::operator =(Thief& original)
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
  Thief& Thief::operator =(Thief&& original)
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
  bool Thief::operator ==(const Thief& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Thief::__copy__(Thief& self, const Thief& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Thief::hash() const
  {
    return (size_t)this;
  }
  
}

