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
#ifndef __GUARD_SPLINTMAIL_HPP__
#define __GUARD_SPLINTMAIL_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "BodyArmour.hpp"
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
   * Splint mail item clss
   */
  class SplintMail: public BodyArmour
  {
  public:
    /**
     * Construction
     */
    SplintMail();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SplintMail(const SplintMail& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    SplintMail(SplintMail& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    SplintMail(SplintMail&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~SplintMail();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SplintMail& operator =(const SplintMail& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual SplintMail& operator =(SplintMail& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual SplintMail& operator =(SplintMail&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const SplintMail& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const SplintMail& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(SplintMail& self, const SplintMail& original);
    
    
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
  class hash<tbrpg::SplintMail>
  {
  public:
    size_t operator()(const tbrpg::SplintMail& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::SplintMail*>
  {
  public:
    size_t operator()(tbrpg::SplintMail* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_SPLINTMAIL_HPP__

