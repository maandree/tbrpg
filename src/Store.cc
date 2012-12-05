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
#include "Store.hpp"


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
  Store::Store() : NPC()
  {
    this->class_inheritance.push_back(80);
    this->record.name = "Store keeper";
    this->cost_multiplier = 1.5;
    this->identify_cost = 100;
    //this->spells = nullptr;
    //this->spell_costs = nullptr;
    //this->inventory = nullptr;
    //this->room_costs = nullptr;
    //this->room_quality = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Store::Store(const Store& original) : NPC(original)
  {
    (void) original;
    this->cost_multiplier = original.cost_multiplier;
    this->identify_cost = original.identify_cost;
    this->spells = original.spells;
    this->spell_costs = original.spell_costs;
    this->inventory = original.inventory;
    this->room_costs = original.room_costs;
    this->room_quality = original.room_quality;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Store::Store(Store& original) : NPC(original)
  {
    (void) original;
    this->cost_multiplier = original.cost_multiplier;
    this->identify_cost = original.identify_cost;
    this->spells = original.spells;
    this->spell_costs = original.spell_costs;
    this->inventory = original.inventory;
    this->room_costs = original.room_costs;
    this->room_quality = original.room_quality;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Store::Store(Store&& original) : NPC(original)
  {
    (void) original;
    std::swap(this->cost_multiplier, original.cost_multiplier);
    std::swap(this->identify_cost, original.identify_cost);
    std::swap(this->spells, original.spells);
    std::swap(this->spell_costs, original.spell_costs);
    std::swap(this->inventory, original.inventory);
    std::swap(this->room_costs, original.room_costs);
    std::swap(this->room_quality, original.room_quality);
  }
  
  
  
  /**
   * Destructor
   */
  Store::~Store()
  {
    ////TODO implement destructor
    //delete this->spells;
    //delete this->spell_costs;
    //delete this->inventory;
    //delete this->room_costs;
    //delete this->room_quality;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Store& Store::operator =(const Store& original)
  {
    (void) original;
    NPC::__copy__((NPC&)*this, (NPC&)original);    this->cost_multiplier = original.cost_multiplier;
    this->identify_cost = original.identify_cost;
    this->spells = original.spells;
    this->spell_costs = original.spell_costs;
    this->inventory = original.inventory;
    this->room_costs = original.room_costs;
    this->room_quality = original.room_quality;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Store& Store::operator =(Store& original)
  {
    (void) original;
    NPC::__copy__((NPC&)*this, (NPC&)original);    this->cost_multiplier = original.cost_multiplier;
    this->identify_cost = original.identify_cost;
    this->spells = original.spells;
    this->spell_costs = original.spell_costs;
    this->inventory = original.inventory;
    this->room_costs = original.room_costs;
    this->room_quality = original.room_quality;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Store& Store::operator =(Store&& original)
  {
    (void) original;
    std::swap((NPC&)*this, (NPC&)original);    std::swap(this->cost_multiplier, original.cost_multiplier);
    std::swap(this->identify_cost, original.identify_cost);
    std::swap(this->spells, original.spells);
    std::swap(this->spell_costs, original.spell_costs);
    std::swap(this->inventory, original.inventory);
    std::swap(this->room_costs, original.room_costs);
    std::swap(this->room_quality, original.room_quality);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Store::operator ==(const Store& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Store::__copy__(Store& self, const Store& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Store::hash() const
  {
    return (size_t)this;
  }
  
}

