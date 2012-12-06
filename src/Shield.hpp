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
#ifndef __GUARD_SHIELD_HPP__
#define __GUARD_SHIELD_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "RightHandItem.hpp"
#include "DamageType.hpp"


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
   * Shield item class
   */
  class Shield: public RightHandItem
  {
  public:
    /**
     * Whether the shield protects against missiles
     */
    bool protect_missile;
    
    /**
     * Whether the shield protects against different damage types in melée battle
     */
    std::unordered_map<DamageType, bool> protect_melee;
    
    
    
    /**
     * Construction
     */
    Shield();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Shield(const Shield& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Shield(Shield& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Shield(Shield&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Shield();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Shield& operator =(const Shield& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Shield& operator =(Shield& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Shield& operator =(Shield&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Shield& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Shield& self, const Shield& original);
    
    
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
  class hash<tbrpg::Shield>
  {
  public:
    size_t operator()(const tbrpg::Shield& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_SHIELD_HPP__

