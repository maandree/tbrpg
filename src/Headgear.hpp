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
#ifndef __HEADGEAR__
#define __HEADGEAR__


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
   * Headgear item class
   */
  class Headgear: public  Item
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
    DamageType[] damage_type;
    
    /**
     * The weapon group
     */
    WeaponGroup weapon_group;
    
    
    
    /**
     * Construction
     */
    Headgear() : Item();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Headgear(const Headgear& original) : Item(original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Headgear(Headgear& original) : Item(original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Headgear(Headgear&& original) : Item(original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Headgear();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Headgear& operator =(const Headgear& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Headgear& operator =(Headgear& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Headgear& operator =(Headgear&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Headgear& self, const Headgear& original);
  
  };
}


#endif//__HEADGEAR__
