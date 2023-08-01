#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include "Player.h"
#include "equipment.h"
#include "variables.h"
#include "choice.h"
#include "General.h"
#include "stringLength.h"

using namespace hns;

int hns::Item::getItemCount()
{
	return numOfItems;
}
int hns::Item::getItemId()
{
	return id;
}
void hns::Item::addItemCount(int add)
{
	numOfItems += add;
}
void hns::Item::setItemCount(int set)
{
	numOfItems = set;
}
int hns::Item::getItemAddedHp()
{
	return addedHp;
}
int hns::Item::getItemAddedMp()
{
	return addedMp;
}
int hns::Item::getItemHpRegen()
{
	return hpRegen;
}
int hns::Item::getItemMpRegen()
{
	return mpRegen;
}
int hns::Item::getItemDmg()
{
	return dmg;
}
int hns::Item::getItemDef()
{
	return def;
}
int hns::Item::getItemStrReq()
{
	return strReq;
}
int hns::Item::getItemInReq()
{
	return inReq;
}
int hns::Item::getItemLvlReq()
{
	return lvlReq;
}
int hns::Item::getItemMpReq()
{
	return mpReq;
}
int hns::Item::getItemValue()
{
	return value;
}
sf::Color hns::Item::getItemColor()
{
	return color;
}
std::wstring hns::Item::getItemName()
{
	return itemName;
}

int hns::Equipment::getNumOfItems()
{
	return numOfItems;
}

void hns::Equipment::addNumOfItems(int add)
{
	numOfItems += add;
}

void hns::Equipment::setItem(Item item)
{
	eqItem[getNumOfItems()] = item;
}

void hns::Equipment::drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring name, int& k, int x, int y, sf::Color color)
{
	text.setFillColor(color);

	text.setCharacterSize(24);
	text.setPosition(259.f + x, 138.f + y + (k * 25));
	text.setString(name);
	window.draw(text);
	k++;
}

void hns::Equipment::drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring statStr, int& k, int value, int x, int y, sf::Color green, sf::Color red)
{
	if (value >= 0) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + std::to_wstring(value));
	window.draw(text);
	k++;
}

void hns::Equipment::drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring statStr, int& k, int requiredVal, int x, int y, int value, sf::Color green, sf::Color red)
{
	if (value >= requiredVal) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + std::to_wstring(requiredVal));
	window.draw(text);
	k++;
}

void hns::Equipment::addItem(int idVar = 0, int howManyItems = 1)
{
	std::wstring load = loadFileString(eqName);
	std::wstring stats[16];

	int a = 0;
	bool hasItemStatBeenRead = false;
	bool addedItem = false;

	for (int i = 0; i < load.size(); i++)
	{
		if (hasItemStatBeenRead == true)
		{
			for (int u = 0; u < 16; u++) stats[u] = L"";
			hasItemStatBeenRead = false;
		}

		if (load[i] == *L",")
		{
			a++;
		}
		else if (load[i] == *L";")
		{
			if (idVar == std::stoi(stats[0]))
			{
				for (int u = 0; u < numOfItems; u++)
				{
					if (eqItem[u].getItemId() == idVar and addedItem == false)
					{
						eqItem[u].addItemCount(howManyItems);
						addedItem = true;
					}
					else if (u == numOfItems - 1 and addedItem == false)
					{
						setItem(Item(std::stoi(stats[0]), std::stoi(stats[1]), std::stoi(stats[2]), std::stoi(stats[3]),
									 std::stoi(stats[4]), std::stoi(stats[5]), std::stoi(stats[6]), std::stoi(stats[7]),
									 std::stoi(stats[8]), std::stoi(stats[9]), std::stoi(stats[10]), std::stoi(stats[11]), howManyItems,
									 std::stoi(stats[12]), std::stoi(stats[13]), std::stoi(stats[14]), stats[15]));
						addNumOfItems(1);
						addedItem = true;
					}
				}
			}

			i++;
			a = 0;
			hasItemStatBeenRead = true;
		}
		else stats[a] = stats[a] + load[i];
	}
}

