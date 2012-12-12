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
    this->class_inheritance.push_back(140);
    ////TODO implement constructor
    //this->cost_multiplier = 0;
    //this->identify_cost = 0;
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Store::fork() const
  {
    return (Object*)(new Store(*this));
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
    if ((NPC&)(*this) != (NPC&)other)  return false;
    if (this->cost_multiplier != other.cost_multiplier)  return false;
    if (this->identify_cost != other.identify_cost)  return false;
    if (this->spells != other.spells)  return false;
    if (this->spell_costs != other.spell_costs)  return false;
    if (this->inventory != other.inventory)  return false;
    if (this->room_costs != other.room_costs)  return false;
    if (this->room_quality != other.room_quality)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Store::operator !=(const Store& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<NPC>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<float>()(this->cost_multiplier);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->identify_cost);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<Spell>>()(this->spells);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::vector<int>>()(this->spell_costs);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::vector<Item>>()(this->inventory);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<std::vector<int>>()(this->room_costs);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<float>>()(this->room_quality);
    return rc;
  }
  
}

