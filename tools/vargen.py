#!/usr/bin/env python3
# -*- mode: python, encoding: utf-8 -*-
'''
tbrpg – Text based roll playing game

Copyright © 2012  Mattias Andrée (maandree@kth.se)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
'''
import sys
import os

copyNotice = ''
lineptr = 0
lines = [line.replace('\n', '') for line in sys.stdin.readlines()]

while (len(lines[lineptr]) > 1) and (lines[lineptr][1] == '*'):
    lineptr++

copyNotice = '\n'.join(line[:lineptr])
lines = lines[lineptr:] + ['EOF']
lineptr = 0

classLine = None
varLines = None

for line in lines:
    if len(line) == 0:
        continue
    if line[0] == '\t':
        varLines.append(line[1:])
    else:
        DO-STUFF
        classLine = line
        varLines = []





"""
namespace tbrpg
{
  /**
   * Item base class
   */
  class Item
  {
  protected:
    /**
     * The item's weight in grams
     */
    int weight;
    
    /**
     * Is the item stuck in its current position?
     */
    bool stuck;
    
    /**
     * The item's monetary value
     */
    int value;
    
    /**
     * Is the item identified?
     */
    bool identified;
    
    /**
     * The lore needed to be able to identify the item without magic
     */
    int identifyLore;
    
    /**
     * Is the item cursed?
     */
    bool cursed;
    
    
  public:
    /**
     * Constructor
     */
    Item();
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Item(const Item& original);
    
    /**
     * Copy constructor
     *
     * @param  original  The object to clone
     */
    Item(Item& original);
    
    /**
     * Move constructor
     *
     * @param  original  The object to clone
     */
    Item(Item&& original);
    
    
    
    /**
     * Destructor
     */
    virtual ~Item();
    
    
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Item& operator =(const Item& original);
    
    /**
     * Assignment operator
     * 
     * @param   original  The reference object
     * @return            The invoked object
     */
    virtual Item& operator =(Item& original);
    
    /**
     * Move operator
     * 
     * @param   original  The moved object, its resourced will be moved
     * @return            The invoked object
     */
    virtual Item& operator =(Item&& original);
    
    
    
    /**
     * Get the weight of the item
     * 
     * @return  The weight of the item
     */
    virtual int getWeight() const;
    
    /**
     * Is the item stuck in its position
     * 
     * @return  Whether the item is stuck in its position
     */
    virtual bool isStuck() const;
    
    /**
     * Get the item's monetary value
     * 
     * @return  The item's monetary value
     */
    virtual int getValue() const;
    
    /**
     * Is the item identified?
     * 
     * @return  Wether the item identified
     */
    virtual bool isIdentified() const;
    
    /**
     * Get the lore needed to be able to identify the item without magic
     * 
     * @return  The lore needed to be able to identify the item without magic
     */
    virtual int getIdentifyLore() const;
    
    /**
     * Set the item as identified
     */
    virtual void identify();
    
    /**
     * Is the item cursed?
     * 
     * @return  Whether the item is cursed
     */
    virtual bool isCursed() const;
    
  };
}


#endif//__ITEM__

"""
