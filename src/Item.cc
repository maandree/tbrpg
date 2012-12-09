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
  Item::Item() : Object()
  {
    this->class_inheritance.push_back(18);
    this->name = "some weird item";
    this->description = "You have no idea what this is…";
    this->armour_class = 0x7FFFffff;
    this->weight = 0;
    this->identified = true;
    this->lore_value = 0x7FFFffff;
    this->stuck = false;
    this->cursed = false;
    this->quantity = 1;
    this->quantity_limit = 1;
    this->unit_value = -1;
    this->bonuses = AbilityBonus();
    this->armour_class_modifiers = std::unordered_map<DamageType, int>();
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Item::Item(const Item& original) : Object(original)
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
  Item::Item(Item& original) : Object(original)
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
  Item::Item(Item&& original) : Object(original)
  {
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
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Item& Item::operator =(const Item& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
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
    Object::__copy__((Object&)*this, (Object&)original);
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
    std::swap((Object&)*this, (Object&)original);
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
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Item::operator ==(const Item& other) const
  {
    if (this->name != other.name)  return false;
    if (this->description != other.description)  return false;
    if (this->armour_class != other.armour_class)  return false;
    if (this->weight != other.weight)  return false;
    if (this->identified != other.identified)  return false;
    if (this->lore_value != other.lore_value)  return false;
    if (this->stuck != other.stuck)  return false;
    if (this->cursed != other.cursed)  return false;
    if (this->quantity != other.quantity)  return false;
    if (this->quantity_limit != other.quantity_limit)  return false;
    if (this->unit_value != other.unit_value)  return false;
    if (this->bonuses != other.bonuses)  return false;
    if (this->armour_class_modifiers != other.armour_class_modifiers)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Item::operator !=(const Item& other) const
  {
    return (*this == other) == false;
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
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::string>()(this->name);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<std::string>()(this->description);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->armour_class);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<int>()(this->weight);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<bool>()(this->identified);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<int>()(this->lore_value);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<bool>()(this->stuck);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<bool>()(this->cursed);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<int>()(this->quantity);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<int>()(this->quantity_limit);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<int>()(this->unit_value);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<AbilityBonus>()(this->bonuses);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::unordered_map<DamageType, int>>()(this->armour_class_modifiers);
    return rc;
  }
  
}

