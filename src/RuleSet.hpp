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


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"



#include "hash.hpp"
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
  class RuleSet: public Object
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
     * Natural regenation when idle: hit points
     */
    int idle_healing;
    
    /**
     * Natural regenation when idle: turn interval
     */
    char idle_healing_turns;
    
    /**
     * Natural regenation when in combat: hit points
     */
    int combat_healing;
    
    /**
     * Natural regenation when in combat: turn interval
     */
    char combat_healing_turns;
    
    /**
     * Natural regenation when resting: hit points
     */
    int rest_healing;
    
    /**
     * Natural regenation when resting: turn interval
     */
    char rest_healing_turns;
    
    /**
     * THAC0 bonus when fighting racial enemy
     */
    int racial_enemy_bonus;
    
    /**
     * THAC0 penality when not fighting racial enemy
     */
    int racial_enemy_penality;
    
    /**
     * The maximum size of the party
     */
    char party_size;
    
    /**
     * The maximum size of the party when the game is starting
     */
    char party_start_size;
    
    /**
     * The number of points below zero (absolute value) at which a critical death reached
     */
    int critical_death;
    
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
    std::vector<Spell> spells;
    
    /**
     * Races in the game that new charactes can chooses
     */
    std::vector<Race> races;
    
    /**
     * Allowed racial enemies
     */
    std::vector<Race> racial_enemies;
    
    
    
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
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
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
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const RuleSet& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const RuleSet& other) const;
    
    
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
    virtual size_t hash() const;
    
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
      return dynamic_cast<RuleSet*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::RuleSet*>
  {
  public:
    size_t operator()(tbrpg::RuleSet* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<RuleSet*>(elem)->hash();
    }
  };
}


#endif//__GUARD_RULESET_HPP__

