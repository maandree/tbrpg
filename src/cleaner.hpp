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
#ifndef __GUARD_CLEANER_HPP__
#define __GUARD_CLEANER_HPP__


#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "prototype.hpp"
#include "Amulet.hpp"
#include "Arrow.hpp"
#include "BastardSword.hpp"
#include "BattleAxe.hpp"
#include "Body.hpp"
#include "Bolt.hpp"
#include "Boots.hpp"
#include "Bow.hpp"
#include "Buckler.hpp"
#include "Bullet.hpp"
#include "ChainMail.hpp"
#include "Cloak.hpp"
#include "Club.hpp"
#include "CompositeLongBow.hpp"
#include "Container.hpp"
#include "Crossbow.hpp"
#include "Dagger.hpp"
#include "Dart.hpp"
#include "Defence.hpp"
#include "Flail.hpp"
#include "FullPlateMail.hpp"
#include "Gauntlets.hpp"
#include "Gem.hpp"
#include "Girdle.hpp"
#include "Gold.hpp"
#include "Halberd.hpp"
#include "Hat.hpp"
#include "Headgear.hpp"
#include "HeavyCrossbow.hpp"
#include "Helmet.hpp"
#include "HighWand.hpp"
#include "Hood.hpp"
#include "Item.hpp"
#include "Key.hpp"
#include "LargeShield.hpp"
#include "LargeSword.hpp"
#include "LeatherArmour.hpp"
#include "LightCrossbow.hpp"
#include "LongBow.hpp"
#include "LongSword.hpp"
#include "LowScroll.hpp"
#include "LowWand.hpp"
#include "Mace.hpp"
#include "MediumShield.hpp"
#include "MeleeWeapon.hpp"
#include "MorningStar.hpp"
#include "OneHandedMelee.hpp"
#include "PlateMail.hpp"
#include "Potion.hpp"
#include "PriestScroll.hpp"
#include "Quarterstaff.hpp"
#include "QuestItem.hpp"
#include "QuickItem.hpp"
#include "RangedWeapon.hpp"
#include "RightHandItem.hpp"
#include "Ring.hpp"
#include "Robe.hpp"
#include "Scroll.hpp"
#include "Shield.hpp"
#include "ShortBow.hpp"
#include "ShortSword.hpp"
#include "Sling.hpp"
#include "SmallShield.hpp"
#include "Spear.hpp"
#include "SplintMail.hpp"
#include "StuddedLeatherArmour.hpp"
#include "TextScroll.hpp"
#include "ThrowingAxe.hpp"
#include "Throwing.hpp"
#include "ThrowingDagger.hpp"
#include "Torch.hpp"
#include "TwoHandedMelee.hpp"
#include "TwoHandedSword.hpp"
#include "Wand.hpp"
#include "WarHammer.hpp"
#include "Weapon.hpp"
#include "WizardScroll.hpp"


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
   * Item class
   */
  class cleaner
  {
  public:
    /**
     * Clean items
     */
    static void clean();
  };
}


#endif//__GUARD_CLEANER_HPP__

