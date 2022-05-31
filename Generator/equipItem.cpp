#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
#include "equipment.h"
#include "menu.h"
#include "Player.h"
#include "variables.h"
#include "choice.h"

using namespace std;


void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring name, int& k, int x, int y, sf::Color color)
{
	text.setFillColor(color);

	text.setCharacterSize(24);
	text.setPosition(259.f + x, 138.f + y + (k * 25));
	text.setString(name);
	window.draw(text);
	k++;
}

void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring statStr, int& k, int value, int x, int y, sf::Color green, sf::Color red)
{
	if (value >= 0) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + to_wstring(value));
	window.draw(text);
	k++;
}

void drawItemInfo(sf::RenderWindow& window, sf::Text text, wstring statStr, int& k, int requiredVal, int x, int y, int value, sf::Color green, sf::Color red)
{
	if (value >= requiredVal) text.setFillColor(green);
	else text.setFillColor(red);

	text.setCharacterSize(18);
	text.setPosition(260.f + x, 148.f + y + (k * 18));
	text.setString(statStr + to_wstring(requiredVal));
	window.draw(text);
	k++;
}