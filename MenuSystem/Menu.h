#pragma once

//
// MIT License
// 
// Copyright (c) 2020 Pharap (@Pharap)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

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
