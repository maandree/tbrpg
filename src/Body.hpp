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
#ifndef __BODY__
#define __BODY__


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
   * Character body item class
   */
  class Body: Item
  {
  public:
    /**
     * Left hand item slots
     */
    Weapon[] left_hand;
    
    /**
     * Right hand item slot
     */
    RightHandItem right_hand;
    
    /**
     * Quiver slots
     */
    Ammunition[] quiver;
    
    /**
     * Quick item slots
     */
    QuickItem[] quick_items;
    
    /**
     * Headgear slots
     */
    Headgear headgear;
    
    /**
     * Amulette and necklace slot
     */
    Amulett amulett;
    
    /**
     * Ring slots
     */
    Ring[] rings;
    
    /**
     * Body armour slot
     */
    BodyArmour body;
    
    /**
     * Gauntlet and bracer slots
     */
    Gauntlets gauntlets;
    
    /**
     * Girdle and belt slot
     */
    Girdle girdle;
    
    /**
     * Boot slot
     */
    Boots boots;
    
    /**
     * Cloak slot
     */
    Cloak cloak;
    
    /**
     * Personal inventory slots
     */
    Item[] personal;
    
    
    
    /**
     * Construction
     */
    Body();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Body(const Body& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Body(Body& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Body(Body&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Body();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Body& operator =(const Body& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Body& operator =(Body& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Body& operator =(Body&& original);
    
  };
}


#endif//__BODY__
