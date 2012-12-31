// -*- mode: c++, coding: utf-8 -*-
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
#include "Town.hpp"


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
  Town::Town() : MapMinor()
  {
    this->class_inheritance.push_back(136);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Town::Town(const Town& original) : MapMinor(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Town::Town(Town& original) : MapMinor(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Town::Town(Town&& original) : MapMinor(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Town::fork() const
  {
    return (Object*)(new Town(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Town::~Town()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Town& Town::operator =(const Town& original)
  {
    MapMinor::__copy__((MapMinor&)*this, (MapMinor&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Town& Town::operator =(Town& original)
  {
    MapMinor::__copy__((MapMinor&)*this, (MapMinor&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Town& Town::operator =(Town&& original)
  {
    std::swap((MapMinor&)*this, (MapMinor&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Town::operator ==(const Town& other) const
  {
    if ((MapMinor&)(*this) != (MapMinor&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Town::operator !=(const Town& other) const
  {
    return (*this == other) == false;
  }
  
  
  /**
   * Resting function
   * 
   * @return  Whether the party successfully slept
   */
  bool Town::rest()
  {
    if (this->may_rest == false)
      {
	std::cout << "May not rest here, either find an inn or rest outside." << std::endl;
	return false;
      }
    
    if (this->interruptions.size() > 0)
      {
	for (RestInterruption& interruption : this->interruptions)
	  if (Dice(interruption.interrupt_dice, interruption.interrupt_die).roll() <= interruption.interrupt_risk)
	    {
	      int monsters = 0;
	      for (Creature& creature : interruption.creatures)
		{
		  this->creatures.push_back(Creature(creature));
		  monsters++;
		}
	      
	      if (monsters == 0)
		std::cout << "You woke up by a terrifing vivid nightmare." << std::endl;
	      else
		std::cout << "You woke up monsters." << std::endl;
	      return false;
	    }
      }
    else
      promptDialogue(1, "Guard",
		 "You may not rest in public, either rent a"     "\n"
		 "room in an inn or rest outside the town.",
		 {});
    
    return true;
  }
  
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Town::__copy__(Town& self, const Town& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Town::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<MapMinor>()(*this);
    return rc;
  }
  
}

