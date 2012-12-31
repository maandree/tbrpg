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
    this->sheet = new CharacterSheet();
  }
  
  /**
   * Destructor
   */
  CharacterCreator::~CharacterCreator()
  {
    if (this->sheet != nullptr)
      delete this->sheet;
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
    
    std::vector<std::string> racials = std::vector<std::string>();
    std::unordered_map<std::string, Race> racialMap = std::unordered_map<std::string, Race>();
    for (const Race& r : this->ruleset.racial_enemies)
      {
	racialMap[r.name] = r;
	racials.push_back(r.name);
      }
    
    std::vector<std::string> prestiges;
    std::unordered_map<std::string, std::vector<Class>> prestigeMap;
    
    std::vector<std::string> specialisations = std::vector<std::string>();
    std::unordered_map<std::string, MagicSchool> specialisationMap = std::unordered_map<std::string, MagicSchool>();
    
    std::vector<std::string> alignments;
    std::vector<std::string> all_alignments = {"chaotic evil",    "neutral evil", "lawful evil",
					       "chaotic neutral", "true neutral", "lawful neutral",
					       "chaotic good",    "neutral good", "lawful good"};
    std::unordered_map<std::string, char> alignmentMap = std::unordered_map<std::string, char>();
    for (size_t i = 0; i < all_alignments.size(); i++)
      alignmentMap[all_alignments[i]] = (char)i;
    
    std::unordered_map<WeaponGroup, int> proficiencyMap = std::unordered_map<WeaponGroup, int>();
    Weapon WEAPON_PROTOTYPE = PROTOTYPE(Weapon);
    int count;
    int assignScores;
    int eachScores;
    
    std::string* labels;
    std::string input;
    int assignable;
    long indexInput;
    std::string c;
    bool ok;
    bool hasSpecialisation;
    bool hasExtra;
    
    
  _01:
    input = promptList("Select gender: ", genders);
    if (input == "")
      return nullptr;
    this->sheet->female = input == "female";
    
    
  _02:
    input = promptList("Select race: ", races);
    if (input == "")
      goto _01;
    this->sheet->race = raceMap[input];
    
    
  _03:
    prestiges = std::vector<std::string>();
    prestigeMap = std::unordered_map<std::string, std::vector<Class>>();
    for (std::vector<Class>& p : this->sheet->race.allowed_classes)
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
    this->sheet->prestige = prestigeMap[input];
    this->sheet->class_abondoned = {};
    this->sheet->experience = {};
    this->sheet->level = {};
    for (long i = 0, n = this->sheet->prestige.size(); i < n; i++)
      {
	this->sheet->class_abondoned.push_back(false);
	this->sheet->experience.push_back(0);
	this->sheet->level.push_back(1);
      }
    hasSpecialisation = false;
    
    
  _04:
    this->sheet->specialisation = GENERAL_MAGE;
    for (Class& c : this->sheet->prestige)
      if (c.specialisations.size() > 0)
	{
	  specialisations = std::vector<std::string>();
	  specialisationMap = std::unordered_map<std::string, MagicSchool>();
	  for (MagicSchool& s : c.specialisations)
	    for (MagicSchool& z : this->sheet->race.specialisations)
	      if (s == z)
		{
		  specialisationMap[s.practicer] = s;
		  specialisations.push_back(s.practicer);
		  break;
		}
	  if (specialisations.size() == 1)
	    this->sheet->specialisation = specialisationMap[specialisations[0]];
	  else if (specialisations.size() > 1)
	    {
	      hasSpecialisation = true;
	      input = promptList("Select mage specialisation: ", specialisations);
	      if (input == "")
		goto _03;
	      this->sheet->specialisation = specialisationMap[input];
	    }
	  break;
	}
    
    
  _05:
    alignments = std::vector<std::string>();
    for (long i = 0; i < (long)(all_alignments.size()); i++)
      {
	ok = true;
	for (Class& c : this->sheet->prestige)
	  ok &= c.alignments[i];
	if (ok)
	  {
	    alignments.push_back(all_alignments[i]);
	    alignmentMap[all_alignments[i]] = i;
	  }
      }
    input = promptList("Select alignment: ", alignments);
    if (input == "")
      {
	if (hasSpecialisation)
	  goto _04;
	else
	  goto _03;
      }
    this->sheet->alignment = alignmentMap[input];
    
    
   _06:
    this->start = new int[6];
    this->lower = new int[6];
    this->upper = new int[6];
    abilityReroll(*this);
    ok = assign(6, 0, (void*)&(this->sheet->abilities.abilities.strength18), abilityPrinter, abilityReroll);
    if (ok)
      {
	this->sheet->abilities.abilities.strength     = this->start[0];
	this->sheet->abilities.abilities.constitution = this->start[1];
	this->sheet->abilities.abilities.dexterity    = this->start[2];
	this->sheet->abilities.abilities.intelligence = this->start[3];
	this->sheet->abilities.abilities.wisdom       = this->start[4];
	this->sheet->abilities.abilities.charisma     = this->start[5];
      }
    delete[] this->start;
    delete[] this->lower;
    delete[] this->upper;
    if (ok == false)
      goto _05;
    
    
  _07:
    for (const WeaponGroup* weapongroup : WEAPON_GROUPS)
      proficiencyMap[*weapongroup] = 0;
    
    count = assignScores = eachScores = 0;
    for (Class& c : this->sheet->prestige)
      {
	int candidate = c.experience_chart.proficiencies[1];
	if (assignScores < candidate)
	  assignScores = candidate;
	candidate = c.proficiencies_each;
	if (eachScores < candidate)
	  eachScores = candidate;
	auto ptr = c.can_use.begin();
	auto end = c.can_use.end();
	while (ptr != end)
	  {
	    auto entry = *ptr++;
	    if (entry.second && (entry.first >= WEAPON_PROTOTYPE))
	      {
		Weapon* w = static_cast<Weapon*>(entry.first.getActual());
		const WeaponGroup* wg = w->weapon_group;
		if (proficiencyMap[*wg] == 0)
		  proficiencyMap[*wg] = ++count;
	      }
	  }
      }
    
    this->start = new int[count];
    this->lower = new int[count];
    this->upper = new int[count];
    for (int i = 0; i < count; i++)
      {
	this->start[i] = this->lower[i] = 0;
	this->upper[i] = eachScores;
      }
    
    labels = new std::string[count];
    for (const WeaponGroup* weapongroup : WEAPON_GROUPS)
      if (proficiencyMap[*weapongroup] != 0)
	labels[proficiencyMap[*weapongroup] - 1] = changeCase(weapongroup->name, CAMEL_CASE);
    
    ok = assign(count, assignScores, labels, genericPrinter);
    
    delete[] this->lower;
    delete[] this->upper;
    delete[] labels;
    
    if (ok == false)
      {
	delete[] this->start;
	goto _06;
      }
    
    this->sheet->proficiencies = std::unordered_map<WeaponGroup, int>();
    for (const WeaponGroup* weapongroup : WEAPON_GROUPS)
      if (proficiencyMap[*weapongroup] != 0)
	this->sheet->proficiencies[*weapongroup] = this->start[proficiencyMap[*weapongroup] - 1];
    
    delete[] this->start;
    hasExtra = false;
    
    
  _08:
    /* Racial enemy */
    this->sheet->racial_enemy = nullptr;
    for (Class& c : this->sheet->prestige)
      if (c.have_racial_enemy)
	{
	  hasExtra = true;
	  input = promptList("Select racial enemy: ", racials);
	  if (input == "")
	    goto _07;
	  this->sheet->racial_enemy = &(racialMap[input]);
	  break;
	}
    
    /* Thief abilities */
    assignable = 0;
    start = new int[4];
    start[0] = this->sheet->race.bonuses.thief_abilities.find_traps;
    start[1] = this->sheet->race.bonuses.thief_abilities.open_locks;
    start[2] = this->sheet->race.bonuses.thief_abilities.pick_pockets;
    start[3] = this->sheet->race.bonuses.thief_abilities.stealth;
    upper = new int[4];
    for (int i = 0; i < 4; i++)
      upper[i] = 0;
    for (Class& c : this->sheet->prestige)
      {
	start[0] += c.abilities.thief_abilities.find_traps;
	start[1] += c.abilities.thief_abilities.open_locks;
	start[2] += c.abilities.thief_abilities.pick_pockets;
	start[3] += c.abilities.thief_abilities.stealth;
	for (int i = 0; i < 4; i++)
	  if (start[i] >= 0)
	    upper[i] += c.abilities.thief_abilities.limit;
	assignable += c.experience_chart.thief_abilities[1];
      }
    lower = new int[4];
    for (int i = 0; i < 4; i++)
      lower[i] = start[i];
    labels = new std::string[4];
    *(labels + 0) = "Find traps:   ";
    *(labels + 1) = "Open locks:   ";
    *(labels + 2) = "Pick pockets: ";
    *(labels + 3) = "Stealth:      ";
    hasExtra = assignable;
    if ((assignable))
      ok = assign(4, assignable, labels, genericPrinter);
    else
      ok = true;
    delete[] labels;
    delete[] lower;
    delete[] upper;
    if (ok)
      {
	this->sheet->abilities.thief_abilities.find_traps   = start[0];
	this->sheet->abilities.thief_abilities.open_locks   = start[1];
	this->sheet->abilities.thief_abilities.pick_pockets = start[2];
	this->sheet->abilities.thief_abilities.stealth      = start[3];
	delete[] start;
      }
    else
      {
	delete[] start;
	if ((assignable))
	  goto _07;
      }
    
    /* Spells *//* TODO not tested */
    {
      int wizardAssign0 = 0;
      int wizardAssign1 = 0;
      int priestAssign1 = 0;
      for (Class& c : this->sheet->prestige)
	{
	  if (c.experience_chart.selectable_wizard.size() > 0)
	    wizardAssign0 += c.experience_chart.selectable_wizard[0];
	  if (c.experience_chart.selectable_wizard.size() > 1)
	    wizardAssign1 += c.experience_chart.selectable_wizard[1];
	  if (c.experience_chart.selectable_priest.size() > 1)
	    priestAssign1 += c.experience_chart.selectable_priest[1];
	}
      
      std::vector<std::string> wizard0s = std::vector<std::string>();
      std::vector<std::string> wizard1s = std::vector<std::string>();
      std::vector<std::string> priest1s = std::vector<std::string>();
      std::unordered_map<std::string, Spell> wizard0Map = std::unordered_map<std::string, Spell>();
      std::unordered_map<std::string, Spell> wizard1Map = std::unordered_map<std::string, Spell>();
      std::unordered_map<std::string, Spell> priest1Map = std::unordered_map<std::string, Spell>();
      
      for (Spell& spell : this->ruleset.spells)
	if (spell.wizard && (spell.level == 0))
	  {
	    wizard0s.push_back(spell.name);
	    wizard0Map[spell.name] = spell;
	  }
	else if (spell.wizard && (spell.level == 1))
	  {
	    wizard1s.push_back(spell.name);
	    wizard1Map[spell.name] = spell;
	  }
	else if (spell.priest && (spell.level == 1))
	  {
	    priest1s.push_back(spell.name);
	    priest1Map[spell.name] = spell;
	  }
      
      this->sheet->spells.learned = std::vector<Spell>();
      
      if ((wizardAssign0 > 0) && (wizard0s.size() > 0))
	{
	  hasExtra = true;
	  std::vector<std::string> selected = promptMulti("Select level 0 wizard spells", wizardAssign0, wizard0s);
	  if (selected.size() == 0)
	    goto _07;
	  for (std::string& spell : selected)
	    this->sheet->spells.learned.push_back(wizard0Map[spell]);
	}
      
      if ((wizardAssign1 > 0) && (wizard1s.size() > 0))
	{
	  hasExtra = true;
	  std::vector<std::string> selected = promptMulti("Select level 1 wizard spells", wizardAssign1, wizard1s);
	  if (selected.size() == 0)
	    goto _07;
	  for (std::string& spell : selected)
	    this->sheet->spells.learned.push_back(wizard1Map[spell]);
	}
      
      if ((priestAssign1 > 0) && (priest1s.size() > 0))
	{
	  hasExtra = true;
	  std::vector<std::string> selected = promptMulti("Select level 1 priest spells", priestAssign1, priest1s);
	  if (selected.size() == 0)
	    goto _07;
	  for (std::string& spell : selected)
	    this->sheet->spells.learned.push_back(priest1Map[spell]);
	}
    }
    
    
  _09:
    input = promptList("Do you have a portrait: ", {"yes", "no"});
    if (input == "")
      {
	if (hasExtra)
	  goto _08;
	else
	  goto _07;
      }
    if (input == "no")
      this->sheet->portrait = "";
    else
      {
	input = promptFile("Select portrait: ", true);
	if (input == "")
	  {
	    if (hasExtra)
	      goto _08;
	    else
	      goto _07;
	  }
	this->sheet->portrait = input;
      }
    
    
  _10:
    indexInput = promptIndex("Select colour: ", {"red", "green", "yellow", "blue", "magenta", "cyan"});
    if (indexInput < 0)
      goto _09;
    this->sheet->colour = (char)(indexInput + 1);
    
    
    input = promptArbitrary("Select name: ");
    if (input == "")
      goto _10;
    this->sheet->name = input;
    
    
    Inventory* inventory = (Inventory*)(this->ruleset.inventory_prototype.fork());
    this->sheet->inventory = *inventory;
    delete inventory;
    //cleaner::getInstance().enqueueDelete(inventory);
    long long prestige = 0;
    ActionSlotChart slotchart = ActionSlotChart();
    for (Class& c : this->sheet->prestige)
      prestige |= slotchart.index_map[c];
    std::vector<ActionSlot>& slots = slotchart.slot_map[prestige];
    size_t weapons = this->sheet->inventory.left_hand.size();
    for (ActionSlot slot : slots)
      if (slot == QUICK_WEAPON)
	weapons++;
    this->sheet->inventory.left_hand = std::vector<Weapon*>(weapons);
    
    
    int minHP = 0, bestHP = 0, hpBonus = 0;
    char hpDie = 0, hpDice = 0;
    for (Class& c : this->sheet->prestige)
      {
	if (minHP < c.hit_points)
	  minHP = c.hit_points;
	
	int hp = c.experience_chart.hit_point_die[1]
	       * c.experience_chart.hit_point_dice[1]
	       + c.experience_chart.hit_point_bonus[1];
	if (bestHP < hp)
	  {
	    bestHP = hp;
	    hpDie = c.experience_chart.hit_point_die[1];
	    hpDice = c.experience_chart.hit_point_dice[1];
	    hpBonus = c.experience_chart.hit_point_bonus[1];
	  }
      }
    
    bestHP = Dice(hpDice, hpDie).roll() + hpBonus;
    if (bestHP < minHP)
      bestHP = minHP;
    this->sheet->hit_points = bestHP;
    
    
    CharacterSheet* rc = this->sheet;
    this->sheet = nullptr;
    return rc;
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
	std::cout << "\033[H\033[2J" << "Remaining: " << leftover << "\n\n";
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
	    else if ((c == 'd') || ((c == 'D') && ! ((last <= '0') && (last <= '9'))))
	      {
		if (leftover == 0)
		  {
		    reading = false;
		    break;
		  }
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
		printf("\033[%iARemaining: \033[K%i\n\033[%iB", tmp, leftover, tmp - 1);
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
    self.sheet->abilities.abilities.strength18 = self.dice100.roll();
    self.lower[0] = self.lower[1] = self.lower[2] = self.lower[3] = self.lower[4] = self.lower[5] = 0;
    for (Class& c : self.sheet->prestige)
      {
	int _str, _con, _dex, _int, _wis, _chr;
	self.lower[0] = (_str = c.lower_limits.strength)     > self.lower[0] ? _str : self.lower[0];
	self.lower[1] = (_con = c.lower_limits.constitution) > self.lower[1] ? _con : self.lower[1];
	self.lower[2] = (_dex = c.lower_limits.dexterity)    > self.lower[2] ? _dex : self.lower[2];
	self.lower[3] = (_int = c.lower_limits.intelligence) > self.lower[3] ? _int : self.lower[3];
	self.lower[4] = (_wis = c.lower_limits.wisdom)       > self.lower[4] ? _wis : self.lower[4];
	self.lower[5] = (_chr = c.lower_limits.charisma)     > self.lower[5] ? _chr : self.lower[5];
      }
    self.upper[0] = self.sheet->race.bonuses.abilities.strength;
    self.upper[1] = self.sheet->race.bonuses.abilities.constitution;
    self.upper[2] = self.sheet->race.bonuses.abilities.dexterity;
    self.upper[3] = self.sheet->race.bonuses.abilities.intelligence;
    self.upper[4] = self.sheet->race.bonuses.abilities.wisdom;
    self.upper[5] = self.sheet->race.bonuses.abilities.charisma;
    if (self.sheet->female)
      self.lower[0]--;
    else
      self.lower[2]--;
    for (int i = 0; i < 6; i++)
      {
	self.start[i] = self.abilityDice.roll();
	if (self.start[i] < self.lower[i])
	  self.start[i] = self.lower[i];
	self.lower[i] += self.upper[i];
	self.upper[i] += 18;
	if (self.sheet->female)
	  self.upper[0]--;
	else
	  self.upper[2]--;
	if (self.start[i] > self.upper[i])
	  self.start[i] = self.upper[i];
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
      std::cout << "Strength: " << value << "/" << ((strength18 % 100) < 10 ? "0" : "") << (strength18 % 100);
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
    std::cout << *((std::string*)data + index) << ": " << value;
  }
  
}

