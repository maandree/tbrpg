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
#include "Proficiency.hpp"


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
  Proficiency::Proficiency()
  {
    ////TODO implement constructor
    //this->hit_bonus = 0;
    //this->damage_bonus = 0;
    //this->half_attacks = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Proficiency::Proficiency(const Proficiency& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->half_attacks = original.half_attacks;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Proficiency::Proficiency(Proficiency& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->half_attacks = original.half_attacks;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Proficiency::Proficiency(Proficiency&& original)
  {
    (void) original;
    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::swap(this->half_attacks, original.half_attacks);
  }
  
  
  
  /**
   * Destructor
   */
  Proficiency::~Proficiency()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Proficiency& Proficiency::operator =(const Proficiency& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->half_attacks = original.half_attacks;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Proficiency& Proficiency::operator =(Proficiency& original)
  {
    (void) original;
    //this->hit_bonus = original.hit_bonus;
    //this->damage_bonus = original.damage_bonus;
    //this->half_attacks = original.half_attacks;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Proficiency& Proficiency::operator =(Proficiency&& original)
  {
    (void) original;
    ////std::swap(this->hit_bonus, original.hit_bonus);
    ////std::swap(this->damage_bonus, original.damage_bonus);
    ////std::swap(this->half_attacks, original.half_attacks);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Proficiency::__copy__(Proficiency& self, const Proficiency& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Proficiency::hash() const
  {
    return (size_t)this;
  }
  
}

