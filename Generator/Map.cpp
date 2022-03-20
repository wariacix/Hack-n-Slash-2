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
#include "gotoxy.h"
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
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
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
						if (rand() % 5 > 1 and x < 48) biome[x + 1][y] = 1;
						if (rand() % 5 > 1 and x > 0) biome[x - 1][y] = 1;
						if (rand() % 5 > 1 and y < 46) biome[x][y + 1] = 1;
						if (rand() % 5 > 1 and y > 0) biome[x][y - 1] = 1;
						if (rand() % 5 > 0 and x < 48 and y < 46) biome[x + 1][y + 1] = 1;
						if (rand() % 5 > 0 and x > 0 and y < 46) biome[x - 1][y + 1] = 1;
						if (rand() % 5 > 0 and x < 48 and y > 0) biome[x + 1][y - 1] = 1;
						if (rand() % 5 > 0 and x > 0 and y > 0) biome[x - 1][y - 1] = 1;
					}
				}
			}
			hero[24][23] = 1;
		};

void Map::enlargeMountains()
		{
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
				{
					if (x > 0 and x < 48 and y > 0 and y < 46 and biome[x][y] == 1 and biome[x + 1][y] == 0 and biome[x - 1][y] == 0 and biome[x][y - 1] == 0 and biome[x][y + 1] == 0) biome[x][y] = 0;
					if (x > 0 and x < 48 and y > 0 and y < 46 and biome[x][y] == 0 and biome[x + 1][y] == 1 and biome[x - 1][y] == 1 and biome[x][y - 1] == 1 and biome[x][y + 1] == 1) biome[x][y] = 1;
				}
			}
		};

void Map::createDeserts()
		{
			for (x = 0; x < 48; x++)
			{
				if (rand() % 2 == 0) biome[x][36] = 2;
				for (y = 37; y < 46; y++)
				{
					biome[x][y] = 2;
				}
			}
		};

