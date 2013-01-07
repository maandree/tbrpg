// -*- mode: c++ , coding: utf-8 -*-
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
#include "HalfElf.hpp"


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
  HalfElf::HalfElf() : Race()
  {
    this->class_inheritance.push_back(116);
    this->name = "half-elf";
    this->bonuses.thief_abilities.find_traps = 0;
    this->bonuses.thief_abilities.open_locks = 0;
    this->bonuses.thief_abilities.pick_pockets = 10;
    this->bonuses.thief_abilities.stealth = 5;
    
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Ranger)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Thief)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Bard)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Cleric)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Druid)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Mage)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Sorcerer)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Thief)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Cleric)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Druid)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Mage)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Mage), &PROTOTYPE(Cleric)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Mage), &PROTOTYPE(Thief)}));
    this->allowed_classes->push_back(new std::vector<Class*>({&PROTOTYPE(Fighter), &PROTOTYPE(Mage), &PROTOTYPE(Cleric)}));
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HalfElf::HalfElf(const HalfElf& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  HalfElf::HalfElf(HalfElf& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  HalfElf::HalfElf(HalfElf&& original) : Race(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* HalfElf::fork() const
  {
    return (Object*)(new HalfElf(*this));
  }
  
  
  
  /**
   * Destructor
   */
  HalfElf::~HalfElf()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  HalfElf& HalfElf::operator =(const HalfElf& original)
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
  HalfElf& HalfElf::operator =(HalfElf& original)
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
  HalfElf& HalfElf::operator =(HalfElf&& original)
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
  bool HalfElf::operator ==(const HalfElf& other) const
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
  bool HalfElf::operator !=(const HalfElf& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void HalfElf::__copy__(HalfElf& self, const HalfElf& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t HalfElf::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Race>()(*this);
    return rc;
  }
  
}

