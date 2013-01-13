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
#include "InventoryExaminor.hpp"


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
  void InventoryExaminor::examine(long character, std::vector<GameCharacter*>* characters) const
  {
    __store_tty();
    
    std::cout << CSI "?25l";
    
    char c;
    bool reading = true;
    
    while (reading)
      {
	std::flush(std::cout);
	if (read(STDIN_FILENO, &c, 1) <= 0)
	  c = CTRL('G');
	
	bool readinginner = true;
	while (readinginner)
	  {
	    readinginner = false;
	    switch (c)
	      {
	      case '\033':
		if (read(STDIN_FILENO, &c, 1) <= 0)
		  break;
		if (c == 'O')
		  {
		    read(STDIN_FILENO, &c, 1);
		    switch (c)
		      {
		      case 'P':
			c = '1';
			readinginner = true;
			break;
		      case 'Q':
			c = '2';
			readinginner = true;
			break;
		      case 'R':
			c = '3';
			readinginner = true;
			break;
		      }
		  }
		else if (c == '[')
		  {
		    read(STDIN_FILENO, &c, 1);
		    if (c == '1')
		      {
			switch (c)
			  {
			  case '1':
			  case '2':
			  case '3':
			    readinginner = true;
			    break;
			  }
			read(STDIN_FILENO, &c, 1);
			if (c != '~')
			  readinginner = false;
		      }
		    else if (c == 'A')
		      {
			c = CTRL('P');
			readinginner = true;
		      }
		    else if (c == 'B')
		      {
			c = CTRL('N');
			readinginner = true;
		      }
		  }
		break;
		
	      case '1': /* Equipped items */
		break;
		
	      case '2': /* Personal inventory */
		break;
		
	      case '3': /* Item on the ground */
		break;
		
	      case 'd': /* Drop temporary slot item on the ground */
		break;
		
	      case 'D': /* Drop item on the ground */
		break;
		
	      case 'p': /* Pick up item to temporary slot */
		break;
		
	      case 's': /* Swap item with temporary slot */
		break;
		
	      case 'e': /* Examine item in slot */
		break;
		
	      case 'E': /* Examine item in temporary slot */
		break;
		
	      case 'P': /* Give item to another party member */
		break;
		
	      case CTRL('D'): /* Complete */
		break;
		
	      case CTRL('G'): /* Abort */
		break;
		
	      case CTRL('P'): /* Navigate up */
		break;
		
	      case CTRL('N'): /* Navigate down */
		break;
	      }
	  }
      }
    
    std::flush(std::cout << CSI "?25l");
    
    __restore_tty();
  }
  
}

