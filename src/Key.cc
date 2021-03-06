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
#include "Key.hpp"


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
  Key::Key() : Item(), QuestItem()
  {
    this->class_inheritance.push_back(92);
    this->interface_inheritance.push_back("QuestItem");
    this->name = "key";
    this->weight = 5;
    this->unit_value = -1;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Key::Key(const Key& original) : Item(original), QuestItem(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Key::Key(Key& original) : Item(original), QuestItem(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Key::Key(Key&& original) : Item(original), QuestItem(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Key::fork() const
  {
    return (Object*)(new Key(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Key::~Key()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Key& Key::operator =(const Key& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    QuestItem::__copy__((QuestItem&)*this, (QuestItem&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Key& Key::operator =(Key& original)
  {
    Item::__copy__((Item&)*this, (Item&)original);
    QuestItem::__copy__((QuestItem&)*this, (QuestItem&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Key& Key::operator =(Key&& original)
  {
    std::swap((Item&)*this, (Item&)original);
    std::swap((QuestItem&)*this, (QuestItem&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Key::operator ==(const Key& other) const
  {
    if ((Item&)(*this) != (Item&)other)  return false;
    if ((QuestItem&)(*this) != (QuestItem&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Key::operator !=(const Key& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Key::__copy__(Key& self, const Key& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Key::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Item>()(*this);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<QuestItem>()(*this);
    return rc;
  }
  
}

