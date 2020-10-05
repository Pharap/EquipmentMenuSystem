#pragma once

#include <Arduboy2.h>
#include "Utility.h"

using MenuAction = void (*)(Player &);

struct MenuOption
{
	const char * Text;
	MenuAction Action;
};

struct Menu
{
	const char * Title;
	const MenuOption * Options;
	uint8_t OptionsLength;
};

inline void DrawMenu(Arduboy2 & arduboy, const Menu & menu, uint8_t selected)
{
	arduboy.println(asFlashStringHelper(menu.Title));

	for (uint8_t i = 0; i < menu.OptionsLength; ++i)
	{
		arduboy.print((i == selected) ? F("> ") : F("  "));
		arduboy.println(readFlashStringPointer(&menu.Options[i].Text));
	}
}

inline void DrawProgmemMenu(Arduboy2 & arduboy, const Menu & progmemMenu, uint8_t selected)
{
	Menu menu;
	memcpy_P(&menu, &progmemMenu, sizeof(Menu));

	DrawMenu(arduboy, menu, selected);
}

inline bool ApplyMenuAction(Player & player, const Menu & menu, uint8_t selected)
{
	if(selected > menu.OptionsLength)
		return false;

	MenuAction action = reinterpret_cast<MenuAction>(pgm_read_ptr(&menu.Options[selected].Action));
	action(player);

	return true;
}

inline bool ApplyProgmemMenuAction(Player & player, const Menu & progmemMenu, uint8_t selected)
{
	Menu menu;
	memcpy_P(&menu, &progmemMenu, sizeof(Menu));

	return ApplyMenuAction(player, menu, selected);
}