void hns::Equipment::updateStats(Player &player)
{
	player.maxhp = 100 + equippedItem[0].getItemAddedHp() + equippedItem[1].getItemAddedHp() + equippedItem[2].getItemAddedHp() + equippedItem[3].getItemAddedHp() + equippedItem[4].getItemAddedHp() + equippedItem[5].getItemAddedHp() + equippedItem[6].getItemAddedHp() + equippedItem[7].getItemAddedHp();
	player.maxmp = 20 + equippedItem[0].getItemAddedMp() + equippedItem[1].getItemAddedMp() + equippedItem[2].getItemAddedMp() + equippedItem[3].getItemAddedMp() + equippedItem[4].getItemAddedMp() + equippedItem[5].getItemAddedMp() + equippedItem[6].getItemAddedMp() + equippedItem[7].getItemAddedMp();
	player.hpRegen = 1 + equippedItem[0].getItemHpRegen() + equippedItem[1].getItemHpRegen() + equippedItem[2].getItemHpRegen() + equippedItem[3].getItemHpRegen() + equippedItem[4].getItemHpRegen() + equippedItem[5].getItemHpRegen() + equippedItem[6].getItemHpRegen() + equippedItem[7].getItemHpRegen();
	player.mpRegen = 1 + equippedItem[0].getItemMpRegen() + equippedItem[1].getItemMpRegen() + equippedItem[2].getItemMpRegen() + equippedItem[3].getItemMpRegen() + equippedItem[4].getItemMpRegen() + equippedItem[5].getItemMpRegen() + equippedItem[6].getItemMpRegen() + equippedItem[7].getItemMpRegen();
	player.dmg = equippedItem[0].getItemDmg() + equippedItem[1].getItemDmg() + equippedItem[2].getItemDmg() + equippedItem[3].getItemDmg() + equippedItem[4].getItemDmg() + equippedItem[5].getItemDmg() + equippedItem[6].getItemDmg() + equippedItem[7].getItemDmg();
	player.def = equippedItem[0].getItemDef() + equippedItem[1].getItemDef() + equippedItem[2].getItemDef() + equippedItem[3].getItemDef() + equippedItem[4].getItemDef() + equippedItem[5].getItemDef() + equippedItem[6].getItemDef() + equippedItem[7].getItemDef();
}

