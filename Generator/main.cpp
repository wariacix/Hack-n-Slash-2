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
#include "equipment.h"
#include "equipItem.h"
#include "Map.h"
#include "Player.h"
#include "intMap.h"


Map mainMap;
Player mainPlayer;

int debugMode = 0;
int cityID[48][46], cityGuardian[48][46], item[9999], armory[3], x, y, p, mtnChance;
std::wstring cityName[30];
int text[50];
int fightMode = 0; //0bez walki,1walka,2ekwipunek w trakcie walki
bool los = false;
std::wstring enemyName;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
struct items armor, weapon, shield, selectedItem;

using namespace std;


void setBaseValues()
{
	mtnChance = 13;
	los = false;

	for (p = 0; p < 9999; p++) item[p] = 0;
	for (p = 0; p < 50; p++) text[p] = -1000;

	armory[0] = 0;
	armory[1] = 0;
	armory[2] = 0;

	equipItem(2, 1000);
	equipItem(2, 2000);
	equipItem(2, 3000);

	item[0] = 200;
	item[1] = 20;
	item[2] = 10;
	item[3] = 5;
	item[4] = 5;
	item[5] = 5;
	item[6] = 5;
	item[1001] = 1;
	item[1002] = 1;
	item[2001] = 1;
	item[2002] = 1;
	item[3001] = 1;
};

void updateHpMp()
{
	if (mainPlayer.hp < mainPlayer.maxhp) mainPlayer.hp = mainPlayer.hp + mainPlayer.hpRegen; else mainPlayer.hp = mainPlayer.maxhp;
	if (mainPlayer.mp < mainPlayer.maxmp) mainPlayer.mp = mainPlayer.mp + mainPlayer.mpRegen; else mainPlayer.mp = mainPlayer.maxmp;
}

int main()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	srand(time(NULL));
	intMap map1;
	map1.loadMap(L"map1");
	while (true)
	{
		system("color 0f");
		system("mode con: cols=126 lines=50");
		setBaseValues();
		gameGui();
		map1.viewMap();
		menu();
		mainMap.generateMap();

		while (los == false)
		{
			updateHpMp();
			mainMap.clearFog(mainPlayer);
			mainMap.viewMap();
			gameGui();
			if (mainMap.city[mainPlayer.x][mainPlayer.y] == 1) textbox(3, 0);
			if (rand() % 7 == 0 and mainMap.biome[mainPlayer.x][mainPlayer.y] == 4) textbox(1, 300 + rand() % 2); //0 - Polany   1 - Góry   2 - Pustynia   3 - Arktyka   4 - Lasy
			mainPlayer.movePlayer(mainMap);
		}
	}
};