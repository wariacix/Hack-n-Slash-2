#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
#include "choice.h"
#include "intMap.h"

using namespace std;

void intMap::viewMap()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int textboxOffsetX = 26; const int textboxOffsetY = 9;
	int offsetX = 26; int offsetY = 9;

	textboxAnimation();

	for (int playerX = 0; playerX < sizeX; playerX++)
	{
		for (int playerY = 0; playerY < sizeY; playerY++)
		{
			if (mapCollision[playerX][playerY] == L'3')
			{
				SetConsoleTextAttribute(hConsole, 60);
				gotoxy(0, 0);
				wcout << L"KURWAMACJAPIERDOLEKURWAMACJAPIERDOLE";
				_getch();
				for (int xWindow = 0; xWindow < 68; xWindow++)
				{
					for (int yWindow = 0; yWindow < 33; yWindow++)
					{
						if (playerX - 34 >= 0 && playerY - 16 >= 0 && playerX - 34 < sizeX && playerY - 16 > sizeY)
						{
							wcout << L"CHUJ0000000______0000001111";
							gotoxy(offsetX + xWindow, offsetY + yWindow);
							wcout << mapGraphics[playerX - 34][playerY - 16];
							_getch();
						}
						gotoxy(offsetX + xWindow, offsetY + yWindow);
						if (xWindow == 34 && yWindow == 16) wcout << L'A';
						else if (xWindow == 34 && yWindow == 15) wcout << L'☺';
					}
				}
			}
		}
	}
	wcout << mapCollision[3][3];
}

void intMap::loadMap(wstring mapName)
{
	wifstream mapFile(L"C:\\Users\\waria\\source\\repos\\Hack-n-Slash-2\\" + mapName + L".txt");
	mapFile >> std::noskipws;
	if (mapFile.good())
	{
		// Map graphics (text) loop
		int a, b;
		a = 0; b = 0;
		while (mapFile.eof() == false)
		{
			mapFile >> mapGraphics[a][b];
			if (a >= 3 and mapGraphics[a-3][b] == L'*' and mapGraphics[a - 2][b] == L'&' and mapGraphics[a - 1][b] == L'&' and mapGraphics[a][b] == L'*')
			{
				wcout << L"HAHA ZAŁADOWAŁO SKURWYSYNU";
				mapGraphics[a - 3][b] = L' ';
				mapGraphics[a - 2][b] = L' ';
				mapGraphics[a - 1][b] = L' ';
				mapGraphics[a][b] = L' ';
				gotoxy(0, 0);
				break;
			}

			a++;
			if (a >= sizeX + 1)
			{
				a = 0;
				b++;
			}
		}

		// Map collisions loop
		a = 0; b = 0;
		while (mapFile.eof() == false)
		{
			mapFile >> mapCollision[a][b];

			//Check for the end of this section 9009
			if (a == 3 and mapCollision[a - 3][b] == L'9' and mapCollision[a - 2][b] == L'0' and mapCollision[a - 1][b] == L'0' and mapCollision[a][b] == L'9')
			{
				wcout << L"HAHA ZAŁADOWAŁO SKURWYSYNU999999999999999999999999";
				mapCollision[a - 3][b] = L'0';
				mapCollision[a - 2][b] = L'0';
				mapCollision[a - 1][b] = L'0';
				mapCollision[a][b] = L'0';
				break;
			}

			a++;
			if (a >= sizeX + 1)
			{
				a = 0;
				b++;
			}
		}

		// Map events loop
		a = 0; b = 0;
		while (mapFile.eof() == false)
		{
			mapFile >> mapEvents[a][b];

			//Check for the end of this section 9009
			if (a == 3 and mapEvents[a - 3][b] == L'9' and mapEvents[a - 2][b] == L'0' and mapEvents[a - 1][b] == L'0' and mapEvents[a][b] == L'9')
			{
				mapEvents[a - 3][b] = L'0';
				mapEvents[a - 2][b] = L'0';
				mapEvents[a - 1][b] = L'0';
				mapEvents[a][b] = L'0';
				mapFile.close();
				break;
			}

			a++;
			if (a >= sizeX + 1)
			{
				a = 0;
				b++;
			}
		}
	}
	else wcout << L"Unable to open map file";
}