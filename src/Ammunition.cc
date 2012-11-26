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
  Ammunition::Ammunition()
  {
    //TODO implement constructor
    //wizard_slots = nullptr;
    //priest_slots = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(const Ammunition& original)
  {
    this->wizard_slots = original.wizard_slots;
    this->priest_slots = original.priest_slots;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition& original)
  {
    this->wizard_slots = original.wizard_slots;
    this->priest_slots = original.priest_slots;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Ammunition::Ammunition(Ammunition&& original)
  {
    std::move(this->wizard_slots, original.wizard_slots);
    std::move(this->priest_slots, original.priest_slots);
  }
  
  
  
  /**
   * Destructor
   */
  Ammunition::~Ammunition()
  {
    //TODO implement destructor
    //delete wizard_slots;
    //delete priest_slots;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ammunition& Ammunition::operator =(const Ammunition& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->wizard_slots = original.wizard_slots;
    this->priest_slots = original.priest_slots;
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
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->wizard_slots = original.wizard_slots;
    this->priest_slots = original.priest_slots;
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
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);    std::move(this->wizard_slots, original.wizard_slots);
    std::move(this->priest_slots, original.priest_slots);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Ammunition::__copy__(Ammunition& self, const Ammunition& original);
  {
    left = right;
  }
  
}

