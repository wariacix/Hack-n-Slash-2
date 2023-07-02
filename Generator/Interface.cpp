#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include "menu.h"
#include "General.h"
#include "variables.h"
#include "choice.h"
#include "Interface.h"
#include "GameObject.h"

//BAR

hns::Bar::Bar(Player player, int x, int y, int sizeX, int sizeY, std::string topTexName, std::string botTexName)
{
	this->GameObject::GameObject(x, y, sizeX, sizeY, botTexName);
	frontTexture.loadFromFile("Textures\\" + topTexName + ".png");
	frontTexture.setRepeated(true);
	texture.setRepeated(true);
	frontSpr.setTexture(frontTexture);
	frontSpr.setPosition(x, y);
	frontSpr.setScale(5.f, 5.f);
	setSize(player.hp, player.maxhp);
}

void hns::Bar::setSize(float stat1, float stat2)
{
	frontSpr.setTextureRect(sf::IntRect(0, 0, (stat1 / stat2 * sizeX), sizeY));
}

void hns::Bar::Draw(sf::RenderWindow& window, float stat1, float stat2)
{
	setSize(stat1, stat2);
	window.draw(sprite);
	window.draw(frontSpr);
}

//INTERFACE

hns::Interface::Interface(Player player, int x, int y, int sizeX, int sizeY, std::string texName)
{
	this->GameObject::GameObject(x, y, sizeX, sizeY, texName);
	mpBar.setSize(player.mp, player.maxmp);
}

void hns::Interface::Draw(sf::RenderWindow& window, Player player)
{
	GameObject::Draw(window);
	hpBar.Draw(window, player.hp, player.maxhp);
	mpBar.Draw(window, player.mp, player.maxmp);
}