#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "variables.h"
#include "Player.h"
#include "Map.h"

using namespace std;
std::wstring Map::genCityName()
		{
			wstring part1, part2, all;
			int random;
			random = rand() % 14;
			if (random == 0) part1 = L"Goten";
			else if (random == 1) part1 = L"Uru";
			else if (random == 2) part1 = L"Ham";
			else if (random == 3) part1 = L"Kor";
			else if (random == 4) part1 = L"Hindel";
			else if (random == 5) part1 = L"Ter";
			else if (random == 6) part1 = L"Ant";
			else if (random == 7) part1 = L"Pers";
			else if (random == 8) part1 = L"Ber";
			else if (random == 9) part1 = L"Toro";
			else if (random == 10) part1 = L"Rotter";
			else if (random == 11) part1 = L"Porto";
			else if (random == 12) part1 = L"Bur";
			else if (random == 13) part1 = L"Dore";
			random = rand() % 11;
			if (random == 0) part2 = L"burg";
			else if (random == 1) part2 = L"owo";
			else if (random == 2) part2 = L"ino";
			else if (random == 3) part2 = L"berg";
			else if (random == 4) part2 = L"del";
			else if (random == 5) part2 = L"awa";
			else if (random == 6) part2 = L"-el";
			else if (random == 7) part2 = L"ein";
			else if (random == 8) part2 = L"kes";
			else if (random == 9) part2 = L"ov";
			else if (random == 10) part2 = L"ing";
			all = part1 + part2;
			return all;
		}

void Map::setBaseValues()
		{
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					biome[x][y] = 0;
					city[x][y] = 0;
					hero[x][y] = 0;
					path[x][y] = 0;
					fog[x][y] = 1;
					path[x][y] = 0;
					if (rand() % mtnChance == 1) biome[x][y] = 1;
					if (biome[x][y] == 1) //POSZERZANIE GÓR
					{
						if (rand() % 5 > 1 and x < mapWidth - 1) biome[x + 1][y] = 1;
						if (rand() % 5 > 1 and x > 0) biome[x - 1][y] = 1;
						if (rand() % 5 > 1 and y < mapHeight - 1) biome[x][y + 1] = 1;
						if (rand() % 5 > 1 and y > 0) biome[x][y - 1] = 1;
						if (rand() % 5 > 0 and x < mapWidth - 1 and y < mapHeight - 1) biome[x + 1][y + 1] = 1;
						if (rand() % 5 > 0 and x > 0 and y < mapHeight - 1) biome[x - 1][y + 1] = 1;
						if (rand() % 5 > 0 and x < mapWidth - 1 and y > 0) biome[x + 1][y - 1] = 1;
						if (rand() % 5 > 0 and x > 0 and y > 0) biome[x - 1][y - 1] = 1;
					}
				}
			}
			hero[24][23] = 1;
		};

void Map::enlargeMountains()
		{
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					if (x > 1 and x < mapWidth - 1 and y > 1 and y < mapHeight - 1 and biome[x][y] == 1 and biome[x + 1][y] == 0 and biome[x - 1][y] == 0 and biome[x][y - 1] == 0 and biome[x][y + 1] == 0) biome[x][y] = 0;
					if (x > 1 and x < mapWidth - 1 and y > 1 and y < mapHeight - 1 and biome[x][y] == 0 and biome[x + 1][y] == 1 and biome[x - 1][y] == 1 and biome[x][y - 1] == 1 and biome[x][y + 1] == 1) biome[x][y] = 1;
				}
			}
		};

void Map::createDeserts()
		{
			for (int x = 0; x < mapWidth; x++)
			{
				if (rand() % 2 == 0) biome[x][36] = 2;
				for (int y = 37; y < mapHeight; y++)
				{
					biome[x][y] = 2;
				}
			}
		};

void Map::createArctic()
		{
			for (int x = 0; x < mapWidth; x++)
			{
				if (rand() % 2 == 0) biome[x][5] = 3;
				for (int y = 0; y < 5; y++) biome[x][y] = 3;
			}
		};

