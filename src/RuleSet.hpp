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
#ifndef __GUARD_RULESET_HPP__
#define __GUARD_RULESET_HPP__
#ifdef  CIRCULAR_RULESET
#include "RuleSet.circular"
#endif//CIRCULAR_RULESET


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "ReputationChart.hpp"
#include "AbilityChart.hpp"
#include "Inventory.hpp"
#include "Spell.hpp"
#include "Race.hpp"


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
   * Game rules
   */
  class RuleSet
  {
  public:
    /**
     * The number of sides on the dice to roll at the attack roll
     */
    char attack_roll_die;
    
    /**
     * The number of dice to roll at the attack roll
     */
    char attack_roll_dice;
    
    /**
     * The minimum attack roll needed for a critical hit
     */
    char critical_hit;
    
    /**
     * The maximum attack roll needed for a critical miss
     */
    char critical_miss;
    
    /**
     * The reputation chart
     */
    ReputationChart reputation_chart;
    
    /**
     * The ability chart
     */
    AbilityChart ability_chart;
    
    /**
     * The inventory prototype, basiclly it defines how many slots there is in the inventory
     */
    Inventory inventory_prototype;
    
    /**
     * All spells, very useful for when new characters selects spells, or to restrict imported characters
     */
    Spell* spells;
    
    /**
     * Races in the game that new charactes can chooses
     */
    Race* races;
    
    
    
    /**
     * Construction
     */
    RuleSet();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RuleSet(const RuleSet& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    RuleSet(RuleSet& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    RuleSet(RuleSet&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~RuleSet();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RuleSet& operator =(const RuleSet& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual RuleSet& operator =(RuleSet& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual RuleSet& operator =(RuleSet&& original);
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(RuleSet& self, const RuleSet& original);
    
    
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
  class hash<tbrpg::RuleSet>
  {
  public:
    size_t operator()(const tbrpg::RuleSet& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_RULESET_HPP__
