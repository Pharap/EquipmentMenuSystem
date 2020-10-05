#pragma once

#include "Menu.h"
#include "Player.h"
#include "Utility.h"

// Options
constexpr char EquipmentMenuOptionTable[] PROGMEM = "Table";
void GivePlayerTable(Player & player) { /*give the player a table*/ }

constexpr char EquipmentMenuOptionOrnament[] PROGMEM = "Ornament";
void GivePlayerOrnament(Player & player) { /*give the player an ornament*/ }

constexpr char EquipmentMenuOptionLaptop[] PROGMEM = "Laptop";
void GivePlayerLaptop(Player & player) { /*give the player a laptop?*/ }

// Menu
constexpr char EquipmentMenuTitle[] PROGMEM = "BUY EQUIPMENT";

constexpr MenuOption EquipmentMenuOptions[] PROGMEM =
{
  { EquipmentMenuOptionTable, GivePlayerTable },
  { EquipmentMenuOptionOrnament, GivePlayerOrnament },
  { EquipmentMenuOptionLaptop, GivePlayerLaptop },
};

constexpr Menu EquipmentMenu PROGMEM =
{
	EquipmentMenuTitle,
	EquipmentMenuOptions,
	ArrayLength(EquipmentMenuOptions)
};

constexpr uint8_t EquipmentMenuLength =  ArrayLength(EquipmentMenuOptions);
constexpr uint8_t EquipmentMenuMinIndex =  0;
constexpr uint8_t EquipmentMenuMaxIndex =  EquipmentMenuLength - 1;
