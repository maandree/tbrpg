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
#include "Spell.hpp"


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
  Spell::Spell()
  {
    //TODO implement constructor
    //name = nullptr;
    //coluration = nullptr;
    //practicer = nullptr;
    //opposite = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(const Spell& original)
  {
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell& original)
  {
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell&& original)
  {
    std::move(this->name, original.name);
    std::move(this->coluration, original.coluration);
    std::move(this->practicer, original.practicer);
    std::move(this->opposite, original.opposite);
  }
  
  
  
  /**
   * Destructor
   */
  Spell::~Spell()
  {
    //TODO implement destructor
    //delete name;
    //delete coluration;
    //delete practicer;
    //delete opposite;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(const Spell& original)
  {
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell& original)
  {
    this->name = original.name;
    this->coluration = original.coluration;
    this->practicer = original.practicer;
    this->opposite = original.opposite;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell&& original)
  {
    std::move(this->name, original.name);
    std::move(this->coluration, original.coluration);
    std::move(this->practicer, original.practicer);
    std::move(this->opposite, original.opposite);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Spell::__copy__(Spell& self, const Spell& original);
  {
    left = right;
  }
  
}

