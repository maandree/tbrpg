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
#include "AbilityChart.hpp"


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
  AbilityChart::AbilityChart() : Object()
  {
    this->class_inheritance.push_back(22);
    
    this->strength     = new AbilityBonus[26];
    this->strength18   = new AbilityBonus[101];
    this->dexterity    = new AbilityBonus[26];
    this->constitution = new AbilityBonus[26];
    this->intelligence = new AbilityBonus[26];
    this->wisdom       = new AbilityBonus[26];
    this->charisma     = new AbilityBonus[26];
    
    for (int i = 0; i <= 25; i++)
      {
	this->strength[i]     = AbilityBonus();
	this->dexterity[i]    = AbilityBonus();
	this->constitution[i] = AbilityBonus();
	this->intelligence[i] = AbilityBonus();
	this->wisdom[i]       = AbilityBonus();
	this->charisma[i]     = AbilityBonus();
      }
    for (int i = 0; i <= 100; i++)
      this->strength18[i] = AbilityBonus();
    
    this->strength[1].bonuses.hit_bonus = -5;
    this->strength[2].bonuses.hit_bonus = -5;
    this->strength[3].bonuses.hit_bonus = -3;
    this->strength[4].bonuses.hit_bonus = -2;
    this->strength[5].bonuses.hit_bonus = -2;
    this->strength[6].bonuses.hit_bonus = -1;
    this->strength[7].bonuses.hit_bonus = -1;
    this->strength[17].bonuses.hit_bonus = 1;
    this->strength[18].bonuses.hit_bonus = 1;
    for (int i = 0; i <= 50; i++)
      this->strength18[i].bonuses.hit_bonus = 1;
    for (int i = 51; i <= 99; i++)
      this->strength18[i].bonuses.hit_bonus = 2;
    this->strength18[100].bonuses.hit_bonus = 3;
    this->strength[19].bonuses.hit_bonus = 3;
    this->strength[20].bonuses.hit_bonus = 3;
    this->strength[21].bonuses.hit_bonus = 4;
    this->strength[22].bonuses.hit_bonus = 4;
    this->strength[23].bonuses.hit_bonus = 5;
    this->strength[24].bonuses.hit_bonus = 6;
    this->strength[25].bonuses.hit_bonus = 7;
    
    this->strength[1].bonuses.damage_bonus = -2;
    this->strength[2].bonuses.damage_bonus = -2;
    this->strength[3].bonuses.damage_bonus = -1;
    this->strength[4].bonuses.damage_bonus = -1;
    this->strength[5].bonuses.damage_bonus = -1;
    this->strength[16].bonuses.damage_bonus = 1;
    this->strength[17].bonuses.damage_bonus = 1;
    this->strength[18].bonuses.damage_bonus = 2;
    this->strength18[0].bonuses.hit_bonus = 2;
    for (int i = 1; i <= 75; i++)
      this->strength18[i].bonuses.hit_bonus = 3;
    for (int i = 76; i <= 90; i++)
      this->strength18[i].bonuses.hit_bonus = 4;
    for (int i = 91; i <= 99; i++)
      this->strength18[i].bonuses.hit_bonus = 5;
    this->strength18[100].bonuses.hit_bonus = 6;
    this->strength[19].bonuses.damage_bonus = 7;
    this->strength[20].bonuses.damage_bonus = 8;
    this->strength[21].bonuses.damage_bonus = 9;
    this->strength[22].bonuses.damage_bonus = 10;
    this->strength[23].bonuses.damage_bonus = 11;
    this->strength[24].bonuses.damage_bonus = 12;
    this->strength[25].bonuses.damage_bonus = 14;
    
    this->strength[1].bonuses.carry_limit = 1750;
    this->strength[2].bonuses.carry_limit = 2000;
    this->strength[3].bonuses.carry_limit = 2250;
    this->strength[4].bonuses.carry_limit = 6750;
    this->strength[5].bonuses.carry_limit = 6750;
    this->strength[6].bonuses.carry_limit = 13500;
    this->strength[7].bonuses.carry_limit = 13500;
    this->strength[8].bonuses.carry_limit = 22500;
    this->strength[9].bonuses.carry_limit = 22500;
    this->strength[10].bonuses.carry_limit = 31500;
    this->strength[11].bonuses.carry_limit = 31500;
    this->strength[12].bonuses.carry_limit = 40500;
    this->strength[13].bonuses.carry_limit = 40500;
    this->strength[14].bonuses.carry_limit = 45000;
    this->strength[15].bonuses.carry_limit = 45000;
    this->strength[16].bonuses.carry_limit = 67500;
    this->strength[17].bonuses.carry_limit = 67500;
    this->strength[18].bonuses.carry_limit = 90000;
    for (int i = 1; i <= 50; i++)
      this->strength18[i].bonuses.carry_limit = 99000;
    for (int i = 51; i <= 75; i++)
      this->strength18[i].bonuses.carry_limit = 112500;
    for (int i = 76; i <= 90; i++)
      this->strength18[i].bonuses.carry_limit = 126000;
    for (int i = 91; i <= 99; i++)
      this->strength18[i].bonuses.carry_limit = 144000;
    this->strength18[100].bonuses.carry_limit = 180000;
    this->strength[19].bonuses.carry_limit = 225000;
    this->strength[20].bonuses.carry_limit = 270000;
    this->strength[21].bonuses.carry_limit = 315000;
    this->strength[22].bonuses.carry_limit = 360000;
    this->strength[23].bonuses.carry_limit = 450000;
    this->strength[24].bonuses.carry_limit = 540000;
    this->strength[25].bonuses.carry_limit = 720000;
    
    this->strength[1].bonuses.bashing = 0.00;
    this->strength[2].bonuses.bashing = 0.01;
    this->strength[3].bonuses.bashing = 0.03;
    this->strength[4].bonuses.bashing = 0.04;
    this->strength[5].bonuses.bashing = 0.04;
    this->strength[6].bonuses.bashing = 0.06;
    this->strength[7].bonuses.bashing = 0.06;
    this->strength[8].bonuses.bashing = 0.08;
    this->strength[9].bonuses.bashing = 0.08;
    this->strength[10].bonuses.bashing = 0.10;
    this->strength[11].bonuses.bashing = 0.10;
    this->strength[12].bonuses.bashing = 0.12;
    this->strength[13].bonuses.bashing = 0.12;
    this->strength[14].bonuses.bashing = 0.14;
    this->strength[15].bonuses.bashing = 0.14;
    this->strength[16].bonuses.bashing = 0.16;
    this->strength[17].bonuses.bashing = 0.18;
    this->strength[18].bonuses.bashing = 0.20;
    for (int i = 1; i <= 50; i++)
      this->strength18[i].bonuses.bashing = 0.25;
    for (int i = 51; i <= 75; i++)
      this->strength18[i].bonuses.bashing = 0.30;
    for (int i = 76; i <= 90; i++)
      this->strength18[i].bonuses.bashing = 0.35;
    for (int i = 91; i <= 99; i++)
      this->strength18[i].bonuses.bashing = 0.40;
    this->strength18[100].bonuses.bashing = 0.45;
    this->strength[19].bonuses.bashing = 0.50;
    this->strength[20].bonuses.bashing = 0.55;
    this->strength[21].bonuses.bashing = 0.60;
    this->strength[22].bonuses.bashing = 0.65;
    this->strength[23].bonuses.bashing = 0.70;
    this->strength[24].bonuses.bashing = 0.75;
    this->strength[25].bonuses.bashing = 0.80;
    
    this->dexterity[1].bonuses.missile_attack_bonus = -3;
    this->dexterity[2].bonuses.missile_attack_bonus = -2;
    this->dexterity[3].bonuses.missile_attack_bonus = -1;
    this->dexterity[16].bonuses.missile_attack_bonus = 1;
    this->dexterity[17].bonuses.missile_attack_bonus = 2;
    this->dexterity[18].bonuses.missile_attack_bonus = 2;
    this->dexterity[19].bonuses.missile_attack_bonus = 3;
    this->dexterity[20].bonuses.missile_attack_bonus = 3;
    this->dexterity[21].bonuses.missile_attack_bonus = 4;
    this->dexterity[22].bonuses.missile_attack_bonus = 4;
    this->dexterity[23].bonuses.missile_attack_bonus = 4;
    this->dexterity[24].bonuses.missile_attack_bonus = 5;
    this->dexterity[25].bonuses.missile_attack_bonus = 5;
    
    this->dexterity[1].bonuses.armour_class_bonus = 6;
    this->dexterity[2].bonuses.armour_class_bonus = 5;
    this->dexterity[3].bonuses.armour_class_bonus = 4;
    this->dexterity[4].bonuses.armour_class_bonus = 3;
    this->dexterity[5].bonuses.armour_class_bonus = 2;
    this->dexterity[6].bonuses.armour_class_bonus = 1;
    this->dexterity[15].bonuses.armour_class_bonus = -1;
    this->dexterity[16].bonuses.armour_class_bonus = -2;
    this->dexterity[17].bonuses.armour_class_bonus = -3;
    this->dexterity[18].bonuses.armour_class_bonus = -4;
    this->dexterity[19].bonuses.armour_class_bonus = -4;
    this->dexterity[20].bonuses.armour_class_bonus = -4;
    this->dexterity[21].bonuses.armour_class_bonus = -5;
    this->dexterity[22].bonuses.armour_class_bonus = -5;
    this->dexterity[23].bonuses.armour_class_bonus = -5;
    this->dexterity[24].bonuses.armour_class_bonus = -6;
    this->dexterity[25].bonuses.armour_class_bonus = -6;
    
    this->constitution[1].bonuses.hit_point_bonus = -2;
    this->constitution[2].bonuses.hit_point_bonus = -1;
    this->constitution[3].bonuses.hit_point_bonus = -1;
    this->constitution[4].bonuses.hit_point_bonus = -1;
    this->constitution[15].bonuses.hit_point_bonus = 1;
    this->constitution[16].bonuses.hit_point_bonus = 2;
    this->constitution[17].bonuses.hit_point_bonus = 3;
    this->constitution[18].bonuses.hit_point_bonus = 4;
    this->constitution[19].bonuses.hit_point_bonus = 5;
    this->constitution[20].bonuses.hit_point_bonus = 5;
    this->constitution[21].bonuses.hit_point_bonus = 6;
    this->constitution[22].bonuses.hit_point_bonus = 6;
    this->constitution[23].bonuses.hit_point_bonus = 6;
    this->constitution[24].bonuses.hit_point_bonus = 7;
    this->constitution[25].bonuses.hit_point_bonus = 7;
    
    for (int i = 1; i <= 11; i++)
      this->constitution[i].bonuses.resurrectability = 0.35 + 0.05 * i;
    for (int i = 12; i <= 15; i++)
      this->constitution[i].bonuses.resurrectability = 0.90 + 0.02 * (i - 11);
    for (int i = 16; i <= 25; i++)
      this->constitution[i].bonuses.resurrectability = 1.00;
    
    for (int i = 1; i <= 25; i++)
      {
	this->intelligence[i].bonuses.spell_level_limit = i >= 18 ? 9 : (i >> 1);
	this->intelligence[i].bonuses.spell_learn = i > 18
	                                          ? ((i - 19 + 95) / 100.)
	                                          : (0.05 * (i - 2));
      }
    this->intelligence[1].bonuses.spell_learn = 0.00;
    this->intelligence[2].bonuses.spell_learn = 0.01;
    this->intelligence[18].bonuses.spell_learn = 0.85;
    this->intelligence[25].bonuses.spell_learn = 1.00;
    
    this->intelligence[3].bonuses.max_spells_level = 1;
    this->intelligence[4].bonuses.max_spells_level = 1;
    this->intelligence[5].bonuses.max_spells_level = 2;
    this->intelligence[6].bonuses.max_spells_level = 2;
    this->intelligence[7].bonuses.max_spells_level = 4;
    this->intelligence[8].bonuses.max_spells_level = 4;
    this->intelligence[9].bonuses.max_spells_level = 6;
    this->intelligence[10].bonuses.max_spells_level = 7;
    this->intelligence[11].bonuses.max_spells_level = 7;
    this->intelligence[12].bonuses.max_spells_level = 7;
    this->intelligence[13].bonuses.max_spells_level = 9;
    this->intelligence[14].bonuses.max_spells_level = 9;
    this->intelligence[15].bonuses.max_spells_level = 11;
    this->intelligence[16].bonuses.max_spells_level = 11;
    this->intelligence[17].bonuses.max_spells_level = 14;
    this->intelligence[18].bonuses.max_spells_level = 17;
    for (int i = 1; i <= 25; i++)
      this->intelligence[i].bonuses.max_spells_level = -1;
    
    this->intelligence[1].bonuses.lore_bonus = -30;
    this->intelligence[2].bonuses.lore_bonus = -30;
    this->intelligence[3].bonuses.lore_bonus = -20;
    this->intelligence[4].bonuses.lore_bonus = -20;
    this->intelligence[5].bonuses.lore_bonus = -20;
    this->intelligence[6].bonuses.lore_bonus = -20;
    this->intelligence[7].bonuses.lore_bonus = -10;
    this->intelligence[8].bonuses.lore_bonus = -10;
    this->intelligence[9].bonuses.lore_bonus = -10;
    this->intelligence[15].bonuses.lore_bonus = 3;
    this->intelligence[16].bonuses.lore_bonus = 5;
    this->intelligence[17].bonuses.lore_bonus = 7;
    this->intelligence[18].bonuses.lore_bonus = 10;
    this->intelligence[19].bonuses.lore_bonus = 12;
    for (int i = 20; i <= 25; i++)
      this->intelligence[i].bonuses.lore_bonus = 15 + (i - 20) * 5;
    
    for (int i = 1; i <= 5; i++)
      this->wisdom[i].bonuses.magic_defence_bonus = -6 + i;
    this->wisdom[6].bonuses.magic_defence_bonus = -1;
    this->wisdom[7].bonuses.magic_defence_bonus = -1;
    for (int i = 15; i <= 25; i++)
      this->wisdom[i].bonuses.magic_defence_bonus = i > 18 ? 4 : (i - 14);
    
    for (int i = 1; i <= 12; i++)
      this->wisdom[i].bonuses.spell_failure = (65 - i * 5) / 100.;
    
    this->wisdom[1].bonuses.lore_bonus = -30;
    this->wisdom[2].bonuses.lore_bonus = -30;
    this->wisdom[3].bonuses.lore_bonus = -20;
    this->wisdom[4].bonuses.lore_bonus = -20;
    this->wisdom[5].bonuses.lore_bonus = -20;
    this->wisdom[6].bonuses.lore_bonus = -20;
    this->wisdom[7].bonuses.lore_bonus = -10;
    this->wisdom[8].bonuses.lore_bonus = -10;
    this->wisdom[9].bonuses.lore_bonus = -10;
    this->wisdom[15].bonuses.lore_bonus = 3;
    this->wisdom[16].bonuses.lore_bonus = 5;
    this->wisdom[17].bonuses.lore_bonus = 7;
    this->wisdom[18].bonuses.lore_bonus = 10;
    this->wisdom[19].bonuses.lore_bonus = 12;
    for (int i = 20; i <= 25; i++)
      this->wisdom[i].bonuses.lore_bonus = 15 + (i - 20) * 5;
    
    this->wisdom[13].bonuses.bonus_spells = {0, 1};
    this->wisdom[14].bonuses.bonus_spells = {0, 2};
    this->wisdom[15].bonuses.bonus_spells = {0, 2, 1};
    this->wisdom[16].bonuses.bonus_spells = {0, 2, 2};
    this->wisdom[17].bonuses.bonus_spells = {0, 2, 2, 1};
    this->wisdom[18].bonuses.bonus_spells = {0, 2, 2, 1, 1};
    this->wisdom[19].bonuses.bonus_spells = {0, 3, 2, 1, 2};
    this->wisdom[20].bonuses.bonus_spells = {0, 3, 3, 1, 2};
    this->wisdom[21].bonuses.bonus_spells = {0, 3, 3, 2, 2, 1};
    this->wisdom[22].bonuses.bonus_spells = {0, 3, 3, 2, 3, 2};
    this->wisdom[23].bonuses.bonus_spells = {0, 3, 3, 2, 3, 4};
    this->wisdom[24].bonuses.bonus_spells = {0, 3, 3, 2, 3, 4, 2};
    this->wisdom[25].bonuses.bonus_spells = {0, 3, 3, 2, 3, 4, 3, 1};
    
    for (int i = 1; i <= 7; i++)
      this->charisma[i].bonuses.reaction_bonus = -8 + i;
    this->charisma[13].bonuses.reaction_bonus = 1;
    this->charisma[14].bonuses.reaction_bonus = 2;
    this->charisma[15].bonuses.reaction_bonus = 3;
    this->charisma[16].bonuses.reaction_bonus = 4;
    this->charisma[17].bonuses.reaction_bonus = 4;
    this->charisma[18].bonuses.reaction_bonus = 5;
    for (int i = 19; i <= 25; i++)
      this->charisma[i].bonuses.reaction_bonus = i - 11;
    
    for (int i = 1; i <= 9; i++)
      this->dexterity[i].thief_abilities.find_traps = -30 + 5 * (i >> 1);
    this->dexterity[10].thief_abilities.find_traps = -10;
    this->dexterity[11].thief_abilities.find_traps = -5;
    for (int i = 18; i <= 25; i++)
      this->dexterity[i].thief_abilities.find_traps = 5 * (i - 17);
    
    for (int i = 1; i <= 10; i++)
      this->dexterity[i].thief_abilities.open_locks = -30 + 5 * (i >> 1);
    for (int i = 16; i <= 25; i++)
      this->dexterity[i].thief_abilities.open_locks = 5 * (i - 15);
    
    for (int i = 1; i <= 10; i++)
      this->dexterity[i].thief_abilities.pick_pockets = -35 + 5 * (i >> 1);
    this->dexterity[11].thief_abilities.pick_pockets = -5;
    for (int i = 1; i <= 25; i++)
      this->dexterity[i].thief_abilities.pick_pockets = 5 * (i - 16);
    
    for (int i = 1; i <= 10; i++)
      this->dexterity[i].thief_abilities.stealth = -40 + 5 * (i >> 1);
    this->dexterity[11].thief_abilities.stealth = -10;
    this->dexterity[12].thief_abilities.stealth = -5;
    this->dexterity[17].thief_abilities.stealth = 5;
    this->dexterity[18].thief_abilities.stealth = 10;
    this->dexterity[19].thief_abilities.stealth = 15;
    this->dexterity[20].thief_abilities.stealth = 18;
    this->dexterity[21].thief_abilities.stealth = 20;
    this->dexterity[22].thief_abilities.stealth = 23;
    this->dexterity[23].thief_abilities.stealth = 25;
    this->dexterity[24].thief_abilities.stealth = 30;
    this->dexterity[25].thief_abilities.stealth = 35;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(const AbilityChart& original) : Object(original)
  {
    (void) original;
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart& original) : Object(original)
  {
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart&& original) : Object(original)
  {
    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->constitution, original.constitution);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityChart::~AbilityChart()
  {
    delete[] this->strength;
    delete[] this->strength18;
    delete[] this->dexterity;
    delete[] this->constitution;
    delete[] this->intelligence;
    delete[] this->wisdom;
    delete[] this->charisma;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(const AbilityChart& original)
  {
    delete[] this->strength;
    delete[] this->strength18;
    delete[] this->dexterity;
    delete[] this->constitution;
    delete[] this->intelligence;
    delete[] this->wisdom;
    delete[] this->charisma;
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(AbilityChart& original)
  {
    delete[] this->strength;
    delete[] this->strength18;
    delete[] this->dexterity;
    delete[] this->constitution;
    delete[] this->intelligence;
    delete[] this->wisdom;
    delete[] this->charisma;
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->dexterity = original.dexterity;
    this->constitution = original.constitution;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(AbilityChart&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->constitution, original.constitution);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool AbilityChart::operator ==(const AbilityChart& other) const
  {
    if (this->strength != other.strength)  return false;
    if (this->strength18 != other.strength18)  return false;
    if (this->dexterity != other.dexterity)  return false;
    if (this->constitution != other.constitution)  return false;
    if (this->intelligence != other.intelligence)  return false;
    if (this->wisdom != other.wisdom)  return false;
    if (this->charisma != other.charisma)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool AbilityChart::operator !=(const AbilityChart& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void AbilityChart::__copy__(AbilityChart& self, const AbilityChart& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t AbilityChart::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<AbilityBonus*>()(strength);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<AbilityBonus*>()(strength18);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<AbilityBonus*>()(dexterity);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<AbilityBonus*>()(constitution);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<AbilityBonus*>()(intelligence);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<AbilityBonus*>()(wisdom);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<AbilityBonus*>()(charisma);
    return rc;
  }
  
}

