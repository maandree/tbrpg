// -*- mode: c++, encoding: utf-8 -*-
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
#ifndef __GUARD_BASICSENARIO_HPP__
#define __GUARD_BASICSENARIO_HPP__


#include "Senario.hpp"
#include "pager.hpp"
#include "prompter.hpp"
#include "cleaner.hpp"
#include "Town.hpp"
#include "House.hpp"
#include "Wilderness.hpp"
#include "Gold.hpp"
#include "Door.hpp"
#include "Store.hpp"

#include "ShortSword.hpp"
#include "LongSword.hpp"
#include "Bullet.hpp"
#include "Sling.hpp"
#include "ChainMail.hpp"
#include "Helmet.hpp"
#include "Key.hpp"


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
   * A basic game senario
   */
  class BasicSenario : public Senario
  {
  public:
    /**
     * Constructor
     */
    BasicSenario();
    
    /**
     * Destructor
     */
    ~BasicSenario();
    
    
    
    /**
     * This is invoked when the senario starts.
     * The prologue, and perhaps a short tutorial,
     * should be displayed.
     */
    virtual void start();
    
    
    
    /**
     * Gets the name of the game senario
     * 
     * @return  The name of the game senario
     */
    static std::string getTitle();
    
  };
}


#endif//__GUARD_BASICSENARIO_HPP__

