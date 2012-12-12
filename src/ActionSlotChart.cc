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
#include "ActionSlotChart.hpp"


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
  ActionSlotChart::ActionSlotChart() : Object()
  {
    this->class_inheritance.push_back(18);
    ////TODO implement constructor
    //this->index_map = nullptr;
    //this->slot_map = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(const ActionSlotChart& original) : Object(original)
  {
    (void) original;
    this->index_map = original.index_map;
    this->slot_map = original.slot_map;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(ActionSlotChart& original) : Object(original)
  {
    (void) original;
    this->index_map = original.index_map;
    this->slot_map = original.slot_map;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(ActionSlotChart&& original) : Object(original)
  {
    (void) original;
    std::swap(this->index_map, original.index_map);
    std::swap(this->slot_map, original.slot_map);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* ActionSlotChart::fork() const
  {
    return (Object*)(new ActionSlotChart(*this));
  }
  
  
  
  /**
   * Destructor
   */
  ActionSlotChart::~ActionSlotChart()
  {
    ////TODO implement destructor
    //delete this->index_map;
    //delete this->slot_map;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(const ActionSlotChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->index_map = original.index_map;
    this->slot_map = original.slot_map;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(ActionSlotChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->index_map = original.index_map;
    this->slot_map = original.slot_map;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(ActionSlotChart&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->index_map, original.index_map);
    std::swap(this->slot_map, original.slot_map);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ActionSlotChart::operator ==(const ActionSlotChart& other) const
  {
    if (this->index_map != other.index_map)  return false;
    if (this->slot_map != other.slot_map)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool ActionSlotChart::operator !=(const ActionSlotChart& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void ActionSlotChart::__copy__(ActionSlotChart& self, const ActionSlotChart& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ActionSlotChart::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::unordered_map<Class, long long>>()(this->index_map);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::unordered_map<long long, std::vector<ActionSlot>>>()(this->slot_map);
    return rc;
  }
  
}

