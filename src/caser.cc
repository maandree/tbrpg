// -*- mode: c++ , coding: utf-8 -*-
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
#include "caser.hpp"


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
  /* Text case modifier  */
  
  
  #define __lowercase(c)  ((('A' <= c) && (c <= 'Z')) ? (c |  0x20) : c)
  #define __uppercase(c)  ((('a' <= c) && (c <= 'z')) ? (c & ~0x20) : c)
  #define __wordsep(c)    ((c == ' ') || (c == '-'))
  #define __sentsep(c)    ((c == '.') || (c == '!') || (c == '?'))
  
  
  /**
   * Change casing
   * 
   * @param   text    The text
   * @param   casing  The new casing
   * @return          The text with the new casing
   */
  std::string changeCase(std::string& text, Case casing)
  {
    const char* str = text.c_str();
    char* _str = (char*)malloc(text.size() + 1);
    size_t n = text.size();
    
    if (casing == LOWER_CASE)
      while ((*_str++ = __lowercase(*str)))
	str++;
    else if (casing == SENTENCE_CASE)
      {
	bool insent = false;
	while ((*_str = *str++))
	  {
	    if (__sentsep(*_str))
	      insent = false;
	    *_str = insent ? __lowercase(*_str) : __uppercase(*_str);
	    if (__wordsep(*_str) == false)
	      insent = true;
	    _str++;
	  }
	_str++;
      }
    else if (casing == CAMEL_CASE)
      {
	bool inword = false;
	while ((*_str = *str++))
	  {
	    if (__wordsep(*_str))
	      inword = false;
	    *_str = inword ? __lowercase(*_str) : __uppercase(*_str);
	    if (__wordsep(*_str) == false)
	      inword = true;
	    _str++;
	  }
	_str++;
      }
    else
      while ((*_str++ = __uppercase(*str)))
	str++;
    
    _str -= n + 1;
    std::string rc = std::string(_str);
    free(_str);
    return rc;
  }
  
  
  #undef __lowercase
  #undef __uppercase
  #undef __wordsep
  #undef __sentsep
  
}

