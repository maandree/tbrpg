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
#ifndef __GUARD_BLUNTWEAPON_HPP__
#define __GUARD_BLUNTWEAPON_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "OneHandedMelee.hpp"



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
   * Blunt weapon item class
   */
  class BluntWeapon: public OneHandedMelee
  {
  public:
    /**
     * Construction
     */
    BluntWeapon();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    BluntWeapon(const BluntWeapon& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    BluntWeapon(BluntWeapon& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    BluntWeapon(BluntWeapon&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~BluntWeapon();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual BluntWeapon& operator =(const BluntWeapon& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual BluntWeapon& operator =(BluntWeapon& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual BluntWeapon& operator =(BluntWeapon&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const BluntWeapon& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const BluntWeapon& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(BluntWeapon& self, const BluntWeapon& original);
    
    
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
  class hash<tbrpg::BluntWeapon>
  {
  public:
    size_t operator()(const tbrpg::BluntWeapon& elem) const
    {
      return dynamic_cast<BluntWeapon*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::BluntWeapon*>
  {
  public:
    size_t operator()(tbrpg::BluntWeapon* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<BluntWeapon*>(elem)->hash();
    }
  };
}


#endif//__GUARD_BLUNTWEAPON_HPP__

