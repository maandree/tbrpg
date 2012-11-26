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
    //this->attack_roll_die = 0;
    //this->attack_roll_dice = 0;
    //this->critical_hit = 0;
    //this->critical_miss = 0;
    //this->reputation_chart = nullptr;
    //this->ability_chart = nullptr;
    //this->inventory_prototype = nullptr;
    //this->spells = nullptr;
    //this->races = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(const RuleSet& original)
  {
    (void) original;
    //this->attack_roll_die = original.attack_roll_die;
    //this->attack_roll_dice = original.attack_roll_dice;
    //this->critical_hit = original.critical_hit;
    //this->critical_miss = original.critical_miss;
    //this->reputation_chart = original.reputation_chart;
    //this->ability_chart = original.ability_chart;
    //this->inventory_prototype = original.inventory_prototype;
    //this->spells = original.spells;
    //this->races = original.races;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(RuleSet& original)
  {
    (void) original;
    //this->attack_roll_die = original.attack_roll_die;
    //this->attack_roll_dice = original.attack_roll_dice;
    //this->critical_hit = original.critical_hit;
    //this->critical_miss = original.critical_miss;
    //this->reputation_chart = original.reputation_chart;
    //this->ability_chart = original.ability_chart;
    //this->inventory_prototype = original.inventory_prototype;
    //this->spells = original.spells;
    //this->races = original.races;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  RuleSet::RuleSet(RuleSet&& original)
  {
    (void) original;
    ////std::swap(this->attack_roll_die, original.attack_roll_die);
    ////std::swap(this->attack_roll_dice, original.attack_roll_dice);
    ////std::swap(this->critical_hit, original.critical_hit);
    ////std::swap(this->critical_miss, original.critical_miss);
    ////std::move(this->reputation_chart, original.reputation_chart);
    ////std::move(this->ability_chart, original.ability_chart);
    ////std::move(this->inventory_prototype, original.inventory_prototype);
    ////std::move(this->spells, original.spells);
    ////std::move(this->races, original.races);
  }
  
  
  
  /**
   * Destructor
   */
  RuleSet::~RuleSet()
  {
    ////TODO implement destructor
    //delete reputation_chart;
    //delete ability_chart;
    //delete inventory_prototype;
    //delete spells;
    //delete races;
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
    //this->attack_roll_die = original.attack_roll_die;
    //this->attack_roll_dice = original.attack_roll_dice;
    //this->critical_hit = original.critical_hit;
    //this->critical_miss = original.critical_miss;
    //this->reputation_chart = original.reputation_chart;
    //this->ability_chart = original.ability_chart;
    //this->inventory_prototype = original.inventory_prototype;
    //this->spells = original.spells;
    //this->races = original.races;
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
    //this->attack_roll_die = original.attack_roll_die;
    //this->attack_roll_dice = original.attack_roll_dice;
    //this->critical_hit = original.critical_hit;
    //this->critical_miss = original.critical_miss;
    //this->reputation_chart = original.reputation_chart;
    //this->ability_chart = original.ability_chart;
    //this->inventory_prototype = original.inventory_prototype;
    //this->spells = original.spells;
    //this->races = original.races;
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
    ////std::swap(this->attack_roll_die, original.attack_roll_die);
    ////std::swap(this->attack_roll_dice, original.attack_roll_dice);
    ////std::swap(this->critical_hit, original.critical_hit);
    ////std::swap(this->critical_miss, original.critical_miss);
    ////std::move(this->reputation_chart, original.reputation_chart);
    ////std::move(this->ability_chart, original.ability_chart);
    ////std::move(this->inventory_prototype, original.inventory_prototype);
    ////std::move(this->spells, original.spells);
    ////std::move(this->races, original.races);
    return *this;
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

