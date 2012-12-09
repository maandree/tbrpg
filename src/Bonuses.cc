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
  Bonuses::Bonuses() : Object()
  {
    this->class_inheritance.push_back(3);
    this->hit_bonus = 0;
    this->damage_bonus = 0;
    this->carry_limit = 0;
    this->bashing = 0;
    this->missile_attack_bonus = 0;
    this->armour_class_bonus = 0;
    this->hit_point_bonus = 0;
    this->resurrectability = 0;
    this->reaction_bonus = 0;
    this->spell_level_limit = 0;
    this->spell_learn = 0;
    this->max_spells_level = 0;
    this->lore_bonus = 0;
    this->magic_defence_bonus = 0;
    this->spell_failure = 0;
    this->bonus_spells = {};
    this->morale = 0;
    this->luck = 0;
    this->detect_doors = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bonuses::Bonuses(const Bonuses& original) : Object(original)
  {
    (void) original;
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
  Bonuses::Bonuses(Bonuses& original) : Object(original)
  {
    (void) original;
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
  Bonuses::Bonuses(Bonuses&& original) : Object(original)
  {
    (void) original;
    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->carry_limit, original.carry_limit);
    std::swap(this->bashing, original.bashing);
    std::swap(this->missile_attack_bonus, original.missile_attack_bonus);
    std::swap(this->armour_class_bonus, original.armour_class_bonus);
    std::swap(this->hit_point_bonus, original.hit_point_bonus);
    std::swap(this->resurrectability, original.resurrectability);
    std::swap(this->reaction_bonus, original.reaction_bonus);
    std::swap(this->spell_level_limit, original.spell_level_limit);
    std::swap(this->spell_learn, original.spell_learn);
    std::swap(this->max_spells_level, original.max_spells_level);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->magic_defence_bonus, original.magic_defence_bonus);
    std::swap(this->spell_failure, original.spell_failure);
    std::swap(this->bonus_spells, original.bonus_spells);
    std::swap(this->morale, original.morale);
    std::swap(this->luck, original.luck);
    std::swap(this->detect_doors, original.detect_doors);
  }
  
  
  
  /**
   * Destructor
   */
  Bonuses::~Bonuses()
  {
    // do nothing
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
    Object::__copy__((Object&)*this, (Object&)original);    this->hit_bonus = original.hit_bonus;
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
  Bonuses& Bonuses::operator =(Bonuses& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->hit_bonus = original.hit_bonus;
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
  Bonuses& Bonuses::operator =(Bonuses&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->hit_bonus, original.hit_bonus);
    std::swap(this->damage_bonus, original.damage_bonus);
    std::swap(this->carry_limit, original.carry_limit);
    std::swap(this->bashing, original.bashing);
    std::swap(this->missile_attack_bonus, original.missile_attack_bonus);
    std::swap(this->armour_class_bonus, original.armour_class_bonus);
    std::swap(this->hit_point_bonus, original.hit_point_bonus);
    std::swap(this->resurrectability, original.resurrectability);
    std::swap(this->reaction_bonus, original.reaction_bonus);
    std::swap(this->spell_level_limit, original.spell_level_limit);
    std::swap(this->spell_learn, original.spell_learn);
    std::swap(this->max_spells_level, original.max_spells_level);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->magic_defence_bonus, original.magic_defence_bonus);
    std::swap(this->spell_failure, original.spell_failure);
    std::swap(this->bonus_spells, original.bonus_spells);
    std::swap(this->morale, original.morale);
    std::swap(this->luck, original.luck);
    std::swap(this->detect_doors, original.detect_doors);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Bonuses::operator ==(const Bonuses& other) const
  {
    if (this->hit_bonus != other.hit_bonus)  return false;
    if (this->damage_bonus != other.damage_bonus)  return false;
    if (this->carry_limit != other.carry_limit)  return false;
    if (this->bashing != other.bashing)  return false;
    if (this->missile_attack_bonus != other.missile_attack_bonus)  return false;
    if (this->armour_class_bonus != other.armour_class_bonus)  return false;
    if (this->hit_point_bonus != other.hit_point_bonus)  return false;
    if (this->resurrectability != other.resurrectability)  return false;
    if (this->reaction_bonus != other.reaction_bonus)  return false;
    if (this->spell_level_limit != other.spell_level_limit)  return false;
    if (this->spell_learn != other.spell_learn)  return false;
    if (this->max_spells_level != other.max_spells_level)  return false;
    if (this->lore_bonus != other.lore_bonus)  return false;
    if (this->magic_defence_bonus != other.magic_defence_bonus)  return false;
    if (this->spell_failure != other.spell_failure)  return false;
    if (this->bonus_spells != other.bonus_spells)  return false;
    if (this->morale != other.morale)  return false;
    if (this->luck != other.luck)  return false;
    if (this->detect_doors != other.detect_doors)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Bonuses::operator !=(const Bonuses& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->hit_bonus);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->damage_bonus);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->carry_limit);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<float>()(this->bashing);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<int>()(this->missile_attack_bonus);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<int>()(this->armour_class_bonus);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<int>()(this->hit_point_bonus);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<float>()(this->resurrectability);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->reaction_bonus);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<char>()(this->spell_level_limit);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<float>()(this->spell_learn);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<char>()(this->max_spells_level);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<int>()(this->lore_bonus);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<float>()(this->magic_defence_bonus);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<float>()(this->spell_failure);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<int>>()(this->bonus_spells);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->morale);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->luck);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<float>()(this->detect_doors);
    return rc;
  }
  
}

