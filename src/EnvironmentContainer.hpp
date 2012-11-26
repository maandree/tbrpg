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
#ifndef __ENVIRONMENTCONTAINER__
#define __ENVIRONMENTCONTAINER__


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
   * Item container that are in the environments
   */
  class EnvironmentContainer: Container, Lockable
  {
  public:
    /**
     * Distance to the waylay point in metres
     */
    int first_distance;
    
    /**
     * Distance from the waylay point in metres
     */
    int last_distance;
    
    /**
     * The number of sides on the dice to roll to determine whether you are being waylaid
     */
    char waylay_die;
    
    /**
     * The number dice to roll to determine whether you are being waylaid
     */
    char waylay_dice;
    
    /**
     * The highest value for at which you get waylaid, use 0 for never, and 255 for always
     */
    unsigned char waylay_risk;
    
    /**
     * At which direction the road is located and leads
     */
    std::string direction;
    
    /**
     * The area entered if you get waylaid
     */
    MapMinor waylay_map;
    
    /**
     * The area to which the the road leads
     */
    MapMinor leads_to;
    
    
    
    /**
     * Construction
     */
    EnvironmentContainer();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    EnvironmentContainer(const EnvironmentContainer& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    EnvironmentContainer(EnvironmentContainer& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    EnvironmentContainer(EnvironmentContainer&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~EnvironmentContainer();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual EnvironmentContainer& operator =(const EnvironmentContainer& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual EnvironmentContainer& operator =(EnvironmentContainer& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual EnvironmentContainer& operator =(EnvironmentContainer&& original);
    
  };
}


#endif//__ENVIRONMENTCONTAINER__
