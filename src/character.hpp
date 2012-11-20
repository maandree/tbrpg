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
#ifndef __CHARACTER__
#define __CHARACTER__


#include <stdlib.h>
#include <algorithm>
#include <string>


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
   * Character class
   */
  class Character
  {
  public:
    /**
     * Gender: female
     */
    const static bool FEMALE = false;
    
    /**
     * Gender: male
     */
    const static bool MALE = true;
    
    
    /**
     * Alignment: lawful good
     */
    const static char LAWFUL_GOOD = 8;
    
    /**
     * Alignment: neutral good
     */
    const static char NEUTRAL_GOOD = 7;
    
    /**
     * Alignment: chaotic good
     */
    const static char CHAOTIC_GOOD = 6;
    
    /**
     * Alignment: lawful neutral
     */
    const static char LAWFUL_NEUTRAL = 5;
    
    /**
     * Alignment: neutral
     */
    const static char TRUE_NEUTRAL = 4;
    
    /**
     * Alignment: chaotic neutral
     */
    const static char CHAOTIC_NEUTRAL = 3;
    
    /**
     * Alignment: lawful evil
     */
    const static char LAWFUL_EVIL = 2;
    
    /**
     * Alignment: neutral evil
     */
    const static char NEUTRAL_EVIL = 1;
    
    /**
     * Alignment: chaotic evil
     */
    const static char CHAOTIC_EVIL = 0;
    
    
    
  protected:
    /**
     * The gender of the character
     */
    bool gender;
    
    /**
     * The name of the character
     */
    std::string name;
    
    /**
     * Optional image, no bigger than 80x80 pixels
     */
    std::string image;
    
    /**
     * ANSI colour value used on the character name
     */
    char colour;
    
    /**
     * Character alignment
     */
    char alignment;
    
    /**
     * The characters reputation
     */
    char reputation;
    
    /**
     * The character's strength
     */
    char strength;
    
    /**
     * The character's constitution
     */
    char constitution;
    
    /**
     * The character's dexterity
     */
    char dexterity;
    
    /**
     * The character's intelligence
     */
    char intelligence;
    
    /**
     * The character's wisdom
     */
    char wisdom;
    
    /**
     * The character's charisma
     */
    char charisma;
    
    
    
  public:
    /**
     * Constructor
     */
    Character();
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Character(const Character& original);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Character(Character& original);
    
    /**
     * Move constructor
     *
     * @param  original  The object to clone
     */
    Character(Character&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Character();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(const Character& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Character& operator =(Character& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Character& operator =(Character&& original);
    
  };
}


#endif//__ITEM__

