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
#include "Wizard.hpp"


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
  Wizard::Wizard() : Class()
  {
    this->spell_progression.wizard_slots = std::vector<std::vector<int>>(31);
    for (int i = 0; i <= 30; i++)
      {
	this->spell_progression.wizard_slots[i] = std::vector<int>(10);
	this->spell_progression.wizard_slots[i][0] = 1 + i;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 1:
	  case 2:
	  case 4:
	  case 5:
	  case 13:
	  case 19:
	  case 23:
	  case 26:
	  case 29:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][1] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 3:
	  case 4:
	  case 7:
	  case 10:
	  case 14:
	  case 21:
	  case 25:
	  case 28:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][2] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 5:
	  case 6:
	  case 8:
	  case 11:
	  case 13:
	  case 24:
	  case 28:
	  case 30:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][3] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 7:
	  case 8:
	  case 11:
	  case 12:
	  case 15:
	  case 26:
	  case 29:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][4] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 9:
	  case 10:
	  case 11:
	  case 12:
	  case 15:
	  case 27:
	  case 30:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][5] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 12:
	  case 13:
	  case 16:
	  case 20:
	  case 23:
	  case 27:
	  case 30:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][6] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 14:
	  case 16:
	  case 17:
	  case 21:
	  case 23:
	  case 28:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][7] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 16:
	  case 17:
	  case 19:
	  case 24:
	  case 25:
	  case 28:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][8] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 18:
	  case 23:
	  case 26:
	  case 29:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][9] = cur;
      }
    
    this->experience_chart.experience = std::vector<int>(31);
    this->experience_chart.hit_point_die = std::vector<char>(31);
    this->experience_chart.hit_point_dice = std::vector<char>(31);
    this->experience_chart.hit_point_bonus = std::vector<int>(31);
    this->experience_chart.proficiencies = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      {
	this->experience_chart.hit_point_die[i] = 4;
	this->experience_chart.hit_point_dice[i] = i > 10 ? 10 : i;
	this->experience_chart.hit_point_bonus[i] = i <= 10 ? 0 : (i - 10);
	this->experience_chart.proficiencies[i] = i / 5 + 2;
	if (i <= 1)
	  this->experience_chart.experience[i] = 0;
	else if (i <= 6)
	  this->experience_chart.experience[i] = 2500 << (i - 2);
	else if (i <= 8)
	  this->experience_chart.experience[i] = 60000 + 30000 * (i - 7);
	else if (i == 9)
	  this->experience_chart.experience[i] = 135000;
	else if (i <= 11)
	  this->experience_chart.experience[i] = 250000 + 125000 * (i - 10);
	else
	  this->experience_chart.experience[i] = 750000 + 375000 * (i - 12);
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Wizard::Wizard(const Wizard& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Wizard::Wizard(Wizard& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Wizard::Wizard(Wizard&& original) : Class(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Wizard::~Wizard()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Wizard& Wizard::operator =(const Wizard& original)
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
  Wizard& Wizard::operator =(Wizard& original)
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
  Wizard& Wizard::operator =(Wizard&& original)
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
  void Wizard::__copy__(Wizard& self, const Wizard& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Wizard::hash() const
  {
    return (size_t)this;
  }
  
}

