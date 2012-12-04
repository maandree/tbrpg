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
#include "StuddedLeatherArmour.hpp"


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
  StuddedLeatherArmour::StuddedLeatherArmour() : BodyArmour()
  {
    this->name = "studded leather armour";
    this->armour_class = 7;
    this->armour_class_modifiers[SLASHING] = -2;
    this->armour_class_modifiers[PIERCING] = -1;
    this->wizard_magic_use = true;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  StuddedLeatherArmour::StuddedLeatherArmour(const StuddedLeatherArmour& original) : BodyArmour(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  StuddedLeatherArmour::StuddedLeatherArmour(StuddedLeatherArmour& original) : BodyArmour(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  StuddedLeatherArmour::StuddedLeatherArmour(StuddedLeatherArmour&& original) : BodyArmour(original)
  {
    (void) original;

  }
  
  
  
  /**
   * Destructor
   */
  StuddedLeatherArmour::~StuddedLeatherArmour()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  StuddedLeatherArmour& StuddedLeatherArmour::operator =(const StuddedLeatherArmour& original)
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
  StuddedLeatherArmour& StuddedLeatherArmour::operator =(StuddedLeatherArmour& original)
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
  StuddedLeatherArmour& StuddedLeatherArmour::operator =(StuddedLeatherArmour&& original)
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
  bool StuddedLeatherArmour::operator ==(const StuddedLeatherArmour& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void StuddedLeatherArmour::__copy__(StuddedLeatherArmour& self, const StuddedLeatherArmour& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t StuddedLeatherArmour::hash() const
  {
    return (size_t)this;
  }
  
}

