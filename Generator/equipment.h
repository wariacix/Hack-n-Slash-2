#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h"

class Player;

namespace equipmentSystem
{
	class Item
	{
	private:
		int id;
		int addedHp;
		int addedMp;
		int hpRegen;
		int mpRegen;
		int dmg;
		int def;
		int strReq;
		int inReq;
		int lvlReq;
		int mpReq;
		int numOfItems;
		sf::Color color;
		std::wstring itemName;
	public:
		Item(int id = -1, int addedHp = 0, int addedMp = 0, int hpRegen = 0, int mpRegen = 0, int dmg = 0, int def = 0, int strReq = 0, int inReq = 0, int lvlReq = 0, int mpReq = 0, int numOfItems = -1, int rColor = 255, int gColor = 255, int bColor = 0, std::wstring itemName = L"error")
		{
			this->id = id;
			this->addedHp = addedHp;
			this->addedMp = addedMp;
			this->hpRegen = hpRegen;
			this->mpRegen = mpRegen;
			this->dmg = dmg;
			this->def = def;
			this->strReq = strReq;
			this->inReq = inReq;
			this->lvlReq = lvlReq;
			this->mpReq = mpReq;
			this->numOfItems = numOfItems;
			this->color = sf::Color(rColor, gColor, bColor, 255);
			this->itemName = itemName;
		};

		int getItemId();

		int getItemAddedHp();

		int getItemAddedMp();

		int getItemHpRegen();

		int getItemMpRegen();

		int getItemDmg();

		int getItemDef();

		int getItemStrReq();

		int getItemInReq();

		int getItemLvlReq();

		int getItemMpReq();

		int getItemCount();

		sf::Color getItemColor();

		std::wstring getItemName();

		void setItemCount(int set);

		void addItemCount(int add);
	};

	class Equipment
	{
	private:
		const int equipmentWidth = 10;
		const int equipmentHeight = 6;
		int numOfItems;

		std::wstring loadItemStats();

		void drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring name, int& k, int x, int y, sf::Color color);

		void drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring statStr, int& k, int value, int x, int y, sf::Color green, sf::Color red);

		void drawItemInfo(sf::RenderWindow& window, sf::Text text, std::wstring statStr, int& k, int requiredVal, int x, int y, int value, sf::Color green, sf::Color red);

		void drawItemSprite(sf::RenderWindow& window, int x, int y, int id);

		void setItem(Item item);

	public:
		Item* equippedItem;
		Item* eqItem;
		Equipment()
		{
			numOfItems = 1;
			eqItem = new Item[9999];
			equippedItem = new Item[3];
			addItem(1000, 1);
			addItem(2000, 1);
			addItem(3000, 1);
		}

		void addItem(int id, int howManyItems);
		void updateStats(Player& player);
		void viewEquipment(sf::RenderWindow& window, Player& player);
		int getNumOfItems();
		void itemDeletion(int id);
		void itemSwapping(Item& item, int type);
		void addNumOfItems(int add);
		void equipItem(Item& item, Player& player);
		void viewItemStats(sf::RenderWindow& window, Item& item, int x, int y);
	};
}