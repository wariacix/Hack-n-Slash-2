#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "General.h"
#include "Player.h"

class Player;
using namespace hns;

class hns::Item
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
	int value;
	int numOfItems;
	sf::Color color;
	std::wstring itemName;
public:
	Item(int id = -1, int addedHp = 0, int addedMp = 0, int hpRegen = 0, int mpRegen = 0, int dmg = 0, int def = 0, int strReq = 0, int inReq = 0, int lvlReq = 0, int mpReq = 0, int value = 0, int numOfItems = -1, int rColor = 255, int gColor = 255, int bColor = 0, std::wstring itemName = L"error")
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
		this->value = value;
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

	int getItemValue();

	int getItemCount();

	sf::Color getItemColor();

	std::wstring getItemName();

	void setItemCount(int set);

	void addItemCount(int add);
};

class hns::Equipment
{
private:
	virtual void viewItemStats(sf::RenderWindow& window, Item& item, int x, int y);

protected:
	int equipmentWidth = 10;
	int equipmentHeight = 6;
	int numOfItems;

	std::string eqName, bottomTxt, topTxt;

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
		bottomTxt = "eqInterfaceBottom";
		topTxt = "eqInterfaceTop";
		eqName = "Data\\itemStats";
		numOfItems = 1;
		eqItem = new Item[9999];
		equippedItem = new Item[8];
	}

	void addItem(int id, int howManyItems);
	void updateStats(Player& player);
	virtual void viewEquipment(sf::RenderWindow& window, Player& player);
	int getNumOfItems();
	void itemDeletion(int id);
	void itemSwapping(Item& item, int type);
	void addNumOfItems(int add);
	void equipItem(Item& item, Player& player);
	bool checkItemRequirements(Item item, Player& player);
};

class hns::Shop : public hns::Equipment
{
private:
	float priceMultiplier;
	std::string shopName;
	void viewItemStats(sf::RenderWindow& window, hns::Item& item, int x, int y);
public:
	Shop(int equipmentWidth, int equipmentHeight, std::string fileName, float priceMultiplier = 1.20f, std::string shopName = "alchemyUI") : Equipment::Equipment()
	{
		this->equipmentWidth = equipmentWidth;
		this->equipmentHeight = equipmentHeight;
		this->priceMultiplier = priceMultiplier;
		this->shopName = shopName;
		bottomTxt = shopName + "bot";
		topTxt = shopName + "top";
		std::wstring shopStats = loadFileString("Data\\Shop\\" + fileName);
		std::wstring currentId = L"";

		for (int i = 0; i < shopStats.size(); i++)
		{
			if (shopStats[i] == *L";")
			{
				addItem(stoi(currentId), 9999);
				currentId = L"";
			}
			else currentId = currentId + shopStats[i];
		}
	}

	void viewEquipment(sf::RenderWindow& window, Player& player, Equipment& playerEq);
	void buyItem(Player& player, Item& item, Equipment& playerEq);

	std::wstring getShopName();
};