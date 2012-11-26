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
#ifndef __GUARD_SPELLPROGRESSION_HPP__
#define __GUARD_SPELLPROGRESSION_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>




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
   * Spell progression chart
   */
  class SpellProgression
  {
  public:
    /**
     * The number of wizard spell slots per character level and spell level
     */
    //int** wizard_slots;
    
    /**
     * The number of priest spell slots per character level and spell level
     */
    //int** priest_slots;
    
    
    
    /**
     * Construction
     */
    SpellProgression();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SpellProgression(const SpellProgression& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SpellProgression(SpellProgression& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    SpellProgression(SpellProgression&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~SpellProgression();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SpellProgression& operator =(const SpellProgression& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SpellProgression& operator =(SpellProgression& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual SpellProgression& operator =(SpellProgression&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(SpellProgression& self, const SpellProgression& original);
    
  };
}


#endif//__GUARD_SPELLPROGRESSION_HPP__
