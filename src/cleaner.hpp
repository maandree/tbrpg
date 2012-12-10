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
#ifndef __GUARD_CLEANER_HPP__
#define __GUARD_CLEANER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>


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
   * Cleaner class
   */
  class cleaner
  {
  private:
    /**
     * Objects to free
     */
    static std::vector<void*> clean_list_free;
    
    /**
     * Objects to delete
     */
    static std::vector<void*> clean_list_delete;
    
    /**
     * Objects to delete[]
     */
    static std::vector<void*> clean_list_array;
    
    
  public:
    /**
     * Clean system
     */
    static void clean();
    
    /**
     * Add instance that that should be cleaned using `free()`
     * 
     * @param  obj  The object
     */
    static void enqueueFree(void* object);
    
    /**
     * Add instance that that should be cleaned using `delete`
     * 
     * @param  obj  The object
     */
    static void enqueueDelete(void* object);
    
    /**
     * Add instance that that should be cleaned using `delete[]`
     * 
     * @param  obj  The object
     */
    static void enqueueDeleteArray(void* object);
    
    
  };
}


#endif//__GUARD_CLEANER_HPP__

