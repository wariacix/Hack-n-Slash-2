#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
#include "fight.h"
#include "equipItem.h"
#include "gotoxy.h"
#include "draw.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"
#include "choice.h"
#include "stringLength.h"

using namespace std;

void equipmentSFML(sf::RenderWindow &window)
{
	int equipmentWidth = 10;
	int equipmentHeight = 6;
	int equipmentItem[10][500][3];
	string equipmentItemName[10][500];
	bool wasUsed[9999];
	int hasBeenPressed = 0;
	equipmentItem[0][0][1] = 1; //first item in eq is chosen by default
afterItemUse:
	for (int g = 0; g < 9999; g++)
	{
		wasUsed[g] = false;
	}

	for (int eqx = 0; eqx < equipmentWidth; eqx++)
	{
		for (int eqy = 0; eqy < 500; eqy++)
		{
			equipmentItem[eqx][eqy][0] = 0; // item quantity
			if (equipmentItem[eqx][eqy][1] != 1) equipmentItem[eqx][eqy][1] = 0;  // is item chosen or not
			equipmentItem[eqx][eqy][2] = 0; // item id
			equipmentItemName[eqx][eqy] = " ";  // item gfx
		}
	}

	for (int eqy = 0; eqy < 500; eqy++)
	{
		for (int eqx = 0; eqx < equipmentWidth; eqx++)
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

	sf::Texture tBottom, tTop, tRope, tSlot;
	tBottom.loadFromFile("Textures\\eqInterfaceBottom.png", sf::IntRect(0, 0, 320, 200));
	tTop.loadFromFile("Textures\\eqInterfaceTop.png", sf::IntRect(0, 0, 320, 200));
	tRope.loadFromFile("Textures\\eqInterfaceRope.png", sf::IntRect(0, 0, 320, 200));
	tSlot.loadFromFile("Textures\\eqSlot.png", sf::IntRect(0, 0, 15, 15));

	sf::Sprite eqInterfaceSprite, eqSlot;
	eqInterfaceSprite.setScale(5.f,5.f);
	eqInterfaceSprite.setPosition(0, 0);

	if (window.isOpen())
	{
		sf::Font font;
		font.loadFromFile("dpcomic.ttf");
		int yDifference = 0; //since you can't display 9999 items in 60 item slots (10x6 eq) you have to have some y changing mechanism
	equipmentManeuveringLoop:
		window.clear();
		eqInterfaceSprite.setScale(5.f, 5.f);
		eqInterfaceSprite.setTexture(tBottom);
		window.draw(eqInterfaceSprite);
		bool maxItemsLimitFlag = false;
		int eqy = 0;
		int eqx = 0;
		int slotCount = 0;
		int holder = yDifference * equipmentHeight;
		while (maxItemsLimitFlag == false)
		{
			slotCount = 0;
			for (int g = 0; g < 9999; g++)
			{
				if (item[g] >= 1)
				{
					if (holder == 0)
					{
						bool choiceFlag = false;
						for (int i = 0; i < equipmentWidth; i++) if (equipmentItem[i][eqy + yDifference][1] == 1) choiceFlag = true;

						//draw item choice gfx if any in the row are chosen
						if (equipmentItem[eqx][eqy + yDifference][1] == 1 and choiceFlag == true)
						{
							eqSlot.setTexture(tSlot);
							eqSlot.setColor(sf::Color::Green);
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy + yDifference) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);
							eqSlot.setColor(sf::Color::White);

							sf::Texture tItem;
							sf::Sprite sItem;
							tItem.loadFromFile("Textures\\Items\\" + to_string(equipmentItem[eqx][eqy + yDifference][2]) + ".png", sf::IntRect(0, 0, 12, 12));
							sItem.setTexture(tItem);
							sItem.setScale(5.f, 5.f);
							sItem.setPosition(185.f + ((eqx) * 75.f), 145.f + ((eqy + yDifference) * 75.f));
							window.draw(sItem);

							sf::Text text;
							text.setFont(font);
							text.setFillColor(sf::Color::White);
							text.setOutlineColor(sf::Color::Black);
							text.setOutlineThickness(1.f);
							text.setCharacterSize(24);
							text.setPosition(243.f + ((eqx) * 75.f) - 10 * stringLength(equipmentItem[eqx][eqy + yDifference][0]), 180.f + ((eqy + yDifference) * 75.f));
							text.setString(to_string(equipmentItem[eqx][eqy + yDifference][0]));
							window.draw(text);
						}
						else
						{
							eqSlot.setTexture(tSlot);
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy + yDifference) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);

							sf::Texture tItem;
							sf::Sprite sItem;
							tItem.loadFromFile("Textures\\Items\\" + to_string(equipmentItem[eqx][eqy + yDifference][2]) + ".png", sf::IntRect(0, 0, 12, 12));
							sItem.setTexture(tItem);
							sItem.setScale(5.f, 5.f);
							sItem.setPosition(185.f + ((eqx) * 75.f), 145.f + ((eqy + yDifference) * 75.f));
							window.draw(sItem);

							sf::Text text;
							text.setFont(font);
							text.setFillColor(sf::Color::White);
							text.setOutlineColor(sf::Color::Black);
							text.setOutlineThickness(1.f);
							text.setCharacterSize(24);
							text.setPosition(243.f + ((eqx) * 75.f) - 10 * stringLength(equipmentItem[eqx][eqy + yDifference][0]), 180.f + ((eqy + yDifference) * 75.f));
							text.setString(to_string(equipmentItem[eqx][eqy + yDifference][0]));
							window.draw(text);
						}
						//after drawing choice go to the next slot
						if (eqx < equipmentWidth - 1) eqx++;
						else if (eqx == equipmentWidth - 1)
						{
							eqx = 0;
							eqy++;
						}

						if (equipmentItem[eqx][eqy + yDifference][0] >= 1)
						{
							eqSlot.setTexture(tSlot);
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy + yDifference) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);
						}

						slotCount++;
						if (slotCount > (equipmentHeight * equipmentWidth))
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
		eqInterfaceSprite.setTexture(tTop);
		eqInterfaceSprite.setScale(5.f, 5.f);
		eqInterfaceSprite.setPosition(0, 0);
		window.draw(eqInterfaceSprite);

		//Check for mouse position and change item choice accordingly
		for (int eqy = 0; eqy < 500; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				if (mouse.x >= 180.f + (eqx * 75) and mouse.x <= 255.f + (eqx * 75) and mouse.y >= 140.f + (eqy * 75) and mouse.y <= 214.f + (eqy * 75) and equipmentItem[eqx][eqy][0] > 0)
				{
					for (int x = 0; x < equipmentWidth; x++)
					{
						for (int y = 0; y < 500; y++)
						{
							if (equipmentItem[x][y][1] == 1) equipmentItem[x][y][1] = 0;
						}
					}
					equipmentItem[eqx][eqy][1] = 1;
				}
			}
		}


		//interaction with items in inventory loop
		for (int eqy = 0; eqy < 500; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				if (equipmentItem[eqx][eqy][1] == 1)
				{
					if (equipmentItem[eqx][eqy][2] >= 0)
					{
						equipItemSFML(window, 0, equipmentItem[eqx][eqy][2], eqx, eqy + yDifference);
						window.display();
					}
					//gameGui
					while (true)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true)
						{
							hasBeenPressed = 1;
							if (eqx > 0 and equipmentItem[eqx - 1][eqy][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx - 1][eqy][1] = 1;
							}
							if (eqx == 0 and equipmentItem[equipmentWidth - 1][eqy - 1][0] > 0 and eqy > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[equipmentWidth - 1][eqy - 1][1] = 1;
							}
							Sleep(40);
							goto equipmentManeuveringLoop;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true)
						{
							hasBeenPressed = 2;
							if (eqx < equipmentWidth - 1 and equipmentItem[eqx + 1][eqy][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx + 1][eqy][1] = 1;
							}
							if (eqx >= equipmentWidth - 1 and equipmentItem[0][eqy + 1][0] > 0 and eqy < 500)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[0][eqy + 1][1] = 1;
							}
							Sleep(40);
							goto equipmentManeuveringLoop;
						}
						else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == true)
						{
							hasBeenPressed = 3;
							equipItemSFML(window, 1, equipmentItem[eqx][eqy][2], eqx, eqy); //function in other file for equipping/using items
							//gameGui
							Sleep(40);
							goto afterItemUse;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == 1)
						{
							hasBeenPressed = 4;
							if (eqy > 0 and equipmentItem[eqx][eqy - 1][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx][eqy - 1][1] = 1;
								if (yDifference > 0 and (eqy - yDifference == 0)) yDifference--;
							}
							Sleep(40);
							goto equipmentManeuveringLoop;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1)
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
							Sleep(40);
							goto equipmentManeuveringLoop;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == 1)
						{
							hasBeenPressed = 0;
							goto exit;
						}
						else goto equipmentManeuveringLoop;
						hasBeenPressed = 0;
					}
				}
			}
		}
	}
exit:;
}