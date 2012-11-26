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
#include "Entrance.hpp"


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
  Entrance::Entrance()
  {
    ////TODO implement constructor
    //this->usable = false;
    //this->description = nullptr;
    //this->direction = nullptr;
    //this->leads_to = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(const Entrance& original)
  {
    (void) original;
    //this->usable = original.usable;
    //this->description = original.description;
    //this->direction = original.direction;
    //this->leads_to = original.leads_to;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance& original)
  {
    (void) original;
    //this->usable = original.usable;
    //this->description = original.description;
    //this->direction = original.direction;
    //this->leads_to = original.leads_to;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance&& original)
  {
    (void) original;
    ////std::swap(this->usable, original.usable);
    ////std::move(this->description, original.description);
    ////std::move(this->direction, original.direction);
    ////std::move(this->leads_to, original.leads_to);
  }
  
  
  
  /**
   * Destructor
   */
  Entrance::~Entrance()
  {
    ////TODO implement destructor
    //delete description;
    //delete direction;
    //delete leads_to;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(const Entrance& original)
  {
    (void) original;
    //this->usable = original.usable;
    //this->description = original.description;
    //this->direction = original.direction;
    //this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(Entrance& original)
  {
    (void) original;
    //this->usable = original.usable;
    //this->description = original.description;
    //this->direction = original.direction;
    //this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(Entrance&& original)
  {
    (void) original;
    ////std::swap(this->usable, original.usable);
    ////std::move(this->description, original.description);
    ////std::move(this->direction, original.direction);
    ////std::move(this->leads_to, original.leads_to);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Entrance::__copy__(Entrance& self, const Entrance& original)
  {
    self = original;
  }
  
}

