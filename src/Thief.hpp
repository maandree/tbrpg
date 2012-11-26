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
#ifndef __THIEF__
#define __THIEF__


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
   * The thief class
   */
  class Thief: public  Rogue
  {
  public:
    /**
     * Construction
     */
    Thief() : Rogue();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Thief(const Thief& original) : Rogue(original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Thief(Thief& original) : Rogue(original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Thief(Thief&& original) : Rogue(original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Thief();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Thief& operator =(const Thief& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Thief& operator =(Thief& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Thief& operator =(Thief&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Thief& self, const Thief& original);
  
  };
}


#endif//__THIEF__
