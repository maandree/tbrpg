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
#include "ActionSlotChart.hpp"
#include "prompter.hpp"
#include "caser.hpp"
#include "cleaner.hpp"


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
  public:
    /**
     * The game's rules
     */
    const RuleSet* ruleset;
    
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
    
    /**
     * Ability dice
     */
    Dice abilityDice;
    
    /**
     * 1D100 dice
     */
    Dice dice100;
    
    /**
     * The character sheet that is being generated
     */
    CharacterSheet* sheet;
    
    
    
    /**
     * Constructor
     * 
     * @param  rules  The game's rules
     */
    CharacterCreator(const RuleSet* rules = nullptr);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterCreator(const CharacterCreator& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    CharacterCreator(CharacterCreator& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    CharacterCreator(CharacterCreator&& original);
    
    
    
    /**
     * Destructor
     */
    ~CharacterCreator();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterCreator& operator =(const CharacterCreator& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual CharacterCreator& operator =(CharacterCreator& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual CharacterCreator& operator =(CharacterCreator&& original);
    
    
    
    /**
     * Create a character sheet
     * 
     * @return  A character sheet, nullptr if aborted
     */
    CharacterSheet* create();
    
    
  private:
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
    bool assign(int n, int unassigned, void* data, void (*printer)(int, int, void*), void (*reroll)(CharacterCreator&) = nullptr);
    
  };
  
}


#endif//__GUARD_CHARACTERCREATOR_HPP__

