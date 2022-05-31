#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "GameObject.h"
#include "Map.h"
#include "Player.h"

hns::GameObject::GameObject(int x, int y, int sizeX, int sizeY, std::string texName)
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

void hns::GameObject::changeSprite(sf::Texture sprTexture)
{
	sprite.setTexture(sprTexture);
}

void hns::GameObject::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}