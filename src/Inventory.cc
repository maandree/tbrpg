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
    this->class_inheritance.push_back(27);
    this->left_hand = std::vector<Weapon*>(1);
    this->right_hand = nullptr;
    this->quiver = std::vector<Ammunition*>(3);
    this->quick_items = std::vector<QuickItem*>(3);
    this->headgear = nullptr;
    this->amulet = nullptr;
    this->rings = std::vector<Ring*>(2);
    this->body = nullptr;
    this->gauntlets = nullptr;
    this->girdle = nullptr;
    this->boots = nullptr;
    this->cloak = nullptr;
    this->personal = std::vector<Item*>(16);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(const Inventory& original) : Object(original)
  {
    __copy__(*this, original);
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory& original) : Object(original)
  {
    __copy__(*this, original);
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory&& original) : Object(original)
  {
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
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Inventory::fork() const
  {
    return (Object*)(new Inventory(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Inventory::~Inventory()
  {
    __delete__();
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Inventory& Inventory::operator =(const Inventory& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    __delete__();
    __copy__(*this, original);
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
    Object::__copy__((Object&)*this, (Object&)original);
    __delete__();
    __copy__(*this, original);
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
    std::swap((Object&)*this, (Object&)original);
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
    self.left_hand = std::vector<Weapon*>(original.left_hand.size());
    self.quiver = std::vector<Ammunition*>(original.quiver.size());
    self.quick_items = std::vector<QuickItem*>(original.quick_items.size());
    self.rings = std::vector<Ring*>(original.rings.size());
    self.personal = std::vector<Item*>(original.personal.size());
    
    #ifdef DELETE_INVENTORY
      #define __copy(slot, T)  \
	self.slot = original.slot == nullptr ? nullptr : (T*)(original.slot->fork());
    #else
      #define __copy(slot, T)								\
        {										\
	  self.slot = original.slot == nullptr ? nullptr : (T*)(original.slot->fork());	\
	  if (self.slot != nullptr)							\
	    cleaner::getInstance().enqueueDelete(self.slot);				\
	}//
    #endif
    
    __copy(right_hand, RightHandItem);
    __copy(headgear, Headgear);
    __copy(amulet, Amulet);
    __copy(body, BodyArmour);
    __copy(gauntlets, Gauntlets);
    __copy(girdle, Girdle);
    __copy(boots, Boots);
    __copy(cloak, Cloak);
    
    for (size_t i = 0, n = self.left_hand.size(); i < n; i++)
      __copy(left_hand[i], Weapon);
    for (size_t i = 0, n = self.quiver.size(); i < n; i++)
      __copy(quiver[i], Ammunition);
    for (size_t i = 0, n = self.quick_items.size(); i < n; i++)
      __copy(quick_items[i], QuickItem);
    for (size_t i = 0, n = self.rings.size(); i < n; i++)
      __copy(rings[i], Ring);
    for (size_t i = 0, n = self.personal.size(); i < n; i++)
      __copy(personal[i], Item);
  }
  
  /**
   * Internal cleaning
   */
  void Inventory::__delete__()
  {
    #ifdef DELETE_INVENTORY
    
    #define __delete(slot)		\
      if (this->slot != nullptr)	\
	{				\
	  delete this->slot;		\
	  this->slot = nullptr;		\
	}
    
    #define ___delete(slots)					\
      for (size_t i = 0, n = this->slots.size(); i < n; i++)	\
        __delete(slots[i])
    
    ___delete(left_hand)
    __delete(right_hand)
    ___delete(quiver)
    ___delete(quick_items)
    __delete(headgear)
    __delete(amulet)
    ___delete(rings)
    __delete(body)
    __delete(gauntlets)
    __delete(girdle)
    __delete(boots)
    __delete(cloak)
    ___delete(personal)
    
    #undef __delete
    #undef ___delete
    
    #endif
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Inventory::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<std::vector<Weapon*>>()(this->left_hand);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<RightHandItem*>()(this->right_hand);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<std::vector<Ammunition*>>()(this->quiver);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<std::vector<QuickItem*>>()(this->quick_items);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<Headgear*>()(this->headgear);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<Amulet*>()(this->amulet);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<std::vector<Ring*>>()(this->rings);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<BodyArmour*>()(this->body);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<Gauntlets*>()(this->gauntlets);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Girdle*>()(this->girdle);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<Boots*>()(this->boots);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<Cloak*>()(this->cloak);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<std::vector<Item*>>()(this->personal);
    return rc;
  }
  
}

