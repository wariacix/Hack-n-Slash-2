#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <winuser.h>
#include <fcntl.h>
#include <io.h>
#include "equipment.h"
#include "variables.h"
#include "Map.h"

using namespace std;

void Player::movePlayer(Map &map1)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool a = true;
	while (a == true)
	{
		int wybor = _getch();
		SetConsoleTextAttribute(hConsole, 15);
		a = false;
		if (wybor == 97)
		{
			if (x > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x - 1][y] = 1;
				x--;
			}
		}
		else if (wybor == 100)
		{
			if (x < 47)
			{
				map1.hero[x][y] = 0;
				map1.hero[x + 1][y] = 1;
				x++;
			}
		}
		else if (wybor == 101)
		{
			equipment();
		}
		else if (wybor == 119)
		{
			if (y > 0)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y - 1] = 1;
				y--;
			}
		}
		else if (wybor == 115)
		{
			if (y < 45)
			{
				map1.hero[x][y] = 0;
				map1.hero[x][y + 1] = 1;
				y++;
			}
		}
		else if (wybor == 112)
		{
			los = true;
		}
		else if (wybor == 109)
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