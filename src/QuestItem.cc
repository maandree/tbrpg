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
#include "QuestItem.hpp"


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
  QuestItem::QuestItem()
  {
    //TODO implement constructor
    //hit_bonus = nullptr;
    //bonus = nullptr;
    //half_attacks = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(const QuestItem& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->bonus = original.bonus;
    this->half_attacks = original.half_attacks;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(QuestItem& original)
  {
    this->hit_bonus = original.hit_bonus;
    this->bonus = original.bonus;
    this->half_attacks = original.half_attacks;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  QuestItem::QuestItem(QuestItem&& original)
  {
    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->bonus, original.bonus);
    std::move(this->half_attacks, original.half_attacks);
  }
  
  
  
  /**
   * Destructor
   */
  QuestItem::~QuestItem()
  {
    //TODO implement destructor
    //delete hit_bonus;
    //delete bonus;
    //delete half_attacks;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(const QuestItem& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hit_bonus = original.hit_bonus;
    this->bonus = original.bonus;
    this->half_attacks = original.half_attacks;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(QuestItem& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->hit_bonus = original.hit_bonus;
    this->bonus = original.bonus;
    this->half_attacks = original.half_attacks;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  QuestItem& QuestItem::operator =(QuestItem&& original)
  {
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);
    std::move((Item)*this, (Item)original);    std::move(this->hit_bonus, original.hit_bonus);
    std::move(this->bonus, original.bonus);
    std::move(this->half_attacks, original.half_attacks);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void QuestItem::__copy__(QuestItem& self, const QuestItem& original);
  {
    left = right;
  }
  
}

