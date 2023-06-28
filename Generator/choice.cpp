#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "General.h"
#include "menu.h"
#include "variables.h"
#include "choice.h"
#include "Interface.h"
#include "equipment.h"

class hns::Interface;

using namespace std;

hns::Dialogue::Dialogue()
	{
		hasSoundBeenPlayed = false;
		font.loadFromFile("dpcomic.ttf");

		viewTexture.loadFromFile("Textures\\humanCityView.png");
		viewSprite.setTexture(viewTexture);
		viewSprite.setPosition(70.f, 50.f);
		viewSprite.setScale(5.f, 5.f);

		interfaceTexture.loadFromFile("Textures\\interface.png");
		interfaceSprite.setTexture(interfaceTexture);
		interfaceSprite.setPosition(0.f, 0.f);

		text.setFont(font);
		text.setFillColor(sf::Color{ 233,211,199,255 });
		text.setOutlineColor(sf::Color{ 23,8,0,255 });
		text.setOutlineThickness(2.f);

		buffer.loadFromFile("Sounds\\FANFARE.wav");
		enterSound.setBuffer(buffer);
	};

hns::Dialogue::Dialogue(std::string viewTextureName, std::string enterSoundName, std::string interfaceStr, std::string fontName)
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

hns::Dialogue::Dialogue(const hns::Dialogue& copiedDialogue)
	{
		hasSoundBeenPlayed = false;
		font = copiedDialogue.font;
		viewTexture = copiedDialogue.viewTexture;
		viewSprite = copiedDialogue.viewSprite;
		interfaceTexture = copiedDialogue.interfaceTexture;
		interfaceSprite = copiedDialogue.interfaceSprite;
		text = copiedDialogue.text;
		buffer = copiedDialogue.buffer;
		enterSound = copiedDialogue.enterSound;
	};

int hns::Dialogue::getDialogueAnswer(sf::RenderWindow& window, Player player, hns::Interface ui, wstring choiceString[6], bool playSound)
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

		sf::Texture buttonT;
		buttonT.loadFromFile("Textures\\button.png", sf::IntRect(0, 0, 51, 11));
		sf::Sprite buttonS;
		buttonS.setTexture(buttonT);

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

			getDialogueAnswerTick(buttonS, numberOfButtons, choice, choiceString, window, player, ui);

			window.display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				Sleep(150);
				return choice;
			}
		}
		los = true;
		return 999;
	}

void hns::Dialogue::getDialogueAnswerTick(sf::Sprite& buttonS, int& numberOfButtons, int& choice, wstring choiceString[6], sf::RenderWindow& window, Player player, hns::Interface ui)
{
	drawView(window);
	drawInterface(window, player, ui);

	for (int i = 0; i < numberOfButtons; i++)
	{
		if (choice == i) buttonS.setColor(sf::Color{ 252,255,0,255 });
		else buttonS.setColor(sf::Color::White);
		buttonS.setScale(5.f, 5.f);

		if (numberOfButtons == 2 or numberOfButtons == 4)
		{
			if (i < 2)
			{
				buttonS.setPosition(290.f + (i * 260), 780.f);
			}
			else
			{
				buttonS.setPosition(290.f + ((i - 2) * 260), 840.f);
			}
			window.draw(buttonS);

			text.setCharacterSize(24);
			text.setString(choiceString[i]);

			if (i < 2)
			{
				text.setPosition(305.f + (i * 260), 790.f);
			}
			else
			{
				text.setPosition(305.f + ((i - 2) * 260), 850.f);
			}
			window.draw(text);
		}
		else
		{
			if (i < 3)
			{
				buttonS.setPosition(165.f + (i * 260), 780.f);
			}
			else
			{
				buttonS.setPosition(165.f + ((i - 3) * 260), 840.f);
			}
			window.draw(buttonS);

			text.setCharacterSize(24);
			text.setString(choiceString[i]);

			if (i < 3)
			{
				text.setPosition(180.f + (i * 260), 790.f);
			}
			else
			{
				text.setPosition(180.f + ((i - 3) * 260), 850.f);
			}
			window.draw(text);
		}
	}


	//Choice manipulation
	if (numberOfButtons == 2 or numberOfButtons == 4)
	{
		int sleepTime = 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && choice >= 1)
		{
			choice--; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && choice < numberOfButtons - 1)
		{
			choice++; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && choice - 2 >= 0)
		{
			choice = choice - 2; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && choice + 2 < numberOfButtons)
		{
			choice = choice + 2; Sleep(sleepTime);
		}
	}
	else
	{
		int sleepTime = 100;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && choice >= 1)
		{
			choice--; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && choice < numberOfButtons - 1)
		{
			choice++; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && choice - 3 >= 0)
		{
			choice = choice - 3; Sleep(sleepTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && choice + 3 < numberOfButtons)
		{
			choice = choice + 3; Sleep(sleepTime);
		}
	}
}

