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
#include <cstring>
#include "textbox.h"
#include "Map.h"
#include "gotoxy.h"
#include "menu.h"
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "Player.h"
#include "main.h"
#include "variables.h"
#include "choice.h"
#pragma warning(disable : 4996)
constexpr auto RUNAWAY = 35;

using namespace std;

void xpCount()
{
	while (mainPlayer.xp >= mainPlayer.reqexp)
	{
		mainPlayer.xp = mainPlayer.xp - mainPlayer.reqexp;
		mainPlayer.reqexp = mainPlayer.reqexp + 250;
		mainPlayer.lvl++;
		for (int p = 0; p < 50; p++)
		{
			gotoxy(121, p);
			wcout << L"     ";
		}
	}
}

void clear()
{
	for (int i = 9; i < 42; i++)
	{
		gotoxy(25, i);
		wcout << L"│                                                                    │";
	}
}

void textboxAnimation()
{
	gotoxy(40, 15);
	wcout << L"/──────────────────────────────────────\\";
	for (int i = 16; i < 35; i++)
	{
		gotoxy(40, i);
		wcout << L"│                                      │";
	}
	gotoxy(40, 35);
	wcout << L"\\──────────────────────────────────────/";
	Sleep(150);
	gotoxy(30, 10);
	wcout << L"/──────────────────────────────────────────────────────────\\";
	for (int i = 11; i < 40; i++)
	{
		gotoxy(30, i);
		wcout << L"│                                                          │";
	}
	gotoxy(30, 40);
	wcout << L"\\──────────────────────────────────────────────────────────/";
	Sleep(150);
	gotoxy(25, 8);
	wcout << L"/────────────────────────────────────────────────────────────────────\\";
	for (int i = 9; i < 42; i++)
	{
		gotoxy(25, i);
		wcout << L"│                                                                    │";
	}
	gotoxy(25, 42);
	wcout << L"\\────────────────────────────────────────────────────────────────────/";
}

void textWriting(wstring input, int yF = 34, int textColor = 15)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColor);
	clear();

	wstring* text = new wstring(input);
	int a = 0; int lines = 0; int lineLength = 59; int waitingTime = 60;
	const wchar_t* textArray = text->c_str();

	gotoxy(30, yF);

	while (a + (lines * lineLength) < text->length())
	{
		if (a > lineLength)
		{
			lines++;
			a = a - lineLength;
			gotoxy(30, yF + lines);

		}
		if (_kbhit() == 1) waitingTime = 1;
		Sleep(waitingTime);
		wcout << textArray[a + (lines * lineLength)];
		a++;
	}
	if (waitingTime == 1) _getch();
	delete text;
}


void textWritingSFML(wstring input, sf::Text textEnt, sf::RenderWindow &window, Map mainMap, Player mainPlayer)
{
	sf::Clock clock;

	wstring* text = new wstring(input);
	int a = 0; int lines = 0; int lineLength = 56;
	const wchar_t* textArray = text->c_str();
	float sec = 3.f;

			for (int i = 1; i < wcslen(textArray); i++)
			{
				sf::Event event;
				a = 0;
				lines = 0;
				int charsLeft = i;
				window.clear();
				while (window.pollEvent(event)) if (event.type == sf::Event::KeyPressed) sec = 1.f;
				mainMap.viewMapSFML(window, mainPlayer);
				while (charsLeft > 0)
				{
					if (a > lineLength)
					{
						lines++;
						a = a - lineLength - 1;

					}
					while (true) { sf::Time time = clock.getElapsedTime(); if (time.asMilliseconds() > sec) break; };
					textEnt.setString(textArray[a + (lines * lineLength)]);
					textEnt.setPosition(160 + 14 * a, 755 + lines * 23);
					window.draw(textEnt);
					a++;
					charsLeft--;
				}
				window.display();
			}
	delete text;
}

