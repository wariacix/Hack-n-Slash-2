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
	void setSize(float stat1, float stat2, bool vertical = false, bool inverted = false);
	void Draw(sf::RenderWindow& window, float stat1, float stat2, bool vertical = false, bool inverted = false);
};

class hns::Interface : public hns::GameObject
{
private:
	hns::Bar hpBar; hns::Bar mpBar = hns::Bar(Player(), 250, 10, 41, 5, "mpUItop", "mpUIbot");
	hns::Bar xpBar = hns::Bar(Player(), 1585, 0, 3, 200, "xpBarFull", "xpBarEmpty");
	hns::TextObject goldIndicator = TextObject(920, 5, 20, 7, "goldBar", 30, sf::Color(255, 197, 0, 255), "test", 10, -4, sf::Color::Black, 2.0f);
	hns::TextObject levelIndicator = TextObject(1450, 0, 27, 7, "levelBar", 27, sf::Color(83, 225, 0, 255), "test", 25, 0, sf::Color::Black, 2.0f);
public:
	Interface(Player player = Player(), int x = 0, int y = 0, int sizeX = 320, int sizeY = 200, std::string texName = "interface");
	
	void Draw(sf::RenderWindow& window, Player player);
};