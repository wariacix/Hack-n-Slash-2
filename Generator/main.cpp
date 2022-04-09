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
#include "Player.h"

#include "Map.h"

Map mainMap;
Player mainPlayer;

int debugMode = 0;
int mtnChance;
std::wstring cityName[30];
bool los = false;
std::wstring enemyName;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;


void setBaseValues(sf::RenderWindow &window, equipmentSystem::Equipment &eq)
{
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
	text.setPosition(4.f, 4.f);
	text.setOutlineThickness(2.f);
	window.setVerticalSyncEnabled(true);
	bool recentlyLeft = 0;
	mainPlayer.lvl = 5;
	mtnChance = 14;
	los = false;

	equipmentSystem::Equipment mainEquipment;

	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(0, 10);
	mainEquipment.addItem(1, 10);
	mainEquipment.addItem(2, 10);
	mainEquipment.addItem(3, 50);
	mainEquipment.addItem(4, 60);
	mainEquipment.addItem(5, 999);
	mainEquipment.addItem(6, 999);
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

	while (true)
	{
		system("color 0f");
		system("mode con: cols=106 lines=25");
		setBaseValues(window, mainEquipment);
		menu();
		mainMap.generateMap();
		wcout << L"READY.";
		while (window.isOpen() and los == false)
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

			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1 && recentlyLeft == 0)
			{
				cityEnter(window, mainMap, mainPlayer);
				recentlyLeft = 1;
			}
			else if (mainMap.city[mainPlayer.x][mainPlayer.y] == 0) recentlyLeft = 0;

			text.setString(to_string((int)mainPlayer.hp) + " / " + to_string(mainPlayer.maxhp)); //Draw health in the corner

			drawInterface(window);
			window.draw(text);
			mainPlayer.movePlayer(mainMap, window, mainEquipment, mainPlayer);
			window.display();
		}
	}
};