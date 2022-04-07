#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

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

		int getItemCount();

		int getItemId();

		void addItemCount(int add);
	};

	class Equipment
	{
	private:
		const int equipmentWidth = 10;
		const int equipmentHeight = 6;
		int numOfItems;
		std::wstring loadItemStats();
		void drawItemSprite(sf::RenderWindow& window, int x, int y, int id);
	public:
		Item* eqItem;
		Equipment()
		{
			numOfItems = 1;
			eqItem = new Item[9999];
		}

		void addItem(int id, int howManyItems);
		int getNumOfItems();
		void addNumOfItems(int add);
		void viewEquipment(sf::RenderWindow& window);
		void setItem(Item item);
	};
}
void equipmentSFML(sf::RenderWindow& window);