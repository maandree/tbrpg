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
#include "Race.hpp"


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
  Race::Race()
  {
    //TODO implement constructor
    //hit_points = nullptr;
    //thac0 = nullptr;
    //lore_bonus = nullptr;
    //alignments = nullptr;
    //learn_from_scroll = false;
    //proficiencies_each = nullptr;
    //experience_chart = nullptr;
    //spell_progression = nullptr;
    //abilities = nullptr;
    //lower_limits = nullptr;
    //special_abilties = nullptr;
    //can_use = nullptr;
    //proficiency_chart = nullptr;
    //default_one_hand = nullptr;
    //default_two_hand = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(const Race& original)
  {
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilties = original.special_abilties;
    this->can_use = original.can_use;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hand = original.default_two_hand;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race& original)
  {
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilties = original.special_abilties;
    this->can_use = original.can_use;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hand = original.default_two_hand;
  }
  
  /**
   * Move constructor
   * 
   * @param  original  The object to clone
   */
  Race::Race(Race&& original)
  {
    std::move(this->hit_points, original.hit_points);
    std::move(this->thac0, original.thac0);
    std::move(this->lore_bonus, original.lore_bonus);
    std::move(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::move(this->proficiencies_each, original.proficiencies_each);
    std::move(this->experience_chart, original.experience_chart);
    std::move(this->spell_progression, original.spell_progression);
    std::move(this->abilities, original.abilities);
    std::move(this->lower_limits, original.lower_limits);
    std::move(this->special_abilties, original.special_abilties);
    std::move(this->can_use, original.can_use);
    std::move(this->proficiency_chart, original.proficiency_chart);
    std::move(this->default_one_hand, original.default_one_hand);
    std::move(this->default_two_hand, original.default_two_hand);
  }
  
  
  
  /**
   * Destructor
   */
  Race::~Race()
  {
    //TODO implement destructor
    //delete hit_points;
    //delete thac0;
    //delete lore_bonus;
    //delete alignments;
    //delete proficiencies_each;
    //delete experience_chart;
    //delete spell_progression;
    //delete abilities;
    //delete lower_limits;
    //delete special_abilties;
    //delete can_use;
    //delete proficiency_chart;
    //delete default_one_hand;
    //delete default_two_hand;
  }
  
  
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(const Race& original)
  {
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilties = original.special_abilties;
    this->can_use = original.can_use;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hand = original.default_two_hand;
    return *this;
  }
  
  /**
   * Assignment operator
   * 
   * @param   original  The reference object
   * @return            The invoked object
   */
  Race& Race::operator =(Race& original)
  {
    this->hit_points = original.hit_points;
    this->thac0 = original.thac0;
    this->lore_bonus = original.lore_bonus;
    this->alignments = original.alignments;
    this->learn_from_scroll = original.learn_from_scroll;
    this->proficiencies_each = original.proficiencies_each;
    this->experience_chart = original.experience_chart;
    this->spell_progression = original.spell_progression;
    this->abilities = original.abilities;
    this->lower_limits = original.lower_limits;
    this->special_abilties = original.special_abilties;
    this->can_use = original.can_use;
    this->proficiency_chart = original.proficiency_chart;
    this->default_one_hand = original.default_one_hand;
    this->default_two_hand = original.default_two_hand;
    return *this;
  }
  
  /**
   * Move operator
   * 
   * @param   original  The moved object, its resourced will be moved
   * @return            The invoked object
   */
  Race& Race::operator =(Race&& original)
  {
    std::move(this->hit_points, original.hit_points);
    std::move(this->thac0, original.thac0);
    std::move(this->lore_bonus, original.lore_bonus);
    std::move(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::move(this->proficiencies_each, original.proficiencies_each);
    std::move(this->experience_chart, original.experience_chart);
    std::move(this->spell_progression, original.spell_progression);
    std::move(this->abilities, original.abilities);
    std::move(this->lower_limits, original.lower_limits);
    std::move(this->special_abilties, original.special_abilties);
    std::move(this->can_use, original.can_use);
    std::move(this->proficiency_chart, original.proficiency_chart);
    std::move(this->default_one_hand, original.default_one_hand);
    std::move(this->default_two_hand, original.default_two_hand);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  static void Race::__copy__(Race& self, const Race& original);
  {
    left = right;
  }
  
}

