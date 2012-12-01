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
   * Prompter internal data, some information is stored between promptings
   */
  struct
  {
    long bpz;
    long apz;
    char* bp;
    char* ap;
    char* tmp;
    char* esc;
    char c;
    bool reading;
    long before;
    long after;
    bool aborted;
    long escptr;
    long escsize;
    bool override;
    bool ignoreNUL;
    bool controlX;
    std::string ansi;
  } prompterdata;
  
  
  /**
   * Prompt the user for an arbitrary string
   * 
   * @param   instruction  Instruction for the user
   * @return               The string provided by the user, empty string is returned if aborted
   */
  std::string promptArbitrary(std::string instruction);
  
}


#endif//__GUARD_PROMPTER_HPP__

