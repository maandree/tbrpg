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
#ifndef __GUARD_ACTIONSLOT_HPP__
#define __GUARD_ACTIONSLOT_HPP__


namespace tbrpg
{
  /**
   * Action slot typename
   */
  typedef char ActionSlot;
  
  
  
  /**
   * Action slot: Quick weapon
   */
  ActionSlot QUICK_WEAPON = 0;
  
  /**
   * Action slot: Quick spell
   */
  ActionSlot QUICK_SPELL = 1;
  
  /**
   * Action slot: Turn undead
   */
  ActionSlot TURN_UNDEAD = 2;
  
  /**
   * Action slot: Bard song
   */
  ActionSlot BARD_SONG = 3;
  
  /**
   * Action slot: Find traps
   */
  ActionSlot FIND_TRAPS = 4;
  
  /**
   * Action slot: Thieving
   */
  ActionSlot THIEVING = 5;
  
  /**
   * Action slot: Stealth
   */
  ActionSlot STEALTH = 6;
  
  /**
   * Action slot: Stealth
   */
  ActionSlot CAST_SPELL = 6;
  
}


#endif//__GUARD_ACTIONSLOT_HPP__
