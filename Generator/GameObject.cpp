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
	sprite.setTexture(texture);
	sprite.setScale(5.f, 5.f);
	sprite.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
	sprite.setPosition(x, y);
}

void hns::GameObject::changeSprite(sf::Texture& sprTexture)
{
	sprite.setTexture(sprTexture);
}

void hns::GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void hns::GameObject::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	sprite.setPosition(x, y);
}

bool hns::GameObject::isHovered(sf::RenderWindow& window)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	if (mouse.x >= x && mouse.x <= x + (sizeX * 5) && mouse.y >= y && mouse.y <= y + (sizeY * 5)) return true;
	else return false;
}

bool hns::GameObject::isClicked(sf::RenderWindow& window)
{
	if (isHovered(window) == true and sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == true) return true;
	else return false;
}