void hns::Equipment::viewEquipment(sf::RenderWindow &window, Player &player)
{
	hns::Interface eqUI(mainPlayer, 0, 0, 320, 200, "eqInterfaceTop");
	for (int i = 0; i < numOfItems; i++)
	{
		if (eqItem[i].getItemId() == 100)
		{
			eqItem[i].setItemCount(player.gold);
		}
	}
	int equipmentItem[10][200][3];
	std::string equipmentItemName[10][200];
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
		for (int eqy = 0; eqy < 200; eqy++)
		{
			equipmentItem[eqx][eqy][0] = 0; // item quantity
			if (equipmentItem[eqx][eqy][1] != 1) equipmentItem[eqx][eqy][1] = 0;  // is item chosen or not
			equipmentItem[eqx][eqy][2] = 0; // item id
			equipmentItemName[eqx][eqy] = " ";  // item gfx
		}
	}

	for (int eqy = 0; eqy < 200; eqy++)
	{
		for (int eqx = 0; eqx < equipmentWidth; eqx++)
		{
			for (int g = 0; g < 9999; g++)
			{
				if (eqItem[g].getItemCount() >= 1 and wasUsed[g] == false)
				{
					wasUsed[g] = true;
					equipmentItem[eqx][eqy][0] = eqItem[g].getItemCount();
					equipmentItem[eqx][eqy][2] = eqItem[g].getItemId();
					break;
				}
			}
		}
	}

	sf::Texture tBottom, tTop, tSlot;
	tBottom.loadFromFile("Textures\\eqInterfaceBottom.png", sf::IntRect(0, 0, 320, 200));
	tTop.loadFromFile("Textures\\eqInterfaceTop.png", sf::IntRect(0, 0, 320, 200));
	tSlot.loadFromFile("Textures\\eqSlot.png", sf::IntRect(0, 0, 15, 15));

	sf::Sprite eqSlot;

	if (window.isOpen())
	{
		sf::Font font;
		font.loadFromFile("dpcomic.ttf");
		int yDifference = 0; //since you can't display 9999 items in 60 item slots (10x6 eq) you have to have some y changing mechanism
	equipmentManeuveringLoop:
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(1);
			}
		}
		window.clear();
		eqUI.changeSprite(tBottom);
		eqUI.Draw(window, player);
		bool maxItemsLimitFlag = false;
		int eqy = 0;
		int eqx = 0;
		int slotCount = 0;
		int holder = yDifference * equipmentHeight;

		for (int x = 0; x < equipmentWidth; x++)
		{
			for (int y = 0; y < equipmentHeight; y++)
			{
				eqSlot.setColor(sf::Color::White);
				eqSlot.setTexture(tSlot);
				eqSlot.setPosition(180.f + ((x) * 75.f), 140.f + ((y) * 75.f));
				eqSlot.setScale(5.f, 5.f);
				window.draw(eqSlot);
			}
		}

		while (maxItemsLimitFlag == false)
		{
			slotCount = 0;
			for (int g = 0; g < 9999; g++)
			{
				if (eqItem[g].getItemCount() >= 1)
				{
					if (holder == 0)
					{
						bool choiceFlag = false;
						for (int i = 0; i < equipmentWidth; i++) if (equipmentItem[i][eqy + yDifference][1] == 1) choiceFlag = true;

						//draw item choice gfx if any in the row are chosen
						if (equipmentItem[eqx][eqy + yDifference][1] == 1 and choiceFlag == true)
						{
							eqSlot.setTexture(tSlot);
							eqSlot.setColor(sf::Color{ 0,255,0,255 });
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);
							eqSlot.setColor(sf::Color::White);

							drawItemSprite(window, 185.f + ((eqx) * 75.f), 145.f + ((eqy) * 75.f), equipmentItem[eqx][eqy + yDifference][2]);

							sf::Text text;
							text.setFont(font);
							text.setFillColor(sf::Color::White);
							text.setOutlineColor(sf::Color::Black);
							text.setOutlineThickness(2.f);
							text.setCharacterSize(24);
							text.setPosition(243.f + ((eqx) * 75.f) - 10 * stringLength(equipmentItem[eqx][eqy + yDifference][0]), 180.f + ((eqy) * 75.f));
							text.setString(std::to_string(equipmentItem[eqx][eqy + yDifference][0]));
							window.draw(text);
						}
						else
						{
							eqSlot.setTexture(tSlot);
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);

							drawItemSprite(window, 185.f + ((eqx) * 75.f), 145.f + ((eqy) * 75.f), equipmentItem[eqx][eqy + yDifference][2]);

							sf::Text text;
							text.setFont(font);
							text.setFillColor(sf::Color::White);
							text.setOutlineColor(sf::Color::Black);
							text.setOutlineThickness(2.f);
							text.setCharacterSize(24);
							text.setPosition(243.f + ((eqx) * 75.f) - 10 * stringLength(equipmentItem[eqx][eqy + yDifference][0]), 180.f + ((eqy) * 75.f));
							text.setString(std::to_string(equipmentItem[eqx][eqy + yDifference][0]));
							window.draw(text);
						}
						//after drawing choice go to the next slot
						if (eqx < equipmentWidth - 1) eqx++;
						else if (eqx == equipmentWidth - 1)
						{
							eqx = 0;
							eqy++;
						}

						slotCount++;
						if (slotCount > ((equipmentHeight * equipmentWidth - 1)))
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
		eqUI.changeSprite(tTop);
		eqUI.Draw(window, player);

		//Drawing equipped items
		//WEAPON
		drawItemSprite(window, 1210, 630, equippedItem[0].getItemId());

		//ARMOR-
		drawItemSprite(window, 1210, 265, equippedItem[1].getItemId());

		//SHIELD-
		drawItemSprite(window, 1435, 170, equippedItem[2].getItemId());

		//BOOTS
		drawItemSprite(window, 1325, 845, equippedItem[3].getItemId());

		//HELMET
		drawItemSprite(window, 1325, 95, equippedItem[4].getItemId());

		//NECKLACE
		drawItemSprite(window, 1210, 170, equippedItem[5].getItemId());

		//RING 1
		drawItemSprite(window, 1210, 810, equippedItem[6].getItemId());

		//RING 2
		drawItemSprite(window, 1435, 810, equippedItem[7].getItemId());

		//Check for mouse position and change item choice accordingly
		for (int eqy = 0; eqy < 200; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				if (mouse.x >= 180.f + (eqx * 75) and mouse.x <= 255.f + (eqx * 75) and mouse.y >= 140.f + ((eqy + yDifference) * 75) and mouse.y <= 214.f + ((eqy + yDifference) * 75) and equipmentItem[eqx][eqy + yDifference][0] > 0)
				{
					for (int x = 0; x < equipmentWidth; x++)
					{
						for (int y = 0; y < 200; y++)
						{
							if (equipmentItem[x][y][1] == 1) equipmentItem[x][y][1] = 0;
						}
					}
					equipmentItem[eqx][eqy - yDifference][1] = 1;
				}
			}
		}


		//interaction with items in inventory loop
		for (int eqy = 0; eqy < 200; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				if (equipmentItem[eqx][eqy][1] == 1)
				{
					if (equipmentItem[eqx][eqy][2] >= 0)
					{
						int offsetX = 180, offsetY = 140;
						sf::Vector2i mouse = sf::Mouse::getPosition(window);
						if (mouse.x >= 1210.f && mouse.y >= 630.f && mouse.x <= 1285.f && mouse.y <= 705.f)
						{
							viewItemStats(window, equippedItem[0], 1210 - offsetX, 630 - offsetY);
						}
						else if (mouse.x >= 1210.f && mouse.y >= 265.f && mouse.x <= 1285.f && mouse.y <= 340.f)
						{
							viewItemStats(window, equippedItem[1], 1210 - offsetX, 265 - offsetY);
						}
						else if (mouse.x >= 1435.f && mouse.y >= 170.f && mouse.x <= 1510.f && mouse.y <= 245.f)
						{
							viewItemStats(window, equippedItem[2], 1435 - offsetX, 170 - offsetY);
						}
						else if (mouse.x >= 1325.f && mouse.y >= 845.f && mouse.x <= 1400.f && mouse.y <= 920.f)
						{
							viewItemStats(window, equippedItem[3], 1325 - offsetX, 845 - offsetY);
						}
						else if (mouse.x >= 1325.f && mouse.y >= 95.f && mouse.x <= 1400.f && mouse.y <= 170.f)
						{
							viewItemStats(window, equippedItem[4], 1325 - offsetX, 95 - offsetY);
						}
						else if (mouse.x >= 1210.f && mouse.y >= 170.f && mouse.x <= 1285.f && mouse.y <= 245.f)
						{
							viewItemStats(window, equippedItem[5], 1210 - offsetX, 170 - offsetY);
						}
						else if (mouse.x >= 1210.f && mouse.y >= 810.f && mouse.x <= 1285.f && mouse.y <= 885.f)
						{
							viewItemStats(window, equippedItem[6], 1210 - offsetX, 810 - offsetY);
						}
						else if (mouse.x >= 1435.f && mouse.y >= 810.f && mouse.x <= 1510.f && mouse.y <= 885.f)
						{
							viewItemStats(window, equippedItem[6], 1435 - offsetX, 810 - offsetY);
						}

						int whichItem = 0;
						for (int i = 0; i < 9999; i++)
						{
							if (equipmentItem[eqx][eqy][2] == eqItem[i].getItemId()) whichItem = i;
						}
						viewItemStats(window, eqItem[whichItem], eqx * 75, (eqy - yDifference) * 75);
					}
					while (true)
					{
						hns::Cursor::Draw(window);
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true && window.hasFocus())
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
								if (yDifference > 0 and (eqy - yDifference == 0)) yDifference--;
							}
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true && window.hasFocus())
						{
							hasBeenPressed = 2;
							if (eqx < equipmentWidth - 1 and equipmentItem[eqx + 1][eqy][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx + 1][eqy][1] = 1;
							}
							if (eqx >= equipmentWidth - 1 and equipmentItem[0][eqy + 1][0] > 0 and eqy < 200)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[0][eqy + 1][1] = 1;
							}
							if (equipmentItem[0][eqy + 1][1] == 1 and (eqy - yDifference) == equipmentHeight - 1)
							{
								yDifference++;
							}
							Sleep(80);
						}
						else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == true && window.hasFocus())
						{
							hasBeenPressed = 3;
							int whichItem = 0;
							for (int i = 0; i < 9999; i++)
							{
								if (equipmentItem[eqx][eqy][2] == eqItem[i].getItemId()) whichItem = i;
							}
							equipItem(eqItem[whichItem], player); //function in other file for equipping/using items
							updateStats(player);
							window.display();
							Sleep(70);
							goto afterItemUse;
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == 1 && window.hasFocus())
						{
							hasBeenPressed = 4;
							if (eqy > 0 and equipmentItem[eqx][eqy - 1][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx][eqy - 1][1] = 1;
								if (yDifference > 0 and (eqy - yDifference == 0)) yDifference--;
							}
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1 && window.hasFocus())
						{
							hasBeenPressed = 5;
							if (eqy < 200 and equipmentItem[eqx][eqy + 1][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx][eqy + 1][1] = 1;
							}
							if (equipmentItem[eqx][eqy + 1][1] == 1 and (eqy - yDifference) == equipmentHeight - 1)
							{
								yDifference++;
							}
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == 1 && window.hasFocus())
						{
							hasBeenPressed = 0;
							goto exit;
						}
						window.display();
						goto equipmentManeuveringLoop;
						hasBeenPressed = 0;
					}
				}
			}
		}
	}
