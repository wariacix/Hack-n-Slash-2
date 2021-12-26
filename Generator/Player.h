#pragma once
#include "Map.h"
#include <string>

class Map;

class Player
{
public:
	int x, y;
	int gold;
	int hpRegen;
	int mpRegen;
	float hp;
	float mp;
	int maxmp;
	int maxhp;
	int dodgeChance;
	int def;
	int dmg;
	int str;
	int in;
	int lvl;
	int reqexp;
	double xp;
	std::wstring heroName;
	Player()
	{
		gold = 0;
		x = 24;
		y = 23;
		hpRegen = 1;
		mpRegen = 1;
		hp = 1;
		mp = 1;
		maxmp = 20;
		maxhp = 100;
		dodgeChance = 5;
		def = 8;
		dmg = 11;
		str = 10;
		in = 10;
		lvl = 1;
		reqexp = 500;
		xp = 0;
		heroName = L"NO NAME";
	}
	void movePlayer(Map &map1);
};
extern Player mainPlayer;