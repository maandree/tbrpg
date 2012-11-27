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
  ExperienceChart::ExperienceChart()
  {
    ////TODO implement constructor
    //this->experience = nullptr;
    //this->hit_point_die = nullptr;
    //this->hit_point_dice = nullptr;
    //this->hit_point_bonus = nullptr;
    //this->selectable_wizard = nullptr;
    //this->selectable_priest = nullptr;
    //this->new_spells = nullptr;
    //this->proficiencies = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(const ExperienceChart& original)
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
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(ExperienceChart& original)
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
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ExperienceChart::ExperienceChart(ExperienceChart&& original)
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
  }
  
  
  
  /**
   * Destructor
   */
  ExperienceChart::~ExperienceChart()
  {
    ////TODO implement destructor
    //delete experience;
    //delete hit_point_die;
    //delete hit_point_dice;
    //delete hit_point_bonus;
    //delete selectable_wizard;
    //delete selectable_priest;
    //delete new_spells;
    //delete proficiencies;
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
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
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
    this->experience = original.experience;
    this->hit_point_die = original.hit_point_die;
    this->hit_point_dice = original.hit_point_dice;
    this->hit_point_bonus = original.hit_point_bonus;
    this->selectable_wizard = original.selectable_wizard;
    this->selectable_priest = original.selectable_priest;
    this->new_spells = original.new_spells;
    this->proficiencies = original.proficiencies;
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
    std::swap(this->experience, original.experience);
    std::swap(this->hit_point_die, original.hit_point_die);
    std::swap(this->hit_point_dice, original.hit_point_dice);
    std::swap(this->hit_point_bonus, original.hit_point_bonus);
    std::swap(this->selectable_wizard, original.selectable_wizard);
    std::swap(this->selectable_priest, original.selectable_priest);
    std::swap(this->new_spells, original.new_spells);
    std::swap(this->proficiencies, original.proficiencies);
    return *this;
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

