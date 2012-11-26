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
    //TODO implement constructor
    //locked = false;
    //pick_level = nullptr;
    //bash_level = nullptr;
    //pickable = false;
    //bashable = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(const Entrance& original)
  {
    this->locked = original.locked;
    this->pick_level = original.pick_level;
    this->bash_level = original.bash_level;
    this->pickable = original.pickable;
    this->bashable = original.bashable;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance& original)
  {
    this->locked = original.locked;
    this->pick_level = original.pick_level;
    this->bash_level = original.bash_level;
    this->pickable = original.pickable;
    this->bashable = original.bashable;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Entrance::Entrance(Entrance&& original)
  {
    std::swap(this->locked, original.locked);
    std::move(this->pick_level, original.pick_level);
    std::move(this->bash_level, original.bash_level);
    std::swap(this->pickable, original.pickable);
    std::swap(this->bashable, original.bashable);
  }
  
  
  
  /**
   * Destructor
   */
  Entrance::~Entrance()
  {
    //TODO implement destructor
    //delete pick_level;
    //delete bash_level;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Entrance& Entrance::operator =(const Entrance& original)
  {
    this->locked = original.locked;
    this->pick_level = original.pick_level;
    this->bash_level = original.bash_level;
    this->pickable = original.pickable;
    this->bashable = original.bashable;
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
    this->locked = original.locked;
    this->pick_level = original.pick_level;
    this->bash_level = original.bash_level;
    this->pickable = original.pickable;
    this->bashable = original.bashable;
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
    std::swap(this->locked, original.locked);
    std::move(this->pick_level, original.pick_level);
    std::move(this->bash_level, original.bash_level);
    std::swap(this->pickable, original.pickable);
    std::swap(this->bashable, original.bashable);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Entrance::__copy__(Entrance& self, const Entrance& original);
  {
    left = right;
  }
  
}

