#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Map.h"
#include "Player.h"
void drawInterface(sf::RenderWindow& window);
void cityEnter(sf::RenderWindow& window, Map& mainMap, Player& mainPlayer);
#ifndef choice_h
#define choice_h
int choice(sf::RenderWindow& window, std::wstring choiceString[6], int& choice);
#endif

