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
#include "ExperienceChart.hpp"


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
  ExperienceChart::ExperienceChart() : Object()
  {
    this->class_inheritance.push_back(9);
    ////TODO implement constructor
    //this->experience = nullptr;
    //this->hit_point_die = nullptr;
    //this->hit_point_dice = nullptr;
    //this->hit_point_bonus = nullptr;
    //this->selectable_wizard = nullptr;
    //this->selectable_priest = nullptr;
    //this->new_spells = nullptr;
    //this->proficiencies = nullptr;
    //this->backstabs = nullptr;
    //this->thief_abilities = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(const ExperienceChart& original) : Object(original)
  {
    (void) original;
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
    this->backstabs = original.backstabs;
    this->thief_abilities = original.thief_abilities;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(ExperienceChart& original) : Object(original)
  {
    (void) original;
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
    this->backstabs = original.backstabs;
    this->thief_abilities = original.thief_abilities;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(ExperienceChart&& original) : Object(original)
  {
    (void) original;
    std::swap(this->experience, original.experience);
    std::swap(this->hit_point_die, original.hit_point_die);
    std::swap(this->hit_point_dice, original.hit_point_dice);
    std::swap(this->hit_point_bonus, original.hit_point_bonus);
    std::swap(this->selectable_wizard, original.selectable_wizard);
    std::swap(this->selectable_priest, original.selectable_priest);
    std::swap(this->new_spells, original.new_spells);
    std::swap(this->proficiencies, original.proficiencies);
    std::swap(this->backstabs, original.backstabs);
    std::swap(this->thief_abilities, original.thief_abilities);
  }
  
  
  
  /**
   * Destructor
   */
  ExperienceChart::~ExperienceChart()
  {
    ////TODO implement destructor
    //delete this->experience;
    //delete this->hit_point_die;
    //delete this->hit_point_dice;
    //delete this->hit_point_bonus;
    //delete this->selectable_wizard;
    //delete this->selectable_priest;
    //delete this->new_spells;
    //delete this->proficiencies;
    //delete this->backstabs;
    //delete this->thief_abilities;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ExperienceChart& ExperienceChart::operator =(const ExperienceChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
    this->backstabs = original.backstabs;
    this->thief_abilities = original.thief_abilities;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ExperienceChart& ExperienceChart::operator =(ExperienceChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
    this->backstabs = original.backstabs;
    this->thief_abilities = original.thief_abilities;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ExperienceChart& ExperienceChart::operator =(ExperienceChart&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->experience, original.experience);
    std::swap(this->hit_point_die, original.hit_point_die);
    std::swap(this->hit_point_dice, original.hit_point_dice);
    std::swap(this->hit_point_bonus, original.hit_point_bonus);
    std::swap(this->selectable_wizard, original.selectable_wizard);
    std::swap(this->selectable_priest, original.selectable_priest);
    std::swap(this->new_spells, original.new_spells);
    std::swap(this->proficiencies, original.proficiencies);
    std::swap(this->backstabs, original.backstabs);
    std::swap(this->thief_abilities, original.thief_abilities);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ExperienceChart::operator ==(const ExperienceChart& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void ExperienceChart::__copy__(ExperienceChart& self, const ExperienceChart& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ExperienceChart::hash() const
  {
    return (size_t)this;
  }
  
}

