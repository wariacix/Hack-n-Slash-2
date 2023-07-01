#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "GameObject.h"
#include "General.h"
#include "InterfaceObjects.h"
class hns::Menu
{
private:
	hns::GameObject background = GameObject(0, 0, 320, 200, "UI\\mainMenu");
	hns::MenuButton redButton = MenuButton(36*5, 75*5, 103, 20, "UI\\redScroll", 48, "Start a new game");
	hns::MenuButton blueButton = MenuButton(36 * 5, 99 * 5, 103, 20, "UI\\blueScroll", 48, "Load the game");
	hns::MenuButton yellowButton = MenuButton(36 * 5, 147 * 5, 83, 20, "UI\\yellowScroll", 48, "Exit");
public:
	void Draw(sf::RenderWindow &window);
	
	void Start(sf::RenderWindow& window);
};