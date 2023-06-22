#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"

class hns::menuButton : public GameObject
{
	sf::Font font;
	sf::Text title;
	int textSize = 24;

	void draw(sf::RenderWindow& window);
	void setTitle(std::wstring input);
};