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
#include "gotoxy.h"
#include "menu.h"
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"
#include "choice.h"

using namespace std;

void drawInterface(sf::RenderWindow& window)
{
	sf::Texture tInterface;
	sf::Sprite sInterface;
	tInterface.loadFromFile("Textures\\interface.png", sf::IntRect(0, 0, 1600, 1000));
	sInterface.setTexture(tInterface);
	sInterface.setPosition(0.f, 0.f);
	window.draw(sInterface);
}

void cityEnter(sf::RenderWindow& window, Map &mainMap, Player &mainPlayer)
{
	int choice = 0;
	sf::Texture tCityView;
	sf::Sprite sCityView;

	if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 0) tCityView.loadFromFile("Textures\\humanCityView.png", sf::IntRect(0, 0, 193, 125));
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 2) tCityView.loadFromFile("Textures\\orcCityView.png", sf::IntRect(0, 0, 193, 125));
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4) tCityView.loadFromFile("Textures\\forestCityView.png", sf::IntRect(0, 0, 193, 125));
	sCityView.setTexture(tCityView);
	sCityView.setPosition(70.f, 50.f);
	sCityView.setScale(5.f, 5.f);

	sf::SoundBuffer buffer;
	sf::Sound sound;
	if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 2) buffer.loadFromFile("Sounds\\HORN3.wav");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 0) buffer.loadFromFile("Sounds\\FANFARE.wav");
	else if (mainMap.biome[mainPlayer.x][mainPlayer.y] == 4) buffer.loadFromFile("Sounds\\GARDENS3.wav");
	sound.setBuffer(buffer);
	sound.play();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		bool exit = false;
		window.clear();
		window.draw(sCityView);
		drawInterface(window);
		switch (choiceSFML(window, new (std::wstring[]){ L"Try To Enter The City",L"Get Back To Main Map",L"",L"",L"",L""}, choice))
		{
		case 0:
			break;
		case 1:
			exit = true;
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
		window.display();
		if (exit == true) break;
	}
}

int choiceSFML(sf::RenderWindow &window, wstring choiceString[6], int &choice)
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

	//Gfx
	for (int i = 0; i < numberOfButtons; i++)
	{
		sf::Texture buttonT;
		buttonT.loadFromFile("Textures\\button.png", sf::IntRect(0, 0, 51, 11));
		sf::Sprite buttonS;
		buttonS.setTexture(buttonT);
		if (choice == i) buttonS.setColor(sf::Color{120,120,120,255});
		else buttonS.setColor(sf::Color::White);
		buttonS.setScale(5.f, 5.f);
		if (i < 3)
		{
			buttonS.setPosition(165.f + (i * 260), 780.f);
		}
		else
		{
			buttonS.setPosition(165.f + ((i - 3) * 260), 840.f);
		}
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

		sf::Font font;
		font.loadFromFile("dpcomic.ttf");

		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color{233,211,199,255});
		text.setOutlineColor(sf::Color{ 23,8,0,255 });
		text.setOutlineThickness(2.f);
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

	//Choice manipulation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && choice >= 1)
	{
		choice--;
		Sleep(30);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && choice < numberOfButtons - 1)
	{
		choice++;
		Sleep(30);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && choice - 3 >= 0)
	{
		choice = choice - 3;
		Sleep(30);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && choice + 3 < numberOfButtons)
	{
		choice = choice + 3;
		Sleep(30);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) return choice;
	return 999;
}

