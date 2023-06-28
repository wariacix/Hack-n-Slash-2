#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "GameObject.h"
#include "General.h"
class hns::Menu
{
private:
	hns::GameObject background = GameObject(0, 0, 320, 200, "UI\\mainMenu");
	hns::GameObject redButton = GameObject(36*5, 75*5, 103, 20, "UI\\redScroll");
	hns::GameObject blueButton = GameObject(36 * 5, 99 * 5, 103, 20, "UI\\blueScroll");
	hns::GameObject yellowButton = GameObject(36 * 5, 147 * 5, 83, 20, "UI\\yellowScroll");
public:
	void Draw(sf::RenderWindow &window);
	
	void Start(sf::RenderWindow& window);
};