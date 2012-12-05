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
#include "Container.hpp"


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
  Container::Container() : Item()
  {
    this->name = "container";
    ////TODO implement constructor
    //this->contains = nullptr;
    //this->contain_limit = 0;
    //this->weight_modifier = 0;
    //this->can_contain = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(const Container& original) : Item(original)
  {
    (void) original;
    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(Container& original) : Item(original)
  {
    (void) original;
    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Container::Container(Container&& original) : Item(original)
  {
    (void) original;
    std::swap(this->contains, original.contains);
    std::swap(this->contain_limit, original.contain_limit);
    std::swap(this->weight_modifier, original.weight_modifier);
    std::swap(this->can_contain, original.can_contain);
  }
  
  
  
  /**
   * Destructor
   */
  Container::~Container()
  {
    ////TODO implement destructor
    //delete this->contains;
    //delete this->can_contain;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Container& Container::operator =(const Container& original)
  {
    (void) original;
    Item::__copy__((Item&)*this, (Item&)original);    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Container& Container::operator =(Container& original)
  {
    (void) original;
    Item::__copy__((Item&)*this, (Item&)original);    this->contains = original.contains;
    this->contain_limit = original.contain_limit;
    this->weight_modifier = original.weight_modifier;
    this->can_contain = original.can_contain;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Container& Container::operator =(Container&& original)
  {
    (void) original;
    std::swap((Item&)*this, (Item&)original);    std::swap(this->contains, original.contains);
    std::swap(this->contain_limit, original.contain_limit);
    std::swap(this->weight_modifier, original.weight_modifier);
    std::swap(this->can_contain, original.can_contain);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Container::operator ==(const Container& other) const
  {
    return this == &other;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Container::__copy__(Container& self, const Container& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Container::hash() const
  {
    return (size_t)this;
  }
  
}

