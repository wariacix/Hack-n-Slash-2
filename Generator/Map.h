#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player;

class Map
{
public:
	int biome[48][46];
	int city[48][46];
	int hero[48][46];
	int fog[48][46];
	int path[48][46];

	Map()
	{
		for (int x = 0; x < 48; x++)
		{
			for (int y = 0; y < 46; y++)
			{
				biome[x][y] = 0;
				city[x][y] = 0;
				hero[x][y] = 0;
				fog[x][y] = 1;
				path[x][y] = 0;
			}
		}
	};

	std::wstring genCityName();

	void clearFog(Player& player1);

	void viewMapSFML(sf::RenderWindow &window, Player player);

	void setBaseValues();

	void enlargeMountains();

	void createDeserts();

	void createArctic();

	void createBaseBiomes();

	void createCities();

	void createForests();

	void createForestCities();

	void furtherCityGen();

	int checkForCityCount();

	void generatePaths();

	void generateMap();
};
