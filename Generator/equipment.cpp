#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "gotoxy.h"
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"
#include "choice.h"
#include "stringLength.h"
#include "equipItem.h"

using namespace std;

void equipment()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int equipmentItem[5][500][3];
	string equipmentItemName[5][500];
	bool wasUsed[9999];
	int hasBeenPressed = 0;
afterItemUse:
	for (int g = 0; g < 9999; g++)
	{
		wasUsed[g] = false;
	}

	for (int eqx = 0; eqx < 5; eqx++)
	{
		for (int eqy = 0; eqy < 500; eqy++)
		{
			equipmentItem[eqx][eqy][0] = 0; // item quantity
			equipmentItem[eqx][eqy][1] = 0; // is item chosen or not
			equipmentItem[eqx][eqy][2] = 0; // item id
			equipmentItemName[eqx][eqy] = " ";  // item gfx
		}
	}

	draw(4, 0, 3); // draw equipment gui

	for (int eqy = 0; eqy < 500; eqy++)
	{
		for (int eqx = 0; eqx < 5; eqx++)
		{
			for (int g = 0; g < 9999; g++)
			{
				if (item[g] >= 1 and wasUsed[g] == false)
				{
					wasUsed[g] = true;
					equipmentItem[eqx][eqy][0] = item[g];
					equipmentItem[eqx][eqy][2] = g;
					break;
				}
			}
		}
	}

	equipmentItem[0][0][1] = 1; //after item use your selection goes back to the first item in eq
	int yDifference = 0; //since you can't display 9999 items in 24 item slots (6x4 eq) you have to have some y changing mechanism
equipmentManeuveringLoop:
	bool maxItemsLimitFlag = false;
	int eqy = 0;
	int eqx = 0;
	int slotCount = 0;
	int holder = yDifference * 5;
	while (maxItemsLimitFlag == false)
	{
		slotCount = 0;
		for (int g = 0; g < 9999; g++)
		{
			if (item[g] >= 1)
			{
				if (holder == 0)
				{
					draw(g + 1000, 6 + eqx * 17, 4 + (eqy) * 9);
					gotoxy(8 + (eqx * 17), 11 + (eqy) * 9);
					wcout << "              ";
					gotoxy(22 - stringLength(item[g]) + (eqx * 17), 11 + (eqy) * 9);
					wcout << equipmentItem[eqx][eqy + yDifference][0];

					gotoxy(12 + (eqx * 17), 11 + (eqy) * 9);

					//draw item choice gfx if any in the row are chosen
					if (equipmentItem[0][eqy + yDifference][1] == 1 or equipmentItem[1][eqy + yDifference][1] == 1 or equipmentItem[2][eqy + yDifference][1] == 1 or equipmentItem[3][eqy + yDifference][1] == 1 or equipmentItem[4][eqy + yDifference][1] == 1)
					{
						if (equipmentItem[eqx][eqy + yDifference][1] == 1) wcout << L"<V>";
						draw(5, 0, 7 + (eqy) * 9);
					}
					else
					{
						if (equipmentItem[eqx][eqy + yDifference][1] == 1) wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9);
						wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9 + 1);
						wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9 + 2);
						wcout << L"   ";
					}
					
					//after drawing choice go to the next slot
					if (eqx < 4) eqx++;
					else if (eqx == 4)
					{
						eqx = 0;
						eqy++;
					}

					slotCount++;
					if (slotCount > 24)
					{
						maxItemsLimitFlag = true;
						break;
					}
				}
				else if (holder > 0)
				{
					holder--;
				}
			}
			if (g == 9998) maxItemsLimitFlag = true; //if there's too many items, equipment function won't display any more
		}
	}

	//interaction with items in inventory loop
	for (int eqy = 0; eqy < 500; eqy++)
	{
		for (int eqx = 0; eqx < 5; eqx++)
		{
			if (equipmentItem[eqx][eqy][1] == 1)
			{
				if (equipmentItem[eqx][eqy][2] >= 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					equipItem(0, equipmentItem[eqx][eqy][2]);
				}
				gameGui(3);
				SetConsoleTextAttribute(hConsole, 112);
				while (true)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == 1 and hasBeenPressed != 1)
					{
						hasBeenPressed = 1;
						if (eqx > 0 and equipmentItem[eqx - 1][eqy][0] > 0)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[eqx - 1][eqy][1] = 1;
						}
						if (eqx == 0 and equipmentItem[4][eqy - 1][0] > 0 and eqy > 0)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[4][eqy - 1][1] = 1;
						}
						goto equipmentManeuveringLoop;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == 1 and hasBeenPressed != 2)
					{
						hasBeenPressed = 2;
						if (eqx < 4 and equipmentItem[eqx + 1][eqy][0] > 0)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[eqx + 1][eqy][1] = 1;
						}
						if (eqx >= 4 and equipmentItem[0][eqy + 1][0] > 0 and eqy < 500)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[0][eqy + 1][1] = 1;
						}
						goto equipmentManeuveringLoop;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) == 1 or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == 1 and hasBeenPressed != 3)
					{
						hasBeenPressed = 3;
						equipItem(1, equipmentItem[eqx][eqy][2]); //function in other file for equiping/using items
						gameGui(3);
						goto afterItemUse;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == 1 and hasBeenPressed != 4)
					{
						hasBeenPressed = 4;
						if (eqy > 0 and equipmentItem[eqx][eqy - 1][0] > 0)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[eqx][eqy - 1][1] = 1;
							if (yDifference > 0 and (eqy - yDifference == 0)) yDifference--;
						}
						goto equipmentManeuveringLoop;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1 and hasBeenPressed != 5)
					{
						hasBeenPressed = 5;
						if (eqy < 500 and equipmentItem[eqx][eqy + 1][0] > 0)
						{
							equipmentItem[eqx][eqy][1] = 0;
							equipmentItem[eqx][eqy + 1][1] = 1;
						}
						if (equipmentItem[eqx][eqy + 1][1] == 1 and (eqy - yDifference) == 4)
						{
							yDifference++;
						}
						goto equipmentManeuveringLoop;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == 1)
					{
						hasBeenPressed = 0;
						goto exit;
					}
					hasBeenPressed = 0;
				}
			}
		}
	}
	exit:
	SetConsoleTextAttribute(hConsole, 15);
}