exit:;
}

void hns::Shop::viewEquipment(sf::RenderWindow& window, Player& player, Equipment& playerEq)
{
	hns::Interface shopUI(mainPlayer,0,0,320,200,"interface");
	for (int i = 0; i < numOfItems; i++)
	{
		if (eqItem[i].getItemId() == 100)
		{
			eqItem[i].setItemCount(player.gold);
		}
	}
	int equipmentItem[10][200][3];
	std::string equipmentItemName[10][200];
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
		for (int eqy = 0; eqy < 200; eqy++)
		{
			equipmentItem[eqx][eqy][0] = 0; // item quantity
			if (equipmentItem[eqx][eqy][1] != 1) equipmentItem[eqx][eqy][1] = 0;  // is item chosen or not
			equipmentItem[eqx][eqy][2] = 0; // item id
			equipmentItemName[eqx][eqy] = " ";  // item gfx
		}
	}

	for (int eqy = 0; eqy < 200; eqy++)
	{
		for (int eqx = 0; eqx < equipmentWidth; eqx++)
		{
			for (int g = 0; g < 9999; g++)
			{
				if (eqItem[g].getItemCount() >= 1 and wasUsed[g] == false)
				{
					wasUsed[g] = true;
					equipmentItem[eqx][eqy][0] = eqItem[g].getItemCount();
					equipmentItem[eqx][eqy][2] = eqItem[g].getItemId();
					break;
				}
			}
		}
	}

	sf::Texture tBottom, tTop, tSlot;
	tBottom.loadFromFile("Textures\\"+ bottomTxt +".png", sf::IntRect(0, 0, 320, 200));
	tTop.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 320, 200));
	tSlot.loadFromFile("Textures\\eqSlot.png", sf::IntRect(0, 0, 15, 15));

	sf::Sprite eqSlot;

	if (window.isOpen())
	{
		sf::Font font;
		font.loadFromFile("dpcomic.ttf");
		int yDifference = 0; //since you can't display 9999 items in 60 item slots (10x6 eq) you have to have some y changing mechanism
	equipmentManeuveringLoop:
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(1);
			}
		}
		window.clear();

		shopUI.changeSprite(tBottom);
		shopUI.Draw(window, player);
		bool maxItemsLimitFlag = false;
		int eqy = 0;
		int eqx = 0;
		int slotCount = 0;
		int holder = yDifference * equipmentHeight;

		for (int x = 0; x < equipmentWidth; x++)
		{
			for (int y = 0; y < equipmentHeight; y++)
			{
				eqSlot.setColor(sf::Color::White);
				eqSlot.setTexture(tSlot);
				eqSlot.setPosition(180.f + ((x) * 75.f), 140.f + ((y) * 75.f));
				eqSlot.setScale(5.f, 5.f);
				window.draw(eqSlot);
			}
		}

		while (maxItemsLimitFlag == false)
		{
			slotCount = 0;
			for (int g = 0; g < 9999; g++)
			{
				if (eqItem[g].getItemCount() >= 1)
				{
					if (holder == 0)
					{
						bool choiceFlag = false;
						for (int i = 0; i < equipmentWidth; i++) if (equipmentItem[i][eqy + yDifference][1] == 1) choiceFlag = true;

						//draw item choice gfx if any in the row are chosen
						if (equipmentItem[eqx][eqy + yDifference][1] == 1 and choiceFlag == true)
						{
							eqSlot.setColor(sf::Color{ 0,255,0,255 });
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);
							eqSlot.setColor(sf::Color::White);

							drawItemSprite(window, 185.f + ((eqx) * 75.f), 145.f + ((eqy) * 75.f), equipmentItem[eqx][eqy + yDifference][2]);
						}
						else
						{
							eqSlot.setPosition(180.f + ((eqx) * 75.f), 140.f + ((eqy) * 75.f));
							eqSlot.setScale(5.f, 5.f);
							window.draw(eqSlot);

							drawItemSprite(window, 185.f + ((eqx) * 75.f), 145.f + ((eqy) * 75.f), equipmentItem[eqx][eqy + yDifference][2]);
						}
						//after drawing choice go to the next slot
						if (eqx < equipmentWidth - 1) eqx++;
						else if (eqx == equipmentWidth - 1)
						{
							eqx = 0;
							eqy++;
						}

						slotCount++;
						if (slotCount > ((equipmentHeight * equipmentWidth - 1)))
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
		shopUI.changeSprite(tTop);
		shopUI.Draw(window, player);

		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(2.f);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Yellow);
		text.setString("Gold: " + std::to_string(player.gold));
		text.setPosition(20.f, 8.f);
		window.draw(text);

		//Check for mouse position and change item choice accordingly
		for (int eqy = 0; eqy < 200; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				if (mouse.x >= 180.f + (eqx * 75) and mouse.x <= 255.f + (eqx * 75) and mouse.y >= 140.f + ((eqy + yDifference) * 75) and mouse.y <= 214.f + ((eqy + yDifference) * 75) and equipmentItem[eqx][eqy + yDifference][0] > 0)
				{
					for (int x = 0; x < equipmentWidth; x++)
					{
						for (int y = 0; y < 200; y++)
						{
							if (equipmentItem[x][y][1] == 1) equipmentItem[x][y][1] = 0;
						}
					}
					equipmentItem[eqx][eqy - yDifference][1] = 1;
				}
			}
		}


		//interaction with items in inventory loop
		for (int eqy = 0; eqy < 200; eqy++)
		{
			for (int eqx = 0; eqx < equipmentWidth; eqx++)
			{
				if (equipmentItem[eqx][eqy][1] == 1)
				{
					shopUI.Draw(window, player);
					if (equipmentItem[eqx][eqy][2] >= 0)
					{
						int whichItem = 0;
						for (int i = 0; i < 9999; i++)
						{
							if (equipmentItem[eqx][eqy][2] == eqItem[i].getItemId()) whichItem = i;
						}
						viewItemStats(window, eqItem[whichItem], eqx * 75, (eqy - yDifference) * 75);
					}
					while (true)
					{
						hns::Cursor::Draw(window);
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
								if (yDifference > 0 and (eqy - yDifference == 0)) yDifference--;
							}
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true)
						{
							hasBeenPressed = 2;
							if (eqx < equipmentWidth - 1 and equipmentItem[eqx + 1][eqy][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx + 1][eqy][1] = 1;
							}
							if (eqx >= equipmentWidth - 1 and equipmentItem[0][eqy + 1][0] > 0 and eqy < 200)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[0][eqy + 1][1] = 1;
							}
							if (equipmentItem[0][eqy + 1][1] == 1 and (eqy - yDifference) == equipmentHeight - 1)
							{
								yDifference++;
							}
							Sleep(80);
						}
						else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == true)
						{
							hasBeenPressed = 3;
							int whichItem = 0;
							for (int i = 0; i < 9999; i++)
							{
								if (equipmentItem[eqx][eqy][2] == eqItem[i].getItemId()) whichItem = i;
							}
							buyItem(player, eqItem[whichItem], playerEq); //function in other file for equipping/using items
							updateStats(player);
							window.display();
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
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1)
						{
							hasBeenPressed = 5;
							if (eqy < 200 and equipmentItem[eqx][eqy + 1][0] > 0)
							{
								equipmentItem[eqx][eqy][1] = 0;
								equipmentItem[eqx][eqy + 1][1] = 1;
							}
							if (equipmentItem[eqx][eqy + 1][1] == 1 and (eqy - yDifference) == equipmentHeight - 1)
							{
								yDifference++;
							}
							Sleep(80);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == 1)
						{
							hasBeenPressed = 0;
							goto exit;
						}
						window.display();
						goto equipmentManeuveringLoop;
						hasBeenPressed = 0;
					}
				}
			}
		}
	}
