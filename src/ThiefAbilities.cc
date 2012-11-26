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
#include "ThiefAbilities.hpp"


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
  ThiefAbilities::ThiefAbilities()
  {
    //TODO implement constructor
    //melee = nullptr;
    //missile = nullptr;
    //fire = nullptr;
    //cold = nullptr;
    //lightning = nullptr;
    //acid = nullptr;
    //poison = nullptr;
    //physical = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(const ThiefAbilities& original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(ThiefAbilities& original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ThiefAbilities::ThiefAbilities(ThiefAbilities&& original)
  {
    std::move(this->melee, original.melee);
    std::move(this->missile, original.missile);
    std::move(this->fire, original.fire);
    std::move(this->cold, original.cold);
    std::move(this->lightning, original.lightning);
    std::move(this->acid, original.acid);
    std::move(this->poison, original.poison);
    std::move(this->physical, original.physical);
  }
  
  
  
  /**
   * Destructor
   */
  ThiefAbilities::~ThiefAbilities()
  {
    //TODO implement destructor
    //delete melee;
    //delete missile;
    //delete fire;
    //delete cold;
    //delete lightning;
    //delete acid;
    //delete poison;
    //delete physical;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(const ThiefAbilities& original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(ThiefAbilities& original)
  {
    this->melee = original.melee;
    this->missile = original.missile;
    this->fire = original.fire;
    this->cold = original.cold;
    this->lightning = original.lightning;
    this->acid = original.acid;
    this->poison = original.poison;
    this->physical = original.physical;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ThiefAbilities& ThiefAbilities::operator =(ThiefAbilities&& original)
  {
    std::move(this->melee, original.melee);
    std::move(this->missile, original.missile);
    std::move(this->fire, original.fire);
    std::move(this->cold, original.cold);
    std::move(this->lightning, original.lightning);
    std::move(this->acid, original.acid);
    std::move(this->poison, original.poison);
    std::move(this->physical, original.physical);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void ThiefAbilities::__copy__(ThiefAbilities& self, const ThiefAbilities& original);
  {
    left = right;
  }
  
}

