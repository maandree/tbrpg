// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Class.hpp"


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
  Class::Class() : Object()
  {
    this->class_inheritance.push_back(19);
    this->name = "?";
    this->hit_points = 8;
    this->thac0 = 10;
    this->lore_bonus = 1;
    this->learn_from_scroll = false;
    this->proficiencies_each = 1;
    this->extra_strength = false;
    this->have_racial_enemy = false;
    
    this->abilities = AbilityBonus();
    this->abilities.thief_abilities.find_traps = -1;
    this->abilities.thief_abilities.open_locks = -1;
    this->abilities.thief_abilities.pick_pockets = -1;
    this->abilities.thief_abilities.stealth = -1;
    
    this->experience_chart = ExperienceChart();
    char backstabs;
    for (long i = 0; i <= 30; i++)
      {
	this->experience_chart.thief_abilities[i] = 0;
        backstabs = i >= 13 ? 5 : ((i + 7) >> 2);
	this->experience_chart.backstabs[i] = backstabs;
      }
    
    this->spell_progression = SpellProgression();
    
    this->alignments = (bool*)malloc(9);//bool[9];
    for (int i = 0; i < 9; i++)
      this->alignments[i] = true;
    
    this->can_use = std::unordered_map<Item*, bool>();
    this->can_use[&PROTOTYPE(Hood)] = true;/*
    this->can_use[&PROTOTYPE(Helmet)] = true;
    this->can_use[&PROTOTYPE(Buckler)] = true;
    this->can_use[&PROTOTYPE(SmallShield)] = true;
    this->can_use[&PROTOTYPE(LeatherArmour)] = true;
    this->can_use[&PROTOTYPE(StuddedLeatherArmour)] = true;
    this->can_use[&PROTOTYPE(Dart)] = true;
    this->can_use[&PROTOTYPE(Sling)] = true;
    this->can_use[&PROTOTYPE(ThrowingDagger)] = true;
    this->can_use[&PROTOTYPE(Fist)] = true;
    this->can_use[&PROTOTYPE(Fists)] = true;
    this->can_use[&PROTOTYPE(Bullet)] = true;
    this->can_use[&PROTOTYPE(Torch)] = true;
    this->can_use[&PROTOTYPE(Quarterstaff)] = true;
    this->can_use[&PROTOTYPE(Dagger)] = true;
    this->can_use[&PROTOTYPE(Club)] = true;
    this->can_use[&PROTOTYPE(Potion)] = true;
    this->can_use[&PROTOTYPE(LowScroll)] = true;
    this->can_use[&PROTOTYPE(LowWand)] = true;
    */
    this->lower_limits = Abilities();
    this->lower_limits.strength = 3;
    this->lower_limits.strength18 = 0;
    this->lower_limits.constitution = 3;
    this->lower_limits.dexterity = 3;
    this->lower_limits.intelligence = 3;
    this->lower_limits.wisdom = 3;
    this->lower_limits.charisma = 3;
    
    this->default_one_hand = PROTOTYPE(Fist);
    this->default_two_hands = PROTOTYPE(Fists);
    
    this->special_abilities = {};
    this->specialisations = {};
    
    this->proficiency_chart = std::unordered_map<WeaponGroup, std::vector<Proficiency>>();
    for (const WeaponGroup* weapongroup : WEAPON_GROUPS)
      this->proficiency_chart[*weapongroup] = {
	Proficiency(0, -1, 2), 
	Proficiency(0, 1, 2),
	Proficiency(1, 3, 3)
      };
    
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(const Class& original) : Object(original)
  {
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = (bool*)malloc(9);//new bool[9];
    for (int i = 0; i < 9; i++)
      this->alignments[i] = original.alignments[i];
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->extra_strength = original.extra_strength;
    this->have_racial_enemy = original.have_racial_enemy;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilities = original.special_abilities;
    this->can_use = original.can_use;
    this->specialisations = original.specialisations;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hands = original.default_two_hands;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(Class& original) : Object(original)
  {
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = (bool*)malloc(9);//new bool[9];
    for (int i = 0; i < 9; i++)
      this->alignments[i] = original.alignments[i];
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->extra_strength = original.extra_strength;
    this->have_racial_enemy = original.have_racial_enemy;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilities = original.special_abilities;
    this->can_use = original.can_use;
    this->specialisations = original.specialisations;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hands = original.default_two_hands;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(Class&& original) : Object(original)
  {
    std::swap(this->name, original.name);
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->thac0, original.thac0);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::swap(this->proficiencies_each, original.proficiencies_each);
    std::swap(this->extra_strength, original.extra_strength);
    std::swap(this->have_racial_enemy, original.have_racial_enemy);
    std::swap(this->experience_chart, original.experience_chart);
    std::swap(this->spell_progression, original.spell_progression);
    std::swap(this->abilities, original.abilities);
    std::swap(this->lower_limits, original.lower_limits);
    std::swap(this->special_abilities, original.special_abilities);
    std::swap(this->can_use, original.can_use);
    std::swap(this->specialisations, original.specialisations);
    std::swap(this->proficiency_chart, original.proficiency_chart);
    std::swap(this->default_one_hand, original.default_one_hand);
    std::swap(this->default_two_hands, original.default_two_hands);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Class::fork() const
  {
    return (Object*)(new Class(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Class::~Class()
  {
    free(this->alignments);//delete[] this->alignments;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Class& Class::operator =(const Class& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    for (int i = 0; i < 9; i++)
      this->alignments[i] = original.alignments[i];
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->extra_strength = original.extra_strength;
    this->have_racial_enemy = original.have_racial_enemy;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilities = original.special_abilities;
    this->can_use = original.can_use;
    this->specialisations = original.specialisations;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hands = original.default_two_hands;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Class& Class::operator =(Class& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    for (int i = 0; i < 9; i++)
      this->alignments[i] = original.alignments[i];
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->extra_strength = original.extra_strength;
    this->have_racial_enemy = original.have_racial_enemy;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilities = original.special_abilities;
    this->can_use = original.can_use;
    this->specialisations = original.specialisations;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hands = original.default_two_hands;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Class& Class::operator =(Class&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->name, original.name);
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->thac0, original.thac0);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::swap(this->proficiencies_each, original.proficiencies_each);
    std::swap(this->extra_strength, original.extra_strength);
    std::swap(this->have_racial_enemy, original.have_racial_enemy);
    std::swap(this->experience_chart, original.experience_chart);
    std::swap(this->spell_progression, original.spell_progression);
    std::swap(this->abilities, original.abilities);
    std::swap(this->lower_limits, original.lower_limits);
    std::swap(this->special_abilities, original.special_abilities);
    std::swap(this->can_use, original.can_use);
    std::swap(this->specialisations, original.specialisations);
    std::swap(this->proficiency_chart, original.proficiency_chart);
    std::swap(this->default_one_hand, original.default_one_hand);
    std::swap(this->default_two_hands, original.default_two_hands);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Class::operator ==(const Class& other) const
  {
    if (this->name != other.name)  return false;
    if (this->hit_points != other.hit_points)  return false;
    if (this->thac0 != other.thac0)  return false;
    if (this->lore_bonus != other.lore_bonus)  return false;
    for (int i = 0; i < 9; i++)
      if (this->alignments[i] != other.alignments[i])  return false;
    if (this->learn_from_scroll != other.learn_from_scroll)  return false;
    if (this->proficiencies_each != other.proficiencies_each)  return false;
    if (this->extra_strength != other.extra_strength)  return false;
    if (this->have_racial_enemy != other.have_racial_enemy)  return false;
    if (this->experience_chart != other.experience_chart)  return false;
    if (this->spell_progression != other.spell_progression)  return false;
    if (this->abilities != other.abilities)  return false;
    if (this->lower_limits != other.lower_limits)  return false;
    if (this->special_abilities != other.special_abilities)  return false;
    if (this->can_use != other.can_use)  return false;
    if (this->specialisations != other.specialisations)  return false;
    if (this->proficiency_chart != other.proficiency_chart)  return false;
    if (this->default_one_hand != other.default_one_hand)  return false;
    if (this->default_two_hands != other.default_two_hands)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Class::operator !=(const Class& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Class::__copy__(Class& self, const Class& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Class::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->hit_points);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->thac0);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<int>()(this->lore_bonus);
    for (int i = 0; i < 9; i++)
      {
	rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
	rc += std::hash<bool>()(this->alignments[i]);
      }
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<bool>()(this->learn_from_scroll);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<char>()(this->proficiencies_each);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<bool>()(this->extra_strength);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<bool>()(this->have_racial_enemy);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<ExperienceChart>()(this->experience_chart);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<SpellProgression>()(this->spell_progression);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<AbilityBonus>()(this->abilities);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<Abilities>()(this->lower_limits);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::vector<Spell*>>()(this->special_abilities);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<std::unordered_map<Item*, bool>>()(this->can_use);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<MagicSchool>>()(this->specialisations);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::unordered_map<WeaponGroup, std::vector<Proficiency>>>()(this->proficiency_chart);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Weapon>()(this->default_one_hand);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<Weapon>()(this->default_two_hands);
    return rc;
  }
  
}

