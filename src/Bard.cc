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
#include "Bard.hpp"


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
  Bard::Bard() : Rogue()
  {
    this->name = "bard";
    this->thac0 = 20;
    this->lore_bonus = 10;
    this->lower_limits.charisma = 9;
    this->alignments[8] = false;
    this->alignments[6] = false;
    this->alignments[2] = false;
    this->alignments[0] = false;
    
    this->abilities.thief_abilities.limit = 99;
    this->abilities.thief_abilities.stealth = 10;
    for (long i = 2; i <= 30; i++)
      this->experience_chart.thief_abilities[i] = 5;
    
    this->can_use[ChainMail()] = true;
    this->can_use[LongBow()] = true;
    this->can_use[HeavyCrossbow()] = true;
    this->can_use[LightCrossbow()] = true;
    this->can_use[Flail()] = true;
    this->can_use[Halberd()] = true;
    this->can_use[TwoHandedSword()] = true;
    this->can_use[WarHammer()] = true;
    this->can_use[BastardSword()] = true;
    this->can_use[BattleAxe()] = true;
    this->can_use[Bolt()] = true;
    this->can_use[Mace()] = true;
    this->can_use[MorningStar()] = true;
    this->can_use[Spear()] = true;
    
    this->spell_progression.wizard_slots = std::vector<std::vector<int>>(24);
    for (int i = 0; i <= 23; i++)
      this->spell_progression.wizard_slots[i] = std::vector<int>(7);
    
    this->spell_progression.wizard_levels = std::vector<int>(31);
    for (int i = 0; i <= 30; i++)
      this->spell_progression.wizard_levels[i] = i < 2 ? 0 : i > 23 ? 8 : ((i + 1) / 3);
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 2:
	  case 3:
	  case 5:
	  case 16:
	  case 21:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][1] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 4:
	  case 6:
	  case 8:
	  case 17:
	  case 22:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][2] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 7:
	  case 9:
	  case 11:
	  case 18:
	  case 23:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][3] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 10:
	  case 12:
	  case 14:
	  case 19:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][4] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 13:
	  case 15:
	  case 17:
	  case 20:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][5] = cur;
      }
    
    for (int cur = 0, i = 0; i <= 23; i++)
      {
	switch (cur)
	  {
	  case 16:
	  case 18:
	  case 20:
	  case 23:
	    cur++;
	  }
	this->spell_progression.wizard_slots[i][6] = cur;
      }
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(const Bard& original) : Rogue(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(Bard& original) : Rogue(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Bard::Bard(Bard&& original) : Rogue(original)
  {
    (void) original;
  }
  
  
  
  /**
   * Destructor
   */
  Bard::~Bard()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bard& Bard::operator =(const Bard& original)
  {
    Rogue::__copy__((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bard& Bard::operator =(Bard& original)
  {

    Rogue::__copy__((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Bard& Bard::operator =(Bard&& original)
  {
    std::swap((Rogue&)*this, (Rogue&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Bard::operator ==(const Bard& other) const
  {
    if ((Rogue&)(*this) != (Rogue&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Bard::operator !=(const Bard& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Bard::__copy__(Bard& self, const Bard& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Bard::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Rogue>()(*this);
    return rc;
  }
  
}

