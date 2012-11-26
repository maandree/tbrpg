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
#include "Defence.hpp"


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
  Defence::Defence()
  {
    //TODO implement constructor
    //hit_bonus = nullptr;
    //damage_bonus = nullptr;
    //carry_limit = nullptr;
    //bashing = nullptr;
    //missile_attack_bonus = nullptr;
    //armour_class_bonus = nullptr;
    //hit_point_bonus = nullptr;
    //resurrectability = nullptr;
    //reaction_bonus = nullptr;
    //spell_level_limit = nullptr;
    //spell_learn = nullptr;
    //max_spells_level = nullptr;
    //lore_bonus = nullptr;
    //magic_defence_bonus = nullptr;
    //spell_failure = nullptr;
    //bonus_spells = nullptr;
    //morale = nullptr;
    //luck = nullptr;
    //detect_doors = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(const Defence& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_bonus = original.damage_bonus;
    this->carry_limit = original.carry_limit;
    this->bashing = original.bashing;
    this->missile_attack_bonus = original.missile_attack_bonus;
    this->armour_class_bonus = original.armour_class_bonus;
    this->hit_point_bonus = original.hit_point_bonus;
    this->resurrectability = original.resurrectability;
    this->reaction_bonus = original.reaction_bonus;
    this->spell_level_limit = original.spell_level_limit;
    this->spell_learn = original.spell_learn;
    this->max_spells_level = original.max_spells_level;
    this->lore_bonus = original.lore_bonus;
    this->magic_defence_bonus = original.magic_defence_bonus;
    this->spell_failure = original.spell_failure;
    this->bonus_spells = original.bonus_spells;
    this->morale = original.morale;
    this->luck = original.luck;
    this->detect_doors = original.detect_doors;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(Defence& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_bonus = original.damage_bonus;
    this->carry_limit = original.carry_limit;
    this->bashing = original.bashing;
    this->missile_attack_bonus = original.missile_attack_bonus;
    this->armour_class_bonus = original.armour_class_bonus;
    this->hit_point_bonus = original.hit_point_bonus;
    this->resurrectability = original.resurrectability;
    this->reaction_bonus = original.reaction_bonus;
    this->spell_level_limit = original.spell_level_limit;
    this->spell_learn = original.spell_learn;
    this->max_spells_level = original.max_spells_level;
    this->lore_bonus = original.lore_bonus;
    this->magic_defence_bonus = original.magic_defence_bonus;
    this->spell_failure = original.spell_failure;
    this->bonus_spells = original.bonus_spells;
    this->morale = original.morale;
    this->luck = original.luck;
    this->detect_doors = original.detect_doors;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(Defence&& original)
  {
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_bonus, original.damage_bonus);
    std::move(this->carry_limit, original.carry_limit);
    std::move(this->bashing, original.bashing);
    std::move(this->missile_attack_bonus, original.missile_attack_bonus);
    std::move(this->armour_class_bonus, original.armour_class_bonus);
    std::move(this->hit_point_bonus, original.hit_point_bonus);
    std::move(this->resurrectability, original.resurrectability);
    std::move(this->reaction_bonus, original.reaction_bonus);
    std::move(this->spell_level_limit, original.spell_level_limit);
    std::move(this->spell_learn, original.spell_learn);
    std::move(this->max_spells_level, original.max_spells_level);
    std::move(this->lore_bonus, original.lore_bonus);
    std::move(this->magic_defence_bonus, original.magic_defence_bonus);
    std::move(this->spell_failure, original.spell_failure);
    std::move(this->bonus_spells, original.bonus_spells);
    std::move(this->morale, original.morale);
    std::move(this->luck, original.luck);
    std::move(this->detect_doors, original.detect_doors);
  }
  
  
  
  /**
   * Destructor
   */
  Defence::~Defence()
  {
    //TODO implement destructor
    //delete hit_bonus;
    //delete damage_bonus;
    //delete carry_limit;
    //delete bashing;
    //delete missile_attack_bonus;
    //delete armour_class_bonus;
    //delete hit_point_bonus;
    //delete resurrectability;
    //delete reaction_bonus;
    //delete spell_level_limit;
    //delete spell_learn;
    //delete max_spells_level;
    //delete lore_bonus;
    //delete magic_defence_bonus;
    //delete spell_failure;
    //delete bonus_spells;
    //delete morale;
    //delete luck;
    //delete detect_doors;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Defence& Defence::operator =(const Defence& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_bonus = original.damage_bonus;
    this->carry_limit = original.carry_limit;
    this->bashing = original.bashing;
    this->missile_attack_bonus = original.missile_attack_bonus;
    this->armour_class_bonus = original.armour_class_bonus;
    this->hit_point_bonus = original.hit_point_bonus;
    this->resurrectability = original.resurrectability;
    this->reaction_bonus = original.reaction_bonus;
    this->spell_level_limit = original.spell_level_limit;
    this->spell_learn = original.spell_learn;
    this->max_spells_level = original.max_spells_level;
    this->lore_bonus = original.lore_bonus;
    this->magic_defence_bonus = original.magic_defence_bonus;
    this->spell_failure = original.spell_failure;
    this->bonus_spells = original.bonus_spells;
    this->morale = original.morale;
    this->luck = original.luck;
    this->detect_doors = original.detect_doors;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Defence& Defence::operator =(Defence& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->damage_bonus = original.damage_bonus;
    this->carry_limit = original.carry_limit;
    this->bashing = original.bashing;
    this->missile_attack_bonus = original.missile_attack_bonus;
    this->armour_class_bonus = original.armour_class_bonus;
    this->hit_point_bonus = original.hit_point_bonus;
    this->resurrectability = original.resurrectability;
    this->reaction_bonus = original.reaction_bonus;
    this->spell_level_limit = original.spell_level_limit;
    this->spell_learn = original.spell_learn;
    this->max_spells_level = original.max_spells_level;
    this->lore_bonus = original.lore_bonus;
    this->magic_defence_bonus = original.magic_defence_bonus;
    this->spell_failure = original.spell_failure;
    this->bonus_spells = original.bonus_spells;
    this->morale = original.morale;
    this->luck = original.luck;
    this->detect_doors = original.detect_doors;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Defence& Defence::operator =(Defence&& original)
  {
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->damage_bonus, original.damage_bonus);
    std::move(this->carry_limit, original.carry_limit);
    std::move(this->bashing, original.bashing);
    std::move(this->missile_attack_bonus, original.missile_attack_bonus);
    std::move(this->armour_class_bonus, original.armour_class_bonus);
    std::move(this->hit_point_bonus, original.hit_point_bonus);
    std::move(this->resurrectability, original.resurrectability);
    std::move(this->reaction_bonus, original.reaction_bonus);
    std::move(this->spell_level_limit, original.spell_level_limit);
    std::move(this->spell_learn, original.spell_learn);
    std::move(this->max_spells_level, original.max_spells_level);
    std::move(this->lore_bonus, original.lore_bonus);
    std::move(this->magic_defence_bonus, original.magic_defence_bonus);
    std::move(this->spell_failure, original.spell_failure);
    std::move(this->bonus_spells, original.bonus_spells);
    std::move(this->morale, original.morale);
    std::move(this->luck, original.luck);
    std::move(this->detect_doors, original.detect_doors);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Defence::__copy__(Defence& self, const Defence& original);
  {
    left = right;
  }
  
}

