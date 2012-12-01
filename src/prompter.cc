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
  
  #define __malloc_string(CHARS)  \
    (symbol*)malloc((CHARS) * sizeof(symbol))
  
  
  
  /**
   * `symbol*` to `char*` converter
   * 
   * @param  symbols  `symbol*` NUL-free string to use
   * @param  chars    `char*` NUL-free string to fill
   */
  void symbol_decode(symbol* symbols, char* chars)
  {
    int s = 0;
    int c = 0;
    long n, i;
    char m;
    char* cc;
    
    char* utf8buf;
    bool ucs = false;
    
    symbol sym;
    while ((sym = *(symbols + s++)))
      if (sym < 128)
	*(chars + c++) = (char)sym;
      else
	{
	  if (ucs == false)
	    {
	      ucs = true;
	      utf8buf = (char*)malloc(8);
	    }
	  
	  #define mm  (128 | (m >> 1))
	  
	  m = n = 0;
	  for (;;)
	    {
	      *(utf8buf + n++) = (char)(sym & 63) | 128;
	      sym >>= 6;
	      m = mm;
	      
	      if ((sym == 0) && ((mm & (*(utf8buf + n - 1) & 127)) == 0))
		{
		  *(utf8buf + n - 1) |= m;
		  break;
		}
	    }
	  while (n)
	    *(chars + c++) = *(utf8buf + --n);
	  
          #undef mm
	}
    
    *(chars + c) = 0;
    
    if (ucs)
      free(utf8buf);
  }
  
  /**
   * Complete prompting
   */
  void prompt_done()
  {
    long i;
    prompterdata.reading = false;
    std::cout << std::endl;
    std::flush(std::cout);
    
    prompterdata.tmp = __malloc_string(prompterdata.before + prompterdata.after + 1);
    for (i = 0; i < prompterdata.before; i++)
      *(prompterdata.tmp)++ = *(prompterdata.bp + i);
    free(prompterdata.bp);
    for (i = prompterdata.after - 1; i >= 0; i--)
      *(prompterdata.tmp)++ = *(prompterdata.ap + i);
    free(prompterdata.ap);
    *prompterdata.tmp = 0;
    prompterdata.tmp -= prompterdata.before + prompterdata.after;
  }
  
  /**
   * Fetch escape sequences, after the initial \e
   * 
   * @return  Whether a sequences was fetched
   */
  bool prompt_esc()
  {
    long i;
    char* tmp;
    prompterdata.esc = (char*)malloc(prompterdata.escsize = 16);
    prompterdata.escptr = 0;
    
    #define __check(LOWER, UPPER)  \
      ((LOWER <= prompterdata.c) && (prompterdata.c <= UPPER))
    #define ___check  \
      !(__check('~', '~') || __check('a', 'z') || __check('A', 'Z'))
    
    while (___check || ((prompterdata.escptr == 1) && (prompterdata.c == 'O')))
      {
	if (read(STDIN_FILENO, &(prompterdata.c), 1) <= 0)
          {
	    free(prompterdata.esc);
	    prompt_done();
	    break;
	  }
	if (prompterdata.c != '\0') /* C-space can be sent from the kernel */
	  {
	    *(prompterdata.esc + prompterdata.escptr++) = prompterdata.c;
	    if (prompterdata.escptr == prompterdata.escsize)
	      {
		tmp = (char*)malloc(prompterdata.escsize <<= 1);
		for (i = 0; i < prompterdata.escptr; i++)
		  *(tmp + i) = *(prompterdata.esc + i);
		free(prompterdata.esc);
		prompterdata.esc = tmp;
	      }
	  }
	}
    if (___check)
      return false;
    
    #undef __check
    #undef ___check
    
    *(prompterdata.esc + prompterdata.escptr) = 0;
    prompterdata.ansi = std::string(prompterdata.esc);
    free(prompterdata.esc);
    
    return true;
  }
  
  
  /**
   * Insert a character (no echo)
   * 
   * @param  sym  The character to insert
   */
  void prompt_char(symbol sym)
  {
    long i;
    if (prompterdata.before == prompterdata.bpz)
      {
	prompterdata.tmp = __malloc_string(prompterdata.bpz <<= 1);
	for (i = 0; i < prompterdata.before; i++)
	  *(prompterdata.tmp + i) = *(prompterdata.ap + i);
	free(prompterdata.bp);
	prompterdata.bp = prompterdata.tmp;
      }
    
    *(prompterdata.bp + prompterdata.before++) = sym;
    if (prompterdata.after > 0)
      prompterdata.after--;
    
  }

  /**
   * Insert a ASCII character
   */
  void prompt_ascii()
  {
    long i;
    if (prompterdata.c < ' ')
      return;
    
    prompt_char((symbol)(prompterdata.c));
    
    printf("%c", prompterdata.c);
    std::flush(std::cout);
  }
  
  /**
   * Insert a UTF-8 encoded character
   */
  void prompt_utf8()
  {
    char n = 0;
    while (prompterdata.c & 0x80)
      {
	prompterdata.c <<= 1;
	n++;
      }
    
    char invalid = 0xC0;
    symbol sym = (symbol)((prompterdata.c & 127) >> n);
    for (char i = 1; i != n; i++)
      {
	if (read(STDIN_FILENO, &(prompterdata.c), 1) <= 0)
	  {
	    prompt_done();
	    return;
	  }
        if ((prompterdata.c & 0xC0) != 0x80)
	  {
	    invalid = prompterdata.c;
	    break;
	  }
	sym = (sym << 6) | (symbol)(prompterdata.c & 63);
      }
    
    prompt_char(sym);
    
    char* chars = (char*)malloc(9);
    symbol* syms = __malloc_string(2);
    *syms = sym;
    *(syms + 1) = 0;
    symbol_decode(syms, chars);
    
    printf("%s", chars);
    std::flush(std::cout);
    
    free(chars);
    free(syms);
    
    if (invalid != 0xC0)
      {
	prompterdata.c = invalid;
	prompt_ascii();
      }
  }
  
  /**
   * Abort prompting
   */
  void prompt_abort()
  {
    prompterdata.reading = false;
    std::cout << std::endl;
    std::flush(std::cout);
    
    free(prompterdata.ap);
    free(prompterdata.bp);
    prompterdata.aborted = true;
  }
  
  /**
   * Erase a character
   */
  void prompt_erase()
  {
    long i;
    if (prompterdata.before > 0)
      {
	prompterdata.before--;
	printf("\e[D");
	for (i = prompterdata.after - 1; i >= 0; i--)
	  printf("%c", *(prompterdata.ap + i));
	printf(" \e[%liD", prompterdata.after + 1);
	std::flush(std::cout);
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Set mark
   */
  void prompt_mark()
  {
    if (prompterdata.ignoreNUL && (prompterdata.c == '\0'))
      return;
  }
  
  /**
   * Go to the beginning
   */
  void prompt_home()
  {
    long i;
    if (prompterdata.before > 0)
      {
	printf("\e[%liD", prompterdata.before);
	while (prompterdata.before != 0)
	  {
	    if (prompterdata.after == prompterdata.apz)
	      {
		prompterdata.tmp = __malloc_string(prompterdata.apz <<= 1);
		for (i = 0; i < prompterdata.after; i++)
		  *(prompterdata.tmp + i) = *(prompterdata.ap + i);
		free(prompterdata.ap);
		prompterdata.ap = prompterdata.tmp;
	      }
	    prompterdata.before--;
	    *(prompterdata.ap + prompterdata.after) = *(prompterdata.bp + prompterdata.before);
	    prompterdata.after++;
	  }
	prompterdata.before = 0;
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Go to the end
   */
  void prompt_end()
  {
    long i;
    if (prompterdata.after > 0)
      {
	printf("\e[%liC", prompterdata.after);
	while (prompterdata.after != 0)
	  {
	    if (prompterdata.before == prompterdata.bpz)
	      {
		prompterdata.tmp = __malloc_string(prompterdata.bpz <<= 1);
		for (i = 0; i < prompterdata.before; i++)
		  *(prompterdata.tmp + i) = *(prompterdata.bp + i);
		free(prompterdata.bp);
		prompterdata.bp = prompterdata.tmp;
	      }
	    prompterdata.after--;
	    *(prompterdata.bp + prompterdata.before) = *(prompterdata.ap + prompterdata.after);
	    prompterdata.before++;
	  }
	prompterdata.after = 0;
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Delete a character
   */
  void prompt_delete()
  {
    long i;
    if (prompterdata.after > 0)
      {
	prompterdata.after--;
	for (i = prompterdata.after - 1; i >= 0; i--)
	  printf("%c", *(prompterdata.ap + i));
	printf(" \e[%liD", prompterdata.after + 1);
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Go left of character
   */
  void prompt_left()
  {
    long i;
    if (prompterdata.before == 0)
      {
	__bell();
      }
    else
      {
	printf("\e[D");
	if (prompterdata.after == prompterdata.apz)
	  {
	    prompterdata.tmp = __malloc_string(prompterdata.apz <<= 1);
	    for (i = 0; i < prompterdata.after; i++)
	      *(prompterdata.tmp + i) = *(prompterdata.ap + i);
	    free(prompterdata.ap);
	    prompterdata.ap = prompterdata.tmp;
	  }
	prompterdata.before--;
	*(prompterdata.ap + prompterdata.after) = *(prompterdata.bp + prompterdata.before);
	prompterdata.after++;
      }
  }
  
  /**
   * Go right of character
   */
  void prompt_right()
  {
    if (prompterdata.after == 0)
      {
	__bell();
      }
    else
      {
	printf("\e[C");
	prompterdata.after--;
	*(prompterdata.bp + prompterdata.before) = *(prompterdata.ap + prompterdata.after);
	prompterdata.before++;
      }
  }
  
  
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
    
    prompterdata.bpz = 64;
    prompterdata.apz = 64;
    prompterdata.bp = __malloc_string(prompterdata.bpz);
    prompterdata.ap = __malloc_string(prompterdata.apz);
    prompterdata.reading = true;
    prompterdata.after = 0;
    prompterdata.aborted = false;
    prompterdata.controlX = false;
    
    __store_tty();
    
    while (prompterdata.reading)
      {
	if (read(STDIN_FILENO, &(prompterdata.c), 1) <= 0)
	  prompterdata.c = '\n';
        
        if (prompterdata.controlX && ! ((prompterdata.c == '\n') || CTRL('D') || CTRL('G')))
	  {
            switch (prompterdata.c)
	      {
                case CTRL('X'):
                 break;
                
                case CTRL('C'):
                  prompterdata.ignoreNUL ^= true;
                  break;
              }
            
            if (prompterdata.c != '\0') /* C-space can be sent from the kernel */
	      {
	        prompterdata.controlX = false;
	        continue;
              }
          }
  
	switch (prompterdata.c)
	  {
	  case '\n':
          case CTRL('D'):
	    prompt_done();
	    break;
	    
	  case CTRL('G'):
	    prompt_abort();
	    break;
	    
	  case '\b':
	  case 127:
	    prompt_erase();
	    break;
	    
	    
	  case '\e':
	    {
	      if (prompt_esc() == false)
	        break;
	      
	      if ((prompterdata.ansi == "OH") || (prompterdata.ansi == "[1~")) /* home */
		prompt_home();
	      else if ((prompterdata.ansi == "OF") || (prompterdata.ansi == "[4~")) /* end */
		prompt_end();
	      else if (prompterdata.ansi == "[2~") /* insert */
		prompterdata.override ^= true;
	      else if (prompterdata.ansi == "[3;2~") /* C-delete */
		;
	      else if (prompterdata.ansi == "[3~") /* delete */
		prompt_delete();
	      else if (prompterdata.ansi == "[5~") /* page up */
		;
	      else if (prompterdata.ansi == "[6~") /* page down */
		;
	      else if (prompterdata.ansi == "[A") /* up */
		;
	      else if (prompterdata.ansi == "[B") /* down */
		;
	      else if (prompterdata.ansi == "[C") /* right */
		prompt_right();
	      else if (prompterdata.ansi == "[D") /* left */
		prompt_left();
	      else if (prompterdata.ansi == "[1;2C") /* S-right */
		;
	      else if (prompterdata.ansi == "[1;2D") /* S-left */
		;
	      else if (prompterdata.ansi == "[1;3C") /* C-right */
		;
	      else if (prompterdata.ansi == "[1;3D") /* C-left */
		;
	      else if (prompterdata.ansi == "[1;4C") /* C-S-right */
		;
	      else if (prompterdata.ansi == "[1;4D") /* C-S-left */
		;
	      else if ((prompterdata.ansi == "\t") || (prompterdata.ansi == "[Z")) /* backtab */
		;
	      else if ((prompterdata.ansi == "y") || prompterdata.ansi == "Y") /* M-y */
		;
	      else if ((prompterdata.ansi == "w") || prompterdata.ansi == "W") /* M-w */
		;
	      else if ((prompterdata.ansi == "f") || prompterdata.ansi == "F") /* M-f */
		;
	      else if ((prompterdata.ansi == "b") || prompterdata.ansi == "B") /* M-b */
		;
	      #ifdef DEBUG
	        else
		  {
		    std::cerr << prompterdata.ansi << std::endl;
		    std::flush(std::cerr);
		  }
	      #endif
	      std::flush(std::cout);
	    }
	    break;
          
          
          case '\0':
          case CTRL('C'):
	    prompt_mark();
            break;
         
	  case CTRL('X'):
	    prompterdata.controlX = true;
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
	  case CTRL('F'): prompt_right(); break;
	  case CTRL('B'): prompt_left();  break;
	  case CTRL('A'): prompt_home();  break;
	  case CTRL('E'): prompt_end();   break;
          
	  
	  default:
	    {
	      if ((prompterdata.c & 0x80) == 0)
		prompt_ascii();
	      else
		prompt_utf8();
	    }
	    break;
	  }
      }
    
    __restore_tty();
    
    if (prompterdata.aborted)
      return "";
    char* tmp = (char*)malloc((prompterdata.before + prompterdata.after) * 8 + 1);
    symbol_decode(prompterdata.tmp, tmp);
    free(prompterdata.tmp);
    std::string rc = std::string(tmp);
    free(tmp);
    return rc;
  }
  
  
  #undef __store_tty
  #undef __restore_tty
  #undef __bell
  #undef __malloc_string
  
}

