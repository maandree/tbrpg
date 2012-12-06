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
#include "pager.hpp"


#define  ESC  "\033"  /* since \e generates a non-ISO-standard warning */
#define  CSI  ESC "["


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
  /* Text browser */
  
  
  /**
   * Display a long text
   * 
   * @param  text  The text, wrapped to 60 columns, may contain form feeds
   */
  void pager(std::string text)
  {
    if (text == "")
      return;
    
    int WRAP = 60;
    
    
    std::vector<std::vector<std::string>> pages = std::vector<std::vector<std::string>>();
    std::vector<std::string> curpage = std::vector<std::string>();
    long ptr = 0, size = 64;
    char* curline = (char*)malloc(size);
    char* cstr = (char*)(text.c_str());
    char* tmp;
    char c;
    
    bool reading = true;
    while (reading)
      {
	if ((c = *cstr++) == 0)
	  {
	    c = CTRL('L');
	    reading = false;
	  }
	
	if (ptr == size)
	  {
	    tmp = (char*)malloc(size <<= 1);
	    for (long i = 0; i < ptr; i++)
	      *(tmp + i) = *(curline + i);
	    free(curline);
	    curline = tmp;
	  }
	
	switch (c)
	  {
	  case '\n':
	  case CTRL('L'):
	    *(curline + ptr) = 0;
	    ptr = 0;
	    curpage.push_back(std::string(curline));
	    
	    if (c == CTRL('L'))
	      {
		pages.push_back(curpage);
		curpage = std::vector<std::string>();
	      }
	    break;
	  
	  default:
	    *(curline + ptr++) = c;
	    break;
	}
      }
    
    
    struct termios saved_stty;
    struct termios stty;
    tcgetattr(STDIN_FILENO, &saved_stty);
    tcgetattr(STDIN_FILENO, &stty);
    stty.c_lflag &= ~(ICANON | ECHO | ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &stty);
    
    long page = 0;
    long line = 0;
    reading = true;
    curpage = pages[0];
    
    #define _ "          "
    std::string space60 = _ _ _ _ _ _;
    #undef _
    
    std::cout << CSI "?1049h" << CSI "?25l";
    
    while (reading)
      {
	struct winsize termsize;
	int termwidth = WRAP;
	int termheight = 25;
	for (int fd = 1; fd <= 3; fd++)
	  if (ioctl(fd % 3, TIOCGWINSZ, &termsize) != -1)
	    {
	      termwidth  = termsize.ws_col;
	      termheight = termsize.ws_row;
	      break;
	    }
	if (termwidth < WRAP)
	  termwidth = WRAP;
	
	int left = (termwidth - WRAP) >> 1;
	
        auto status = [&] (void) -> void
	  {  
	    std::cout << CSI << termheight << ";1H";
	    if (left > 0)
	      std::cout << CSI << left << "C";
	    std::cout << CSI "07m" << space60 << CSI "27m" CSI "60D";
	    printf("-- line %li to %li of %li -- page %li of %li --",
		   line + 1, line + termheight, (long)(curpage.size()),
		   page + 1, (long)(pages.size()));
	  };
	
	std::cout << CSI "H" CSI "2J";
	status();
	
	for (size_t i = line, s = line, n = curpage.size(); i < n; i++)
	  {
	    if (i - s == (size_t)(termheight - 1))
	      break;
	    std::cout << CSI << (i - s + 1) << ";" << (left + 1) << "H";
	    std::cout << curpage[line];
	  }
	
	std::flush(std::cout);
	
	bool readinginner = false;
	while (readinginner)
	  {
	    if (read(STDIN_FILENO, &c, 1) <= 0)
	      c = CTRL('G');
	    switch (c)
	      {
	      case 'q':
	      case 'Q':
	      case 'w':
	      case 'W':
	      case CTRL('C'):
	      case CTRL('D'):
	      case CTRL('G'):
		reading = false;
	      case CTRL('L'):
		readinginner = false;
		break;
		
	      case 'A':
		if (line == 0)
		  break;
	        line--;
	        readinginner = false;
		break;
		
	      case '\n':
	      case 'B':
		if (line + termheight >= (long)(curpage.size()))
		  break;
		std::cout << CSI << termheight << ";1H" CSI "K" << curpage[line + termheight];
		line++;
		status();
		std::flush(std::cout);
		break;
		
	      case 'C':
		if (page + 1 == (long)(pages.size()))
		  break;
		page++;
		readinginner = false;
		break;
		
	      case 'D':
		if (page == 0)
		  break;
		page--;
		readinginner = false;
		break;
		
	      case '5':
		line -= termheight - 1;
		if (line < 0)
		  line = 0;
		readinginner = false;
		break;
		
	      case '6':
		line += termheight - 1;
		if (line + termheight >= (long)(curpage.size()))
		  line = curpage.size() - termheight;
		if (line < 0)
		  line = 0;
		readinginner = false;
		break;
	      }
	  }
      }
    
    std::cout << CSI "?25h" << CSI "?1049l";
    std::flush(std::cout);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty);
  }
  
}


#undef CSI
#undef ESC

