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
#ifndef __GUARD_BUCKLER_HPP__
#define __GUARD_BUCKLER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Shield.hpp"



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
   * Buckler item class
   */
  class Buckler: public Shield
  {
  public:
    /**
     * Construction
     */
    Buckler();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Buckler(const Buckler& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Buckler(Buckler& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Buckler(Buckler&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Buckler();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Buckler& operator =(const Buckler& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Buckler& operator =(Buckler& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Buckler& operator =(Buckler&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Buckler& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Buckler& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Buckler& self, const Buckler& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    virtual size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Buckler>
  {
  public:
    size_t operator()(const tbrpg::Buckler& elem) const
    {
      return dynamic_cast<const tbrpg::Buckler*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::Buckler*>
  {
  public:
    size_t operator()(tbrpg::Buckler* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<tbrpg::Buckler*>(elem)->hash();
    }
  };
}


#endif//__GUARD_BUCKLER_HPP__

