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
#include "Player.h"
#include "equipment.h"
#include "variables.h"
#include "Map.h"

using namespace std;

void Player::CheckForKeyActivity(sf::RenderWindow& window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && hasBeenPressed[0] == true && window.hasFocus()) hasBeenPressed[0] = false;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && hasBeenPressed[1] == true && window.hasFocus()) hasBeenPressed[1] = false;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && hasBeenPressed[2] == true && window.hasFocus()) hasBeenPressed[2] = false;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && hasBeenPressed[3] == true && window.hasFocus()) hasBeenPressed[3] = false;
}

void Player::movePlayer(Map &map1, sf::RenderWindow &window, hns::Equipment &eq, Player& player)
{
		CheckForKeyActivity(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && hasBeenPressed[0] == false && window.hasFocus())
		{
			hasBeenPressed[0] = true;
			if (x > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x - 1][y] = 1;
				x--;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && hasBeenPressed[1] == false && window.hasFocus())
		{
			hasBeenPressed[1] = true;
			if (x < map1.getMapWidth() - 1)
			{
				map1.hero[x][y] = 0;
				map1.hero[x + 1][y] = 1;
				x++;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && window.hasFocus() or sf::Keyboard::isKeyPressed(sf::Keyboard::I) && window.hasFocus())
		{
			eq.viewEquipment(window, player);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && hasBeenPressed[2] == false && window.hasFocus())
		{
			hasBeenPressed[2] = true;
			if (y > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y - 1] = 1;
				y--;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && hasBeenPressed[3] == false && window.hasFocus())
		{
			hasBeenPressed[3] = true;
			if (y < map1.getMapHeight() - 1)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y + 1] = 1;
				y++;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && window.hasFocus())
		{
			los = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && window.hasFocus())
		{
			for (int x0 = 0; x0 < 48; x0++)
			{
				for (int y0 = 0; y0 < 46; y0++)
				{
					map1.fog[x0][y0] = 0;
				}
			}
		}
}
void Player::Regenerate()
{
	if (hp < maxhp) hp = hp + hpRegen; else hp = maxhp;
	if (mp < maxmp) mp = mp + mpRegen; else mp = maxmp;
}