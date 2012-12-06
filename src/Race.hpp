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
#ifndef __GUARD_RACE_HPP__
#define __GUARD_RACE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"



#include "Class.hpp"
#include "MagicSchool.hpp"
#include "AbilityBonus.hpp"


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
   * Race class
   */
  class Race: public Object
  {
  public:
    /**
     * The name of the race
     */
    std::string name;
    
    /**
     * Allowed classes for the race
     */
    std::vector<std::vector<Class>> allowed_classes;
    
    /**
     * At which level the dual class is allowed, use 2³¹ − 1 for never
     */
    short dualclass_level;
    
    /**
     * Allowed magic specialisations
     */
    std::vector<MagicSchool> specialisations;
    
    /**
     * Bonuses for the race
     */
    AbilityBonus bonuses;
    
    
    
    /**
     * Construction
     */
    Race();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Race(const Race& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Race(Race& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Race(Race&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Race();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Race& operator =(const Race& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Race& operator =(Race& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Race& operator =(Race&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Race& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Race& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Race& self, const Race& original);
    
    
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
  class hash<tbrpg::Race>
  {
  public:
    size_t operator()(const tbrpg::Race& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_RACE_HPP__

