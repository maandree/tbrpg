// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "SpellProgression.hpp"


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
  SpellProgression::SpellProgression() : Object()
  {
    this->class_inheritance.push_back(10);
    this->wizard_slots = new std::vector<std::vector<int>*>();
    this->priest_slots = new std::vector<std::vector<int>*>();
    this->wizard_levels = new std::vector<int>();
    this->priest_levels = new std::vector<int>();
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellProgression::SpellProgression(const SpellProgression& original) : Object(original)
  {
    this->wizard_slots = new std::vector<std::vector<int>*>();
    this->priest_slots = new std::vector<std::vector<int>*>();
    for (std::vector<int>* elem : *(original.wizard_slots))
      this->wizard_slots->push_back(new std::vector<int>(*elem));
    for (std::vector<int>* elem : *(original.priest_slots))
      this->priest_slots->push_back(new std::vector<int>(*elem));
    this->wizard_levels = new std::vector<int>(*(original.wizard_levels));
    this->priest_levels = new std::vector<int>(*(original.priest_levels));
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  SpellProgression::SpellProgression(SpellProgression& original) : Object(original)
  {
    this->wizard_slots = new std::vector<std::vector<int>*>();
    this->priest_slots = new std::vector<std::vector<int>*>();
    for (std::vector<int>* elem : *(original.wizard_slots))
      this->wizard_slots->push_back(new std::vector<int>(*elem));
    for (std::vector<int>* elem : *(original.priest_slots))
      this->priest_slots->push_back(new std::vector<int>(*elem));
    this->wizard_levels = new std::vector<int>(*(original.wizard_levels));
    this->priest_levels = new std::vector<int>(*(original.priest_levels));
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  SpellProgression::SpellProgression(SpellProgression&& original) : Object(original)
  {
    std::swap(this->wizard_slots, original.wizard_slots);
    std::swap(this->priest_slots, original.priest_slots);
    std::swap(this->wizard_levels, original.wizard_levels);
    std::swap(this->priest_levels, original.priest_levels);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* SpellProgression::fork() const
  {
    return (Object*)(new SpellProgression(*this));
  }
  
  
  
  /**
   * Destructor
   */
  SpellProgression::~SpellProgression()
  {
    for (std::vector<int>* elem : *(this->wizard_slots))
      delete elem;
    for (std::vector<int>* elem : *(this->priest_slots))
      delete elem;
    delete this->wizard_slots;
    delete this->priest_slots;
    delete this->wizard_levels;
    delete this->priest_levels;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellProgression& SpellProgression::operator =(const SpellProgression& original)
  {
    for (std::vector<int>* elem : *(this->wizard_slots))
      delete elem;
    for (std::vector<int>* elem : *(this->priest_slots))
      delete elem;
    delete this->wizard_slots;
    delete this->priest_slots;
    delete this->wizard_levels;
    delete this->priest_levels;
    Object::__copy__((Object&)*this, (Object&)original);
    this->wizard_slots = new std::vector<std::vector<int>*>();
    this->priest_slots = new std::vector<std::vector<int>*>();
    for (std::vector<int>* elem : *(original.wizard_slots))
      this->wizard_slots->push_back(new std::vector<int>(*elem));
    for (std::vector<int>* elem : *(original.priest_slots))
      this->priest_slots->push_back(new std::vector<int>(*elem));
    this->wizard_levels = new std::vector<int>(*(original.wizard_levels));
    this->priest_levels = new std::vector<int>(*(original.priest_levels));
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  SpellProgression& SpellProgression::operator =(SpellProgression& original)
  {
    for (std::vector<int>* elem : *(this->wizard_slots))
      delete elem;
    for (std::vector<int>* elem : *(this->priest_slots))
      delete elem;
    delete this->wizard_slots;
    delete this->priest_slots;
    delete this->wizard_levels;
    delete this->priest_levels;
    Object::__copy__((Object&)*this, (Object&)original);
    this->wizard_slots = new std::vector<std::vector<int>*>();
    this->priest_slots = new std::vector<std::vector<int>*>();
    for (std::vector<int>* elem : *(original.wizard_slots))
      this->wizard_slots->push_back(new std::vector<int>(*elem));
    for (std::vector<int>* elem : *(original.priest_slots))
      this->priest_slots->push_back(new std::vector<int>(*elem));
    this->wizard_levels = new std::vector<int>(*(original.wizard_levels));
    this->priest_levels = new std::vector<int>(*(original.priest_levels));
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  SpellProgression& SpellProgression::operator =(SpellProgression&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->wizard_slots, original.wizard_slots);
    std::swap(this->priest_slots, original.priest_slots);
    std::swap(this->wizard_levels, original.wizard_levels);
    std::swap(this->priest_levels, original.priest_levels);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool SpellProgression::operator ==(const SpellProgression& other) const
  {
    if (this->wizard_slots != other.wizard_slots)  return false;
    if (this->priest_slots != other.priest_slots)  return false;
    if (this->wizard_levels != other.wizard_levels)  return false;
    if (this->priest_levels != other.priest_levels)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool SpellProgression::operator !=(const SpellProgression& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void SpellProgression::__copy__(SpellProgression& self, const SpellProgression& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t SpellProgression::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<std::vector<int>*>*>()(this->wizard_slots);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::vector<std::vector<int>*>*>()(this->priest_slots);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::vector<int>*>()(this->wizard_levels);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<int>*>()(this->priest_levels);
    return rc;
  }
  
}