exit:;
}

void hns::Equipment::drawItemSprite(sf::RenderWindow &window, int x, int y, int id)
{
	if (id != -1)
	{
		sf::Texture tItem;
		sf::Sprite sItem;
		tItem.loadFromFile("Textures\\Items\\" + std::to_string(id) + ".png", sf::IntRect(0, 0, 12, 12));
		sItem.setTexture(tItem);
		sItem.setScale(5.f, 5.f);
		sItem.setPosition(x, y);
		window.draw(sItem);
	}
}

void hns::Equipment::itemSwapping(Item& item, int type)
{
	if (equippedItem[type - 1].getItemId() != -1) addItem(equippedItem[type - 1].getItemId(), 1);
	equippedItem[type - 1] = item;
	if (item.getItemCount() > 1) item.addItemCount(-1);
	else itemDeletion(item.getItemId());
}

void hns::Equipment::itemDeletion(int id)
{
	for (int i = 0; i < getNumOfItems(); i++)
	{
		if (eqItem[i].getItemId() == id)
		{
			eqItem[i] = Item();
			if (i != getNumOfItems()) //if the item is NOT last in eq
			{
				for (int a = i; a < i + std::abs(i - getNumOfItems()); a++)
				{
					eqItem[i + (a - i)] = eqItem[i + 1 + (a - i)];
				}
			}
		}
	}
}