void hns::Dialogue::playViewSound()
		{
			if (hasSoundBeenPlayed == false)
			{
				hasSoundBeenPlayed = true;
				enterSound.play();
			}
		}

void hns::Dialogue::drawView(sf::RenderWindow& window)
{
	window.draw(viewSprite);
}

void hns::Dialogue::drawInterface(sf::RenderWindow& window, Player player, hns::Interface ui)
{
	ui.hns::Interface::Draw(window, player);
}

void hns::Dialogue::textWriting(wstring input, sf::Text textEnt, sf::RenderWindow& window, Map mainMap, Player mainPlayer)
	{
		sf::Clock clock;

		wstring* text = new wstring(input);
		int a = 0; int lines = 0; int lineLength = 56;
		const wchar_t* textArray = text->c_str();
		float sec = 3.0f;

		for (int i = 1; i < wcslen(textArray); i++)
		{
			sf::Event event;
			a = 0;
			lines = 0;
			int charsLeft = i;
			window.clear();
			while (window.pollEvent(event)) if (event.type == sf::Event::KeyPressed) sec = 1.f;
			mainMap.ViewMap(window, mainPlayer, clock);
			while (charsLeft > 0)
			{
				if (a > lineLength)
				{
					lines++;
					a = a - lineLength - 1;

				}
				while (true) { sf::Time time = clock.getElapsedTime(); if (time.asMilliseconds() > sec) break; };
				textEnt.setString(textArray[a + (lines * lineLength)]);
				textEnt.setPosition(160 + 12 * a, 755 + lines * 23);
				window.draw(textEnt);
				a++;
				charsLeft--;
			}
			window.display();
		}
		delete text;
	}

void CityEnter(sf::RenderWindow& window, Map &mainMap, Player &mainPlayer, hns::Equipment &mainEquipment, hns::Interface &mainInterface)
{
	hns::Dialogue cityDialogue;
	if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 0) cityDialogue.Dialogue::Dialogue("humanCityView", "FANFARE", "interface", "dpcomic");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 2) cityDialogue.Dialogue::Dialogue("orcCityView", "HORN3", "interface", "dpcomic");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4) cityDialogue.Dialogue::Dialogue("forestCityView", "GARDENS3", "interface", "dpcomic");

	hns::Shop alchemyShop(3, 4, "alchemy"), armorerShop(4, 4, "armorer"), blacksmithShop(4, 4, "blacksmith"), jewelerShop(4,4, "jeweler");

	int exit = false;
	while (exit == false)
	{
		switch (cityDialogue.getDialogueAnswer(window, mainPlayer, mainInterface, new (std::wstring[]){ L"Enter the City",L"Get Back to Main Map",L"",L"",L"",L"" }, 1))
		{
		case 0:
			switch (cityDialogue.getDialogueAnswer(window, mainPlayer, mainInterface, new (std::wstring[]){ L"Alchemist",L"Armorer",L"Blacksmith",L"Jeweler",L"Exit the City",L"",L""}))
			{
			case 0:
				alchemyShop.viewEquipment(window, mainPlayer, mainEquipment);
				break;
			case 1:
				armorerShop.viewEquipment(window, mainPlayer, mainEquipment);
				break;
			case 2:
				blacksmithShop.viewEquipment(window, mainPlayer, mainEquipment);
				break;
			case 3:
				jewelerShop.viewEquipment(window, mainPlayer, mainEquipment);
				break;
			case 4:
				exit = true;
				break;
			case 999:
				break;
			}
			break;
		case 1:
			exit = true;
			break;
		case 999:
			break;
		}
	}
}