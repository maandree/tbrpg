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
#include "Bonuses.hpp"


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
  Bonuses::Bonuses()
  {
    //TODO implement constructor
    //reaction_adjustment = nullptr;
    //wanted = nullptr;
    //killing_innocent = nullptr;
    //injuring_innocent = nullptr;
    //stealing = nullptr;
    //killing_guard = nullptr;
    //donation_needed = nullptr;
    //price_adjustment = nullptr;
    //good_reaction = nullptr;
    //neutral_reaction = nullptr;
    //evil_reaction = nullptr;
    //alignment_reputation = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Bonuses::Bonuses(const Bonuses& original)
  {
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
  Bonuses::Bonuses(Bonuses& original)
  {
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
  Bonuses::Bonuses(Bonuses&& original)
  {
    std::move(this->reaction_adjustment, original.reaction_adjustment);
    std::move(this->wanted, original.wanted);
    std::move(this->killing_innocent, original.killing_innocent);
    std::move(this->injuring_innocent, original.injuring_innocent);
    std::move(this->stealing, original.stealing);
    std::move(this->killing_guard, original.killing_guard);
    std::move(this->donation_needed, original.donation_needed);
    std::move(this->price_adjustment, original.price_adjustment);
    std::move(this->good_reaction, original.good_reaction);
    std::move(this->neutral_reaction, original.neutral_reaction);
    std::move(this->evil_reaction, original.evil_reaction);
    std::move(this->alignment_reputation, original.alignment_reputation);
  }
  
  
  
  /**
   * Destructor
   */
  Bonuses::~Bonuses()
  {
    //TODO implement destructor
    //delete reaction_adjustment;
    //delete wanted;
    //delete killing_innocent;
    //delete injuring_innocent;
    //delete stealing;
    //delete killing_guard;
    //delete donation_needed;
    //delete price_adjustment;
    //delete good_reaction;
    //delete neutral_reaction;
    //delete evil_reaction;
    //delete alignment_reputation;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(const Bonuses& original)
  {
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
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(Bonuses& original)
  {
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
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Bonuses& Bonuses::operator =(Bonuses&& original)
  {
    std::move(this->reaction_adjustment, original.reaction_adjustment);
    std::move(this->wanted, original.wanted);
    std::move(this->killing_innocent, original.killing_innocent);
    std::move(this->injuring_innocent, original.injuring_innocent);
    std::move(this->stealing, original.stealing);
    std::move(this->killing_guard, original.killing_guard);
    std::move(this->donation_needed, original.donation_needed);
    std::move(this->price_adjustment, original.price_adjustment);
    std::move(this->good_reaction, original.good_reaction);
    std::move(this->neutral_reaction, original.neutral_reaction);
    std::move(this->evil_reaction, original.evil_reaction);
    std::move(this->alignment_reputation, original.alignment_reputation);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Bonuses::__copy__(Bonuses& self, const Bonuses& original);
  {
    left = right;
  }
  
}

