// -*- mode: c++, encoding: utf-8 -*-
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#include "../src/Abilities.hpp"
#include "../src/AbilityBonus.hpp"
#include "../src/AbilityChart.hpp"
#include "../src/ActionSlotChart.hpp"
#include "../src/ActionSlot.hpp"
#include "../src/Ammunition.hpp"
#include "../src/Amulet.hpp"
#include "../src/Arrow.hpp"
#include "../src/Bard.hpp"
#include "../src/BastardSword.hpp"
#include "../src/BattleAxe.hpp"
#include "../src/BluntWeapon.hpp"
#include "../src/BodyArmour.hpp"
#include "../src/Body.hpp"
#include "../src/Bolt.hpp"
#include "../src/Bonuses.hpp"
#include "../src/Boots.hpp"
#include "../src/Bow.hpp"
#include "../src/Buckler.hpp"
#include "../src/Bullet.hpp"
#include "../src/ChainMail.hpp"
#include "../src/Character.hpp"
#include "../src/CharacterSheet.hpp"
#include "../src/Class.hpp"
#include "../src/Cleric.hpp"
#include "../src/Cloak.hpp"
#include "../src/Club.hpp"
#include "../src/CompositeLongBow.hpp"
#include "../src/Container.hpp"
#include "../src/CorpseMaker.hpp"
#include "../src/Creature.hpp"
#include "../src/Crossbow.hpp"
#include "../src/Dagger.hpp"
#include "../src/DamageType.hpp"
#include "../src/Dart.hpp"
#include "../src/Defence.hpp"
#include "../src/Dice.hpp"
#include "../src/Die.hpp"
#include "../src/Door.hpp"
#include "../src/Druid.hpp"
#include "../src/Dwarf.hpp"
#include "../src/Elf.hpp"
#include "../src/Entrance.hpp"
#include "../src/EnvironmentContainer.hpp"
#include "../src/ExperienceChart.hpp"
#include "../src/Fighter.hpp"
#include "../src/Fist.hpp"
#include "../src/Fists.hpp"
#include "../src/Flail.hpp"
#include "../src/FullPlateMail.hpp"
#include "../src/Gauntlets.hpp"
#include "../src/Gem.hpp"
#include "../src/Girdle.hpp"
#include "../src/Gnome.hpp"
#include "../src/Gold.hpp"
#include "../src/Halberd.hpp"
#include "../src/HalfElf.hpp"
#include "../src/Halfling.hpp"
#include "../src/HalfOrc.hpp"
#include "../src/Hat.hpp"
#include "../src/Headgear.hpp"
#include "../src/HeavyCrossbow.hpp"
#include "../src/Helmet.hpp"
#include "../src/HighWand.hpp"
#include "../src/Hood.hpp"
#include "../src/House.hpp"
#include "../src/Human.hpp"
#include "../src/Inventory.hpp"
#include "../src/Item.hpp"
#include "../src/Key.hpp"
#include "../src/LargeShield.hpp"
#include "../src/LargeSword.hpp"
#include "../src/LeatherArmour.hpp"
#include "../src/LightCrossbow.hpp"
#include "../src/Lockable.hpp"
#include "../src/LongBow.hpp"
#include "../src/LongSword.hpp"
#include "../src/LowScroll.hpp"
#include "../src/LowWand.hpp"
#include "../src/Mace.hpp"
#include "../src/Mage.hpp"
#include "../src/MagicSchool.hpp"
#include "../src/MapMajor.hpp"
#include "../src/_MapMinor.hpp"
#include "../src/MapMinor.hpp"
#include "../src/Map.hpp"
#include "../src/MediumShield.hpp"
#include "../src/MeleeWeapon.hpp"
#include "../src/MorningStar.hpp"
#include "../src/NPC.hpp"
#include "../src/Object.hpp"
#include "../src/OneHandedMelee.hpp"
#include "../src/Paladin.hpp"
#include "../src/Party.hpp"
#include "../src/PlateMail.hpp"
#include "../src/Potion.hpp"
#include "../src/Priest.hpp"
#include "../src/PriestScroll.hpp"
#include "../src/Proficiency.hpp"
#include "../src/Quarterstaff.hpp"
#include "../src/QuestItem.hpp"
#include "../src/QuickItem.hpp"
#include "../src/Race.hpp"
#include "../src/RangedWeapon.hpp"
#include "../src/Ranger.hpp"
#include "../src/ReputationChart.hpp"
#include "../src/RestInterruption.hpp"
#include "../src/RightHandItem.hpp"
#include "../src/Ring.hpp"
#include "../src/Road.hpp"
#include "../src/Robe.hpp"
#include "../src/Rogue.hpp"
#include "../src/RuleSet.hpp"
#include "../src/SavingThrows.hpp"
#include "../src/Scroll.hpp"
#include "../src/Shield.hpp"
#include "../src/ShortBow.hpp"
#include "../src/ShortSword.hpp"
#include "../src/Sling.hpp"
#include "../src/SmallShield.hpp"
#include "../src/Sorcerer.hpp"
#include "../src/Spear.hpp"
#include "../src/SpellBook.hpp"
#include "../src/Spell.hpp"
#include "../src/SpellProgression.hpp"
#include "../src/SplintMail.hpp"
#include "../src/Store.hpp"
#include "../src/StuddedLeatherArmour.hpp"
#include "../src/TextScroll.hpp"
#include "../src/ThiefAbilities.hpp"
#include "../src/Thief.hpp"
#include "../src/ThrowingAxe.hpp"
#include "../src/ThrowingDagger.hpp"
#include "../src/Throwing.hpp"
#include "../src/Torch.hpp"
#include "../src/Town.hpp"
#include "../src/TwoHandedMelee.hpp"
#include "../src/TwoHandedSword.hpp"
#include "../src/Wand.hpp"
#include "../src/WarHammer.hpp"
#include "../src/Warrior.hpp"
#include "../src/WeaponGroup.hpp"
#include "../src/Weapon.hpp"
#include "../src/Wilderness.hpp"
#include "../src/Wizard.hpp"
#include "../src/WizardScroll.hpp"
#include "../src/Senario.hpp"
#include "../src/BasicSenario.hpp"
#include "../src/CharacterCreator.hpp"
#include "../src/cleaner.hpp"


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
   * This the main entry point of the program
   * 
   * @param   argc  The number of elements in `argv`
   * @param   argv  Command line arguments, including the execute file
   * @return        Exit value, 0 if successful
   */
  int __main__(int argc, char** argv)
  {
    (void) argc;
    (void) argv;
    cleaner::getInstance();
    
    #define __a(T)  {std::cout << "a: " << #T << std::endl; auto x = new T(); delete x;}
    #define __b(T)  {std::cout << "b: " << #T << std::endl; auto x = T(), y = T(); x = y;}
    #define __(T)  __a(T) __b(T) //
    
    /* misc. */
    /**/
    __(Abilities);
    __(AbilityBonus);
    __(AbilityChart);
    __(ActionSlot);
    __(Amulet);
    __(BodyArmour);
    __(Bonuses);
    __(Boots);
    __(Buckler);
    __(ChainMail);
    __(Cloak);
    __(Container);
    __(CorpseMaker);
    __(Defence);
    __(Dice);
    __(Die);
    __(Door);
    __(Entrance);
    __(EnvironmentContainer);
    __(ExperienceChart);
    __(FullPlateMail);
    __(Gauntlets);
    __(Gem);
    __(Girdle);
    __(Gold);
    __(Hat);
    __(Headgear);
    __(Helmet);
    __(HighWand);
    __(Hood);
    __(House);
    __(Item);
    __(Key);
    __(LargeShield);
    __(LeatherArmour);
    __(Lockable);
    __(LowScroll);
    __(LowWand);
    __(MapMajor);
    __(_MapMinor);
    __(MapMinor);
    __(Map);
    __(MediumShield);
    __(Object);
    __(Party);
    __(PlateMail);
    __(Potion);
    __(PriestScroll);
    __(Proficiency);
    __(QuestItem);
    __(QuickItem);
    __(ReputationChart);
    __(RestInterruption);
    __(RightHandItem);
    __(Ring);
    __(Road);
    __(Robe);
    __(SavingThrows);
    __(Scroll);
    __(Shield);
    __(SmallShield);
    __(SpellBook);
    __(SpellProgression);
    __(SplintMail);
    __(StuddedLeatherArmour);
    __(TextScroll);
    __(ThiefAbilities);
    __(Town);
    __(Wand);
    __(Wilderness);
    __(WizardScroll);
    __(ActionSlotChart);
    __(Body);
    __(Character);
    __(CharacterSheet);
    __(Creature);
    __(DamageType);
    __(Inventory);
    __(MagicSchool);
    __(NPC);
    __(RuleSet);
    __(Spell);
    __(Store);
    __(WeaponGroup);
    __(CharacterCreator);
    /**/
    
    /* races */
    /**/
    __(Dwarf);
    __(Elf);
    __(Gnome);
    __(Human);
    __(HalfElf);
    __(Halfling);
    __(HalfOrc);
    __(Race);
    /**/
    
    /* prestiges */
    /**/
    __(Bard);
    __(Class);
    __(Cleric);
    __(Druid);
    __(Fighter);
    __(Mage);
    __(Paladin);
    __(Priest);
    __(Ranger);
    __(Rogue);
    __(Sorcerer);
    __(Thief);
    __(Warrior);
    __(Wizard);
    /**/
    
    /* weapons and ammunition */
    /**/
    __(Ammunition);
    __(Arrow);
    __(BastardSword);
    __(BattleAxe);
    __(BluntWeapon);
    __(Bolt);
    __(Bow);
    __(Bullet);
    __(Club);
    __(CompositeLongBow);
    __(Crossbow);
    __(Dagger);
    __(Dart);
    __(Fist);
    __(Fists);
    __(Flail);
    __(Halberd);
    __(HeavyCrossbow);
    __(LargeSword);
    __(LightCrossbow);
    __(LongBow);
    __(LongSword);
    __(Mace);
    __(MeleeWeapon);
    __(MorningStar);
    __(OneHandedMelee);
    __(Quarterstaff);
    __(RangedWeapon);
    __(ShortBow);
    __(ShortSword);
    __(Sling);
    __(Spear);
    __(ThrowingAxe);
    __(ThrowingDagger);
    __(Throwing);
    __(Torch);
    __(TwoHandedMelee);
    __(TwoHandedSword);
    __(WarHammer);
    __(Weapon);
    /**/
    
    /* senarioes */
    /**/
    __(Senario);
    __(BasicSenario);
    /**/
    
    cleaner::getInstance().clean();
    return 0;
  }
}

int main(int argc, char** argv)
{
  return tbrpg::__main__(argc, argv);
}

