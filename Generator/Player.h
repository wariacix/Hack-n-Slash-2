#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "equipment.h"
#include "General.h"

class hns::Equipment;
class hns::Map;

class hns::Player
{
public:
	int x;
	int y;
	int gold;
	int hpRegen;
	int mpRegen;
	float hp;
	float mp;
	int maxmp;
	int maxhp;
	int def;
	int dmg;
	int str;
	int in;
	int agi;
	int crit;
	int lvl;
	int reqexp;
	double xp;
	bool alive;
	bool hasBeenPressed[4];
	std::wstring heroName;
	Player()
	{
		gold = 0;
		x = 24;
		y = 23;
		hpRegen = 1;
		mpRegen = 1;
		hp = 100;
		mp = 8;
		maxmp = 20;
		maxhp = 100;
		def = 8;
		dmg = 11;
		str = 10;
		in = 10;
		agi = 1;
		crit = 3;
		lvl = 1;
		reqexp = 500;
		xp = 0;
		for (int i = 0; i < 4; i++) hasBeenPressed[i] = false;
		heroName = L"NO NAME";
		alive = true;
	}
	void movePlayer(Map &map1, sf::RenderWindow& window, hns::Equipment &eq, Player& player);
	void Regenerate();
private:
	void CheckForKeyActivity(sf::RenderWindow& window);
};
extern hns::Player mainPlayer;