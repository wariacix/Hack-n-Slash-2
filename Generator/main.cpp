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
#include "InterfaceObjects.h"
#include "Interface.h"
#include "Map.h"
#include "Fight.h"

sf::Texture hns::Cursor::texture;
sf::Texture hns::Cursor::textureClicked;
sf::Sprite hns::Cursor::sprite;

hns::Cursor cursor = hns::Cursor();
hns::Player mainPlayer;

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
	mainEquipment.addItem(4000, 1);
	mainEquipment.addItem(5000, 1);
	mainEquipment.addItem(6000, 1);
	mainEquipment.addItem(7000, 1);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
	mainEquipment.addItem(100, mainPlayer.gold);
	mainEquipment.addItem(0, 2);
	mainEquipment.addItem(101, 20);
	mainEquipment.addItem(102, 20);
	mainEquipment.addItem(103, 10);

	hns::Interface mainUI(mainPlayer);
	hns::Interface fightUI(mainPlayer,0,0,320,200,"fightInterface");
	hns::Map mainMap("default", 78, 70);

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
		bool hasClickedConfirmation = true;
		hns::ScrollList scrollList = hns::ScrollList(350, 250, 96, 48, 64, L"Enemy's dead. Items dropped:");
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

			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1 && recentlyLeft == 0)
			{
				CityEnter(window, mainMap, mainPlayer, mainEquipment, mainUI);
				recentlyLeft = 1;
			}
			else if (mainMap.city[mainPlayer.x][mainPlayer.y] == 0) recentlyLeft = 0;

			mainUI.Draw(window, mainPlayer);
			if (rollX != mainPlayer.x or rollY != mainPlayer.y)
			{
				rollX = mainPlayer.x;
				rollY = mainPlayer.y;
				hasRolled = false;
			}

			if (hasRolled == false)
			{
				if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4 && rand() % 12 == 0)
				{
					scrollList = hns::ScrollList(371, 259, 55, 20, 30, L"Items found:");
					hns::Enemy enemy;
					enemy.loadEnemy("forest");
					hns::Fight fight(enemy);
					fight.start(window, mainPlayer, fightUI, mainEquipment);
					int itemRewardArray[4] = { 0,1,5,101 };
					int chosenItemId = rand() % 4;
					int howMany = 1 + rand() % 2;
					if (rand() % 2 == 0)
					{
						mainEquipment.addItem(itemRewardArray[chosenItemId], howMany);
						std::wstring sampleName;
						for (int i = 0; i < 9999; i++)
						{
							if (itemRewardArray[chosenItemId] == mainEquipment.eqItem[i].getItemId())
							{
								sampleName = mainEquipment.eqItem[i].getItemName();
							}
						}
						scrollList.AddTextObject(48, 10, "UI\\Scrolls\\paper-piece", std::to_wstring(howMany) + L"x " + sampleName);
						scrollList.Draw(window);
						hasClickedConfirmation = false;
					}
				}
				else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 6 && rand() % 12 == 0)
				{
					scrollList = hns::ScrollList(371, 259, 55, 20, 30, L"Items found:");
					hns::Enemy enemy;
					enemy.loadEnemy("forestCold");
					hns::Fight fight(enemy);
					fight.start(window, mainPlayer, fightUI, mainEquipment);
					int itemRewardArray[4] = { 0,1,5,102 };
					int chosenItemId = rand() % 4;
					int howMany = 1 + rand() % 2;
					if (rand() % 2 == 0)
					{
						mainEquipment.addItem(itemRewardArray[chosenItemId], howMany);
						std::wstring sampleName;
						for (int i = 0; i < 9999; i++)
						{
							if (itemRewardArray[chosenItemId] == mainEquipment.eqItem[i].getItemId())
							{
								sampleName = mainEquipment.eqItem[i].getItemName();
							}
						}
						scrollList.AddTextObject(48, 10, "UI\\Scrolls\\paper-piece", std::to_wstring(howMany) + L"x " + sampleName);
						scrollList.Draw(window);
						hasClickedConfirmation = false;
					}
				}
				else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 1 && rand() % 15 == 0)
				{
					scrollList = hns::ScrollList(371, 259, 55, 20, 30, L"Items found:");
					hns::Enemy enemy;
					enemy.loadEnemy("mountains");
					hns::Fight fight(enemy);
					fight.start(window, mainPlayer, fightUI, mainEquipment);
					int itemRewardArray[3] = { 0,1,103 };
					int chosenItemId = rand() % 3;
					int howMany = 1 + rand() % 2;
					if (rand() % 2 == 0)
					{
						mainEquipment.addItem(itemRewardArray[chosenItemId], howMany);
						std::wstring sampleName;
						for (int i = 0; i < 9999; i++)
						{
							if (itemRewardArray[chosenItemId] == mainEquipment.eqItem[i].getItemId())
							{
								sampleName = mainEquipment.eqItem[i].getItemName();
							}
						}
						scrollList.AddTextObject(48, 10, "UI\\Scrolls\\paper-piece", std::to_wstring(howMany) + L"x " + sampleName);
						scrollList.Draw(window);
						hasClickedConfirmation = false;
					}
				}
				else hasRolled = true;
			}
			mainPlayer.movePlayer(mainMap, window, mainEquipment, mainPlayer);
			if (hasClickedConfirmation == false) scrollList.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) == true || sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true || sf::Keyboard::isKeyPressed(sf::Keyboard::S) == true || sf::Keyboard::isKeyPressed(sf::Keyboard::E) == true || sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true || sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true) hasClickedConfirmation = true;
			window.display();
		}
		mainPlayer = hns::Player();
		mainEquipment = Equipment();
		mainEquipment.addItem(1000, 1);
		mainEquipment.addItem(2000, 1);
		mainEquipment.addItem(3000, 1);
		mainEquipment.addItem(4000, 1);
		mainEquipment.addItem(5000, 1);
		mainEquipment.addItem(6000, 1);
		mainEquipment.addItem(7000, 1);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.equipItem(mainEquipment.eqItem[1], mainPlayer);
		mainEquipment.addItem(100, mainPlayer.gold);
		mainEquipment.addItem(0, 2);
		mainEquipment.addItem(101, 20);
		mainEquipment.addItem(102, 20);
		mainEquipment.addItem(103, 10);
	}
};