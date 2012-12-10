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
#include "cleaner.hpp"


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
   * Clean system
   */
  void cleaner::clean()
  {
    for (void* item : this->clean_list_free)
      free(item);
    this->clean_list_free = std::vector<void*>();
    
    for (Object* item : this->clean_list_delete)
      delete item;
    this->clean_list_delete = std::vector<Object*>();
    
    for (Object* item : this->clean_list_array)
      delete[] item;
    this->clean_list_array = std::vector<Object*>();
  }
  
  /**
   * Add instance that that should be cleaned using `free()`
   * 
   * @param  obj  The object
   */
  void cleaner::enqueueFree(void* object)
  {
    this->clean_list_free.push_back(object);
  }
  
  /**
   * Add instance that that should be cleaned using `delete`
   * 
   * @param  obj  The object
   */
  void cleaner::enqueueDelete(Object* object)
  {
    this->clean_list_delete.push_back(object);
  }
  
  /**
   * Add instance that that should be cleaned using `delete[]`
   * 
   * @param  obj  The object
   */
  void cleaner::enqueueDeleteArray(Object* object)
  {
    this->clean_list_array.push_back(object);
  }
  
}

