#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Fight.h"
#include "choice.h"
#include "Player.h"

class Player;
class hns::Dialogue;

hns::Enemy::Enemy(int id, std::wstring name, float damage, float hp, float maxhp, int xp, int gold)
{
	this->id = id;
	this->name = name;
	this->damage = damage;
	this->hp = hp;
	this->maxhp = maxhp;
	this->xp = xp;
	this->gold = gold;
}

void hns::Enemy::loadEnemy(std::string fileName)
{
	std::wstring load = loadFileString("Data\\Enemies\\" + fileName);
	std::wstring stats[6];
	int numOfEnemies = 0;

	int a = 0;
	bool hasItemStatBeenRead = false;
	bool addedItem = false;

	for (int i = 0; i < load.size(); i++)
	{
		if (hasItemStatBeenRead == true)
		{
			for (int u = 0; u < 6; u++) stats[u] = L"";
			hasItemStatBeenRead = false;
		}

		if (load[i] == *L",")
		{
			a++;
		}
		else if (load[i] == *L";")
		{

			i++;
			a = 0;
			hasItemStatBeenRead = true;
			numOfEnemies++;
		}
		else stats[a] = stats[a] + load[i];
	}

	int chooseEnemy = rand() % numOfEnemies;

	for (int i = 0; i < load.size(); i++)
	{
		if (hasItemStatBeenRead == true)
		{
			for (int u = 0; u < 6; u++) stats[u] = L"";
			hasItemStatBeenRead = false;
		}

		if (load[i] == *L",")
		{
			a++;
		}
		else if (load[i] == *L";")
		{
			if (std::stoi(stats[0]) == chooseEnemy)
			{
				name = stats[1];
				damage = std::stoi(stats[2]);
				maxhp = std::stoi(stats[3]);
				hp = maxhp;
				xp = std::stoi(stats[4]);
				gold = std::stoi(stats[5]);
			}
			i++;
			a = 0;
			hasItemStatBeenRead = true;
		}
		else stats[a] = stats[a] + load[i];
	}
}

hns::Fight::Fight(hns::Enemy enemy, std::string sprName)
{
	this->enemy = enemy;
	this->sprName = sprName;
}

void hns::Fight::viewBackground(sf::RenderWindow &window)
{
	sf::Texture texture;
	texture.loadFromFile("Textures\\" + sprName);
	sprite.setTexture(texture);
	window.draw(sprite);
}

void hns::Fight::start(sf::RenderWindow &window, Player &mainPlayer, hns::Interface mainInterface, hns::Equipment &mainEquipment)
{
	hns::FightDialogue fightDialogue("forestView", "GARDENS3", "interface", "dpcomic");
	bool left = false;
	while (left == false)
	{
		switch (fightDialogue.getDialogueAnswer(window, mainPlayer, enemy, mainInterface, new (std::wstring[]){ L"Attack",L"Equipment",L"Try to Break Free",L"",L"",L"" }, false))
		{
		case 0:
			mainPlayer.hp -= enemy.damage;
			enemy.hp -= mainPlayer.dmg;
			break;
		case 1:
			mainEquipment.viewEquipment(window, mainPlayer);
			break;
		case 2:
			if (rand() % 4 == 0) left = true;
			else mainPlayer.hp -= enemy.damage;
			break;
		case 999:
			break;
		}
		if (mainPlayer.hp <= 0)
		{
			left = true;
			mainPlayer.alive = false;
		}
		else if (enemy.hp <= 0)
		{
			left = true;
			mainPlayer.gold += enemy.gold;
			mainPlayer.xp += enemy.xp;
			if (mainPlayer.xp > 250 + (mainPlayer.lvl * 250))
			{
				mainPlayer.xp -= 250 + (mainPlayer.lvl * 250);
				mainPlayer.lvl++;
				std::wcout << L"Level up!" << std::endl;
			}
		}
	}
}

hns::FightDialogue::FightDialogue(std::string viewTextureName, std::string enterSoundName, std::string interfaceStr, std::string fontName)
{
	hasSoundBeenPlayed = false;
	font.loadFromFile(fontName + ".ttf");

	viewTexture.loadFromFile("Textures\\" + viewTextureName + ".png");
	viewSprite.setTexture(viewTexture);
	viewSprite.setPosition(70.f, 50.f);
	viewSprite.setScale(5.f, 5.f);

	interfaceTexture.loadFromFile("Textures\\" + interfaceStr + ".png");
	interfaceSprite.setTexture(interfaceTexture);
	interfaceSprite.setPosition(0.f, 0.f);

	text.setFont(font);
	text.setFillColor(sf::Color{ 233,211,199,255 });
	text.setOutlineColor(sf::Color{ 23,8,0,255 });
	text.setOutlineThickness(2.f);

	buffer.loadFromFile("Sounds\\" + enterSoundName + ".wav");
	enterSound.setBuffer(buffer);

};

int hns::FightDialogue::getDialogueAnswer(sf::RenderWindow& window, Player player, Enemy enemy, hns::Interface ui, std::wstring choiceString[6], bool playSound)
{
	int numberOfButtons = 0;
	for (int i = 0; i < 6; i++)
	{
		numberOfButtons++;
		if (choiceString[i] == L"")
		{
			numberOfButtons--;
		}
	}

	int choice = 0; // Starting at first button

	sf::Font font;
	font.loadFromFile("dpcomic.ttf");
	sf::Text enemyText;
	enemyText.setOutlineThickness(3.f);
	enemyText.setFont(font);
	enemyText.setString(enemy.name);
	enemyText.setPosition(550 - 6 * enemy.name.length(),90);

	bool clickFlag = false;

	hns::GameObject button(290, 780, 51, 11, "button");

	if (playSound == true) playViewSound();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(1);
			}
		}

		window.clear();

		getDialogueAnswerTick(clickFlag, button, numberOfButtons, choice, choiceString, window, player, ui);
		
		window.draw(enemyText);

		hns::Bar enemyBar = Bar(Player(), 400, 60, 61, 5, "enemyUIbot", "enemyUItop");
		enemyBar.Draw(window, enemy.hp, enemy.maxhp);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) or clickFlag == true)
		{
			Sleep(100);
			return choice;
		}
	}
	los = true;
	return 999;
}