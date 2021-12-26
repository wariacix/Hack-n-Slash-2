#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <winuser.h>
#include "gotoxy.h"
#include "gen.h"
#include "variables.h"
#include "equipItem.h"
#include "Map.h"

struct items armor, weapon, shield, selectedItem;

using namespace std;

void gen()
{
	srand(time(NULL));
	Map::MapGeneration::generateMap();

	for (p = 0; p < 9999; p++) item[p] = 0;
	for (p = 0; p < 50; p++) text[p] = -1000;

	armory[0] = 0;
	armory[1] = 0;
	armory[2] = 0;

	equipItem(2, 1000);
	equipItem(2, 2000);
	equipItem(2, 3000);

	item[0] = 99999;
	item[1] = 527;
	item[1001] = 1;
	item[1002] = 1;
	item[2001] = 1;
	item[2002] = 1;
	item[3001] = 1;
}