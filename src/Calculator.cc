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
#include "Calculator.hpp"


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
  #define ___f(X, Y, Z)  (this->rules.ability_chart.X[(long)(this->Y(character))].bonuses.Z)
  
  #define __g(X, op)					\
    if (this->getStrength(character) != 18)		\
      op ___f(strength, getStrength, X);		\
    else						\
      op ___f(strength18, getStrength18, X);		\
    op ___f(constitution, getConstitution, X);		\
    op ___f(dexterity, getDexterity, X);		\
    op ___f(intelligence, getIntelligence, X);		\
    op ___f(wisdom, getWisdom, X);			\
    op ___f(charisma, getCharisma, X);			\
    op (character.record.race.bonuses.bonuses.X);	\
    for (const Class& c : character.record.prestige)	\
      op (c.abilities.bonuses.X)
  
  #define __f(X) __g(X, rc +=)
  
  #define __w  *(weapon.weapon_group)
  
  
  
  /**
   * Constructor
   */
  Calculator::Calculator(const RuleSet& ruleset) : Object()
  {
    this->class_inheritance.push_back(144);
    this->rules = ruleset;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(const Calculator& original) : Object(original)
  {
    this->rules = (RuleSet&)(original.rules);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator& original) : Object(original)
  {
    this->rules = (RuleSet&)(original.rules);
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator&& original) : Object(original)
  {
    std::swap(this->rules, original.rules);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Calculator::fork() const
  {
    return (Object*)(new Calculator(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Calculator::~Calculator()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(const Calculator& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->rules = (RuleSet&)(original.rules);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(Calculator& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    this->rules = (RuleSet&)(original.rules);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(Calculator&& original)
  {
    std::swap((Object&)*this, (Object&)original);
    std::swap(this->rules, (RuleSet&)(original.rules));
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Calculator::operator ==(const Calculator& other) const
  {
    if (this->rules != other.rules)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Calculator::operator !=(const Calculator& other) const
  {
    return (*this == other) == false;
  }
  
  
  
  /**
   * Gets a character's strength
   * 
   * @param   character  The character
   * @return             The character's strength
   */
  char Calculator::getStrength(const Character& character) const
  {
    char rc = character.record.abilities.abilities.strength;
    return rc;
  }
  
  /**
   * Gets a character's strength's extra part of 18
   * 
   * @param   character  The character
   * @return             The character's strength's extra part of 18
   */
  char Calculator::getStrength18(const Character& character) const
  {
    char rc = character.record.abilities.abilities.strength18;
    return rc;
  }
  
  /**
   * Gets a character's constitution
   * 
   * @param   character  The character
   * @return             The character's constitution
   */
  char Calculator::getConstitution(const Character& character) const
  {
    char rc = character.record.abilities.abilities.constitution;
    return rc;
  }
  
  /**
   * Gets a character's dexterity
   * 
   * @param   character  The character
   * @return             The character's dexterity
   */
  char Calculator::getDexterity(const Character& character) const
  {
    char rc = character.record.abilities.abilities.dexterity;
    return rc;
  }
  
  /**
   * Gets a character's intelligence
   * 
   * @param   character  The character
   * @return             The character's intelligence
   */
  char Calculator::getIntelligence(const Character& character) const
  {
    char rc = character.record.abilities.abilities.intelligence;
    return rc;
  }
  
  /**
   * Gets a character's wisdom
   * 
   * @param   character  The character
   * @return             The character's wisdom
   */
  char Calculator::getWisdom(const Character& character) const
  {
    char rc = character.record.abilities.abilities.wisdom;
    return rc;
  }
  
  /**
   * Gets a character's charisma
   * 
   * @param   character  The character
   * @return             The character's charisma
   */
  char Calculator::getCharisma(const Character& character) const
  {
    char rc = character.record.abilities.abilities.charisma;
    return rc;
  }
  
  
  /**
   * Get the number of half attacks inclicted by a character
   * 
   * @param   character  The character
   * @param   weapon     The character's weapon
   * @return             The number of half attacks
   */
  char Calculator::getHalfAttacks(const Character& character, const Weapon& weapon) const
  {
    char rc = 0;
    int prof = character.record.proficiencies.at(__w);
    for (const Class& c : character.record.prestige)
      rc += c.proficiency_chart.at(__w)[prof].half_attacks;
    rc /= character.record.prestige.size();
    rc += character.extra_attacks;
    return rc;
  }
  
  /**
   * Get a character's THAC0
   * 
   * @param   character  The character
   * @param   weapon     The character's weapon
   * @param   ammo       The character's ammunition
   * @return             The character's THAC0
   */
  int Calculator::getTHAC0(const Character& character, const Weapon& weapon, const Ammunition* ammo) const
  {
    int rc = 0;
    __f(hit_bonus);
    __f(luck);
    if (weapon.melee == false)
      {
	__f(missile_attack_bonus);
      }
    rc = -rc;
    for (char level : character.record.level) /* TODO make this formula customisable */
      rc -= level - 1;
    int f = (character.fatigue - 24) / 4; /* TODO make this formula customisable */
    if (f > 0)
      rc += f;
    int rc_prof = 0, rc_class = 0;
    int prof = character.record.proficiencies.at(__w);
    for (const Class& c : character.record.prestige)
      {
	rc_prof += c.proficiency_chart.at(__w)[prof].hit_bonus;
	if (rc_class < c.thac0)
	  rc_class = c.thac0;
      }
    rc -= rc_prof / character.record.prestige.size();
    rc += rc_class;
    rc -= weapon.hit_bonus;
    if (ammo != nullptr)
      rc -= ammo->hit_bonus;
    return rc;
  }
  
  /**
   * Gets a character's damage bonus
   * 
   * @param   character  The character
   * @param   weapon     The character's weapon
   * @param   ammo       The character's ammunition
   * @return             The characters damage bonus
   */
  int Calculator::getDamageBonus(const Character& character, const Weapon& weapon, const Ammunition* ammo) const
  {
    int rc = 0;
    if (weapon.melee)
      {
	__f(damage_bonus);
      }
    int rc_prof = 0;
    int prof = character.record.proficiencies.at(__w);
    for (const Class& c : character.record.prestige)
      rc_prof += c.proficiency_chart.at(__w)[prof].damage_bonus;
    rc += rc_prof / character.record.prestige.size();
    rc += weapon.damage_bonus;
    if (ammo != nullptr)
      rc += ammo->damage_bonus;
    return rc;
  }
  
  /**
   * Gets a character's carry limit
   * 
   * @param   character  The character
   * @return             The characters's carry limit in grams
   */
  int Calculator::getCarryLimit(const Character& character) const
  {
    int rc = 0;
    __f(carry_limit);
    return rc;
  }
  
  /**
   * Gets a character's bashing modifier
   * 
   * @param   character  The character
   * @return             The character's bashing modifier
   */
  float Calculator::getBashing(const Character& character) const
  {
    float rc = 0;
    __f(bashing);
    return rc;
  }
  
  /**
   * Gets a character's armour class
   * 
   * @param   character   The character
   * @param   damagetype  The damage type versus which to get the armour class
   * @param   missile     Whether to ger armour class versus missile weapons, otherwise, versus melée weapons
   * @param   weapon      The character's weapon
   * @return              The character's armour class
   */
  int Calculator::getArmourClass(const Character& character, const DamageType& damagetype, bool missile, const Weapon& weapon) const
  {
    int rc = 0;
    __f(armour_class_bonus);
    rc += weapon.bonuses.bonuses.armour_class_bonus;
    if (character.record.inventory.right_hand != nullptr)
      if (*(character.record.inventory.right_hand) >= PROTOTYPE(Shield))
	{
	  Shield* shield = static_cast<Shield*>(character.record.inventory.right_hand);
	  if (missile ? shield->protect_missile : shield->protect_melee[damagetype])
	    {
	      rc += shield->bonuses.bonuses.armour_class_bonus;
	      rc += shield->armour_class_modifiers[damagetype];
	      rc += missile ? shield->bonuses.defence.missile : shield->bonuses.defence.melee;
	    }
	}
    int base = 10; /* TODO make base AC customisable */
    if (character.record.inventory.body != nullptr)
      {
	int candidate;
	candidate = character.record.inventory.body->armour_class;
	if (base > candidate)
	  base = candidate;
      }
    return base - rc;
  }
  
  /**
   * Gets a character's hit point bonus at level up that does not depend on the level
   * 
   * @param   character  The character
   * @return             The character's hit point bonus at level up that does not depend on the level
   */
  int Calculator::getLevelUpHitPointBonus(const Character& character) const
  {
    int rc = 0;
    __f(hit_point_bonus);
    return rc;
  }
  
  /**
   * Get a character's resurrectability
   * 
   * @param   character  The character
   * @return             The character's resurrectability
   */
  float Calculator::getResurrectability(const Character& character) const
  {
    float rc = 0;
    __f(resurrectability);
    return rc;
  }
  
  /**
   * Gets a character's spell level limit
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell level limit, negative for disabled
   */
  int Calculator::getSpellLevelLimit(const Character& character, bool wizard) const
  {
    int rc = 0;
    if (wizard)
      {
	__f(spell_level_limit);
      }
    else
      {
	/* TODO make customisable */
	short wis = getWisdom(character);
	rc = 5;
	if (wis >= 17)  rc++;
	if (wis >= 18)  rc++;
      }
    return rc;
  }
  
  /**
   * Gets a character's spell learn success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell learn success chance, negative for disabled
   */
  float Calculator::getSpellLearn(const Character& character, bool wizard) const
  {
    float rc = 0;
    if (wizard)
      {
	__f(spell_learn);
	bool ok = false;
	for (const Class& c : character.record.prestige)
	  if (c.learn_from_scroll)
	    ok = true;
	if (ok == false)
	  rc = -10;
      }
    else
      rc = -10;
    return rc;
  }
  
  /**
   * Gets a character's spell scroll use success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell scroll use success chance, negative for disabled
   */
  float Calculator::getSpellScrollUse(const Character& character, bool wizard) const
  {
    (void) character;
    (void) wizard;
  //TODO should this depend on something?
    float rc = 2;
    return rc;
  }
  
  /**
   * Gets a character's spell learn count limit
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell learn count limit, negative for disabled
   */
  int Calculator::getSpellCountLimit(const Character& character, bool wizard) const
  {
    int rc = 0;
    if (wizard)
      {
	__f(max_spells_level);
      }
    else
      rc = 0x7FFFffff;
    return rc;
  }
  
  /**
   * Gets a character's spell cast success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell cast use success chance, negative for disabled
   */
  float Calculator::getSpellSuccess(const Character& character, bool wizard) const
  {
    float rc = 0;
    if (wizard)
      {
	rc = 2;
      }
    else
      {
	__f(spell_failure);
	rc = 1 - rc;
	if (rc < 0)
	  rc = 0;
      }
    return rc;
  }
  
  /**
   * Get a characters's number of spell slots
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's numer of spell slots per spell level
   */
  std::vector<int> Calculator::getSpellSlots(const Character& character, bool wizard) const
  {
    std::vector<int> rc = std::vector<int>();
    if (wizard)
      for (size_t c = 0, n = character.record.prestige.size(); c < n; c++)
	{
	  std::vector<std::vector<int>> chart = (std::vector<std::vector<int>>&)(character.record.prestige[c].spell_progression.wizard_slots);
	  char level = character.record.level[c];
	  if (level >= (char)(chart.size()))
	    level = chart.size() - 1;
	  size_t i = 0;
	  for (int count : chart[level])
	    {
  	      if (i >= rc.size())
  		rc.push_back(count);
  	      else
		rc[i] += count;
	      i++;
	    }
	}
    else
      {
	std::vector<std::vector<int>> rca = std::vector<std::vector<int>>();
	__g(bonus_spells, rca.push_back);
	
	
	for (size_t c = 0, n = character.record.prestige.size(); c < n; c++)
	  {
	    std::vector<std::vector<int>> chart = (std::vector<std::vector<int>>&)(character.record.prestige[c].spell_progression.priest_slots);
	    char level = character.record.level[c];
	    if (level >= (char)(chart.size()))
	      level = chart.size() - 1;
	    rca.push_back(chart[level]);
	  }
	
	for (std::vector<int>& rcae : rca)
	  {
	    size_t i = 0;
	    for (int count : rcae)
	      {
		if (i >= rc.size())
		  rc.push_back(count);
		else
		  rc[i] += count;
		i++;
	      }
	  }
      }
    return rc;
  }
  
  /**
   * Gets a character's lore level
   * 
   * @param   character  The character
   * @return             The character's lore level
   */
  int Calculator::getLore(const Character& character) const
  {
    int rc = 0;
    __f(lore_bonus);
    return rc;
  }
  
  /**
   * Gets a character's reaction adjustment
   * 
   * @param   character  The character
   * @return             The character's reaction adjustment
   */
  int Calculator::getReactionAdjustment(const Character& character) const
  {
    int rc = 0;
    __f(reaction_bonus);
    return rc;
  }
  
  /**
   * Gets whether a cahracter is protected against critical hits
   * 
   * @parma   character  The character
   * @return             Whether a cahracter is protected against critical hits
   */
  bool Calculator::getCriticalHitProtected(const Character& character) const
  {
    Headgear* headgear = character.record.inventory.headgear;
    bool rc = (headgear != nullptr) && headgear->critical_hit_protection;
    return rc;
  }
  
//TODO magic defence
//TODO casting level
//TODO detect doors
//TODO armour can block spell casting
//TODO bonuses from used items
//TODO element defence
  
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Calculator::__copy__(Calculator& self, const Calculator& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Calculator::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<RuleSet>()(this->rules);
    return rc;
  }
  
  
  #undef __w
  #undef __f
  #undef ___f
  
}

