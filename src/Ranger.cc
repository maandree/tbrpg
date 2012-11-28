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
#include "Ranger.hpp"


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
  Ranger::Ranger() : Warrior()
  {
    this->spell_progression.priest_slots = std::vector<std::vector<int>>(17);
    for (int i = 0; i <= 16; i++)
      this->spell_progression.priest_slots[i] = std::vector<int>(4);
    
    this->spell_progression.priest_levels = std::vector<std::vector<int>>(31);
    for (int i = 0; i <= 30; i++)
      this->spell_progression.priest_levels[i] = i < 8 ? 0 : i > 16 ? 9 : (i - 7);
    
    for (int cur = 0, i = 0; i <= 16; i++)
      {
	switch (cur)
	  {
	  case 8:
	  case 9:
	  case 13:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][1] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 16; i++)
      {
	switch (cur)
	  {
	  case 10:
	  case 11:
	  case 15:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][2] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 16; i++)
      {
	switch (cur)
	  {
	  case 12:
	  case 14:
	  case 16:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][3] = cur;
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(const Ranger& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(Ranger& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Ranger::Ranger(Ranger&& original) : Warrior(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Ranger::~Ranger()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ranger& Ranger::operator =(const Ranger& original)
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
  Ranger& Ranger::operator =(Ranger& original)
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
  Ranger& Ranger::operator =(Ranger&& original)
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
  void Ranger::__copy__(Ranger& self, const Ranger& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Ranger::hash() const
  {
    return (size_t)this;
  }
  
}