void Map::createBaseBiomes()
		{
			srand(time(NULL));
			setBaseValues();
			enlargeMountains();
			createArctic();
			createDeserts();
		};

void Map::createCities()
		{
			int x1, y1;
			for (int x = 6; x < mapWidth - 5; x++)
			{
				for (int y = 6; y < mapHeight - 5; y++)
				{
					int cityChance = 1;
					for (x1 = 0; x1 < 5; x1++)
					{
						for (y1 = 0; y1 < 5; y1++)
						{
							if (biome[x + x1 - 2][y + y1 - 2] == 1 or biome[x + x1 - 2][y + y1 - 2] == 3) cityChance = 0;
						}
					}
					if (cityChance == 1 and city[x][y] != 1)
					{
						city[x][y] = 1;
					}
				}
			}
			for (int i = 0; i < 50000; i++)
			{
				int x = rand() % (mapWidth - 5);
				int y = rand() % (mapHeight - 5);
				int cityChance = 0;
				for (x1 = 0; x1 < 15; x1++)
				{
					for (y1 = 0; y1 < 15; y1++)
					{
						if ((x + x1 - 7 >= 0) && (y + y1 - 7 >= 0) && (x + x1 - 7 < mapWidth) && (y + y1 - 7 < mapHeight) && city[x + x1 - 7][y + y1 - 7] == 1) cityChance++;
					}
				}
				if (cityChance > 1) city[x][y] = 0;
			}
			for (int x = 0; x < mapWidth; x++)
			{
				city[x][mapHeight - 3] = 0;
				city[x][mapHeight - 2] = 0;
				city[x][mapHeight - 1] = 0;
			}
			for (int y = 0; y < mapHeight; y++)
			{
				city[0][y] = 0;
				city[1][y] = 0;
				city[2][y] = 0;
				city[3][y] = 0;
				city[4][y] = 0;
			}
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					int a = 1;
					if (city[x][y] == 1)
					{
						cityID[x][y] = a;
						a++;
					}
				}
			}
		};

void Map::createForests()
		{
			int x1, y1;
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					int forestChance = 1;
					for (x1 = 0; x1 < 3; x1++)
					{
						for (y1 = 0; y1 < 3; y1++)
						{
							if (x + x1 - 1 >= 0 && x + x1 - 1 < mapWidth && y + y1 - 1 >= 0 && y + y1 - 1 < mapHeight && biome[x + x1 - 1][y + y1 - 1] != 0 and biome[x + x1 - 1][y + y1 - 1] != 1) forestChance = 0;
						}
					}
					for (x1 = 0; x1 < 9; x1++)
					{
						for (y1 = 0; y1 < 9; y1++)
						{
							if (x + x1 - 4 >= 0 && x + x1 - 4 < mapWidth && y + y1 - 4 >= 0 && y + y1 - 4 < mapHeight && city[x + x1 - 4][y + y1 - 4] != 0) forestChance = 0;
						}
					}
					if (forestChance == 1 and rand() % 14 == 0 and x > 0 and y > 0 and y < mapHeight and x < mapWidth)
					{
						for (x1 = 0; x1 < 3; x1++)
						{
							for (y1 = 0; y1 < 3; y1++)
							{
								if (x + x1 - 1 >= 0 && x + x1 - 1 < mapWidth && y + y1 - 1 >= 0 && y + y1 - 1 < mapHeight && biome[x + x1 - 1][y + y1 - 1] == 0) biome[x + x1 - 1][y + y1 - 1] = 4;
							}
						}
					}
				}
			}

			for (int x = 1; x < mapWidth - 1; x++)
			{
				for (int y = 1; y < mapHeight - 1; y++)
				{
					if (biome[x][y] == 4 and (biome[x + 1][y] == 0 or biome[x - 1][y] == 0 or biome[x][y + 1] == 0 or biome[x][y - 1] == 0))
					{
						if (x < mapWidth)
						{
							if (biome[x + 1][y] == 0)
							{
								biome[x + 1][y] = 100;
							}
						}
						if (x > 0)
						{
							if (biome[x - 1][y] == 0)
							{
								biome[x - 1][y] = 100;
							}
						}
						if (y < mapHeight)
						{
							if (biome[x][y + 1] == 0)
							{
								biome[x][y + 1] = 100;
							}
						}
						if (y > 0)
						{
							if (biome[x][y - 1] == 0)
							{
								biome[x][y - 1] = 100;
							}
						}
					}
				}
			}

			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					if (biome[x][y] == 100)
					{
						biome[x][y] = 4;
					}
				}
			}
		}

