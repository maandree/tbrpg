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
#ifndef __GUARD_AMMUNITION_HPP__
#define __GUARD_AMMUNITION_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Item.hpp"



#include "hash.hpp"
#include "RangedWeapon.hpp"
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
   * Ammunition item class
   */
  class Ammunition: public Item
  {
  public:
    /**
     * The hit bonus the ammunition brings
     */
    int hit_bonus;
    
    /**
     * The number of sides on the dice rolled to determine the inflicted damage
     */
    char damage_die;
    
    /**
     * The number dice rolled to determine the inflicted damage
     */
    char damage_dice;
    
    /**
     * Damage modifier
     */
    int damage_bonus;
    
    /**
     * Weapon that the ammunition can be used with
     */
    RangedWeapon usable_with;
    
    /**
     * The damage type inflicted by the ammunition
     */
    DamageType damage_type;
    
    
    
    /**
     * Construction
     */
    Ammunition();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Ammunition(const Ammunition& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Ammunition(Ammunition& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Ammunition(Ammunition&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Ammunition();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Ammunition& operator =(const Ammunition& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Ammunition& operator =(Ammunition& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Ammunition& operator =(Ammunition&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Ammunition& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Ammunition& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Ammunition& self, const Ammunition& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    virtual size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Ammunition>
  {
  public:
    size_t operator()(const tbrpg::Ammunition& elem) const
    {
      return dynamic_cast<const tbrpg::Ammunition*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::Ammunition*>
  {
  public:
    size_t operator()(tbrpg::Ammunition* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<tbrpg::Ammunition*>(elem)->hash();
    }
  };
}


#endif//__GUARD_AMMUNITION_HPP__

