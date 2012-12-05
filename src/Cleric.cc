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
#include "Cleric.hpp"


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
  Cleric::Cleric() : Priest()
  {
    this->name = "cleric";
    this->thac0 = 20;
    this->abilities.bonuses.detect_doors = 0.10;
    
    this->can_use[MediumShield()] = true;
    this->can_use[LargeShield()] = true;
    this->can_use[ChainMail()] = true;
    this->can_use[SplintMail()] = true;
    this->can_use[PlateMail()] = true;
    this->can_use[FullPlateMail()] = true;
    this->can_use[Dart()] = false;
    this->can_use[Dagger()] = false;
    this->can_use[Flail()] = true;
    this->can_use[Mace()] = true;
    this->can_use[MorningStar()] = true;
    
    this->experience_chart.experience = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      if (i <= 1)
	this->experience_chart.experience[i] = 0;
      else if (i <= 4)
	this->experience_chart.experience[i] = 1500 << (i - 2);
      else if (i == 5)
	this->experience_chart.experience[i] = 13000;
      else if (i <= 8)
	this->experience_chart.experience[i] = 27500 << (i - 6);
      else
	this->experience_chart.experience[i] = 225000 * (i - 8);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Cleric::Cleric(const Cleric& original) : Priest(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Cleric::Cleric(Cleric& original) : Priest(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Cleric::Cleric(Cleric&& original) : Priest(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  Cleric::~Cleric()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Cleric& Cleric::operator =(const Cleric& original)
  {
    (void) original;
    Priest::__copy__((Priest&)*this, (Priest&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Cleric& Cleric::operator =(Cleric& original)
  {
    (void) original;
    Priest::__copy__((Priest&)*this, (Priest&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Cleric& Cleric::operator =(Cleric&& original)
  {
    (void) original;
    std::swap((Priest&)*this, (Priest&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Cleric::operator ==(const Cleric& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Cleric::__copy__(Cleric& self, const Cleric& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Cleric::hash() const
  {
    return (size_t)this;
  }
  
}

