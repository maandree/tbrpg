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
  AbilityChart::AbilityChart()
  {
    //TODO implement constructor
    //name = nullptr;
    //description = nullptr;
    //wizard = false;
    //priest = false;
    //level = nullptr;
    //saving = nullptr;
    //touch = false;
    //range = nullptr;
    //casting_time = nullptr;
    //duration = nullptr;
    //duration_die = nullptr;
    //duration_dice = nullptr;
    //effect_area = nullptr;
    //school = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(const AbilityChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->school = original.school;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->school = original.school;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  AbilityChart::AbilityChart(AbilityChart&& original)
  {
    std::move(this->name, original.name);
    std::move(this->description, original.description);
    std::swap(this->wizard, original.wizard);
    std::swap(this->priest, original.priest);
    std::move(this->level, original.level);
    std::move(this->saving, original.saving);
    std::swap(this->touch, original.touch);
    std::move(this->range, original.range);
    std::move(this->casting_time, original.casting_time);
    std::move(this->duration, original.duration);
    std::move(this->duration_die, original.duration_die);
    std::move(this->duration_dice, original.duration_dice);
    std::move(this->effect_area, original.effect_area);
    std::move(this->school, original.school);
  }
  
  
  
  /**
   * Destructor
   */
  AbilityChart::~AbilityChart()
  {
    //TODO implement destructor
    //delete name;
    //delete description;
    //delete level;
    //delete saving;
    //delete range;
    //delete casting_time;
    //delete duration;
    //delete duration_die;
    //delete duration_dice;
    //delete effect_area;
    //delete school;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  AbilityChart& AbilityChart::operator =(const AbilityChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->school = original.school;
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
    this->name = original.name;
    this->description = original.description;
    this->wizard = original.wizard;
    this->priest = original.priest;
    this->level = original.level;
    this->saving = original.saving;
    this->touch = original.touch;
    this->range = original.range;
    this->casting_time = original.casting_time;
    this->duration = original.duration;
    this->duration_die = original.duration_die;
    this->duration_dice = original.duration_dice;
    this->effect_area = original.effect_area;
    this->school = original.school;
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
    std::move(this->name, original.name);
    std::move(this->description, original.description);
    std::swap(this->wizard, original.wizard);
    std::swap(this->priest, original.priest);
    std::move(this->level, original.level);
    std::move(this->saving, original.saving);
    std::swap(this->touch, original.touch);
    std::move(this->range, original.range);
    std::move(this->casting_time, original.casting_time);
    std::move(this->duration, original.duration);
    std::move(this->duration_die, original.duration_die);
    std::move(this->duration_dice, original.duration_dice);
    std::move(this->effect_area, original.effect_area);
    std::move(this->school, original.school);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void AbilityChart::__copy__(AbilityChart& self, const AbilityChart& original);
  {
    left = right;
  }
  
}

