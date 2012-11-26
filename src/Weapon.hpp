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
#ifndef __WEAPON__
#define __WEAPON__


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
   * Weapon item class
   */
  class Weapon: public  RightHandItem
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
    Weapon() : RightHandItem();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(const Weapon& original) : RightHandItem(original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(Weapon& original) : RightHandItem(original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Weapon(Weapon&& original) : RightHandItem(original);
    
    
    
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
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Weapon& self, const Weapon& original);
  
  };
}


#endif//__WEAPON__
