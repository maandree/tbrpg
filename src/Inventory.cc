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
#include "Inventory.hpp"


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
  Inventory::Inventory()
  {
    //TODO implement constructor
    //strength = nullptr;
    //strength18 = nullptr;
    //dexterity = nullptr;
    //constitution = nullptr;
    //intelligence = nullptr;
    //wisdom = nullptr;
    //charisma = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(const Inventory& original)
  {
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory& original)
  {
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory&& original)
  {
    std::move(this->strength, original.strength);
    std::move(this->strength18, original.strength18);
    std::move(this->dexterity, original.dexterity);
    std::move(this->constitution, original.constitution);
    std::move(this->intelligence, original.intelligence);
    std::move(this->wisdom, original.wisdom);
    std::move(this->charisma, original.charisma);
  }
  
  
  
  /**
   * Destructor
   */
  Inventory::~Inventory()
  {
    //TODO implement destructor
    //delete strength;
    //delete strength18;
    //delete dexterity;
    //delete constitution;
    //delete intelligence;
    //delete wisdom;
    //delete charisma;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(const Inventory& original)
  {
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(Inventory& original)
  {
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(Inventory&& original)
  {
    std::move(this->strength, original.strength);
    std::move(this->strength18, original.strength18);
    std::move(this->dexterity, original.dexterity);
    std::move(this->constitution, original.constitution);
    std::move(this->intelligence, original.intelligence);
    std::move(this->wisdom, original.wisdom);
    std::move(this->charisma, original.charisma);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Inventory::__copy__(Inventory& self, const Inventory& original);
  {
    left = right;
  }
  
}

