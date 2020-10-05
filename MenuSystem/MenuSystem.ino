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
  
  if(arduboy.justPressed(A_BUTTON))
  {
	ApplyProgmemMenuAction(player, EquipmentMenu, menuIndex);
  }

  arduboy.clear();
  DrawProgmemMenu(arduboy, EquipmentMenu, menuIndex);
  arduboy.display();
}
