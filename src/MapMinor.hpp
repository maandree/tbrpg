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
#ifndef __GUARD_MAPMINOR_HPP__
#define __GUARD_MAPMINOR_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "_MapMinor.hpp"



#include "hash.hpp"
#include "Road.hpp"
#include "Entrance.hpp"
#include "Item.hpp"
#include "Creature.hpp"
#include "MapMajor.hpp"
#include "RestInterruption.hpp"


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
   * Map area
   */
  class MapMinor: public _MapMinor
  {
  public:
    /**
     * Description of the area
     */
    std::string description;
    
    /**
     * Whether you may rest in the area without renting a room
     */
    bool may_rest;
    
    /**
     * The radius of the area, in metres, the party starts at origo
     */
    float area;
    
    /**
     * Roads to other major areas in the area
     */
    std::vector<Road> roads;
    
    /**
     * Entrance to other areas in the area
     */
    std::vector<Entrance> connections;
    
    /**
     * Items in the area
     */
    std::vector<Item> items;
    
    /**
     * Creatures in the area
     */
    std::vector<Creature> creatures;
    
    /**
     * Which major area to which  the area belongs
     */
    MapMajor is_in;
    
    /**
     * Possible rest interruptions
     */
    std::vector<RestInterruption> interruptions;
    
    
    
    /**
     * Construction
     */
    MapMinor();
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(const MapMinor& original);
    
    /**
     * Copy constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(MapMinor& original);
    
    /**
     * Move constructor
     * 
     * @param  original  The object to clone
     */
    MapMinor(MapMinor&& original);
    
    /**
     * Fork the object
     * 
     * @return  A fork of the object
     */
    virtual Object* fork() const;
    
    
    
    /**
     * Destructor
     */
    virtual ~MapMinor();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MapMinor& operator =(const MapMinor& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual MapMinor& operator =(MapMinor& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual MapMinor& operator =(MapMinor&& original);
    
    
    /**
     * Equality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are equal
     */
    virtual bool operator ==(const MapMinor& other) const;
    
    /**
     * Inequality evaluator
     * 
     * @param   other  The other comparand
     * @return         Whether the instances are not equal
     */
    virtual bool operator !=(const MapMinor& other) const;
    
    
  protected:
    /**
     * Copy method
     * 
     * @param  self      The object to modify
     * @param  original  The reference object
     */
    static void __copy__(MapMinor& self, const MapMinor& original);
    
    
  public:
    /**
     * Hash method
     * 
     * @return  The object's hash code
     */
    size_t hash() const;
    
  };
}

namespace std
{
  template<>
  class hash<tbrpg::MapMinor>
  {
  public:
    size_t operator()(const tbrpg::MapMinor& elem) const
    {
      return elem.hash();
    }
  };
  
  template<>
  class hash<tbrpg::MapMinor*>
  {
  public:
    size_t operator()(tbrpg::MapMinor* elem) const
    {
      return elem == nullptr ? 0 : elem->hash();
    }
  };
}


#endif//__GUARD_MAPMINOR_HPP__

