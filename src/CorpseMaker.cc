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
#include "CorpseMaker.hpp"


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
  CorpseMaker::CorpseMaker() : Object()
  {
    this->class_inheritance.push_back(138);
    this->strenght_weight = new int[26];
    this->strenght18_weight = new int[101];
    this->constitution_weight = new int[26];
    
    for (long i = 0; i <= 25; i++)
	this->constitution_weight[i] = 500 * i;
    int w = 0;
    for (long i = 0; i <= 18; i++)
      {
	this->strenght_weight[i] = w;
	w += 500;
      }
    for (long i = 0; i <= 100; i++)
      {
	this->strenght18_weight[i] = w;
	w += 50;
      }
    w += 500;
    for (long i = 19; i <= 25; i++)
      {
	this->strenght_weight[i] = w;
	w += 500;
      }
    this->strenght_weight[18] = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(const CorpseMaker& original) : Object(original)
  {
    this->strenght_weight = new int[26];
    this->strenght18_weight = new int[101];
    this->constitution_weight = new int[26];
    for (long i = 0; i < 26; i++)
      {
	this->strenght_weight[i] = original.strenght_weight[i];
	this->constitution_weight[i] = original.constitution_weight[i];
      }
    for (long i = 0; i < 101; i++)
      this->strenght18_weight[i] = original.strenght18_weight[i];
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(CorpseMaker& original) : Object(original)
  {
    this->strenght_weight = new int[26];
    this->strenght18_weight = new int[101];
    this->constitution_weight = new int[26];
    for (long i = 0; i < 26; i++)
      {
	this->strenght_weight[i] = original.strenght_weight[i];
	this->constitution_weight[i] = original.constitution_weight[i];
      }
    for (long i = 0; i < 101; i++)
      this->strenght18_weight[i] = original.strenght18_weight[i];
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  CorpseMaker::CorpseMaker(CorpseMaker&& original) : Object(original)
  {
    this->strenght_weight = new int[26];
    this->strenght18_weight = new int[101];
    this->constitution_weight = new int[26];
    std::swap(this->strenght_weight, original.strenght_weight);
    std::swap(this->strenght18_weight, original.strenght18_weight);
    std::swap(this->constitution_weight, original.constitution_weight);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* CorpseMaker::fork() const
  {
    return (Object*)(new CorpseMaker(*this));
  }
  
  
  
  /**
   * Destructor
   */
  CorpseMaker::~CorpseMaker()
  {
    delete[] this->strenght_weight;
    delete[] this->strenght18_weight;
    delete[] this->constitution_weight;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(const CorpseMaker& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    for (long i = 0; i < 26; i++)
      {
	this->strenght_weight[i] = original.strenght_weight[i];
	this->constitution_weight[i] = original.constitution_weight[i];
      }
    for (long i = 0; i < 101; i++)
      this->strenght18_weight[i] = original.strenght18_weight[i];
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(CorpseMaker& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    for (long i = 0; i < 26; i++)
      {
	this->strenght_weight[i] = original.strenght_weight[i];
	this->constitution_weight[i] = original.constitution_weight[i];
      }
    for (long i = 0; i < 101; i++)
      this->strenght18_weight[i] = original.strenght18_weight[i];
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  CorpseMaker& CorpseMaker::operator =(CorpseMaker&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->strenght_weight, original.strenght_weight);
    std::swap(this->strenght18_weight, original.strenght18_weight);
    std::swap(this->constitution_weight, original.constitution_weight);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool CorpseMaker::operator ==(const CorpseMaker& other) const
  {
    for (long i = 0; i <= 25; i++)
      {
	if (this->strenght_weight[i] != other.strenght_weight[i])  return false;
	if (this->constitution_weight[i] != other.constitution_weight[i])  return false;
      }
    for (long i = 0; i <= 100; i++)
      if (this->strenght18_weight[i] != other.strenght18_weight[i])  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool CorpseMaker::operator !=(const CorpseMaker& other) const
  {
    return (*this == other) == false;
  }
  
  
  /**
   * Makes a corpse for a character
   * 
   * @param   character  The dead character
   * @return             The corpse of the character
   */
  Body CorpseMaker::makeCorpse(Character& character) const
  {
    Body body = Body();
    body.character = &character;
    body.name += character.record.name;
    if (character.record.abilities.abilities.strength != 18)
      body.weight += this->strenght_weight[character.record.abilities.abilities.strength];
    if (character.record.abilities.abilities.strength == 18)
      body.weight += this->strenght18_weight[character.record.abilities.abilities.strength18];
    body.weight += this->constitution_weight[character.record.abilities.abilities.constitution];
    return body;
  }
  
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void CorpseMaker::__copy__(CorpseMaker& self, const CorpseMaker& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t CorpseMaker::hash() const
  {
    size_t rc = 0;
    for (long i = 0; i <= 25; i++)
      {
	rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
	rc += std::hash<int>()(this->strenght_weight[i]);
	rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
	rc += std::hash<int>()(this->constitution_weight[i]);
      }
    for (long i = 0; i <= 100; i++)
      {
	rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
	rc += std::hash<int>()(this->strenght18_weight[i]);
      }
    return rc;
  }
  
}