void Map::createArctic()
		{
			for (x = 0; x < 48; x++)
			{
				if (rand() % 2 == 0) biome[x][5] = 3;
				for (y = 0; y < 5; y++) biome[x][y] = 3;
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
			for (x = 6; x < 43; x++)
			{
				for (y = 6; y < 41; y++)
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
				x = rand() % 43;
				y = rand() % 41;
				int cityChance = 0;
				for (x1 = 0; x1 < 15; x1++)
				{
					for (y1 = 0; y1 < 15; y1++)
					{
						if (city[x + x1 - 7][y + y1 - 7] == 1) cityChance++;
					}
				}
				if (cityChance > 1) city[x][y] = 0;
			}
			for (x = 0; x < 48; x++)
			{
				city[x][44] = 0;
				city[x][45] = 0;
				city[x][46] = 0;
			}
			for (y = 0; y < 46; y++)
			{
				city[0][y] = 0;
				city[1][y] = 0;
				city[2][y] = 0;
				city[3][y] = 0;
				city[4][y] = 0;
			}
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
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
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
				{
					int forestChance = 1;
					for (x1 = 0; x1 < 3; x1++)
					{
						for (y1 = 0; y1 < 3; y1++)
						{
							if (biome[x + x1 - 1][y + y1 - 1] != 0 and biome[x + x1 - 1][y + y1 - 1] != 1) forestChance = 0;
						}
					}
					for (x1 = 0; x1 < 9; x1++)
					{
						for (y1 = 0; y1 < 9; y1++)
						{
							if (city[x + x1 - 4][y + y1 - 4] != 0) forestChance = 0;
						}
					}
					if (forestChance == 1 and rand() % 14 == 0 and x > 0 and y > 0 and y < 46 and x < 48)
					{
						for (x1 = 0; x1 < 3; x1++)
						{
							for (y1 = 0; y1 < 3; y1++)
							{
								if (biome[x + x1 - 1][y + y1 - 1] == 0) biome[x + x1 - 1][y + y1 - 1] = 4;
							}
						}
					}
				}
			}

			for (x = 1; x < 47; x++)
			{
				for (y = 1; y < 45; y++)
				{
					if (biome[x][y] == 4 and (biome[x + 1][y] == 0 or biome[x - 1][y] == 0 or biome[x][y + 1] == 0 or biome[x][y - 1] == 0))
					{
						if (x < 48)
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
						if (y < 46)
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

			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
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
			for (x = 6; x < 43; x++)
			{
				for (y = 6; y < 41; y++)
				{
					int cityChance = 1;
					for (x1 = 0; x1 < 3; x1++)
					{
						for (y1 = 0; y1 < 3; y1++)
						{
							if (biome[x + x1 - 1][y + y1 - 1] != 4 or city[x + x1 - 1][y + y1 - 1] == 1 and x + x1 - 4 > 0 and x + x1 - 4 < 48 and y + y1 + 4 > 0 and y + y1 + 4 < 46) cityChance = 0;
						}
					}
					for (x1 = 0; x1 < 9; x1++)
					{
						for (y1 = 0; y1 < 9; y1++)
						{
							if (city[x + x1 - 4][y + y1 - 4] == 1 and x + x1 - 4 > 0 and x + x1 - 4 < 48 and y + y1 + 4 > 0 and y + y1 + 4 < 46) cityChance = 0;
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
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
				{
					if (city[x][y] == 1)
					{
						cityCount++;
						cityID[x][y] = cityCount;
					}
					cityGuardian[x][y] = 1;
				}
			}
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
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
			for (x = 0; x < 48; x++)
			{
				for (y = 0; y < 46; y++)
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

void Map::generatePaths()
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			int minion[48][46];
			bool hasCityBeenPathed[48][46];
			int howManyPaths = 0;
		chuj:
			bool success = false;
			int rep = 0;
			while (success == false)
			{
			back2:
				for (x = 0; x < 48; x++)
					for (y = 0; y < 46; y++) hasCityBeenPathed[x][y] = false;
				int x1, y1, x2, y2;
				x1 = -1, x2 = -1, y1 = -1, y2 = -1;
				bool citySearchingSuccess = false;
				while (citySearchingSuccess == false)
				{
					x = rand() % 48, y = rand() % 46;
					if (city[x][y] == 1)
					{
						if (x1 == -1 and y1 == -1)
						{
							x1 = x, y1 = y;
						}
						else if (x2 == -1 and y2 == -1 and hasCityBeenPathed[x][y] == false and (x1 != x2 and y1 != y2))
						{
							x2 = x, y2 = y;
							citySearchingSuccess = true;
						}
					}
				}
				if (x1 == x2 and y1 == y2) goto back2;
				double fDistance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
				int requestedDistance = fDistance;
				if (requestedDistance <= 6) requestedDistance = requestedDistance + 3;
				else if (requestedDistance > 6 and requestedDistance <= 10) requestedDistance = requestedDistance + 5;
				else if (requestedDistance > 10 and requestedDistance <= 14) requestedDistance = requestedDistance + 7;
				else if (requestedDistance > 14) goto back2;
				int measuredDistance = 0;
				rep = 0;
				int xr, yr;
				if (debugMode == 1)
				{
					SetConsoleTextAttribute(hConsole, 30);
					gotoxy(2 * x1, y1 + 4);
					wcout << L"C1";
					gotoxy(2 * x2, y2 + 4);
					wcout << L"C2";
					gotoxy(0, 0);
					wcout << L"Iteration: ";
					gotoxy(30, 0);
					wcout << requestedDistance << L"  ";
				}
				bool repAdded = false;
			cancel:
				while (success == false)
				{
					rep++;
					if (debugMode == 1)
					{
						gotoxy(12, 0);
						wcout << rep;
					}
					if (rep > 25000 and repAdded == false)
					{
						repAdded = true;
						requestedDistance = requestedDistance + 2;
					}
					if (rep > 50000)
					{
						SetConsoleTextAttribute(hConsole, 15);
						gotoxy(12, 0);
						wcout << L"                ";
						goto back2;
					}
					SetConsoleTextAttribute(hConsole, 1);
					for (x = 0; x < 48; x++)
					{
						for (y = 0; y < 46; y++)
						{
							minion[x][y] = 0;
						}
					}
					minion[x1][y1] = 2;
					measuredDistance = 0;
					int turn = 0;
					while (measuredDistance <= requestedDistance)
					{
						for (x = 0; x < 48; x++)
						{
							for (y = 0; y < 46; y++)
							{
								if (minion[x][y] == 2)
								{
									bool hasBeenMountain = false;
									int innerTurn = 0;
								back:
									if (measuredDistance > requestedDistance) goto cancel;
									int xrand = rand() % 3 - 1;
									int yrand = rand() % 3 - 1;
									xr = xrand + x;
									yr = yrand + y;
									if (abs(xrand) == abs(yrand)) goto back;
									innerTurn++;
									if (innerTurn > 15) goto cancel;
									if (biome[xr][yr] == 1)
									{
										hasBeenMountain = true;
										goto back;
									}
									int bezpiecznik = 0;
									for (int o = -1; o < 1; o++)
									{
										for (int p = -1; p < 1; p++)
										{
											if (minion[xr + o][yr + p] == 1) bezpiecznik++;
										}
									}
									if (bezpiecznik > 1) goto cancel;
									if ((xr < 1 or xr > 47 or yr < 1 or yr > 45) or (minion[xr][yr] == 1 or minion[xr][yr] == 2 or path[xr][yr] == 1)) goto back;
									if ((xr > 2 and xr < 46 and yr > 2 and yr < 44) and success == false and (minion[xr][yr] != 1 and minion[xr][yr] != 2) and biome[xr][yr] != 1)
									{
										minion[x][y] = 1;
										minion[xr][yr] = 2;
										measuredDistance++;
										if (hasBeenMountain == true)
										{
											hasBeenMountain = false;
											requestedDistance++;
										}
										turn = 0;
									}
									else goto back;
									turn++;
									if (x2 == xr and y2 == yr)
									{
										if (measuredDistance > requestedDistance) goto cancel;
										minion[xr][yr] = 1;
										success = true;
										howManyPaths++;
										if (debugMode == 1)
										{
											gotoxy(37, 0);
											SetConsoleTextAttribute(hConsole, 14);
											wcout << measuredDistance << L"  ";
										}
										goto done;
									}
								}
								if (turn > 30) goto cancel;
							}
						}
					}
				}
			}
		done:
			if (debugMode == 1)
			{
				for (x = 0; x < 48; x++)
				{
					for (y = 0; y < 46; y++)
					{
						SetConsoleTextAttribute(hConsole, 120);
						gotoxy(2 * x, y + 4);
						if (biome[x][y] == 1) wcout << L"/\\";
						else
						{
							if (minion[x][y] == 1)
							{
								SetConsoleTextAttribute(hConsole, 68);
								wcout << L"##";
							}
							else
							{
								if (path[x][y] == 1)
								{
									SetConsoleTextAttribute(hConsole, 170);
									wcout << L"##";
								}
							}
						}
					}
				}
				SetConsoleTextAttribute(hConsole, 15);
				gotoxy(12, 0);
				wcout << L"                ";
				Sleep(550);
			}

			for (x = 0; x < 48; x++)
				for (y = 0; y < 46; y++) if (minion[x][y] != 0) path[x][y] = 1;

			if (howManyPaths < 2) goto chuj;
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
			generatePaths();
		}

void Map::viewMap()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int u = 0; u < 46; u++)
	{
		for (int c = 0; c < 48; c++)
		{
			gotoxy(2 * c, u + 4);
			switch (fog[c][u])
			{
			case 0:
				switch (hero[c][u])
				{
				case 0:
					switch (city[c][u])
					{
					case 0:
						switch (biome[c][u]) //0,68,170
						{
						case 0:
							SetConsoleTextAttribute(hConsole, 162);
							if (path[c][u] == 0)
							{
								srand((c + u) * (c - u) * u + 2);
								int random = rand() % 8;
								if (random == 0) wcout << L"vv";
								else if (random == 1) wcout << L"~v";
								else if (random == 2) wcout << L"v~";
								else wcout << L"~~";
								srand(time(NULL));
							}
							else if (path[c][u] == 1)
							{
								SetConsoleTextAttribute(hConsole, 166);
								wcout << L"##";
							}
							break;
						case 1:
							if (biome[c][u] == 1 and c < 47 and c > 1 and biome[c + 1][u] == 1 or biome[c - 1][u] != 1)
							{
								SetConsoleTextAttribute(hConsole, 120);
							}
							else SetConsoleTextAttribute(hConsole, 135);
							if (path[c][u] == 0) wcout << L"/\\";
							else if (path[c][u] == 1)
							{
								SetConsoleTextAttribute(hConsole, 118);
								wcout << L"##";
							}
							break;
						case 2:
							SetConsoleTextAttribute(hConsole, 230);
							if (path[c][u] == 0) wcout << L"~~";
							else if (path[c][u] == 1)
							{
								wcout << L"##";
							}
							break;
						case 3:
							SetConsoleTextAttribute(hConsole, 251);
							if (path[c][u] == 0) wcout << L"~~";
							else if (path[c][u] == 1)
							{
								SetConsoleTextAttribute(hConsole, 246);
								wcout << L"##";
							}
							break;
						case 4:
							SetConsoleTextAttribute(hConsole, 32);
							if (path[c][u] == 0) wcout << L"##";
							else if (path[c][u] == 1)
							{
								SetConsoleTextAttribute(hConsole, 38);
								wcout << L"##";
							}
							break;
						}
						break;
					case 1:
						int id;
						id = cityID[c][u];
						if (biome[c][u] == 0) SetConsoleTextAttribute(hConsole, 15);
						else if (biome[c][u] == 2) SetConsoleTextAttribute(hConsole, 14);
						else if (biome[c][u] == 4) SetConsoleTextAttribute(hConsole, 10);
						wcout << L"[]";
						bool isHidden = false;
						for (int h = -2; h < 6; h++)
						{
							if (c + h >= 0 and u - 2 >= 0 and c + h <= 48 and u - 2 <= 46)
							{
								if (hero[c + h][u - 2] == 1) isHidden = true;
							}
						}
						if (isHidden == false) gotoxy(2 * c - 2, u + 2);
						else if (isHidden == true) gotoxy(2 * c - 2, u + 1);
						wcout << cityName[id];
						break;
					}
					break;
				case 1:
					SetConsoleTextAttribute(hConsole, 240);
					wcout << L"☺↑";
					break;
				}
				break;
			case 1:
				SetConsoleTextAttribute(hConsole, 8);
				wcout << L"??";
				break;
			}
		}
	}
}

void Map::clearFog(Player &player1)
{
	int x1, y1;
	for (x1 = 0; x1 < 7; x1++)
	{
		for (y1 = 0; y1 < 5; y1++)
		{
			if (player1.x + x1 - 3 < 48 and player1.y + y1 - 2 < 46 and player1.x + x1 - 3 > 0 and player1.y + y1 - 2 > 0)
			{
				fog[player1.x + x1 - 3][player1.y + y1 - 2] = 0;
			}
		}
	}
	for (x1 = 0; x1 < 5; x1++)
	{
		for (y1 = 0; y1 < 7; y1++)
		{
			if (player1.x + x1 - 2 < 48 and player1.y + y1 - 3 < 46 and player1.x + x1 - 2 > 0 and player1.y + y1 - 3 > 0)
			{
				fog[player1.x + x1 - 2][player1.y + y1 - 3] = 0;
			}
		}
	}
}

void Map::viewMapSFML(sf::RenderWindow &window, Player player)
{
	sf::Vector2u resolution = window.getSize();
	int mapWindowX = 960;
	int mapWindowY = 620;
	int textureRes = 48;
	sf::Texture tPlains, tForest, tDesert, tMountains, tArctic, tPlayer, tCity, tInterface;
	sf::Sprite tileSprite, sInterface;
	tPlains.loadFromFile("Textures\\grass.png", sf::IntRect(0, 0, 16, 16));
	tForest.loadFromFile("Textures\\forest.png", sf::IntRect(0, 0, 16, 16));
	tDesert.loadFromFile("Textures\\desert.png", sf::IntRect(0, 0, 16, 16));
	tArctic.loadFromFile("Textures\\arctic.png", sf::IntRect(0, 0, 16, 16));
	tPlayer.loadFromFile("Textures\\player.png", sf::IntRect(0, 0, 16, 16));
	for (int u = 0; u < 46; u++)
	{
		for (int c = 0; c < 48; c++)
		{
			if (biome[c][u] == 0)
			{
				if (city[c][u] == 1)
				{
					tCity.loadFromFile("Textures\\grasscity.png", sf::IntRect(0, 0, 16, 16));
					tileSprite.setTexture(tCity);
					tileSprite.setScale(textureRes/16, textureRes / 16);
					tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
					window.draw(tileSprite);
				}
				else
				{
					tileSprite.setTexture(tPlains);
					tileSprite.setScale(textureRes / 16, textureRes / 16);
					tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
					window.draw(tileSprite);
				}
			}
			else if (biome[c][u] == 1)
			{
				if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(16, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(32, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(48, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(64, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(80, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(96, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(112, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(128, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(144, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(160, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(176, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(192, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] != 1 and u + 1 < 46 and biome[c][u - 1] == 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(208, 0, 16, 16));
				else if (biome[c - 1][u] == 1 and c + 1 > 0 and biome[c + 1][u] != 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(224, 0, 16, 16));
				else if (biome[c - 1][u] != 1 and c + 1 > 0 and biome[c + 1][u] == 1 and c - 1 < 48 and biome[c][u + 1] == 1 and u + 1 < 46 and biome[c][u - 1] != 1 and u - 1 > 0) tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(240, 0, 16, 16));
				else tMountains.loadFromFile("Textures\\mountains.png", sf::IntRect(0, 0, 16, 16));
				tileSprite.setTexture(tMountains);
				tileSprite.setScale(textureRes / 16, textureRes / 16);
				tileSprite.setPosition((c - player.x) * (textureRes) + (mapWindowX / 2) + 70, (u - player.y) * (textureRes) + (mapWindowY / 2) + 50);
				window.draw(tileSprite);
			}
			else if (biome[c][u] == 2)
			{
				if (city[c][u] == 1)
				{
					tCity.loadFromFile("Textures\\desertcity.png", sf::IntRect(0, 0, 16, 16));
					tileSprite.setTexture(tCity);
					tileSprite.setScale(textureRes / 16, textureRes / 16);
					tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
					window.draw(tileSprite);
				}
				else
				{
					tileSprite.setTexture(tDesert);
					tileSprite.setScale(textureRes / 16, textureRes / 16);
					tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
					window.draw(tileSprite);
				}
			}
			else if (biome[c][u] == 3)
			{
				tileSprite.setTexture(tArctic);
				tileSprite.setScale(textureRes / 16, textureRes / 16);
				tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
				window.draw(tileSprite);
			}
			else if (biome[c][u] == 4)
			{
				tileSprite.setTexture(tForest);
				tileSprite.setScale(textureRes / 16, textureRes / 16);
				tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
				window.draw(tileSprite);
			}
			if (player.x == c and player.y == u)
			{
				tileSprite.setTexture(tPlayer);
				tileSprite.setScale(textureRes / 16, textureRes / 16);
				tileSprite.setPosition((c - player.x) * (textureRes)+(mapWindowX / 2) + 70, (u - player.y) * (textureRes)+(mapWindowY / 2) + 50);
				window.draw(tileSprite);
			}
		}
	}
	tInterface.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 1600, 1000));
	sInterface.setTexture(tInterface);
	sInterface.setPosition(0.f, 0.f);
	window.draw(sInterface);
}