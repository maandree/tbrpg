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
    this->experience = std::vector<int>(31);
    this->hit_point_die = std::vector<char>(31);
    this->hit_point_dice = std::vector<char>(31);
    this->hit_point_bonus = std::vector<int>(31);
    this->selectable_wizard = std::vector<int>(31);
    this->selectable_priest = std::vector<int>(31);
    this->new_spells = std::vector<std::vector<Spell*>*>();
    this->proficiencies = std::vector<int>(31);
    this->backstabs = std::vector<char>(31);
    this->thief_abilities = std::vector<char>(31);
    for (size_t i = 0; i < 31; i++)
      this->new_spells.push_back(new std::vector<Spell*>());
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(const ExperienceChart& original) : Object(original)
  {
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    for (size_t i = 0; i < 31; i++)
      this->new_spells.push_back(new std::vector<Spell*>(*(original.new_spells[i])));
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
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    for (size_t i = 0; i < 31; i++)
      this->new_spells.push_back(new std::vector<Spell*>(*(original.new_spells[i])));
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* ExperienceChart::fork() const
  {
    return (Object*)(new ExperienceChart(*this));
  }
  
  
  
  /**
   * Destructor
   */
  ExperienceChart::~ExperienceChart()
  {
    for (std::vector<Spell*>* elem : this->new_spells)
      delete elem;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ExperienceChart& ExperienceChart::operator =(const ExperienceChart& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    for (size_t i = 0; i < 31; i++)
      {
	delete this->new_spells[i];
	this->new_spells[i] = new std::vector<Spell*>(*(original.new_spells[i]));
      }
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
    Object::__copy__((Object&)*this, (Object&)original);
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    for (size_t i = 0; i < 31; i++)
      {
	delete this->new_spells[i];
	this->new_spells[i] = new std::vector<Spell*>(*(original.new_spells[i]));
      }
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
    std::swap((Object&)*this, (Object&)original);
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
    if (this->experience != other.experience)  return false;
    if (this->hit_point_die != other.hit_point_die)  return false;
    if (this->hit_point_dice != other.hit_point_dice)  return false;
    if (this->hit_point_bonus != other.hit_point_bonus)  return false;
    if (this->selectable_wizard != other.selectable_wizard)  return false;
    if (this->selectable_priest != other.selectable_priest)  return false;
    if (this->new_spells != other.new_spells)  return false;
    if (this->proficiencies != other.proficiencies)  return false;
    if (this->backstabs != other.backstabs)  return false;
    if (this->thief_abilities != other.thief_abilities)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool ExperienceChart::operator !=(const ExperienceChart& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<int>>()(this->experience);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<char>>()(this->hit_point_die);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::vector<char>>()(this->hit_point_dice);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<int>>()(this->hit_point_bonus);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::vector<int>>()(this->selectable_wizard);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<std::vector<int>>()(this->selectable_priest);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<std::vector<std::vector<Spell*>*>>()(this->new_spells);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<std::vector<int>>()(this->proficiencies);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<char>>()(this->backstabs);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<char>>()(this->thief_abilities);
    return rc;
  }
  
}

