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
#ifndef __GUARD_QUESTITEM_HPP__
#define __GUARD_QUESTITEM_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "hash.hpp"

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
   * Quest item class
   */
  class QuestItem
  {
  public:
    /**
     * A unique number for the item that the game senario can use for identifying quest items
     */
    int id;
    
    
    
    /**
     * Construction
     */
    QuestItem();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    QuestItem(const QuestItem& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    QuestItem(QuestItem& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    QuestItem(QuestItem&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~QuestItem();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual QuestItem& operator =(const QuestItem& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual QuestItem& operator =(QuestItem& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual QuestItem& operator =(QuestItem&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const QuestItem& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const QuestItem& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(QuestItem& self, const QuestItem& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::QuestItem>
  {
  public:
    size_t operator()(const tbrpg::QuestItem& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::QuestItem*>
  {
  public:
    size_t operator()(tbrpg::QuestItem* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_QUESTITEM_HPP__

