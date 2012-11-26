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
#include "SavingThrows.hpp"


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
  SavingThrows::SavingThrows()
  {
    ////TODO implement constructor
    //this->breath = 0;
    //this->paralyze_poison_death = 0;
    //this->petrification_polymorph = 0;
    //this->rod_staff_wand = 0;
    //this->spell = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(const SavingThrows& original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows& original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SavingThrows::SavingThrows(SavingThrows&& original)
  {
    (void) original;
    //std::swap(this->breath, original.breath);
    //std::swap(this->paralyze_poison_death, original.paralyze_poison_death);
    //std::swap(this->petrification_polymorph, original.petrification_polymorph);
    //std::swap(this->rod_staff_wand, original.rod_staff_wand);
    //std::swap(this->spell, original.spell);
  }
  
  
  
  /**
   * Destructor
   */
  SavingThrows::~SavingThrows()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(const SavingThrows& original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows& original)
  {
    (void) original;
    this->breath = original.breath;
    this->paralyze_poison_death = original.paralyze_poison_death;
    this->petrification_polymorph = original.petrification_polymorph;
    this->rod_staff_wand = original.rod_staff_wand;
    this->spell = original.spell;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SavingThrows& SavingThrows::operator =(SavingThrows&& original)
  {
    (void) original;
    //std::swap(this->breath, original.breath);
    //std::swap(this->paralyze_poison_death, original.paralyze_poison_death);
    //std::swap(this->petrification_polymorph, original.petrification_polymorph);
    //std::swap(this->rod_staff_wand, original.rod_staff_wand);
    //std::swap(this->spell, original.spell);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void SavingThrows::__copy__(SavingThrows& self, const SavingThrows& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t SavingThrows::hash() const
  {
    return (size_t)this;
  }
  
}