using namespace std;

void hns::Equipment::equipItem(Item &item, Player &player)
{
	if (item.getItemId() >= 0 and item.getItemId() < 1000)
	{
		switch (item.getItemId())
		{
		case 0:
			mainPlayer.hp = mainPlayer.hp + 25;
			if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 1:
			mainPlayer.hp = mainPlayer.hp + 50;
			if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 2:
			mainPlayer.hp = mainPlayer.hp + 100;
			if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 3:
			mainPlayer.hp = mainPlayer.hp + 200;
			if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 4:
			mainPlayer.hp = mainPlayer.hp + (0.5 * mainPlayer.maxhp);
			if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 5:
			mainPlayer.mp = mainPlayer.mp + 10;
			if (mainPlayer.mp > mainPlayer.maxmp) mainPlayer.mp = mainPlayer.maxmp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		case 6:
			mainPlayer.mp = mainPlayer.mp + 20;
			if (mainPlayer.mp > mainPlayer.maxmp) mainPlayer.mp = mainPlayer.maxmp;
			if (item.getItemCount() > 1) item.addItemCount(-1);
			else itemDeletion(item.getItemId());
			break;
		}
	}
	else if (item.getItemId() >= 1000 and item.getItemId() < 7000 and checkItemRequirements(item, player) == true)
	{
		itemSwapping(item, item.getItemId() / 1000);
	}
	else if (item.getItemId() >= 7000 and item.getItemId() < 8000 and checkItemRequirements(item, player) == true) //Ring slot 1 & 2
	{
		if (equippedItem[6].getItemId() == -1) itemSwapping(item, 7);
		else if (equippedItem[7].getItemId() == -1) itemSwapping(item, 8);
		else
		{
			if (rand() % 2 == 0) itemSwapping(item, 7);
			else itemSwapping(item, 8);
		}
	}
}

