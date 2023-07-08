#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"

class hns::TextObject : public GameObject
{
protected:
	sf::Font font;
	sf::Text title;
	int textSize;
public:
	TextObject(int x, int y, int sizeX, int sizeY, std::string texName, int textSize, sf::Color color, std::string titleName, int xOffset = 84, int yOffset = 13, sf::Color outlineColor = sf::Color::Black, float outlineSize = 0.0f)
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
		title.setFillColor(color);
		title.setOutlineColor(outlineColor);
		title.setOutlineThickness(outlineSize);
	}

	void Draw(sf::RenderWindow& window);
	void SetTitle(std::wstring input);
};

class hns::Cursor
{
public:
	static sf::Texture texture, textureClicked;
	static sf::Sprite sprite;
	
	hns::Cursor()
	{
		texture = sf::Texture();
		textureClicked = sf::Texture();
		sprite = sf::Sprite();
		texture.loadFromFile("Textures\\cursor.png");
		textureClicked.loadFromFile("Textures\\cursorClicked.png");
		sprite.setTexture(texture);
		sprite.setScale(4.0f, 4.0f);
	}

	static void Draw(sf::RenderWindow& window);
};