// -*- mode: c++, encoding: utf-8 -*-
/**
 * tbrpg – Text based roll playing game
 * 
 * Copyright © 2012, 2013  Mattias Andrée (maandree@kth.se)
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
#include "BasicSenario.hpp"


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
  BasicSenario::BasicSenario() : Senario()
  {
    this->rules.party_size = 3;
    this->rules.party_start_size = 3;
    
    this->rules.inventory_prototype.personal[0] = new Gold();
    this->rules.inventory_prototype.personal[0]->quantity = 400;
    cleaner::getInstance().enqueueDelete(this->rules.inventory_prototype.personal[0]);
    
    MapMajor map_town = MapMajor();
    MapMajor map_wilds = MapMajor();
    
    MapMinor area_inn = House();
    MapMinor area_town = Town();
    MapMinor area_wilds = Wilderness();
    MapMinor area_goal = Wilderness();
    
    map_town.name = "The town";
    map_town.visible = true;
    map_town.visited = true;
    map_town.visitable = true;
    
    map_wilds.name = "Outside the town";
    map_wilds.visible = false;
    map_wilds.visited = false;
    map_wilds.visitable = true;
    map_wilds.detectable = true;
    
    area_inn.description = "You are standing in an inn.";
    area_inn.area = 40;
    (area_inn.is_in = map_town).minors.push_back(area_inn);
    
    area_town.description = "You are standing in the marketplace.";
    area_town.area = 80;
    area_town.is_in = map_town;
    (area_town.is_in = map_town).minors.push_back(area_town);
    
    area_wilds.description = "You are out on the open roads.";
    area_wilds.area = 80;
    area_wilds.is_in = map_wilds;
    (area_wilds.is_in = map_wilds).minors.push_back(area_wilds);
    
    area_goal.description = "You are in the wilderness.";
    area_goal.area = 80;
    area_goal.is_in = map_wilds;
    (area_goal.is_in = map_wilds).minors.push_back(area_wilds);
    
    Road road_out = Road();
    Road road_in = Road();
    
    road_out.first_distance = road_in.last_distance = 1000;
    road_out.last_distance = road_in.first_distance = 1000;
    
    road_out.waylay_die = road_out.waylay_dice = 1;
    road_out.waylay_risk = 0;
    
    road_in.waylay_die = road_in.waylay_dice = 1;
    road_in.waylay_risk = 0;
    
    road_out.direction = "south";
    road_in.direction = "north";
    
    road_out.leads_to = area_wilds;
    road_in.leads_to = area_town;
    
    area_town.roads.push_back(road_out);
    area_wilds.roads.push_back(road_in);
    
    Door door_in = Door();
    Door door_out = Door();
    
    door_in.usable = true;
    door_out.usable = true;
    door_in.locked = false;
    door_out.locked = false;
    door_in.direction = "inn";
    door_out.direction = "town";
    door_in.description = "inn, you can rest safely here and get equipment";
    door_out.description = "the town";
    door_in.leads_to = area_inn;
    door_out.leads_to = area_town;
    
    Entrance next = Entrance();
    Entrance prev = Entrance();
    
    next.usable = true;
    prev.usable = true;
    next.direction = "south";
    prev.direction = "north";
    next.description = "the wilderness";
    prev.description = "the open roads";
    next.leads_to = area_goal;
    prev.leads_to = area_wilds;
    
    Store store = Store();
    area_inn.creatures.push_back(store);
    
    this->map.start = (MapMinor&)area_town;
    this->map.majors.push_back(map_town);
    this->map.majors.push_back(map_wilds);
    
    store.room_costs.push_back(1);
    store.room_quality.push_back(2);
    store.room_costs.push_back(2);
    store.room_quality.push_back(4);
    store.room_costs.push_back(4);
    store.room_quality.push_back(8);
    store.room_costs.push_back(8);
    store.room_quality.push_back(16);
    
    store.inventory.push_back(PROTOTYPE(ShortSword));
    store.inventory.push_back(PROTOTYPE(LongSword));
    store.inventory.push_back(PROTOTYPE(Bullet));
    store.inventory.push_back(PROTOTYPE(Sling));
    store.inventory.push_back(PROTOTYPE(ChainMail));
    store.inventory.push_back(PROTOTYPE(Helmet));
    
    for (Item& item : store.inventory)
      item.quantity = -1;
    
    Key* questkey = new Key();
    questkey->id = 0;
    cleaner::getInstance().enqueueDelete(questkey);
    
    Creature gibberling = Creature();
    gibberling.x = 50;
    gibberling.y = 50;
    gibberling.alive = true;
    gibberling.resurrect = false;
    gibberling.experience = 10;
    gibberling.record.name = "gibberling";
    gibberling.record.colour = 2;
    gibberling.record.alignment = 4;
    gibberling.record.inventory.personal.push_back(questkey);
  }
  
  /**
   * Destructor
   */
  BasicSenario::~BasicSenario()
  {
    // do nothing
  }
  
  
  
  /**
   * This is invoked when the senario starts.
   * The prologue, and perhaps a short tutorial,
   * should be displayed.
   */
  void BasicSenario::start()
  {
    page("This is a simple demo senario.\n"
	 "\n"
	 "You stand outside an inn, where you purchase items such as"   "\n"
	 "armour and weapons that your need in your quest. You mission" "\n"
	 "is to the legendary sword known as Sword of Legends.");
    
    promptDialogue(2, "Tutor",
		   "examine map       :: Examine you world map"                             "\n"
		   "examine area      :: Examine the area"                                  "\n"
		   "examine party     :: Examine your character's abilities and spellbooks" "\n"
		   "examine inventory :: Open your inventorty, and pick up items"           "\n"
		   "turn undead [off] :: Turn on or off Turn Undead (special ability)"      "\n"
		   "find traps [off]  :: Turn on or off Find Traps (special ability)"       "\n"
		   "stealth [off]     :: Turn on or off Stealth Mode (special ability)"     "\n"
		   "pick pocket       :: Pick pocket a NPC (special ability)"               "\n"
		   "disarm            :: Disarm a found trap (special ability)"             "\n"
		   "unlock            :: Unlock a door or chest (special ability)"          "\n"
		   "bash              :: Bash a door or chest"                              "\n"
		   "specials          :: List other special ability commands you can use"   "\n"
		   "talk              :: Talk to a NPC"                                     "\n"
		   "travel            :: Go in some direction"                              "\n"
		   "cast ***          :: Cast a *** spell"                                  "\n"
		   "cast              :: Cast a non-quick spell"                            "\n"
		   "attack            :: Attack with you current weapon"                    "\n"
		   "weapon            :: Change your current weapon"                        "\n"
		   "quiver            :: Change the ammunition to use from you quiver"      "\n"
		   "rest              :: Rest, you party must be gathered"                  "\n"
		   "!                 :: Redo the last action that was not a wait action"   "\n"
		   ".                 :: Wait a turn"                                       "\n"
		   "quit              :: Stop playing", {});
  }
  
  
  /**
   * Gets the name of the game senario
   * 
   * @return  The name of the game senario
   */
  std::string BasicSenario::getTitle()
  {
    return "Basic game senario demo";
  }
  
}

