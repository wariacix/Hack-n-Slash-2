#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "Map.h"
void textWritingSFML(std::wstring input, sf::Text textEnt, sf::RenderWindow& window, Map mainMap, Player mainPlayer);
#ifndef textbox_h
#define textbox_h
void textboxAnimation();
void textbox(int txtBoxType, int npcId);
#endif