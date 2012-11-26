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
#include "Headgear.hpp"


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
  Headgear::Headgear()
  {
    //TODO implement constructor
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
    // = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(const Headgear& original)
  {
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(Headgear& original)
  {
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Headgear::Headgear(Headgear&& original)
  {
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
  }
  
  
  
  /**
   * Destructor
   */
  Headgear::~Headgear()
  {
    //TODO implement destructor
    //delete ;
    //delete ;
    //delete ;
    //delete ;
    //delete ;
    //delete ;
    //delete ;
    //delete ;
    //delete ;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(const Headgear& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(Headgear& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    this-> = original.;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Headgear& Headgear::operator =(Headgear&& original)
  {
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    std::move(this->, original.);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Headgear::__copy__(Headgear& self, const Headgear& original);
  {
    left = right;
  }
  
}

