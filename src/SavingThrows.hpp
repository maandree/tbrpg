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
#ifndef __GUARD_SAVINGTHROWS_HPP__
#define __GUARD_SAVINGTHROWS_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"



#include "hash.h"

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
   * Saving throws
   */
  class SavingThrows: public Object
  {
  public:
    /**
     * Save versus breath weapons
     */
    int breath;
    
    /**
     * Save versus paralyzation/poison/death magic
     */
    int paralyze_poison_death;
    
    /**
     * Save versus petrification/polymorph
     */
    int petrification_polymorph;
    
    /**
     * Save versus rods/staffs/wands
     */
    int rod_staff_wand;
    
    /**
     * Save versus spells
     */
    int spell;
    
    
    
    /**
     * Construction
     */
    SavingThrows();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SavingThrows(const SavingThrows& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SavingThrows(SavingThrows& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    SavingThrows(SavingThrows&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~SavingThrows();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SavingThrows& operator =(const SavingThrows& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SavingThrows& operator =(SavingThrows& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual SavingThrows& operator =(SavingThrows&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const SavingThrows& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const SavingThrows& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(SavingThrows& self, const SavingThrows& original);
    
    
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
  class hash<tbrpg::SavingThrows>
  {
  public:
    size_t operator()(const tbrpg::SavingThrows& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_SAVINGTHROWS_HPP__

