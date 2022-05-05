#pragma once
#include "General.h"

class hns::Enemy
{
	int id;
	std::wstring name;
	float damage;
	float hp;
	float maxhp;
public:
	Enemy(int id = 0, std::wstring name = L"Wolf", float damage = 10, float hp = 75, float maxhp = 75);
};

class hns::Fight
{
	hns::Enemy enemy;
public:
	Fight(hns::Enemy enemy = Enemy());
};
