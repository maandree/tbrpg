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
    this->reaction_adjustment = new int[21];
    this->wanted = new bool[21];
    this->killing_innocent = new int[21];
    this->injuring_innocent = new int[21];
    this->stealing = new int[21];
    this->killing_guard = new int[21];
    this->donation_needed = new int[21];
    this->price_adjustment = new float[21];
    this->good_reaction = new signed char[21];
    this->neutral_reaction = new signed char[21];
    this->evil_reaction = new signed char[21];
    this->alignment_reputation = new char[9];
    
    for (int i = 0; i <= 20; i++)
      this->wanted[i] = i < 6;
    
    for (int i = 0; i <= 13; i++)
      this->reaction_adjustment[i] = i < 8 ? (i - 8) : 0;
    for (int i = 14; i <= 20; i++)
      {
	this->reaction_adjustment[i] = (i - 12) >> 1;
	this->donation_needed[i] = i > 17 ? i == 17 ? 500 : -1 : (500 * (i - 14));
      }
    this->donation_needed[0] = -1;
    this->donation_needed[13] = this->donation_needed[2] = 1200;
    this->donation_needed[14] = 900;
    this->donation_needed[15] = 700;
    for (int i = 7; i <= 10; i++)
      this->donation_needed[i] = 100 * (i - 5);
    this->donation_needed[4] = this->donation_needed[3] = 1000;
    this->donation_needed[1] = 1500;
    
    for (int i = 0; i <= 20; i++)
      {
	this->stealing[i] = i > 8 ? -1 : 0;
	this->injuring_innocent[i] = i > 4 ? i > 17 ? -2 : -1 : 0;
	this->killing_guard[i] = -((i + (i > 6 ? i > 17 ? 1 : 2 : 0)) >> 1);
      }
    
    for (int i = 0; i <= 1; i++)
      this->killing_innocent[i] = i > 1 ? -1 : 0;
    for (int i = 2; i <= 9; i++)
      this->killing_innocent[i] = i == 9 ? -3 : -2;
    for (int i = 10; i <= 14; i++)
      this->killing_innocent[i] = i > 11 ? -5 : -4;
    for (int i = 15; i <= 19; i++)
      this->killing_innocent[i] = 9 - i;
    this->killing_innocent[20] = -10;
    
    for (int i = 0; i <= 2; i++)
      this->price_adjustment[i] = -1.;
    this->price_adjustment[3] = 2.00;
    this->price_adjustment[15] = 0.90;
    for (int i = 10; i <= 14; i++)
      this->price_adjustment[i] = 1.00;
    for (int i = 16; i <= 20; i++)
      this->price_adjustment[i] = (10 * (25 - i)) / 100.;
    for (int i = 5; i <= 9; i++)
      this->price_adjustment[i] = (10 * (19 - i) + (i > 7 ? 10 : 0)) / 100.;
    
    for (int i = 0; i <= 5; i++)
      this->good_reaction[i] = i < 3 ? -3 : -2;
    for (int i = 6; i <= 12; i++)
      this->good_reaction[i] = i < 9 ? -1 : 0;
    for (int i = 13; i <= 20; i++)
      this->good_reaction[i] = 1;
    
    for (int i = 0; i <= 3; i++)
      this->neutral_reaction[i] = i < 2 ? -3 : -2;
    for (int i = 4; i <= 18; i++)
      this->neutral_reaction[i] = i < 6 ? -1 : 0;
    for (int i = 19; i <= 20; i++)
      this->neutral_reaction[i] = -1;
    
    for (int i = 0; i <= 12; i++)
      this->evil_reaction[i] = i < 7 ? 1 : -0;
    for (int i = 13; i <= 20; i++)
      this->evil_reaction[i] = (10 - i) / 3;
    
    for (int i = 1; i <= 7; i++)
      this->alignment_reputation[i] = (i / 3) + 9;
    this->alignment_reputation[0] = 8;
    this->alignment_reputation[8] = 12;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(const ReputationChart& original) : Object(original)
  {
    this->reaction_adjustment = new int[21];
    this->wanted = new bool[21];
    this->killing_innocent = new int[21];
    this->injuring_innocent = new int[21];
    this->stealing = new int[21];
    this->killing_guard = new int[21];
    this->donation_needed = new int[21];
    this->price_adjustment = new float[21];
    this->good_reaction = new signed char[21];
    this->neutral_reaction = new signed char[21];
    this->evil_reaction = new signed char[21];
    this->alignment_reputation = new char[9];
    for (long i = 0; i < 21; i++)
      {
	this->reaction_adjustment[i] = original.reaction_adjustment[i];
	this->wanted[i] = original.wanted[i];
	this->killing_innocent[i] = original.killing_innocent[i];
	this->injuring_innocent[i] = original.injuring_innocent[i];
	this->stealing[i] = original.stealing[i];
	this->killing_guard[i] = original.killing_guard[i];
	this->donation_needed[i] = original.donation_needed[i];
	this->price_adjustment[i] = original.price_adjustment[i];
	this->good_reaction[i] = original.good_reaction[i];
	this->neutral_reaction[i] = original.neutral_reaction[i];
	this->evil_reaction[i] = original.evil_reaction[i];
      }
    for (long i = 0; i < 9; i++)
      this->alignment_reputation[i] = original.alignment_reputation[i];
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(ReputationChart& original) : Object(original)
  {
    this->reaction_adjustment = new int[21];
    this->wanted = new bool[21];
    this->killing_innocent = new int[21];
    this->injuring_innocent = new int[21];
    this->stealing = new int[21];
    this->killing_guard = new int[21];
    this->donation_needed = new int[21];
    this->price_adjustment = new float[21];
    this->good_reaction = new signed char[21];
    this->neutral_reaction = new signed char[21];
    this->evil_reaction = new signed char[21];
    this->alignment_reputation = new char[9];
    for (long i = 0; i < 21; i++)
      {
	this->reaction_adjustment[i] = original.reaction_adjustment[i];
	this->wanted[i] = original.wanted[i];
	this->killing_innocent[i] = original.killing_innocent[i];
	this->injuring_innocent[i] = original.injuring_innocent[i];
	this->stealing[i] = original.stealing[i];
	this->killing_guard[i] = original.killing_guard[i];
	this->donation_needed[i] = original.donation_needed[i];
	this->price_adjustment[i] = original.price_adjustment[i];
	this->good_reaction[i] = original.good_reaction[i];
	this->neutral_reaction[i] = original.neutral_reaction[i];
	this->evil_reaction[i] = original.evil_reaction[i];
      }
    for (long i = 0; i < 9; i++)
      this->alignment_reputation[i] = original.alignment_reputation[i];
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  ReputationChart::ReputationChart(ReputationChart&& original) : Object(original)
  {
    this->reaction_adjustment = new int[21];
    this->wanted = new bool[21];
    this->killing_innocent = new int[21];
    this->injuring_innocent = new int[21];
    this->stealing = new int[21];
    this->killing_guard = new int[21];
    this->donation_needed = new int[21];
    this->price_adjustment = new float[21];
    this->good_reaction = new signed char[21];
    this->neutral_reaction = new signed char[21];
    this->evil_reaction = new signed char[21];
    this->alignment_reputation = new char[9];
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
    delete[] this->reaction_adjustment;
    delete[] this->wanted;
    delete[] this->killing_innocent;
    delete[] this->injuring_innocent;
    delete[] this->stealing;
    delete[] this->killing_guard;
    delete[] this->donation_needed;
    delete[] this->price_adjustment;
    delete[] this->good_reaction;
    delete[] this->neutral_reaction;
    delete[] this->evil_reaction;
    delete[] this->alignment_reputation;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  ReputationChart& ReputationChart::operator =(const ReputationChart& original)
  {
    Object::__copy__((Object&)*this, (Object&)original);
    for (long i = 0; i < 21; i++)
      {
	this->reaction_adjustment[i] = original.reaction_adjustment[i];
	this->wanted[i] = original.wanted[i];
	this->killing_innocent[i] = original.killing_innocent[i];
	this->injuring_innocent[i] = original.injuring_innocent[i];
	this->stealing[i] = original.stealing[i];
	this->killing_guard[i] = original.killing_guard[i];
	this->donation_needed[i] = original.donation_needed[i];
	this->price_adjustment[i] = original.price_adjustment[i];
	this->good_reaction[i] = original.good_reaction[i];
	this->neutral_reaction[i] = original.neutral_reaction[i];
	this->evil_reaction[i] = original.evil_reaction[i];
      }
    for (long i = 0; i < 9; i++)
      this->alignment_reputation[i] = original.alignment_reputation[i];
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
    Object::__copy__((Object&)*this, (Object&)original);
    for (long i = 0; i < 21; i++)
      {
	this->reaction_adjustment[i] = original.reaction_adjustment[i];
	this->wanted[i] = original.wanted[i];
	this->killing_innocent[i] = original.killing_innocent[i];
	this->injuring_innocent[i] = original.injuring_innocent[i];
	this->stealing[i] = original.stealing[i];
	this->killing_guard[i] = original.killing_guard[i];
	this->donation_needed[i] = original.donation_needed[i];
	this->price_adjustment[i] = original.price_adjustment[i];
	this->good_reaction[i] = original.good_reaction[i];
	this->neutral_reaction[i] = original.neutral_reaction[i];
	this->evil_reaction[i] = original.evil_reaction[i];
      }
    for (long i = 0; i < 9; i++)
      this->alignment_reputation[i] = original.alignment_reputation[i];
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
    std::swap((Object&)*this, (Object&)original);
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
    for (long i = 0; i < 21; i++)
      {
	if (this->reaction_adjustment[i] != other.reaction_adjustment[i])  return false;
	if (this->wanted[i] != other.wanted[i])  return false;
	if (this->killing_innocent[i] != other.killing_innocent[i])  return false;
	if (this->injuring_innocent[i] != other.injuring_innocent[i])  return false;
	if (this->stealing[i] != other.stealing[i])  return false;
	if (this->killing_guard[i] != other.killing_guard[i])  return false;
	if (this->donation_needed[i] != other.donation_needed[i])  return false;
	if (this->price_adjustment[i] != other.price_adjustment[i])  return false;
	if (this->good_reaction[i] != other.good_reaction[i])  return false;
	if (this->neutral_reaction[i] != other.neutral_reaction[i])  return false;
	if (this->evil_reaction[i] != other.evil_reaction[i])  return false;
      }
    for (long i = 0; i < 9; i++)
      if (this->alignment_reputation[i] != other.alignment_reputation[i])  return false;
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
    for (long i = 0; i < 21; i++)
      {
	rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
	rc += std::hash<int>()(this->reaction_adjustment[i]);
	rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
	rc += std::hash<bool>()(this->wanted[i]);
	rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
	rc += std::hash<int>()(this->killing_innocent[i]);
	rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
	rc += std::hash<int>()(this->injuring_innocent[i]);
	rc = (rc * 11) ^ ((rc >> (sizeof(size_t) << 2)) * 11);
	rc += std::hash<int>()(this->stealing[i]);
	rc = (rc * 13) ^ ((rc >> (sizeof(size_t) << 2)) * 13);
	rc += std::hash<int>()(this->killing_guard[i]);
	rc = (rc * 17) ^ ((rc >> (sizeof(size_t) << 2)) * 17);
	rc += std::hash<int>()(this->donation_needed[i]);
	rc = (rc * 19) ^ ((rc >> (sizeof(size_t) << 2)) * 19);
	rc += std::hash<float>()(this->price_adjustment[i]);
	rc = (rc * 3) ^ ((rc >> (sizeof(size_t) << 2)) * 3);
	rc += std::hash<signed char>()(this->good_reaction[i]);
	rc = (rc * 5) ^ ((rc >> (sizeof(size_t) << 2)) * 5);
	rc += std::hash<signed char>()(this->neutral_reaction[i]);
	rc = (rc * 7) ^ ((rc >> (sizeof(size_t) << 2)) * 7);
	rc += std::hash<signed char>()(this->evil_reaction[i]);
      }
    for (long i = 0; i < 9; i++)
      {
	rc = (rc * 9) ^ ((rc >> (sizeof(size_t) << 2)) * 9);
	rc += std::hash<char>()(this->alignment_reputation[i]);
      }
    return rc;
  }
  
}

