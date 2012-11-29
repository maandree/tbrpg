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
#ifndef __GUARD_ITEM_HPP__
#define __GUARD_ITEM_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "AbilityBonus.hpp"
#include "DamageType.hpp"


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
   * Item class
   */
  class Item
  {
  public:
    /**
     * The name of the item
     */
    std::string name;
    
    /**
     * Description of the item, text scrolls should use this for their text
     */
    std::string description;
    
    /**
     * The armour class, use 2³¹ − 1 for none
     */
    int armour_class;
    
    /**
     * The wieght of the item, in grams
     */
    int weight;
    
    /**
     * Whether the item is identified
     */
    bool identified;
    
    /**
     * The lore needed to identify the item by examining it
     */
    int lore_value;
    
    /**
     * Whether the item is stuck in its position
     */
    bool stuck;
    
    /**
     * Whether the item is cursed
     */
    bool cursed;
    
    /**
     * The current quantity
     */
    int quantity;
    
    /**
     * The quantity limit
     */
    int quantity_limit;
    
    /**
     * The monetary value of each item
     */
    int unit_value;
    
    /**
     * Ability bonuses
     */
    AbilityBonus bonuses;
    
    /**
     * Armour class modifiers for the damage types
     */
    std::unordered_map<DamageType, int> armour_class_modifiers;
    
    
    
    /**
     * Construction
     */
    Item();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Item(const Item& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Item(Item& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Item(Item&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Item();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Item& operator =(const Item& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Item& operator =(Item& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Item& operator =(Item&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operation ==(const Item& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Item& self, const Item& original);
    
    
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
  class hash<tbrpg::Item>
  {
  public:
    size_t operator()(const tbrpg::Item& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_ITEM_HPP__
