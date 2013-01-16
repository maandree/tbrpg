// -*- mode: c++ , coding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "Object.hpp"


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
  Object::Object()
  {
    this->class_inheritance = std::vector<short>();
    this->class_inheritance.push_back(0);
    this->actual_instance = (void*)this;
    this->interface_inheritance = std::vector<std::string>();
    this->event_handler = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Object::Object(const Object& original)
  {
    this->class_inheritance = original.class_inheritance;
    this->actual_instance = original.actual_instance;
    this->event_handler = original.event_handler;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Object::Object(Object& original)
  {
    this->class_inheritance = original.class_inheritance;
    this->actual_instance = original.actual_instance;
    this->event_handler = original.event_handler;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Object::Object(Object&& original)
  {
    std::swap(this->class_inheritance, original.class_inheritance);
    std::swap(this->actual_instance, original.actual_instance);
    std::swap(this->event_handler, original.event_handler);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* Object::fork() const
  {
    return (Object*)(new Object(*this));
  }
  
  
  
  /**
   * Destructor
   */
  Object::~Object()
  {
    // do nothing
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Object& Object::operator =(const Object& original)
  {
    this->class_inheritance = original.class_inheritance;
    this->actual_instance = original.actual_instance;
    this->event_handler = original.event_handler;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Object& Object::operator =(Object& original)
  {
    this->class_inheritance = original.class_inheritance;
    this->actual_instance = original.actual_instance;
    this->event_handler = original.event_handler;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Object& Object::operator =(Object&& original)
  {
    std::swap(this->class_inheritance, original.class_inheritance);
    std::swap(this->actual_instance, original.actual_instance);
    std::swap(this->event_handler, original.event_handler);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool Object::operator ==(const Object& other) const
  {
    return this == &other;
  }
  
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool Object::operator !=(const Object& other) const
  {
    return (*this == other) == false;
  }
  
  
  /**
   * 'Instance of' evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the left comparand is an instance of the right comparand's class
   */
  bool Object::operator >=(const Object& other) const
  {
    if (this->class_inheritance.size() < other.class_inheritance.size())
      return false;
    
    for (size_t i = 0, n = other.class_inheritance.size(); i < n; i++)
      if (this->class_inheritance[i] != other.class_inheritance[i])
	return false;
    
    return true;
  }
  
  
  /**
   * Reversed 'instance of' evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the right comparand is an instance of the left comparand's class
   */
  bool Object::operator <=(const Object& other) const
  {
    return other >= *this;
  }
  
  
  /**
   * Checks whether the class implements a specific interface
   * 
   * @param   interface  The interface
   * @return             Whether the class implements a specific interface
   */
  bool Object::implements(const std::string& interface) const
  {
    for (const std::string& elem : this->interface_inheritance)
      if (elem == interface)
	return true;
    return false;
  }
  
  
  /**
   * Gets the actual instance of this object
   * 
   * @return  The actual instance of this object
   */
  void* Object::getActual() const
  {
    return this->actual_instance;
  }
  
  
  /**
   * Invoked on a custom event
   * 
   * @param  action  The action name
   * @param  args    The action parameters
   */
  void Object::event(const std::string& action, void* args)
  {
    if ((this->event_handler))
      (*(this->event_handler))(this, action, args);
  }
  
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Object::__copy__(Object& self, const Object& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Object::hash() const
  {
    return (size_t)this;
  }
  
}

