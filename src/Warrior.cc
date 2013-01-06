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
#include "Warrior.hpp"


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
   * Constructor
   */
  Warrior::Warrior() : Class()
  {
    this->class_inheritance.push_back(112);
    this->proficiencies_each = 2;
    this->hit_points = 10;
    this->thac0 = 22;
    this->abilities.saving_throws.breath = 17;
    this->abilities.saving_throws.paralyze_poison_death = 14;
    this->abilities.saving_throws.petrification_polymorph = 15;
    this->abilities.saving_throws.rod_staff_wand = 16;
    this->abilities.saving_throws.spell = 17;
    this->lower_limits.strength = 9;
    this->extra_strength = true;
    /*
    this->can_use[&PROTOTYPE(MediumShield)] = true;
    this->can_use[&PROTOTYPE(LargeShield)] = true;
    this->can_use[&PROTOTYPE(ChainMail)] = true;
    this->can_use[&PROTOTYPE(SplintMail)] = true;
    this->can_use[&PROTOTYPE(PlateMail)] = true;
    this->can_use[&PROTOTYPE(FullPlateMail)] = true;
    this->can_use[&PROTOTYPE(CompositeLongBow)] = true;
    this->can_use[&PROTOTYPE(LongBow)] = true;
    this->can_use[&PROTOTYPE(ShortBow)] = true;
    this->can_use[&PROTOTYPE(HeavyCrossbow)] = true;
    this->can_use[&PROTOTYPE(LightCrossbow)] = true;
    this->can_use[&PROTOTYPE(ThrowingAxe)] = true;
    this->can_use[&PROTOTYPE(Flail)] = true;
    this->can_use[&PROTOTYPE(Halberd)] = true;
    this->can_use[&PROTOTYPE(TwoHandedSword)] = true;
    this->can_use[&PROTOTYPE(WarHammer)] = true;
    this->can_use[&PROTOTYPE(Arrow)] = true;
    this->can_use[&PROTOTYPE(BastardSword)] = true;
    this->can_use[&PROTOTYPE(BattleAxe)] = true;
    this->can_use[&PROTOTYPE(Bolt)] = true;
    this->can_use[&PROTOTYPE(LongSword)] = true;
    this->can_use[&PROTOTYPE(Mace)] = true;
    this->can_use[&PROTOTYPE(MorningStar)] = true;
    this->can_use[&PROTOTYPE(ShortSword)] = true;
    this->can_use[&PROTOTYPE(Spear)] = true;
    */
    for (const WeaponGroup* weapongroup : WEAPON_GROUPS)
      this->proficiency_chart[*weapongroup].push_back(Proficiency(3, 4, 3));
    
    this->experience_chart.experience = std::vector<int>(31);
    this->experience_chart.hit_point_die = std::vector<char>(31);
    this->experience_chart.hit_point_dice = std::vector<char>(31);
    this->experience_chart.hit_point_bonus = std::vector<int>(31);
    this->experience_chart.proficiencies = std::vector<int>(31);
    
    for (int i = 1; i <= 30; i++)
      {
	this->experience_chart.hit_point_die[i] = 10;
	this->experience_chart.hit_point_dice[i] = i > 9 ? 9 : i;
	this->experience_chart.hit_point_bonus[i] = i <= 9 ? 0 : ((i - 9) * 3);
	this->experience_chart.proficiencies[i] = i / 3 + 4;
	if (i <= 1)
	  this->experience_chart.experience[i] = 0;
	else if (i <= 6)
	  this->experience_chart.experience[i] = 2250 << (i - 2);
	else if (i <= 10)
	  this->experience_chart.experience[i] = 75000 << (i - 7);
	else
	  this->experience_chart.experience[i] = 300000 * (i - 8);
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(const Warrior& original) : Class(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(Warrior& original) : Class(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Warrior::Warrior(Warrior&& original) : Class(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Warrior::fork() const
  {
    return (Object*)(new Warrior(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Warrior::~Warrior()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(const Warrior& original)
  {
    Class::__copy__((Class&)*this, (Class&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(Warrior& original)
  {
    Class::__copy__((Class&)*this, (Class&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Warrior& Warrior::operator =(Warrior&& original)
  {
    std::swap((Class&)*this, (Class&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Warrior::operator ==(const Warrior& other) const
  {
    if ((Class&)(*this) != (Class&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Warrior::operator !=(const Warrior& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Warrior::__copy__(Warrior& self, const Warrior& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Warrior::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Class>()(*this);
    return rc;
  }
  
}

