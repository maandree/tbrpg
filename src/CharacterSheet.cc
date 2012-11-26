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
#include "CharacterSheet.hpp"


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
  CharacterSheet::CharacterSheet()
  {
    //TODO implement constructor
    //allowed_classes = nullptr;
    //bonuses = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(const CharacterSheet& original)
  {
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(CharacterSheet& original)
  {
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  CharacterSheet::CharacterSheet(CharacterSheet&& original)
  {
    std::move(this->allowed_classes, original.allowed_classes);
    std::move(this->bonuses, original.bonuses);
  }
  
  
  
  /**
   * Destructor
   */
  CharacterSheet::~CharacterSheet()
  {
    //TODO implement destructor
    //delete allowed_classes;
    //delete bonuses;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CharacterSheet& CharacterSheet::operator =(const CharacterSheet& original)
  {
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CharacterSheet& CharacterSheet::operator =(CharacterSheet& original)
  {
    this->allowed_classes = original.allowed_classes;
    this->bonuses = original.bonuses;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  CharacterSheet& CharacterSheet::operator =(CharacterSheet&& original)
  {
    std::move(this->allowed_classes, original.allowed_classes);
    std::move(this->bonuses, original.bonuses);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void CharacterSheet::__copy__(CharacterSheet& self, const CharacterSheet& original);
  {
    left = right;
  }
  
}

