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
#include "equipment.h"
#include "menu.h"
#include "Player.h"
#include "variables.h"
#include "choice.h"

using namespace std;


void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring name, int& k, int x, int y, sf::Color color)
{
	text.setFillColor(color);

	text.setCharacterSize(24);
	text.setPosition(259.f + x, 138.f + y + (k * 25));
	text.setString(name);
	window.draw(text);
	k++;
}

void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring statStr, int& k, int value, int x, int y, sf::Color green, sf::Color red)
{
	if (value >= 0) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + to_wstring(value));
	window.draw(text);
	k++;
}

void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring statStr, int& k, int requiredVal, int x, int y, int value, sf::Color green, sf::Color red)
{
	if (value >= requiredVal) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + to_wstring(requiredVal));
	window.draw(text);
	k++;
}

void equipItemSFML(sf::RenderWindow &window, int mode, int ID, int x, int y)
{
	struct items
	{
		int id = 0;
		int addedHp = 0;
		int addedMp = 0;
		int hpRegen = 0;
		int mpRegen = 0;
		int dmg = 0;
		int def = 0;
		int strReq = 0;
		int inReq = 0;
		int lvlReq = 0;
		int mpReq = 0;
		sf::Color color = sf::Color::White;
		wstring itemName = L" ";
	};
	selectedItem.addedHp = 0; selectedItem.addedMp = 0; selectedItem.hpRegen = 0; selectedItem.mpRegen = 0; selectedItem.dmg = 0; selectedItem.def = 0; selectedItem.strReq = 0; selectedItem.inReq = 0; selectedItem.lvlReq = 0; selectedItem.mpReq = 0; selectedItem.color = sf::Color::White; selectedItem.itemName = L" ";
	selectedItem.id = ID;
	if (ID >= 0 and ID < 1000)
	{
		switch (ID)
		{
		case 0:
			selectedItem.itemName = L"Potion +25HP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 1:
			selectedItem.itemName = L"Potion +50HP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 2:
			selectedItem.itemName = L"Potion +100HP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 3:
			selectedItem.itemName = L"Potion +200HP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 4:
			selectedItem.itemName = L"Potion +50%HP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 5:
			selectedItem.itemName = L"Potion +10MP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 6:
			selectedItem.itemName = L"Potion +20MP";
			selectedItem.color = sf::Color::Yellow;
			break;
		case 100:
			selectedItem.itemName = L"Gold Coins";
			selectedItem.color = sf::Color::Yellow;
			break;
		}
	}
	else if (ID >= 1000 and ID < 2000)
	{
		switch (ID)
		{
		case 1000:
			selectedItem.dmg = 10;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.itemName = L"Mace";
			break;
		case 1001:
			selectedItem.dmg = 13;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 2;
			selectedItem.itemName = L"Mace With Nails";
			break;
		case 1002:
			selectedItem.dmg = 15;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 3;
			selectedItem.itemName = L"Copper Knife";
			break;
		case 1003:
			selectedItem.dmg = 17;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 4;
			selectedItem.itemName = L"Copper Sword";
			break;
		case 1004:
			selectedItem.dmg = 20;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 5;
			selectedItem.itemName = L"Copper Longsword";
			break;
		case 1005:
			selectedItem.dmg = 17;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 4;
			selectedItem.itemName = L"Iron Knife";
			break;
		case 1006:
			selectedItem.dmg = 20;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 5;
			selectedItem.itemName = L"Iron Sword";
			break;
		case 1007:
			selectedItem.dmg = 23;
			selectedItem.strReq = 0;
			selectedItem.lvlReq = 6;
			selectedItem.itemName = L"Iron Longsword";
			break;
		}
	}
	else if (ID >= 2000 and ID < 3000)
	{
		switch (ID)
		{
		case 2000:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 0;
			selectedItem.def = 5;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Worn Out Leather Armor";
			break;
		case 2001:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 0;
			selectedItem.def = 7;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Leather Armor";
			break;
		case 2002:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 1;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 0;
			selectedItem.def = 9;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 3;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Copper Breastplate";
			break;
		case 2003:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 1;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 0;
			selectedItem.def = 12;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 4;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Copper Chestplate";
			break;
		}
	}
	else if (ID >= 3000 and ID < 4000)
	{
		switch (ID)
		{
		case 3000:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 1;
			selectedItem.def = 3;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Worn Out Wooden Shield";
			break;
		case 3001:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 2;
			selectedItem.def = 4;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Wooden Shield";
			break;
		}
	}

	if (mode == 0) //WYSWIETLANIE
	{
		sf::Font font;
		font.loadFromFile("dpcomic.ttf");


		sf::Text text;
		text.setFont(font);
		text.setFillColor(selectedItem.color);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(1.f);
		text.setCharacterSize(24);

		int textHeight = 0;
		int textWidth = 0;

		if (selectedItem.itemName != L" ")
		{
			wstring str = selectedItem.itemName;
			wchar_t* ptr = _wcsdup(selectedItem.itemName.c_str());
			textWidth = std::wcslen(ptr);
		}
		if (selectedItem.addedHp != 0) textHeight++;
		if (selectedItem.addedMp != 0) textHeight++;
		if (selectedItem.hpRegen != 0) textHeight++;
		if (selectedItem.mpRegen != 0) textHeight++;
		if (selectedItem.dmg != 0) textHeight++;
		if (selectedItem.def != 0) textHeight++;
		if (selectedItem.strReq != 0) textHeight++;
		if (selectedItem.inReq != 0) textHeight++;
		if (selectedItem.lvlReq != 0) textHeight++;
		if (selectedItem.mpReq != 0) textHeight++;


		//Item stats black backside
		sf::RectangleShape backside;
		backside.setScale(1.f,1.f);
		backside.setSize(sf::Vector2f((textWidth * 9) + 44, 36 + (textHeight * 18)));
		backside.setFillColor(sf::Color{ 23,8,0,255 });
		backside.setPosition(255.f + x, 135.f + y);
		window.draw(backside);



		int k = 0;

		if (selectedItem.itemName != L" ") drawItemInfo(window, text, selectedItem.itemName, k, x, y, selectedItem.color);
		if (selectedItem.addedHp != 0) drawItemInfo(window, text, L"HP: ", k, selectedItem.addedHp, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.addedMp != 0) drawItemInfo(window, text, L"MP: ", k, selectedItem.addedMp, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.hpRegen != 0) drawItemInfo(window, text, L"HP Regen: ", k, selectedItem.hpRegen, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.mpRegen != 0) drawItemInfo(window, text, L"MP Regen: ", k, selectedItem.mpRegen, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.dmg != 0) drawItemInfo(window, text, L"DMG: ", k, selectedItem.dmg, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.def != 0) drawItemInfo(window, text, L"DEF: ", k, selectedItem.def, x, y, sf::Color{ 52,150,14,255 }, sf::Color{ 198,0,0,255 });
		if (selectedItem.strReq != 0) drawItemInfo(window, text, L"Min STR: ", k, selectedItem.strReq, x, y, mainPlayer.str, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
		if (selectedItem.inReq != 0) drawItemInfo(window, text, L"Min INT: ", k, selectedItem.inReq, x, y, mainPlayer.in, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
		if (selectedItem.lvlReq != 0) drawItemInfo(window, text, L"Min LVL: ", k, selectedItem.lvlReq, x, y, mainPlayer.lvl, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
		if (selectedItem.mpReq != 0) drawItemInfo(window, text, L"Min MP: ", k, selectedItem.mpReq, x, y, mainPlayer.maxmp, sf::Color{ 71,255,0,255 }, sf::Color{ 255,0,0,255 });
	}
	else if (mode == 1 or mode == 2) //ZAKLADANIE
	{
		if (ID >= 0 and ID < 1000)
		{
			switch (ID)
			{
			case 0:
				mainPlayer.hp = mainPlayer.hp + 25;
				if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
				item[ID] = item[ID] - 1;
				break;
			case 1:
				mainPlayer.hp = mainPlayer.hp + 50;
				if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
				item[ID] = item[ID] - 1;
				break;
			case 2:
				mainPlayer.hp = mainPlayer.hp + 100;
				if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
				item[ID] = item[ID] - 1;
				break;
			case 3:
				mainPlayer.hp = mainPlayer.hp + 200;
				if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
				item[ID] = item[ID] - 1;
				break;
			case 4:
				mainPlayer.hp = mainPlayer.hp + (0.5 * mainPlayer.maxhp);
				if (mainPlayer.hp > mainPlayer.maxhp) mainPlayer.hp = mainPlayer.maxhp;
				item[ID] = item[ID] - 1;
				break;
			case 5:
				mainPlayer.mp = mainPlayer.mp + 10;
				if (mainPlayer.mp > mainPlayer.maxmp) mainPlayer.mp = mainPlayer.maxmp;
				item[ID] = item[ID] - 1;
				break;
			case 6:
				mainPlayer.mp = mainPlayer.mp + 20;
				if (mainPlayer.mp > mainPlayer.maxmp) mainPlayer.mp = mainPlayer.maxmp;
				item[ID] = item[ID] - 1;
				break;
			case 100:
				break;
			}
		}
		if (ID >= 1000 and ID < 2000)
		{
			if (selectedItem.strReq > mainPlayer.str or selectedItem.inReq > mainPlayer.in or selectedItem.lvlReq > mainPlayer.lvl or selectedItem.mpReq > mainPlayer.maxmp) goto cancel;
			weapon.addedHp = selectedItem.addedHp;
			weapon.addedMp = selectedItem.addedMp;
			weapon.hpRegen = selectedItem.hpRegen;
			weapon.mpRegen = selectedItem.mpRegen;
			weapon.dmg = selectedItem.dmg;
			weapon.def = selectedItem.def;
			weapon.strReq = selectedItem.strReq;
			weapon.inReq = selectedItem.inReq;
			weapon.lvlReq = selectedItem.lvlReq;
			weapon.mpReq = selectedItem.mpReq;
			if (mode == 2) goto cancel;
			item[armory[0] + 1000]++;
			item[ID]--;
			armory[0] = ID - 1000;
		}
		else if (ID >= 2000 and ID < 3000)
		{
			if (selectedItem.strReq > mainPlayer.str or selectedItem.inReq > mainPlayer.in or selectedItem.lvlReq > mainPlayer.lvl or selectedItem.mpReq > mainPlayer.maxmp) goto cancel;
			armor.addedHp = selectedItem.addedHp;
			armor.addedMp = selectedItem.addedMp;
			armor.hpRegen = selectedItem.hpRegen;
			armor.mpRegen = selectedItem.mpRegen;
			armor.dmg = selectedItem.dmg;
			armor.def = selectedItem.def;
			armor.strReq = selectedItem.strReq;
			armor.inReq = selectedItem.inReq;
			armor.lvlReq = selectedItem.lvlReq;
			armor.mpReq = selectedItem.mpReq;
			if (mode == 2) goto cancel;
			item[armory[1] + 2000]++;
			item[ID]--;
			armory[1] = ID - 2000;
		}
		else if (ID >= 3000 and ID < 4000)
		{
			if (selectedItem.strReq > mainPlayer.str or selectedItem.inReq > mainPlayer.in or selectedItem.lvlReq > mainPlayer.lvl or selectedItem.mpReq > mainPlayer.maxmp) goto cancel;
			shield.addedHp = selectedItem.addedHp;
			shield.addedMp = selectedItem.addedMp;
			shield.hpRegen = selectedItem.hpRegen;
			shield.mpRegen = selectedItem.mpRegen;
			shield.dmg = selectedItem.dmg;
			shield.def = selectedItem.def;
			shield.strReq = selectedItem.strReq;
			shield.inReq = selectedItem.inReq;
			shield.lvlReq = selectedItem.lvlReq;
			shield.mpReq = selectedItem.mpReq;
			if (mode == 2) goto cancel;
			item[armory[2] + 3000]++;
			item[ID]--;
			armory[2] = ID - 3000;
		}
	cancel:
		mainPlayer.maxhp = weapon.addedHp + armor.addedHp + shield.addedHp + 100;
		mainPlayer.maxmp = weapon.addedMp + armor.addedMp + shield.addedMp + 20;
		mainPlayer.hpRegen = weapon.hpRegen + armor.hpRegen + shield.hpRegen + 1;
		mainPlayer.mpRegen = weapon.mpRegen + armor.mpRegen + shield.mpRegen + 1;
		mainPlayer.dmg = weapon.dmg + armor.dmg + shield.dmg;
		mainPlayer.def = weapon.def + armor.def + shield.def;
		std::wcout << L"";
	}
}