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
#include "Paladin.hpp"


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
  Paladin::Paladin() : Warrior()
  {
    this->lower_limits.charisma = 17;
    
    this->spell_progression.priest_slots = std::vector<std::vector<int>>(21);
    for (int i = 0; i <= 20; i++)
      this->spell_progression.priest_slots[i] = std::vector<int>(5);
    
    this->spell_progression.priest_levels = std::vector<int>(31);
    for (int i = 0; i <= 30; i++)
      this->spell_progression.priest_levels[i] = i < 9 ? 0 : i > 17 ? 9 : (i - 8);
    
    for (int cur = 0, i = 0; i <= 20; i++)
      {
	switch (cur)
	  {
	  case 9:
	  case 10:
	  case 14:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][1] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 20; i++)
      {
	switch (cur)
	  {
	  case 11:
	  case 12:
	  case 16:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][2] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 20; i++)
      {
	switch (cur)
	  {
	  case 13:
	  case 16:
	  case 17:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][3] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 20; i++)
      {
	switch (cur)
	  {
	  case 15:
	  case 19:
	  case 20:
	    cur++;
	  }
	this->spell_progression.priest_slots[i][4] = cur;
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Paladin::Paladin(const Paladin& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Paladin::Paladin(Paladin& original) : Warrior(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Paladin::Paladin(Paladin&& original) : Warrior(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Paladin::~Paladin()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Paladin& Paladin::operator =(const Paladin& original)
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
  Paladin& Paladin::operator =(Paladin& original)
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
  Paladin& Paladin::operator =(Paladin&& original)
  {
    (void) original;

    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Paladin::operator ==(const Paladin& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Paladin::__copy__(Paladin& self, const Paladin& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Paladin::hash() const
  {
    return (size_t)this;
  }
  
}

