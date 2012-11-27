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
#include "RestInterruption.hpp"


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
  RestInterruption::RestInterruption()
  {
    ////TODO implement constructor
    //this->interrupt_die = 0;
    //this->interrupt_dice = 0;
    //this->interrupt_risk = 0;
    //this->creatures = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RestInterruption::RestInterruption(const RestInterruption& original)
  {
    (void) original;
    this->interrupt_die = original.interrupt_die;
    this->interrupt_dice = original.interrupt_dice;
    this->interrupt_risk = original.interrupt_risk;
    this->creatures = original.creatures;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RestInterruption::RestInterruption(RestInterruption& original)
  {
    (void) original;
    this->interrupt_die = original.interrupt_die;
    this->interrupt_dice = original.interrupt_dice;
    this->interrupt_risk = original.interrupt_risk;
    this->creatures = original.creatures;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RestInterruption::RestInterruption(RestInterruption&& original)
  {
    (void) original;
    std::swap(this->interrupt_die, original.interrupt_die);
    std::swap(this->interrupt_dice, original.interrupt_dice);
    std::swap(this->interrupt_risk, original.interrupt_risk);
    std::swap(this->creatures, original.creatures);
  }
  
  
  
  /**
   * Destructor
   */
  RestInterruption::~RestInterruption()
  {
    ////TODO implement destructor
    //delete creatures;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RestInterruption& RestInterruption::operator =(const RestInterruption& original)
  {
    (void) original;
    this->interrupt_die = original.interrupt_die;
    this->interrupt_dice = original.interrupt_dice;
    this->interrupt_risk = original.interrupt_risk;
    this->creatures = original.creatures;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RestInterruption& RestInterruption::operator =(RestInterruption& original)
  {
    (void) original;
    this->interrupt_die = original.interrupt_die;
    this->interrupt_dice = original.interrupt_dice;
    this->interrupt_risk = original.interrupt_risk;
    this->creatures = original.creatures;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  RestInterruption& RestInterruption::operator =(RestInterruption&& original)
  {
    (void) original;
    std::swap(this->interrupt_die, original.interrupt_die);
    std::swap(this->interrupt_dice, original.interrupt_dice);
    std::swap(this->interrupt_risk, original.interrupt_risk);
    std::swap(this->creatures, original.creatures);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void RestInterruption::__copy__(RestInterruption& self, const RestInterruption& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t RestInterruption::hash() const
  {
    return (size_t)this;
  }
  
}

