// -*- mode: c++, encoding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Die.hpp"


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
   * 
   * @param  sideCount  The number of sides on the die
   */
  Die::Die(char sideCount)
  {
    this->sides = sideCount;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Die::Die(const Die& original)
  {
    this->sides = original.sides;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Die::Die(Die& original)
  {
    this->sides = original.sides;
  }
  
  /**
   * Move constructor
   *
   * @param  original  The object to clone
   */
  Die::Die(Die&& original)
  {
    std::swap(this->sides, original.sides);
  }
  
  
  
  /**
   * Destructor
   */
  Die::~Die()
  {
    // Do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Die& Die::operator =(const Die& original)
  {
    this->sides = original.sides;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Die& Die::operator =(Die& original)
  {
    this->sides = original.sides;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Die& Die::operator =(Die&& original)
  {
    std::swap(this->sides, original.sides);
    return *this;
  }
  
  
  
  /**
   * Gets the number of sides on the die
   * 
   * @return  The number of sides on the die
   */
  char Die::getSides() const
  {
    return this->sides;
  }
  
  /**
   * Roll the die
   * 
   * @return  The number of eyes on the die's value side
   */
  char Die::roll() const
  {
    /* Actually using simulated die */
    
    if ((this->sides == 2) || (this->sides & 1))
      return (random() % (this->sides << 1)) / 2 + 1;
    if (this->sides == 100)
      {
	char rc = (random() % 10) * 10 + random() % 10;
	return rc ? rc : 100;
      }
    return (random() % this->sides) + 1;
  }
  
}

