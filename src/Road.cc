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
#include "Road.hpp"


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
  Road::Road()
  {
    ////TODO implement constructor
    //this->first_distance = 0;
    //this->last_distance = 0;
    //this->waylay_die = 0;
    //this->waylay_dice = 0;
    //this->waylay_risk = 0;
    //this->direction = nullptr;
    //this->waylay_map = nullptr;
    //this->leads_to = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Road::Road(const Road& original)
  {
    (void) original;
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Road::Road(Road& original)
  {
    (void) original;
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Road::Road(Road&& original)
  {
    (void) original;
    std::swap(this->first_distance, original.first_distance);
    std::swap(this->last_distance, original.last_distance);
    std::swap(this->waylay_die, original.waylay_die);
    std::swap(this->waylay_dice, original.waylay_dice);
    std::swap(this->waylay_risk, original.waylay_risk);
    std::swap(this->direction, original.direction);
    std::swap(this->waylay_map, original.waylay_map);
    std::swap(this->leads_to, original.leads_to);
  }
  
  
  
  /**
   * Destructor
   */
  Road::~Road()
  {
    ////TODO implement destructor
    //delete this->direction;
    //delete this->waylay_map;
    //delete this->leads_to;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Road& Road::operator =(const Road& original)
  {
    (void) original;
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Road& Road::operator =(Road& original)
  {
    (void) original;
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Road& Road::operator =(Road&& original)
  {
    (void) original;
    std::swap(this->first_distance, original.first_distance);
    std::swap(this->last_distance, original.last_distance);
    std::swap(this->waylay_die, original.waylay_die);
    std::swap(this->waylay_dice, original.waylay_dice);
    std::swap(this->waylay_risk, original.waylay_risk);
    std::swap(this->direction, original.direction);
    std::swap(this->waylay_map, original.waylay_map);
    std::swap(this->leads_to, original.leads_to);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Road::operation ==(const Road& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Road::__copy__(Road& self, const Road& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Road::hash() const
  {
    return (size_t)this;
  }
  
}

