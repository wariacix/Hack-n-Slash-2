#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player;

class Map
{
private:
	int mapWidth = 48;
	int mapHeight = 46;
public:
	std::vector<std::vector<int>> biome;
	std::vector<std::vector<int>> city;
	std::vector<std::vector<int>> cityID;
	std::vector<std::vector<int>> cityGuardian;
	std::vector<std::vector<int>> hero;
	std::vector<std::vector<int>> fog;
	std::vector<std::vector<int>> path;

	Map(int mW = 48, int mH = 46)
	{
		mapWidth = mW;
		mapHeight = mH;
		biome.resize(mW, std::vector<int>(mH, 0));
		city.resize(mW, std::vector<int>(mH, 0));
		cityID.resize(mW, std::vector<int>(mH, 0));
		cityGuardian.resize(mW, std::vector<int>(mH, 0));
		hero.resize(mW, std::vector<int>(mH, 0));
		fog.resize(mW, std::vector<int>(mH, 1));
		path.resize(mW, std::vector<int>(mH, 0));
	};

	std::wstring genCityName();

	int getMapWidth();
	int getMapHeight();

	void clearFog(Player& player1);

	void viewMap(sf::RenderWindow &window, Player player);

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
