#pragma once

#include "Menu.h"
#include "Player.h"
#include "Utility.h"

// Options
const char EquipmentMenuOptionTable[] PROGMEM = "Table";
void GivePlayerTable(Player & player) { /*give the player a table*/ }

const char EquipmentMenuOptionOrnament[] PROGMEM = "Ornament";
void GivePlayerOrnament(Player & player) { /*give the player an ornament*/ }

const char EquipmentMenuOptionLaptop[] PROGMEM = "Laptop";
void GivePlayerLaptop(Player & player) { /*give the player a laptop?*/ }

// Menu
const char EquipmentMenuTitle[] PROGMEM = "BUY EQUIPMENT";

const MenuOption EquipmentMenuOptions[] PROGMEM =
{
  { EquipmentMenuOptionTable, GivePlayerTable },
  { EquipmentMenuOptionOrnament, GivePlayerOrnament },
  { EquipmentMenuOptionLaptop, GivePlayerLaptop },
};

const Menu EquipmentMenu PROGMEM =
{
	EquipmentMenuTitle,
	EquipmentMenuOptions,
	ArrayLength(EquipmentMenuOptions)
};

constexpr const static uint8_t EquipmentMenuLength =  ArrayLength(EquipmentMenuOptions);
constexpr const static uint8_t EquipmentMenuMinIndex =  0;
constexpr const static uint8_t EquipmentMenuMaxIndex =  EquipmentMenuLength - 1;