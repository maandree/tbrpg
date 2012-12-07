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
#include "Fighter.hpp"


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
  Fighter::Fighter() : Warrior()
  {
    this->name = "fighter";
    this->abilities.bonuses.detect_doors = 0.10;
    
    for (WeaponGroup weapongroup : WEAPON_GROUPS)
      {
	this->proficiency_chart[weapongroup].push_back(Proficiency(3, 5, 3));
	this->proficiency_chart[weapongroup].push_back(Proficiency(3, 6, 4));
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Fighter::Fighter(const Fighter& original) : Warrior(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Fighter::Fighter(Fighter& original) : Warrior(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Fighter::Fighter(Fighter&& original) : Warrior(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Fighter::~Fighter()
  {
    /* this->experience_chart.experience is initialised by the superclass's constructor */
    for (int i = 1; i <= 30; i++)
      {
	if (i <= 1)
	  this->experience_chart.experience[i] = 0;
	else if (i <= 7)
	  this->experience_chart.experience[i] = 2000 << (i - 2);
	else if (i <= 8)
	  this->experience_chart.experience[i] = 125000;
	else
	  this->experience_chart.experience[i] = 250000 * (i - 8);
      }
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Fighter& Fighter::operator =(const Fighter& original)
  {
    Warrior::__copy__((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Fighter& Fighter::operator =(Fighter& original)
  {
    Warrior::__copy__((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Fighter& Fighter::operator =(Fighter&& original)
  {
    std::swap((Warrior&)*this, (Warrior&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Fighter::operator ==(const Fighter& other) const
  {
    if ((Warrior&)(*this) != (Warrior&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Fighter::operator !=(const Fighter& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Fighter::__copy__(Fighter& self, const Fighter& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Fighter::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Warrior>()(*this);
    return rc;
  }
  
}

