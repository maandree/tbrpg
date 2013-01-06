// -*- mode: c++ , coding: utf-8 -*-
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
#ifndef __GUARD_INVENTORY_HPP__
#define __GUARD_INVENTORY_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"
#include "Weapon.hpp"
#include "RightHandItem.hpp"
#include "Ammunition.hpp"
#include "QuickItem.hpp"
#include "Headgear.hpp"
#include "Amulet.hpp"
#include "Ring.hpp"
#include "BodyArmour.hpp"
#include "Gauntlets.hpp"
#include "Girdle.hpp"
#include "Boots.hpp"
#include "Cloak.hpp"
#include "Item.hpp"
#include "cleaner.hpp"


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
   * Character inventory class
   */
  class Inventory: public Object
  {
  public:
    /**
     * Left hand item slots
     */
    std::vector<Weapon*> left_hand;
    
    /**
     * Right hand item slot
     */
    RightHandItem* right_hand;
    
    /**
     * Quiver slots
     */
    std::vector<Ammunition*> quiver;
    
    /**
     * Quick item slots
     */
    std::vector<QuickItem*> quick_items;
    
    /**
     * Headgear slots
     */
    Headgear* headgear;
    
    /**
     * Amulet, necklace and locket slot
     */
    Amulet* amulet;
    
    /**
     * Ring slots
     */
    std::vector<Ring*> rings;
    
    /**
     * Body armour slot
     */
    BodyArmour* body;
    
    /**
     * Gauntlet and bracer slots
     */
    Gauntlets* gauntlets;
    
    /**
     * Girdle and belt slot
     */
    Girdle* girdle;
    
    /**
     * Boot slot
     */
    Boots* boots;
    
    /**
     * Cloak slot
     */
    Cloak* cloak;
    
    /**
     * Personal inventory slots
     */
    std::vector<Item*> personal;
    
    
    
    /**
     * Construction
     */
    Inventory();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(const Inventory& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(Inventory& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Inventory(Inventory&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Inventory();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Inventory& operator =(const Inventory& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Inventory& operator =(Inventory& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Inventory& operator =(Inventory&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Inventory& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Inventory& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Inventory& self, const Inventory& original);
    
    /**
     * Internal cleaning
     */
    void __delete__();
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    virtual size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Inventory>
  {
  public:
    size_t operator()(const tbrpg::Inventory& elem) const
    {
      return dynamic_cast<const tbrpg::Inventory*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::Inventory*>
  {
  public:
    size_t operator()(tbrpg::Inventory* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<tbrpg::Inventory*>(elem)->hash();
    }
  };
}


#endif//__GUARD_INVENTORY_HPP__

