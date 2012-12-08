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
#include "../src/CharacterCreator.hpp"
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
    
    /* misc. */
    {auto x = new Abilities(); delete x;}
    {auto x = new AbilityBonus(); delete x;}
    {auto x = new AbilityChart(); delete x;}
    {auto x = new ActionSlot(); delete x;}
    {auto x = new Amulet(); delete x;}
    {auto x = new BodyArmour(); delete x;}
    {auto x = new Bonuses(); delete x;}
    {auto x = new Boots(); delete x;}
    {auto x = new Buckler(); delete x;}
    {auto x = new ChainMail(); delete x;}
    {auto x = new Cloak(); delete x;}
    {auto x = new Container(); delete x;}
    {auto x = new CorpseMaker(); delete x;}
    {auto x = new Defence(); delete x;}
    {auto x = new Dice(); delete x;}
    {auto x = new Die(); delete x;}
    {auto x = new Door(); delete x;}
    {auto x = new Entrance(); delete x;}
    {auto x = new EnvironmentContainer(); delete x;}
    {auto x = new ExperienceChart(); delete x;}
    {auto x = new FullPlateMail(); delete x;}
    {auto x = new Gauntlets(); delete x;}
    {auto x = new Gem(); delete x;}
    {auto x = new Girdle(); delete x;}
    {auto x = new Gold(); delete x;}
    {auto x = new Hat(); delete x;}
    {auto x = new Headgear(); delete x;}
    {auto x = new Helmet(); delete x;}
    {auto x = new HighWand(); delete x;}
    {auto x = new Hood(); delete x;}
    {auto x = new House(); delete x;}
    {auto x = new Item(); delete x;}
    {auto x = new Key(); delete x;}
    {auto x = new LargeShield(); delete x;}
    {auto x = new LeatherArmour(); delete x;}
    {auto x = new Lockable(); delete x;}
    {auto x = new LowScroll(); delete x;}
    {auto x = new LowWand(); delete x;}
    {auto x = new MapMajor(); delete x;}
    {auto x = new _MapMinor(); delete x;}
    {auto x = new MapMinor(); delete x;}
    {auto x = new Map(); delete x;}
    {auto x = new MediumShield(); delete x;}
    {auto x = new Object(); delete x;}
    {auto x = new Party(); delete x;}
    {auto x = new PlateMail(); delete x;}
    {auto x = new Potion(); delete x;}
    {auto x = new PriestScroll(); delete x;}
    {auto x = new Proficiency(); delete x;}
    {auto x = new QuestItem(); delete x;}
    {auto x = new QuickItem(); delete x;}
    {auto x = new ReputationChart(); delete x;}
    {auto x = new RestInterruption(); delete x;}
    {auto x = new RightHandItem(); delete x;}
    {auto x = new Ring(); delete x;}
    {auto x = new Road(); delete x;}
    {auto x = new Robe(); delete x;}
    {auto x = new SavingThrows(); delete x;}
    {auto x = new Scroll(); delete x;}
    {auto x = new Shield(); delete x;}
    {auto x = new SmallShield(); delete x;}
    {auto x = new SpellBook(); delete x;}
    {auto x = new SpellProgression(); delete x;}
    {auto x = new SplintMail(); delete x;}
    {auto x = new StuddedLeatherArmour(); delete x;}
    {auto x = new TextScroll(); delete x;}
    {auto x = new ThiefAbilities(); delete x;}
    {auto x = new Town(); delete x;}
    {auto x = new Wand(); delete x;}
    {auto x = new Wilderness(); delete x;}
    {auto x = new WizardScroll(); delete x;}
    {auto x = new ActionSlotChart(); delete x;}
    {auto x = new Body(); delete x;}
    {auto x = new CharacterCreator(RuleSet()); delete x;}
    {auto x = new Character(); delete x;}
    {auto x = new CharacterSheet(); delete x;}
    {auto x = new Creature(); delete x;}
    {auto x = new DamageType(); delete x;}
    {auto x = new Inventory(); delete x;}
    {auto x = new MagicSchool(); delete x;}
    {auto x = new NPC(); delete x;}
    {auto x = new RuleSet(); delete x;}
    {auto x = new Spell(); delete x;}
    {auto x = new Store(); delete x;}
    {auto x = new WeaponGroup(); delete x;}
    
    /* races */
    {auto x = new Dwarf(); delete x;}
    {auto x = new Elf(); delete x;}
    {auto x = new Gnome(); delete x;}
    {auto x = new Human(); delete x;}
    {auto x = new HalfElf(); delete x;}
    {auto x = new Halfling(); delete x;}
    {auto x = new HalfOrc(); delete x;}
    {auto x = new Race(); delete x;}
    
    /* prestiges */
    {auto x = new Bard(); delete x;}
    {auto x = new Class(); delete x;}
    {auto x = new Cleric(); delete x;}
    {auto x = new Druid(); delete x;}
    {auto x = new Fighter(); delete x;}
    {auto x = new Mage(); delete x;}
    {auto x = new Paladin(); delete x;}
    {auto x = new Priest(); delete x;}
    {auto x = new Ranger(); delete x;}
    {auto x = new Rogue(); delete x;}
    {auto x = new Sorcerer(); delete x;}
    {auto x = new Thief(); delete x;}
    {auto x = new Warrior(); delete x;}
    {auto x = new Wizard(); delete x;}
    
    /* weapons and ammunition */
    {auto x = new Ammunition(); delete x;}
    {auto x = new Arrow(); delete x;}
    {auto x = new BastardSword(); delete x;}
    {auto x = new BattleAxe(); delete x;}
    {auto x = new BluntWeapon(); delete x;}
    {auto x = new Bolt(); delete x;}
    {auto x = new Bow(); delete x;}
    {auto x = new Bullet(); delete x;}
    {auto x = new Club(); delete x;}
    {auto x = new CompositeLongBow(); delete x;}
    {auto x = new Crossbow(); delete x;}
    {auto x = new Dagger(); delete x;}
    {auto x = new Dart(); delete x;}
    {auto x = new Fist(); delete x;}
    {auto x = new Fists(); delete x;}
    {auto x = new Flail(); delete x;}
    {auto x = new Halberd(); delete x;}
    {auto x = new HeavyCrossbow(); delete x;}
    {auto x = new LargeSword(); delete x;}
    {auto x = new LightCrossbow(); delete x;}
    {auto x = new LongBow(); delete x;}
    {auto x = new LongSword(); delete x;}
    {auto x = new Mace(); delete x;}
    {auto x = new MeleeWeapon(); delete x;}
    {auto x = new MorningStar(); delete x;}
    {auto x = new OneHandedMelee(); delete x;}
    {auto x = new Quarterstaff(); delete x;}
    {auto x = new RangedWeapon(); delete x;}
    {auto x = new ShortBow(); delete x;}
    {auto x = new ShortSword(); delete x;}
    {auto x = new Sling(); delete x;}
    {auto x = new Spear(); delete x;}
    {auto x = new ThrowingAxe(); delete x;}
    {auto x = new ThrowingDagger(); delete x;}
    {auto x = new Throwing(); delete x;}
    {auto x = new Torch(); delete x;}
    {auto x = new TwoHandedMelee(); delete x;}
    {auto x = new TwoHandedSword(); delete x;}
    {auto x = new WarHammer(); delete x;}
    {auto x = new Weapon(); delete x;}
    
    
    /* copy operator leak check */
    {auto x = Abilities(), y = Abilities(); x = y;}
    {auto x = AbilityBonus(), y = AbilityBonus(); x = y;}
    {auto x = AbilityChart(), y = AbilityChart(); x = y;}
    {auto x = ActionSlotChart(), y = ActionSlotChart(); x = y;}
    {auto x = ActionSlot(), y = ActionSlot(); x = y;}
    {auto x = Ammunition(), y = Ammunition(); x = y;}
    {auto x = Amulet(), y = Amulet(); x = y;}
    {auto x = Arrow(), y = Arrow(); x = y;}
    {auto x = Bard(), y = Bard(); x = y;}
    {auto x = BastardSword(), y = BastardSword(); x = y;}
    {auto x = BattleAxe(), y = BattleAxe(); x = y;}
    {auto x = BluntWeapon(), y = BluntWeapon(); x = y;}
    {auto x = BodyArmour(), y = BodyArmour(); x = y;}
    {auto x = Body(), y = Body(); x = y;}
    {auto x = Bolt(), y = Bolt(); x = y;}
    {auto x = Bonuses(), y = Bonuses(); x = y;}
    {auto x = Boots(), y = Boots(); x = y;}
    {auto x = Bow(), y = Bow(); x = y;}
    {auto x = Buckler(), y = Buckler(); x = y;}
    {auto x = Bullet(), y = Bullet(); x = y;}
    {auto x = ChainMail(), y = ChainMail(); x = y;}
    {auto x = CharacterCreator(RuleSet()), y = CharacterCreator(RuleSet()); x = y;}
    {auto x = Character(), y = Character(); x = y;}
    {auto x = CharacterSheet(), y = CharacterSheet(); x = y;}
    {auto x = Class(), y = Class(); x = y;}
    {auto x = Cleric(), y = Cleric(); x = y;}
    {auto x = Cloak(), y = Cloak(); x = y;}
    {auto x = Club(), y = Club(); x = y;}
    {auto x = CompositeLongBow(), y = CompositeLongBow(); x = y;}
    {auto x = Container(), y = Container(); x = y;}
    {auto x = CorpseMaker(), y = CorpseMaker(); x = y;}
    {auto x = Creature(), y = Creature(); x = y;}
    {auto x = Crossbow(), y = Crossbow(); x = y;}
    {auto x = Dagger(), y = Dagger(); x = y;}
    {auto x = DamageType(), y = DamageType(); x = y;}
    {auto x = Dart(), y = Dart(); x = y;}
    {auto x = Defence(), y = Defence(); x = y;}
    {auto x = Dice(), y = Dice(); x = y;}
    {auto x = Die(), y = Die(); x = y;}
    {auto x = Door(), y = Door(); x = y;}
    {auto x = Druid(), y = Druid(); x = y;}
    {auto x = Dwarf(), y = Dwarf(); x = y;}
    {auto x = Elf(), y = Elf(); x = y;}
    {auto x = Entrance(), y = Entrance(); x = y;}
    {auto x = EnvironmentContainer(), y = EnvironmentContainer(); x = y;}
    {auto x = ExperienceChart(), y = ExperienceChart(); x = y;}
    {auto x = Fighter(), y = Fighter(); x = y;}
    {auto x = Fist(), y = Fist(); x = y;}
    {auto x = Fists(), y = Fists(); x = y;}
    {auto x = Flail(), y = Flail(); x = y;}
    {auto x = FullPlateMail(), y = FullPlateMail(); x = y;}
    {auto x = Gauntlets(), y = Gauntlets(); x = y;}
    {auto x = Gem(), y = Gem(); x = y;}
    {auto x = Girdle(), y = Girdle(); x = y;}
    {auto x = Gnome(), y = Gnome(); x = y;}
    {auto x = Gold(), y = Gold(); x = y;}
    {auto x = Halberd(), y = Halberd(); x = y;}
    {auto x = HalfElf(), y = HalfElf(); x = y;}
    {auto x = Halfling(), y = Halfling(); x = y;}
    {auto x = HalfOrc(), y = HalfOrc(); x = y;}
    {auto x = Hat(), y = Hat(); x = y;}
    {auto x = Headgear(), y = Headgear(); x = y;}
    {auto x = HeavyCrossbow(), y = HeavyCrossbow(); x = y;}
    {auto x = Helmet(), y = Helmet(); x = y;}
    {auto x = HighWand(), y = HighWand(); x = y;}
    {auto x = Hood(), y = Hood(); x = y;}
    {auto x = House(), y = House(); x = y;}
    {auto x = Human(), y = Human(); x = y;}
    {auto x = Inventory(), y = Inventory(); x = y;}
    {auto x = Item(), y = Item(); x = y;}
    {auto x = Key(), y = Key(); x = y;}
    {auto x = LargeShield(), y = LargeShield(); x = y;}
    {auto x = LargeSword(), y = LargeSword(); x = y;}
    {auto x = LeatherArmour(), y = LeatherArmour(); x = y;}
    {auto x = LightCrossbow(), y = LightCrossbow(); x = y;}
    {auto x = Lockable(), y = Lockable(); x = y;}
    {auto x = LongBow(), y = LongBow(); x = y;}
    {auto x = LongSword(), y = LongSword(); x = y;}
    {auto x = LowScroll(), y = LowScroll(); x = y;}
    {auto x = LowWand(), y = LowWand(); x = y;}
    {auto x = Mace(), y = Mace(); x = y;}
    {auto x = Mage(), y = Mage(); x = y;}
    {auto x = MagicSchool(), y = MagicSchool(); x = y;}
    {auto x = MapMajor(), y = MapMajor(); x = y;}
    {auto x = _MapMinor(), y = _MapMinor(); x = y;}
    {auto x = MapMinor(), y = MapMinor(); x = y;}
    {auto x = Map(), y = Map(); x = y;}
    {auto x = MediumShield(), y = MediumShield(); x = y;}
    {auto x = MeleeWeapon(), y = MeleeWeapon(); x = y;}
    {auto x = MorningStar(), y = MorningStar(); x = y;}
    {auto x = NPC(), y = NPC(); x = y;}
    {auto x = Object(), y = Object(); x = y;}
    {auto x = OneHandedMelee(), y = OneHandedMelee(); x = y;}
    {auto x = Paladin(), y = Paladin(); x = y;}
    {auto x = Party(), y = Party(); x = y;}
    {auto x = PlateMail(), y = PlateMail(); x = y;}
    {auto x = Potion(), y = Potion(); x = y;}
    {auto x = Priest(), y = Priest(); x = y;}
    {auto x = PriestScroll(), y = PriestScroll(); x = y;}
    {auto x = Proficiency(), y = Proficiency(); x = y;}
    {auto x = Quarterstaff(), y = Quarterstaff(); x = y;}
    {auto x = QuestItem(), y = QuestItem(); x = y;}
    {auto x = QuickItem(), y = QuickItem(); x = y;}
    {auto x = Race(), y = Race(); x = y;}
    {auto x = RangedWeapon(), y = RangedWeapon(); x = y;}
    {auto x = Ranger(), y = Ranger(); x = y;}
    {auto x = ReputationChart(), y = ReputationChart(); x = y;}
    {auto x = RestInterruption(), y = RestInterruption(); x = y;}
    {auto x = RightHandItem(), y = RightHandItem(); x = y;}
    {auto x = Ring(), y = Ring(); x = y;}
    {auto x = Road(), y = Road(); x = y;}
    {auto x = Robe(), y = Robe(); x = y;}
    {auto x = Rogue(), y = Rogue(); x = y;}
    {auto x = RuleSet(), y = RuleSet(); x = y;}
    {auto x = SavingThrows(), y = SavingThrows(); x = y;}
    {auto x = Scroll(), y = Scroll(); x = y;}
    {auto x = Shield(), y = Shield(); x = y;}
    {auto x = ShortBow(), y = ShortBow(); x = y;}
    {auto x = ShortSword(), y = ShortSword(); x = y;}
    {auto x = Sling(), y = Sling(); x = y;}
    {auto x = SmallShield(), y = SmallShield(); x = y;}
    {auto x = Sorcerer(), y = Sorcerer(); x = y;}
    {auto x = Spear(), y = Spear(); x = y;}
    {auto x = SpellBook(), y = SpellBook(); x = y;}
    {auto x = Spell(), y = Spell(); x = y;}
    {auto x = SpellProgression(), y = SpellProgression(); x = y;}
    {auto x = SplintMail(), y = SplintMail(); x = y;}
    {auto x = Store(), y = Store(); x = y;}
    {auto x = StuddedLeatherArmour(), y = StuddedLeatherArmour(); x = y;}
    {auto x = TextScroll(), y = TextScroll(); x = y;}
    {auto x = ThiefAbilities(), y = ThiefAbilities(); x = y;}
    {auto x = Thief(), y = Thief(); x = y;}
    {auto x = ThrowingAxe(), y = ThrowingAxe(); x = y;}
    {auto x = ThrowingDagger(), y = ThrowingDagger(); x = y;}
    {auto x = Throwing(), y = Throwing(); x = y;}
    {auto x = Torch(), y = Torch(); x = y;}
    {auto x = Town(), y = Town(); x = y;}
    {auto x = TwoHandedMelee(), y = TwoHandedMelee(); x = y;}
    {auto x = TwoHandedSword(), y = TwoHandedSword(); x = y;}
    {auto x = Wand(), y = Wand(); x = y;}
    {auto x = WarHammer(), y = WarHammer(); x = y;}
    {auto x = Warrior(), y = Warrior(); x = y;}
    {auto x = WeaponGroup(), y = WeaponGroup(); x = y;}
    {auto x = Weapon(), y = Weapon(); x = y;}
    {auto x = Wilderness(), y = Wilderness(); x = y;}
    {auto x = Wizard(), y = Wizard(); x = y;}
    {auto x = WizardScroll(), y = WizardScroll(); x = y;}
    
    return 0;
  }
}

int main(int argc, char** argv)
{
  return tbrpg::__main__(argc, argv);
}

