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
    #define __print(X, Y)					\
      std::cout << (i == index ? CSI "02m" : "")		\
		<< X						\
		<< (Y == nullptr ? "(empty)" : Y->name);	\
      if ((Y != nullptr) && (Y->quantity_limit > 1))		\
	std::cout << " (" << Y->quantity << ")";        	\
      std::cout << CSI "22m" << std::endl
    
    __store_tty();
    
    std::cout << CSI "?25l";
    
    Item* hand = nullptr;
    size_t page = 0, index = 0;
    
    Inventory& inventory = (*(characters))[character]->character->record.inventory;
    std::vector<Item*>& personal = inventory.personal;
    std::vector<Item*>& ground = (*(characters))[character]->area->items;
    
    std::vector<Item**> equipment = std::vector<Item**>();
    for (Item*& slot : inventory.left_hand)
      equipment.push_back(&slot);
    for (Item*& slot : inventory.quiver)
      equipment.push_back(&slot);
    for (Item*& slot : inventory.quick_items)
      equipment.push_back(&slot);
    equipment.push_back(&(inventory.right_hand));
    equipment.push_back(&(inventory.headgear));
    equipment.push_back(&(inventory.amulet));
    for (Item*& slot : inventory.rings)
      equipment.push_back(&slot);
    equipment.push_back(&(inventory.body));
    equipment.push_back(&(inventory.gauntlets));
    equipment.push_back(&(inventory.girdle));
    equipment.push_back(&(inventory.boots));
    equipment.push_back(&(inventory.cloak));
    
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
		    else if ((c == 'A') || (c == 'B'))
		      {
			c = CTRL((c == 'A' ? 'P' : 'N'));
			readinginner = true;
		      }
		  }
		break;
		
	      case '1': /* Equipped items */
	      case '2': /* Personal inventory */
	      case '3': /* Item on the ground */
		page = c - '1';
		index = 0;
		index++;
	      case CTRL('P'): /* Navigate up */ /* XXX this could be speed up */
		index -= 2;
	      case CTRL('N'): /* Navigate down */
		index++;
		if (index < 0)
		  index = 0;
		else
		  {
		    size_t n = page == 2 ? ground.size() + 1
			     : page = 1 ? personal.size() 
			     : inventory.left_hand.size() + inventory.quiver.size()
			     + inventory.quick_items.size() + inventory.rings.size() + 8;
		    if (index >= n)
		      index = n - 1;
		  }
	      case CTRL('L'): /* Redraw */
		std::cout << CSI "H" CSI "2J"
			  << "Temporary slot: "
			  << (hand == nullptr ? "(empty)" : hand->name);
		if ((hand != nullptr) && (hand->quantity_limit > 1))
		  std::cout << " (" << hand->quantity << ")";
		std::cout << std::endl << std::endl;
		if (page == 0)
		  {
		    size_t i = 0;
		    for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
		      {
			__print("Left hand " << j << " ", inventory.left_hand[j]); i++;
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__print("Quiver " << j << "    ", inventory.quiver[j]); i++;
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__print("Quick item " << j << "", inventory.quick_items[j]); i++;
		      }
		    __print("Right hand  ", inventory.right_hand); i++;
		    __print("Headgear    ", inventory.headgear); i++;
		    __print("Amulet      ", inventory.amulet); i++;
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__print("Ring " << j << "      ", inventory.rings[j]); i++;
		      }
		    __print("Body        ", inventory.body); i++;
		    __print("Gauntlets   ", inventory.gauntlets); i++;
		    __print("Girdle      ", inventory.girdle); i++;
		    __print("Boots       ", inventory.boots); i++;
		    __print("Cloak       ", inventory.cloak); i++;
		  }
		else if (page == 1)
		  for (size_t i = 0, n = personal.size(); i < n; i++)
		    {
		      __print((i < 10 ? "Personal  " : "Personal ") << i, personal[i]);
		    }
		else if (page == 2)
		  {
		    for (size_t i = 0, n = ground.size(); i < n; i++)
		    {
		      __print("Ground " << i, ground[i]);
		    }
		    size_t i = ground.size(); 
		    __print("Ground " << i, nullptr);
		  }
		break;
		
	      /* XXX many things here gound be speed up */
	      case 'd': /* Drop temporary slot item on the ground */
		if (hand == nullptr)
		  break;
		ground.push_back(hand);
		hand = nullptr;
		readinginner = true;
		c = CTRL('L');
		break;
		
	      case 'D': /* Drop item on the ground */
		if ((page == 2) && (index < ground.size()))
		  {
		    ground.push_back(ground[index]);
		    ground.erase(index);
		  }
		else if ((page == 1) && (personal[index] != nullptr))
		  {
		    ground.push_back(personal[index]);
		    personal[index] = nullptr;
		  }
		else if ((page == 0) && (*(equipment[index]) != nullptr))
		  {
		    ground.push_back(*(equipment[index]));
		    *(equipment[index]) = nullptr;
		  }
		else
		  break;
		readinginner = true;
		c = CTRL('L');
		break;
		
	      case 'p': /* Pick up item to temporary slot */
		if ((hand))
		  break;
		if ((page == 2) && (index < ground.size()))
		  {
		    hand = ground[index];
		    ground.erase(index);
		  }
		else if ((page == 1) && (personal[index] != nullptr))
		  {
		    hand = personal[index];
		    personal[index] = nullptr;
		  }
		else if ((page == 0) && (*(equipment[index]) != nullptr))
		  {
		    hand = *(equipment[index]);
		    *(equipment[index]) = nullptr;
		  }
		else
		  break;
		readinginner = true;
		c = CTRL('L');
		break;
		
	      case 's': /* Swap item with temporary slot */
		break;
		
	      case 'e': /* Examine item in slot */
		break;
		
	      case 'E': /* Examine item in temporary slot */
		break;
		
	      case 'P': /* Give item to another party member */
		break;
		
	      case CTRL('G'): /* Abort */
		if ((hand))
		  ground.push_back(hand);
		hand = nullptr;
	      case CTRL('D'): /* Complete */
		if (hand == nullptr)
		  reading = false;
		break;
	      }
	  }
      }
    
    std::flush(std::cout << CSI "?25l");
    
    __restore_tty();
    #undef __print
  }
  
}

