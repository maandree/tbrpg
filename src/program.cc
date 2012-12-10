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
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

#include "cleaner.hpp"
#include "prompter.hpp"
#include "Senario.hpp"
#include "CharacterCreator.hpp"

#include "BasicSenario.hpp"


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
    
    /** Initialise random **/
    unsigned a, d;
    asm("cpuid");
    asm volatile("rdtsc" : "=a" (a), "=d" (d));
    srand(((long long)a) | (((long long)d) << 32LL));
    
    std::vector<std::string> senarioTitles = {BasicSenario::getTitle()};
    
    long senarioIndex = promptDialogue(4, "Welcome to tbrpg!",
		 "Select a game senario."                        "\n"
		                                                 "\n"
		 "Use the up and down arrow keys to nagivate,"   "\n"
		 "and press enter, spacebar or the right arrow"  "\n"
		 "key to start the select senario. You can"      "\n"
		 "also use the letter in front of the senario."  "\n"
		                                                 "\n"
		 "You should play with the manual by your side," "\n"
		 "run `info tbrpg` or open a graphical if you"   "\n"
		 "have one installed, jfbview can view them in"  "\n"
		 "the TTY."                                      "\n"
		                                                 "\n"
		 "If you want to exit, press <control>g."        "\n",
		 senarioTitles, 0);
    
    Senario* _senario = nullptr;
    
    if (senarioIndex == 0)
      _senario = new BasicSenario();
    
    if (_senario == nullptr)
      {
	cleaner::clean();
	return 0;
      }
    
    Senario& senario = *_senario;
    CharacterCreator characterCreator = CharacterCreator(senario.rules);
    
    std::vector<CharacterSheet*> sheets = std::vector<CharacterSheet*>(senario.rules.party_start_size);
    bool partyCreated = promptSlots<CharacterSheet>("Create your party, you need at least one character.",
                                                    true, 1, sheets,
						    [&] () -> CharacterSheet* { return characterCreator.create(); },
						    [] (CharacterSheet* sheet, bool selected) -> void {
						      if (sheet == nullptr)
							std::cout << (selected ? "\033[01m(empty)\033[21m" : "(empty)");
						      else
							{
							  std::cout << (selected ? "\033[01;3" : "\033[3") << (int)(sheet->colour) << "m";
							  std::cout << sheet->name << "\033[21;39m";
							}
						    });
    
    if (partyCreated == false)
      {
	cleaner::clean();
	return 0;
      }
    
    senario.partyFormed();
    senario.start();
    
    
    delete _senario;
    cleaner::clean();
    return 0;
  }
}



/**
 * This the main entry point of the program
 * 
 * @param   argc  The number of elements in `argv`
 * @param   argv  Command line arguments, including the execute file
 * @return        Exit value, 0 if successful
 */
int main(int argc, char** argv)
{
  return tbrpg::__main__(argc, argv);
}

