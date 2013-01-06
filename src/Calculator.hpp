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
#ifndef __GUARD_CALCULATOR_HPP__
#define __GUARD_CALCULATOR_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "Character.hpp"



#include "hash.hpp"
#include "RuleSet.hpp"


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
   * Character attribute façade
   */
  class Calculator: public Object
  {
  public:
    /**
     * The game rules
     */
    RuleSet rules;
    
    
    
    /**
     * Construction
     */
    Calculator();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Calculator(const Calculator& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Calculator(Calculator& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Calculator(Calculator&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Calculator();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Calculator& operator =(const Calculator& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Calculator& operator =(Calculator& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Calculator& operator =(Calculator&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Calculator& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Calculator& other) const;
    
    
    
    /**
     * Gets a character's strength
     * 
     * @param   character  The character
     * @return             The character's strength
     */
    virtual char getStrength(const Character& character) const;
    
    /**
     * Gets a character's strength's extra part of 18
     * 
     * @param   character  The character
     * @return             The character's strength's extra part of 18
     */
    virtual char getStrength18(const Character& character) const;
    
    /**
     * Gets a character's constitution
     * 
     * @param   character  The character
     * @return             The character's constitution
     */
    virtual char getConstitution(const Character& character) const;
    
    /**
     * Gets a character's dexterity
     * 
     * @param   character  The character
     * @return             The character's dexterity
     */
    virtual char getDexterity(const Character& character) const;
    
    /**
     * Gets a character's intelligence
     * 
     * @param   character  The character
     * @return             The character's intelligence
     */
    virtual char getIntelligence(const Character& character) const;
    
    /**
     * Gets a character's wisdom
     * 
     * @param   character  The character
     * @return             The character's wisdom
     */
    virtual char getWisdom(const Character& character) const;
    
    /**
     * Gets a character's charisma
     * 
     * @param   character  The character
     * @return             The character's charisma
     */
    virtual char getCharisma(const Character& character) const;
    
    
    /**
     * Get the number of half attacks inclicted by a character
     * 
     * @param   character  The character
     * @param   weapon     The character's weapon
     * @return             The number of half attacks
     */
    virtual char getHalfAttacks(const Character& character, const Weapon& weapon) const;
    
    /**
     * Get a character's THAC0
     * 
     * @param   character  The character
     * @param   weapon     The character's weapon
     * @param   ammo       The character's ammunition
     * @return             The character's THAC0
     */
    virtual int getTHAC0(const Character& character, const Weapon& weapon, const Ammunition* ammo) const;
    
    /**
     * Gets a character's damage bonus
     * 
     * @param   character  The character
     * @param   weapon     The character's weapon
     * @param   ammo       The character's ammunition
     * @return             The characters damage bonus
     */
    virtual int getDamageBonus(const Character& character, const Weapon& weapon, const Ammunition* ammo) const;
    
    /**
     * Gets a character's carry limit
     * 
     * @param   character  The character
     * @return             The characters's carry limit in grams
     */
    virtual int getCarryLimit(const Character& character) const;
    
    /**
     * Gets a character's bashing modifier
     * 
     * @param   character  The character
     * @return             The character's bashing modifier
     */
    virtual float getBashing(const Character& character) const;
    
    /**
     * Gets a character's armour class
     * 
     * @param   character   The character
     * @param   damagetype  The damage type versus which to get the armour class
     * @param   missile     Whether to ger armour class versus missile weapons, otherwise, versus melée weapons
     * @return              The character's armour class
     */
    virtual int getArmourClass(const Character& character, const DamageType& damagetype, bool missile, const Weapon& weapon) const;
    
    /**
     * Gets a character's hit point bonus at level up that does not depend on the level
     * 
     * @param   character  The character
     * @return             The character's hit point bonus at level up that does not depend on the level
     */
    virtual int getLevelUpHitPointBonus(const Character& character) const;
    
    /**
     * Get a character's resurrectability
     * 
     * @param   character  The character
     * @return             The character's resurrectability
     */
    virtual float getResurrectability(const Character& character) const;
    
    /**
     * Gets a character's spell level limit
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's spell level limit, negative for disabled
     */
    virtual int getSpellLevelLimit(const Character& character, bool wizard) const;
    
    /**
     * Gets a character's spell learn success chance
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's spell learn success chance, negative for disabled
     */
    virtual float getSpellLearn(const Character& character, bool wizard) const;
    
    /**
     * Gets a character's spell scroll use success chance
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's spell scroll use success chance, negative for disabled
     */
    virtual float getSpellScrollUse(const Character& character, bool wizard) const;
    
    /**
     * Gets a character's spell learn count limit
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's spell learn count limit, negative for disabled
     */
    virtual int getSpellCountLimit(const Character& character, bool wizard) const;
    
    /**
     * Gets a character's spell cast success chance
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's spell cast use success chance, negative for disabled
     */
    virtual float getSpellSuccess(const Character& character, bool wizard) const;
    
    /**
     * Get a characters's number of spell slots
     * 
     * @param   character  The character
     * @param   wizard     Whether it concerns wizard spells, otherwise, priest spells
     * @return             The character's numer of spell slots per spell level
     */
    virtual std::vector<int> getSpellSlots(const Character& character, bool wizard) const;
    
    /**
     * Gets a character's lore level
     * 
     * @param   character  The character
     * @return             The character's lore level
     */
    virtual int getLore(const Character& character) const;
    
    /**
     * Gets a character's reaction adjustment
     * 
     * @param   character  The character
     * @return             The character's reaction adjustment
     */
    virtual int getReactionAdjustment(const Character& character) const;
    
    /**
     * Gets whether a cahracter is protected against critical hits
     * 
     * @param   character  The character
     * @return             Whether a character is protected against critical hits
     */
    virtual bool getCriticalHitProtected(const Character& character) const;
    
    /**
     * Gets a character's backstab multiplier
     * 
     * @param   character  The character
     * @return             The character's backstab multiplier
     */
    virtual int getBackstabMultiplier(const Character& character) const;
    
    /**
     * Gets a character's lock picking modifier
     * 
     * @param   character  The character
     * @return             The character's lock picking modifier
     */
    virtual float getPicking(const Character& character) const;
    
    /**
     * Gets a character's pick pocketing modifier
     * 
     * @param   character  The character
     * @return             The character's pick pocketing modifier
     */
    virtual float getStealing(const Character& character) const;
    
    /**
     * Gets a character's stealth modifier
     * 
     * @param   character  The character
     * @return             The character's stealth modifier
     */
    virtual float getHiding(const Character& character) const;
    
    /**
     * Gets a character's find traps modifier
     * 
     * @param   character  The character
     * @return             The character's find traps modifier
     */
    virtual float getFinding(const Character& character) const;
    
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Calculator& self, const Calculator& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    virtual size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Calculator>
  {
  public:
    size_t operator()(const tbrpg::Calculator& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Calculator*>
  {
  public:
    size_t operator()(tbrpg::Calculator* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_CALCULATOR_HPP__

