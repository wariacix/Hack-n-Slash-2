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
#include "draw.h"
#include "variables.h"
#include "choice.h"
#include "equipment.h"
#include "gameGui.h"
#include "Player.h"

using namespace std;

int randomHP()
{
	return 5 * (rand() % 3);
}

int fight(int id)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	float enemyHP, enemyMaxHP, enemyBaseDmg, dmgRandomizer1, dmgRandomizer2;
	SetConsoleTextAttribute(hConsole, 15);
	for (int i = 9; i < 42; i++)
	{
		gotoxy(25, i);
		wcout << "|                                                                    |";
	}
	switch (id) //0-99 INNE    100-149 - Polany   150-199 - Góry   200-249 - Pustynia   250-299 - Arktyka   300-349 - Lasy
	{
	case 300:
		draw(300, 1, 1);
		enemyName = L"Wolf";
		enemyMaxHP = 65 + randomHP();
		enemyBaseDmg = 12;
		break;
	case 301:
		draw(301, 1, 1);
		enemyName = L"Bear";
		enemyMaxHP = 95 + randomHP();
		enemyBaseDmg = 9;
		break;
	}
	enemyHP = enemyMaxHP;
	gameGui(0, enemyHP, enemyMaxHP);
powrot:
	dmgRandomizer1 = mainPlayer.dmg + rand() % 3;
	dmgRandomizer2 = (enemyBaseDmg + rand() % 3)*(1 - mainPlayer.def/100);
	SetConsoleTextAttribute(hConsole, 15);
	if (mainPlayer.hp <= 0)
	{
		gotoxy(2, 4);
		wcout << L"You lost.";
		enemyMaxHP = 0;
		return 0;
	}
	if (enemyHP <= 0)
	{
		gotoxy(97, 4);
		wcout << L"You won.";
		enemyMaxHP = 0;
		return 1;
	}

	//WYBÓR

	int fightChoice = choice(L"Standard attack", L"Magic attack", L"Equipment", L"Try running away (25%)", L"null", L"null", 4);
	if (fightChoice == 1)
	{
		enemyHP = enemyHP - dmgRandomizer1;
		mainPlayer.hp = mainPlayer.hp - dmgRandomizer2;
		gameGui(1, enemyHP, enemyMaxHP, dmgRandomizer2, dmgRandomizer1, 0);
		goto powrot;
	}
	else if (fightChoice == 2) goto powrot;
	else if (fightChoice == 3)
	{
		equipment();
		gameGui(0, enemyHP, enemyMaxHP, dmgRandomizer2, dmgRandomizer1, 0);
		gotoxy(25, 8);
		wcout << L"/────────────────────────────────────────────────────────────────────\\";
		for (int i = 9; i < 42; i++)
		{
			gotoxy(25, i);
			wcout << L"│                                                                    │";
		}
		gotoxy(25, 42);
		wcout << L"\\────────────────────────────────────────────────────────────────────/";
		draw(id, 1, 1);
		goto powrot;
	}
	else if (fightChoice == 4)
	{
		if (rand() % 4 != 0)
		{
			mainPlayer.hp = mainPlayer.hp - dmgRandomizer2;
			goto powrot;
		}
	}
	return 1;
}