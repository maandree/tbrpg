// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "Potion.hpp"


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
  Potion::Potion() : QuickItem()
  {
    this->class_inheritance.push_back(76);
    this->name = "potion";
    this->quantity_limit = 5;
    this->weight = 300;
    this->unit_value = 0;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Potion::Potion(const Potion& original) : QuickItem(original)
  {
    (void) original;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Potion::Potion(Potion& original) : QuickItem(original)
  {
    (void) original;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Potion::Potion(Potion&& original) : QuickItem(original)
  {
    (void) original;
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Potion::fork() const
  {
    return (Object*)(new Potion(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Potion::~Potion()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Potion& Potion::operator =(const Potion& original)
  {
    QuickItem::__copy__((QuickItem&)*this, (QuickItem&)original);
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Potion& Potion::operator =(Potion& original)
  {
    QuickItem::__copy__((QuickItem&)*this, (QuickItem&)original);
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Potion& Potion::operator =(Potion&& original)
  {
    std::swap((QuickItem&)*this, (QuickItem&)original);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Potion::operator ==(const Potion& other) const
  {
    if ((QuickItem&)(*this) != (QuickItem&)other)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Potion::operator !=(const Potion& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Potion::__copy__(Potion& self, const Potion& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Potion::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<QuickItem>()(*this);
    return rc;
  }
  
}

