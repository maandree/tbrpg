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
#ifndef __GUARD_PARTY_HPP__
#define __GUARD_PARTY_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"
#include "Character.hpp"


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
   * The players' party
   */
  class Party: public Object
  {
  public:
    /**
     * The party's reputation
     */
    int reputation;
    
    /**
     * The characters in the party
     */
    std::vector<Character*> characters;
    
    
    
    /**
     * Construction
     */
    Party();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Party(const Party& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Party(Party& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Party(Party&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Party();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Party& operator =(const Party& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Party& operator =(Party& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Party& operator =(Party&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Party& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Party& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Party& self, const Party& original);
    
    
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
  class hash<tbrpg::Party>
  {
  public:
    size_t operator()(const tbrpg::Party& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Party*>
  {
  public:
    size_t operator()(tbrpg::Party* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_PARTY_HPP__

