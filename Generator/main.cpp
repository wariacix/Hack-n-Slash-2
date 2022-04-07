#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "menu.h"
#include "variables.h"
#include "choice.h"
#include "equipment.h"
#include "equipItem.h"
#include "Player.h"

#include "Map.h"

Map mainMap;
Player mainPlayer;
items weapon, armor, shield, selectedItem;

int debugMode = 0;
int cityID[48][46], cityGuardian[48][46], item[9999], armory[3], x, y, p, mtnChance;
std::wstring cityName[30];
int text[50];
int fightMode = 0; //0bez walki,1walka,2ekwipunek w trakcie walki
bool los = false;
std::wstring enemyName;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;


void setBaseValues(sf::RenderWindow &window, equipmentSystem::Equipment &eq)
{
	mainPlayer.lvl = 4;
	mtnChance = 13;
	los = false;

	for (p = 0; p < 9999; p++) item[p] = 0;
	for (p = 0; p < 50; p++) text[p] = -1000;

	armory[0] = 0;
	armory[1] = 0;
	armory[2] = 0;

	equipItemSFML(window, 2, 1000, 0, 0);
	equipItemSFML(window, 2, 2000, 0, 0);
	equipItemSFML(window, 2, 3000, 0, 0);

	item[0] = 200;
	item[1] = 20;
	item[2] = 10;
	item[3] = 5;
	item[4] = 5;
	item[5] = 5;
	item[6] = 5;
	item[1001] = 1;
	item[1002] = 1;
	item[1003] = 1;
	item[1004] = 1;
	item[1005] = 1;
	item[1006] = 1;
	item[1007] = 1;
	item[2001] = 1;
	item[2002] = 1;
	item[2003] = 1;
	item[3001] = 1;
};

void xpCount()
{
	while (mainPlayer.xp >= mainPlayer.reqexp)
	{
		mainPlayer.xp = mainPlayer.xp - mainPlayer.reqexp;
		mainPlayer.reqexp = mainPlayer.reqexp + 250;
		mainPlayer.lvl++;
	}
}

void updateHpMp()
{
	if (mainPlayer.hp < mainPlayer.maxhp) mainPlayer.hp = mainPlayer.hp + mainPlayer.hpRegen; else mainPlayer.hp = mainPlayer.maxhp;
	if (mainPlayer.mp < mainPlayer.maxmp) mainPlayer.mp = mainPlayer.mp + mainPlayer.mpRegen; else mainPlayer.mp = mainPlayer.maxmp;
}

void drawInterface(sf::RenderWindow& window)
{
	sf::Texture tInterface;
	sf::Sprite sInterface;
	tInterface.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 1600, 1000));
	sInterface.setTexture(tInterface);
	sInterface.setPosition(0.f, 0.f);
	window.draw(sInterface);
}

int main()
{
	srand(time(NULL));
	sf::Font font;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Hack n' Slash 2");
	font.loadFromFile("dpcomic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(22);
	text.setPosition(3.f, 3.f);
	window.setVerticalSyncEnabled(true);
	bool recentlyLeft = 0;

	equipmentSystem::Equipment test;

	test.addItem(0, 10);
	test.addItem(1, 10);
	test.addItem(2, 10);
	test.addItem(3, 50);
	test.addItem(4, 60);
	wcout << test.eqItem[0].getItemId() << endl;
	wcout << test.eqItem[0].getItemCount() << endl;
	wcout << test.eqItem[1].getItemId() << endl;
	wcout << test.eqItem[1].getItemCount() << endl;
	wcout << test.eqItem[2].getItemId() << endl;
	wcout << test.eqItem[2].getItemCount() << endl;
	wcout << test.eqItem[3].getItemId() << endl;
	wcout << test.eqItem[3].getItemCount() << endl;
	_getch();

	while (true)
	{
		system("color 0f");
		system("mode con: cols=106 lines=25");
		setBaseValues(window, test);
		menu();
		mainMap.generateMap();
		wcout << L"READY.";
		while (window.isOpen() and los == false)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			mainMap.clearFog(mainPlayer);
			mainMap.viewMapSFML(window, mainPlayer);

			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1 && recentlyLeft == 0)
			{
				cityEnter(window, mainMap, mainPlayer);
				recentlyLeft = 1;
			}
			else if (mainMap.city[mainPlayer.x][mainPlayer.y] == 0) recentlyLeft = 0;

			text.setString(to_string((int)mainPlayer.hp) + " / " + to_string(mainPlayer.maxhp)); //Draw health in the corner

			drawInterface(window);
			window.draw(text);
			mainPlayer.movePlayer(mainMap, window, test);
			window.display();
		}
	}
};