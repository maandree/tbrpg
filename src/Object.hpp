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
#ifndef __GUARD_OBJECT_HPP__
#define __GUARD_OBJECT_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "hash.hpp"


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
   * Master super class
   */
  class Object
  {
  private:
    /**
     * The actual instance of this object
     */
    void* actual_instance;
    
  protected:
    /**
     * Interface inheritance vector
     */
    std::vector<std::string> interface_inheritance;
    
    /**
     * Class inheritance vector
     */
    std::vector<short> class_inheritance;
    
  public:
    /**
     * Event handling function
     * 
     * @param  Object*      The invoked object
     * @param  std::string  The event name
     * @param  void*        The event arguments
     */
    void (*event_handler)(Object*, const std::string&, void*);
    
    
    
    /**
     * Construction
     */
    Object();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Object(const Object& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    Object(Object& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    Object(Object&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~Object();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Object& operator =(const Object& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Object& operator =(Object& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Object& operator =(Object&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const Object& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const Object& other) const;
    
    
    /**
     * 'Instance of' evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the left comparand is an instance of the right comparand's class
     */
    bool operator >=(const Object& other) const;
    
    /**
     * Reversed 'instance of' evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the right comparand is an instance of the left comparand's class
     */
    bool operator <=(const Object& other) const;
    
    /**
     * Checks whether the class implements a specific interface
     * 
     * @param   interface  The interface
     * @return             Whether the class implements a specific interface
     */
    bool implements(const std::string& interface) const;
    
    
    /**
     * Gets the actual instance of this object
     * 
     * @return  The actual instance of this object
     */
    void* getActual() const;
    
    
    /**
     * Invoked on a custom event
     * 
     * @param  action  The action name
     * @param  args    The action parameters
     */
    virtual void event(const std::string& action, void* args);
    
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(Object& self, const Object& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
    
  private:
    /**
     * NoOP event handler
     * 
     * @param  self   The invoked object
     * @param  ebent  The event name
     * @param  args   The event arguments
     */
    static void noop_event(Object* self, const std::string& event, void* args);
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::Object>
  {
  public:
    size_t operator()(const tbrpg::Object& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::Object*>
  {
  public:
    size_t operator()(tbrpg::Object* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_OBJECT_HPP__

