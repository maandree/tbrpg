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
  CharacterSheet* create() const
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
    
    
    std::string input;
    long indexInput;
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
	  input = promptList("Select mage specialisation: ", specialisations);
	  for (MagicSchool& s : c.specialisations)
	    for (MagicSchool& z : sheet.race.specialisations)
	      if (s == z)
		{
		  specialisationMap[s.practicer] = s;
		  specialisations.push_back(s);
		  break;
		}
	  if (input == "")
	    goto _03;
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
    // Abilities abilities.abilities
    
    
  _07:
    // std::unordered_map<WeaponGroup, int> proficiencies
    
    
  _08:
    // Race racial_enemy
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
  
}

