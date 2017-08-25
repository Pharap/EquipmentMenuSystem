#pragma once

#include <Arduboy2.h>
#include "Utility.h"

using MenuAction = void (*)(Player *);

struct MenuOption
{
  const char * Text;
  MenuAction Action;
};

struct Menu
{
  const char * Title;
  const MenuOption * Options;
  const uint8_t OptionsLength;
};

void DrawMenu(Arduboy2 & arduboy, const Menu & menu, const uint8_t & selected)
{
  arduboy.println(AsFlashStringHelper(pgm_read_word(&(menu.Title))));
  
  const uint8_t count = pgm_read_byte(&(menu.OptionsLength));
  const MenuOption * const entries = reinterpret_cast<const MenuOption *>(pgm_read_word(&(menu.Options)));
  
  for (uint8_t i = 0; i < count; ++i)
  {
	arduboy.print((i == selected) ? F("> ") : F("  "));
    arduboy.println(AsFlashStringHelper(pgm_read_word(&entries[i])));
  }
}