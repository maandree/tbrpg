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
#ifndef __GUARD_MAGICSCHOOL_HPP__
#define __GUARD_MAGICSCHOOL_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
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
   * Magic school class
   */
  class MagicSchool: public Object
  {
  public:
    /**
     * The name of the school
     */
    std::string name;
    
    /**
     * The colouration of the magic in the school
     */
    std::string coluration;
    
    /**
     * The name of the practicers of the school
     */
    std::string practicer;
    
    /**
     * The opposite schools
     */
    std::vector<MagicSchool> opposite;
    
    
    
    /**
     * Construction
     * 
     * @param  schoolName        The name of the school
     * @param  effectColuration  The colouration of the magic in the school
     * @param  practicerName     The name of the practicers of the school
     */
    MagicSchool(std::string schoolName = "", std::string effectColuration = "", std::string practicerName = "");
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(const MagicSchool& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(MagicSchool& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    MagicSchool(MagicSchool&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~MagicSchool();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(const MagicSchool& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(MagicSchool& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual MagicSchool& operator =(MagicSchool&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const MagicSchool& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const MagicSchool& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(MagicSchool& self, const MagicSchool& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
  
  
  
  /**
   * Magic school: none
   */
  static const MagicSchool GENERAL_MAGE = MagicSchool("general", "", "general mage");
  
  /**
   * Magic school: abjuration
   */
  static MagicSchool ABJURATION = MagicSchool("abjuration", "green", "abjurer");
  
  /**
   * Magic school: alteration
   */
  static MagicSchool ALTERATION = MagicSchool("alteration", "blue", "transmuter");
  
  /**
   * Magic school: conjuration
   */
  static MagicSchool CONJURATION = MagicSchool("conjuration", "orange", "conjurer");
  
  /**
   * Magic school: divination
   */
  static MagicSchool DIVINATION = MagicSchool("divination", "white/pearl", "diviner");
  
  /**
   * Magic school: enchantment
   */
  static MagicSchool ENCHANTMENT = MagicSchool("enchantment", "magenta", "enchanter");
  
  /**
   * Magic school: illusion
   */
  static MagicSchool ILLUSION = MagicSchool("illusion", "multicoloured", "illusionist");
  
  /**
   * Magic school: invocation
   */
  static MagicSchool INVOCATION = MagicSchool("invocation", "red", "invoker");
  
  /**
   * Magic school: necromancy
   */
  static MagicSchool NECROMANCY = MagicSchool("necromancy", "ice/blue", "necromancer");
  
}

namespace std
{
  template<>
  class hash<tbrpg::MagicSchool>
  {
  public:
    size_t operator()(const tbrpg::MagicSchool& elem) const
    {
       return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::MagicSchool*>
  {
  public:
    size_t operator()(tbrpg::MagicSchool* elem) const
    {
       return elem->hash();
    }
  };
}


#endif//__GUARD_MAGICSCHOOL_HPP__

