// -*- mode: c++, coding: utf-8 -*-
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
#ifndef __GUARD_WEAPON_HPP__
#define __GUARD_WEAPON_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "RightHandItem.hpp"
#include "hash.hpp"
#include "DamageType.hpp"
#include "WeaponGroup.hpp"


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
   * Weapon item class
   */
  class Weapon: public RightHandItem
  {
  public:
    /**
     * The number of hands required for the weapon
     */
    char hands;
    
    /**
     * The weapon's speed factor
     */
    char speed_factor;
    
    /**
     * The hit bonus the weapon brings
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
     * Whether the weapon is a melée weapon
     */
    bool melee;
    
    /**
     * The damage type, if multiple, one fill be selected at uniform random for each attack
     */
    std::vector<DamageType> damage_type;
    
    /**
     * The weapon group
     */
    WeaponGroup* weapon_group;
    
    
    
    /**
     * Construction
     */
    Weapon();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(const Weapon& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(Weapon& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(Weapon&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Weapon();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Weapon& operator =(const Weapon& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Weapon& operator =(Weapon& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Weapon& operator =(Weapon&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Weapon& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Weapon& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Weapon& self, const Weapon& original);
    
    
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
  class hash<tbrpg::Weapon>
  {
  public:
    size_t operator()(const tbrpg::Weapon& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Weapon*>
  {
  public:
    size_t operator()(tbrpg::Weapon* elem) const
    {
       return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_WEAPON_HPP__

