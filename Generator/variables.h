#pragma once
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
	int id;
	int addedHp;
	int addedMp;
	int hpRegen;
	int mpRegen;
	int dmg;
	int def;
	int strReq;
	int inReq;
	int lvlReq;
	int mpReq;
	int color;
	std::wstring itemName;
};
extern items weapon;
extern items armor;
extern items shield;
extern items selectedItem;