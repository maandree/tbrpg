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
#include "QuestItem.hpp"


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
  QuestItem::QuestItem()
  {
    this->id = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(const QuestItem& original)
  {
    this->id = original.id;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(QuestItem& original)
  {
    this->id = original.id;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(QuestItem&& original)
  {
    std::swap(this->id, original.id);
  }
  
  
  
  /**
   * Destructor
   */
  QuestItem::~QuestItem()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(const QuestItem& original)
  {
    this->id = original.id;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(QuestItem& original)
  {
    this->id = original.id;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(QuestItem&& original)
  {
    std::swap(this->id, original.id);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool QuestItem::operator ==(const QuestItem& other) const
  {
    if (this->id != other.id)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool QuestItem::operator !=(const QuestItem& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void QuestItem::__copy__(QuestItem& self, const QuestItem& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t QuestItem::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->id);
    return rc;
  }
  
}

