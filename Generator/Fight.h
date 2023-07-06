#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "General.h"
#include "Player.h"
#include "choice.h"
#include "Interface.h"
#include "InterfaceObjects.h"

class hns::Enemy
{
public:
	int id;
	std::wstring name;
	float damage;
	float hp;
	float maxhp;
	int xp;
	int gold;
	Enemy(int id = 0, std::wstring name = L"Wolf", float damage = 10, float hp = 75, float maxhp = 75, int xp = 250, int gold = 30);
	void loadEnemy(std::string fileName);
};

class hns::Fight
{
	hns::Enemy enemy;
	std::string sprName;
	sf::Sprite sprite;
	void viewBackground(sf::RenderWindow& window);
public:
	Fight(hns::Enemy enemy = Enemy(), std::string sprName = "forest.png");
	void start(sf::RenderWindow& window, Player& mainPlayer, hns::Interface mainInterface, hns::Equipment& mainEquipment);
};

class hns::FightDialogue : public hns::Dialogue
{
public:
	FightDialogue(std::string viewTextureName, std::string enterSoundName, std::string interfaceStr, std::string fontName);
	int getDialogueAnswer(sf::RenderWindow& window, Player player, Enemy enemy, hns::FightDiary diary, hns::Interface ui, std::wstring choiceString[6], bool playSound);
};

class hns::FightDiary
{
	sf::Font font;
	sf::Text textField[36];
public:
	FightDiary()
	{
		font.loadFromFile("dpcomic.ttf");
		for (int i = 0; i < 36; i++)
		{
			textField[i].setFont(font);
			textField[i].setFillColor(sf::Color::Yellow);
			textField[i].setOutlineColor(sf::Color::Black);
			textField[i].setOutlineThickness(2.0f);
			textField[i].setString("");
			textField[i].setCharacterSize(20.0f);
			textField[i].setPosition(1175 + 10, 50 + (i * 25));
		}
	}

	void Push(std::wstring string, sf::Color inColor = sf::Color::Yellow, sf::Color outColor = sf::Color::Black);
	void Draw(sf::RenderWindow& window);
};
