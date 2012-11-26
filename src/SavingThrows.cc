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
#include "SavingThrows.hpp"


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
  SavingThrows::SavingThrows()
  {
    //TODO implement constructor
    //find_traps = nullptr;
    //open_locks = nullptr;
    //pick_pockets = nullptr;
    //stealth = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(const SavingThrows& original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows& original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows&& original)
  {
    std::move(this->find_traps, original.find_traps);
    std::move(this->open_locks, original.open_locks);
    std::move(this->pick_pockets, original.pick_pockets);
    std::move(this->stealth, original.stealth);
  }
  
  
  
  /**
   * Destructor
   */
  SavingThrows::~SavingThrows()
  {
    //TODO implement destructor
    //delete find_traps;
    //delete open_locks;
    //delete pick_pockets;
    //delete stealth;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(const SavingThrows& original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows& original)
  {
    this->find_traps = original.find_traps;
    this->open_locks = original.open_locks;
    this->pick_pockets = original.pick_pockets;
    this->stealth = original.stealth;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows&& original)
  {
    std::move(this->find_traps, original.find_traps);
    std::move(this->open_locks, original.open_locks);
    std::move(this->pick_pockets, original.pick_pockets);
    std::move(this->stealth, original.stealth);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void SavingThrows::__copy__(SavingThrows& self, const SavingThrows& original);
  {
    left = right;
  }
  
}

