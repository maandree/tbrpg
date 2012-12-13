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
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/stat.h>


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
   * UCS character type
   */
  typedef signed int symbol; /* sic, signed */
  
  
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
  std::string promptArbitrary(const std::string& instruction, void (*previous)(void) = prompt_noop, void (*next)(void) = prompt_noop, void (*done)(void) = prompt_done);
  
  /**
   * Prompt the user for an alternative and return the index
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptIndex(const std::string& instruction, const std::vector<std::string>& alternatives, void (*previous)(void) = prompt_noop, void (*next)(void) = prompt_noop);
  
  /**
   * Prompt the user for an alternative
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The selected alternative
   */
  std::string promptList(const std::string& instruction, const std::vector<std::string>& alternatives, void (*previous)(void) = prompt_noop, void (*next)(void) = prompt_noop);
  
  /**
   * Prompt the user for a file
   * 
   * @param   instruction   Instruction for the user
   * @param   loadfile      Whether to load the file
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The selected file, or if loadfile is true, its content
   */
  std::string promptFile(const std::string& instruction, bool loadfile, void (*previous)(void) = prompt_noop, void (*next)(void) = prompt_noop);
  
  /**
   * Prompt multiple item selection
   * 
   * @param   instruction   Instruction for the user
   * @param   selectcount   The number of items that can be choosed
   * @param   items         The items list from which to choose
   * @return                Selected items
   */
  std::vector<std::string> promptMulti(const std::string& instruction, long selectcount, const std::vector<std::string>& items);
  
  /**
   * Prompt the user with a dialogue
   * 
   * @param   colour        The colour of the person with whom you are speaking
   * @param   name          The name of the person with whom you are speaking
   * @param   message       The received message
   * @param   alternatives  Alternatives
   * @parm    spacing       The number of lines between alternatives
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptDialogue(char colour, const std::string& name, const std::string& message, const std::vector<std::string>& alternatives, char spacing = 1);
  
  /**
   * Prompt the user for a menu alternative and return index
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptIndex(const std::string& instruction, const std::vector<std::string>& alternatives);
  
  /**
   * Print a list in columns
   * 
   * @param  items  The items to print
   */
  void columnate(const std::vector<std::string>& items);
  
  
  /**
   * Lets the user assign items to slots, maybe even create the items
   * 
   * @param   <T>          The class of the assigned item
   * @param   <Fc>         T* () function  (implicit)
   * @param   <Fp>         void (T* item, bool selected) function  (implicit)
   * @param   instruction  Instructions for the user, can be multilined
   * @param   newitems     Whether the items returned by `creator` should be destructed when removed
   * @param   min          The minimum number items needed
   * @param   solts        Vector with slots
   * @param   creator      Function used to create items to put in the slots
   * @param   printer      Function prints a single line string that represents a slot
   * @return               Whether the assignment was completed
   */
  template<class T, class Fc, class Fp>
  bool promptSlots(std::string instruction, bool newitems, size_t min, std::vector<T*>* slots, Fc creator, Fp printer)
  {
    __store_tty();
    
    size_t current = 0;
    char c;
    
    const char* cstr = instruction.c_str();
    int firstline = 3;
    while ((c = *cstr++))
      if (c == '\n')
	firstline++;
    
    size_t assigneditems = 0;
    for (T* item : *slots)
      if (item != nullptr)
	assigneditems++;
    
    bool reading = true;
    while (reading)
      {
	std::cout << CSI "H" CSI "2J" CSI "?25l" << instruction << std::endl << std::endl;
	for (size_t i = 0, n = slots->size(); i < n; i++)
	  {
	    std::cout << (i == current ? CSI "01;34m> " CSI "21;39m" : "  ");
	    printer((*slots)[i], i == current);
	    std::cout << std::endl;
	  }
	std::flush(std::cout);
	
	bool readinginner = true;
	while (readinginner)
	  {
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = CTRL('G');
	    
	    switch (c)
	      {
	      case CTRL('L'):
		readinginner = false;
		break;
		
	      case CTRL('D'):
		if (assigneditems >= min)
		  readinginner = reading = false;
		break;
		
	      case CTRL('G'):
		assigneditems = -1;
		readinginner = reading = false;
		break;
		
	      case 'r':
	      case 'R':
		if ((*slots)[current] == nullptr)
		  break;
		if (newitems)
		  delete (*slots)[current];
		assigneditems--;
		(*slots)[current] = nullptr;
		std::cout << CSI << (current + firstline) << ";1H" CSI "K" CSI "01;34m> " CSI "21;39m";
		printer((*slots)[current], true);
		std::flush(std::cout);
		break;
		
	      case 'A':
	      case 'B':
		if (current == (c == 'A' ? 0 : (slots->size() - 1)))
		  break;
		std::cout << CSI << (current + firstline) << ";1H" CSI "K  ";
		printer((*slots)[current], false);
		current += c == 'A' ? -1 : 1;
		std::cout << CSI << (current + firstline) << ";1H" CSI "K" CSI "01;34m> " CSI "21;39m";
		printer((*slots)[current], true);
		std::flush(std::cout);
		break;
		
	      case ' ':
	      case 'C':
	      case '\n':
		readinginner = false;
		std::flush(std::cout << CSI "H" CSI "2J" CSI "?25h");
		T* newitem = creator();
		if (newitem == nullptr)
		  break;
		if ((*slots)[current] == nullptr)
		    assigneditems++;
		else
		  if (newitems)
		    delete (*slots)[current];
		(*slots)[current] = newitem;
		break;
	      }
	  }
      }
    
    std::flush(std::cout << CSI "H" CSI "2J" CSI "?25h");
    __restore_tty();
    
    bool rc = (ssize_t)(assigneditems) >= (ssize_t)(min);
    if (newitems && ! rc)
      for (size_t i = 0, n = slots->size(); i < n; i++)
	if ((*slots)[i] != nullptr)
	  {
	    delete (*slots)[i];
	    (*slots)[i] = nullptr;
	  }
    
    return rc;
  }
  
  

  /*  
  #undef __store_tty
  #undef __restore_tty
  #undef CSI
  #undef ESC
  */
  
}


#endif//__GUARD_PROMPTER_HPP__

