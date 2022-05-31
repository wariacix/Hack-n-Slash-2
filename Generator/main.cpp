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
#include "General.h"
#include "equipment.h"
#include "Player.h"
#include "GameObject.h"
#include "Interface.h"
#include "Map.h"
#include "Fight.h"

Map mainMap;
Player mainPlayer;

int debugMode = 0;
int mtnChance;
std::wstring cityName[30];
bool los = false;
std::wstring enemyName;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;


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
	tInterface.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 320, 200));
	sInterface.setScale(5.f,5.f);
	sInterface.setTexture(tInterface);
	sInterface.setPosition(0.f, 0.f);
	window.draw(sInterface);
}

int main()
{
	srand(time(NULL));
	sf::Font font;
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "Hack n' Slash 2");
	window.setVerticalSyncEnabled(true);
	bool recentlyLeft = 0;
	mtnChance = 14;
	los = false;

	hns::Equipment mainEquipment;
	hns::Interface mainUI(mainPlayer);

	mainEquipment.addItem(1000, 1);
	mainEquipment.addItem(2000, 1);
	mainEquipment.addItem(3000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(0, 3);
	mainEquipment.addItem(100, mainPlayer.gold);
	mainEquipment.addItem(101, 20);
	mainEquipment.addItem(102, 20);
	mainEquipment.addItem(103, 20);
	mainEquipment.addItem(1001, 1);
	mainEquipment.addItem(1002, 1);
	mainEquipment.addItem(1003, 1);
	mainEquipment.addItem(1004, 1);
	mainEquipment.addItem(1005, 1);
	mainEquipment.addItem(1006, 1);
	mainEquipment.addItem(1007, 1);
	mainEquipment.addItem(1008, 1);
	mainEquipment.addItem(2001, 1);
	mainEquipment.addItem(2002, 1);
	mainEquipment.addItem(2003, 1);
	mainEquipment.addItem(3001, 1);
	mainEquipment.addItem(3002, 1);

	bool hasRolled = false;
	int rollX = -1, rollY = -1;
	while (true)
	{
		system("color 0f");
		system("mode con: cols=106 lines=25");
		menu();
		mainMap.generateMap();
		wcout << L"READY.";
		while (window.isOpen() and mainPlayer.alive == true)
		{
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
			mainMap.clearFog(mainPlayer);
			mainMap.viewMapSFML(window, mainPlayer);

			if (rollX != mainPlayer.x or rollY != mainPlayer.y)
			{
				rollX = mainPlayer.x;
				rollY = mainPlayer.y;
				hasRolled = false;
			}

			if (hasRolled == false)
			{
				if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4 && rand() % 10 == 0)
				{
					hns::Fight fight;
					fight.start(window, mainPlayer, mainUI, mainEquipment);
				}
				else hasRolled = true;
			}

			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1 && recentlyLeft == 0)
			{
				cityEnter(window, mainMap, mainPlayer, mainEquipment, mainUI);
				recentlyLeft = 1;
			}
			else if (mainMap.city[mainPlayer.x][mainPlayer.y] == 0) recentlyLeft = 0;

			mainUI.hns::Interface::draw(window, mainPlayer);
			mainPlayer.movePlayer(mainMap, window, mainEquipment, mainPlayer);
			window.display();
		}
	}
};