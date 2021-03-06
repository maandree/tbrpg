// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
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
    this->class_inheritance.push_back(102);
    this->name = "cleric";
    this->thac0 = 20;
    this->abilities.bonuses.detect_doors = 0.10;
    
    this->can_use[&PROTOTYPE(MediumShield)] = true;
    this->can_use[&PROTOTYPE(LargeShield)] = true;
    this->can_use[&PROTOTYPE(ChainMail)] = true;
    this->can_use[&PROTOTYPE(SplintMail)] = true;
    this->can_use[&PROTOTYPE(PlateMail)] = true;
    this->can_use[&PROTOTYPE(FullPlateMail)] = true;
    this->can_use[&PROTOTYPE(Dart)] = false;
    this->can_use[&PROTOTYPE(Dagger)] = false;
    this->can_use[&PROTOTYPE(Flail)] = true;
    this->can_use[&PROTOTYPE(Mace)] = true;
    this->can_use[&PROTOTYPE(MorningStar)] = true;
    
    this->experience_chart->experience = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      if (i <= 1)
	this->experience_chart->experience[i] = 0;
      else if (i <= 4)
	this->experience_chart->experience[i] = 1500 << (i - 2);
      else if (i == 5)
	this->experience_chart->experience[i] = 13000;
      else if (i <= 8)
	this->experience_chart->experience[i] = 27500 << (i - 6);
      else
	this->experience_chart->experience[i] = 225000 * (i - 8);
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Cleric::fork() const
  {
    return (Object*)(new Cleric(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Cleric::~Cleric()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Cleric& Cleric::operator =(const Cleric& original)
  {
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
    if ((Priest&)(*this) != (Priest&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Cleric::operator !=(const Cleric& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Priest>()(*this);
    return rc;
  }
  
}

