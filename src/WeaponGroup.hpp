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
#ifndef __GUARD_WEAPONGROUP_HPP__
#define __GUARD_WEAPONGROUP_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"


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
   * Weapon group
   */
  class WeaponGroup: public Object
  {
  public:
    /**
     * The name of the weapon group
     */
    std::string name;
    
    
    
    /**
     * Construction
     * 
     * @param  weaponGroupName  The name of the weapon group
     */
    WeaponGroup(const std::string weaponGroupName = "");
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    WeaponGroup(const WeaponGroup& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    WeaponGroup(WeaponGroup& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    WeaponGroup(WeaponGroup&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~WeaponGroup();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual WeaponGroup& operator =(const WeaponGroup& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual WeaponGroup& operator =(WeaponGroup& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual WeaponGroup& operator =(WeaponGroup&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const WeaponGroup& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const WeaponGroup& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(WeaponGroup& self, const WeaponGroup& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
  
  
  /**
   * Bows
   */
  static const WeaponGroup BOW = WeaponGroup("bow");
  
  /**
   * Spiked weapons
   */
  static const WeaponGroup SPIKED_WEAPONS = WeaponGroup("spiked weapons");
  
  /**
   * Small swords
   */
  static const WeaponGroup SMALL_SWORDS = WeaponGroup("small swords");
  
  /**
   * Large swords
   */
  static const WeaponGroup LARGE_SWORDS = WeaponGroup("large swords");
  
  /**
   * Axe
   */
  static const WeaponGroup AXE = WeaponGroup("axe");
  
  /**
   * Blunt weapons
   */
  static const WeaponGroup BLUNT_WEAPONS = WeaponGroup("blunt weapons");
  
  /**
   * Missile weapons
   */
  static const WeaponGroup MISSILE_WEAPONS = WeaponGroup("missile weapons");
  
  /**
   * Pole-arm (pole weapons)
   */
  static const WeaponGroup POLEARM = WeaponGroup("pole-arm");
  
  
  /**
   * All weapon groups
   */
  static const std::vector<WeaponGroup> WEAPON_GROUPS = {BOW, SPIKED_WEAPONS, SMALL_SWORDS, LARGE_SWORDS,
							 AXE, BLUNT_WEAPONS, MISSILE_WEAPONS, POLEARM};
  
}

namespace std
{
  template<>
  class hash<tbrpg::WeaponGroup>
  {
  public:
    size_t operator()(const tbrpg::WeaponGroup& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_WEAPONGROUP_HPP__

