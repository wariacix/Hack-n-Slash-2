#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player;

class ExtendedTexture
{
public:
	sf::Texture mainTexture;
	sf::Sprite mainSprite;
	std::string name;
	ExtendedTexture(sf::Texture mainTexture, std::string name)
	{
		this->mainTexture = mainTexture;
		this->name = name;
	}
	ExtendedTexture()
	{
		mainTexture.create(16,16);
		name = "null";
	}
};

class Map
{
private:
	int mapWidth;
	int mapHeight;
	std::string mapName;
	std::vector<ExtendedTexture> mapTextures;
public:
	std::vector<std::vector<int>> biome;
	std::vector<std::vector<int>> city;
	std::vector<std::vector<int>> cityID;
	std::vector<std::vector<int>> cityGuardian;
	std::vector<std::vector<int>> hero;
	std::vector<std::vector<int>> fog;
	std::vector<std::vector<int>> path;

	Map(std::string mapName = "default", int mW = 48, int mH = 46)
	{
		mapWidth = mW;
		mapHeight = mH;
		this->mapName = mapName;

		mapTextures.begin();
		biome.resize(mW, std::vector<int>(mH, 0));
		city.resize(mW, std::vector<int>(mH, 0));
		cityID.resize(mW, std::vector<int>(mH, 0));
		cityGuardian.resize(mW, std::vector<int>(mH, 0));
		hero.resize(mW, std::vector<int>(mH, 0));
		fog.resize(mW, std::vector<int>(mH, 1));
		path.resize(mW, std::vector<int>(mH, 0));
	};

	std::wstring GenCityName();

	int getMapWidth();
	int getMapHeight();

	void ClearFog(Player& player1);

	sf::Texture ChooseConnectedTexture(int c, int u, int biomeId, std::vector<std::vector<int>> valueType, std::string fileName, sf::RenderWindow& window, Player player);

	sf::Texture LookForTexture(std::string name);

	void ViewMap(sf::RenderWindow &window, Player player, sf::Clock& clock);

	void BakeTextures();

	void Initialize();

	void SetBaseValues();

	void EnlargeMountains();

	void CreateDeserts();

	void CreateArctic();

	void CreateBaseBiomes();

	void CreateCities();

	void CreateForests();

	void CreateForestCities();

	void FurtherCityGen();

	int CheckForCityCount();

	void generatePaths();

	void GenerateMap();

	void AssignNewTexture(std::string name, sf::IntRect intRect);
};
