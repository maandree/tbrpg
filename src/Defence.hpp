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
#ifndef __GUARD_DEFENCE_HPP__
#define __GUARD_DEFENCE_HPP__


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
   * Defence class
   */
  class Defence
  {
  public:
    /**
     * Armour class versus melée bonus
     */
    int melee;
    
    /**
     * Armour class versus missile bonus
     */
    int missile;
    
    /**
     * Resistance against fire bonus
     */
    float fire;
    
    /**
     * Resistance against cold bonus
     */
    float cold;
    
    /**
     * Resistance against lightning bonus
     */
    float lightning;
    
    /**
     * Resistance against acid bonus
     */
    float acid;
    
    /**
     * Resistance against poison bonus
     */
    float poison;
    
    /**
     * Resistance against physical damage bonus
     */
    float physical;
    
    
    
    /**
     * Construction
     */
    Defence();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Defence(const Defence& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Defence(Defence& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Defence(Defence&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Defence();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Defence& operator =(const Defence& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Defence& operator =(Defence& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Defence& operator =(Defence&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Defence& self, const Defence& original);
    
    
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
  class hash<tbrpg::Defence>
  {
  public:
    size_t operator()(const tbrpg::Defence& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_DEFENCE_HPP__