int choice(wstring wstring1, wstring wstring2, wstring wstring3, wstring wstring4, wstring wstring5, wstring wstring6, int numberOfOptions) {
	int optionChoice = 1;
	int choice1, choice2, choice3, choice4, choice5;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(numberOfOptions)
	{
	int options[6];
	case 2:
		options[0] = 1;
		options[1] = 0;
	loop1:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length()/2)*2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		choice1 = _getch();
		switch(choice1)
		{
		case 13:
			if (options[0] == 1 and options[1] == 0)
			{
				return optionChoice = 1;
			}
			else if (options[0] == 0 and options[1] == 1)
			{
				return optionChoice = 2;
			}
			break;
		case 115:
			if (options[0] == 0) options[0] = 1;
			else if (options[0] == 1) options[0] = 0;
			if (options[1] == 0) options[1] = 1;
			else if (options[1] == 1) options[1] = 0;
			break;
		case 119:
			if (options[0] == 0) options[0] = 1;
			else if (options[0] == 1) options[0] = 0;
			if (options[1] == 0) options[1] = 1;
			else if (options[1] == 1) options[1] = 0;
			break;
		}
		goto loop1;
		break;
	case 3:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
	loop2:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 34 - (wstring3.length() / 2), 41);
			else gotoxy(26 + 34 - (wstring3.length() / 2) - 1, 41);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 34 - (wstring3.length() / 2), 41);
			else gotoxy(26 + 34 - (wstring3.length() / 2) - 1, 41);
			wcout << wstring3;
		}
		choice2 = _getch();
		switch (choice2)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			break;
		case 115:
			if (options[0] == 0 and options[1] == 0 and options[2] == 1)
			{
				options[0] = 1;
				options[2] = 0;
			}
			else if (options[0] == 1 and options[1] == 0 and options[2] == 0)
			{
				options[0] = 0;
				options[1] = 1;
			}
			else if (options[0] == 0 and options[1] == 1 and options[2] == 0)
			{
				options[1] = 0;
				options[2] = 1;
			}
			break;
		case 119:
			if (options[0] == 0 and options[1] == 0 and options[2] == 1)
			{
				options[1] = 1;
				options[2] = 0;
			}
			else if (options[0] == 1 and options[1] == 0 and options[2] == 0)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[0] == 0 and options[1] == 1 and options[2] == 0)
			{
				options[1] = 0;
				options[0] = 1;
			}
			break;
		}
		goto loop2;
		break;
	case 4:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
	loop3:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 115:
			if (options[0] == 1 or options[2] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
			}
			else if (options[1] == 1 or options[3] == 1)
			{
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 119:
			if (options[0] == 1 or options[2] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
			}
			else if (options[1] == 1 or options[3] == 1)
			{
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		}
		goto loop3;
		break;
	case 5:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
		options[4] = 0;
	loop4:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		if (options[4] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 35 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 35 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		else if (options[4] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 35 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 35 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			else if (options[4] == 1)
			{
				return optionChoice = 5;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 115:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[3] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[4] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[4] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[0] = 1;
			}
			break;
		case 119:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[4] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[4] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[0] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[1] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[3] = 1;
			}
			break;
		}
		goto loop4;
		break;
	case 6:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
		options[4] = 0;
		options[5] = 0;
	loop5:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		if (options[4] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                  ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 17 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 17 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		else if (options[4] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                  ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 17 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 17 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		if (options[5] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 41);
			wcout << "                                  ";
			if ((wstring6.length() / 2) * 2 == wstring6.length()) gotoxy(26 + 52 - (wstring6.length() / 2), 41);
			else gotoxy(26 + 52 - (wstring6.length() / 2) - 1, 41);
			wcout << wstring6;
		}
		else if (options[5] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 41);
			wcout << "                                  ";
			if ((wstring6.length() / 2) * 2 == wstring6.length()) gotoxy(26 + 52 - (wstring6.length() / 2), 41);
			else gotoxy(26 + 52 - (wstring6.length() / 2) - 1, 41);
			wcout << wstring6;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			else if (options[4] == 1)
			{
				return optionChoice = 5;
			}
			else if (options[5] == 1)
			{
				return optionChoice = 6;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			else if (options[4] == 1 or options[5] == 1)
			{
				if (options[4] == 0) options[4] = 1;
				else if (options[4] == 1) options[4] = 0;
				if (options[5] == 0) options[5] = 1;
				else if (options[5] == 1) options[5] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			else if (options[4] == 1 or options[5] == 1)
			{
				if (options[4] == 0) options[4] = 1;
				else if (options[4] == 1) options[4] = 0;
				if (options[5] == 0) options[5] = 1;
				else if (options[5] == 1) options[5] = 0;
			}
			break;
		case 115:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[3] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[4] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[5] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[0] = 1;
			}
			else if (options[5] == 1)
			{
				options[5] = 0;
				options[1] = 1;
			}
			break;
		case 119:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[4] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[5] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[0] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[1] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[2] = 1;
			}
			else if (options[5] == 1)
			{
				options[5] = 0;
				options[3] = 1;
			}
			break;
		}
		goto loop5;
		break;
	}
	return optionChoice;
}