#include "Player.h"
#include "Utility.h"
#include "Menu.h"
#include "EquipmentMenu.h"

Arduboy2 arduboy;
Player player;

void setup()
{
	arduboy.begin();
}

uint8_t menuIndex;

void loop()
{
  if(!arduboy.nextFrame()) return;

  arduboy.pollButtons();
  
  if(arduboy.justPressed(DOWN_BUTTON))
  {
  	if(menuIndex < EquipmentMenuMaxIndex)
  		++menuIndex;
  }

  if(arduboy.justPressed(UP_BUTTON))
  {
  	if(menuIndex > EquipmentMenuMinIndex)
  		--menuIndex;
  }

  arduboy.clear();
  DrawProgmemMenu(arduboy, EquipmentMenu, menuIndex);
  arduboy.display();
}
