// -*- mode: c++, coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Mage.hpp"


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
  Mage::Mage() : Wizard()
  {
    this->class_inheritance.push_back(100);
    this->name = "mage";
    this->learn_from_scroll = true;
    this->experience_chart.selectable_wizard = {0, 2};
    this->specialisations = {GENERAL_MAGE, ABJURATION, ALTERATION,
			     CONJURATION, DIVINATION, ENCHANTMENT,
			     ILLUSION, INVOCATION, NECROMANCY};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mage::Mage(const Mage& original) : Wizard(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mage::Mage(Mage& original) : Wizard(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Mage::Mage(Mage&& original) : Wizard(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Mage::fork() const
  {
    return (Object*)(new Mage(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Mage::~Mage()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mage& Mage::operator =(const Mage& original)
  {
    Wizard::__copy__((Wizard&)*this, (Wizard&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mage& Mage::operator =(Mage& original)
  {
    Wizard::__copy__((Wizard&)*this, (Wizard&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Mage& Mage::operator =(Mage&& original)
  {
    std::swap((Wizard&)*this, (Wizard&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Mage::operator ==(const Mage& other) const
  {
    if ((Wizard&)(*this) != (Wizard&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Mage::operator !=(const Mage& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Mage::__copy__(Mage& self, const Mage& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Mage::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Wizard>()(*this);
    return rc;
  }
  
}

