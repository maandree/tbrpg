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
#include "Abilities.hpp"


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
  Abilities::Abilities() : Object()
  {
    ////TODO implement constructor
    //this->strength = 0;
    //this->strength18 = 0;
    //this->constitution = 0;
    //this->dexterity = 0;
    //this->intelligence = 0;
    //this->wisdom = 0;
    //this->charisma = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Abilities::Abilities(const Abilities& original) : Object(original)
  {
    (void) original;
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->constitution = original.constitution;
    this->dexterity = original.dexterity;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Abilities::Abilities(Abilities& original) : Object(original)
  {
    (void) original;
    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->constitution = original.constitution;
    this->dexterity = original.dexterity;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Abilities::Abilities(Abilities&& original) : Object(original)
  {
    (void) original;
    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->constitution, original.constitution);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
  }
  
  
  
  /**
   * Destructor
   */
  Abilities::~Abilities()
  {
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Abilities& Abilities::operator =(const Abilities& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->constitution = original.constitution;
    this->dexterity = original.dexterity;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Abilities& Abilities::operator =(Abilities& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);
    Object::__copy__((Object&)*this, (Object&)original);    this->strength = original.strength;
    this->strength18 = original.strength18;
    this->constitution = original.constitution;
    this->dexterity = original.dexterity;
    this->intelligence = original.intelligence;
    this->wisdom = original.wisdom;
    this->charisma = original.charisma;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Abilities& Abilities::operator =(Abilities&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);
    std::swap((Object&)*this, (Object&)original);    std::swap(this->strength, original.strength);
    std::swap(this->strength18, original.strength18);
    std::swap(this->constitution, original.constitution);
    std::swap(this->dexterity, original.dexterity);
    std::swap(this->intelligence, original.intelligence);
    std::swap(this->wisdom, original.wisdom);
    std::swap(this->charisma, original.charisma);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Abilities::operator ==(const Abilities& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Abilities::__copy__(Abilities& self, const Abilities& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Abilities::hash() const
  {
    return (size_t)this;
  }
  
}

