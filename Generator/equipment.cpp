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
#include "fight.h"
#include "draw.h"
#include "gameGui.h"
#include "textbox.h"
#include "variables.h"

#include "choice.h"
#include "stringLength.h"
#include "equipItem.h"

using namespace std;

void equipment()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int equipmentItem[5][500][3];
	string equipmentItemName[5][500];
	bool wasUsed[9999];
powrotPoUzyciu:
	for (int g = 0; g < 9999; g++)
	{
		wasUsed[g] = false;
	}
	for (int eqx = 0; eqx < 5; eqx++)
	{
		for (int eqy = 0; eqy < 500; eqy++)
		{
			equipmentItem[eqx][eqy][0] = 0; //pierwsza wartoœæ - liczba itemów
			equipmentItem[eqx][eqy][1] = 0; //druga wartoœæ - czy zaznaczone
			equipmentItem[eqx][eqy][2] = 0; // trzecia wartoœæ - id itemu
			equipmentItemName[eqx][eqy] = " ";
		}
	}
	draw(4, 0, 3);
	for (int eqy = 0; eqy < 500; eqy++)
	{
		for (int eqx = 0; eqx < 5; eqx++)
		{
			for (int g = 0; g < 9999; g++)
			{
				if (item[g] >= 1 and wasUsed[g] == false)
				{
					wasUsed[g] = true;
					equipmentItem[eqx][eqy][0] = item[g];
					equipmentItem[eqx][eqy][2] = g;
					break;
				}
			}
		}
	}
	equipmentItem[0][0][1] = 1;
	int difference = 0;
powrot:
	bool exit = false;
	int eqy = 0;
	int eqx = 0;
	int slotCount = 0;
	int holder = difference * 5;
	while (exit == false)
	{
		slotCount = 0;
		for (int g = 0; g < 9999; g++)
		{
			if (item[g] >= 1)
			{
				if (holder == 0)
				{
					draw(g + 1000, 6 + eqx * 17, 4 + (eqy) * 9);
					gotoxy(8 + (eqx * 17), 11 + (eqy) * 9);
					wcout << "              ";
					gotoxy(22 - stringLength(item[g]) + (eqx * 17), 11 + (eqy) * 9);
					wcout << equipmentItem[eqx][eqy + difference][0];
					gotoxy(12 + (eqx * 17), 11 + (eqy) * 9);
					if (equipmentItem[0][eqy + difference][1] == 1 or equipmentItem[1][eqy + difference][1] == 1 or equipmentItem[2][eqy + difference][1] == 1 or equipmentItem[3][eqy + difference][1] == 1 or equipmentItem[4][eqy + difference][1] == 1)
					{
						if (equipmentItem[eqx][eqy + difference][1] == 1) wcout << L"<V>";
						draw(5, 0, 7 + (eqy) * 9);
					}
					else
					{
						if (equipmentItem[eqx][eqy + difference][1] == 1) wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9);
						wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9 + 1);
						wcout << L"   ";
						gotoxy(0, 7 + (eqy) * 9 + 2);
						wcout << L"   ";
					}
					if (eqx < 4) eqx++;
					else if (eqx == 4)
					{
						eqx = 0;
						eqy++;
					}
					slotCount++;
					if (slotCount > 24)
					{
						exit = true;
						break;
					}
				}
				else if (holder > 0)
				{
					holder--;
				}
			}
			if (g == 9998) exit = true;
		}
	}
	for (int eqy = 0; eqy < 500; eqy++)
	{
		for (int eqx = 0; eqx < 5; eqx++)
		{
			if (equipmentItem[eqx][eqy][1] == 1)
			{
				if (equipmentItem[eqx][eqy][2] >= 0)
				{
					SetConsoleTextAttribute(hConsole, 15);
					equipItem(0, equipmentItem[eqx][eqy][2]);
				}
				gameGui(3);
			missclick:
				int wybor = _getch();
				SetConsoleTextAttribute(hConsole, 112);
				if (wybor == 97)
				{
					if (eqx > 0 and equipmentItem[eqx - 1][eqy][0] > 0)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[eqx - 1][eqy][1] = 1;
					}
					if (eqx == 0 and equipmentItem[4][eqy - 1][0] > 0 and eqy > 0)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[4][eqy - 1][1] = 1;
					}
					goto powrot;
				}
				else if (wybor == 100)
				{
					if (eqx < 4 and equipmentItem[eqx + 1][eqy][0] > 0)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[eqx + 1][eqy][1] = 1;
					}
					if (eqx >= 4 and equipmentItem[0][eqy + 1][0] > 0 and eqy < 500)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[0][eqy + 1][1] = 1;
					}
					goto powrot;
				}
				else if (wybor == 101 or wybor == 13)
				{
					equipItem(1, equipmentItem[eqx][eqy][2]);
					gameGui(3);
					goto powrotPoUzyciu;
				}
				else if (wybor == 119)
				{
					if (eqy > 0 and equipmentItem[eqx][eqy - 1][0] > 0)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[eqx][eqy - 1][1] = 1;
						if (difference > 0 and (eqy - difference == 0)) difference--;
					}
					goto powrot;
				}
				else if (wybor == 115)
				{
					if (eqy < 500 and equipmentItem[eqx][eqy + 1][0] > 0)
					{
						equipmentItem[eqx][eqy][1] = 0;
						equipmentItem[eqx][eqy + 1][1] = 1;
					}
					if (equipmentItem[eqx][eqy + 1][1] == 1 and (eqy - difference) == 4)
					{
						difference++;
					}
					goto powrot;
				}
				else if (wybor == 27)
				{
					goto exit;
				}
				else goto missclick;
			}
		}
	}
	exit:
	SetConsoleTextAttribute(hConsole, 15);
}