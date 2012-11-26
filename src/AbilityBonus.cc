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
    //TODO implement constructor
    //character = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(const AbilityBonus& original)
  {
    this->character = original.character;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus& original)
  {
    this->character = original.character;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityBonus::AbilityBonus(AbilityBonus&& original)
  {
    std::move(this->character, original.character);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityBonus::~AbilityBonus()
  {
    //TODO implement destructor
    //delete character;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityBonus& AbilityBonus::operator =(const AbilityBonus& original)
  {
    this->character = original.character;
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
    this->character = original.character;
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
    std::move(this->character, original.character);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void AbilityBonus::__copy__(AbilityBonus& self, const AbilityBonus& original);
  {
    left = right;
  }
  
}

