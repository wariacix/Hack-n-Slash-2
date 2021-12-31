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
#include "intMap.h"

using namespace std;

void intMap::viewMap()
{
	wcout << mapGraphics[0][0] << mapGraphics[1][0] << mapGraphics[0][1] << mapGraphics[1][1];
	_getch();
}

void intMap::loadMap(wstring mapName)
{
	wifstream mapGraphicsFile(L"C:\\Users\\xx\\Documents\\hns2\\Map Files\\" + mapName + L".txt");
	mapGraphicsFile >> std::noskipws;
	if (mapGraphicsFile.good())
	{
		int a, b;
		a = 0; b = 0;
		while (mapGraphicsFile.eof() == false)
		{
			mapGraphicsFile >> mapGraphics[a][b];
			gotoxy(0, 0);
			wcout << a << L"    ";
			gotoxy(0, 2);
			wcout << b << L"    ";
			if (a > 397) _getch();
			if (a == 3 and mapGraphics[a-3][b] == L'*' and mapGraphics[a - 2][b] == L'&' and mapGraphics[a - 1][b] == L'&' and mapGraphics[a][b] == L'*')
			{
				mapGraphics[a - 3][b] = L' ';
				mapGraphics[a - 2][b] = L' ';
				mapGraphics[a - 1][b] = L' ';
				mapGraphics[a][b] = L' ';
				mapGraphicsFile.close();
			}
			a++;
			if (a >= sizeX + 1)
			{
				a = 0;
				b++;
			}
		}
		_getch();
	}
	else wcout << L"Unable to open map file";
}