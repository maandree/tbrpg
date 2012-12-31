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
	printf(del ? "%s " CSI "%liD" : "%s" CSI "%liD", tmpc + start, end - start + (del ? 1 : 0));
	free(tmpc);
      }
    else if (del)
      printf(" " CSI "D");
  }
  
  /**
   * Redraw the input
   * 
   * @param  position  The current position of the cursor
   */
  void prompt_redraw(long position)
  {
    if (position > 0)
      printf(CSI "%liD", position);
    if (prompterdata.mark <= 0)
      prompt_print_before(0, prompterdata.before);
    else if (prompterdata.mark - 1 >= prompterdata.before)
      prompt_print_before(0, prompterdata.before);
    else
      {
	prompt_print_before(0, prompterdata.mark - 1);
	printf(CSI "44m");
	prompt_print_before(prompterdata.mark - 1, prompterdata.before);
	printf(CSI "49m");
      }
    prompt_print_after(0, prompterdata.after);
    if (prompterdata.mark - 1 > prompterdata.before)
      {
	printf(CSI "44m");
	prompt_print_after(0, prompterdata.mark - 1 - prompterdata.before);
	printf(CSI "49m");
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
   * Fetch file stat of file with link following, but only if regular file
   * 
   * @param   filename  The name of the file
   * @param   filestat  Stat storage
   * @return            −1 iff the file does not exist or link to a regular file
   */
  int prompt_stat(char* filename, struct stat* filestat)
  {
    return stat(filename, filestat);
    /* TODO implement restriction */
  }
  
  /**
   * Complete prompting hook for file prompting
   */
  void prompt_file()
  {
    /* BEGIN drag and drop support */
    
    bool start;
    bool endfar;
    bool end;
    
    if (prompterdata.before == 0)
      start = *(prompterdata.ap + prompterdata.after - 1) == '\'';
    else
      start = *(prompterdata.bp) == '\'';
    
    if (prompterdata.after == 0)
      endfar = *(prompterdata.bp + prompterdata.before - 1) == ' ';
    else
      endfar = *(prompterdata.ap) == ' ';
    
    if (prompterdata.after == 0)
      end = *(prompterdata.bp + prompterdata.before - 2) == '\'';
    else if (prompterdata.after == 1)
      end = *(prompterdata.bp + prompterdata.before - 1) == '\'';
    else
      end = *(prompterdata.ap + 1) == '\'';
    
    if (start && endfar && end)
      {
	prompterdata.mark = 0;
	long n = prompterdata.before + prompterdata.after - 3, b = 0;
	prompterdata.tmp = __malloc_string(n);
	if (prompterdata.before > 0)
	  printf(CSI "%liD", prompterdata.before);
	printf(CSI "K");
	
	bool quote = true;
	bool slash = false;
	char c;
	for (long i = 1; i <= n; i++)
	  {
	    if (i < prompterdata.before)
	      c = *(prompterdata.bp + i);
	    else
	      c = *(prompterdata.ap + prompterdata.after - 1 + (i - prompterdata.before));
	    
	    if (slash)
	      {
		*(prompterdata.tmp + b++) = c;
		slash = false;
	      }
	    else if (c == '\'')
	      quote ^= true;
	    else if (quote || (c != '\\'))
	      *(prompterdata.tmp + b++) = c;
	    else
	      slash = true;
	  }
	
	prompterdata.before = b;
	free(prompterdata.bp);
	prompterdata.bp = prompterdata.tmp;
	prompterdata.bpz = n;
	prompterdata.after = 0;
	prompt_print_before(0, prompterdata.before);
	std::flush(std::cout);
      }
    
    /* END drag and drop support */
    
    prompterdata.tmp = __malloc_string(prompterdata.before + prompterdata.after + 1);
    for (long i = 0; i < prompterdata.before; i++)
      *(prompterdata.tmp)++ = *(prompterdata.bp + i);
    for (long i = prompterdata.after - 1; i >= 0; i--)
      *(prompterdata.tmp)++ = *(prompterdata.ap + i);
    *prompterdata.tmp = 0;
    prompterdata.tmp -= prompterdata.before + prompterdata.after;
    
    char* tmp = (char*)malloc((prompterdata.before + prompterdata.after) * 8 + 1);
    symbol_decode(prompterdata.tmp, tmp);
    free(prompterdata.tmp);
    
    struct stat filestat;
    if (prompt_stat(tmp, &filestat) == -1)
      {
	free(tmp);
        return;
      }
    free(tmp);

    prompt_done();
  }
  
  /**
   * Complete prompting hook for alternative prompting
   */
  void prompt_alternative()
  {
    prompterdata.tmp = __malloc_string(prompterdata.before + prompterdata.after + 1);
    for (long i = 0; i < prompterdata.before; i++)
      *(prompterdata.tmp)++ = *(prompterdata.bp + i);
    for (long i = prompterdata.after - 1; i >= 0; i--)
      *(prompterdata.tmp)++ = *(prompterdata.ap + i);
    *prompterdata.tmp = 0;
    prompterdata.tmp -= prompterdata.before + prompterdata.after;
    
    char* tmp = (char*)malloc((prompterdata.before + prompterdata.after) * 8 + 1);
    symbol_decode(prompterdata.tmp, tmp);
    free(prompterdata.tmp);
    std::string str = std::string(tmp);
    
    for (std::string& alternative : prompterdata.alternatives)
      if (str == alternative)
	{
	  free(tmp);
	  prompt_done();
	  return;
	}
    
    __bell();
    
    free(tmp);
    std::cout << std::endl;
    columnate(prompterdata.alternatives);
    std::flush(std::cout);
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
      printf(CSI "44m");
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
      printf(CSI "49m");
    
    if (prompterdata.after > 0)
      {
	if (prompterdata.override)
	  prompterdata.after--;
	else
	  {
	    prompt_print_after(0, prompterdata.after);
	    if (prompterdata.mark - 1 > prompterdata.before)
	      {
		printf(CSI "44m");
		prompt_print_after(0, prompterdata.mark - 1 - prompterdata.before);
		printf(CSI "49m");
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
	printf(CSI "%liD", prompterdata.before);
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
	    printf(CSI "44m");
	    prompt_print_after(0, prompterdata.mark - 1);
	    printf(CSI "49m");
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
	printf(CSI "%liC", prompterdata.after);
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
	  printf(CSI "%liC", prompterdata.after);
	if (del &  1)  printf(" ");
	if (del &  2)  printf("  ");
	if (del &  4)  printf("    ");
	if (del &  8)  printf("        ");
	if (del & 16)  printf("                ");
        for (i = 0; i + 32 <= del; i += 32)
	  printf("                                ");
	printf(CSI "%liD", prompterdata.after + del);
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
	      prompterdata.mark = 0;
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
	printf(CSI "D");
	prompt_print_after(0, prompterdata.after, true);
	std::flush(std::cout);
	bool neg = prompterdata.mark < 0;
	if (neg)
	  prompterdata.mark = -(prompterdata.mark);
	if (prompterdata.mark - 1 > prompterdata.before)
	  prompterdata.mark--;
	else if (prompterdata.mark - 1 == prompterdata.before)
	  prompterdata.mark = 0;
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
    if (prompterdata.before == 0)
      {
	__bell();
      }
    else
      {
	printf(CSI "D");
	prompt_left_buffer();
	if (prompterdata.mark - 1 > prompterdata.before)
	  {
	    printf(CSI "44m");
	    prompt_print_after(0, 1);
	    printf(CSI "49m");
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
	    printf(CSI "44m");
	    prompt_print_after(0, 1);
	    printf(CSI "49m");
	  }
	printf(CSI "C");
	prompt_right_buffer();
        if (prompterdata.mark - 1 >= prompterdata.before)
	  {
	    printf(CSI "D");
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
  void prompt_redraw(const std::string& instruction)
  {
    std::cout << CSI "H" CSI "2J" << instruction;
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
	printf(CSI "%liC", n = prompterdata.mark - prompterdata.before);
	for (i = 0; i < n; i++)
	  prompt_right_buffer();
      }
    else
      {
	printf(CSI "%liD", n = prompterdata.before - prompterdata.mark);
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
  void prompt_noop()
  {
    // noop
  }
  
  
  /**
   * Prompt the user for an arbitrary string
   * 
   * @param   instruction  Instruction for the user
   * @param   previous     Previous entry hook
   * @param   next         Next entry hook
   * @param   done         Entry done hook
   * @return               The string provided by the user, empty string is returned if aborted
   */
  std::string promptArbitrary(const std::string& instruction, void (*previous)(void), void (*next)(void), void (*done)(void)) /* TODO colouring hooks and more editing command */
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
	  case '\n':
	    done();
	    if (prompterdata.reading)
	      {
		std::cout << std::endl << instruction;
		prompterdata.mark = 0;
		prompt_print_before(0, prompterdata.before);
		prompt_print_after(0, prompterdata.after);
		std::flush(std::cout);
	      }
	    break;
	    
	  case CTRL('D'):
	    prompt_done();
	    break;
	    
	  case '\b': case 127:
	    prompt_erase();
	    break;
	    
          case '\0':
	    if (prompterdata.ignoreNUL)
	      break;
	  case CTRL('C'):
	    prompt_mark();
	    break;
	    
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
	      else
		{
	          #ifdef DEBUG
		    std::cerr << prompterdata.ansi << std::endl;
		    std::flush(std::cerr);
	          #endif
		}
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
	  case CTRL('T'):
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
  
  
  /**
   * Prompt the user for an alternative and return the index
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptIndex(const std::string& instruction, const std::vector<std::string>& alternatives, void (*previous)(void), void (*next)(void))
  {
    std::string input = promptList(instruction, alternatives, previous, next);
    if (input == "")
      return -1;
    for (long i = 0, n = alternatives.size(); i < n; i++)
      if (input == alternatives[i])
	return i;
    return -1;
  }
  
  
  /**
   * Prompt the user for an alternative
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The select alternative
   */
  std::string promptList(const std::string& instruction, const std::vector<std::string>& alternatives, void (*previous)(void), void (*next)(void))
  {
    prompterdata.alternatives = alternatives;
    std::sort(prompterdata.alternatives.begin(), prompterdata.alternatives.end());
    std::string input = promptArbitrary(instruction, previous, next, prompt_alternative);
    if (input != "")
      for (const std::string& alternative : alternatives)
	if (input == alternative)
	  return alternative;
    return "";
  }
  
  
  /**
   * Prompt the user for a file
   * 
   * @param   instruction   Instruction for the user
   * @param   loadfile      Whether to load the file
   * @param   previous      Previous entry hook
   * @param   next          Next entry hook
   * @return                The selected file, or if loadfile is true, its content
   */
  std::string promptFile(const std::string& instruction, bool loadfile, void (*previous)(void), void (*next)(void))
  {
    std::string input = promptArbitrary(instruction, previous, next, prompt_file);
    if (input != "")
      {
	struct stat filestat;
	char* cstr = (char*)(input.c_str());
	if (prompt_stat(cstr, &filestat) == -1)
	  return "";
	
	if (loadfile == false)
	  return input;
	
	long blocksize = (long)(filestat.st_blksize);
        long filesize = (long)(filestat.st_size);
	char* data = (char*)malloc(filesize + 1);
	char* buf = (char*)malloc(blocksize);
	char* filename = (char*)(input.c_str());
	FILE* file = fopen(filename, "r");
	if (file == nullptr)
	  {
	    std::flush(std::cout << "Unable to read file" << std::endl);
	    free(buf);
	    free(data);
	    return "";
	  }
	long ptr = 0, n, i, nul = 0;
	
	while (ptr < filesize)
	  {
	    n = (ptr + blocksize <= filesize) ? blocksize : (filesize - ptr);
	    fread(buf, 1, n, file); // =: n
	    for (i = 0; i < n; i++)
	      if ((*(data + ptr++ - nul) = *(buf + i)) == 0)
		nul++;
	  }
	
	fclose(file);
	free(buf);
	*(data + ptr) = 0;
	std::string rc = std::string(data);
	free(data);
	return rc;
      }
    return "";
  }
  
  
  /**
   * Prompt multiple item selection
   * 
   * @param   instruction   Instruction for the user
   * @param   selectcount   The number of items that can be choosed
   * @param   items         The items list from which to choose
   * @return                Selected items
   */
  std::vector<std::string> promptMulti(const std::string& instruction, long selectcount, const std::vector<std::string>& items)
  {
    long remaining = selectcount;
    long above = 0, current = 0, below;
    
    size_t selectedn = (items.size() + 7) >> 3;
    char* selected = (char*)malloc(selectedn);
    for (size_t i = 0; i < selectedn; i++)
      *(selected + i) = 0;
    
    __store_tty();
    
    bool reading = true;
    
    
    while (reading)
      {
	struct winsize termsize;
	int termheight = 45;
	for (int fd = 1; fd <= 3; fd++)
	  if (ioctl(fd % 3, TIOCGWINSZ, &termsize) != -1)
	    {
	      termheight = termsize.ws_row;
	      break;
	    }
	long dispheight = termheight - 5, disp = dispheight;
	if (disp > (long)(items.size()) - above)
	  disp = items.size() - above;
	
	below = items.size() - above - dispheight;
	if (below < 0)
	  below = 0;
	
	std::cout << CSI "?1049h" CSI "H" CSI "2J" CSI "?25l" << instruction << std::endl
		  << "Remaining: " << remaining << std::endl << std::endl;
	
	bool sel;
	for (long i = 0, j; i < disp; i++)
	  {
	    j = i + above;
	    sel = *(selected + (j >> 3)) & (1 << (j & 7));
	    std::cout << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
		      << (i + above == current ? CSI "01;34m" : "")
	              << items[i + above]
		      << (i + above == current ? CSI "21;39m" : "")
		      << std::endl;
	  }
	
	std::cout << CSI << termheight << ";1H" CSI "K"
		  << "(above: " << above << ")(below: " << below << ")";
	std::flush(std::cout);
	
	
	bool readinginner = true;
	while (reading && readinginner)
	  {
	    char c;
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = '\n';
	    
	    switch (c)
	      {
	      case '\n':
	      case CTRL('D'):
		if (remaining > 0)
		  {
		    __bell();
		    break;
		  }
		reading = false;
		break;
		
	      case CTRL('L'):
		readinginner = false;
		break;
		
	      case CTRL('G'):
		for (size_t i = 0; i < selectedn; i++)
		  *(selected + i) = 0;
		reading = false;
		break;
		
	      case ' ':
	      case 'C':
	      case 'D':
		sel = *(selected + (current >> 3)) & (1 << (current & 7));
		if (c == 'C')
		  {
		    if (sel)
		      break;
		  }
		else if (c == 'D')
		  if (sel == false)
		    break;
		sel ^= true;
		remaining += sel ? -1 : 1;
		if (remaining < 0)
		  {
		    remaining++;
		    __bell();
		    break;
		  }
		*(selected + (current >> 3)) ^= 1 << (current & 7);
		std::cout << CSI << (current - above + 4) <<  ";1H"
			  << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
			  << CSI "01;34m" << items[current] << CSI "21;39m"
		          << CSI "2;1H" CSI "K"
			  << "Remaining: " << remaining;
		std::flush(std::cout);
		break;
		
	      case 'A':
		current--;
	        if (current < 0)
		  {
		    current++;
		    break;
		  }
		if (current < above)
		  {
		    above -= ((termheight - 5) >> 1) | ((termheight - 5) & 1);
		    if (above < 0)
		      above = 0;
		    readinginner = false;
		  }
		else
		  {
		    sel = *(selected + ((current + 1) >> 3)) & (1 << ((current + 1) & 7));
		    std::cout << CSI << (current + 1 - above + 4) <<  ";1H"
			      << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
			      << items[current + 1];
		    sel = *(selected + (current >> 3)) & (1 << (current & 7));
		    std::cout << CSI << (current - above + 4) <<  ";1H"
			      << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
			      << CSI "01;34m" << items[current] << CSI "21;39m";
		    std::flush(std::cout);
		  }
		break;
		
	      case 'B':
		current++;
		if (current == (long)(items.size()))
		  {
		    current--;
		    break;
		  }
		if (current >= disp + above)
		  {
		    above += ((termheight - 5) >> 1) | ((termheight - 5) & 1);
		    readinginner = false;
		  }
		else
		  {
		    sel = *(selected + ((current - 1) >> 3)) & (1 << ((current - 1) & 7));
		    std::cout << CSI << (current - 1 - above + 4) <<  ";1H"
			      << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
			      << items[current - 1];
		    sel = *(selected + (current >> 3)) & (1 << (current & 7));
		    std::cout << CSI << (current - above + 4) <<  ";1H"
			      << (sel ? "[" CSI "01;32mX" CSI "21;39m] " : "[ ] ")
			      << CSI "01;34m" << items[current] << CSI "21;39m";
		    std::flush(std::cout);
		  }
		break;
	      }
	  }
      }
    
    
    std::cout << CSI "?1049l" CSI "H" CSI "2J" CSI "?25h";
    std::flush(std::cout);
    __restore_tty();
    
    std::vector<std::string> rc = std::vector<std::string>();
    for(size_t i = 0; i < selectedn; i++)
      if ((*(selected + i)))
	for (size_t j = 0; j < 8; j++)
	  if ((*(selected + i) & (1 << j)))
	    rc.push_back(items[(i << 3) | j]);
    
    free(selected);
    return rc;
  }
  
  
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
  long promptDialogue(char colour, const std::string& name, const std::string& message, const std::vector<std::string>& alternatives, char spacing)
  {
    __store_tty();
    long selected = 0;
    long rc = 0;
    
  _redo:
    std::cout << CSI "?25l" CSI "H" CSI "2J" CSI "01;3" << (int)colour << "m" << name << CSI "21;39m" << std::endl
	      << std::endl
	      << message << std::endl
	      << std::endl;
    
    if (alternatives.size() == 0)
      {
	std::cout << CSI "01m  [ Press enter or spacebar to continue ]" CSI "21m" << std::endl << std::endl;
	std::flush(std::cout);
	
	char lastc, c = 0;
	for (;;)
	  {
	    lastc = c;
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = '\n';
	    
	    if ((c == ' ') || (c == '\n') || ((c == 'C') && (lastc == '[')))
	      break;
	    if (c == CTRL('G'))
	      {
		rc = -1;
		break;
	      }
	    if (c == CTRL('L'))
	      goto _redo;
	  }
      }
    else
      {
	#define __index(i)  ((char)((((i) + 1) <= 10) ? ('0' + (((i) + 1) % 10)) : ('a' + (((i) + 1) - 11))))
	
	long* linemap = new long[alternatives.size() + 1];
	long totallines = 0;
	long last = alternatives.size() - 1;
	
	std::vector<std::string> alts = {};
	
        #define __printdialogue(alt, i)						     \
	  std::cout << CSI "01m" CSI "31m" << __index(i) << CSI "39m." CSI "21m  ";  \
	  if (i == selected)							     \
	    std::cout << CSI "01;34m";						     \
	  std::cout << (alt);							     \
	  if (i == selected)							     \
	    std::cout << CSI "21;39m";						     \
	  for (char _i_ = 0; _i_ <= spacing; _i_++)				     \
	    std::cout << std::endl
	
	
	long index = 0;
	for (const std::string& alternative : alternatives)
	  {
	    int lines = 0;
	    const char* cstr = alternative.c_str();
	    while ((*cstr))
	      if (*cstr++ == '\n')
		lines++;
	    cstr = alternative.c_str();
	    char* str = (char*)malloc(lines * 4 + 1 + alternative.size());
	    char* _str = str;
	    char chr;
	    while ((chr = *str++ = *cstr++))
	      if (chr == '\n')
		{
		  *str++ = ' ';
		  *str++ = ' ';
		  *str++ = ' ';
		  *str++ = ' ';
		}
	    alts.push_back(std::string(_str));
	    free(_str);
	    __printdialogue(alts[index], index);
	    linemap[index++] = totallines;
	    totallines += lines + spacing + 1;
	  }
	linemap[alternatives.size()] = totallines + spacing;
	
	
	std::flush(std::cout);
	
	#define __printdialogue2(i, j)				       \
	  std::cout << CSI << (totallines - linemap[i]) << "A";	       \
	  __printdialogue(alts[i], i);				       \
	  if (totallines - linemap[i + 1] > 0)			       \
	    std::cout << CSI << (totallines - linemap[i + 1]) << "B";  \
	  std::cout << CSI << (totallines - linemap[j]) << "A";	       \
	  __printdialogue(alts[j], j);				       \
	  if (totallines - linemap[j + 1] > 0)			       \
	    std::cout << CSI << (totallines - linemap[j + 1]) << "B"
	
	char lastc = 0, c = 0;
	for (;;)
	  {
	    lastc = c;
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = CTRL('G');
	    
	    if ((c == ' ') || (c == '\n') || ((lastc == '[') && (c == 'C')))
	      {
		rc = selected;
		break;
	      }
	    if (c == CTRL('G'))
	      {
		rc = -1;
		break;
	      }
	    if (c == CTRL('L'))
	      {
		delete[] linemap;
		goto _redo;
	      }
	    
	    if ((lastc == '[') && (c == 'A'))
	      {
		if (selected == 0)
		  continue;
		selected--;
		__printdialogue2(selected + 1, selected);
		std::flush(std::cout);
	      }
	    else if ((lastc == '[') && (c == 'B'))
	      {
		if ((size_t)(selected + 1) == alts.size())
		  continue;
		selected++;
		__printdialogue2(selected - 1, selected);
		std::flush(std::cout);
	      }
	    
	    if (lastc == '[')
	      continue;
	    
	    long newsel = -1;
	    if (('1' <= c) && (c <= '9') && (c <= __index(last)))
	      newsel = (long)(c - '1');
	    else if ((c == '0') && (alts.size() >= 10))
	      newsel = 9;
	    else if (('a' <= c) && (c <= __index(last)))
	      newsel = (long)(c - 'a' + 10);
	    
	    if (newsel >= 0)
	      {
		long oldsel = selected;
		__printdialogue2(oldsel, newsel);
		std::flush(std::cout);
		selected = newsel;
		break;
	      }
	  }
	
	delete[] linemap;
	
	#undef __printdialogue2
	#undef __printdialogue
	#undef __index
      }
    
    std::flush(std::cout << CSI "H" CSI "2J" CSI "?25h");
    __restore_tty();
    
    return rc;
  }
  
  
  /**
   * Prompt the user for a menu alternative and return index
   * 
   * @param   instruction   Instruction for the user
   * @param   alternatives  Alternatives
   * @return                The index of the select alternative, −1 if aborted
   */
  long promptMenu(const std::string& instruction, const std::vector<std::string>& alternatives)
  {
    __store_tty();
    std::cout << CSI "?1049h" CSI "?25l";
    
    long selected = 0;
    bool reading = true;
    char c;
    while (reading)
      {
	std::flush(std::cout << CSI "H" CSI "2J" << instruction << std::endl << std::endl);
	int index = 0;
	for (const std::string& alt : alternatives)
	  if (index++ == selected)
	    std::cout << CSI "01;34m" << alt << CSI "21;39m" << std::endl;
	  else
	    std::cout << alt << std::endl;
	std::flush(std::cout);
	
	bool readinginner = true;
	while (readinginner)
	  {
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = CTRL('G');
	    
	    switch (c) /* TODO document this in the info manual */
	      {
	      case CTRL('G'):
		reading = readinginner = false;
		selected = -1;
		break;
		
	      case CTRL('L'):
		readinginner = false;
		break;
		
	      case CTRL('D'):
	      case ' ':
	      case 'd':
	      case 'D':
	      case 'C':
	      case '\n':
		reading = readinginner = false;
		break;
		
	      case 'A':
	      case 'B':
		if (selected == (c == 'A' ? 0 : (long)(alternatives.size() - 1)))
		  break;
		std::cout << CSI << (selected + 1) << ";1H" << alternatives[selected];
		selected += (c == 'A' ? -1 : 1);
		std::flush(std::cout << CSI << (selected + 1) << ";1H" CSI "01;34m" << alternatives[selected] << CSI "21;39m");
		break;
	      }
	  }
      }
    
    std::flush(std::cout << CSI "?1049l" CSI "?25h" CSI "H" CSI "2J");	
    __restore_tty();
    return selected;
  }
  
  
  /**
   * Print a list in columns
   * 
   * @param  items  The items to print
   */
  void columnate(const std::vector<std::string>& items)
  {
    struct winsize termsize;
    int termwidth = 120;
    for (int fd = 1; fd <= 3; fd++)
      if (ioctl(fd % 3, TIOCGWINSZ, &termsize) != -1)
	{
	  termwidth = termsize.ws_col;
	  break;
	}
    termwidth += 2;
    
    int width = 0;
    std::vector<int> widths = std::vector<int>();
    for (const std::string& item : items)
      {
	int w = 0, n = 0;
	char* cstr = (char*)(item.c_str());
	char c = 1;
	symbol sym = 0;
	while ((c))
	  {
	    if ((c & 0xC0) != 0x80)
	      {
		if      ((0x0300 <= sym) && (sym <= 0x036F))  w--;
		else if ((0x20D0 <= sym) && (sym <= 0x20FF))  w--;
		else if ((0x1DC0 <= sym) && (sym <= 0x1DFF))  w--;
		else if ((0xFE20 <= sym) && (sym <= 0xFE2F))  w--;
	      }
	    if ((c = *cstr++) == 0)
	      break;
	    if ((c & 0x80) == 0)
	      {
		w++;
	        sym = 0;
	      }
	    else if ((c & 0xC0) == 0xC0)
	      {
		w++;
		while ((c & 0x80))
		  {
	  	    c <<= 1;
		    n++;
		  }
		sym = ((symbol)c & 127) >> n;
	      }
	    else
	      sym = (sym << 6) | (sym & 0x3F);
	  }
	widths.push_back(w);
      }
    for (int w : widths)
      if (width < w)
	width = w;
    width += 2;
    
    int cols = termwidth / width;
    int rows = (items.size() + cols - 1) / cols;
    
    std::vector<std::vector<std::string>> columns = std::vector<std::vector<std::string>>();
    for (int i = 0; i < cols; i++)
      columns.push_back(std::vector<std::string>());
    
    char* spaces = (char*)malloc(width * 16 + 1);
    
    int y = 0, x = 0, i, j = 0, w;
    for (const std::string& item : items)
      {
	i = 0;
	char* cstr = (char*)(item.c_str());
	while ((*(cstr + i)))
	  {
	    *(spaces + i) = *(cstr + i);
	    i++;
	  }
	w = widths[j++];
	while (w < width)
	  {
	    *(spaces + i++) = ' ';
	    w++;
	  }
	*(spaces + i) = 0;
	std::string cell = std::string(spaces);
	columns[x].push_back(cell);
	if (++y == rows)
	  {
	    x++;
	    y = 0;
	  }
      }
    
    free(spaces);
    
    int diff = rows * cols - items.size();
    if ((diff > 2) && (rows > 1))
      {
	int c = cols - 1;
	diff--;
	while (diff > 0)
	  {
	    for (int i = 0; i < diff; i++)
	      {
		if (columns[c - 1].size() == 0)
		  break;
		columns[c].insert(columns[c].begin(), columns[c - 1][columns[c - 1].size() - 1]);
		columns[c - 1].pop_back();
	      }
	    c--;
	    diff--;
	  }
      }
    
    std::vector<std::vector<std::string>> lines = std::vector<std::vector<std::string>>();
    for (int r = 0; r < rows; r++)
      {
	lines.push_back(std::vector<std::string>());
	for (int c = 0; c < cols; c++)
	  if (r < (long)(columns[c].size()))
	    lines[r].push_back(columns[c][r]);
      }
    
    for (int r = 0; r < rows; r++)
      {
	auto line = lines[r];
	cols = line.size();
	for (int c = 0; c < cols; c++)
	  if (c + 1 == cols)
	    std::cout << line[c].substr(0, width - 2);
	  else
	    std::cout << line[c];
	std::cout << std::endl;
      }
  }
  
  
  
  #undef __bell
  #undef __malloc_string
  
}

