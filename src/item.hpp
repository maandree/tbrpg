// -*- mode: c++, encoding: utf-8 -*-
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
#ifndef __ITEM__
#define __ITEM__


#include <stdlib.h>
#include <algorithm>


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
   * Item base class
   */
  class Item
  {
  protected:
    /**
     * The item's weight in grams
     */
    int weight;
    
    /**
     * Is the item stuck in its current position
     */
    bool stuck;
    
    
  public:
    /**
     * Constructor
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
     * Reconstruction operator
     * 
     * @return  The invoked object
     */
    virtual Item& operator =();
    
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
     * Get the weight of the item
     * 
     * @return  The weight of the item
     */
    virtual int getWeight() const;
    
    /**
     * Is the item stuck in its position
     * 
     * @return  Whether the item is stuck in its position
     */
    virtual bool isStuck() const;
    
  };
}


#endif//__ITEM__

