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
#include "Bonuses.hpp"


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
  Bonuses::Bonuses()
  {
    ////TODO implement constructor
    //this->hit_bonus = 0;
    //this->damage_bonus = 0;
    //this->carry_limit = 0;
    //this->bashing = 0;
    //this->missile_attack_bonus = 0;
    //this->armour_class_bonus = 0;
    //this->hit_point_bonus = 0;
    //this->resurrectability = 0;
    //this->reaction_bonus = 0;
    //this->spell_level_limit = 0;
    //this->spell_learn = 0;
    //this->max_spells_level = 0;
    //this->lore_bonus = 0;
    //this->magic_defence_bonus = 0;
    //this->spell_failure = 0;
    //this->bonus_spells = nullptr;
    //this->morale = 0;
    //this->luck = 0;
    //this->detect_doors = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bonuses::Bonuses(const Bonuses& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->carry_limit = original.carry_limit;
    //this->bashing = original.bashing;
    //this->missile_attack_bonus = original.missile_attack_bonus;
    //this->armour_class_bonus = original.armour_class_bonus;
    //this->hit_point_bonus = original.hit_point_bonus;
    //this->resurrectability = original.resurrectability;
    //this->reaction_bonus = original.reaction_bonus;
    //this->spell_level_limit = original.spell_level_limit;
    //this->spell_learn = original.spell_learn;
    //this->max_spells_level = original.max_spells_level;
    //this->lore_bonus = original.lore_bonus;
    //this->magic_defence_bonus = original.magic_defence_bonus;
    //this->spell_failure = original.spell_failure;
    //this->bonus_spells = original.bonus_spells;
    //this->morale = original.morale;
    //this->luck = original.luck;
    //this->detect_doors = original.detect_doors;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bonuses::Bonuses(Bonuses& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->carry_limit = original.carry_limit;
    //this->bashing = original.bashing;
    //this->missile_attack_bonus = original.missile_attack_bonus;
    //this->armour_class_bonus = original.armour_class_bonus;
    //this->hit_point_bonus = original.hit_point_bonus;
    //this->resurrectability = original.resurrectability;
    //this->reaction_bonus = original.reaction_bonus;
    //this->spell_level_limit = original.spell_level_limit;
    //this->spell_learn = original.spell_learn;
    //this->max_spells_level = original.max_spells_level;
    //this->lore_bonus = original.lore_bonus;
    //this->magic_defence_bonus = original.magic_defence_bonus;
    //this->spell_failure = original.spell_failure;
    //this->bonus_spells = original.bonus_spells;
    //this->morale = original.morale;
    //this->luck = original.luck;
    //this->detect_doors = original.detect_doors;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Bonuses::Bonuses(Bonuses&& original)
  {
    (void) original;
    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::swap(this->carry_limit, original.carry_limit);
    ////std::swap(this->bashing, original.bashing);
    ////std::swap(this->missile_attack_bonus, original.missile_attack_bonus);
    ////std::swap(this->armour_class_bonus, original.armour_class_bonus);
    ////std::swap(this->hit_point_bonus, original.hit_point_bonus);
    ////std::swap(this->resurrectability, original.resurrectability);
    ////std::swap(this->reaction_bonus, original.reaction_bonus);
    ////std::swap(this->spell_level_limit, original.spell_level_limit);
    ////std::swap(this->spell_learn, original.spell_learn);
    ////std::swap(this->max_spells_level, original.max_spells_level);
    ////std::swap(this->lore_bonus, original.lore_bonus);
    ////std::swap(this->magic_defence_bonus, original.magic_defence_bonus);
    ////std::swap(this->spell_failure, original.spell_failure);
    ////std::move(this->bonus_spells, original.bonus_spells);
    ////std::swap(this->morale, original.morale);
    ////std::swap(this->luck, original.luck);
    ////std::swap(this->detect_doors, original.detect_doors);
  }
  
  
  
  /**
   * Destructor
   */
  Bonuses::~Bonuses()
  {
    ////TODO implement destructor
    //delete bonus_spells;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(const Bonuses& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->carry_limit = original.carry_limit;
    //this->bashing = original.bashing;
    //this->missile_attack_bonus = original.missile_attack_bonus;
    //this->armour_class_bonus = original.armour_class_bonus;
    //this->hit_point_bonus = original.hit_point_bonus;
    //this->resurrectability = original.resurrectability;
    //this->reaction_bonus = original.reaction_bonus;
    //this->spell_level_limit = original.spell_level_limit;
    //this->spell_learn = original.spell_learn;
    //this->max_spells_level = original.max_spells_level;
    //this->lore_bonus = original.lore_bonus;
    //this->magic_defence_bonus = original.magic_defence_bonus;
    //this->spell_failure = original.spell_failure;
    //this->bonus_spells = original.bonus_spells;
    //this->morale = original.morale;
    //this->luck = original.luck;
    //this->detect_doors = original.detect_doors;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(Bonuses& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->carry_limit = original.carry_limit;
    //this->bashing = original.bashing;
    //this->missile_attack_bonus = original.missile_attack_bonus;
    //this->armour_class_bonus = original.armour_class_bonus;
    //this->hit_point_bonus = original.hit_point_bonus;
    //this->resurrectability = original.resurrectability;
    //this->reaction_bonus = original.reaction_bonus;
    //this->spell_level_limit = original.spell_level_limit;
    //this->spell_learn = original.spell_learn;
    //this->max_spells_level = original.max_spells_level;
    //this->lore_bonus = original.lore_bonus;
    //this->magic_defence_bonus = original.magic_defence_bonus;
    //this->spell_failure = original.spell_failure;
    //this->bonus_spells = original.bonus_spells;
    //this->morale = original.morale;
    //this->luck = original.luck;
    //this->detect_doors = original.detect_doors;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(Bonuses&& original)
  {
    (void) original;
    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::swap(this->carry_limit, original.carry_limit);
    ////std::swap(this->bashing, original.bashing);
    ////std::swap(this->missile_attack_bonus, original.missile_attack_bonus);
    ////std::swap(this->armour_class_bonus, original.armour_class_bonus);
    ////std::swap(this->hit_point_bonus, original.hit_point_bonus);
    ////std::swap(this->resurrectability, original.resurrectability);
    ////std::swap(this->reaction_bonus, original.reaction_bonus);
    ////std::swap(this->spell_level_limit, original.spell_level_limit);
    ////std::swap(this->spell_learn, original.spell_learn);
    ////std::swap(this->max_spells_level, original.max_spells_level);
    ////std::swap(this->lore_bonus, original.lore_bonus);
    ////std::swap(this->magic_defence_bonus, original.magic_defence_bonus);
    ////std::swap(this->spell_failure, original.spell_failure);
    ////std::move(this->bonus_spells, original.bonus_spells);
    ////std::swap(this->morale, original.morale);
    ////std::swap(this->luck, original.luck);
    ////std::swap(this->detect_doors, original.detect_doors);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Bonuses::__copy__(Bonuses& self, const Bonuses& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Bonuses::hash() const
  {
    return (size_t)this;
  }
  
}

