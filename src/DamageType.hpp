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
#ifndef __GUARD_DAMAGETYPE_HPP__
#define __GUARD_DAMAGETYPE_HPP__


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
   * Damage type
   */
  class DamageType
  {
  public:
    /**
     * The name of the damage type
     */
    std::string name;
    
    
    
    /**
     * Construction
     * 
     * @param  damageTypeName The name of the damage type
     */
    DamageType(std::string damageTypeName = nullptr);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    DamageType(const DamageType& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    DamageType(DamageType& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    DamageType(DamageType&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~DamageType();
    
    
    
    virtual bool operator ==(const DamageType& other) const;
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual DamageType& operator =(const DamageType& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual DamageType& operator =(DamageType& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual DamageType& operator =(DamageType&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operation ==(const DamageType& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(DamageType& self, const DamageType& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
  
  
  
  /**
   * Damage type: slashing
   */
  static DamageType SLASHING = DamageType("slashing");
  
  /**
   * Damage type: piercing
   */
  static DamageType PIERCING = DamageType("piercing");
  
  /**
   * Damage type: bludgeoning
   */
  static DamageType BLUDGEONING = DamageType("bludgeoning");
    
}

namespace std
{
  template<>
  class hash<tbrpg::DamageType>
  {
  public:
    size_t operator()(const tbrpg::DamageType& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_DAMAGETYPE_HPP__
