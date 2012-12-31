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
#include "Gnome.hpp"


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
  Gnome::Gnome() : Race()
  {
    this->class_inheritance.push_back(119);
    this->name = "gnome";
    this->bonuses.abilities.intelligence = 1;
    this->bonuses.abilities.wisdom = -1;
    this->bonuses.thief_abilities.find_traps = 10;
    this->bonuses.thief_abilities.open_locks = 5;
    this->bonuses.thief_abilities.pick_pockets = 0;
    this->bonuses.thief_abilities.stealth = 5;
    
    this->specialisations = {ILLUSION};
    
    this->allowed_classes =
      {{PROTOTYPE(Fighter)},
       {PROTOTYPE(Thief)},
       {PROTOTYPE(Cleric)},
       {PROTOTYPE(Mage)}, {PROTOTYPE(Sorcerer)},
       {PROTOTYPE(Fighter), PROTOTYPE(Thief)},
       {PROTOTYPE(Fighter), PROTOTYPE(Cleric)},
       {PROTOTYPE(Fighter), PROTOTYPE(Druid)},
       {PROTOTYPE(Fighter), PROTOTYPE(Mage)},
       {PROTOTYPE(Mage), PROTOTYPE(Cleric)},
       {PROTOTYPE(Ranger), PROTOTYPE(Cleric)},
       {PROTOTYPE(Fighter), PROTOTYPE(Mage), PROTOTYPE(Thief)},
       {PROTOTYPE(Fighter), PROTOTYPE(Mage), PROTOTYPE(Cleric)}};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Gnome::Gnome(const Gnome& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Gnome::Gnome(Gnome& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Gnome::Gnome(Gnome&& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Gnome::fork() const
  {
    return (Object*)(new Gnome(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Gnome::~Gnome()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Gnome& Gnome::operator =(const Gnome& original)
  {
    Race::__copy__((Race&)*this, (Race&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Gnome& Gnome::operator =(Gnome& original)
  {
    Race::__copy__((Race&)*this, (Race&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Gnome& Gnome::operator =(Gnome&& original)
  {
    std::swap((Race&)*this, (Race&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Gnome::operator ==(const Gnome& other) const
  {
    if ((Race&)(*this) != (Race&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Gnome::operator !=(const Gnome& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Gnome::__copy__(Gnome& self, const Gnome& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Gnome::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Race>()(*this);
    return rc;
  }
  
}

