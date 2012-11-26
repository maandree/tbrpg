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
#include "EnvironmentContainer.hpp"


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
  EnvironmentContainer::EnvironmentContainer()
  {
    //TODO implement constructor
    //first_distance = nullptr;
    //last_distance = nullptr;
    //waylay_die = nullptr;
    //waylay_dice = nullptr;
    //waylay_risk = 0;
    //direction = nullptr;
    //waylay_map = nullptr;
    //leads_to = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  EnvironmentContainer::EnvironmentContainer(const EnvironmentContainer& original)
  {
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  EnvironmentContainer::EnvironmentContainer(EnvironmentContainer& original)
  {
    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  EnvironmentContainer::EnvironmentContainer(EnvironmentContainer&& original)
  {
    std::move(this->first_distance, original.first_distance);
    std::move(this->last_distance, original.last_distance);
    std::move(this->waylay_die, original.waylay_die);
    std::move(this->waylay_dice, original.waylay_dice);
    std::swap(this->waylay_risk, original.waylay_risk);
    std::move(this->direction, original.direction);
    std::move(this->waylay_map, original.waylay_map);
    std::move(this->leads_to, original.leads_to);
  }
  
  
  
  /**
   * Destructor
   */
  EnvironmentContainer::~EnvironmentContainer()
  {
    //TODO implement destructor
    //delete first_distance;
    //delete last_distance;
    //delete waylay_die;
    //delete waylay_dice;
    //delete direction;
    //delete waylay_map;
    //delete leads_to;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  EnvironmentContainer& EnvironmentContainer::operator =(const EnvironmentContainer& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  EnvironmentContainer& EnvironmentContainer::operator =(EnvironmentContainer& original)
  {
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);
    %s::__copy__((%s&)*this, (%s&)original);    this->first_distance = original.first_distance;
    this->last_distance = original.last_distance;
    this->waylay_die = original.waylay_die;
    this->waylay_dice = original.waylay_dice;
    this->waylay_risk = original.waylay_risk;
    this->direction = original.direction;
    this->waylay_map = original.waylay_map;
    this->leads_to = original.leads_to;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  EnvironmentContainer& EnvironmentContainer::operator =(EnvironmentContainer&& original)
  {
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);
    std::move((Container,)*this, (Container,)original);
    std::move((Lockable)*this, (Lockable)original);    std::move(this->first_distance, original.first_distance);
    std::move(this->last_distance, original.last_distance);
    std::move(this->waylay_die, original.waylay_die);
    std::move(this->waylay_dice, original.waylay_dice);
    std::swap(this->waylay_risk, original.waylay_risk);
    std::move(this->direction, original.direction);
    std::move(this->waylay_map, original.waylay_map);
    std::move(this->leads_to, original.leads_to);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void EnvironmentContainer::__copy__(EnvironmentContainer& self, const EnvironmentContainer& original);
  {
    left = right;
  }
  
}

