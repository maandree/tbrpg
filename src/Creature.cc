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
#include "Creature.hpp"


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
  Creature::Creature()
  {
    //TODO implement constructor
    //interrupt_die = nullptr;
    //interrupt_dice = nullptr;
    //interrupt_risk = 0;
    //creatures = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Creature::Creature(const Creature& original)
  {
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
  Creature::Creature(Creature& original)
  {
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
  Creature::Creature(Creature&& original)
  {
    std::move(this->interrupt_die, original.interrupt_die);
    std::move(this->interrupt_dice, original.interrupt_dice);
    std::swap(this->interrupt_risk, original.interrupt_risk);
    std::move(this->creatures, original.creatures);
  }
  
  
  
  /**
   * Destructor
   */
  Creature::~Creature()
  {
    //TODO implement destructor
    //delete interrupt_die;
    //delete interrupt_dice;
    //delete creatures;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Creature& Creature::operator =(const Creature& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->interrupt_die = original.interrupt_die;
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
  Creature& Creature::operator =(Creature& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->interrupt_die = original.interrupt_die;
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
  Creature& Creature::operator =(Creature&& original)
  {
    std::move((Character)*this, (Character)original);
    std::move((Character)*this, (Character)original);
    std::move((Character)*this, (Character)original);
    std::move((Character)*this, (Character)original);    std::move(this->interrupt_die, original.interrupt_die);
    std::move(this->interrupt_dice, original.interrupt_dice);
    std::swap(this->interrupt_risk, original.interrupt_risk);
    std::move(this->creatures, original.creatures);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Creature::__copy__(Creature& self, const Creature& original);
  {
    left = right;
  }
  
}

