#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"

class hns::MenuButton : public GameObject
{
protected:
	sf::Font font;
	sf::Text title;
	int textSize;
public:
	MenuButton(int x, int y, int sizeX, int sizeY, std::string texName, int textSize, std::string titleName, int xOffset = 84, int yOffset = 13)
	{
		this->x = x;
		this->y = y;
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->textSize = textSize;

		texture.loadFromFile("Textures\\" + texName + ".png");
		sprite.setScale(5.f, 5.f);
		sprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
		sprite.setPosition(x, y);
		sprite.setTexture(texture);

		font.loadFromFile("dpcomic.ttf");

		title.setFont(font);
		title.setString(titleName);
		title.setCharacterSize(textSize);
		title.setPosition(x + xOffset, y + yOffset);
		title.setFillColor(sf::Color::White);
		title.setOutlineColor(sf::Color::Black);
		title.setOutlineThickness(2.f);
	}

	void Draw(sf::RenderWindow& window);
	void SetTitle(std::wstring input);
};