// -*- mode: c++, coding: utf-8 -*-
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
#include "GameCharacter.hpp"


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
  GameCharacter::GameCharacter() : Object()
  {
    this->class_inheritance.push_back(142);
    ////TODO implement constructor
    //this->turn_undead_on = false;
    //this->find_traps_on = false;
    //this->stealth_on = false;
    //this->bard_song_on = false;
    //this->self_interruptable = false;
    //this->damage_interruptable = false;
    //this->turns = 0;
    //this->weapon = 0;
    //this->quiver = 0;
    //this->action = nullptr;
    //this->character = nullptr;
    //this->area = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  GameCharacter::GameCharacter(const GameCharacter& original) : Object(original)
  {
    (void) original;
    this->turn_undead_on = original.turn_undead_on;
    this->find_traps_on = original.find_traps_on;
    this->stealth_on = original.stealth_on;
    this->bard_song_on = original.bard_song_on;
    this->self_interruptable = original.self_interruptable;
    this->damage_interruptable = original.damage_interruptable;
    this->turns = original.turns;
    this->weapon = original.weapon;
    this->quiver = original.quiver;
    this->action = original.action;
    this->character = original.character;
    this->area = original.area;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  GameCharacter::GameCharacter(GameCharacter& original) : Object(original)
  {
    (void) original;
    this->turn_undead_on = original.turn_undead_on;
    this->find_traps_on = original.find_traps_on;
    this->stealth_on = original.stealth_on;
    this->bard_song_on = original.bard_song_on;
    this->self_interruptable = original.self_interruptable;
    this->damage_interruptable = original.damage_interruptable;
    this->turns = original.turns;
    this->weapon = original.weapon;
    this->quiver = original.quiver;
    this->action = original.action;
    this->character = original.character;
    this->area = original.area;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  GameCharacter::GameCharacter(GameCharacter&& original) : Object(original)
  {
    (void) original;
    std::swap(this->turn_undead_on, original.turn_undead_on);
    std::swap(this->find_traps_on, original.find_traps_on);
    std::swap(this->stealth_on, original.stealth_on);
    std::swap(this->bard_song_on, original.bard_song_on);
    std::swap(this->self_interruptable, original.self_interruptable);
    std::swap(this->damage_interruptable, original.damage_interruptable);
    std::swap(this->turns, original.turns);
    std::swap(this->weapon, original.weapon);
    std::swap(this->quiver, original.quiver);
    std::swap(this->action, original.action);
    std::swap(this->character, original.character);
    std::swap(this->area, original.area);
  }
  
  /**
   * Fork the object
   * 
   * @return  A fork of the object
   */
  Object* GameCharacter::fork() const
  {
    return (Object*)(new GameCharacter(*this));
  }
  
  
  
  /**
   * Destructor
   */
  GameCharacter::~GameCharacter()
  {
    ////TODO implement destructor
    //delete this->action;
    //delete this->character;
    //delete this->area;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  GameCharacter& GameCharacter::operator =(const GameCharacter& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->turn_undead_on = original.turn_undead_on;
    this->find_traps_on = original.find_traps_on;
    this->stealth_on = original.stealth_on;
    this->bard_song_on = original.bard_song_on;
    this->self_interruptable = original.self_interruptable;
    this->damage_interruptable = original.damage_interruptable;
    this->turns = original.turns;
    this->weapon = original.weapon;
    this->quiver = original.quiver;
    this->action = original.action;
    this->character = original.character;
    this->area = original.area;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  GameCharacter& GameCharacter::operator =(GameCharacter& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->turn_undead_on = original.turn_undead_on;
    this->find_traps_on = original.find_traps_on;
    this->stealth_on = original.stealth_on;
    this->bard_song_on = original.bard_song_on;
    this->self_interruptable = original.self_interruptable;
    this->damage_interruptable = original.damage_interruptable;
    this->turns = original.turns;
    this->weapon = original.weapon;
    this->quiver = original.quiver;
    this->action = original.action;
    this->character = original.character;
    this->area = original.area;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  GameCharacter& GameCharacter::operator =(GameCharacter&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->turn_undead_on, original.turn_undead_on);
    std::swap(this->find_traps_on, original.find_traps_on);
    std::swap(this->stealth_on, original.stealth_on);
    std::swap(this->bard_song_on, original.bard_song_on);
    std::swap(this->self_interruptable, original.self_interruptable);
    std::swap(this->damage_interruptable, original.damage_interruptable);
    std::swap(this->turns, original.turns);
    std::swap(this->weapon, original.weapon);
    std::swap(this->quiver, original.quiver);
    std::swap(this->action, original.action);
    std::swap(this->character, original.character);
    std::swap(this->area, original.area);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool GameCharacter::operator ==(const GameCharacter& other) const
  {
    if (this->turn_undead_on != other.turn_undead_on)  return false;
    if (this->find_traps_on != other.find_traps_on)  return false;
    if (this->stealth_on != other.stealth_on)  return false;
    if (this->bard_song_on != other.bard_song_on)  return false;
    if (this->self_interruptable != other.self_interruptable)  return false;
    if (this->damage_interruptable != other.damage_interruptable)  return false;
    if (this->turns != other.turns)  return false;
    if (this->weapon != other.weapon)  return false;
    if (this->quiver != other.quiver)  return false;
    if (this->action != other.action)  return false;
    if (this->character != other.character)  return false;
    if (this->area != other.area)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool GameCharacter::operator !=(const GameCharacter& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void GameCharacter::__copy__(GameCharacter& self, const GameCharacter& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t GameCharacter::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<bool>()(this->turn_undead_on);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<bool>()(this->find_traps_on);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<bool>()(this->stealth_on);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<bool>()(this->bard_song_on);
    rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
    rc += std::hash<bool>()(this->self_interruptable);
    rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
    rc += std::hash<bool>()(this->damage_interruptable);
    rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
    rc += std::hash<char>()(this->turns);
    rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
    rc += std::hash<char>()(this->weapon);
    rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
    rc += std::hash<char>()(this->quiver);
    rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
    rc += std::hash<Action>()(this->action);
    rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
    rc += std::hash<Character>()(this->character);
    rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
    rc += std::hash<MapMinor>()(this->area);
    return rc;
  }
  
}

