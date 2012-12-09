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
#include "cleaner.hpp"


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
   * Clean items
   */
  void cleaner::clean()
  {
    delete PROTOTYPE(Amulet);
    delete PROTOTYPE(Arrow);
    delete PROTOTYPE(BastardSword);
    delete PROTOTYPE(BattleAxe);
    delete PROTOTYPE(Body);
    delete PROTOTYPE(Bolt);
    delete PROTOTYPE(Boots);
    delete PROTOTYPE(Bow);
    delete PROTOTYPE(Buckler);
    delete PROTOTYPE(Bullet);
    delete PROTOTYPE(ChainMail);
    delete PROTOTYPE(Cloak);
    delete PROTOTYPE(Club);
    delete PROTOTYPE(CompositeLongBow);
    delete PROTOTYPE(Container);
    delete PROTOTYPE(Crossbow);
    delete PROTOTYPE(Dagger);
    delete PROTOTYPE(Dart);
    delete PROTOTYPE(Defence);
    delete PROTOTYPE(Flail);
    delete PROTOTYPE(FullPlateMail);
    delete PROTOTYPE(Gauntlets);
    delete PROTOTYPE(Gem);
    delete PROTOTYPE(Girdle);
    delete PROTOTYPE(Gold);
    delete PROTOTYPE(Halberd);
    delete PROTOTYPE(Hat);
    delete PROTOTYPE(Headgear);
    delete PROTOTYPE(HeavyCrossbow);
    delete PROTOTYPE(Helmet);
    delete PROTOTYPE(HighWand);
    delete PROTOTYPE(Hood);
    delete PROTOTYPE(Item);
    delete PROTOTYPE(Key);
    delete PROTOTYPE(LargeShield);
    delete PROTOTYPE(LargeSword);
    delete PROTOTYPE(LeatherArmour);
    delete PROTOTYPE(LightCrossbow);
    delete PROTOTYPE(LongBow);
    delete PROTOTYPE(LongSword);
    delete PROTOTYPE(LowScroll);
    delete PROTOTYPE(LowWand);
    delete PROTOTYPE(Mace);
    delete PROTOTYPE(MediumShield);
    delete PROTOTYPE(MeleeWeapon);
    delete PROTOTYPE(MorningStar);
    delete PROTOTYPE(OneHandedMelee);
    delete PROTOTYPE(PlateMail);
    delete PROTOTYPE(Potion);
    delete PROTOTYPE(PriestScroll);
    delete PROTOTYPE(Quarterstaff);
    delete PROTOTYPE(QuestItem);
    delete PROTOTYPE(QuickItem);
    delete PROTOTYPE(RangedWeapon);
    delete PROTOTYPE(RightHandItem);
    delete PROTOTYPE(Ring);
    delete PROTOTYPE(Robe);
    delete PROTOTYPE(Scroll);
    delete PROTOTYPE(Shield);
    delete PROTOTYPE(ShortBow);
    delete PROTOTYPE(ShortSword);
    delete PROTOTYPE(Sling);
    delete PROTOTYPE(SmallShield);
    delete PROTOTYPE(Spear);
    delete PROTOTYPE(SplintMail);
    delete PROTOTYPE(StuddedLeatherArmour);
    delete PROTOTYPE(TextScroll);
    delete PROTOTYPE(ThrowingAxe);
    delete PROTOTYPE(Throwing);
    delete PROTOTYPE(ThrowingDagger);
    delete PROTOTYPE(Torch);
    delete PROTOTYPE(TwoHandedMelee);
    delete PROTOTYPE(TwoHandedSword);
    delete PROTOTYPE(Wand);
    delete PROTOTYPE(WarHammer);
    delete PROTOTYPE(Weapon);
    delete PROTOTYPE(WizardScroll);
  }
  
}

