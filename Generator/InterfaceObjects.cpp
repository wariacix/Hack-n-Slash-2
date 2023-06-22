#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "General.h"
#include "GameObject.h"
#include "InterfaceObjects.h"

void menuButton::setTitle(std::wstring input)
{
	title.setString(input);
}