void Map::createForestCities()
		{
			int x1, y1;
			for (int x = 6; x < 43; x++)
			{
				for (int y = 6; y < 41; y++)
				{
					int cityChance = 1;
					for (x1 = 0; x1 < 3; x1++)
					{
						for (y1 = 0; y1 < 3; y1++)
						{
							if (biome[x + x1 - 1][y + y1 - 1] != 4 or city[x + x1 - 1][y + y1 - 1] == 1 and x + x1 - 4 > 0 and x + x1 - 4 < mapWidth and y + y1 + 4 > 0 and y + y1 + 4 < mapHeight) cityChance = 0;
						}
					}
					for (x1 = 0; x1 < 9; x1++)
					{
						for (y1 = 0; y1 < 9; y1++)
						{
							if (x + x1 - 4 > 0 and x + x1 - 4 < mapWidth - 1 and y + y1 + 4 > 0 and y + y1 + 4 < mapHeight - 1 and city[x + x1 - 4][y + y1 - 4] == 1) cityChance = 0;
						}
					}
					if (cityChance == 1 and city[x][y] != 1 and rand() % 20 == 0)
					{
						city[x][y] = 1;
					}
				}
			}
		};

void Map::furtherCityGen()
		{
			int cityCount = 0;
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					if (city[x][y] == 1)
					{
						cityCount++;
						cityID[x][y] = cityCount;
					}
					cityGuardian[x][y] = 1;
				}
			}
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					for (int i = 0; i < 20; i++)
					{
						if (cityID[x][y] == i)
						{
							cityName[i] = genCityName();
						}
					}
				}
			}
		}

int Map::checkForCityCount()
		{
			int human = 0, orc = 0, elve = 0;
			for (int x = 0; x < mapWidth; x++)
			{
				for (int y = 0; y < mapHeight; y++)
				{
					if (city[x][y] == 1)
					{
						if (biome[x][y] == 0) human++;
						else if (biome[x][y] == 2) orc++;
						else if (biome[x][y] == 4) elve++;
					}
					path[x][y] = 0;
				}
			}
			if (human < 5 or orc < 3 or elve < 3) return 0;
			else return 1;
		}

void Map::generateMap()
		{
			srand(time(NULL));
			setBaseValues();
			while (checkForCityCount() == 0)
			{
				createBaseBiomes();
				createCities();
				createForests();
				createForestCities();
				furtherCityGen();
			}
		}

void Map::clearFog(Player &player1)
{
	int x1, y1;
	for (x1 = 0; x1 < 7; x1++)
	{
		for (y1 = 0; y1 < 5; y1++)
		{
			if (player1.x + x1 - 3 < mapWidth and player1.y + y1 - 2 < mapHeight and player1.x + x1 - 3 > 0 and player1.y + y1 - 2 > 0)
			{
				fog[player1.x + x1 - 3][player1.y + y1 - 2] = 0;
			}
		}
	}
	for (x1 = 0; x1 < 5; x1++)
	{
		for (y1 = 0; y1 < 7; y1++)
		{
			if (player1.x + x1 - 2 < mapWidth and player1.y + y1 - 3 < mapHeight and player1.x + x1 - 2 > 0 and player1.y + y1 - 3 > 0)
			{
				fog[player1.x + x1 - 2][player1.y + y1 - 3] = 0;
			}
		}
	}
}

int Map::getMapHeight()
{
	return mapHeight;
}
int Map::getMapWidth()
{
	return mapWidth;
}

