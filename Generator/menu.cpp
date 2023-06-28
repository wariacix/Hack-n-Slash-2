#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "General.h"
#include "menu.h"

void hns::Menu::Draw(sf::RenderWindow& window)
{
	background.Draw(window);
	redButton.Draw(window);
	blueButton.Draw(window);
	yellowButton.Draw(window);
}

void hns::Menu::Start(sf::RenderWindow& window)
{
	bool gameStarted = false;
	bool textures[2] = { false, false };
	sf::Texture a, b, c, d;
	a.loadFromFile("Textures\\UI\\redScrollClicked.png", sf::IntRect(0, 0, 103, 20));
	b.loadFromFile("Textures\\UI\\yellowScrollClicked.png", sf::IntRect(0, 0, 83, 20));
	c.loadFromFile("Textures\\UI\\redScroll.png", sf::IntRect(0, 0, 103, 20));
	d.loadFromFile("Textures\\UI\\yellowScroll.png", sf::IntRect(0, 0, 83, 20));
	while (gameStarted == false)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit(1);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (redButton.isHovered(window) == true) gameStarted = true;
				if (yellowButton.isHovered(window) == true)
				{
					window.close();
					exit(1);
				}
			}
		}


		if (redButton.isHovered(window) == true)
		{
			if (textures[0] == false)
			{
				redButton.changeSprite(a);
				textures[0] = true;
			}
		}
		else if (redButton.isHovered(window) == false)
		{
			if (textures[0] == true)
			{
				redButton.changeSprite(c);
				textures[0] = false;
			}
		}
		if (yellowButton.isHovered(window) == true)
		{
			if (textures[1] == false)
			{
				yellowButton.changeSprite(b);
				textures[1] = true;
			}
		}
		else if (yellowButton.isHovered(window) == false)
		{
			if (textures[1] == true)
			{
				yellowButton.changeSprite(d);
				textures[1] = false;
			}
		}


		window.clear();
		Draw(window);
		window.display();
	}
}