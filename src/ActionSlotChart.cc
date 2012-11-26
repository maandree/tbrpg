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
#include "ActionSlotChart.hpp"


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
  ActionSlotChart::ActionSlotChart()
  {
    //TODO implement constructor
    //name = nullptr;
    //description = nullptr;
    //armour_class = nullptr;
    //weight = nullptr;
    //identified = false;
    //lore_value = nullptr;
    //stuck = false;
    //cursed = false;
    //quantity = nullptr;
    //quantity_limit = nullptr;
    //unit_value = nullptr;
    //bonuses = nullptr;
    //armour_class_modifiers = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(const ActionSlotChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->armour_class = original.armour_class;
    this->weight = original.weight;
    this->identified = original.identified;
    this->lore_value = original.lore_value;
    this->stuck = original.stuck;
    this->cursed = original.cursed;
    this->quantity = original.quantity;
    this->quantity_limit = original.quantity_limit;
    this->unit_value = original.unit_value;
    this->bonuses = original.bonuses;
    this->armour_class_modifiers = original.armour_class_modifiers;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(ActionSlotChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->armour_class = original.armour_class;
    this->weight = original.weight;
    this->identified = original.identified;
    this->lore_value = original.lore_value;
    this->stuck = original.stuck;
    this->cursed = original.cursed;
    this->quantity = original.quantity;
    this->quantity_limit = original.quantity_limit;
    this->unit_value = original.unit_value;
    this->bonuses = original.bonuses;
    this->armour_class_modifiers = original.armour_class_modifiers;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ActionSlotChart::ActionSlotChart(ActionSlotChart&& original)
  {
    std::move(this->name, original.name);
    std::move(this->description, original.description);
    std::move(this->armour_class, original.armour_class);
    std::move(this->weight, original.weight);
    std::swap(this->identified, original.identified);
    std::move(this->lore_value, original.lore_value);
    std::swap(this->stuck, original.stuck);
    std::swap(this->cursed, original.cursed);
    std::move(this->quantity, original.quantity);
    std::move(this->quantity_limit, original.quantity_limit);
    std::move(this->unit_value, original.unit_value);
    std::move(this->bonuses, original.bonuses);
    std::move(this->armour_class_modifiers, original.armour_class_modifiers);
  }
  
  
  
  /**
   * Destructor
   */
  ActionSlotChart::~ActionSlotChart()
  {
    //TODO implement destructor
    //delete name;
    //delete description;
    //delete armour_class;
    //delete weight;
    //delete lore_value;
    //delete quantity;
    //delete quantity_limit;
    //delete unit_value;
    //delete bonuses;
    //delete armour_class_modifiers;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(const ActionSlotChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->armour_class = original.armour_class;
    this->weight = original.weight;
    this->identified = original.identified;
    this->lore_value = original.lore_value;
    this->stuck = original.stuck;
    this->cursed = original.cursed;
    this->quantity = original.quantity;
    this->quantity_limit = original.quantity_limit;
    this->unit_value = original.unit_value;
    this->bonuses = original.bonuses;
    this->armour_class_modifiers = original.armour_class_modifiers;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(ActionSlotChart& original)
  {
    this->name = original.name;
    this->description = original.description;
    this->armour_class = original.armour_class;
    this->weight = original.weight;
    this->identified = original.identified;
    this->lore_value = original.lore_value;
    this->stuck = original.stuck;
    this->cursed = original.cursed;
    this->quantity = original.quantity;
    this->quantity_limit = original.quantity_limit;
    this->unit_value = original.unit_value;
    this->bonuses = original.bonuses;
    this->armour_class_modifiers = original.armour_class_modifiers;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ActionSlotChart& ActionSlotChart::operator =(ActionSlotChart&& original)
  {
    std::move(this->name, original.name);
    std::move(this->description, original.description);
    std::move(this->armour_class, original.armour_class);
    std::move(this->weight, original.weight);
    std::swap(this->identified, original.identified);
    std::move(this->lore_value, original.lore_value);
    std::swap(this->stuck, original.stuck);
    std::swap(this->cursed, original.cursed);
    std::move(this->quantity, original.quantity);
    std::move(this->quantity_limit, original.quantity_limit);
    std::move(this->unit_value, original.unit_value);
    std::move(this->bonuses, original.bonuses);
    std::move(this->armour_class_modifiers, original.armour_class_modifiers);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void ActionSlotChart::__copy__(ActionSlotChart& self, const ActionSlotChart& original);
  {
    left = right;
  }
  
}

