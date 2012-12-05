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
#include "RuleSet.hpp"


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
   * Constructor
   */
  RuleSet::RuleSet()
  {
    ////TODO implement constructor
    this->attack_roll_die = 20;
    this->attack_roll_dice = 1;
    this->critical_hit = 20;
    this->critical_miss = 1;
    this->idle_healing = 1;
    this->idle_healing_turns = 1;
    this->combat_healing = 0;
    this->combat_healing_turns = 1;
    this->rest_healing = 2;
    this->rest_healing_turns = 1;
    this->racial_enemy_bonus = 4;
    this->racial_enemy_penality = 4;
    //this->reputation_chart = nullptr;
    //this->ability_chart = nullptr;
    //this->inventory_prototype = nullptr;
    //this->spells = nullptr;
    //this->races = nullptr;
    
    ABJURATION.opposite = {ALTERATION};
    ALTERATION.opposite = {ABJURATION, NECROMANCY};
    CONJURATION.opposite = {DIVINATION};
    DIVINATION.opposite = {CONJURATION};
    ENCHANTMENT.opposite = {INVOCATION};
    ILLUSION.opposite = {NECROMANCY};
    INVOCATION.opposite = {ENCHANTMENT, CONJURATION};
    NECROMANCY.opposite = {ILLUSION};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(const RuleSet& original)
  {
    (void) original;
    this->attack_roll_die = original.attack_roll_die;
    this->attack_roll_dice = original.attack_roll_dice;
    this->critical_hit = original.critical_hit;
    this->critical_miss = original.critical_miss;
    this->idle_healing = original.idle_healing;
    this->idle_healing_turns = original.idle_healing_turns;
    this->combat_healing = original.combat_healing;
    this->combat_healing_turns = original.combat_healing_turns;
    this->rest_healing = original.rest_healing;
    this->rest_healing_turns = original.rest_healing_turns;
    this->racial_enemy_bonus = original.racial_enemy_bonus;
    this->racial_enemy_penality = original.racial_enemy_penality;
    this->reputation_chart = original.reputation_chart;
    this->ability_chart = original.ability_chart;
    this->inventory_prototype = original.inventory_prototype;
    this->spells = original.spells;
    this->races = original.races;
    this->racial_enemies = original.racial_enemies;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(RuleSet& original)
  {
    (void) original;
    this->attack_roll_die = original.attack_roll_die;
    this->attack_roll_dice = original.attack_roll_dice;
    this->critical_hit = original.critical_hit;
    this->critical_miss = original.critical_miss;
    this->idle_healing = original.idle_healing;
    this->idle_healing_turns = original.idle_healing_turns;
    this->combat_healing = original.combat_healing;
    this->combat_healing_turns = original.combat_healing_turns;
    this->rest_healing = original.rest_healing;
    this->rest_healing_turns = original.rest_healing_turns;
    this->racial_enemy_bonus = original.racial_enemy_bonus;
    this->racial_enemy_penality = original.racial_enemy_penality;
    this->reputation_chart = original.reputation_chart;
    this->ability_chart = original.ability_chart;
    this->inventory_prototype = original.inventory_prototype;
    this->spells = original.spells;
    this->races = original.races;
    this->racial_enemies = original.racial_enemies;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(RuleSet&& original)
  {
    (void) original;
    std::swap(this->attack_roll_die, original.attack_roll_die);
    std::swap(this->attack_roll_dice, original.attack_roll_dice);
    std::swap(this->critical_hit, original.critical_hit);
    std::swap(this->critical_miss, original.critical_miss);
    std::swap(this->idle_healing, original.idle_healing);
    std::swap(this->idle_healing_turns, original.idle_healing_turns);
    std::swap(this->combat_healing, original.combat_healing);
    std::swap(this->combat_healing_turns, original.combat_healing_turns);
    std::swap(this->rest_healing, original.rest_healing);
    std::swap(this->rest_healing_turns, original.rest_healing_turns);
    std::swap(this->racial_enemy_bonus, original.racial_enemy_bonus);
    std::swap(this->racial_enemy_penality, original.racial_enemy_penality);
    std::swap(this->reputation_chart, original.reputation_chart);
    std::swap(this->ability_chart, original.ability_chart);
    std::swap(this->inventory_prototype, original.inventory_prototype);
    std::swap(this->spells, original.spells);
    std::swap(this->races, original.races);
    std::swap(this->racial_enemies, original.racial_enemies);
  }
  
  
  
  /**
   * Destructor
   */
  RuleSet::~RuleSet()
  {
    ////TODO implement destructor
    //delete this->reputation_chart;
    //delete this->ability_chart;
    //delete this->inventory_prototype;
    //delete this->spells;
    //delete this->races;
    //delete this->racial_enemies;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RuleSet& RuleSet::operator =(const RuleSet& original)
  {
    (void) original;
    this->attack_roll_die = original.attack_roll_die;
    this->attack_roll_dice = original.attack_roll_dice;
    this->critical_hit = original.critical_hit;
    this->critical_miss = original.critical_miss;
    this->idle_healing = original.idle_healing;
    this->idle_healing_turns = original.idle_healing_turns;
    this->combat_healing = original.combat_healing;
    this->combat_healing_turns = original.combat_healing_turns;
    this->rest_healing = original.rest_healing;
    this->rest_healing_turns = original.rest_healing_turns;
    this->racial_enemy_bonus = original.racial_enemy_bonus;
    this->racial_enemy_penality = original.racial_enemy_penality;
    this->reputation_chart = original.reputation_chart;
    this->ability_chart = original.ability_chart;
    this->inventory_prototype = original.inventory_prototype;
    this->spells = original.spells;
    this->races = original.races;
    this->racial_enemies = original.racial_enemies;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  RuleSet& RuleSet::operator =(RuleSet& original)
  {
    (void) original;
    this->attack_roll_die = original.attack_roll_die;
    this->attack_roll_dice = original.attack_roll_dice;
    this->critical_hit = original.critical_hit;
    this->critical_miss = original.critical_miss;
    this->idle_healing = original.idle_healing;
    this->idle_healing_turns = original.idle_healing_turns;
    this->combat_healing = original.combat_healing;
    this->combat_healing_turns = original.combat_healing_turns;
    this->rest_healing = original.rest_healing;
    this->rest_healing_turns = original.rest_healing_turns;
    this->racial_enemy_bonus = original.racial_enemy_bonus;
    this->racial_enemy_penality = original.racial_enemy_penality;
    this->reputation_chart = original.reputation_chart;
    this->ability_chart = original.ability_chart;
    this->inventory_prototype = original.inventory_prototype;
    this->spells = original.spells;
    this->races = original.races;
    this->racial_enemies = original.racial_enemies;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  RuleSet& RuleSet::operator =(RuleSet&& original)
  {
    (void) original;
    std::swap(this->attack_roll_die, original.attack_roll_die);
    std::swap(this->attack_roll_dice, original.attack_roll_dice);
    std::swap(this->critical_hit, original.critical_hit);
    std::swap(this->critical_miss, original.critical_miss);
    std::swap(this->idle_healing, original.idle_healing);
    std::swap(this->idle_healing_turns, original.idle_healing_turns);
    std::swap(this->combat_healing, original.combat_healing);
    std::swap(this->combat_healing_turns, original.combat_healing_turns);
    std::swap(this->rest_healing, original.rest_healing);
    std::swap(this->rest_healing_turns, original.rest_healing_turns);
    std::swap(this->racial_enemy_bonus, original.racial_enemy_bonus);
    std::swap(this->racial_enemy_penality, original.racial_enemy_penality);
    std::swap(this->reputation_chart, original.reputation_chart);
    std::swap(this->ability_chart, original.ability_chart);
    std::swap(this->inventory_prototype, original.inventory_prototype);
    std::swap(this->spells, original.spells);
    std::swap(this->races, original.races);
    std::swap(this->racial_enemies, original.racial_enemies);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool RuleSet::operator ==(const RuleSet& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void RuleSet::__copy__(RuleSet& self, const RuleSet& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t RuleSet::hash() const
  {
    return (size_t)this;
  }
  
}

