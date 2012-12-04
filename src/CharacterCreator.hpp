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
#ifndef __GUARD_CHARACTERCREATOR_HPP__
#define __GUARD_CHARACTERCREATOR_HPP__


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <unordered_map>

#include "CharacterSheet.hpp"
#include "RuleSet.hpp"
#include "Dice.hpp"
#include "prompter.hpp"


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
   * Character creator class
   */
  class CharacterCreator
  {
  protected:
    /**
     * The game's rules
     */
    RuleSet ruleset;
    
    /**
     * The start values, these are updated by the assign function
     */
    int* start;
    
    /**
     * The lower bounds
     */
    int* lower;
    
    /**
     * The upper bounds
     */
    int* upper;
    
    
    
  public:
    /**
     * Constructor
     * 
     * @param  rules  The game's rules
     */
    CharacterCreator(const RuleSet& rules);
    
    /**
     * Destructor
     */
    virtual ~CharacterCreator();
    
    
    
    /**
     * Create a character sheet
     * 
     * @return  A character sheet, nullptr if aborted
     */
    virtual CharacterSheet* create() const;
    
    
  protected:
    
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
    virtual bool assign(int n, int unassigned, void* data, void (*printer)(int, int, void*), void (**reroll)() == nullptr);
    
    /**
     * Ability score printer
     * 
     * @param  index  The index of the ability
     * @param  value  The value of the ability
     * @param  data   Pointer to the 100-part of the strenght
     */
    virtual void abilityPrinter(int index, int value, void* data);
    
    /**
     * Ability score reroll
     */
    virtual void abilityReroll();
    
  };
  
}


#endif//__GUARD_CHARACTERCREATOR_HPP__

