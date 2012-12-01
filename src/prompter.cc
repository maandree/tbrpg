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
#include "prompter.hpp"


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
    stty.c_lflag &= ~(ICANON | ECHO);          \
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &stty)
    
  #define __restore_tty()					\
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty)
  
  #define __bell()						\
    printf("\a"); /* bell, some people have bell enabled */	\
    std::flush(std::cout)
  
  
  
  /**
   * Prompt the user for an arbitrary string
   * 
   * @param   instruction  Instruction for the user
   * @return               The string provided by the user, empty string is returned if aborted
   */
  std::string promptArbitrary(std::string instruction)
  {
    std::cout << instruction;
    std::flush(std::cout);
    
    long bpz = 64;
    long apz = 64;
    char* bp = (char*)malloc(bpz);
    char* ap = (char*)malloc(apz);
    char* tmp;
    char* esc;
    char c;
    bool reading = true;
    long i, before = 0, after = 0;
    bool aborted = false;
    long escptr, escsize;
    bool override = false, ignoreNUL = false, controlX = false;
    std::string ansi;
    
    __store_tty();
    
    while (reading)
      {
	if (read(STDIN_FILENO, &c, 1) <= 0)
	  c = '\n';
        
        if (controlX && ! ((c == '\n') || CTRL('D') || CTRL('G')))
	  {
            switch (c)
	      {
                case CTRL('X'):
                 break;
                
                case CTRL('V'):
		  {
                    ignoreNUL ^= true;
		  }
                  break;
              }
            
            if (c != '\0') /* C-space can be sent from the kernel */
	      {
	        controlX = false;
	        continue;
              }
          }
  
	switch (c)
	  {
	  case '\n':
          case CTRL('D'):
	    {
	      reading = false;
	      std::cout << std::endl;
	      std::flush(std::cout);
	      
	      tmp = (char*)malloc(before + after + 1);
	      for (i = 0; i < before; i++)
		*tmp++ = *(bp + i);
	      free(bp);
	      for (i = after - 1; i >= 0; i--)
		*tmp++ = *(ap + i);
	      free(ap);
	      *tmp++ = 0;
	      tmp -= (before + after + 1);
	    }
	    break;
	    
	    
	  case CTRL('G'):
	    {
	      reading = false;
	      std::cout << std::endl;
	      std::flush(std::cout);
	      
	      free(ap);
	      free(bp);
	      aborted = true;
	    }
	    break;
	    
	    
	  case '\b':
	  case 127:
	    {
	      if (before > 0)
		{
		  before--;
		  printf("\e[D");
		  for (i = after - 1; i >= 0; i--)
		    printf("%c", *(ap + i));
		  printf(" \e[%liD", after + 1);
		  std::flush(std::cout);
		}
	      else
		{
		  __bell();
		}
	    }
	    break;
	    
	    
	  case '\e':
	    {
	      esc = (char*)malloc(escsize = 16);
	      escptr = 0;
	      
	      while (((c != '~') && ! ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))) || ((escptr == 1) && (c == 'O')))
		{
		  if (read(STDIN_FILENO, &c, 1) <= 0)
		    {
		      free(esc);
		      reading = false;
		      std::cout << std::endl;
		      std::flush(std::cout);
		      
		      esc = (char*)malloc(before + after + 1);
		      for (i = 0; i < before; i++)
			*esc++ = *(bp + i);
		      free(bp);
		      for (i = after - 1; i >= 0; i--)
			*esc++ = *(ap + i);
		      free(ap);
		      *esc++ = 0;
		      esc -= (before + after + 1);
		      break;
		    }
		  if (c != '\0') /* C-space can be sent from the kernel */
		    {
		      *(esc + escptr++) = c;
		      if (escptr == escsize)
			{
			  tmp = (char*)malloc(escsize <<= 1);
			  for (i = 0; i < escptr; i++)
			    *(tmp + i) = *(esc + i);
			  free(esc);
			  esc = tmp;
		        }
		    }
		}
	      if ((c != '~') && ! ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'))))
		break;
	      
	      *(esc + escptr) = 0;
	      ansi = std::string(esc);
	      free(esc);
	      
	      
	      if ((ansi == "OH") || (ansi == "[1~")) /* home */
		if (before > 0)
		  {
		    printf("\e[%liD", before);
		    while (before != 0)
		      {
			if (after == apz)
			  {
			    tmp = (char*)malloc(apz <<= 1);
			    for (i = 0; i < after; i++)
			      *(tmp + i) = *(ap + i);
			    free(ap);
			    ap = tmp;
			}
			before--;
			*(ap + after) = *(bp + before);
			after++;
		      }
		    before = 0;
		  }
		else
		  {
		    __bell();
		  }
	      else if ((ansi == "OF") || (ansi == "[4~")) /* end */
		if (after > 0)
		  {
		    printf("\e[%liC", after);
		    while (after != 0)
		      {
			if (before == bpz)
			  {
			    tmp = (char*)malloc(bpz <<= 1);
			    for (i = 0; i < before; i++)
			      *(tmp + i) = *(bp + i);
			    free(bp);
			    bp = tmp;
			  }
			after--;
			*(bp + before) = *(ap + after);
			before++;
		      }
		    after = 0;
		  }
		else
		  {
		    __bell();
		  }
	      else if (ansi == "[2~") /* insert */
		override ^= true;
	      else if (ansi == "[3;2~") /* C-delete */
		;
	      else if (ansi == "[3~") /* delete */
		if (after > 0)
		  {
		    after--;
		    for (i = after - 1; i >= 0; i--)
		      printf("%c", *(ap + i));
		    printf(" \e[%liD", after + 1);
		  }
		else
		  {
		    __bell();
		  }
	      else if (ansi == "[5~") /* page up */
		;
	      else if (ansi == "[6~") /* page down */
		;
	      else if (ansi == "[A") /* up */
		;
	      else if (ansi == "[B") /* down */
		;
	      else if (ansi == "[C") /* right */
		if (after == 0)
		  {
		    __bell();
		    break;
		  }
		else
		  {
		    printf("\e[C");
		    after--;
		    *(bp + before) = *(ap + after);
		    before++;
		  }
	      else if (ansi == "[D") /* left */
		{
		  if (before == 0)
		    {
		      __bell();
		      break;
		    }
		  else
		    {
		      printf("\e[D");
		      if (after == apz)
			{
			  tmp = (char*)malloc(apz <<= 1);
			  for (i = 0; i < after; i++)
			    *(tmp + i) = *(ap + i);
			  free(ap);
			  ap = tmp;
			}
		      before--;
		      *(ap + after) = *(bp + before);
		      after++;
		    }
		}
	      else if (ansi == "[1;2C") /* S-right */
		;
	      else if (ansi == "[1;2D") /* S-left */
		;
	      else if (ansi == "[1;3C") /* C-right */
		;
	      else if (ansi == "[1;3D") /* C-left */
		;
	      else if (ansi == "[1;4C") /* C-S-right */
		;
	      else if (ansi == "[1;4D") /* C-S-left */
		;
	      else if ((ansi == "\t") || (ansi == "[Z")) /* backtab */
		;
	      else if ((ansi == "y") || ansi == "Y") /* M-y */
		;
	      else if ((ansi == "w") || ansi == "W") /* M-w */
		;
	      else if ((ansi == "f") || ansi == "F") /* M-f */
		;
	      else if ((ansi == "b") || ansi == "B") /* M-b */
		;
	      #ifdef DEBUG
	        else
		  {
		    std::cerr << ansi << std::endl;
		    std::flush(std::cerr);
		  }
	      #endif
	      std::flush(std::cout);
	    }
	    break;
          
          
          case '\0':
          case CTRL('V'):
            if (ignoreNUL && (c == '\0'))
	      break;
            break;
          
          
          case '\t':
            break;
          
          
	  case CTRL('L'):
            break;
	  case CTRL('W'):
            break;
	  case CTRL('Y'):
            break;
	  case CTRL('K'):
            break;
	  case CTRL('F'):
            break;
	  case CTRL('B'):
            break;
	  case CTRL('A'):
            break;
	  case CTRL('E'):
            break;
          
         
	  case CTRL('X'):
	    {
              controlX = true;
            }
            break;
	  
	  
	  default:
	    {
	      if ((c & 0x80) == 0)
		{
		  if (c < ' ')
		    break;
		  
		  if (before == bpz)
		    {
		      tmp = (char*)malloc(bpz <<= 1);
		      for (i = 0; i < before; i++)
			*(tmp + i) = *(ap + i);
		      free(bp);
		      bp = tmp;
		    }
		  *(bp + before++) = c;
		  if (after > 0)
		    after--;
		  printf("%c", c);
		  std::flush(std::cout);
		}
	      else
		{
		  // TODO implement UTF-8 support
		}
	    }
	    break;
	  }
      }
    
    __restore_tty();
    
    if (aborted)
      return "";
    std::string rc = std::string(tmp);
    free(tmp);
    return rc;
  }
  
  
  #undef __store_tty
  #undef __restore_tty
  #undef __bell
  
}

