#include "Fight.h"

hns::Enemy::Enemy(int id, std::wstring name, float damage, float hp, float maxhp)
{
	this->id = id;
	this->name = name;
	this->damage = damage;
	this->hp = hp;
	this->maxhp = maxhp;
}

hns::Fight::Fight(hns::Enemy enemy)
{
	this->enemy = enemy;
}