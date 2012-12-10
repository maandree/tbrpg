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

#include "../src/prompter.hpp"


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
    
    
    std::vector<std::string> items = promptMulti("promptMulti: ", 10,
						 {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm",
					          "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"});
    for (std::string& item : items)
      std::cout << item << std::endl;
    std::flush(std::cout);
    
    std::cout << promptFile("promptFile(false): ", false);
    std::flush(std::cout << std::endl);
    
    std::cout << promptFile("promptFile(true): ", true);
    std::flush(std::cout << std::endl);
    
    std::cout << promptList("promptList: ", {"aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj", "kk", "ll", "mm",
	                                     "nn", "oo", "pp", "qq", "rr", "ss", "tt", "uu", "vv", "ww", "xx", "yy", "zz"});
    std::flush(std::cout << std::endl);
    
    std::cout << promptIndex("promptIndex: ", {"alpha", "beta", "gamma", "delta"});
    std::flush(std::cout << std::endl);
    
    std::cout << promptArbitrary("promptArbitrary: ");
    std::flush(std::cout << std::endl);
    
    std::cout << promptArbitrary("promptArbitrary: ");
    std::flush(std::cout << std::endl);
    
    if (promptDialogue(2, "Tutor", "This is just\na simple\ndialogue.", {}) != -1)
      std::flush(std::cout << promptDialogue(2, "Tutor", "Now you can select a reply.", {"one line", "two\nlines", "three\n\nlines"}) << std::endl);
    
    return 0;
  }
}

int main(int argc, char** argv)
{
  return tbrpg::__main__(argc, argv);
}

