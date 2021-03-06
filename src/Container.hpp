// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __GUARD_CONTAINER_HPP__
#define __GUARD_CONTAINER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Item.hpp"
#include "hash.hpp"


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
   * Item container item class
   */
  class Container: public Item
  {
  public:
    /**
     * Items contained by the container
     */
    std::vector<Item*> contains;
    
    /**
     * Number of items that can be put in the container
     */
    int contain_limit;
    
    /**
     * Weight multiplier
     */
    float weight_modifier;
    
    /**
     * Items that can be put inside the container
     */
    std::vector<Item> can_contain;
    
    
    
    /**
     * Construction
     */
    Container();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Container(const Container& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Container(Container& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Container(Container&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Container();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Container& operator =(const Container& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Container& operator =(Container& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Container& operator =(Container&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Container& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Container& other) const;
    
    
    /**
     * Check whether the container can hold an item
     * 
     * @param   item    The item to add
     * @param   remove  Item to remove
     * @return          Whether the container can hold the item
     */
    virtual bool canHold(Item* item, Item* remove = nullptr) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Container& self, const Container& original);
    
    
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
  class hash<tbrpg::Container>
  {
  public:
    size_t operator()(const tbrpg::Container& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Container*>
  {
  public:
    size_t operator()(tbrpg::Container* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_CONTAINER_HPP__

