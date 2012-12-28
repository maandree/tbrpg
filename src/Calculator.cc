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
  /**
   * Constructor
   */
  Calculator::Calculator() : Object()
  {
    this->class_inheritance.push_back(144);
    ////TODO implement constructor
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(const Calculator& original) : Object(original)
  {
    (void) original;

  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator& original) : Object(original)
  {
    (void) original;

  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Calculator::Calculator(Calculator&& original) : Object(original)
  {
    (void) original;

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
    ////TODO implement destructor
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Calculator& Calculator::operator =(const Calculator& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
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
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);
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
    (void) original;
    std::swap((Object&)*this, (Object&)original);
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
    return character.record.abilities.abilities.strength;
  }
  
  /**
   * Gets a character's strength's extra part of 18
   * 
   * @param   character  The character
   * @return             The character's strength's extra part of 18
   */
  char Calculator::getStrength18(const Character& character) const
  {
    return character.record.abilities.abilities.strength18;
  }
  
  /**
   * Gets a character's constitution
   * 
   * @param   character  The character
   * @return             The character's constitution
   */
  char Calculator::getConstitution(const Character& character) const
  {
    return character.record.abilities.abilities.constitution;
  }
  
  /**
   * Gets a character's dexterity
   * 
   * @param   character  The character
   * @return             The character's dexterity
   */
  char Calculator::getDexterity(const Character& character) const
  {
    return character.record.abilities.abilities.dexterity;
  }
  
  /**
   * Gets a character's intelligence
   * 
   * @param   character  The character
   * @return             The character's intelligence
   */
  char Calculator::getIntelligence(const Character& character) const
  {
    return character.record.abilities.abilities.intelligence;
  }
  
  /**
   * Gets a character's wisdom
   * 
   * @param   character  The character
   * @return             The character's wisdom
   */
  char Calculator::getWisdom(const Character& character) const
  {
    return character.record.abilities.abilities.wisdom;
  }
  
  /**
   * Gets a character's charisma
   * 
   * @param   character  The character
   * @return             The character's charisma
   */
  char Calculator::getCharisma(const Character& character) const
  {
    return character.record.abilities.abilities.charisma;
  }
  
  
  /**
   * Get the number of half attacks inclicted by a character
   * 
   * @param   character  The character
   * @return             The number of half attacks
   */
  int Calculator::getHalfAttacks(const Character& character) const; // character proficiency
  
  /**
   * Get a character's THAC0
   * 
   * @param   character  The character
   * @param   missile    Whether to get THAC0 when using missile weapon, otherwise, when using melée weapon
   * @return             The character's THAC0
   */
  int Calculator::getTHAC0(const Character& character, bool missile) const; // str (dex:missle) proficiency luck $(: -(fatigue - 24) / 4 : 0) weapon class $(-(level - 1))
  
  /**
   * Gets a character's damage bonus
   * 
   * @param   character  The character
   * @param   missile    Whether to get damage bonus when using missile weapon, otherwise, when using melée weapon
   * @return             The characters damage bonus
   */
  int Calculator::getDamageBonus(const Character& character, bool missile) const; // (str:melée) proficiency weapon
  
  /**
   * Gets a character's carry limit
   * 
   * @param   character  The character
   * @return             The characters's carry limit in grams
   */
  int Calculator::getCarryLimit(const Character& character) const; // str
  
  /**
   * Gets a character's bashing modifier
   * 
   * @param   character  The character
   * @return             The character's bashing modifier
   */
  float Calculator::getBashing(const Character& character) const; // str
  
  /**
   * Gets a character's armour class
   * 
   * @param   character   The character
   * @param   damagetype  The damage type versus which to get the armour class
   * @param   missile     Whether to ger armour class versus missile weapons, otherwise, versus melée weapons
   * @return              The character's armour class
   */
  int Calculator::getArmourClass(const Character& character, const DamageType& damagetype, bool missile) const; // dex bodyarmour shield weapon
  
  /**
   * Gets a character's hit point bonus at level up that does not depend on the level
   * 
   * @param   character  The character
   * @return             The character's hit point bonus at level up that does not depend on the level
   */
  int Calculator::getLevelUpHitPointBonus(const Character& character) const; // con
  
  /**
   * Get a character's resurrectability
   * 
   * @param   character  The character
   * @return             The character's resurrectability
   */
  float Calculator::getResurrectability(const Character& character) const; // con
  
  /**
   * Gets a character's spell level limit
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell level limit, negative for disabled
   */
  int Calculator::getSpellLevelLimit(const Character& character, const bool wizard) const; // (wizard:int) (priest:wis)
  
  /**
   * Gets a character's spell learn success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell learn success chance, negative for disabled
   */
  float Calculator::getSpellLearn(const Character& character, const bool wizard) const; // (wizard:int)
  
  /**
   * Gets a character's spell scroll use success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell scroll use success chance, negative for disabled
   */
  float Calculator::getSpellScrollUse(const Character& character, const bool wizard) const; // (wizard:in)
  
  /**
   * Gets a character's spell learn count limit
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell learn count limit, negative for disabled
   */
  int Calculator::getSpellCountLimit(const Character& character, const bool wizard) const; // (wizard:int)
  
  /**
   * Gets a character's spell cast success chance
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's spell cast use success chance, negative for disabled
   */
  float Calculator::getSpellSuccess(const Character& character, const bool wizard) const; // (priest:wis)
  
  /**
   * Get a characters's number of spell slots
   * 
   * @param   character  The character
   * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
   * @return             The character's numer of spell slots per spell level
   */
  std::vector<int> Calculator::getSpellSlots(const Character& character, const bool wizard) const; // (priest:wis)
  
  /**
   * Gets a character's lore level
   * 
   * @param   character  The character
   * @return             The character's lore level
   */
  int Calculator::getLore(const Character& character) const; // int wis
  
  /**
   * Gets a character's reaction adjustment
   * 
   * @param   character  The character
   * @return             The character's reaction adjustment
   */
  int Calculator::getReactionAdjustment(const Character& character) const; // cha
  
  /**
   * Gets whether a cahracter is protected against critical hits
   * 
   * @parma   character  The character
   * @return             Whether a cahracter is protected against critical hits
   */
  bool Calculator::getCriticalHitProtected(const Character& character) const; // helmet
  
  
  
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
    return rc;
  }
  
}

