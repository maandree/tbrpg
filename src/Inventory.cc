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
#include "Inventory.hpp"


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
  Inventory::Inventory() : Object()
  {
    this->class_inheritance.push_back(23);
    ////TODO implement constructor
    //this->left_hand = nullptr;
    //this->right_hand = nullptr;
    //this->quiver = nullptr;
    //this->quick_items = nullptr;
    //this->headgear = nullptr;
    //this->amulet = nullptr;
    //this->rings = nullptr;
    //this->body = nullptr;
    //this->gauntlets = nullptr;
    //this->girdle = nullptr;
    //this->boots = nullptr;
    //this->cloak = nullptr;
    //this->personal = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(const Inventory& original) : Object(original)
  {
    (void) original;
    this->left_hand = original.left_hand;
    this->right_hand = original.right_hand;
    this->quiver = original.quiver;
    this->quick_items = original.quick_items;
    this->headgear = original.headgear;
    this->amulet = original.amulet;
    this->rings = original.rings;
    this->body = original.body;
    this->gauntlets = original.gauntlets;
    this->girdle = original.girdle;
    this->boots = original.boots;
    this->cloak = original.cloak;
    this->personal = original.personal;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory& original) : Object(original)
  {
    (void) original;
    this->left_hand = original.left_hand;
    this->right_hand = original.right_hand;
    this->quiver = original.quiver;
    this->quick_items = original.quick_items;
    this->headgear = original.headgear;
    this->amulet = original.amulet;
    this->rings = original.rings;
    this->body = original.body;
    this->gauntlets = original.gauntlets;
    this->girdle = original.girdle;
    this->boots = original.boots;
    this->cloak = original.cloak;
    this->personal = original.personal;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory&& original) : Object(original)
  {
    (void) original;
    std::swap(this->left_hand, original.left_hand);
    std::swap(this->right_hand, original.right_hand);
    std::swap(this->quiver, original.quiver);
    std::swap(this->quick_items, original.quick_items);
    std::swap(this->headgear, original.headgear);
    std::swap(this->amulet, original.amulet);
    std::swap(this->rings, original.rings);
    std::swap(this->body, original.body);
    std::swap(this->gauntlets, original.gauntlets);
    std::swap(this->girdle, original.girdle);
    std::swap(this->boots, original.boots);
    std::swap(this->cloak, original.cloak);
    std::swap(this->personal, original.personal);
  }
  
  
  
  /**
   * Destructor
   */
  Inventory::~Inventory()
  {
    ////TODO implement destructor
    //delete this->left_hand;
    //delete this->right_hand;
    //delete this->quiver;
    //delete this->quick_items;
    //delete this->headgear;
    //delete this->amulet;
    //delete this->rings;
    //delete this->body;
    //delete this->gauntlets;
    //delete this->girdle;
    //delete this->boots;
    //delete this->cloak;
    //delete this->personal;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(const Inventory& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->left_hand = original.left_hand;
    this->right_hand = original.right_hand;
    this->quiver = original.quiver;
    this->quick_items = original.quick_items;
    this->headgear = original.headgear;
    this->amulet = original.amulet;
    this->rings = original.rings;
    this->body = original.body;
    this->gauntlets = original.gauntlets;
    this->girdle = original.girdle;
    this->boots = original.boots;
    this->cloak = original.cloak;
    this->personal = original.personal;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(Inventory& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->left_hand = original.left_hand;
    this->right_hand = original.right_hand;
    this->quiver = original.quiver;
    this->quick_items = original.quick_items;
    this->headgear = original.headgear;
    this->amulet = original.amulet;
    this->rings = original.rings;
    this->body = original.body;
    this->gauntlets = original.gauntlets;
    this->girdle = original.girdle;
    this->boots = original.boots;
    this->cloak = original.cloak;
    this->personal = original.personal;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(Inventory&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->left_hand, original.left_hand);
    std::swap(this->right_hand, original.right_hand);
    std::swap(this->quiver, original.quiver);
    std::swap(this->quick_items, original.quick_items);
    std::swap(this->headgear, original.headgear);
    std::swap(this->amulet, original.amulet);
    std::swap(this->rings, original.rings);
    std::swap(this->body, original.body);
    std::swap(this->gauntlets, original.gauntlets);
    std::swap(this->girdle, original.girdle);
    std::swap(this->boots, original.boots);
    std::swap(this->cloak, original.cloak);
    std::swap(this->personal, original.personal);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Inventory::operator ==(const Inventory& other) const
  {
    if (this->left_hand != other.left_hand)  return false;
    if (this->right_hand != other.right_hand)  return false;
    if (this->quiver != other.quiver)  return false;
    if (this->quick_items != other.quick_items)  return false;
    if (this->headgear != other.headgear)  return false;
    if (this->amulet != other.amulet)  return false;
    if (this->rings != other.rings)  return false;
    if (this->body != other.body)  return false;
    if (this->gauntlets != other.gauntlets)  return false;
    if (this->girdle != other.girdle)  return false;
    if (this->boots != other.boots)  return false;
    if (this->cloak != other.cloak)  return false;
    if (this->personal != other.personal)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Inventory::operator !=(const Inventory& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Inventory::__copy__(Inventory& self, const Inventory& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Inventory::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<std::vector<Weapon>>()(left_hand);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<RightHandItem>()(right_hand);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<std::vector<Ammunition>>()(quiver);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<std::vector<QuickItem>>()(quick_items);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<Headgear>()(headgear);
    rc = (rc * 13) ^ (rc >> (sizeof(size_t) << 2) * 13);
    rc += std::hash<Amulet>()(amulet);
    rc = (rc * 17) ^ (rc >> (sizeof(size_t) << 2) * 17);
    rc += std::hash<std::vector<Ring>>()(rings);
    rc = (rc * 19) ^ (rc >> (sizeof(size_t) << 2) * 19);
    rc += std::hash<BodyArmour>()(body);
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<Gauntlets>()(gauntlets);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<Girdle>()(girdle);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<Boots>()(boots);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<Cloak>()(cloak);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<std::vector<Item>>()(personal);
    return rc;
  }
  
}

