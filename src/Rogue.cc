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
#include "Rogue.hpp"


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
  Rogue::Rogue() : Class()
  {
    this->class_inheritance.push_back(51);
    this->hit_points = 6;
    this->abilities.saving_throws.breath = 16;
    this->abilities.saving_throws.paralyze_poison_death = 13;
    this->abilities.saving_throws.petrification_polymorph = 12;
    this->abilities.saving_throws.rod_staff_wand = 14;
    this->abilities.saving_throws.spell = 15;
    
    this->can_use[Hood()] = false;
    this->can_use[Arrow()] = true;
    this->can_use[LongSword()] = true;
    this->can_use[ShortSword()] = true;
    this->can_use[ShortBow()] = true;
    
    this->experience_chart.experience = std::vector<int>(31);
    this->experience_chart.hit_point_die = std::vector<char>(31);
    this->experience_chart.hit_point_dice = std::vector<char>(31);
    this->experience_chart.hit_point_bonus = std::vector<int>(31);
    this->experience_chart.proficiencies = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      {
	this->experience_chart.hit_point_die[i] = 6;
	this->experience_chart.hit_point_dice[i] = i > 10 ? 10 : i;
	this->experience_chart.hit_point_bonus[i] = i <= 10 ? 0 : ((i - 10) * 2);
	this->experience_chart.proficiencies[i] = i / 4 + 2;
	if (i <= 1)
	  this->experience_chart.experience[i] = 0;
	else if (i <= 7)
	  this->experience_chart.experience[i] = 1250 << (i - 2);
	else if (i <= 11)
	  this->experience_chart.experience[i] = (7 + (i - 8) * (i - 1) / 2) * 10000;
	else
	  this->experience_chart.experience[i] = 220000 * (i - 10);
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Rogue::Rogue(const Rogue& original) : Class(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Rogue::Rogue(Rogue& original) : Class(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Rogue::Rogue(Rogue&& original) : Class(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Rogue::~Rogue()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Rogue& Rogue::operator =(const Rogue& original)
  {
    Class::__copy__((Class&)*this, (Class&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Rogue& Rogue::operator =(Rogue& original)
  {
    Class::__copy__((Class&)*this, (Class&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Rogue& Rogue::operator =(Rogue&& original)
  {
    std::swap((Class&)*this, (Class&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Rogue::operator ==(const Rogue& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Rogue::__copy__(Rogue& self, const Rogue& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Rogue::hash() const
  {
    return (size_t)this;
  }
  
}

