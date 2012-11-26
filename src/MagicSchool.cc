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
   * Constructor
   */
  MagicSchool::MagicSchool()
  {
    //TODO implement constructor
    //hit_points = nullptr;
    //alive = nullptr;
    //morale = nullptr;
    //intoxication = nullptr;
    //fatigue = nullptr;
    //record = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(const MagicSchool& original)
  {
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->record = original.record;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(MagicSchool& original)
  {
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->record = original.record;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  MagicSchool::MagicSchool(MagicSchool&& original)
  {
    std::move(this->hit_points, original.hit_points);
    std::move(this->alive, original.alive);
    std::move(this->morale, original.morale);
    std::move(this->intoxication, original.intoxication);
    std::move(this->fatigue, original.fatigue);
    std::move(this->record, original.record);
  }
  
  
  
  /**
   * Destructor
   */
  MagicSchool::~MagicSchool()
  {
    //TODO implement destructor
    //delete hit_points;
    //delete alive;
    //delete morale;
    //delete intoxication;
    //delete fatigue;
    //delete record;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(const MagicSchool& original)
  {
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->record = original.record;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(MagicSchool& original)
  {
    this->hit_points = original.hit_points;
    this->alive = original.alive;
    this->morale = original.morale;
    this->intoxication = original.intoxication;
    this->fatigue = original.fatigue;
    this->record = original.record;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  MagicSchool& MagicSchool::operator =(MagicSchool&& original)
  {
    std::move(this->hit_points, original.hit_points);
    std::move(this->alive, original.alive);
    std::move(this->morale, original.morale);
    std::move(this->intoxication, original.intoxication);
    std::move(this->fatigue, original.fatigue);
    std::move(this->record, original.record);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void MagicSchool::__copy__(MagicSchool& self, const MagicSchool& original);
  {
    left = right;
  }
  
}

