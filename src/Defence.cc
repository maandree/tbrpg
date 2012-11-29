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
#include "Defence.hpp"


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
  Defence::Defence()
  {
    ////TODO implement constructor
    //this->melee = 0;
    //this->missile = 0;
    //this->fire = 0;
    //this->cold = 0;
    //this->lightning = 0;
    //this->acid = 0;
    //this->poison = 0;
    //this->physical = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Defence::Defence(const Defence& original)
  {
    (void) original;
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
  Defence::Defence(Defence& original)
  {
    (void) original;
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
  Defence::Defence(Defence&& original)
  {
    (void) original;
    std::swap(this->melee, original.melee);
    std::swap(this->missile, original.missile);
    std::swap(this->fire, original.fire);
    std::swap(this->cold, original.cold);
    std::swap(this->lightning, original.lightning);
    std::swap(this->acid, original.acid);
    std::swap(this->poison, original.poison);
    std::swap(this->physical, original.physical);
  }
  
  
  
  /**
   * Destructor
   */
  Defence::~Defence()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Defence& Defence::operator =(const Defence& original)
  {
    (void) original;
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
  Defence& Defence::operator =(Defence& original)
  {
    (void) original;
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
  Defence& Defence::operator =(Defence&& original)
  {
    (void) original;
    std::swap(this->melee, original.melee);
    std::swap(this->missile, original.missile);
    std::swap(this->fire, original.fire);
    std::swap(this->cold, original.cold);
    std::swap(this->lightning, original.lightning);
    std::swap(this->acid, original.acid);
    std::swap(this->poison, original.poison);
    std::swap(this->physical, original.physical);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Defence::operator ==(const Defence& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Defence::__copy__(Defence& self, const Defence& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Defence::hash() const
  {
    return (size_t)this;
  }
  
}

