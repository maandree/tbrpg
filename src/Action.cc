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
#include "Action.hpp"


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
  Action::Action() : Object()
  {
    this->class_inheritance.push_back(143);
    this->target = nullptr;
    this->spell = nullptr;
    this->item = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Action::Action(const Action& original) : Object(original)
  {
    this->target = original.target;
    this->spell = original.spell;
    this->item = original.item;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Action::Action(Action& original) : Object(original)
  {
    this->target = original.target;
    this->spell = original.spell;
    this->item = original.item;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Action::Action(Action&& original) : Object(original)
  {
    std::swap(this->target, original.target);
    std::swap(this->spell, original.spell);
    std::swap(this->item, original.item);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Action::fork() const
  {
    return (Object*)(new Action(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Action::~Action()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Action& Action::operator =(const Action& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->target = original.target;
    this->spell = original.spell;
    this->item = original.item;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Action& Action::operator =(Action& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->target = original.target;
    this->spell = original.spell;
    this->item = original.item;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Action& Action::operator =(Action&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->target, original.target);
    std::swap(this->spell, original.spell);
    std::swap(this->item, original.item);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Action::operator ==(const Action& other) const
  {
    if (this->target != other.target)  return false;
    if (this->spell != other.spell)  return false;
    if (this->item != other.item)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Action::operator !=(const Action& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Action::__copy__(Action& self, const Action& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Action::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Character*>()(this->target);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Spell*>()(this->spell);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<QuickItem*>()(this->item);
    return rc;
  }
  
}

