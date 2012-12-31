// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#ifndef __GUARD_ACTIONSLOT_HPP__
#define __GUARD_ACTIONSLOT_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>


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
   * Action slot
   */
  class ActionSlot
  {
  protected:
    /**
     * The ID of the slot type
     */
    char id;
    
    
    
  public:
    /**
     * Construction
     * 
     * @param  typeID  The ID of the slot type
     */
    ActionSlot(char typeID = 0);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlot(const ActionSlot& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlot(ActionSlot& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlot(ActionSlot&& original);
    
    
    
    /**
     * Destructor
     */
    ~ActionSlot();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    ActionSlot& operator =(const ActionSlot& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    ActionSlot& operator =(ActionSlot& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    ActionSlot& operator =(ActionSlot&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    bool operator ==(const ActionSlot& other) const;
    
    
    
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
    
    
  /**
   * Action slot: Quick weapon
   */
  static ActionSlot QUICK_WEAPON = 0;
  
  /**
   * Action slot: Quick spell
   */
  static ActionSlot QUICK_SPELL = 1;
  
  /**
   * Action slot: Turn undead
   */
  static ActionSlot TURN_UNDEAD = 2;
  
  /**
   * Action slot: Bard song
   */
  static ActionSlot BARD_SONG = 3;
  
  /**
   * Action slot: Find traps
   */
  static ActionSlot FIND_TRAPS = 4;
  
  /**
   * Action slot: Thieving
   */
  static ActionSlot THIEVING = 5;
  
  /**
   * Action slot: Stealth
   */
  static ActionSlot STEALTH = 6;
  
  /**
   * Action slot: Cast spell
   */
  static ActionSlot CAST_SPELL = 7;
  
  
}


namespace std
{
  template<>
  class hash<tbrpg::ActionSlot>
  {
  public:
    size_t operator()(const tbrpg::ActionSlot& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_ACTIONSLOT_HPP__
