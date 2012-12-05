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
    this->class_inheritance.push_back(16);
    ////TODO implement constructor
    this->lore_bonus = 1;
    this->learn_from_scroll = false;
    this->proficiencies_each = 1;
    this->extra_strength = false;
    this->have_racial_enemy = false;
    //this->abilities = nullptr;
    //this->special_abilities = nullptr;
    //this->can_use = nullptr;
    //this->specialisations = nullptr;
    
    this->abilities.thief_abilities.find_traps = -1;
    this->abilities.thief_abilities.open_locks = -1;
    this->abilities.thief_abilities.pick_pockets = -1;
    this->abilities.thief_abilities.stealth = -1;
    
    this->experience_chart.thief_abilities = std::vector<char>(31);
    this->experience_chart.backstabs = std::vector<char>(31);
    char backstabs;
    for (long i = 0; i <= 30; i++)
      {
	this->experience_chart.thief_abilities.push_back(0);
        backstabs = backstabs >= 13 ? 5 : ((i + 7) >> 2);
	this->experience_chart.backstabs.push_back(backstabs);
      }
    
    this->alignments = new bool[9];
    for (int i = 0; i < 9; i++)
      this->alignments[i] = true;
    
    this->can_use[Hood()] = true;
    this->can_use[Helmet()] = true;
    this->can_use[Buckler()] = true;
    this->can_use[SmallShield()] = true;
    this->can_use[LeatherArmour()] = true;
    this->can_use[StuddedLeatherArmour()] = true;
    this->can_use[Dart()] = true;
    this->can_use[Sling()] = true;
    this->can_use[ThrowingDagger()] = true;
    this->can_use[Fist()] = true;
    this->can_use[Fists()] = true;
    this->can_use[Bullet()] = true;
    this->can_use[Torch()] = true;
    this->can_use[Quarterstaff()] = true;
    this->can_use[Dagger()] = true;
    this->can_use[Club()] = true;
    this->can_use[Potion()] = true;
    this->can_use[LowScroll()] = true;
    this->can_use[LowWand()] = true;
    
    this->lower_limits.strength = 3;
    this->lower_limits.strength18 = 0;
    this->lower_limits.constitution = 3;
    this->lower_limits.dexterity = 3;
    this->lower_limits.intelligence = 3;
    this->lower_limits.wisdom = 3;
    this->lower_limits.charisma = 3;
    this->default_one_hand = Fist();
    this->default_two_hand = Fists();
    
    for (WeaponGroup weapongroup : WEAPON_GROUPS)
      this->proficiency_chart[weapongroup] = {Proficiency(0, -1, 2), Proficiency(0, 1, 2), Proficiency(1, 3, 3)};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(const Class& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
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
    this->default_two_hand = original.default_two_hand;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(Class& original) : Object(original)
  {
    (void) original;
    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
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
    this->default_two_hand = original.default_two_hand;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(Class&& original) : Object(original)
  {
    (void) original;
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
    std::swap(this->default_two_hand, original.default_two_hand);
  }
  
  
  
  /**
   * Destructor
   */
  Class::~Class()
  {
    ////TODO implement destructor
    delete[] this->alignments;
    //delete this->experience_chart;
    //delete this->spell_progression;
    //delete this->abilities;
    //delete this->lower_limits;
    //delete this->special_abilities;
    //delete this->can_use;
    //delete this->specialisations;
    //delete this->proficiency_chart;
    //delete this->default_one_hand;
    //delete this->default_two_hand;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Class& Class::operator =(const Class& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
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
    this->default_two_hand = original.default_two_hand;
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
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->name = original.name;
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
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
    this->default_two_hand = original.default_two_hand;
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
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->name, original.name);
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
    std::swap(this->default_two_hand, original.default_two_hand);
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
    return this == &other;
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
    return (size_t)this;
  }
  
}

