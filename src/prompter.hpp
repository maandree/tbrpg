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
#ifndef __GUARD_PROMPTER_HPP__
#define __GUARD_PROMPTER_HPP__


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stropts.h>


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
  /* Enhanced command line prompter */
  
  
  /**
   * UCS character type
   */
  typedef signed int /* sic */  symbol;
  
  
  /**
   * Prompter internal data, some information is stored between promptings
   */
  struct
  {
    /**
     * Before point size
     */
    long bpz;
    
    /**
     * After point size
     */
    long apz;
    
    /**
     * Before point buffer
     */
    symbol* bp;
    
    /**
     * After point buffer
     */
    symbol* ap;
    
    /**
     * Temporary buffer
     */
    symbol* tmp;
    
    /**
     * Escape sequence buffer
     */
    char* esc;
    
    /**
     * Current byte
     */
    char c;
    
    /**
     * Whether the prompter is still taking input
     */
    bool reading;
    
    /**
     * Assigned characters before point
     */
    long before;
    
    /**
     * Assigned characters after point
     */
    long after;
    
    /**
     * The mark position + 1, negated if deactivated, and zero if not set
     */
    long mark;
    
    /**
     * Whether the prompter was interrupted
     */
    bool aborted;
    
    /**
     * Escape sequence buffer pointer
     */
    long escptr;
    
    /**
     * Escape sequence buffer size
     */
    long escsize;
    
    /**
     * Whether override mode is enabled
     */
    bool override = false;
    
    /**
     * Whether ignore NUL mode is enabled, C-c can used instead
     */
    bool ignoreNUL;
    
    /**
     * Whether override mode is enabled
     */
    bool controlX;
    
    /**
     * Complete ANSI escape sequence
     */
    std::string ansi;
    
    /**
     * Possible alternatives
     */
    std::vector<std::string> alternatives;
    
  } prompterdata;
  
  
  
  /**
   * No operator
   */
  void prompt_noop();
  
  /**
   * Complete prompting
   */
  void prompt_done();
  
  /**
   * Prompt the user for an arbitrary string
   * 
   * @param   instruction  Instruction for the user
   * @param   previous     Previous entry hook
   * @param   next         Next entry hook
   * @param   done         Entry done hook
   * @return               The string provided by the user, empty string is returned if aborted
   */
  std::string promptArbitrary(std::string instruction, void (*previous)() = prompt_noop, void (*next)() = prompt_noop, void (*done)() = prompt_done());
  
  /**
   * Prompt the user for an alternative and return the index
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptIndex(std::string instruction, std::vector<std::string> alternatives, void (*previous)() = prompt_noop, void (*next)() = prompt_noop);
  
  /**
   * Prompt the user for an alternative
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The selected alternative
   */
  std::string promptList(std::string instruction, std::vector<std::string> alternatives, void (*previous)() = prompt_noop, void (*next)() = prompt_noop);
  
  /**
   * Prompt the user for a file
   * 
   * @param   instruction   Instruction for the user
   * @param   loadfile      Whether to load the file
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The selected file, or if loadfile is true, its content
   */
  std::string promptFile(std::string instruction, bool loadfile, void (*previous)() = prompt_noop, void (*next)() = prompt_noop);
  
  /**
   * Print a list in columns
   * 
   * @param  items  The items to print
   */
  void columnate(std::vector<std::string> items);
  
}


#endif//__GUARD_PROMPTER_HPP__

