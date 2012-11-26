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
#include "Lockable.hpp"


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
  Lockable::Lockable()
  {
    ////TODO implement constructor
    //this->locked = false;
    //this->pick_level = 0;
    //this->bash_level = 0;
    //this->pickable = false;
    //this->bashable = false;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Lockable::Lockable(const Lockable& original)
  {
    (void) original;
    //this->locked = original.locked;
    //this->pick_level = original.pick_level;
    //this->bash_level = original.bash_level;
    //this->pickable = original.pickable;
    //this->bashable = original.bashable;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Lockable::Lockable(Lockable& original)
  {
    (void) original;
    //this->locked = original.locked;
    //this->pick_level = original.pick_level;
    //this->bash_level = original.bash_level;
    //this->pickable = original.pickable;
    //this->bashable = original.bashable;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Lockable::Lockable(Lockable&& original)
  {
    (void) original;
    ////std::swap(this->locked, original.locked);
    ////std::swap(this->pick_level, original.pick_level);
    ////std::swap(this->bash_level, original.bash_level);
    ////std::swap(this->pickable, original.pickable);
    ////std::swap(this->bashable, original.bashable);
  }
  
  
  
  /**
   * Destructor
   */
  Lockable::~Lockable()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Lockable& Lockable::operator =(const Lockable& original)
  {
    (void) original;
    //this->locked = original.locked;
    //this->pick_level = original.pick_level;
    //this->bash_level = original.bash_level;
    //this->pickable = original.pickable;
    //this->bashable = original.bashable;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Lockable& Lockable::operator =(Lockable& original)
  {
    (void) original;
    //this->locked = original.locked;
    //this->pick_level = original.pick_level;
    //this->bash_level = original.bash_level;
    //this->pickable = original.pickable;
    //this->bashable = original.bashable;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Lockable& Lockable::operator =(Lockable&& original)
  {
    (void) original;
    ////std::swap(this->locked, original.locked);
    ////std::swap(this->pick_level, original.pick_level);
    ////std::swap(this->bash_level, original.bash_level);
    ////std::swap(this->pickable, original.pickable);
    ////std::swap(this->bashable, original.bashable);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Lockable::__copy__(Lockable& self, const Lockable& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Lockable::hash() const
  {
    return (size_t)this;
  }
  
}

