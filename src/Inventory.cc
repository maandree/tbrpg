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
  Inventory::Inventory()
  {
    ////TODO implement constructor
    //this->left_hand = nullptr;
    //this->right_hand = nullptr;
    //this->quiver = nullptr;
    //this->quick_items = nullptr;
    //this->headgear = nullptr;
    //this->amulett = nullptr;
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
  Inventory::Inventory(const Inventory& original)
  {
    (void) original;
    //this->left_hand = original.left_hand;
    //this->right_hand = original.right_hand;
    //this->quiver = original.quiver;
    //this->quick_items = original.quick_items;
    //this->headgear = original.headgear;
    //this->amulett = original.amulett;
    //this->rings = original.rings;
    //this->body = original.body;
    //this->gauntlets = original.gauntlets;
    //this->girdle = original.girdle;
    //this->boots = original.boots;
    //this->cloak = original.cloak;
    //this->personal = original.personal;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory& original)
  {
    (void) original;
    //this->left_hand = original.left_hand;
    //this->right_hand = original.right_hand;
    //this->quiver = original.quiver;
    //this->quick_items = original.quick_items;
    //this->headgear = original.headgear;
    //this->amulett = original.amulett;
    //this->rings = original.rings;
    //this->body = original.body;
    //this->gauntlets = original.gauntlets;
    //this->girdle = original.girdle;
    //this->boots = original.boots;
    //this->cloak = original.cloak;
    //this->personal = original.personal;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Inventory::Inventory(Inventory&& original)
  {
    (void) original;
    ////std::move(this->left_hand, original.left_hand);
    ////std::move(this->right_hand, original.right_hand);
    ////std::move(this->quiver, original.quiver);
    ////std::move(this->quick_items, original.quick_items);
    ////std::move(this->headgear, original.headgear);
    ////std::move(this->amulett, original.amulett);
    ////std::move(this->rings, original.rings);
    ////std::move(this->body, original.body);
    ////std::move(this->gauntlets, original.gauntlets);
    ////std::move(this->girdle, original.girdle);
    ////std::move(this->boots, original.boots);
    ////std::move(this->cloak, original.cloak);
    ////std::move(this->personal, original.personal);
  }
  
  
  
  /**
   * Destructor
   */
  Inventory::~Inventory()
  {
    ////TODO implement destructor
    //delete left_hand;
    //delete right_hand;
    //delete quiver;
    //delete quick_items;
    //delete headgear;
    //delete amulett;
    //delete rings;
    //delete body;
    //delete gauntlets;
    //delete girdle;
    //delete boots;
    //delete cloak;
    //delete personal;
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
    //this->left_hand = original.left_hand;
    //this->right_hand = original.right_hand;
    //this->quiver = original.quiver;
    //this->quick_items = original.quick_items;
    //this->headgear = original.headgear;
    //this->amulett = original.amulett;
    //this->rings = original.rings;
    //this->body = original.body;
    //this->gauntlets = original.gauntlets;
    //this->girdle = original.girdle;
    //this->boots = original.boots;
    //this->cloak = original.cloak;
    //this->personal = original.personal;
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
    //this->left_hand = original.left_hand;
    //this->right_hand = original.right_hand;
    //this->quiver = original.quiver;
    //this->quick_items = original.quick_items;
    //this->headgear = original.headgear;
    //this->amulett = original.amulett;
    //this->rings = original.rings;
    //this->body = original.body;
    //this->gauntlets = original.gauntlets;
    //this->girdle = original.girdle;
    //this->boots = original.boots;
    //this->cloak = original.cloak;
    //this->personal = original.personal;
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
    ////std::move(this->left_hand, original.left_hand);
    ////std::move(this->right_hand, original.right_hand);
    ////std::move(this->quiver, original.quiver);
    ////std::move(this->quick_items, original.quick_items);
    ////std::move(this->headgear, original.headgear);
    ////std::move(this->amulett, original.amulett);
    ////std::move(this->rings, original.rings);
    ////std::move(this->body, original.body);
    ////std::move(this->gauntlets, original.gauntlets);
    ////std::move(this->girdle, original.girdle);
    ////std::move(this->boots, original.boots);
    ////std::move(this->cloak, original.cloak);
    ////std::move(this->personal, original.personal);
    return *this;
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
    return (size_t)this;
  }
  
}

