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
#include "InventorExaminor.hpp"


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
  #define  __store_tty()		       \
    struct termios saved_stty;                 \
    struct termios stty;                       \
    tcgetattr(STDIN_FILENO, &saved_stty);      \
    tcgetattr(STDIN_FILENO, &stty);            \
    stty.c_lflag &= ~(ICANON | ECHO | ISIG);   \
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &stty)
    
  #define __restore_tty()  \
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty)
  
  #define  ESC  "\033"  /* since \e generates a non-ISO-standard warning */
  #define  CSI  ESC "["
  
  
  
  /**
   * Construction
   */
  InventoryExaminor::InventoryExaminor()
  {
    // Do nothing
  }
  
  
  
  /**
   * Destructor
   */
  InventoryExaminor::~InventoryExaminor()
  {
    // Do nothing
  }
  
  
  
  /**
   * Examine a characters inventory
   * 
   * @param  character   The index of the active character
   * @param  characters  The party members
   */
  void InventoryExaminor::examine(long character, GameCharacter* characters) const
  {
    if (read(STDIN_FILENO, &(prompterdata.c), 1) <= 0)
      prompterdata.c = '\n';
  }
  
}

