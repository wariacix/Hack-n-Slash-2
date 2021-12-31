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
#include "menu.h"
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "Player.h"
#include "textbox.h"
#include "variables.h"
#include "choice.h"
#include "equipment.h"

using namespace std;

void itemInfoStringName(wstring main, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	wstring blankSpace;
	blankSpace = main;
	for (int a = 0; a < 23 - main.length(); a++)
	{
		blankSpace = blankSpace + L" ";
	}
	SetConsoleTextAttribute(hConsole, color);
	std::wcout << blankSpace;
}

void itemInfoString(wstring type, int requiredNumber, int color = 15, int number = -1)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	wstring blankSpace, main;
	main = type + L": +" + to_wstring(requiredNumber);
	for (int a = 0; a < 23 - main.length(); a++)
	{
		blankSpace = blankSpace + L" ";
	}
	SetConsoleTextAttribute(hConsole, color);
	std::wcout << type + L": ";
	if (number == -1)
	{
		if (requiredNumber >= 0)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::wcout << L"+" << requiredNumber << blankSpace;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::wcout << requiredNumber << blankSpace;
		}
	}
	else if (number >= 0)
	{
		if (requiredNumber <= number)
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::wcout << requiredNumber << L" " << blankSpace;
		}
		else if (requiredNumber > number)
		{
			SetConsoleTextAttribute(hConsole, 4);
			std::wcout << requiredNumber << L" " << blankSpace;
		}
	}
}

void equipItem(int mode, int ID)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
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
		int color = 15;
		wstring itemName = L" ";
	};
	selectedItem.addedHp = 0; selectedItem.addedMp = 0; selectedItem.hpRegen = 0; selectedItem.mpRegen = 0; selectedItem.dmg = 0; selectedItem.def = 0; selectedItem.strReq = 0; selectedItem.inReq = 0; selectedItem.lvlReq = 0; selectedItem.mpReq = 0; selectedItem.color = 15; selectedItem.itemName = L" ";
	selectedItem.id = ID;
	if (ID >= 0 and ID < 1000)
	{
		switch (ID)
		{
		case 0:
			selectedItem.itemName = L"Potion +25HP";
			selectedItem.color = 14;
			break;
		case 1:
			selectedItem.itemName = L"Potion +50HP";
			selectedItem.color = 14;
			break;
		case 2:
			selectedItem.itemName = L"Potion +100HP";
			selectedItem.color = 14;
			break;
		case 3:
			selectedItem.itemName = L"Potion +200HP";
			selectedItem.color = 14;
			break;
		case 4:
			selectedItem.itemName = L"Potion +50%HP";
			selectedItem.color = 14;
			break;
		case 5:
			selectedItem.itemName = L"Potion +10MP";
			selectedItem.color = 14;
			break;
		case 6:
			selectedItem.itemName = L"Potion +20MP";
			selectedItem.color = 14;
			break;
		}
	}
	else if (ID >= 1000 and ID < 2000)
	{
		switch (ID)
		{
		case 1000:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 10;
			selectedItem.def = 0;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 1;
			selectedItem.mpReq = 0;
			selectedItem.color = 8;
			selectedItem.itemName = L"Branches";
			break;
		case 1001:
			selectedItem.addedHp = 0;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 13;
			selectedItem.def = 0;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 2;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Mace";
			break;
		case 1002:
			selectedItem.addedHp = -2;
			selectedItem.addedMp = 0;
			selectedItem.hpRegen = 0;
			selectedItem.mpRegen = 0;
			selectedItem.dmg = 15;
			selectedItem.def = 0;
			selectedItem.strReq = 0;
			selectedItem.inReq = 0;
			selectedItem.lvlReq = 3;
			selectedItem.mpReq = 0;
			selectedItem.itemName = L"Rusty Knife";
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
			selectedItem.color = 8;
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
			selectedItem.color = 8;
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
		wstring attribute = L"";
		int k = 4;
		if (selectedItem.itemName != L" ")
		{
			gotoxy(97, k); k++;
			itemInfoStringName(selectedItem.itemName, selectedItem.color);
		}
		if (selectedItem.addedHp != 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"HP",selectedItem.addedHp);
		}
		if (selectedItem.addedMp > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"MP", selectedItem.addedMp);
		}
		if (selectedItem.hpRegen > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"HP Regen", selectedItem.hpRegen);
		}
		if (selectedItem.mpRegen > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"MP Regen", selectedItem.hpRegen);
		}
		if (selectedItem.dmg > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"DMG", selectedItem.dmg);
		}
		if (selectedItem.def > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"DEF", selectedItem.def);
		}
		if (selectedItem.strReq > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"Min STR", selectedItem.strReq, 15, mainPlayer.str);
		}
		if (selectedItem.inReq > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"Min INT", selectedItem.inReq, 15, mainPlayer.in);
		}
		if (selectedItem.lvlReq > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"Min LVL", selectedItem.lvlReq, 15, mainPlayer.lvl);
		}
		if (selectedItem.mpReq > 0)
		{
			gotoxy(97, k); k++;
			itemInfoString(L"Min MP", selectedItem.mpReq, 15, mainPlayer.maxmp);
		}
		for (int i = 0; i < 30 - k; i++)
		{
			gotoxy(97, k); k++; std::wcout << "                       ";
		}
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