class MonsterFight
{
public:
	wstring monsterName;
	int monstergoldLoot;
	int monsterExpLoot;
	int monsterId;
	int monsterBiome;
	void monsterFightFunction()
	{
		bool runawayFlag = false;
		textWriting(monsterName + L" has approached.");
		draw(100 + (50 * monsterBiome) + monsterId, 48, 10);
		if (choice(L"Attack", L"Run away (35%)", L"X", L"X", L"X", L"X", 2) == 2)
		{
			if (rand() % 100 <= RUNAWAY) runawayFlag = true;
			else
			{
				int wybor = fight(100 + (50 * monsterBiome) + monsterId);
				if (wybor == 0) los = true;
				else if (wybor == 1)
				{
					mainPlayer.gold += monstergoldLoot;
					mainPlayer.xp += monsterExpLoot;
				}
			}
		}
		else
		{
			int wybor = fight(100 + (50 * monsterBiome) + monsterId);
			if (wybor == 0) los = true;
			else if (wybor == 1)
			{
				mainPlayer.gold += monstergoldLoot;
				mainPlayer.xp += monsterExpLoot;
			}
		}
	};
};



void textbox(int txtBoxType, int npcId)
{
	MonsterFight monster[2] = { {L"Wolf", 20, 100, 0, 4}, {L"Bear", 20, 120, 1, 4} };
	textboxAnimation();
	if (txtBoxType == 1) // Monster fighting
	{
		switch (npcId)
		{
		case 300:
			monster[0].monsterFightFunction();
			break;
		case 301:
			monster[1].monsterFightFunction();
			break;
		}
		xpCount();
	}
	else if (txtBoxType == 2)
	{
		if (npcId == 1)
		{

		}
	}
	else if (txtBoxType == 3) // Special NPCs
	{
		if (cityGuardian[x][y] == 1)
		{
			draw(1, 26, 9);
			if (choice(L"Talk to city's guardian", L"Get back", L"X", L"X", L"X", L"X", 2) == 2)
			{
			}
			else
			{
				textWriting(L"Who are you? I don't recognize you. Are you one of the peasants working at our farms?");
				switch (choice(L"Yes, my lord.", L"No.", L"I'm a warrior and I'm going to attack you if you don't let me in.", L"X", L"X", L"X", 3))
				{
				case 1:
					textWriting(L"You certainly don't look like one. Go back to where you belong, OUTSIDE of this city!");
					_getch();
					textWriting(L"(Angry guard kicks you out.)");
					_getch();
					break;
				case 2:
					textWriting(L"Who are you then?");
					switch (choice(L"A warrior named " + mainPlayer.heroName + L".", L"An adventurer named " + mainPlayer.heroName + L".", L"A merchant, I've got a lot of mainPlayer.gold and goods willing to sell.", L"X", L"X", L"X", 3))
					{
					case 1:
						switch (rand() % 2)
						{
						case 0:
							textWriting(L"A warrior? Prove yourself. Our city needs more like you. Do you know how to hunt wild boars? We need some of their leather to get through the winter safely. I'll let you in if you hand me over 10 of these.");
							choice(L"Fine, I'll bring them.", L"Sorry, I don't have time for this.", L"X", L"X", L"X", L"X", 2);
							break;
						case 1:
							textWriting(L"A warrior? Prove yourself. Our city needs more like you. Lately we've been struggling to catch bandits near our city. Get them, and I'll let you through.");
							choice(L"Fine, I'll catch them.", L"Sorry, I don't have time for this.", L"X", L"X", L"X", L"X", 2);
							break;
						}
						break;
					}
					break;
				case 3:
					textWriting(L"GUARDS!");
					_getch();
					textWriting(L"THERE'S A PERSON TRYING TO GET IN! WE GOTTA GET HIM!");
					_getch();
					if (mainPlayer.lvl < 15)
					{
						mainPlayer.hp = mainPlayer.hp - 10;
						textWriting(L"(You barely escape, losing 10 hp in the process.)");
						_getch();
					}
					else
					{
						cityGuardian[x][y] = 0;
						textWriting(L"(You get into the city on corpses of dead guards.)");
						mainPlayer.xp = mainPlayer.xp + 750;
						_getch();
					}
					break;
				}
			}
		}
		else
		{
			draw(2, 26, 9);
			if (choice(L"Get into the city", L"Get back", L"X", L"X", L"X", L"X", 2) == 2)
			{
			}
		}
	}
	_getch();
}