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
#include "ReputationChart.hpp"


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
  ReputationChart::ReputationChart() : Object()
  {
    this->class_inheritance.push_back(2);
    ////TODO implement constructor
    //this->reaction_adjustment = nullptr;
    //this->wanted = nullptr;
    //this->killing_innocent = nullptr;
    //this->injuring_innocent = nullptr;
    //this->stealing = nullptr;
    //this->killing_guard = nullptr;
    //this->donation_needed = nullptr;
    //this->price_adjustment = nullptr;
    //this->good_reaction = nullptr;
    //this->neutral_reaction = nullptr;
    //this->evil_reaction = nullptr;
    //this->alignment_reputation = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(const ReputationChart& original) : Object(original)
  {
    (void) original;
    this->reaction_adjustment = original.reaction_adjustment;
    this->wanted = original.wanted;
    this->killing_innocent = original.killing_innocent;
    this->injuring_innocent = original.injuring_innocent;
    this->stealing = original.stealing;
    this->killing_guard = original.killing_guard;
    this->donation_needed = original.donation_needed;
    this->price_adjustment = original.price_adjustment;
    this->good_reaction = original.good_reaction;
    this->neutral_reaction = original.neutral_reaction;
    this->evil_reaction = original.evil_reaction;
    this->alignment_reputation = original.alignment_reputation;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(ReputationChart& original) : Object(original)
  {
    (void) original;
    this->reaction_adjustment = original.reaction_adjustment;
    this->wanted = original.wanted;
    this->killing_innocent = original.killing_innocent;
    this->injuring_innocent = original.injuring_innocent;
    this->stealing = original.stealing;
    this->killing_guard = original.killing_guard;
    this->donation_needed = original.donation_needed;
    this->price_adjustment = original.price_adjustment;
    this->good_reaction = original.good_reaction;
    this->neutral_reaction = original.neutral_reaction;
    this->evil_reaction = original.evil_reaction;
    this->alignment_reputation = original.alignment_reputation;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(ReputationChart&& original) : Object(original)
  {
    (void) original;
    std::swap(this->reaction_adjustment, original.reaction_adjustment);
    std::swap(this->wanted, original.wanted);
    std::swap(this->killing_innocent, original.killing_innocent);
    std::swap(this->injuring_innocent, original.injuring_innocent);
    std::swap(this->stealing, original.stealing);
    std::swap(this->killing_guard, original.killing_guard);
    std::swap(this->donation_needed, original.donation_needed);
    std::swap(this->price_adjustment, original.price_adjustment);
    std::swap(this->good_reaction, original.good_reaction);
    std::swap(this->neutral_reaction, original.neutral_reaction);
    std::swap(this->evil_reaction, original.evil_reaction);
    std::swap(this->alignment_reputation, original.alignment_reputation);
  }
  
  
  
  /**
   * Destructor
   */
  ReputationChart::~ReputationChart()
  {
    ////TODO implement destructor
    //delete this->reaction_adjustment;
    //delete this->wanted;
    //delete this->killing_innocent;
    //delete this->injuring_innocent;
    //delete this->stealing;
    //delete this->killing_guard;
    //delete this->donation_needed;
    //delete this->price_adjustment;
    //delete this->good_reaction;
    //delete this->neutral_reaction;
    //delete this->evil_reaction;
    //delete this->alignment_reputation;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ReputationChart& ReputationChart::operator =(const ReputationChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->reaction_adjustment = original.reaction_adjustment;
    this->wanted = original.wanted;
    this->killing_innocent = original.killing_innocent;
    this->injuring_innocent = original.injuring_innocent;
    this->stealing = original.stealing;
    this->killing_guard = original.killing_guard;
    this->donation_needed = original.donation_needed;
    this->price_adjustment = original.price_adjustment;
    this->good_reaction = original.good_reaction;
    this->neutral_reaction = original.neutral_reaction;
    this->evil_reaction = original.evil_reaction;
    this->alignment_reputation = original.alignment_reputation;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ReputationChart& ReputationChart::operator =(ReputationChart& original)
  {
    (void) original;
    Object::__copy__((Object&)*this, (Object&)original);    this->reaction_adjustment = original.reaction_adjustment;
    this->wanted = original.wanted;
    this->killing_innocent = original.killing_innocent;
    this->injuring_innocent = original.injuring_innocent;
    this->stealing = original.stealing;
    this->killing_guard = original.killing_guard;
    this->donation_needed = original.donation_needed;
    this->price_adjustment = original.price_adjustment;
    this->good_reaction = original.good_reaction;
    this->neutral_reaction = original.neutral_reaction;
    this->evil_reaction = original.evil_reaction;
    this->alignment_reputation = original.alignment_reputation;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  ReputationChart& ReputationChart::operator =(ReputationChart&& original)
  {
    (void) original;
    std::swap((Object&)*this, (Object&)original);    std::swap(this->reaction_adjustment, original.reaction_adjustment);
    std::swap(this->wanted, original.wanted);
    std::swap(this->killing_innocent, original.killing_innocent);
    std::swap(this->injuring_innocent, original.injuring_innocent);
    std::swap(this->stealing, original.stealing);
    std::swap(this->killing_guard, original.killing_guard);
    std::swap(this->donation_needed, original.donation_needed);
    std::swap(this->price_adjustment, original.price_adjustment);
    std::swap(this->good_reaction, original.good_reaction);
    std::swap(this->neutral_reaction, original.neutral_reaction);
    std::swap(this->evil_reaction, original.evil_reaction);
    std::swap(this->alignment_reputation, original.alignment_reputation);
    return *this;
  }
  
  
  /**
   * Equality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are equal
   */
  bool ReputationChart::operator ==(const ReputationChart& other) const
  {
    if (this->reaction_adjustment != other.reaction_adjustment)  return false;
    if (this->wanted != other.wanted)  return false;
    if (this->killing_innocent != other.killing_innocent)  return false;
    if (this->injuring_innocent != other.injuring_innocent)  return false;
    if (this->stealing != other.stealing)  return false;
    if (this->killing_guard != other.killing_guard)  return false;
    if (this->donation_needed != other.donation_needed)  return false;
    if (this->price_adjustment != other.price_adjustment)  return false;
    if (this->good_reaction != other.good_reaction)  return false;
    if (this->neutral_reaction != other.neutral_reaction)  return false;
    if (this->evil_reaction != other.evil_reaction)  return false;
    if (this->alignment_reputation != other.alignment_reputation)  return false;
    return true;
  }
  
  /**
   * Inequality evaluator
   * 
   * @param   other  The other comparand
   * @return         Whether the instances are not equal
   */
  bool ReputationChart::operator !=(const ReputationChart& other) const
  {
    return (*this == other) == false;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void ReputationChart::__copy__(ReputationChart& self, const ReputationChart& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t ReputationChart::hash() const
  {
    size_t rc = 0;
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<int[]>()(reaction_adjustment);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<bool[]>()(wanted);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<int[]>()(killing_innocent);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<int[]>()(injuring_innocent);
    rc = (rc * 11) ^ (rc >> (sizeof(size_t) << 2) * 11);
    rc += std::hash<int[]>()(stealing);
    rc = (rc * 13) ^ (rc >> (sizeof(size_t) << 2) * 13);
    rc += std::hash<int[]>()(killing_guard);
    rc = (rc * 17) ^ (rc >> (sizeof(size_t) << 2) * 17);
    rc += std::hash<int[]>()(donation_needed);
    rc = (rc * 19) ^ (rc >> (sizeof(size_t) << 2) * 19);
    rc += std::hash<float[]>()(price_adjustment);
    rc = (rc * 3) ^ (rc >> (sizeof(size_t) << 2) * 3);
    rc += std::hash<signed char[]>()(good_reaction);
    rc = (rc * 5) ^ (rc >> (sizeof(size_t) << 2) * 5);
    rc += std::hash<signed char[]>()(neutral_reaction);
    rc = (rc * 7) ^ (rc >> (sizeof(size_t) << 2) * 7);
    rc += std::hash<signed char[]>()(evil_reaction);
    rc = (rc * 9) ^ (rc >> (sizeof(size_t) << 2) * 9);
    rc += std::hash<char[]>()(alignment_reputation);
    return rc;
  }
  
}

