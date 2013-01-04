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
#ifndef __GUARD_ENTRANCE_HPP__
#define __GUARD_ENTRANCE_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"
#include "_MapMinor.hpp"


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
   * Connection between map areas
   */
  class Entrance: public Object
  {
  public:
    /**
     * Whether the entrance can be used
     */
    bool usable;
    
    /**
     * A description of what you see
     */
    std::string description;
    
    /**
     * The direction to the entrace
     */
    std::string direction;
    
    /**
     * The area to which the entrance leads
     */
    _MapMinor* leads_to;
    
    
    
    /**
     * Construction
     */
    Entrance();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(const Entrance& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(Entrance& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Entrance(Entrance&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Entrance();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Entrance& operator =(const Entrance& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Entrance& operator =(Entrance& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Entrance& operator =(Entrance&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Entrance& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Entrance& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Entrance& self, const Entrance& original);
    
    
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
  class hash<tbrpg::Entrance>
  {
  public:
    size_t operator()(const tbrpg::Entrance& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Entrance*>
  {
  public:
    size_t operator()(tbrpg::Entrance* elem) const
    {
       return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_ENTRANCE_HPP__

