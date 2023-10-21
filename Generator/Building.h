#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "General.h"

class hns::Building
{
private:
	std::string dialogueName;
	int level;
public:
	Building()
	{

	}
	virtual void Enter();
};
