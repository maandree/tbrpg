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
#ifndef __GUARD_PROTOTYPE_HPP__
#define __GUARD_PROTOTYPE_HPP__


#include <stdlib.h>
#include <unordered_map>

#include "cleaner.hpp"


/**
 * Get the prototype for a class
 * 
 * @param   C  The class
 * @return     The prototype for a class
 */
#define PROTOTYPE(C)  ((C&)*(prototype<C>::get()))


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
   * Class prototypes
   * 
   * @param  <C>  The class
   */
  template<class C>
  class prototype
  {
  public:
    /**
     * Get the prototype for a class
     * 
     * @return  The prototype for a class
     */
    static C* get()
    {
      static C* instance = (C*)(cleaner::getInstance().enqueueDelete(new C()));
      return instance;
    }
    
  };
}


#endif//__GUARD_PROTOTYPE_HPP__
