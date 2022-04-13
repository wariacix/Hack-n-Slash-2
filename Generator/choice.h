#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Map.h"
#include "Player.h"
#include "Interface.h"

void drawInterface(sf::RenderWindow& window);
void cityEnter(sf::RenderWindow& window, Map& mainMap, Player& mainPlayer, equipmentSystem::Equipment &mainEquipment, hns::Interface& mainInterface);
#ifndef choice_h
#define choice_h
int choice(sf::RenderWindow& window, std::wstring choiceString[6], int& choice);
#endif

