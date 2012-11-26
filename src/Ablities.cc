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
#include "Ablities.hpp"


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
  Ablities::Ablities()
  {
    //TODO implement constructor
    //breath = nullptr;
    //paralyze_poison_death = nullptr;
    //petrification_polymorph = nullptr;
    //rod_staff_wand = nullptr;
    //spell = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Ablities::Ablities(const Ablities& original)
  {
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
  Ablities::Ablities(Ablities& original)
  {
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
  Ablities::Ablities(Ablities&& original)
  {
    std::move(this->breath, original.breath);
    std::move(this->paralyze_poison_death, original.paralyze_poison_death);
    std::move(this->petrification_polymorph, original.petrification_polymorph);
    std::move(this->rod_staff_wand, original.rod_staff_wand);
    std::move(this->spell, original.spell);
  }
  
  
  
  /**
   * Destructor
   */
  Ablities::~Ablities()
  {
    //TODO implement destructor
    //delete breath;
    //delete paralyze_poison_death;
    //delete petrification_polymorph;
    //delete rod_staff_wand;
    //delete spell;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Ablities& Ablities::operator =(const Ablities& original)
  {
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
  Ablities& Ablities::operator =(Ablities& original)
  {
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
  Ablities& Ablities::operator =(Ablities&& original)
  {
    std::move(this->breath, original.breath);
    std::move(this->paralyze_poison_death, original.paralyze_poison_death);
    std::move(this->petrification_polymorph, original.petrification_polymorph);
    std::move(this->rod_staff_wand, original.rod_staff_wand);
    std::move(this->spell, original.spell);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Ablities::__copy__(Ablities& self, const Ablities& original);
  {
    left = right;
  }
  
}

