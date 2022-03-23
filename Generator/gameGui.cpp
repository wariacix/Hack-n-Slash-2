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
#include "Player.h"
#include "gotoxy.h"
#include "gameGui.h"
#include "variables.h"
#include "stringLength.h"

using namespace std;

void pasek(int max, int value, int coordx, int coordy, int fColor, int sColor, std::wstring name)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	string number = to_string(value) + "/" + to_string(max);
	char meter[21] = "[__________________]";
	for (int t = 0; t < number.length(); t++)
	{
		gotoxy(10 + 20 - number.length(), 1);
		meter[t + 19 - number.length()] = number[t];
	}
	gotoxy(coordx, coordy);
	wcout << name << L" ";
	for (int t = 0; t < 20; t++)
	{
		if ((max / 20) * t < value) SetConsoleTextAttribute(hConsole, fColor); //162
		else SetConsoleTextAttribute(hConsole, sColor); //196
		if (t == 0) wcout << meter[0];
		else if (t == 19) wcout << L"]";
		else wcout << meter[t];
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void xpBar()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int q = 0; q < 50; q++)
	{
		gotoxy(120, q);
		if (q == 3) wcout << L"╡";
		else wcout << L"│";
	}

	if (mainPlayer.xp > 0)
	{
		int top = (mainPlayer.xp / mainPlayer.reqexp) * 50;
		for (int h = top; h > 0; h--)
		{
			gotoxy(121, 50 - h);
			SetConsoleTextAttribute(hConsole, 162); wprintf(L"▒");
			SetConsoleTextAttribute(hConsole, 175); wprintf(L"▓");
			SetConsoleTextAttribute(hConsole, 162); wprintf(L" ");
			SetConsoleTextAttribute(hConsole, 162); wprintf(L"▓");
			SetConsoleTextAttribute(hConsole, 32); wprintf(L"▒");
		}
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void gameGui(int mode, int enemyHP, int enemyMaxHP, int enemyDMGdone, int dmgDone, int ID, wstring customMessage)
{		// TRYBY: 0 - NORMALNY gameGui, 1 - WALKA, 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_setmode(_fileno(stdout), _O_WTEXT);
	int p;
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(0, 3);
	if (mode == 3) wcout << L"═════╤════════════════╤════════════════╤════════════════╤═══╧════════════╤══════════════════════╦═══════════════════════";
	else wcout << L"════════════════════════════════════════════════════════════╧═══════════════════════════════════╦═══════════════════════";
	for (p = 0; p < 46; p++)
	{
		gotoxy(96, p + 4);
		if (mode == 1 or mode == 3 or mode == 5) wcout << L"║";
		else if (mode == 0 or mode == 2) wcout << L"║                      ";
	}
	xpBar();
	gotoxy(60, 0);
	wcout << L"│                                                  ";
	gotoxy(60, 1);
	wcout << L"│                                                  ";
	gotoxy(60, 2);
	wcout << L"│                                                  ";
	gotoxy(60, 3);
	wcout << L"╧";
	pasek(mainPlayer.maxhp, mainPlayer.hp, 1, 1, 162, 192, L"HP");
	pasek(mainPlayer.maxmp, mainPlayer.mp, 26, 1, 213, 157, L"MP");
	wcout << L" DMG " << mainPlayer.dmg;
	gotoxy(1, 2);
	wcout << mainPlayer.heroName;
	wcout << L" [Level: " << mainPlayer.lvl << L"]";
	if (enemyMaxHP > 0)
	{
		int varInt = enemyHP; //SEKCJA HP
		string number = to_string(varInt) + "/" + to_string(enemyMaxHP);
		char meter[21] = "[__________________]";
		for (int t = 0; t < number.length(); t++)
		{
			gotoxy(60 + 20 - number.length(), 1);
			meter[t + 19 - number.length()] = number[t];
		}
		gotoxy(63, 1);
		wcout << L"HP ";
		for (int t = 0; t < 20; t++)
		{
			if ((enemyMaxHP / 20) * t < enemyHP) SetConsoleTextAttribute(hConsole, 162);
			else SetConsoleTextAttribute(hConsole, 196);
			if (t == 0) wcout << meter[0];
			else if (t == 19) wcout << "]";
			else wcout << meter[t];
		}
		SetConsoleTextAttribute(hConsole, 15);
		gotoxy(63, 2);
		wcout << enemyName;
	}
	if (mode == 1)
	{
		text[0] = dmgDone;
		text[1] = enemyDMGdone;
		for (p = 21; p > 0; p--)
		{
			if (2 * p - 2 >= 0)
			{
				text[2 * p] = text[2 * p - 2];
			}
			if (2 * p - 1 >= 0)
			{
				text[2 * p + 1] = text[2 * p - 1];
			}
		}
		for (p = 0; p < 21; p++)
		{
			gotoxy(97, 2 * p + 4);
			if (2 * p + 2 == 2) SetConsoleTextAttribute(hConsole, 142);
			if (2 * p + 2 == 4) SetConsoleTextAttribute(hConsole, 7);
			if (2 * p + 2 >= 6) SetConsoleTextAttribute(hConsole, 8);
			if (text[2 * p + 2] != -1000)
			{
				wcout << L"You attacked: " + to_wstring(text[2 * p + 2]) + L"DMG";
				for (int i = 0; i < 6 - stringLength(dmgDone); i++)
				{
					wcout << L" ";
				}
			}
			if (2 * p - 1 >= 0)
			{
				gotoxy(97, 2 * p + 3);
				if (2 * p + 1 == 3) SetConsoleTextAttribute(hConsole, 142);
				if (2 * p + 1 == 5) SetConsoleTextAttribute(hConsole, 7);
				if (2 * p + 1 >= 7) SetConsoleTextAttribute(hConsole, 8);
				if (text[2 * p + 1] != -1000)
				{
					wcout << L"Enemy attacked: " + to_wstring(text[2 * p + 1]) + L"DMG";
					for (int i = 0; i < 4 - stringLength(enemyDMGdone); i++)
					{
						wcout << L" ";
					}
				}
			}
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	if (mode == 0)
	{
		for (p = 0; p < 50; p++)
		{
			text[p] = -1000;
		}
	}
}