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
#include "menu.h"
#include "variables.h"
#include "choice.h"

using namespace std;

namespace dialogueSystem
{
	class Dialogue
	{
	private:
		sf::Font font;
		sf::Texture viewTexture, interfaceTexture;
		sf::Sprite viewSprite, interfaceSprite;
		sf::SoundBuffer buffer;
		sf::Sound enterSound;
		sf::Text text;
	public:
		Dialogue()
		{
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

		Dialogue(std::string viewTextureName, std::string enterSoundName, std::string interfaceStr, std::string fontName)
		{
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

		Dialogue(dialogueSystem::Dialogue& copiedDialogue)
		{
			font = copiedDialogue.font;
			viewTexture = copiedDialogue.viewTexture;
			viewSprite = copiedDialogue.viewSprite;
			interfaceTexture = copiedDialogue.interfaceTexture;
			interfaceSprite = copiedDialogue.interfaceSprite;
			text = copiedDialogue.text;
			buffer = copiedDialogue.buffer;
			enterSound = copiedDialogue.enterSound;
		};
		
		int getDialogueAnswer(sf::RenderWindow& window, wstring choiceString[6], bool playSound = false)
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
						window.close();
				}

				window.clear();

				drawView(window);
				drawInterface(window);

				for (int i = 0; i < numberOfButtons; i++)
				{
					if (choice == i) buttonS.setColor(sf::Color{ 252,255,0,255 });
					else buttonS.setColor(sf::Color::White);
					buttonS.setScale(5.f, 5.f);
					if (i < 3)
					{
						if (numberOfButtons == 2 or numberOfButtons == 4) buttonS.setPosition(290.f + (i * 260), 780.f);
						else buttonS.setPosition(165.f + (i * 260), 780.f);
					}
					else
					{
						if (numberOfButtons == 2 or numberOfButtons == 4) buttonS.setPosition(290.f + (i * 260), 840.f);
						else buttonS.setPosition(165.f + ((i - 3) * 260), 840.f);
					}
					window.draw(buttonS);

					text.setCharacterSize(24);
					text.setString(choiceString[i]);

					if (i < 3)
					{
						if (numberOfButtons == 2 or numberOfButtons == 4) text.setPosition(305.f + (i * 260), 790.f);
						else text.setPosition(180.f + (i * 260), 790.f);
					}
					else
					{
						if (numberOfButtons == 2 or numberOfButtons == 4) text.setPosition(305.f + ((i - 3) * 260), 850.f);
						else text.setPosition(180.f + ((i - 3) * 260), 850.f);
					}
					window.draw(text);
				}
				window.display();


				//Choice manipulation
				int sleepTime = 40;
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					Sleep(60);
					return choice;
				}
			}
			return 999;
		}

		void playViewSound()
		{
			enterSound.play();
		}

		void drawView(sf::RenderWindow& window)
		{
			window.draw(viewSprite);
		}

		void drawInterface(sf::RenderWindow& window)
		{
			window.draw(interfaceSprite);
		}

		static void textWriting(wstring input, sf::Text textEnt, sf::RenderWindow& window, Map mainMap, Player mainPlayer)
		{
			sf::Clock clock;

			wstring* text = new wstring(input);
			int a = 0; int lines = 0; int lineLength = 56;
			const wchar_t* textArray = text->c_str();
			float sec = 3.f;

			for (int i = 1; i < wcslen(textArray); i++)
			{
				sf::Event event;
				a = 0;
				lines = 0;
				int charsLeft = i;
				window.clear();
				while (window.pollEvent(event)) if (event.type == sf::Event::KeyPressed) sec = 1.f;
				mainMap.viewMapSFML(window, mainPlayer);
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
	};
}

void drawInterface(sf::RenderWindow& window)
{
	sf::Texture tInterface;
	sf::Sprite sInterface;
	tInterface.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 1600, 1000));
	sInterface.setTexture(tInterface);
	sInterface.setPosition(0.f, 0.f);
	window.draw(sInterface);
}

void drawView(sf::RenderWindow& window, string fileName)
{
	sf::Texture tView;
	sf::Sprite sView;
	string folder = "Textures\\", extension = ".png";
	tView.loadFromFile(folder + fileName + extension, sf::IntRect(0, 0, 193, 125));
	sView.setTexture(tView);
	sView.setPosition(70.f, 50.f);
	sView.setScale(5.f, 5.f);
	window.draw(sView);
}

void cityEnter(sf::RenderWindow& window, Map &mainMap, Player &mainPlayer)
{
	dialogueSystem::Dialogue cityDialoguePlaceholder;
	if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 0) dialogueSystem::Dialogue cityDialoguePlaceholder("humanCityView", "FANFARE", "interface", "dpcomic");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 2) dialogueSystem::Dialogue cityDialoguePlaceholder("orcCityView", "HORN3", "interface", "dpcomic");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4) dialogueSystem::Dialogue cityDialoguePlaceholder("forestCityView", "GARDENS3", "interface", "dpcomic");
	dialogueSystem::Dialogue cityDialogue = cityDialoguePlaceholder;

	switch (cityDialogue.getDialogueAnswer(window, new (std::wstring[]){ L"Try to Enter The City",L"Get Back to Main Map",L"",L"",L"",L""}, 1))
	{
	case 0:
		switch (cityDialogue.getDialogueAnswer(window, new (std::wstring[]){ L"Try Entering by The Gate",L"Try Entering by Climbing",L"Go Back",L"",L"",L""}))
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 999:
			break;
		}
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 999:
		break;
	}
}