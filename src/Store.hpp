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
#ifndef __GUARD_STORE_HPP__
#define __GUARD_STORE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "NPC.hpp"
#include "hash.hpp"
#include "Spell.hpp"
#include "Item.hpp"


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
   * Store non-player character
   */
  class Store: public NPC
  {
  public:
    /**
     * Multipler for the value of the items at which the store sells, it buys at unmodified value
     */
    float cost_multiplier;
    
    /**
     * The price at which the stores identifies items, negative if it does not offer identification
     */
    int identify_cost;
    
    /**
     * Spells the store (priest) offers to cast
     */
    std::vector<Spell> spells;
    
    /**
     * The cost at which the store (priest) casts spells
     */
    std::vector<int> spell_costs;
    
    /**
     * The store's inventory, negative quantity if unlimited, zero does selling and not buying
     */
    std::vector<Item> inventory;
    
    /**
     * The cost of the available rooms
     */
    std::vector<int> room_costs;
    
    /**
     * The natural healing multiplier for the available rooms
     */
    std::vector<float> room_quality;
    
    
    
    /**
     * Construction
     */
    Store();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Store(const Store& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Store(Store& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Store(Store&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Store();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Store& operator =(const Store& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Store& operator =(Store& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Store& operator =(Store&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Store& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Store& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Store& self, const Store& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Store>
  {
  public:
    size_t operator()(const tbrpg::Store& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Store*>
  {
  public:
    size_t operator()(tbrpg::Store* elem) const
    {
       return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_STORE_HPP__

