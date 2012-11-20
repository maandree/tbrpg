// -*- mode: c++, encoding: utf-8 -*-
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
#include "dice.hpp"


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
   * @param  sideCount  The number of sides on the dice
   */
  Dice::Dice(int sideCount)
  {
    this->sides = sideCount;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(const Dice& original)
  {
    this->sides = original.sides;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(Dice& original)
  {
    this->sides = original.sides;
  }
  
  /**
   * Move constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(Dice&& original)
  {
    this->sides = original.sides;
  }
  
  
  
  /**
   * Destructor
   */
  Dice::~Dice()
  {
    // Do nothing
  }
  
  
  
  /**
   * Reconstruction operator
   * 
   * @param   sideCount  The number of sides on the dice 
   * @return             The invoked object
   */
  Dice& Dice::operator =(int sideCount)
  {
    this->sides = sideCount;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Dice& Dice::operator =(const Dice& original)
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
  Dice& Dice::operator =(Dice& original)
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
  Dice& Dice::operator =(Dice&& original)
  {
    std::swap(this->sides, original.sides);
    return *this;
  }
  
  
  
  /**
   * Gets the number of sides on the dice
   * 
   * @return  The number of sides on the dice
   */
  int Dice::getSides() const
  {
    return this->sides;
  }
  
  /**
   * Throw the dice
   * 
   * @return  The number of eyes on the dice's value side
   */
  int Dice::getThrow() const
  {
    return (random() % this->sides) + 1;
  }
  
}

