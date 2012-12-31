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
#include "Elf.hpp"


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
  Elf::Elf() : Race()
  {
    this->class_inheritance.push_back(113);
    this->name = "elf";
    this->bonuses.bonuses.detect_doors = 0.20;
    this->bonuses.abilities.dexterity = 1;
    this->bonuses.abilities.constitution = -1;
    this->bonuses.thief_abilities.find_traps = 0;
    this->bonuses.thief_abilities.open_locks = -5;
    this->bonuses.thief_abilities.pick_pockets = 5;
    this->bonuses.thief_abilities.stealth = 10;
    
    this->allowed_classes =
      {{PROTOTYPE(Fighter)}, {PROTOTYPE(Ranger)},
       {PROTOTYPE(Thief)},
       {PROTOTYPE(Cleric)},
       {PROTOTYPE(Mage)}, {PROTOTYPE(Sorcerer)},
       {PROTOTYPE(Fighter), PROTOTYPE(Thief)},
       {PROTOTYPE(Fighter), PROTOTYPE(Mage)},
       {PROTOTYPE(Thief), PROTOTYPE(Mage)},
       {PROTOTYPE(Fighter), PROTOTYPE(Mage), PROTOTYPE(Thief)}};
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Elf::Elf(const Elf& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Elf::Elf(Elf& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Elf::Elf(Elf&& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Elf::fork() const
  {
    return (Object*)(new Elf(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Elf::~Elf()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Elf& Elf::operator =(const Elf& original)
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
  Elf& Elf::operator =(Elf& original)
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
  Elf& Elf::operator =(Elf&& original)
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
  bool Elf::operator ==(const Elf& other) const
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
  bool Elf::operator !=(const Elf& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Elf::__copy__(Elf& self, const Elf& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Elf::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Race>()(*this);
    return rc;
  }
  
}

