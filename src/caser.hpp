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
#ifndef __GUARD_CASER_HPP__
#define __GUARD_CASER_HPP__


#include <stdlib.h>
#include <string>


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
  /* Text case modifier */
  
  
  /**
   * The casing
   */
  enum Case
    {
      /**
       * case:d this way
       */
      LOWER_CASE,
      
      /**
       * Case:d this way
       */
      SENTENCE_CASE,
      
      /**
       * Case:d This Way
       */
      CAMEL_CASE,
      
      /**
       * CASE:D THIS WAY
       */
      UPPER_CASE
    };
  
  
  /**
   * Change casing
   * 
   * @param   text    The text
   * @param   casing  The new casing
   * @return          The text with the new casing
   */
  std::string changeCase(std::string& text, Case casing);
  
  /**
   * Change casing
   * 
   * @param   text    The text
   * @param   casing  The new casing
   * @return          The text with the new casing
   */
  inline std::string changeCase(const std::string& text, Case casing)
  {
    return changeCase((std::string&)text, casing);
  }
  
}


#endif//__GUARD_CASER_HPP__

