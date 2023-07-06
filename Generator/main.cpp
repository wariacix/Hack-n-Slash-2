#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include "menu.h"
#include "variables.h"
#include "choice.h"
#include "General.h"
#include "equipment.h"
#include "Player.h"
#include "GameObject.h"
#include "menu.h"
#include "Interface.h"
#include "InterfaceObjects.h"
#include "Map.h"
#include "Fight.h"

Player mainPlayer;

sf::Texture hns::Cursor::texture;
sf::Texture hns::Cursor::textureClicked;
sf::Sprite hns::Cursor::sprite;
hns::Cursor cursor = hns::Cursor();

int debugMode = 0;
int mtnChance;
std::wstring cityName[30];
bool los = false;
std::wstring enemyName;

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
	wcout << L"Started the game." << std::endl;
	srand(time(NULL));
	sf::Font font;
	bool recentlyLeft = 0;
	mtnChance = 14;
	los = false;

	hns::Equipment mainEquipment;
	mainEquipment.addItem(1000, 1);
	mainEquipment.addItem(2000, 1);
	mainEquipment.addItem(3000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(4000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(5000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(6000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(7000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(100, mainPlayer.gold);
	mainEquipment.addItem(0, 2);
	mainEquipment.addItem(101, 20);
	mainEquipment.addItem(102, 20);
	mainEquipment.addItem(103, 10);

	hns::Interface mainUI(mainPlayer);
	hns::Interface fightUI(mainPlayer,0,0,320,200,"fightInterface");
	Map mainMap("default", 78, 70);

	bool hasRolled = false;
	int rollX = -1, rollY = -1;

	hns::Menu menu;

	while (true)
	{
		sf::Clock clock;
		wcout << L"Generating map...";
		mainMap.Initialize();
		wcout << L"READY.";
		sf::RenderWindow window(sf::VideoMode(1600, 1000), "Hack n' Slash 2");
		window.setVerticalSyncEnabled(false);
		window.setMouseCursorVisible(false);
		menu.Start(window);
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
			mainMap.ClearFog(mainPlayer);
			mainMap.ViewMap(window, mainPlayer, clock);

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
					hns::Enemy enemy;
					enemy.loadEnemy("forest");
					hns::Fight fight(enemy);
					fight.start(window, mainPlayer, fightUI, mainEquipment);
				}
				else hasRolled = true;
			}

			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1 && recentlyLeft == 0)
			{
				CityEnter(window, mainMap, mainPlayer, mainEquipment, mainUI);
				recentlyLeft = 1;
			}
			else if (mainMap.city[mainPlayer.x][mainPlayer.y] == 0) recentlyLeft = 0;

			mainUI.Draw(window, mainPlayer);
			mainPlayer.movePlayer(mainMap, window, mainEquipment, mainPlayer);
			window.display();
		}
		mainPlayer = Player();
		mainEquipment = Equipment();
		mainEquipment.addItem(1000, 1);
		mainEquipment.addItem(2000, 1);
		mainEquipment.addItem(3000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(4000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(5000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(6000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(7000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(100, mainPlayer.gold);
		mainEquipment.addItem(101, 20);
		mainEquipment.addItem(102, 20);
		mainEquipment.addItem(103, 10);
	}
};