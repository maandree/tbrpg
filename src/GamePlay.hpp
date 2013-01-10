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
#ifndef __GUARD_GAMEPLAY_HPP__
#define __GUARD_GAMEPLAY_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "Senario.hpp"
#include "prompter.hpp"
#include "GameCharacter.hpp"
#include "Calculator.hpp"
#include "Dice.hpp"
#include "EnvironmentContainer.hpp"
#include "Door.hpp"
#include "ActionSlotChart.hpp"
#include "NPC.hpp"


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
   * Game play class
   */
  class GamePlay
  {
  protected:
    /**
     * The game senario
     */
    Senario* game;
    
    /**
     * The players
     */
    std::vector<GameCharacter*>* players;
    
    /**
     * The next in the game loop
     */
    char next_player;
    
    /**
     * The used last function
     */
    char (GamePlay::*last_function)();
    
    /**
     * The attack dice
     */
    Dice* attack_dice;
    
    /**
     * The attribute calculator
     */
    Calculator* calc;
    
    /**
     * Action slot chart
     */
    ActionSlotChart* slot_chart;
    
    
  public:
    /**
     * Construction
     * 
     * @param  senario  The game senario
     */
    GamePlay(Senario* senario = nullptr);
    
    /**
     * Destructor
     */
    virtual ~GamePlay();
    
    
    /**
     * Play the next round, it may be an AI's turn
     * 
     * @return  Whether there is a next turn
     */
    bool next();
    
    
  protected:
    /**
     * Gets whether the party is gathered
     * 
     * @return  Whether the party is gathered
     */
    bool gathered() const;
    
    
    /**
     * Action: quit
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_quit();
    
    /**
     * Action: wait one turn
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_wait();
    
    /**
     * Action: redo last action by any party member
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_redo();
    
    /**
     * Action: rest
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_rest();
    
    /**
     * Action: select ammunition to use from the quiver
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_quiver();
    
    /**
     * Action: select weapon to use from the quick weapons
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_weapon();
    
    /**
     * Action: attack
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_attack();
    
    /**
     * Action: cast non-quick spell
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_cast();
    
    /**
     * Action: talk
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_talk();
    
    /**
     * Action: list special usable abilities
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_specials();
    
    /**
     * Action: bash a lock
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_bash();
    
    /**
     * Action: pick a lock
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_pick_lock();
    
    /**
     * Action: disarm a trap
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_disarm();
    
    /**
     * Action: pick pocket
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_pick_pocket();
    
    /**
     * Action: turn on stealth mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_stealth();
    
    /**
     * Action: turn off stealth mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_stealth_off();
    
    /**
     * Action: turn on find traps mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_find_traps();
    
    /**
     * Action: turn off find traps mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_find_traps_off();
    
    /**
     * Action: turn on turn undead mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_turn_undead();
    
    /**
     * Action: turn off turn undead mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_turn_undead_off();
    
    /**
     * Action: turn on bard song mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_bard_song();
    
    /**
     * Action: turn off bard song mode
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_bard_song_off();
    
    /**
     * Action: examine inventory
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_inventory();
    
    /**
     * Action: examine party
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_party();
    
    /**
     * Action: examine world map
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_map();
    
    /**
     * Action: examine area
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_area();
    
    /**
     * Action: travel to another area
     *
     * @return  0 for stop playing, 1 for continue playing, 2 for one more time
     */
    char action_travel();
    
    
    /**
     * Find the distances to all map major
     * 
     * @param   start    The start minor area
     * @param   distmap  Map to fill with distances to majors
     * @param   where    Map major to map minor map
     * @return           Walk path mapping
     */
    std::unordered_map<MapMinor*, MapMinor*>* findDistances(MapMinor* start,
							    std::unordered_map<MapMajor*, int>& distmap,
							    std::unordered_map<MapMajor*, MapMinor*>* where) const;
    
    /**
     * Find the path to a area
     * 
     * @param  mapping  Walk path mapping
     * @param  end      The target minor area
     * @param  path     Vector to fill with the path
     */
    void findPath(const std::unordered_map<MapMinor*, MapMinor*>* mapping,
		  MapMinor* end, std::vector<Road*>& path) const;
    
    
  };
}


#endif//__GUARD_GAMEPLAY_HPP__

