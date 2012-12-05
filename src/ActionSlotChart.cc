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
    #define F  (1LL << 0LL)
    #define R  (1LL << 1LL)
    #define P  (1LL << 2LL)
    #define T  (1LL << 3LL)
    #define B  (1LL << 4LL)
    #define C  (1LL << 5LL)
    #define D  (1LL << 6LL)
    #define M  (1LL << 7LL)
    #define S  (1LL << 8LL)
    
    this->index_map[Fighter()] = F;
    this->index_map[Ranger()] = R;
    this->index_map[Paladin()] = P;
    this->index_map[Thief()] = T;
    this->index_map[Bard()] = B;
    this->index_map[Cleric()] = C;
    this->index_map[Druid()] = D;
    this->index_map[Mage()] = M;
    this->index_map[Sorcerer()] = S;
    
    this->slot_map[F] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_WEAPON, QUICK_WEAPON};
    this->slot_map[P] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_WEAPON, TURN_UNDEAD, CAST_SPELL};
    this->slot_map[R] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_WEAPON, STEALTH, CAST_SPELL};
    this->slot_map[M] = {QUICK_WEAPON, QUICK_SPELL, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[S] = {QUICK_WEAPON, QUICK_SPELL, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[C] = {QUICK_WEAPON, TURN_UNDEAD, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[D] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[B] = {QUICK_WEAPON, BARD_SONG, THIEVING, QUICK_SPELL, CAST_SPELL};
    this->slot_map[T] = {QUICK_WEAPON, QUICK_WEAPON, FIND_TRAPS, THIEVING, STEALTH};
    this->slot_map[F|T] = {QUICK_WEAPON, QUICK_WEAPON, FIND_TRAPS, THIEVING, STEALTH};
    this->slot_map[F|M] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[F|C] = {QUICK_WEAPON, QUICK_WEAPON, TURN_UNDEAD, QUICK_SPELL, CAST_SPELL};
    this->slot_map[F|D] = {QUICK_WEAPON, QUICK_WEAPON, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[R|C] = {QUICK_WEAPON, TURN_UNDEAD, STEALTH, QUICK_SPELL, CAST_SPELL};
    this->slot_map[T|C] = {QUICK_WEAPON, FIND_TRAPS, THIEVING, STEALTH, CAST_SPELL};
    this->slot_map[M|T] = {QUICK_WEAPON, FIND_TRAPS, THIEVING, STEALTH, CAST_SPELL};
    this->slot_map[M|C] = {QUICK_WEAPON, TURN_UNDEAD, QUICK_SPELL, QUICK_SPELL, CAST_SPELL};
    this->slot_map[F|M|T] = {QUICK_WEAPON, FIND_TRAPS, THIEVING, STEALTH, CAST_SPELL};
    this->slot_map[F|M|C] = {QUICK_WEAPON, QUICK_WEAPON, TURN_UNDEAD, QUICK_SPELL, CAST_SPELL};
    
    #undef F
    #undef R
    #undef P
    #undef T
    #undef B
    #undef C
    #undef D
    #undef M
    #undef S
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
    Object::__copy__((Object&)*this, (Object&)original);
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
    Object::__copy__((Object&)*this, (Object&)original);
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
    std::swap((Object&)*this, (Object&)original);
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
    return this == &other;
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
    return (size_t)this;
  }
  
}

