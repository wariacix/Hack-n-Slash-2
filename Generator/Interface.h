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
#include "Player.h"
#include "General.h"
#include "menu.h"
#include "variables.h"
#include "GameObject.h"
 
class Player;

class hns::Bar : public hns::GameObject
{
protected:
	sf::Texture frontTexture;
	sf::Sprite frontSpr;
public:
	Bar(Player player = Player(), int x = 40, int y = 10, int sizeX = 41, int sizeY = 5, std::string topTexName = "hpUItop", std::string botTexName = "hpUIbot");
	void setSize(float stat1, float stat2);
	void Draw(sf::RenderWindow& window, float stat1, float stat2);
};

class hns::Interface : public hns::GameObject
{
private:
	Bar hpBar; Bar mpBar = Bar(Player(), 250, 10, 41, 5, "mpUItop", "mpUIbot");
public:
	Interface(Player player = Player(), int x = 0, int y = 0, int sizeX = 320, int sizeY = 200, std::string texName = "interface");
	
	void Draw(sf::RenderWindow& window, Player player);
};