// -*- mode: c++, encoding: utf-8 -*-
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#include "../src/pager.hpp"


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
  /**
   * This the main entry point of the program
   * 
   * @param   argc  The number of elements in `argv`
   * @param   argv  Command line arguments, including the execute file
   * @return        Exit value, 0 if successful
   */
  int __main__(int argc, char** argv)
  {
    (void) argc;
    (void) argv;
    
    struct stat filestat;
    if (stat("./test/pager.text", &filestat) == -1)
      return 1;
    
    long blocksize = (long)(filestat.st_blksize);
    long filesize = (long)(filestat.st_size);
    char* data = (char*)malloc(filesize + 1);
    char* buf = (char*)malloc(blocksize);
    FILE* file = fopen("./test/pager.text", "r");
    if (file == 0)
      {
	free(buf);
	free(data);
	return 2;
      }
    long ptr = 0, n, i, nul = 0;
    
    while (ptr < filesize)
      {
	n = (ptr + blocksize <= filesize) ? blocksize : (filesize - ptr);
	(long)(fread(buf, 1, n, file));
	for (i = 0; i < n; i++)
	  if ((*(data + ptr++ - nul) = *(buf + i)) == 0)
	    nul++;
      }
    
    fclose(file);
    free(buf);
    *(data + ptr) = 0;
    std::string document = std::string(data);
    free(data);
    
    pager(document);
    
    return 0;
  }
}

int main(int argc, char** argv)
{
  return tbrpg::__main__(argc, argv);
}

