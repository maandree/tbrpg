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
#ifndef __PARTY__
#define __PARTY__


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
   * The players' party
   */
  class Party
  {
  public:
    /**
     * The strength, excluding extra for 18
     */
    short strength;
    
    /**
     * Extra strength for strength 18
     */
    short strength18;
    
    /**
     * The constitution
     */
    short constitution;
    
    /**
     * The dexterity
     */
    short dexterity;
    
    /**
     * The intelligence
     */
    short intelligence;
    
    /**
     * The wisdom
     */
    short wisdom;
    
    /**
     * The charisma
     */
    short charisma;
    
    
    
    /**
     * Construction
     */
    Party();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Party(const Party& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Party(Party& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Party(Party&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Party();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Party& operator =(const Party& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Party& operator =(Party& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Party& operator =(Party&& original);
    
  };
}


#endif//__PARTY__