bool hns::Equipment::checkItemRequirements(Item item, Player& player)
{
	if (item.getItemInReq() <= player.in and item.getItemLvlReq() <= player.lvl and item.getItemStrReq() <= player.str and item.getItemMpReq() <= player.maxmp) return true;
	else false;
}

void hns::Equipment::viewItemStats(sf::RenderWindow& window, Item &item, int x, int y)
{
	sf::Font font;
	font.loadFromFile("dpcomic.ttf");


	sf::Text text;
	text.setFont(font);
	text.setFillColor(item.getItemColor());
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1.f);
	text.setCharacterSize(24);

	int textHeight = 0;
	int textWidth = 0;

	if (item.getItemName() != L"")
	{
		wstring str = item.getItemName();
		wchar_t* ptr = _wcsdup(item.getItemName().c_str());
		textWidth = std::wcslen(ptr);
	}
	if (item.getItemAddedHp() != 0) textHeight++;
	if (item.getItemAddedMp() != 0) textHeight++;
	if (item.getItemHpRegen() != 0) textHeight++;
	if (item.getItemMpRegen() != 0) textHeight++;
	if (item.getItemDmg() != 0) textHeight++;
	if (item.getItemDef() != 0) textHeight++;
	if (item.getItemStrReq() != 0) textHeight++;
	if (item.getItemInReq() != 0) textHeight++;
	if (item.getItemLvlReq() != 0) textHeight++;
	if (item.getItemMpReq() != 0) textHeight++;
	if (item.getItemValue() != 0) textHeight++;


	//Item stats black backside
	sf::RectangleShape backside;
	backside.setScale(1.f, 1.f);
	backside.setSize(sf::Vector2f((textWidth * 8.85) + 44, 36 + (textHeight * 17.6)));
	backside.setFillColor(sf::Color{ 23,8,0,255 });
	backside.setPosition(255.f + x, 135.f + y);
	window.draw(backside);



	int k = 0;

	if (item.getItemName() != L"") drawItemInfo(window, text, item.getItemName(), k, x, y, item.getItemColor());
	if (item.getItemAddedHp() != 0) drawItemInfo(window, text, L"HP: ", k, item.getItemAddedHp(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemAddedMp() != 0) drawItemInfo(window, text, L"MP: ", k, item.getItemAddedMp(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemHpRegen() != 0) drawItemInfo(window, text, L"HP Regen: ", k, item.getItemHpRegen(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemMpRegen() != 0) drawItemInfo(window, text, L"MP Regen: ", k, item.getItemMpRegen(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemDmg() != 0) drawItemInfo(window, text, L"DMG: ", k, item.getItemDmg(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemDef() != 0) drawItemInfo(window, text, L"DEF: ", k, item.getItemDef(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemStrReq() != 0) drawItemInfo(window, text, L"Min STR: ", k, item.getItemStrReq(), x, y, mainPlayer.str, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemInReq() != 0) drawItemInfo(window, text, L"Min INT: ", k, item.getItemInReq(), x, y, mainPlayer.in, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemLvlReq() != 0) drawItemInfo(window, text, L"Min LVL: ", k, item.getItemLvlReq(), x, y, mainPlayer.lvl, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemMpReq() != 0) drawItemInfo(window, text, L"Min MP: ", k, item.getItemMpReq(), x, y, mainPlayer.maxmp, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemValue() != 0) drawItemInfo(window, text, L"Value: ", k, item.getItemValue(), x, y, sf::Color{ 255, 255, 0, 255 }, sf::Color{ 255, 255, 0, 255 });
}

void hns::Shop::viewItemStats(sf::RenderWindow& window, Item& item, int x, int y)
{
	sf::Font font;
	font.loadFromFile("dpcomic.ttf");


	sf::Text text;
	text.setFont(font);
	text.setFillColor(item.getItemColor());
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1.f);
	text.setCharacterSize(24);

	int textHeight = 0;
	int textWidth = 0;

	if (item.getItemName() != L"")
	{
		wstring str = item.getItemName();
		wchar_t* ptr = _wcsdup(item.getItemName().c_str());
		textWidth = std::wcslen(ptr);
	}

	if (item.getItemAddedHp() != 0) textHeight++;
	if (item.getItemAddedMp() != 0) textHeight++;
	if (item.getItemHpRegen() != 0) textHeight++;
	if (item.getItemMpRegen() != 0) textHeight++;
	if (item.getItemDmg() != 0) textHeight++;
	if (item.getItemDef() != 0) textHeight++;
	if (item.getItemStrReq() != 0) textHeight++;
	if (item.getItemInReq() != 0) textHeight++;
	if (item.getItemLvlReq() != 0) textHeight++;
	if (item.getItemMpReq() != 0) textHeight++;
	if (item.getItemValue() != 0) textHeight++;


	//Item stats black backside
	sf::RectangleShape backside;
	backside.setScale(1.f, 1.f);
	backside.setSize(sf::Vector2f((textWidth * 9) + 44, 36 + (textHeight * 18)));
	backside.setFillColor(sf::Color{ 23,8,0,255 });
	backside.setPosition(255.f + x, 135.f + y);
	window.draw(backside);



	int k = 0;

	if (item.getItemName() != L"") drawItemInfo(window, text, item.getItemName(), k, x, y, item.getItemColor());
	if (item.getItemAddedHp() != 0) drawItemInfo(window, text, L"HP: ", k, item.getItemAddedHp(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemAddedMp() != 0) drawItemInfo(window, text, L"MP: ", k, item.getItemAddedMp(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemHpRegen() != 0) drawItemInfo(window, text, L"HP Regen: ", k, item.getItemHpRegen(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemMpRegen() != 0) drawItemInfo(window, text, L"MP Regen: ", k, item.getItemMpRegen(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemDmg() != 0) drawItemInfo(window, text, L"DMG: ", k, item.getItemDmg(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemDef() != 0) drawItemInfo(window, text, L"DEF: ", k, item.getItemDef(), x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
	if (item.getItemStrReq() != 0) drawItemInfo(window, text, L"Min STR: ", k, item.getItemStrReq(), x, y, mainPlayer.str, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemInReq() != 0) drawItemInfo(window, text, L"Min INT: ", k, item.getItemInReq(), x, y, mainPlayer.in, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemLvlReq() != 0) drawItemInfo(window, text, L"Min LVL: ", k, item.getItemLvlReq(), x, y, mainPlayer.lvl, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemMpReq() != 0) drawItemInfo(window, text, L"Min MP: ", k, item.getItemMpReq(), x, y, mainPlayer.maxmp, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	if (item.getItemValue() != 0) drawItemInfo(window, text, L"Price: ", k, item.getItemValue() * priceMultiplier, x, y, sf::Color{ 255, 255, 0, 255 }, sf::Color{ 255, 255, 0, 255 });
}

void hns::Shop::buyItem(Player &player, Item &item, Equipment &playerEq)
{
	if (item.getItemValue() * priceMultiplier <= player.gold + 1) // if player has enough gold
	{
		playerEq.addItem(item.getItemId(), 1);
		player.gold = player.gold - (item.getItemValue() * priceMultiplier);
		if (item.getItemCount() > 1) item.addItemCount(-1);
		else itemDeletion(item.getItemId());
	}
}