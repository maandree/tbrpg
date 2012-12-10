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
   * Constructor
   */
  BasicSenario::BasicSenario() : Senario()
  {
    this->rules.party_size = 2;
    this->rules.party_start_size = 2;
    this->rules.inventory_prototype = (Inventory&)*(Inventory*)(this->rules.inventory_prototype.fork());
    this->rules.inventory_prototype.personal[0] = new Gold();
    this->rules.inventory_prototype.personal[0]->quantity = 400;
    cleaner::getInstance().enqueueDelete(&(this->rules.inventory_prototype));
  }
  
  /**
   * Destructor
   */
  BasicSenario::~BasicSenario()
  {
    // do nothing
  }
  
  
  
  /**
   * This is invoked when the senario starts.
   * The prologue, and perhaps a short tutorial,
   * should be displayed.
   */
  void BasicSenario::start()
  {
    page("This is a simple demo senario.\n"
	 "\n"
	 "You stand outside an inn, where you purchase items\n"
	 "such as armour and weapons that your need in your\n"
	 "quest. You mission is to the legendary sword known\n"
	 "as Sword of Legends.");
    
    promptDialogue(2, "Tutor", "", {});
  }
  
  
  /**
   * Gets the name of the game senario
   * 
   * @return  The name of the game senario
   */
  std::string BasicSenario::getTitle()
  {
    return "Basic game senario demo";
  }
  
}

