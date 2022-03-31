#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Map.h"
#include "Player.h"
int choiceSFML(sf::RenderWindow& window, std::wstring choiceString[6], int &choice);
void drawInterface(sf::RenderWindow& window);
void cityEnter(sf::RenderWindow& window, Map& mainMap, Player& mainPlayer);
#ifndef choice_h
#define choice_h
int choice(std::wstring wstring1, std::wstring wstring2, std::wstring wstring3, std::wstring wstring4, std::wstring wstring5, std::wstring wstring6, int numberOfOptions);
#endif

