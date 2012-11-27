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
#include "Item.hpp"


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
  Item::Item()
  {
    ////TODO implement constructor
    //this->name = nullptr;
    //this->description = nullptr;
    //this->armour_class = 0;
    //this->weight = 0;
    //this->identified = false;
    //this->lore_value = 0;
    //this->stuck = false;
    //this->cursed = false;
    //this->quantity = 0;
    //this->quantity_limit = 0;
    //this->unit_value = 0;
    //this->bonuses = nullptr;
    //this->armour_class_modifiers = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Item::Item(const Item& original)
  {
    (void) original;
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
  Item::Item(Item& original)
  {
    (void) original;
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
  Item::Item(Item&& original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->description, original.description);
    std::swap(this->armour_class, original.armour_class);
    std::swap(this->weight, original.weight);
    std::swap(this->identified, original.identified);
    std::swap(this->lore_value, original.lore_value);
    std::swap(this->stuck, original.stuck);
    std::swap(this->cursed, original.cursed);
    std::swap(this->quantity, original.quantity);
    std::swap(this->quantity_limit, original.quantity_limit);
    std::swap(this->unit_value, original.unit_value);
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->armour_class_modifiers, original.armour_class_modifiers);
  }
  
  
  
  /**
   * Destructor
   */
  Item::~Item()
  {
    ////TODO implement destructor
    //delete name;
    //delete description;
    //delete bonuses;
    //delete armour_class_modifiers;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Item& Item::operator =(const Item& original)
  {
    (void) original;
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
  Item& Item::operator =(Item& original)
  {
    (void) original;
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
  Item& Item::operator =(Item&& original)
  {
    (void) original;
    std::swap(this->name, original.name);
    std::swap(this->description, original.description);
    std::swap(this->armour_class, original.armour_class);
    std::swap(this->weight, original.weight);
    std::swap(this->identified, original.identified);
    std::swap(this->lore_value, original.lore_value);
    std::swap(this->stuck, original.stuck);
    std::swap(this->cursed, original.cursed);
    std::swap(this->quantity, original.quantity);
    std::swap(this->quantity_limit, original.quantity_limit);
    std::swap(this->unit_value, original.unit_value);
    std::swap(this->bonuses, original.bonuses);
    std::swap(this->armour_class_modifiers, original.armour_class_modifiers);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Item::__copy__(Item& self, const Item& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Item::hash() const
  {
    return (size_t)this;
  }
  
}

