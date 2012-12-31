// -*- mode: c++, encoding: utf-8 -*-
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
#ifndef __GUARD_DIE_HPP__
#define __GUARD_DIE_HPP__


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
   * Die with an arbirary side count
   */
  class Die
  {
  protected:
    /**
     * The number of sides on the die
     */
    char sides;
    
    
  public:
    /**
     * Constructor
     * 
     * @param  sideCount  The number of sides on the die
     */
    Die(char sideCount = 0);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Die(const Die& original);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Die(Die& original);
    
    /**
     * Move constructor
     *
     * @param  original  The object to clone
     */
    Die(Die&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Die();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Die& operator =(const Die& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Die& operator =(Die& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Die& operator =(Die&& original);
    
    
    
    /**
     * Gets the number of sides on the die
     * 
     * @return  The number of sides on the die
     */
    virtual char getSides() const;
    
    /**
     * Roll the die
     * 
     * @return  The number of eyes on the die's value side
     */
    virtual char roll() const;
    
  };
}


#endif//__GUARD_DIE_HPP__

