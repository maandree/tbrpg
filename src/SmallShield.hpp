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
#ifndef __SMALLSHIELD__
#define __SMALLSHIELD__


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
   * Small shield item class
   */
  class SmallShield: public  Shield
  {
  public:
    /**
     * Construction
     */
    SmallShield() : Shield();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SmallShield(const SmallShield& original) : Shield(original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SmallShield(SmallShield& original) : Shield(original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    SmallShield(SmallShield&& original) : Shield(original);
    
    
    
    /**
     * Destructor
     */
    virtual ~SmallShield();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SmallShield& operator =(const SmallShield& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SmallShield& operator =(SmallShield& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual SmallShield& operator =(SmallShield&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(SmallShield& self, const SmallShield& original);
  
  };
}


#endif//__SMALLSHIELD__
