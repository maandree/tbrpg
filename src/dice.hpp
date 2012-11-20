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
#ifndef __DICE__
#define __DICE__


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
   * Dice with an arbirary side count
   */
  class Dice
  {
  protected:
    /**
     * The number of sides on the dice
     */
    int sides;
    
    
  public:
    /**
     * Constructor
     * 
     * @param  sideCount  The number of sides on the dice
     */
    Dice(int sideCount = 0);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Dice(const Dice& original);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Dice(Dice& original);
    
    /**
     * Move constructor
     *
     * @param  original  The object to clone
     */
    Dice(Dice&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Dice();
    
    
    
    /**
     * Reconstruction operator
     * 
     * @param   sideCount  The number of sides on the dice 
     * @return             The invoked object
     */
    virtual Dice& operator =(int sideCount);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Dice& operator =(const Dice& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Dice& operator =(Dice& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Dice& operator =(Dice&& original);
    
    
    
    /**
     * Gets the number of sides on the dice
     * 
     * @return  The number of sides on the dice
     */
    virtual int getSides() const;
    
    /**
     * Throw the dice
     * 
     * @return  The number of eyes on the dice's value side
     */
    virtual int getThrow() const;
    
  };
}


#endif//__DICE__

