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
#include "Class.hpp"


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
  Class::Class()
  {
    ////TODO implement constructor
    //this->hit_points = 0;
    //this->thac0 = 0;
    //this->lore_bonus = 0;
    //this->alignments = nullptr;
    //this->learn_from_scroll = false;
    //this->proficiencies_each = 0;
    //this->experience_chart = nullptr;
    //this->spell_progression = nullptr;
    //this->abilities = nullptr;
    //this->lower_limits = nullptr;
    //this->special_abilities = nullptr;
    //this->can_use = nullptr;
    //this->proficiency_chart = nullptr;
    //this->default_one_hand = nullptr;
    //this->default_two_hand = nullptr;
  }
  
  /**
   * Copy constructor
   * 
   * @param  original  The object to clone
   */
  Class::Class(const Class& original)
  {
    (void) original;
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
    this->special_abilities = original.special_abilities;
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
  Class::Class(Class& original)
  {
    (void) original;
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
    this->special_abilities = original.special_abilities;
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
  Class::Class(Class&& original)
  {
    (void) original;
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->thac0, original.thac0);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::swap(this->proficiencies_each, original.proficiencies_each);
    std::swap(this->experience_chart, original.experience_chart);
    std::swap(this->spell_progression, original.spell_progression);
    std::swap(this->abilities, original.abilities);
    std::swap(this->lower_limits, original.lower_limits);
    std::swap(this->special_abilities, original.special_abilities);
    std::swap(this->can_use, original.can_use);
    std::swap(this->proficiency_chart, original.proficiency_chart);
    std::swap(this->default_one_hand, original.default_one_hand);
    std::swap(this->default_two_hand, original.default_two_hand);
  }
  
  
  
  /**
   * Destructor
   */
  Class::~Class()
  {
    ////TODO implement destructor
    //delete alignments;
    //delete experience_chart;
    //delete spell_progression;
    //delete abilities;
    //delete lower_limits;
    //delete special_abilities;
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
  Class& Class::operator =(const Class& original)
  {
    (void) original;
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
    this->special_abilities = original.special_abilities;
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
  Class& Class::operator =(Class& original)
  {
    (void) original;
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
    this->special_abilities = original.special_abilities;
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
  Class& Class::operator =(Class&& original)
  {
    (void) original;
    std::swap(this->hit_points, original.hit_points);
    std::swap(this->thac0, original.thac0);
    std::swap(this->lore_bonus, original.lore_bonus);
    std::swap(this->alignments, original.alignments);
    std::swap(this->learn_from_scroll, original.learn_from_scroll);
    std::swap(this->proficiencies_each, original.proficiencies_each);
    std::swap(this->experience_chart, original.experience_chart);
    std::swap(this->spell_progression, original.spell_progression);
    std::swap(this->abilities, original.abilities);
    std::swap(this->lower_limits, original.lower_limits);
    std::swap(this->special_abilities, original.special_abilities);
    std::swap(this->can_use, original.can_use);
    std::swap(this->proficiency_chart, original.proficiency_chart);
    std::swap(this->default_one_hand, original.default_one_hand);
    std::swap(this->default_two_hand, original.default_two_hand);
    return *this;
  }
  
  /**
   * Copy method
   * 
   * @param  self      The object to modify
   * @param  original  The reference object
   */
  void Class::__copy__(Class& self, const Class& original)
  {
    self = original;
  }
  
  /**
   * Hash method
   * 
   * @return  The object's hash code
   */
  size_t Class::hash() const
  {
    return (size_t)this;
  }
  
}
