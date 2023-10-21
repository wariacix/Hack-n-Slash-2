#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "General.h"
#include "Player.h"

class hns::City
{
private:
	std::string name;
	CityType type;
public:
	City()
	{
		name = "unnamed";
		type = human;
	}
};

enum CityType
{
	human = 0,
	orc = 1,
	elve = 2,
	viking = 3,
	goblin = 4
};