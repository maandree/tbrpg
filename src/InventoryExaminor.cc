// -*- mode++ , coding: utf-8 -*-
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
      std::cout << (i == index ? CSI "01m" : "")		\
		<< X						\
		<< (Y == nullptr ? "(empty)" : Y->name);	\
      if ((Y != nullptr) && (Y->quantity_limit > 1))		\
	std::cout << " (" << Y->quantity << ")";        	\
      std::cout << CSI "21m" << std::endl
    
    __store_tty();
    
    std::cout << CSI "?25l";
    
    Item* hand = nullptr;
    Container* container = nullptr;
    size_t page = 0, index = 0;
    
    Inventory& inventory = (*(characters))[character]->character->record.inventory;
    std::vector<Item*>& personal = inventory.personal;
    std::vector<Item*>& ground = (*(characters))[character]->area->items;
    Item* temp = nullptr;
    
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
		      case 'S':
			c = '4';
			readinginner = true;
			break;
		      }
		  }
		else if (c == '[')
		  {
		    read(STDIN_FILENO, &c, 1);
		    char cc = c;
		    if (c == '1')
		      {
			switch (c)
			  {
			  case '1':
			  case '2':
			  case '3':
			  case '4':
			    readinginner = true;
			    break;
			  }
			read(STDIN_FILENO, &c, 1);
			if (c != '~')
			  readinginner = false;
			c = cc;
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
	      case '4': /* Opened container */
		if ((c == '4') and not (container))
		  break;
		page = c - '1';
		index = 0;
		index++;
	      case CTRL('P'): /* Navigate up */ /* XXX this could be speed up */
		index -= 2;
	      case CTRL('N'): /* Navigate down */
		index++;
		if (index == (size_t)(-1))
		  index = 0;
		else
		  {
		    size_t n = page == 3 ? container->contains.size() + 1
			     : page == 2 ? ground.size() + 1
			     : page == 1 ? personal.size() 
			     : inventory.left_hand.size() + inventory.quiver.size()
			     + inventory.quick_items.size() + inventory.rings.size() + 8;
		    if (index >= n)
		      index = n - 1;
		  }
	      case CTRL('L'): /* Redraw */
		/* XXX carry limit and current carry */
		/* std::cout << "Carry limit: " << this->calc->getCarryLimit(*c) << std::endl; */
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
			__print("Left hand " << (j + 1) << ":  ", inventory.left_hand[j]); i++;
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__print("Quiver " << (j + 1) << ":     ", inventory.quiver[j]); i++;
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__print("Quick item " << (j + 1) << ": ", inventory.quick_items[j]); i++;
		      }
		    __print("Right hand:   ", inventory.right_hand); i++;
		    __print("Headgear:     ", inventory.headgear); i++;
		    __print("Amulet:       ", inventory.amulet); i++;
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__print("Ring " << (j + 1) << ":       ", inventory.rings[j]); i++;
		      }
		    __print("Body:         ", inventory.body); i++;
		    __print("Gauntlets:    ", inventory.gauntlets); i++;
		    __print("Girdle:       ", inventory.girdle); i++;
		    __print("Boots:        ", inventory.boots); i++;
		    __print("Cloak:        ", inventory.cloak); i++;
		  }
		else if (page == 1)
		  for (size_t i = 0, n = personal.size(); i < n; i++)
		    {
		      __print((i < 9 ? "Personal  " : "Personal ") << (i + 1) << ": ", personal[i]);
		    }
		else if (page == 2)
		  {
		    for (size_t i = 0, n = ground.size(); i < n; i++)
		      {
			__print("Ground " << (i + 1) << ": ", ground[i]);
		      }
		    size_t i = ground.size();
		    std::cout << (i == index ? CSI "01m" : "")
			      << "Ground " << (i + 1) << ": (empty)"
			      << CSI "21m" << std::endl;
		  }
		else if (page == 3)
		  {
		    for (size_t i = 0, n = container->contains.size(); i < n; i++)
		      {
			__print(container->name << " " << (i + 1) << ": ", container->contains[i]);
		      }
		    size_t i = container->contains.size();
		    std::cout << (i == index ? CSI "01m" : "")
			      << container->name << " " << (i + 1) << ": (empty)"
			      << CSI "21m" << std::endl;
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
		if ((page == 3) && (index < container->contains.size()))
		  {
		    ground.push_back(container->contains[index]);
		    container->contains.erase(container->contains.begin() + index);
		  }
		else if ((page == 2) && (index < ground.size()))
		  {
		    ground.push_back(ground[index]);
		    ground.erase(ground.begin() + index);
		  }
		else if ((page == 1) && (personal[index] != nullptr))
		  {
		    ground.push_back(personal[index]);
		    personal[index] = nullptr;
		  }
		else if (page == 0)
		  {
		    size_t i = 0;
		    
		    #define  __drop(X)					\
		      if ((i == index) && (X != nullptr))		\
			{						\
			  ground.push_back(X);				\
			  X = nullptr;					\
			}			       			\
		      i++
		    
		    for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
		      {
			__drop(inventory.left_hand[j]);
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__drop(inventory.quiver[j]);
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__drop(inventory.quick_items[j]);
		      }
		    __drop(inventory.right_hand);
		    __drop(inventory.headgear);
		    __drop(inventory.amulet);
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__drop(inventory.rings[j]);
		      }
		    __drop(inventory.body);
		    __drop(inventory.gauntlets);
		    __drop(inventory.girdle);
		    __drop(inventory.boots);
		    __drop(inventory.cloak);
		    
		    #undef __drop
		  }
		else
		  break;
		readinginner = true;
		c = CTRL('L');
		break;
		
	      case 'p': /* Pick up item to temporary slot */
		if ((hand))
		  break;
		if ((page == 3) && (index < container->contains.size()))
		  {
		    if (container->contains[index]->stuck)
		      break;
		    hand = container->contains[index];
		    container->contains.erase(container->contains.begin() + index);
		  }
		else if ((page == 2) && (index < ground.size()))
		  {
		    if (ground[index]->stuck)
		      break;
		    hand = ground[index];
		    ground.erase(ground.begin() + index);
		  }
		else if ((page == 1) && (personal[index] != nullptr))
		  {
		    if (personal[index]->stuck)
		      break;
		    hand = personal[index];
		    personal[index] = nullptr;
		  }
		else if (page == 0)
		  {
		    size_t i = 0;
		    
		    #define  __pickup(X)			\
		      if ((i == index) && (X != nullptr))	\
			if (X->stuck == false)			\
			  {					\
			    hand = X;				\
			    X = nullptr;			\
			  }					\
		      i++
		    
		    for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
		      {
			__pickup(inventory.left_hand[j]);
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__pickup(inventory.quiver[j]);
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__pickup(inventory.quick_items[j]);
		      }
		    __pickup(inventory.right_hand);
		    __pickup(inventory.headgear);
		    __pickup(inventory.amulet);
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__pickup(inventory.rings[j]);
		      }
		    __pickup(inventory.body);
		    __pickup(inventory.gauntlets);
		    __pickup(inventory.girdle);
		    __pickup(inventory.boots);
		    __pickup(inventory.cloak);
		    
		    #undef __pickup
		    
		    if ((hand))
		      hand->event("pick_up", nullptr);
		  }
		else
		  break;
		if ((hand))
		  if ((page))
		    hand->event("pick_up", nullptr);
		readinginner = true;
		c = CTRL('L');
		break;
		
	      case 's': /* Swap item with temporary slot */
		#define ___swap(X, Y, Z)	\
		  temp = X;			\
		  X = Y;			\
		  Y = dynamic_cast<Z*>(temp)
		
		if ((page == 3) && (index < container->contains.size()))
		  {
		    if ((hand == nullptr) || (container->canHold(hand) == false))
		      break;
		    container->contains.push_back(hand);
		    hand = nullptr;
		  }
		else if ((page == 3) && (hand == nullptr))
		  {
		    if (container->contains[index]->stuck)
		      break;
		    hand = container->contains[index];
		    container->contains.erase(container->contains.begin() + index);
		  }
		else if (page == 3)
		  {
		    if ((container->contains[index] != nullptr) && (container->contains[index]->stuck))
		      break;
		    if (container->canHold(hand) == false)
		      break;
		    if (container->contains[index]->stuck)
		      break;
		    ___swap(hand, container->contains[index], Item);
		  }
		else if ((page == 2) && (index == ground.size()))
		  {
		    if (hand == nullptr)
		      break;
		    ground.push_back(hand);
		    hand = nullptr;
		  }
		else if ((page == 2) && (hand == nullptr))
		  {
		    if (ground[index]->stuck)
		      break;
		    hand = ground[index];
		    ground.erase(ground.begin() + index);
		  }
		else if (page == 2)
		  {
		    if ((ground[index] != nullptr) && (ground[index]->stuck))
		      break;
		    ___swap(hand, ground[index], Item);
		  }
		else if (page == 1)
		  {
		    if ((personal[index] != nullptr) && (personal[index]->stuck))
		      break;
		    ___swap(hand, personal[index], Item);
		  }
		else if (page == 0)
		  {
		    size_t i = 0;
		    Item* hand_before = hand;
		    
		    #define  __swap(X, Y)					\
		      if (i == index)						\
			if ((hand == nullptr) || (*hand >= PROTOTYPE(Y)))	\
			  if ((X == nullptr) || (X->stuck == false))		\
			    {							\
			      ___swap(hand, X, Y);				\
			    }							\
		      i++
		    
		    for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
		      {
			__swap(inventory.left_hand[j], Weapon);
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__swap(inventory.quiver[j], Ammunition);
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__swap(inventory.quick_items[j], QuickItem);
		      }
		    __swap(inventory.right_hand, RightHandItem);
		    __swap(inventory.headgear, Headgear);
		    __swap(inventory.amulet, Amulet);
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__swap(inventory.rings[j], Ring);
		      }
		    __swap(inventory.body, BodyArmour);
		    __swap(inventory.gauntlets, Gauntlets);
		    __swap(inventory.girdle, Girdle);
		    __swap(inventory.boots, Boots);
		    __swap(inventory.cloak, Cloak);
		    
		    #undef __swap
		    
		    if (hand_before != hand)
		      if ((hand))
			hand->event("pick_up", nullptr);
		  }
		else
		  break;
		if ((hand))
		  if ((page))
		    hand->event("pick_up", nullptr);
		readinginner = true;
		c = CTRL('L');
		#undef ___swap
		break;
		
	      case 'o': /* Open container */
		{
		  temp = nullptr;
		  if ((page == 3) && (index < container->contains.size()))
		    temp = container->contains[index];
		  else if ((page == 2) && (index < ground.size()))
		    temp = ground[index];
		  else if ((page == 1) && (personal[index] != nullptr))
		    temp = personal[index];
		  else if (page == 0)
		    {
		      size_t i = 0;
		      
		      #define  __open(X)			\
			if ((i == index) && (X != nullptr))	\
			  temp = X;				\
			i++
		      
		      for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
			{
			  __open(inventory.left_hand[j]);
			}
		      for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
			{
			  __open(inventory.quiver[j]);
			}
		      for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
			{
			  __open(inventory.quick_items[j]);
			}
		      __open(inventory.right_hand);
		      __open(inventory.headgear);
		      __open(inventory.amulet);
		      for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
			{
			  __open(inventory.rings[j]);
			}
		      __open(inventory.body);
		      __open(inventory.gauntlets);
		      __open(inventory.girdle);
		      __open(inventory.boots);
		      __open(inventory.cloak);
		      
		      #undef __open
		    }
		  else
		    break;
		  
		  if (temp == nullptr)
		    break;
		  if ((*temp >= PROTOTYPE(Container)) == false)
		    break;
		  if (*temp >= PROTOTYPE(EnvironmentContainer))
		    {
		      EnvironmentContainer* cont = static_cast<EnvironmentContainer*>(temp);
		      if (cont->locked)
			{
			  std::vector<long long>* weapon   = new std::vector<long long>();
			  std::vector<long long>* quiver   = new std::vector<long long>();
			  std::vector<long long>* equipped = new std::vector<long long>();
			  std::vector<long long>* personal = new std::vector<long long>();
			  std::vector<long long>** args = (std::vector<long long>**)malloc(4 * sizeof(std::vector<long long>*));
			  args[0] = weapon;
			  args[1] = quiver;
			  args[2] = equipped;
			  args[3] = personal;
			  
			  (void) weapon; /* XXX fill `weapon` with weapon quest item ID:s */
			  (void) quiver; /* XXX fill `quiver` with quiver quest item ID:s */
			  (void) equipped; /* XXX fill `equipped` with equipped quest item ID:s */
			  
			  std::vector<Item*> queue = std::vector<Item*>();
			  MapMinor* area = (*characters)[character]->area;
			  for (GameCharacter* player : *characters)
			    if (player->area == area)
			      for (Item* item : player->character->record.inventory.personal)
				if ((item))
				  queue.push_back(item);
			  while ((queue.size()))
			    {
			      Item* item = queue[queue.size() - 1];
			      queue.erase(queue.end() - 1);
			      if (item->implements("QuestItem"))
				personal->push_back(dynamic_cast<QuestItem*>(item)->id);
			      if (*item >= PROTOTYPE(Container))
				for (Item* subitem : static_cast<Container*>(item)->contains)
				  queue.push_back(subitem);
			    }
			  
			  cont->event("quest_unlock", args);
			  std::flush(std::cout << CSI "?25l");
			  
			  free(args);
			  delete weapon;
			  delete quiver;
			  delete equipped;
			  delete personal;
			  
			  if (cont->locked)
			    break; /* TODO allow unlocking */
			}
		      /* XXX traps */
		    }
		  container = static_cast<Container*>(temp);
		  temp = nullptr;
		  readinginner = true;
		  c = CTRL('L');
		  index = 0;
		  page = 3;
		}
		break;
		
	      case 'P': /* Give item to another party member */
		{
		  std::vector<std::string> names = std::vector<std::string>();
		  for (GameCharacter* p : *characters)
		    {
		      std::stringstream ss;
		      ss << "\033[3" << (char)((int)'0' + p->character->record.colour) << "m"
			 << p->character->record.name << CSI "39m";
		      names.push_back(ss.str());
		    }
		  long i = promptMenu("Select recipient:", names);
		  std::flush(std::cout << CSI "?25l");
		  if (i < 0)
		    break;
		  std::vector<Item*>& backpack = (*(characters))[i]->character->record.inventory.personal;
		  i = 0;
		  for (Item* slot : backpack)
		    if (slot == nullptr)
		      {
			backpack[i] = hand;
			hand = nullptr;
			readinginner = true;
			c = CTRL('L');
			break;
		      }
		    else
		      i++;
		  break;
		}
		
	      case 'E': /* Examine item in temporary slot */
		if ((hand))
		  {
		    this->examine(hand);
		    readinginner = true;
		    c = CTRL('L');
		  }
		break;
		
	      case 'e': /* Examine item in slot */
		if ((page == 3) && (index < container->contains.size()))
		  this->examine(container->contains[index]);
		else if ((page == 2) && (index < ground.size()))
		  this->examine(ground[index]);
		else if ((page == 1) && (personal[index] != nullptr))
		  this->examine(personal[index]);
		else if (page == 0)
		  {
		    size_t i = 0;
		    
		    #define  __examine(X)		       	\
		      if ((i == index) && (X != nullptr))	\
			this->examine(X);			\
		      i++
		    
		    for (size_t j = 0, n = inventory.left_hand.size(); j < n; j++)
		      {
			__examine(inventory.left_hand[j]);
		      }
		    for (size_t j = 0, n = inventory.quiver.size(); j < n; j++)
		      {
			__examine(inventory.quiver[j]);
		      }
		    for (size_t j = 0, n = inventory.quick_items.size(); j < n; j++)
		      {
			__examine(inventory.quick_items[j]);
		      }
		    __examine(inventory.right_hand);
		    __examine(inventory.headgear);
		    __examine(inventory.amulet);
		    for (size_t j = 0, n = inventory.rings.size(); j < n; j++)
		      {
			__examine(inventory.rings[j]);
		      }
		    __examine(inventory.body);
		    __examine(inventory.gauntlets);
		    __examine(inventory.girdle);
		    __examine(inventory.boots);
		    __examine(inventory.cloak);
		    
		    #undef __examine
		  }
		else
		  break;
		readinginner = true;
		c = CTRL('L');
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
    
    std::flush(std::cout << CSI "?25h");
    
    __restore_tty();
    #undef __print
  }
  
  
  /**
   * Examine an item
   * 
   * @param  item  The item to examine
   */
  void InventoryExaminor::examine(Item* item) const
  {
    (void) item;
    /* TODO implement item examination */
  }
  
  
  
  #undef __store_tty
  #undef __restore_tty
  #undef ESC
  #undef CSI
  
}

