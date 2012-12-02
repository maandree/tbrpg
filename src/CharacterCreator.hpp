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

#include "CharacterSheet.hpp"
#include "RuleSet.hpp"
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
     * @return  A character sheet
     */
    virtual CharacterSheet create() const;
    
  };
  
}


#endif//__GUARD_CHARACTERCREATOR_HPP__

