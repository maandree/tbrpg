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
#include "Mace.hpp"


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
  Mace::Mace()
  {
    //TODO implement constructor
    //rate_of_fire = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(const Mace& original)
  {
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(Mace& original)
  {
    this->rate_of_fire = original.rate_of_fire;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Mace::Mace(Mace&& original)
  {
    std::move(this->rate_of_fire, original.rate_of_fire);
  }
  
  
  
  /**
   * Destructor
   */
  Mace::~Mace()
  {
    //TODO implement destructor
    //delete rate_of_fire;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mace& Mace::operator =(const Mace& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);    this->rate_of_fire = original.rate_of_fire;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Mace& Mace::operator =(Mace& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);    this->rate_of_fire = original.rate_of_fire;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Mace& Mace::operator =(Mace&& original)
  {
    std::move((BluntWeapon)*this, (BluntWeapon)original);    std::move(this->rate_of_fire, original.rate_of_fire);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Mace::__copy__(Mace& self, const Mace& original);
  {
    left = right;
  }
  
}

