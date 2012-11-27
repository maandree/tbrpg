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
#include "Priest.hpp"


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
  Priest::Priest() : Class()
  {
    this->spell_progression.priest_slots = std::vector<std::vector<int>>(31);
    for (int i = 0; i <= 30; i++)
      this->spell_progression.priest_slots[i] = std::vector<int>(8);
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 1:
	  case 2:
	  case 4:
	  case 9:
	  case 11:
	  case 12:
	  case 16:
	  case 18:
	  case 19:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][1] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 3:
	  case 4:
	  case 5:
	  case 9:
	  case 12:
	  case 13:
	  case 16:
	  case 18:
	  case 19:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][2] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 5:
	  case 6:
	  case 8:
	  case 11:
	  case 12:
	  case 13:
	  case 16:
	  case 18:
	  case 19:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][3] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 7:
	  case 8:
	  case 10:
	  case 13:
	  case 14:
	  case 15:
	  case 17:
	  case 18:
	  case 21:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][4] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 9:
	  case 10:
	  case 14:
	  case 15:
	  case 17:
	  case 18:
	  case 20:
	  case 21:
	  case 22:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][5] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 11:
	  case 12:
	  case 16:
	  case 18:
	  case 20:
	  case 21:
	  case 23:
	  case 24:
	  case 26:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][6] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 30; i++)
      {
	switch (cur)
	  {
	  case 14:
	  case 17:
	  case 22:
	  case 25:
	  case 27:
	  case 28:
	  case 29:
	  case 30:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][7] = cur;
      }
    
    this->experience_chart.hit_point_die = std::vector<char>(31);
    this->experience_chart.hit_point_dice = std::vector<char>(31);
    this->experience_chart.hit_point_bonus = std::vector<int>(31);
    this->experience_chart.proficiencies = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      {
	this->experience_chart.hit_point_die[i] = 10;
	this->experience_chart.hit_point_dice[i] = i > 9 ? 9 : i;
	this->experience_chart.hit_point_bonus[i] = i <= 9 ? 0 : ((i - 9) * 2);
	this->experience_chart.proficiencies[i] = i / 4 + 2;
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Priest::Priest(const Priest& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Priest::Priest(Priest& original) : Class(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Priest::Priest(Priest&& original) : Class(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Priest::~Priest()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Priest& Priest::operator =(const Priest& original)
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
  Priest& Priest::operator =(Priest& original)
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
  Priest& Priest::operator =(Priest&& original)
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
  void Priest::__copy__(Priest& self, const Priest& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Priest::hash() const
  {
    return (size_t)this;
  }
  
}

