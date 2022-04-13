#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Map.h"
#include "Player.h"

namespace hns
{
	class GameObject
	{
	protected:
		int x, y;
		int sizeX, sizeY;
	public:
		sf::Texture texture;
		sf::Sprite sprite;
		GameObject(int x = 0, int y = 0, int sizeX = 320, int sizeY = 200, std::string texName = "interface")
		{
			this->x = x;
			this->y = y;
			this->sizeX = sizeX;
			this->sizeY = sizeY;
			texture.loadFromFile("Textures\\" + texName + ".png");
			sprite.setScale(5.f, 5.f);
			sprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
			sprite.setPosition(x, y);
			sprite.setTexture(texture);
		}

		void changeSprite(sf::Texture sprTexture)
		{
			sprite.setTexture(sprTexture);
		}

		void draw(sf::RenderWindow& window)
		{
			window.draw(sprite);
		}
	};
}