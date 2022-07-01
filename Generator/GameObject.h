#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "Map.h"
#include "Player.h"

class hns::GameObject
{
protected:
	int x, y;
	int sizeX, sizeY;
public:
	sf::Texture texture;
	sf::Sprite sprite;
	GameObject(int x = 0, int y = 0, int sizeX = 320, int sizeY = 200, std::string texName = "interface");

	void changeSprite(sf::Texture& sprTexture);

	void draw(sf::RenderWindow& window);

	bool isHovered(sf::RenderWindow& window);
	bool isClicked(sf::RenderWindow& window);
};

class hns::menuButton : public GameObject
{
	sf::Font font;
	sf::Text title;
};