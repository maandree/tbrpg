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
#include "Spell.hpp"


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
  Spell::Spell()
  {
    ////TODO implement constructor
    //this->name = nullptr;
    //this->description = nullptr;
    //this->wizard = false;
    //this->priest = false;
    //this->level = 0;
    //this->saving = 0;
    //this->touch = false;
    //this->range = 0;
    //this->casting_time = 0;
    //this->duration = 0;
    //this->duration_die = 0;
    //this->duration_dice = 0;
    //this->effect_area = nullptr;
    //this->school = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(const Spell& original)
  {
    (void) original;
    //this->name = original.name;
    //this->description = original.description;
    //this->wizard = original.wizard;
    //this->priest = original.priest;
    //this->level = original.level;
    //this->saving = original.saving;
    //this->touch = original.touch;
    //this->range = original.range;
    //this->casting_time = original.casting_time;
    //this->duration = original.duration;
    //this->duration_die = original.duration_die;
    //this->duration_dice = original.duration_dice;
    //this->effect_area = original.effect_area;
    //this->school = original.school;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell& original)
  {
    (void) original;
    //this->name = original.name;
    //this->description = original.description;
    //this->wizard = original.wizard;
    //this->priest = original.priest;
    //this->level = original.level;
    //this->saving = original.saving;
    //this->touch = original.touch;
    //this->range = original.range;
    //this->casting_time = original.casting_time;
    //this->duration = original.duration;
    //this->duration_die = original.duration_die;
    //this->duration_dice = original.duration_dice;
    //this->effect_area = original.effect_area;
    //this->school = original.school;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Spell::Spell(Spell&& original)
  {
    (void) original;
    ////std::move(this->name, original.name);
    ////std::move(this->description, original.description);
    ////std::swap(this->wizard, original.wizard);
    ////std::swap(this->priest, original.priest);
    ////std::swap(this->level, original.level);
    ////std::swap(this->saving, original.saving);
    ////std::swap(this->touch, original.touch);
    ////std::swap(this->range, original.range);
    ////std::swap(this->casting_time, original.casting_time);
    ////std::swap(this->duration, original.duration);
    ////std::swap(this->duration_die, original.duration_die);
    ////std::swap(this->duration_dice, original.duration_dice);
    ////std::move(this->effect_area, original.effect_area);
    ////std::move(this->school, original.school);
  }
  
  
  
  /**
   * Destructor
   */
  Spell::~Spell()
  {
    ////TODO implement destructor
    //delete name;
    //delete description;
    //delete effect_area;
    //delete school;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(const Spell& original)
  {
    (void) original;
    //this->name = original.name;
    //this->description = original.description;
    //this->wizard = original.wizard;
    //this->priest = original.priest;
    //this->level = original.level;
    //this->saving = original.saving;
    //this->touch = original.touch;
    //this->range = original.range;
    //this->casting_time = original.casting_time;
    //this->duration = original.duration;
    //this->duration_die = original.duration_die;
    //this->duration_dice = original.duration_dice;
    //this->effect_area = original.effect_area;
    //this->school = original.school;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell& original)
  {
    (void) original;
    //this->name = original.name;
    //this->description = original.description;
    //this->wizard = original.wizard;
    //this->priest = original.priest;
    //this->level = original.level;
    //this->saving = original.saving;
    //this->touch = original.touch;
    //this->range = original.range;
    //this->casting_time = original.casting_time;
    //this->duration = original.duration;
    //this->duration_die = original.duration_die;
    //this->duration_dice = original.duration_dice;
    //this->effect_area = original.effect_area;
    //this->school = original.school;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Spell& Spell::operator =(Spell&& original)
  {
    (void) original;
    ////std::move(this->name, original.name);
    ////std::move(this->description, original.description);
    ////std::swap(this->wizard, original.wizard);
    ////std::swap(this->priest, original.priest);
    ////std::swap(this->level, original.level);
    ////std::swap(this->saving, original.saving);
    ////std::swap(this->touch, original.touch);
    ////std::swap(this->range, original.range);
    ////std::swap(this->casting_time, original.casting_time);
    ////std::swap(this->duration, original.duration);
    ////std::swap(this->duration_die, original.duration_die);
    ////std::swap(this->duration_dice, original.duration_dice);
    ////std::move(this->effect_area, original.effect_area);
    ////std::move(this->school, original.school);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Spell::__copy__(Spell& self, const Spell& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Spell::hash() const
  {
    return (size_t)this;
  }
  
}

