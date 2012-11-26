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
#include "SpellBook.hpp"


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
  SpellBook::SpellBook()
  {
    //TODO implement constructor
    //bonuses = nullptr;
    //thief_abilities = nullptr;
    //saving_throws = nullptr;
    //abilities = nullptr;
    //spells = nullptr;
    //effects = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(const SpellBook& original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook& original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SpellBook::SpellBook(SpellBook&& original)
  {
    std::move(this->bonuses, original.bonuses);
    std::move(this->thief_abilities, original.thief_abilities);
    std::move(this->saving_throws, original.saving_throws);
    std::move(this->abilities, original.abilities);
    std::move(this->spells, original.spells);
    std::move(this->effects, original.effects);
  }
  
  
  
  /**
   * Destructor
   */
  SpellBook::~SpellBook()
  {
    //TODO implement destructor
    //delete bonuses;
    //delete thief_abilities;
    //delete saving_throws;
    //delete abilities;
    //delete spells;
    //delete effects;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(const SpellBook& original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(SpellBook& original)
  {
    this->bonuses = original.bonuses;
    this->thief_abilities = original.thief_abilities;
    this->saving_throws = original.saving_throws;
    this->abilities = original.abilities;
    this->spells = original.spells;
    this->effects = original.effects;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SpellBook& SpellBook::operator =(SpellBook&& original)
  {
    std::move(this->bonuses, original.bonuses);
    std::move(this->thief_abilities, original.thief_abilities);
    std::move(this->saving_throws, original.saving_throws);
    std::move(this->abilities, original.abilities);
    std::move(this->spells, original.spells);
    std::move(this->effects, original.effects);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void SpellBook::__copy__(SpellBook& self, const SpellBook& original);
  {
    left = right;
  }
  
}

