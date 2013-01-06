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
#ifndef __GUARD_CLASS_HPP__
#define __GUARD_CLASS_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Object.hpp"
#include "Fist.hpp"
#include "Fists.hpp"
#include "hash.hpp"
#include "ExperienceChart.hpp"
#include "SpellProgression.hpp"
#include "AbilityBonus.hpp"
#include "Abilities.hpp"
#include "Spell.hpp"
#include "Item.hpp"
#include "MagicSchool.hpp"
#include "WeaponGroup.hpp"
#include "Proficiency.hpp"
#include "Weapon.hpp"
#include "Helmet.hpp"
#include "Hood.hpp"
#include "StuddedLeatherArmour.hpp"
#include "LeatherArmour.hpp"
#include "SmallShield.hpp"
#include "Buckler.hpp"
#include "Dart.hpp"
#include "Sling.hpp"
#include "ThrowingDagger.hpp"
#include "Bullet.hpp"
#include "Torch.hpp"
#include "Quarterstaff.hpp"
#include "Dagger.hpp"
#include "Club.hpp"
#include "Potion.hpp"
#include "LowScroll.hpp"
#include "LowWand.hpp"


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
   * Prestige class
   */
  class Class: public Object
  {
  public:
    /**
     * The name of the class
     */
    std::string name;
    
    /**
     * Minimum starting hit points
     */
    int hit_points;
    
    /**
     * THAC0
     */
    int thac0;
    
    /**
     * Lore bonus per level
     */
    int lore_bonus;
    
    /**
     * Allowed alignments
     */
    bool* alignments;
    
    /**
     * Whether the character can learn wizard spells from scrolls
     */
    bool learn_from_scroll;
    
    /**
     * The number of proficiencies scores that may be assigned to each weapon proficiency for new level 1 characters
     */
    char proficiencies_each;
    
    /**
     * Whether the extra strength at strength 18 is not fixed to zero
     */
    bool extra_strength;
    
    /**
     * Whether characters of this class have a racial enemy
     */
    bool have_racial_enemy;
    
    /**
     * The class's experience chart
     */
    ExperienceChart experience_chart;
    
    /**
     * The class's spell progression chart
     */
    SpellProgression spell_progression;
    
    /**
     * Abilties
     */
    AbilityBonus abilities;
    
    /**
     * Lower ability bounds
     */
    Abilities lower_limits;
    
    /**
     * Special abilities
     */
    std::vector<Spell*> special_abilities;
    
    /**
     * Usable items
     */
    std::unordered_map<Item*, bool> can_use;
    
    /**
     * Availiable specialisations for the class
     */
    std::vector<MagicSchool> specialisations;
    
    /**
     * Proficiency chart
     */
    std::unordered_map<WeaponGroup, std::vector<Proficiency>> proficiency_chart;
    
    /**
     * Weapon used when the character has his left hand free but is holding a shield
     */
    Weapon default_one_hand;
    
    /**
     * Weapon used when the character has both his hands free
     */
    Weapon default_two_hands;
    
    
    
    /**
     * Construction
     */
    Class();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Class(const Class& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Class(Class& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Class(Class&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Class();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Class& operator =(const Class& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Class& operator =(Class& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Class& operator =(Class&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Class& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Class& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Class& self, const Class& original);
    
    
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
  class hash<tbrpg::Class>
  {
  public:
    size_t operator()(const tbrpg::Class& elem) const
    {
      return dynamic_cast<Class*>(&elem)->hash();
    }
  };
  
  template<>
  class hash<tbrpg::Class*>
  {
  public:
    size_t operator()(tbrpg::Class* elem) const
    {
      return elem == nullptr ? 0 : dynamic_cast<Class*>(elem)->hash();
    }
  };
}


#endif//__GUARD_CLASS_HPP__

