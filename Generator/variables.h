#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
extern int x, y, p;
extern int cityID[48][46];
extern int cityGuardian[48][46];
extern std::wstring cityName[30];
extern int mtnChance;
extern int text[50];
extern int fightMode;
extern int item[9999];
extern int armory[3];
extern bool los;
extern int debugMode;
extern std::wstring enemyName;

struct items
{
	int id = 0;
	int addedHp = 0;
	int addedMp = 0;
	int hpRegen = 0;
	int mpRegen = 0;
	int dmg = 0;
	int def = 0;
	int strReq = 0;
	int inReq = 0;
	int lvlReq = 0;
	int mpReq = 0;
	sf::Color color = sf::Color::White;
	std::wstring itemName = L" ";
};

extern items weapon;
extern items armor;
extern items shield;
extern items selectedItem;