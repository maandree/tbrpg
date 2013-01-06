// -*- mode: c++ , encoding: utf-8 -*-
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
#include "Dice.hpp"


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
   * @param  dieCount   The number of dice
   * @param  sideCount  The number of sides on the dice
   */
  Dice::Dice(char dieCount, char sideCount)
  {
    this->count = dieCount;
    this->die = Die(sideCount);
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(const Dice& original)
  {
    this->die = original.die;
    this->count = original.count;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(Dice& original)
  {
    this->die = original.die;
    this->count = original.count;
  }
  
  /**
   * Move constructor
   *
   * @param  original  The object to clone
   */
  Dice::Dice(Dice&& original)
  {
    std::swap(this->die, original.die);
    std::swap(this->count, original.count);
  }
  
  
  
  /**
   * Destructor
   */
  Dice::~Dice()
  {
    // Do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Dice& Dice::operator =(const Dice& original)
  {
    this->die = original.die;
    this->count = original.count;
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
    this->die = original.die;
    this->count = original.count;
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
    std::swap(this->die, original.die);
    std::swap(this->count, original.count);
    return *this;
  }
  
  
  
  /**
   * Gets the number of dice
   * 
   * @return  The number of dice
   */
  char Dice::getCount() const
  {
    return this->count;
  }
  
  /**
   * Gets the number of sides on the dice
   * 
   * @return  The number of sides on the dice
   */
  char Dice::getSides() const
  {
    return this->die.getSides();
  }
  
  /**
   * Roll the dice
   * 
   * @return  The number of eyes on the dice's value side
   */
  int Dice::roll() const
  {
    int sum = 0;
    for (int i = 0; i < this->count; i++)
      sum += this->die.roll();
    return sum;
  }
  
}

