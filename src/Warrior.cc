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
#include "Warrior.hpp"


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
  Warrior::Warrior() : Class()
  {
    this->proficiencies_each = 2;
    this->hit_points = 10;
    this->thac0 = 22;
    this->abilities.saving_throws.breath = 17;
    this->abilities.saving_throws.paralyze_poison_death = 14;
    this->abilities.saving_throws.petrification_polymorph = 15;
    this->abilities.saving_throws.rod_staff_wand = 16;
    this->abilities.saving_throws.spell = 17;
    
    this->experience_chart.experience = std::vector<int>(31);
    this->experience_chart.hit_point_die = std::vector<char>(31);
    this->experience_chart.hit_point_dice = std::vector<char>(31);
    this->experience_chart.hit_point_bonus = std::vector<int>(31);
    this->experience_chart.proficiencies = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      {
	this->experience_chart.hit_point_die[i] = 10;
	this->experience_chart.hit_point_dice[i] = i > 9 ? 9 : i;
	this->experience_chart.hit_point_bonus[i] = i <= 9 ? 0 : ((i - 9) * 3);
	this->experience_chart.proficiencies[i] = i / 3 + 4;
	if (i <= 1)
	  this->experience_chart.experience[i] = 0;
	else if (i <= 6)
	  this->experience_chart.experience[i] = 2250 << (i - 2);
	else if (i <= 10)
	  this->experience_chart.experience[i] = 75000 << (i - 7);
	else
	  this->experience_chart.experience[i] = 300000 * (i - 8);
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(const Warrior& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(Warrior& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(Warrior&& original) : Class(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Warrior::~Warrior()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(const Warrior& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(Warrior& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(Warrior&& original)
  {
    (void) original;

    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Warrior::__copy__(Warrior& self, const Warrior& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Warrior::hash() const
  {
    return (size_t)this;
  }
  
}

