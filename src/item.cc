// -*- mode: c++, encoding: utf-8 -*-
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
#include "item.hpp"


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
    this->weight = 0;
    this->stuck = false;
    this->value = 0;
    this->identified = true;
    this->identifyLore = 0;
    this->cursed = false;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Item::Item(const Item& original)
  {
    this->weight = original.weight;
    this->stuck = original.stuck;
    this->value = original.value;
    this->identified = original.identified;
    this->identifyLore = original.identifyLore;
    this->cursed = original.cursed;
  }
  
  /**
   * Copy constructor
   *
   * @param  original  The object to clone
   */
  Item::Item(Item& original)
  {
    this->weight = original.weight;
    this->stuck = original.stuck;
    this->value = original.value;
    this->identified = original.identified;
    this->identifyLore = original.identifyLore;
    this->cursed = original.cursed;
  }
    
  /**
   * Move constructor
   *
   * @param  original  The object to clone
   */
  Item::Item(Item&& original)
  {
    std::swap(this->weight, original.weight);
    std::swap(this->stuck, original.stuck);
    std::swap(this->value, original.value);
    std::swap(this->identified, original.identified);
    std::swap(this->identifyLore, original.identifyLore);
    std::swap(this->cursed, original.cursed);
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
    this->weight = original.weight;
    this->stuck = original.stuck;
    this->value = original.value;
    this->identified = original.identified;
    this->identifyLore = original.identifyLore;
    this->cursed = original.cursed;
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
    this->weight = original.weight;
    this->stuck = original.stuck;
    this->value = original.value;
    this->identified = original.identified;
    this->identifyLore = original.identifyLore;
    this->cursed = original.cursed;
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
    std::swap(this->weight, original.weight);
    std::swap(this->stuck, original.stuck);
    std::swap(this->value, original.value);
    std::swap(this->identified, original.identified);
    std::swap(this->identifyLore, original.identifyLore);
    std::swap(this->cursed, original.cursed);
    return *this;
  }
  
  
  
  /**
   * Get the weight of the item
   * 
   * @return  The weight of the item
   */
  int Item::getWeight() const
  {
    return this->weight;
  }
  
  /**
   * Is the item stuck in its position
   * 
   * @return  Whether the item is stuck in its position
   */
  bool Item::isStuck() const
  {
    return this->stuck;
  }
  
  /**
   * Get the item's monetary value
   * 
   * @return  The item's monetary value
   */
  int Item::getValue() const
  {
    return this->value;
  }
  
  /**
   * Is the item identified?
   * 
   * @return  Wether the item identified
   */
  bool Item::isIdentified() const
  {
    return this->identified;
  }
  
  /**
   * Get the lore needed to be able to identify the item without magic
   * 
   * @return  The lore needed to be able to identify the item without magic
   */
  int Item::getIdentifyLore() const
  {
    return this->identifyLore;
  }
  
  /**
   * Set the item as identified
   */
  void Item::identify()
  {
    this->identified = true;
  }
  
  /**
   * Is the item cursed?
   * 
   * @return  Whether the item is cursed
   */
  bool Item::isCursed() const
  {
    return this->cursed;
  }
  
}

