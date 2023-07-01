#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"
#include "InterfaceObjects.h"

void MenuButton::SetTitle(std::wstring input)
{
	title.setString(input);
}

void MenuButton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(title);
}