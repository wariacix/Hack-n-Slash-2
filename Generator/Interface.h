#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "menu.h"
#include "variables.h"
#include "GameObject.h"
#include "Player.h"
 
class Player;

namespace hns
{
	class Bar : public GameObject
	{
	protected:
		sf::Texture frontTexture;
		sf::Sprite frontSpr;
	public:
		Bar(Player player = Player(), int x = 40, int y = 10, int sizeX = 41, int sizeY = 5, std::string topTexName = "hpUItop", std::string botTexName = "hpUIbot")
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
		void setSize(float stat1, float stat2)
		{
			frontSpr.setTextureRect(sf::IntRect(0, 0, (stat1/stat2 * sizeX), sizeY));
		}

		void draw(sf::RenderWindow& window, float stat1, float stat2)
		{
			setSize(stat1, stat2);
			window.draw(sprite);
			window.draw(frontSpr);
		}
	};

	class Interface : public GameObject
	{
	private:
		Bar hpBar; Bar mpBar = Bar(Player(), 250, 10, 41, 5, "mpUItop", "mpUIbot");
	public:
		Interface(Player player = Player(), int x = 0, int y = 0, int sizeX = 320, int sizeY = 200, std::string texName = "interface")
		{
			this->GameObject::GameObject(x, y, sizeX, sizeY, texName);
			mpBar.setSize(player.mp, player.maxmp);
		}
		
		void draw(sf::RenderWindow& window, Player player)
		{
			GameObject::draw(window);
			hpBar.draw(window, player.hp, player.maxhp);
			mpBar.draw(window, player.mp, player.maxmp);
		}
	};
}