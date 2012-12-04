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
   * Constructor
   * 
   * @param  rules  The game's rules
   */
  CharacterCreator::CharacterCreator(const RuleSet& rules)
  {
    this->ruleset = rules;
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
  CharacterSheet* CharacterCreator::create() const
  {
    std::vector<std::string> genders = {"male", "female"};
    
    std::vector<std::string> races = std::vector<std::string>();
    std::unordered_map<std::string, Race> raceMap = std::unordered_map<std::string, Race>();
    for (Race& r : this->ruleset.races)
      {
	raceMap[r.name] = r;
	races.push_back(r);
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
    for (long i = 0; i < all_alignments.size(); i++)
      alignmentMap[all_alignments[i]] = (char)i;
    
    Dice abilityDice = Dice(3, 6);
    Dice dice100 = Dice(1, 100);
    
    
    std::string input;
    long indexInput, i;
    std::string c;
    boolean ok;
    CharacterSheet sheet = CharacterSheet();
    
    
  _01:
    input = promptList("Select gender: ", genders);
    if (input == "")
      return nullptr;
    sheet.female = input == "female";
    
    
  _02:
    input = promptList("Select race: ", races);
    if (input == "")
      goto _01;
    sheet.race = raceMap[input];
    
    
  _03:
    prestiges = std::vector<std::string>();
    prestigeMap = std::unordered_map<std::string, std::vector<Class>>();
    for (std::vector<Class>& p : sheet.race.allowed_classes)
      {
	c = "";
	for (Class& c : p)
	  if (c == "")
	    c = p.name;
	  else
	    c += "/" + p.name;
	prestigeMap[c] = p;
        prestiges.push_back(p);
      }
    input = promptList("Select class: ", prestiges);
    if (input == "")
      goto _02;
    sheet.prestige = prestigeMap[input];
    sheet.class_abondoned = {};
    sheet.experience = {};
    sheet.level = {};
    for (long i = 0, n = sheet.prestige.size(); i < n; i++)
      {
	sheet.class_abondoned.push_back(false);
	sheet.experience.push_back(0);
	sheet.level.push_back(1);
      }
    
    
  _04:
    sheet.specialisation = GENERAL_MAGE;
    for (Class& c : sheet.prestige)
      if (c.specialisations.size() > 0)
	{
	  specialisations = std::vector<std::string>();
	  specialisationMap = std::unordered_map<std::string, MagicSchool>();
	  for (MagicSchool& s : c.specialisations)
	    for (MagicSchool& z : sheet.race.specialisations)
	      if (s == z)
		{
		  specialisationMap[s.practicer] = s;
		  specialisations.push_back(s);
		  break;
		}
	  if (specialisations.size() == 1)
	    sheet.specialisation = specialisationMap[specialisations[0]];
	  else if (specialisations.size() > 1)
	    {
	      input = promptList("Select mage specialisation: ", specialisations);
	      if (input == "")
		goto _03;
	      sheet.specialisation = specialisationMap[input];
	    }
	  break;
	}
    
    
  _05:
    alignments = std::vector<std::string>();
    for (long i = 0; i < all_alignments.size(); i++)
      {
	ok = true;
	for (Class& c : sheet.prestige)
	  ok &= *(c.alignments + i);
	if (ok)
	  alignments.push_back(all_alignments[i]);
      }
    input = promptList("Select alignment: ", alignments.size() == 0
		                           ? all_alignments /* fail safe */
		                           : alignments);
    if (input == "")
      goto _04;
    sheet.alignment = alignmentMap[input];
    
    
  _06:
    abilityReroll();
    ok = assign(6, 0, &(sheet.abilities.abilities.strength18), abilityPrinter, &(reroll));
    if (ok)
      {
	sheet.abilities.abilities.strength     = this->start[0];
	sheet.abilities.abilities.constitution = this->start[1];
	sheet.abilities.abilities.dexterity    = this->start[2];
	sheet.abilities.abilities.intelligence = this->start[3];
	sheet.abilities.abilities.wisdom       = this->start[4];
	sheet.abilities.abilities.charisma     = this->start[5];
      }
    delete[] this->start;
    delete[] this->lower;
    delete[] this->upper;
    if (ok == false)
      goto _05;
    
    
  _07:
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
	  this->upper[i] = sheet.prestige.proficiencies_each;
	}
      std::string* labels = (std::string)malloc(count * sizeof(std::string));
      for (WeaponGroup weapongroup : WEAPON_GROUPS)
	if (proficiencyMap[weapongroup] != 0)
	  labels[proficiencyMap[weapongroup] - 1] = weapongroup.name;
      ok = assign(count, sheet.prestige.experience_chart.proficiencies[1], labels, genericPrinter);
      delete[] this->lower;
      delete[] this->upper;
      free(labels);
      sheet.proficiencies = std::unordered_map<WeaponGroup, int>();
      for (WeaponGroup weapongroup : WEAPON_GROUPS)
	if (proficiencyMap[weapongroup] != 0)
	  sheet.proficiencies[weapongroup] = this->start[proficiencyMap[weapongroup] - 1];
      delete proficiencyMap;
      delete[] this->start;
    }
    
    
  _08:
    // Race* racial_enemy
    // SpellBook abilities.spells
    // ThiefAbilities abilities.thief_abilities
    
    
  _09:
    input = promptList("Do you have a portrait: ", {"yes", "no"});
    if (input == "")
      goto _08;
    if (input == "no")
      sheet.portrait = "";
    else
      {
	input = promptFile("Select portrait: ", true);
	if (input == "")
	  goto _08;
	sheet.portrait = input;
      }
    
    
  _10:
    indexInput = promptIndex("Select colour: ", {"red", "green", "yellow", "blue", "magenta", "cyan"});
    if (indexInput < 0)
      goto _09;
    sheet.colour = (char)(indexInput + 1);
    
    
  _11:
    input = promptArbitrary("Select name: ");
    if (input == "")
      goto _10;
    sheet.name = input;
    
    
    
    return &sheet;
  }
  
  
  /**
   * Assign scores
   * 
   * @param   n           Number of printers
   * @param   unassigned  Unassigned scores
   * @param   extra       Extra data to add as argument to the value printer
   * @param   printer     Value printer, takes arguments: index, value, extra data
   * @param   reroll      Pointer to a reroll function pointer, nullptr if not allowed
   * @return              Whether the assignment was completed
   */
  bool CharacterCreator::assign(int n, int unassigned, void* data, void (*printer)(int, int, void*), void (**reroll)())
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
		std::flush(std::out);
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
		(*reroll)();
		leftover = unassigned;
		break;
	      }
	    
	    if (leftover != tmp)
	      {
		tmp = cur + 3;
		printf("\033[%iAUnassigned points: %i\n\033[%iB", tmp, leftover, tmp - 1);
	      }
	    std::flush(std::out);
	  }
      }
    
    
    std::cout << "\033[H\033[2J";
    for (int i = 0; i < n; i++)
      {
	printer(i, this->start[i], data);
	std::cout << std::endl;
      }
    std::cout << "\033[?25h" << std::endl; /* show cursor */
    std::flush(std::out);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved_stty);
    free(stored);
    return true;
  }
  
  
  /**
   * Ability score printer
   * 
   * @param  index  The index of the ability
   * @param  value  The value of the ability
   * @param  data   Pointer to the 100-part of the strenght
   */
  void CharacterCreator::abilityPrinter(int index, int value, void* data) const;
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
  void CharacterCreator::genericPrinter(int index, int value, void* data) const;
  {
    std::cout << *((std::string*)data + index) << value;
  }
  
  
  /**
   * Ability score reroll
   */
  virtual void abilityReroll()
  {
    this->start = new int[6];
    this->lower = new int[6];
    this->upper = new int[6];
    sheet.abilities.abilities.strength18 = dice100.roll();
    this->lower[0] = sheet.prestige.lower_limits.strength;
    this->lower[1] = sheet.prestige.lower_limits.constitution;
    this->lower[2] = sheet.prestige.lower_limits.dexterity;
    this->lower[3] = sheet.prestige.lower_limits.intelligence;
    this->lower[4] = sheet.prestige.lower_limits.wisdom;
    this->lower[5] = sheet.prestige.lower_limits.charisma;
    this->upper[0] = sheet.race.bonuses.abilities.strength;
    this->upper[1] = sheet.race.bonuses.abilities.constitution;
    this->upper[2] = sheet.race.bonuses.abilities.dexterity;
    this->upper[3] = sheet.race.bonuses.abilities.intelligence;
    this->upper[4] = sheet.race.bonuses.abilities.wisdom;
    this->upper[5] = sheet.race.bonuses.abilities.charisma;
    for (i = 0; i < 6; i++)
      {
	this->upper[i] += 18;
	this->start[i] = abilityDice.roll();
	if (this->start[i] < this->lower[i])
	  this->start[i] = this->lower[i];
	this->lower[i] += this->upper[i];
      }
  }
  
}

