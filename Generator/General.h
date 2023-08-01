#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

namespace hns
{
	std::wstring loadFileString(std::string name);
	class Equipment;
	class Shop;
	class Item;
	class GameObject;
	class Interface;
	class Bar;
	class Fight;
	class Enemy;
	class Dialogue;
	class FightDialogue;
	class FightDiary;
	class FightReward;
	class Menu;
	class TextObject;
	class City;
	class Player;
	class Map;
	class Scroll;
	class ScrollList;
	static class Cursor;
}