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
#ifndef __GUARD_ACTIONSLOTCHART_HPP__
#define __GUARD_ACTIONSLOTCHART_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"
#include "Class.hpp"
#include "ActionSlot.hpp"
#include "Fighter.hpp"
#include "Ranger.hpp"
#include "Paladin.hpp"
#include "Thief.hpp"
#include "Bard.hpp"
#include "Cleric.hpp"
#include "Druid.hpp"
#include "Mage.hpp"
#include "Sorcerer.hpp"


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
   * Prestige class–action slot cart
   */
  class ActionSlotChart: public Object
  {
  public:
    /**
     * Prestige class to OR:able index map
     */
    std::unordered_map<Class*, long long> index_map;
    
    /**
     * Index combination to action slots map
     */
    std::unordered_map<long long, std::vector<ActionSlot>> slot_map;
    
    
    
    /**
     * Construction
     */
    ActionSlotChart();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlotChart(const ActionSlotChart& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlotChart(ActionSlotChart& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    ActionSlotChart(ActionSlotChart&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~ActionSlotChart();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ActionSlotChart& operator =(const ActionSlotChart& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual ActionSlotChart& operator =(ActionSlotChart& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual ActionSlotChart& operator =(ActionSlotChart&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const ActionSlotChart& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const ActionSlotChart& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(ActionSlotChart& self, const ActionSlotChart& original);
    
    
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
  class hash<tbrpg::ActionSlotChart>
  {
  public:
    size_t operator()(const tbrpg::ActionSlotChart& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::ActionSlotChart*>
  {
  public:
    size_t operator()(tbrpg::ActionSlotChart* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_ACTIONSLOTCHART_HPP__