void drawTile(sf::RenderWindow &window, sf::Texture texture, int x, int y, int textureRes = 48)
{
	if (x > 0 && x < 1064 && y > 0 && y < 704)
	{
		sf::Sprite tileSprite;
		tileSprite.setTexture(texture);
		tileSprite.setScale(textureRes / 16, textureRes / 16);
		tileSprite.setPosition(x, y);
		window.draw(tileSprite);
	}
}

void Map::viewMap(sf::RenderWindow &window, Player player)
{
	sf::Vector2u resolution = window.getSize();
	int mapWindowX = 960;
	int mapWindowY = 620;
	int textureRes = 48;
	int totalX, totalY;
	sf::Texture tPlains, tForest, tDesert, tMountains, tArctic, tPlayer, tCity, tInterface;
	sf::Sprite tileSprite, sInterface;
	tPlains.loadFromFile("Textures\\grass.png", sf::IntRect(0, 0, 16, 16));
	tForest.loadFromFile("Textures\\forest.png", sf::IntRect(0, 0, 16, 16));
	tDesert.loadFromFile("Textures\\desert.png", sf::IntRect(0, 0, 16, 16));
	tArctic.loadFromFile("Textures\\arctic.png", sf::IntRect(0, 0, 16, 16));
	tPlayer.loadFromFile("Textures\\player.png", sf::IntRect(0, 0, 16, 16));
	for (int u = 0; u < mapHeight; u++)
	{
		for (int c = 0; c < mapWidth; c++)
		{
			totalX = (c - player.x) * (textureRes)+(mapWindowX / 2) + 70 - textureRes / 2;
			totalY = (u - player.y) * (textureRes)+(mapWindowY / 2) + 50 - textureRes / 2;
			if (biome[c][u] == 0)
			{
				if (city[c][u] == 1)
				{
					tCity.loadFromFile("Textures\\grasscity.png", sf::IntRect(0, 0, 16, 16));
					drawTile(window, tCity, totalX, totalY);
				}
				else drawTile(window, tPlains, totalX, totalY);
			}
			else if (biome[c][u] == 1)
			{
				if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] == 1 and biome[c][u + 1] != 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(16, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] == 1 and biome[c][u + 1] != 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(32, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] != 1 and biome[c][u + 1] != 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(48, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] != 1 and biome[c][u + 1] == 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(64, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] != 1 and biome[c][u + 1] == 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(80, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] != 1 and biome[c][u + 1] != 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(96, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] == 1 and biome[c][u + 1] != 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(112, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] == 1 and biome[c][u + 1] == 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(128, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] == 1 and biome[c][u + 1] == 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(144, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] != 1 and biome[c][u + 1] == 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(160, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] == 1 and biome[c][u + 1] == 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(176, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] != 1 and biome[c][u + 1] != 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(192, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] == 1 and biome[c][u + 1] != 1 and biome[c][u - 1] == 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(208, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] == 1 and biome[c + 1][u] != 1 and biome[c][u + 1] == 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(224, 0, 16, 16));
				else if (u + 1 < mapHeight and u - 1 >= 0 and c + 1 < mapWidth and c - 1 >= 0 and biome[c - 1][u] != 1 and biome[c + 1][u] == 1 and biome[c][u + 1] == 1 and biome[c][u - 1] != 1) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(240, 0, 16, 16));
				else tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(0, 0, 16, 16));
				drawTile(window, tMountains, totalX, totalY);
			}
			else if (biome[c][u] == 2)
			{
				if (city[c][u] == 1)
				{
					tCity.loadFromFile("Textures\\desertcity.png", sf::IntRect(0, 0, 16, 16));
					drawTile(window, tCity, totalX, totalY);
				}
				else drawTile(window, tDesert, totalX, totalY);
			}
			else if (biome[c][u] == 3) drawTile(window, tArctic, totalX, totalY);
			else if (biome[c][u] == 4)
			{
				if (city[c][u] == 1)
				{
					tCity.loadFromFile("Textures\\forestcity.png", sf::IntRect(0, 0, 16, 16));
					drawTile(window, tCity, totalX, totalY);
				}
				else drawTile(window, tForest, totalX, totalY);
			}

			if (player.x == c and player.y == u) drawTile(window, tPlayer, totalX, totalY);
		}
	}
}