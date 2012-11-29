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
#ifndef __GUARD_ABILITYBONUS_HPP__
#define __GUARD_ABILITYBONUS_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>



#include "Bonuses.hpp"
#include "ThiefAbilities.hpp"
#include "SavingThrows.hpp"
#include "Abilities.hpp"
#include "SpellBook.hpp"
#include "Spell.hpp"
#include "Defence.hpp"


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
   * Abilities bonus class
   */
  class AbilityBonus
  {
  public:
    /**
     * Bonuses
     */
    Bonuses bonuses;
    
    /**
     * Thief abilities
     */
    ThiefAbilities thief_abilities;
    
    /**
     * Saving throws
     */
    SavingThrows saving_throws;
    
    /**
     * Abilities
     */
    Abilities abilities;
    
    /**
     * Spells
     */
    SpellBook spells;
    
    /**
     * Effects
     */
    std::vector<Spell> effects;
    
    /**
     * Defences
     */
    Defence defence;
    
    
    
    /**
     * Construction
     */
    AbilityBonus();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    AbilityBonus(const AbilityBonus& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    AbilityBonus(AbilityBonus& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    AbilityBonus(AbilityBonus&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~AbilityBonus();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual AbilityBonus& operator =(const AbilityBonus& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual AbilityBonus& operator =(AbilityBonus& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual AbilityBonus& operator =(AbilityBonus&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const AbilityBonus& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(AbilityBonus& self, const AbilityBonus& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::AbilityBonus>
  {
  public:
    size_t operator()(const tbrpg::AbilityBonus& elem) const
    {
       return elem.hash();
    }
  };
}


#endif//__GUARD_ABILITYBONUS_HPP__

