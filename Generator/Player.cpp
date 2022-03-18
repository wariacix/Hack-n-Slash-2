#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "equipment.h"
#include "variables.h"
#include "Map.h"
#include "Player.h"

using namespace std;

void Player::movePlayer(Map &map1)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool a = true;
	while (a == true)
	{
		SetConsoleTextAttribute(hConsole, 15);
		a = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (x > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x - 1][y] = 1;
				x--;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (x < 47)
			{
				map1.hero[x][y] = 0;
				map1.hero[x + 1][y] = 1;
				x++;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) or sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			equipment();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (y > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y - 1] = 1;
				y--;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (y < 45)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y + 1] = 1;
				y++;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			los = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			for (int x0 = 0; x0 < 48; x0++)
			{
				for (int y0 = 0; y0 < 46; y0++)
				{
					map1.fog[x0][y0] = 0;
				}
			}
		}
		else a = true;
	}
}