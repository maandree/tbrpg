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
#ifndef __GUARD_GAMECHARACTER_HPP__
#define __GUARD_GAMECHARACTER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "hash.hpp"
#include "Action.hpp"
#include "Character.hpp"
#include "MapMinor.hpp"
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
   * Game play wrapper for characters
   */
  class GameCharacter: public Object
  {
  public:
    /**
     * Whether turn undead is on
     */
    bool turn_undead_on;
    
    /**
     * Whether find traps is on
     */
    bool find_traps_on;
    
    /**
     * Whether stealth mode is on
     */
    bool stealth_on;
    
    /**
     * Whether the character can interrupt his current action
     */
    bool self_interruptable;
    
    /**
     * Whether the character is interrupted if damaged
     */
    bool damage_interruptable;
    
    /**
     * The number of turns until the current action is performed
     */
    char turns;
    
    /**
     * The index of the selected weapon
     */
    char weapon;
    
    /**
     * The index of the selected quiver
     */
    char quiver;
    
    /**
     * The current action
     */
    Action* action;
    
    /**
     * The character
     */
    Character* character;
    
    /**
     * The area where teh character currently is located
     */
    MapMinor* area;
    
    
    
    /**
     * Construction
     */
    GameCharacter();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    GameCharacter(const GameCharacter& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    GameCharacter(GameCharacter& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    GameCharacter(GameCharacter&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~GameCharacter();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual GameCharacter& operator =(const GameCharacter& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual GameCharacter& operator =(GameCharacter& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual GameCharacter& operator =(GameCharacter&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const GameCharacter& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const GameCharacter& other) const;
    
    
    /**
     * Select weapon to use
     */
    virtual void selectWeapon();
    
    /**
     * Select quiver to use
     */
    virtual void selectQuiver();
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(GameCharacter& self, const GameCharacter& original);
    
    
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
  class hash<tbrpg::GameCharacter>
  {
  public:
    size_t operator()(const tbrpg::GameCharacter& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::GameCharacter*>
  {
  public:
    size_t operator()(tbrpg::GameCharacter* elem) const
    {
       return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_GAMECHARACTER_HPP__

