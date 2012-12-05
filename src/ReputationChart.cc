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
    return this == &other;
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
    return (size_t)this;
  }
  
}

