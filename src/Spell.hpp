// -*- mode: c++, coding: utf-8 -*-
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
#ifndef __GUARD_SPELL_HPP__
#define __GUARD_SPELL_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"



#include "hash.hpp"
#include "MagicSchool.hpp"


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
   * Spell class
   */
  class Spell: public Object
  {
  public:
    /**
     * Spell name
     */
    std::string name;
    
    /**
     * Spell description
     */
    std::string description;
    
    /**
     * Whether the spell is a wizard spell
     */
    bool wizard;
    
    /**
     * Whether the spell is a priest spell
     */
    bool priest;
    
    /**
     * Spell level
     */
    char level;
    
    /**
     * Saving, 0 for none, 1 for half and 2 for negation
     */
    char saving;
    
    /**
     * Whether the spell's range is touching
     */
    bool touch;
    
    /**
     * Whether the spell's range, negative for touch without zero
     */
    float range;
    
    /**
     * Casting time
     */
    char casting_time;
    
    /**
     * Duration modifier
     */
    char duration;
    
    /**
     * Duration die side count
     */
    char duration_die;
    
    /**
     * Duration die count
     */
    char duration_dice;
    
    /**
     * Area of effect
     */
    std::string effect_area;
    
    /**
     * 1 if offensive, −1 if defensive and 0 if informative
     */
    signed char offensiveness;
    
    /**
     * Magic shool
     */
    MagicSchool school;
    
    
    
    /**
     * Construction
     */
    Spell();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Spell(const Spell& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Spell(Spell& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Spell(Spell&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Spell();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Spell& operator =(const Spell& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Spell& operator =(Spell& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Spell& operator =(Spell&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Spell& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Spell& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Spell& self, const Spell& original);
    
    
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
  class hash<tbrpg::Spell>
  {
  public:
    size_t operator()(const tbrpg::Spell& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Spell*>
  {
  public:
    size_t operator()(tbrpg::Spell* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_SPELL_HPP__

