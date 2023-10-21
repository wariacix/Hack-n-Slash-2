#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class hns::Player;

enum Biome
{
	plains,
	mountains,
	desert,
	arctic,
	forest,
	cold_plains,
	cold_forest,
	temporary = 100
};

class ExtendedTexture
{
public:
	sf::Texture mainTexture;
	sf::Sprite mainSprite;
	std::string name;
	ExtendedTexture(sf::Texture mainTexture, sf::Sprite mainSprite, std::string name)
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

class hns::Map
{
private:
	int mapWidth;
	int mapHeight;
	std::string mapName;
	std::vector<ExtendedTexture> mapTextures;
public:
	std::vector<std::vector<Biome>> biome;
	std::vector<std::vector<int>> city;
	std::vector<std::vector<int>> cityID;
	std::vector<std::vector<int>> cityGuardian;
	std::vector<std::vector<int>> hero;
	std::vector<std::vector<int>> fog;
	std::vector<std::vector<int>> sprIndex;
	std::vector<std::vector<int>> path;

	Map(std::string mapName = "default", int mW = 48, int mH = 46)
	{
		mapWidth = mW;
		mapHeight = mH;
		this->mapName = mapName;

		mapTextures.begin();
		biome.resize(mW, std::vector<Biome>(mH, (Biome) 0));
		city.resize(mW, std::vector<int>(mH, 0));
		cityID.resize(mW, std::vector<int>(mH, 0));
		cityGuardian.resize(mW, std::vector<int>(mH, 0));
		hero.resize(mW, std::vector<int>(mH, 0));
		fog.resize(mW, std::vector<int>(mH, 1));
		sprIndex.resize(mW, std::vector<int>(mH, 0));
		path.resize(mW, std::vector<int>(mH, 0));
	};

	std::wstring GenCityName();

	int GetMapWidth();
	int GetMapHeight();

	void DrawTile(sf::RenderWindow& window, int sprIndex, int x, int y, int playerX, int playerY, int textureRes = 48);

	void ClearFog(Player& player1);

	int ChooseConnectedSpriteIndex(int c, int u, int biomeId, std::vector<std::vector<int>> valueType, std::string fileName);
	int ChooseConnectedSpriteIndex(int c, int u, int biomeId, std::vector<std::vector<Biome>> valueType, std::string fileName);

	sf::Texture LookForTexture(std::string name);

	sf::Sprite LookForSprite(std::string name);

	int LookForIndex(std::string name);

	void ViewMap(sf::RenderWindow &window, Player player, sf::Clock& clock);

	void PrepMap();

	void PrepTextures();

	void SetBaseValues();

	void Initialize();

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
