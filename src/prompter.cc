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
    stty.c_lflag &= ~(ICANON | ECHO | ISIG);   \
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &stty)
    
  #define __restore_tty()					\
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty)
  
  #define __bell()						\
    printf("\a"); /* bell, some people have bell enabled */	\
    std::flush(std::cout)
  
  #define __malloc_string(CHARS)  \
    (symbol*)malloc((CHARS) * sizeof(symbol))
  
  #define  ESC  "\033"  /* since \e generates a non-ISO-standard warning */
  
  
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
    long n;
    char m;
    
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
   * Print the text before the point
   * 
   * @param  start  The start
   * @param  end    The end
   */
  void prompt_print_before(long start, long end)
  {
    char* tmpc;
    symbol* tmps;
    long i;
    if (end > start)
      {
        tmpc = (char*)malloc(end * 8 + 1);
	tmps = __malloc_string(end + 1);
	for (i = start; i < end; i++)
	  *(tmps + i) = *(prompterdata.bp + i);
	*(tmps + end) = 0;
	symbol_decode(tmps + start, tmpc + start);
	free(tmps);
	printf("%s", tmpc + start);
	free(tmpc);
      }
  }
  
  /**
   * Print the text after the point
   * 
   * @param  start  The start
   * @param  end    The end
   * @param  del    Whether to delete one character at the end
   */
  void prompt_print_after(long start, long end, bool del = false)
  {
    char* tmpc;
    symbol* tmps;
    symbol* a;
    long i;
    if (end > start)
      {
        tmpc = (char*)malloc(end * 8 + 1);
	tmps = __malloc_string(prompterdata.after + 1);
	a = prompterdata.ap + prompterdata.after - 1;
	for (i = 0; i < end; i++)
	  *(tmps + i) = *(a - i);
	*(tmps + end) = 0;
	symbol_decode(tmps + start, tmpc + start);
	free(tmps);
	printf(del ? "%s " ESC "[%liD" : "%s" ESC "[%liD", tmpc + start, end - start + (del ? 1 : 0));
	free(tmpc);
      }
    else if (del)
      printf(" " ESC "[D");
  }
  
  /**
   * Redraw the input
   * 
   * @param  position  The current position of the cursor
   */
  void prompt_redraw(long position)
  {
    if (position > 0)
      printf(ESC "[%liD", position);
    if (prompterdata.mark <= 0)
      prompt_print_before(0, prompterdata.before);
    else if (prompterdata.mark - 1 >= prompterdata.before)
      prompt_print_before(0, prompterdata.before);
    else
      {
	prompt_print_before(0, prompterdata.mark - 1);
	printf(ESC "[44m");
	prompt_print_before(prompterdata.mark - 1, prompterdata.before);
	printf(ESC "[49m");
      }
    prompt_print_after(0, prompterdata.after);
    if (prompterdata.mark - 1 > prompterdata.before)
      {
	printf(ESC "[44m");
	prompt_print_after(0, prompterdata.mark - 1 - prompterdata.before);
	printf(ESC "[49m");
      }
  }
  
  /**
   * Complete prompting
   */
  void prompt_done()
  {
    prompterdata.mark = 0;
    prompt_redraw(prompterdata.before);
    
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
   * Insert a character
   * 
   * @param  sym  The character to insert
   */
  void prompt_char(symbol sym)
  {
    long i;
    
    if (prompterdata.mark > prompterdata.before + 1)
      prompterdata.mark++;
    
    if (prompterdata.before == prompterdata.bpz)
      {
	prompterdata.tmp = __malloc_string(prompterdata.bpz <<= 1);
	for (i = 0; i < prompterdata.before; i++)
	  *(prompterdata.tmp + i) = *(prompterdata.bp + i);
	free(prompterdata.bp);
	prompterdata.bp = prompterdata.tmp;
      }
    *(prompterdata.bp + prompterdata.before++) = sym;
    
    if ((prompterdata.mark > 0) && (prompterdata.mark < prompterdata.before))
      printf(ESC "[44m");
    if (sym > 127)
      {
	char* chars = (char*)malloc(9);
	symbol* syms = __malloc_string(2);
	*syms = sym;
	*(syms + 1) = 0;
	symbol_decode(syms, chars);
	printf("%s", chars);
	std::flush(std::cout);
	free(chars);
	free(syms);
      }
    else
      printf("%c", (char)(prompterdata.c));
    if ((prompterdata.mark > 0) && (prompterdata.mark < prompterdata.before))
      printf(ESC "[49m");
    
    if (prompterdata.after > 0)
      {
	if (prompterdata.override)
	  prompterdata.after--;
	else
	  {
	    prompt_print_after(0, prompterdata.after);
	    if (prompterdata.mark - 1 > prompterdata.before)
	      {
		printf(ESC "[44m");
		prompt_print_after(0, prompterdata.mark - 1 - prompterdata.before);
		printf(ESC "[49m");
	      }
	  }
      }
    
    std::flush(std::cout);
  }

  /**
   * Insert a ASCII character
   */
  void prompt_ascii()
  {
    if (prompterdata.c < ' ')
      return;
    
    prompt_char((symbol)(prompterdata.c));
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
    
    char invalid = (char)0xC0;
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
    
    if (invalid != (char)0xC0)
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
   * Set mark
   */
  void prompt_mark()
  {
    if (prompterdata.ignoreNUL && (prompterdata.c == '\0'))
      return;
    
    long p = prompterdata.before + 1;
    
    if (prompterdata.mark == p)
      prompterdata.mark = -p;
    else
      prompterdata.mark = p;
    prompt_redraw(prompterdata.before);
    std::flush(std::cout);
  }
  
  /**
   * Go to the beginning
   */
  void prompt_home()
  {
    long i;
    if (prompterdata.before > 0)
      {
	if (prompterdata.mark > 0)
	  prompt_print_after(0, prompterdata.after);
	printf(ESC "[%liD", prompterdata.before);
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
	if (prompterdata.mark > 0)
	  {
	    printf(ESC "[44m");
	    prompt_print_after(0, prompterdata.mark - 1);
	    printf(ESC "[49m");
	  }
	prompt_redraw(prompterdata.before);
	std::flush(std::cout);
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
	printf(ESC "[%liC", prompterdata.after);
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
	prompt_redraw(prompterdata.before);
	std::flush(std::cout);
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Delete a character
   * 
   * @param  whether to insert the deletion to the killring  TODO implement
   */
  void prompt_delete(bool store = false)
  {
    if ((prompterdata.mark > 0) && (prompterdata.mark - 1 != prompterdata.before))
      {
	long cursor = prompterdata.before, del, i;
	if (prompterdata.before < prompterdata.mark - 1)
	  prompterdata.after -= del = prompterdata.mark - 1 - prompterdata.before;
	else
	  prompterdata.before -= del = -(prompterdata.mark - 1 - prompterdata.before);
	prompterdata.mark = -(prompterdata.before + 1);
	prompt_redraw(cursor);
	if (prompterdata.after > 0)
	  printf(ESC "[%liC", prompterdata.after);
	if (del &  1)  printf(" ");
	if (del &  2)  printf("  ");
	if (del &  4)  printf("    ");
	if (del &  8)  printf("        ");
	if (del & 16)  printf("                ");
        for (i = 0; i + 32 <= del; i += 32)
	  printf("                                ");
	printf(ESC "[%liD", prompterdata.after + del);
	std::flush(std::cout);
      }
    else if (store == false)
      {
	if (prompterdata.after > 0)
	  {
	    prompt_print_after(0, --(prompterdata.after), true);
	    std::flush(std::cout);
	    bool neg = prompterdata.mark < 0;
	    if (neg)
	      prompterdata.mark = -(prompterdata.mark);
	    if (prompterdata.mark - 1 > prompterdata.before)
	      prompterdata.mark--;
	    else if (prompterdata.mark - 1 == prompterdata.before)
	      prompterdata.mark == 0;
	    if (neg)
	      prompterdata.mark = -(prompterdata.mark);
	  }
	else
	  {
	    __bell();
	  }
      }
  }
  
  /**
   * Erase a character
   */
  void prompt_erase()
  {
    if ((prompterdata.mark > 0) && (prompterdata.mark - 1 != prompterdata.before))
      prompt_delete();
    else if (prompterdata.before > 0)
      {
	prompterdata.before--;
	printf(ESC "[D");
	prompt_print_after(0, prompterdata.after, true);
	std::flush(std::cout);
	bool neg = prompterdata.mark < 0;
	if (neg)
	  prompterdata.mark = -(prompterdata.mark);
	if (prompterdata.mark - 1 > prompterdata.before)
	  prompterdata.mark--;
	else if (prompterdata.mark - 1 == prompterdata.before)
	  prompterdata.mark == 0;
	if (neg)
	  prompterdata.mark = -(prompterdata.mark);
      }
    else
      {
	__bell();
      }
  }
  
  /**
   * Adjust the buffer for going left of the character
   */
  inline void prompt_left_buffer()
  {
    if (prompterdata.after == prompterdata.apz)
      {
	prompterdata.tmp = __malloc_string(prompterdata.apz <<= 1);
	for (long i = 0; i < prompterdata.after; i++)
	  *(prompterdata.tmp + i) = *(prompterdata.ap + i);
	free(prompterdata.ap);
	prompterdata.ap = prompterdata.tmp;
      }
    prompterdata.before--;
    *(prompterdata.ap + prompterdata.after) = *(prompterdata.bp + prompterdata.before);
    prompterdata.after++;
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
	printf(ESC "[D");
	prompt_left_buffer();
	if (prompterdata.mark - 1 > prompterdata.before)
	  {
	    printf(ESC "[44m");
	    prompt_print_after(0, 1);
	    printf(ESC "[49m");
	  }
	else if (prompterdata.mark - 1 <= prompterdata.before)
	  prompt_print_after(0, 1);
	std::flush(std::cout);
      }
  }
  
  /**
   * Adjust the buffer for going right of the character
   */
  inline void prompt_right_buffer()
  {
    if (prompterdata.before == prompterdata.bpz)
      {
	prompterdata.tmp = __malloc_string(prompterdata.bpz <<= 1);
	for (long i = 0; i < prompterdata.before; i++)
	  *(prompterdata.tmp + i) = *(prompterdata.bp + i);
	free(prompterdata.bp);
	prompterdata.bp = prompterdata.tmp;
      }
    prompterdata.after--;
    *(prompterdata.bp + prompterdata.before) = *(prompterdata.ap + prompterdata.after);
    prompterdata.before++;
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
	if ((prompterdata.mark - 1 <= prompterdata.before) && (prompterdata.mark > 0))
	  {
	    printf(ESC "[44m");
	    prompt_print_after(0, 1);
	    printf(ESC "[49m");
	  }
	printf(ESC "[C");
	prompt_right_buffer();
        if (prompterdata.mark - 1 >= prompterdata.before)
	  {
	    printf(ESC "[D");
	    prompt_print_before(prompterdata.before - 1, prompterdata.before);
	  }
	std::flush(std::cout);
      }
  }
  
  /**
   * Redraw
   * 
   * @param  instruction  Instruction for the user
   */
  void prompt_redraw(std::string instruction)
  {
    std::cout << ESC "[H" ESC "[2J" << instruction;
    prompt_redraw(0);
    std::flush(std::cout);
  }
  
  /**
   * Swap the mark and the point
   */
  void prompt_swap_mark()
  {
    if (  prompterdata.mark - 1  == prompterdata.before)  return;
    if (-(prompterdata.mark - 1) == prompterdata.before)  return;
    if (prompterdata.mark == 0)  return;
    
    bool neg = prompterdata.mark < 0;
    if (neg)
      prompterdata.mark = -(prompterdata.mark);
    prompterdata.mark--;
    
    long n, i, b = prompterdata.before;
    if (prompterdata.mark > prompterdata.before)
      {
	printf(ESC "[%liC", n = prompterdata.mark - prompterdata.before);
	for (i = 0; i < n; i++)
	  prompt_right_buffer();
      }
    else
      {
	printf(ESC "[%liD", n = prompterdata.before - prompterdata.mark);
	for (i = 0; i < n; i++)
	  prompt_left_buffer();
      }
    
    std::flush(std::cout);
    std::swap(prompterdata.mark, prompterdata.before = b);
    
    prompterdata.mark++;
    if (neg)
      prompterdata.mark = -(prompterdata.mark);
  }
  
  
  /**
   * No operator
   */
  void promptNoop()
  {
    // noop
  }
  
  
  /**
   * Prompt the user for an arbitrary string
   * 
   * @param   instruction  Instruction for the user
   * @param   previous     Previous entry hook
   * @param   next         Next entry hook
   * @return               The string provided by the user, empty string is returned if aborted
   */
  std::string promptArbitrary(std::string instruction, void (*previous)(), void (*next)())
  {
    std::cout << instruction;
    std::flush(std::cout);
    
    prompterdata.bpz = 64;
    prompterdata.apz = 64;
    prompterdata.bp = __malloc_string(prompterdata.bpz);
    prompterdata.ap = __malloc_string(prompterdata.apz);
    prompterdata.reading = true;
    prompterdata.before = 0;
    prompterdata.after = 0;
    prompterdata.mark = 0;
    prompterdata.aborted = false;
    prompterdata.controlX = false;
    
    __store_tty();
    
    while (prompterdata.reading)
      {
	if (read(STDIN_FILENO, &(prompterdata.c), 1) <= 0)
	  prompterdata.c = '\n';
        
        if (prompterdata.controlX && ! ((prompterdata.c == '\n') || (prompterdata.c == CTRL('D')) || (prompterdata.c == CTRL('G'))))
	  {
            switch (prompterdata.c)
	      {
	      case CTRL('X'):
		prompt_swap_mark();
		break;
                
	      case CTRL('C'):
		prompterdata.ignoreNUL ^= true;
		break;
		
	      case 'u':
	      case 'U':
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
	  case '\n': case CTRL('D'):  prompt_done();   break;
	  case '\b': case 127:        prompt_erase();  break;
          case '\0': case CTRL('C'):  prompt_mark();   break;
	    
	  case '\033': /* \e */
	    {
	      if (prompt_esc() == false)
	        break;
	      
	      if ((prompterdata.ansi == "OH") || (prompterdata.ansi == "[1~")) /* home */
		prompt_home();
	      else if ((prompterdata.ansi == "OF") || (prompterdata.ansi == "[4~")) /* end */
		prompt_end();
	      else if (prompterdata.ansi == "[2~") /* insert */
		prompterdata.override ^= true;
	      else if (prompterdata.ansi == "[5;2~") /* C-delete */
		;
	      else if (prompterdata.ansi == "[3~") /* delete */
		prompt_delete();
	      //else if (prompterdata.ansi == "[5~") /* page up */
	      //  ;
	      //else if (prompterdata.ansi == "[6~") /* page down */
	      //  ;
	      else if (prompterdata.ansi == "[A") /* up */
		previous();
	      else if (prompterdata.ansi == "[B") /* down */
		next();
	      else if (prompterdata.ansi == "[C") /* right */
		prompt_right();
	      else if (prompterdata.ansi == "[D") /* left */
		prompt_left();
	      else if (prompterdata.ansi == "[1;2C") /* S-right */
		{
		  if (prompterdata.mark <= 0)
		    prompterdata.mark = prompterdata.before;
		  prompt_right();
		}
	      else if (prompterdata.ansi == "[1;2D") /* S-left */
		{
		  if (prompterdata.mark <= 0)
		    prompterdata.mark = prompterdata.before;
		  prompt_left();
		}
	      else if (prompterdata.ansi == "[1;5C") /* C-right */
		;
	      else if (prompterdata.ansi == "[1;5D") /* C-left */
		;
	      else if (prompterdata.ansi == "[1;6C") /* C-S-right */
		;
	      else if (prompterdata.ansi == "[1;6D") /* C-S-left */
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
	    }
	    break;
          
          case '\t':
            break;
          
	  case CTRL('Y'):
            break;
	  case CTRL('_'):
            break;
	  case CTRL('O'):
            break;
          
	  case CTRL('K'):  prompterdata.mark = prompterdata.before + prompterdata.after + 1; /* fall-through */
	  case CTRL('W'):  prompt_delete(true);           break;
	  case CTRL('X'):  prompterdata.controlX = true;  break;
	  case CTRL('L'):  prompt_redraw(instruction);    break;
	  case CTRL('F'):  prompt_right();                break;
	  case CTRL('B'):  prompt_left();                 break;
	  case CTRL('A'):  prompt_home();                 break;
	  case CTRL('E'):  prompt_end();                  break;
	  case CTRL('P'):  previous();                    break;
	  case CTRL('N'):  next();                        break;
	  case CTRL('G'):  prompt_abort();                break;
          
	  default:
	    if ((prompterdata.c & 0x80) == 0)
	      prompt_ascii();
	    else
	      prompt_utf8();
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

