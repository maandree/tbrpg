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
#ifndef __GUARD_CORPSEMAKER_HPP__
#define __GUARD_CORPSEMAKER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "Body.hpp"
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
   * Corpse maker class
   */
  class CorpseMaker: public Object
  {
  public:
    /**
     * Additional weight for strenght scores
     */
    int* strenght_weight;
    
    /**
     * Additional weight for strenght scores at 18
     */
    int* strenght18_weight;
    
    /**
     * Additional weight for constitution scores
     */
    int* constitution_weight;
    
    
    
    /**
     * Construction
     */
    CorpseMaker();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CorpseMaker(const CorpseMaker& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CorpseMaker(CorpseMaker& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    CorpseMaker(CorpseMaker&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~CorpseMaker();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CorpseMaker& operator =(const CorpseMaker& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CorpseMaker& operator =(CorpseMaker& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual CorpseMaker& operator =(CorpseMaker&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const CorpseMaker& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const CorpseMaker& other) const;
    
    
    /**
     * Makes a corpse for a character
     * 
     * @param   character  The dead character
     * @return             The corpse of the character
     */
    virtual Body makeCorpse(Character& character) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(CorpseMaker& self, const CorpseMaker& original);
    
    
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
  class hash<tbrpg::CorpseMaker>
  {
  public:
    size_t operator()(const tbrpg::CorpseMaker& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::CorpseMaker*>
  {
  public:
    size_t operator()(tbrpg::CorpseMaker* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_CORPSEMAKER_HPP__

