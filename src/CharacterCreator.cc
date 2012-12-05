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
#include "CharacterCreator.hpp"


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
   * Ability score printer
   * 
   * @param  index  The index of the ability
   * @param  value  The value of the ability
   * @param  data   Pointer to the 100-part of the strenght
   */
  static void abilityPrinter(int index, int value, void* data);
  
  /**
   * Generic attribute score printer
   * 
   * @param  index  The index of the attribute
   * @param  value  The value of the attribute
   * @param  data   The labels of the attributes
   */
  static void genericPrinter(int index, int value, void* data);
  
  /**
   * Ability score reroll
   * 
   * @param  self  The invoking CharacterCreator
   */
  static void abilityReroll(CharacterCreator& self);
  
  
  
  /**
   * Constructor
   * 
   * @param  rules  The game's rules
   */
  CharacterCreator::CharacterCreator(const RuleSet& rules)
  {
    this->ruleset = rules;
    this->abilityDice = Dice(3, 6);
    this->dice100 = Dice(1, 100);
    this->sheet = CharacterSheet();
  }
  
  /**
   * Destructor
   */
  CharacterCreator::~CharacterCreator()
  {
  }
  
  
  
  /**
   * Create a character sheet
   * 
   * @return  A character sheet, nullptr if aborted
   */
  CharacterSheet* CharacterCreator::create()
  {
    std::vector<std::string> genders = {"male", "female"};
    
    std::vector<std::string> races = std::vector<std::string>();
    std::unordered_map<std::string, Race> raceMap = std::unordered_map<std::string, Race>();
    for (const Race& r : this->ruleset.races)
      {
	raceMap[r.name] = r;
	races.push_back(r.name);
      }
    
    std::vector<std::string> prestiges;
    std::unordered_map<std::string, std::vector<Class>> prestigeMap;
    
    std::vector<std::string> specialisations = std::vector<std::string>();
    std::unordered_map<std::string, MagicSchool> specialisationMap = std::unordered_map<std::string, MagicSchool>();
    
    std::vector<std::string> alignments;
    std::vector<std::string> all_alignments = {"chaotic evil", "neutral evil", "lawful evil",
					       "chaotic neutral", "true neutral", "lawful neutral",
					       "chaotic good", "neutral good", "lawful good"};
    std::unordered_map<std::string, char> alignmentMap = std::unordered_map<std::string, char>();
    for (size_t i = 0; i < all_alignments.size(); i++)
      alignmentMap[all_alignments[i]] = (char)i;
    
    
    std::string input;
    long indexInput;
    std::string c;
    bool ok;
    
    
  _01:
    input = promptList("Select gender: ", genders);
    if (input == "")
      return nullptr;
    this->sheet.female = input == "female";
    
    
  _02:
    input = promptList("Select race: ", races);
    if (input == "")
      goto _01;
    this->sheet.race = raceMap[input];
    
    
  _03:
    prestiges = std::vector<std::string>();
    prestigeMap = std::unordered_map<std::string, std::vector<Class>>();
    for (std::vector<Class>& p : this->sheet.race.allowed_classes)
      {
	std::string ac = "";
	for (Class& c : p)
	  if (ac == "")
	    ac = c.name;
	  else
	    ac += "/" + c.name;
	prestigeMap[ac] = p;
        prestiges.push_back(ac);
      }
    input = promptList("Select class: ", prestiges);
    if (input == "")
      goto _02;
    this->sheet.prestige = prestigeMap[input];
    this->sheet.class_abondoned = {};
    this->sheet.experience = {};
    this->sheet.level = {};
    for (long i = 0, n = this->sheet.prestige.size(); i < n; i++)
      {
	this->sheet.class_abondoned.push_back(false);
	this->sheet.experience.push_back(0);
	this->sheet.level.push_back(1);
      }
    
    
  _04:
    this->sheet.specialisation = GENERAL_MAGE;
    for (Class& c : this->sheet.prestige)
      if (c.specialisations.size() > 0)
	{
	  specialisations = std::vector<std::string>();
	  specialisationMap = std::unordered_map<std::string, MagicSchool>();
	  for (MagicSchool& s : c.specialisations)
	    for (MagicSchool& z : this->sheet.race.specialisations)
	      if (s == z)
		{
		  specialisationMap[s.practicer] = s;
		  specialisations.push_back(s.practicer);
		  break;
		}
	  if (specialisations.size() == 1)
	    this->sheet.specialisation = specialisationMap[specialisations[0]];
	  else if (specialisations.size() > 1)
	    {
	      input = promptList("Select mage specialisation: ", specialisations);
	      if (input == "")
		goto _03;
	      this->sheet.specialisation = specialisationMap[input];
	    }
	  break;
	}
    
    
  _05:
    alignments = std::vector<std::string>();
    for (long i = 0; i < (long)(all_alignments.size()); i++)
      {
	ok = true;
	for (Class& c : this->sheet.prestige)
	  ok &= *(c.alignments + i);
	if (ok)
	  alignments.push_back(all_alignments[i]);
      }
    input = promptList("Select alignment: ", alignments.size() == 0
		                           ? all_alignments /* fail safe */
		                           : alignments);
    if (input == "")
      goto _04;
    this->sheet.alignment = alignmentMap[input];
    
    
   _06:
    abilityReroll(*this);
    ok = assign(6, 0, (void*)&(this->sheet.abilities.abilities.strength18), abilityPrinter, abilityReroll);
    if (ok)
      {
	this->sheet.abilities.abilities.strength     = this->start[0];
	this->sheet.abilities.abilities.constitution = this->start[1];
	this->sheet.abilities.abilities.dexterity    = this->start[2];
	this->sheet.abilities.abilities.intelligence = this->start[3];
	this->sheet.abilities.abilities.wisdom       = this->start[4];
	this->sheet.abilities.abilities.charisma     = this->start[5];
      }
    delete[] this->start;
    delete[] this->lower;
    delete[] this->upper;
    if (ok == false)
      goto _05;
    
    
  _07:
    /*
    {
      // TODO correct this
      int count = 0;
      std::unordered_map<WeaponGroup, int> proficiencyMap = new std::unordered_map<WeaponGroup, int>();
      {
	auto ptr = proficiencyMap.begin();
	auto end = proficiencyMap.end();
	while (ptr != end)
	  {
	    auto wg = (*ptr++).first.weapon_group;
	    if (WeaponGroup[wg] = 0)
	      WeaponGroup[wg] = ++count;
	  }
      }
      this->start = new int[count];
      this->lower = new int[count];
      this->upper = new int[count];
      for (int i = 0; i < count; i++)
	{
	  this->start[i] = this->lower[i] = 0;
	  this->upper[i] = this->sheet.prestige.proficiencies_each;
	}
      std::string* labels = (std::string)malloc(count * sizeof(std::string));
      for (WeaponGroup weapongroup : WEAPON_GROUPS)
	if (proficiencyMap[weapongroup] != 0)
	  labels[proficiencyMap[weapongroup] - 1] = weapongroup.name;
      ok = assign(count, this->sheet.prestige.experience_chart.proficiencies[1], labels, genericPrinter);
      delete[] this->lower;
      delete[] this->upper;
      free(labels);
      this->sheet.proficiencies = std::unordered_map<WeaponGroup, int>();
      for (WeaponGroup weapongroup : WEAPON_GROUPS)
	if (proficiencyMap[weapongroup] != 0)
	  this->sheet.proficiencies[weapongroup] = this->start[proficiencyMap[weapongroup] - 1];
      delete proficiencyMap;
      delete[] this->start;
    }
    */
    
    
  _08:
    // Race* racial_enemy
    // SpellBook abilities.spells
    // ThiefAbilities abilities.thief_abilities
    
    
  _09:
    input = promptList("Do you have a portrait: ", {"yes", "no"});
    if (input == "")
      goto _08;
    if (input == "no")
      this->sheet.portrait = "";
    else
      {
	input = promptFile("Select portrait: ", true);
	if (input == "")
	  goto _08;
	this->sheet.portrait = input;
      }
    
    
  _10:
    indexInput = promptIndex("Select colour: ", {"red", "green", "yellow", "blue", "magenta", "cyan"});
    if (indexInput < 0)
      goto _09;
    this->sheet.colour = (char)(indexInput + 1);
    
    
  _11:
    input = promptArbitrary("Select name: ");
    if (input == "")
      goto _10;
    this->sheet.name = input;
    
    
    
    return &(this->sheet);
  }
  
  
  /**
   * Assign scores
   * 
   * @param   n           Number of printers
   * @param   unassigned  Unassigned scores
   * @param   extra       Extra data to add as argument to the value printer
   * @param   printer     Value printer, takes arguments: index, value, extra data
   * @param   reroll      Reroll function pointer, nullptr if not allowed
   * @return              Whether the assignment was completed
   */
  bool CharacterCreator::assign(int n, int unassigned, void* data, void (*printer)(int, int, void*), void (*reroll)(CharacterCreator&))
  {
    struct termios saved_stty;
    struct termios stty;
    tcgetattr(STDIN_FILENO, &saved_stty);
    tcgetattr(STDIN_FILENO, &stty);
    stty.c_lflag &= ~(ICANON | ECHO | ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &stty);
    std::cout << "\033[?25l"; /* hide cursor */
    
    int cur = 0, leftover = unassigned, tmp;
    char c = 0, last;
    bool reading = true;
    int* stored = (int*)malloc((n + 1) * sizeof(int));
    
    for (int i = 0; i < n; i++)
      *(stored + i) = *(this->start + i);
    *(stored + n) = leftover;
    
    
    while (reading)
      {
	std::cout << "\033[H\033[2J" << "Unassigned points: " << leftover << "\n\n";
	for (int i = 0; i < n; i++)
	  {
	    if (i == cur)
	      std::cout << "\033[01;34m";
	    printer(i, this->start[i], data);
	    if (i == cur)
	      std::cout << "\033[21;39m";
	    std::cout << std::endl;
	  }
        printf("\033[%iA", n - cur - 1);
	std::flush(std::cout);
	
	while (reading)
	  {
	    last = c;
	    if ((read(STDIN_FILENO, &c, 1) <= 0) || (c == CTRL('G')))
	      {
		std::cout << "\033[H\033[2J\033[?25h"; /* show cursor */
		std::flush(std::cout);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty);
		free(stored);
		return false;
	      }

	    tmp = leftover;
	    if ((last == '[') && (c == 'A')) /* up */
	      {
		if (cur == 0)
		  continue;
		std::cout << "\033[A\033[K";
		printer(cur, this->start[cur], data);
		cur--;
		std::cout << "\n\033[2A\033[01;34m\033[K";
		printer(cur, this->start[cur], data);
		std::cout << "\033[21;39m\n";
	      }
	    else if (((last == '[') && (c == 'B')) || (c == '\n')) /* down */
	      {
		if (cur + 1 == n)
		  continue;
		std::cout << "\033[A\033[K";
		printer(cur, this->start[cur], data);
		cur++;
		std::cout << "\n\033[01;34m\033[K";
		printer(cur, this->start[cur], data);
		std::cout << "\033[21;39m\n";
	      }
	    else if ((last == '[') && (c == 'C')) /* right */
	      {
		if (this->start[cur] < this->upper[cur])
		  {
		    if (leftover == 0)
		      std::cout << "\a";
		    else
		      {
			leftover--;
			std::cout << "\033[A\033[01;34m\033[K";
			printer(cur, ++(this->start[cur]), data);
			std::cout << "\033[21;39m\n";
		      }
		  }
	      }
	    else if ((last == '[') && (c == 'D')) /* left */
	      {
		if (this->lower[cur] < this->start[cur])
		  {
		    leftover++;
		    std::cout << "\033[A\033[01;34m\033[K";
		    printer(cur, --(this->start[cur]), data);
		    std::cout << "\033[21;39m\n";
		  }
	      }
	    else if (c == CTRL('L'))
	      break;
	    else if ((c == 'd') || (c == 'D'))
	      {
		reading = false;
		break;
	      }
	    else if ((c == 'r') || (c == 'R'))
	      {
		leftover = *(stored + n);
		for (int i = 0; i < n; i++)
		  *(this->start + i) = *(stored + i);
		break;
	      }
	    else if ((c == 's') || (c == 's'))
	      {
		for (int i = 0; i < n; i++)
		  *(stored + i) = *(this->start + i);
		*(stored + n) = leftover;
	      }
	    else if ((reroll != nullptr) && (c == CTRL('R')))
	      {
		reroll(*this);
		leftover = unassigned;
		break;
	      }
	    
	    if (leftover != tmp)
	      {
		tmp = cur + 3;
		printf("\033[%iAUnassigned points: %i\n\033[%iB", tmp, leftover, tmp - 1);
	      }
	    std::flush(std::cout);
	  }
      }
    
    
    std::cout << "\033[H\033[2J";
    for (int i = 0; i < n; i++)
      {
	printer(i, this->start[i], data);
	std::cout << std::endl;
      }
    std::cout << "\033[?25h" << std::endl; /* show cursor */
    std::flush(std::cout);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty);
    free(stored);
    return true;
  }
  
  
  /**
   * Ability score reroll
   * 
   * @param  self  The invoking CharacterCreator
   */
  static void abilityReroll(CharacterCreator& self)
  {
    self.start = new int[6];
    self.lower = new int[6];
    self.upper = new int[6];
    self.sheet.abilities.abilities.strength18 = self.dice100.roll();
    self.lower[0] = self.lower[1] = self.lower[2] = self.lower[3] = self.lower[4] = self.lower[5] = 0;
    for (Class& c : self.sheet.prestige)
      {
	int _str, _con, _dex, _int, _wis, _chr;
	self.lower[0] = (_str = c.lower_limits.strength)     < self.lower[0] ? _str : self.lower[0];
	self.lower[1] = (_con = c.lower_limits.constitution) < self.lower[1] ? _con : self.lower[1];
	self.lower[2] = (_dex = c.lower_limits.dexterity)    < self.lower[2] ? _dex : self.lower[2];
	self.lower[3] = (_int = c.lower_limits.intelligence) < self.lower[3] ? _int : self.lower[3];
	self.lower[4] = (_wis = c.lower_limits.wisdom)       < self.lower[4] ? _wis : self.lower[4];
	self.lower[5] = (_chr = c.lower_limits.charisma)     < self.lower[5] ? _chr : self.lower[5];
      }
    self.upper[0] = self.sheet.race.bonuses.abilities.strength;
    self.upper[1] = self.sheet.race.bonuses.abilities.constitution;
    self.upper[2] = self.sheet.race.bonuses.abilities.dexterity;
    self.upper[3] = self.sheet.race.bonuses.abilities.intelligence;
    self.upper[4] = self.sheet.race.bonuses.abilities.wisdom;
    self.upper[5] = self.sheet.race.bonuses.abilities.charisma;
    for (int i = 0; i < 6; i++)
      {
	self.upper[i] += 18;
	self.start[i] = self.abilityDice.roll();
	if (self.start[i] < self.lower[i])
	  self.start[i] = self.lower[i];
	self.lower[i] += self.upper[i];
      }
  }
  
  
  /**
   * Ability score printer
   * 
   * @param  index  The index of the ability
   * @param  value  The value of the ability
   * @param  data   Pointer to the 100-part of the strenght
   */
  static void abilityPrinter(int index, int value, void* data)
  {
    int strength18 = *((char*)data);
    if ((index == 0) && (value == 18) && (strength18 != 0))
      std::cout << "Strength: " << value << "/" << strength18;
    else if (index == 0)  std::cout << "Strength: "     << value;
    else if (index == 1)  std::cout << "Constitution: " << value;
    else if (index == 2)  std::cout << "Dexterity: "    << value;
    else if (index == 3)  std::cout << "Intelligence: " << value;
    else if (index == 4)  std::cout << "Wisdom: "       << value;
    else if (index == 5)  std::cout << "Charisma: "     << value;
  }
  
  
  /**
   * Generic attribute score printer
   * 
   * @param  index  The index of the attribute
   * @param  value  The value of the attribute
   * @param  data   The labels of the attributes
   */
  void genericPrinter(int index, int value, void* data)
  {
    std::cout << *((std::string*)data + index) << (value);
  }
  
}

