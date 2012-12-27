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
#ifndef __GUARD_CALCULATOR_HPP__
#define __GUARD_CALCULATOR_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "Character.hpp"



#include "hash.hpp"

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
   * Character attribute calculator
   */
  class Calculator: public Object
  {
  public:
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
    
    
    virtual int getHalfAttacks(const Character& character) const; // character proficiency
    virtual int getTHAC0(const Character& character, bool missile) const; // str (dex:missle) proficiency luck $(: -(fatigue - 24) / 4 : 0) weapon class $(-(level - 1))
    virtual int getDamageBonus(const Character& character, bool missile) const; // (str:melée) proficiency weapon
    virtual int getCarryLimit(const Character& character) const; // str
    virtual int getBashing(const Character& character) const; // str
    virtual int getArmourClass(const Character& character, const DamageType& damagetype, bool missile) const; // dex bodyarmour shield weapon
    virtual int getLevelUpHitPointBonus(const Character& character) const; // con
    virtual int getResurrectability(const Character& character) const; // con
    virtual int getWizardSpellLevelLimit(const Character& character) const; // int
    virtual int getWizardSpellLearn(const Character& character) const; // int
    virtual int getWizardSpellScrollUse(const Character& character) const; // int
    virtual int getWizardSpellCountLimit(const Character& character) const; // int
    virtual int getLore(const Character& character) const; // int wis
    virtual int getPriestSpellFailure(const Character& character) const; // wis
    virtual std::vector<int> getPriestSpellSlots(const Character& character) const; // wis
    virtual std::vector<int> getWizardSpellSlots(const Character& character) const; // 
    virtual int getWizardSpellFailure(const Character& character) const; // 
    virtual int getReactionAdjustment(const Character& character) const; // cha
    virtual bool getCriticalHitProtected(const Character& character) const; // helmet
    
    
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
    size_t hash() const;
    
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

