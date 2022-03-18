#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include <fstream>
#include "gotoxy.h"
#include "fight.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"

using namespace std;

class intMap
{
public:
	static const int sizeX = 400;
	static const int sizeY = 200;
	wchar_t mapGraphics[sizeX][sizeY];
	wchar_t mapCollision[sizeX][sizeY];
	wchar_t mapEvents[sizeX][sizeY];
	int playerX;
	int playerY;
	intMap()
	{
		this->playerX = 0;
		this->playerY = 0;
		for (int a = 0; a < sizeX; a++)
		{
			for (int b = 0; b < sizeY; b++)
			{
				this->mapGraphics[a][b] = L' ';
				this->mapCollision[a][b] = L'0';
				this->mapEvents[a][b] = '0';
			}
		}
	}

	void viewMap();

	void loadMap(wstring mapName);
};