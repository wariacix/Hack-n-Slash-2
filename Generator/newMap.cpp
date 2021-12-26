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
#include "menu.h"
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"
#include "choice.h"

using namespace std;

class newMap
{
private:
	static const int sizeX = 800;
	static const int sizeY = 400;
	int mapCollision[sizeX][sizeY];
	wstring mapGraphics[sizeX][sizeY];
	int mapEvents[sizeX][sizeY];
	int playerX;
	int playerY;
	int cameraX;
	int cameraY;
public:
	newMap()
	{
		this->playerX = 0;
		this->playerY = 0;
		this->cameraX = 0;
		this->cameraY = 0;
		for (int a = 0; a < sizeX; a++)
		{
			for (int b = 0; b < sizeY; b++)
			{
				this->mapCollision[a][b] = 0;
				this->mapGraphics[a][b] = L" ";
				this->mapEvents[a][b] = 0;
			}
		}
	}

	void mapViewing()
	{

	}

	void mapLoading(wstring mapName)
	{
		ifstream mapGraphicsFile(mapName);
		if (mapGraphicsFile.is_open())
		{
			while (mapGraphicsFile.eof() == false)
			{

			}
		}
		else wcout << L"Unable to open map file";
	}
};