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
#include "Druid.hpp"


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
  Druid::Druid() : Priest()
  {
    this->class_inheritance.push_back(103);
    this->name = "druid";
    this->thac0 = 23;
    this->lower_limits.charisma = 9;
    
    this->can_use[&PROTOTYPE(Spear)] = true;
    
    this->experience_chart->experience = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      if (i <= 1)
	this->experience_chart->experience[i] = 0;
      else if (i <= 3)
	this->experience_chart->experience[i] = 2000 << (i - 2);
      else if (i <= 5)
	this->experience_chart->experience[i] = 7500 + 5000 * (i - 4);
      else if (i <= 7)
	this->experience_chart->experience[i] = 20000 + 15000 * (i - 6);
      else if (i <= 9)
	this->experience_chart->experience[i] = 60000 + 30000 * (i - 8);
      else if (i <= 12)
	this->experience_chart->experience[i] = i == 10 ? 125000 : (100000 * (i - 9));
      else if (i <= 14)
	this->experience_chart->experience[i] = 750000 * (i - 12);
      else
	this->experience_chart->experience[i] = 225000 * (i - 7);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Druid::Druid(const Druid& original) : Priest(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Druid::Druid(Druid& original) : Priest(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Druid::Druid(Druid&& original) : Priest(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Druid::fork() const
  {
    return (Object*)(new Druid(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Druid::~Druid()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Druid& Druid::operator =(const Druid& original)
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
  Druid& Druid::operator =(Druid& original)
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
  Druid& Druid::operator =(Druid&& original)
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
  bool Druid::operator ==(const Druid& other) const
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
  bool Druid::operator !=(const Druid& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Druid::__copy__(Druid& self, const Druid& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Druid::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Priest>()(*this);
    return rc;
  }
  
}

