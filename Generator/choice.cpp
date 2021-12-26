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

using namespace std;

int choice(wstring wstring1, wstring wstring2, wstring wstring3, wstring wstring4, wstring wstring5, wstring wstring6, int numberOfOptions) {
	int optionChoice = 1;
	int choice1, choice2, choice3, choice4, choice5;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(numberOfOptions)
	{
	int options[6];
	case 2:
		options[0] = 1;
		options[1] = 0;
	loop1:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length()/2)*2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		choice1 = _getch();
		switch(choice1)
		{
		case 13:
			if (options[0] == 1 and options[1] == 0)
			{
				return optionChoice = 1;
			}
			else if (options[0] == 0 and options[1] == 1)
			{
				return optionChoice = 2;
			}
			break;
		case 115:
			if (options[0] == 0) options[0] = 1;
			else if (options[0] == 1) options[0] = 0;
			if (options[1] == 0) options[1] = 1;
			else if (options[1] == 1) options[1] = 0;
			break;
		case 119:
			if (options[0] == 0) options[0] = 1;
			else if (options[0] == 1) options[0] = 0;
			if (options[1] == 0) options[1] = 1;
			else if (options[1] == 1) options[1] = 0;
			break;
		}
		goto loop1;
		break;
	case 3:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
	loop2:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                                                    ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 34 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 34 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                                                    ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 34 - (wstring2.length() / 2), 40);
			else gotoxy(26 + 34 - (wstring2.length() / 2) - 1, 40);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 34 - (wstring3.length() / 2), 41);
			else gotoxy(26 + 34 - (wstring3.length() / 2) - 1, 41);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 34 - (wstring3.length() / 2), 41);
			else gotoxy(26 + 34 - (wstring3.length() / 2) - 1, 41);
			wcout << wstring3;
		}
		choice2 = _getch();
		switch (choice2)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			break;
		case 115:
			if (options[0] == 0 and options[1] == 0 and options[2] == 1)
			{
				options[0] = 1;
				options[2] = 0;
			}
			else if (options[0] == 1 and options[1] == 0 and options[2] == 0)
			{
				options[0] = 0;
				options[1] = 1;
			}
			else if (options[0] == 0 and options[1] == 1 and options[2] == 0)
			{
				options[1] = 0;
				options[2] = 1;
			}
			break;
		case 119:
			if (options[0] == 0 and options[1] == 0 and options[2] == 1)
			{
				options[1] = 1;
				options[2] = 0;
			}
			else if (options[0] == 1 and options[1] == 0 and options[2] == 0)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[0] == 0 and options[1] == 1 and options[2] == 0)
			{
				options[1] = 0;
				options[0] = 1;
			}
			break;
		}
		goto loop2;
		break;
	case 4:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
	loop3:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 115:
			if (options[0] == 1 or options[2] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
			}
			else if (options[1] == 1 or options[3] == 1)
			{
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 119:
			if (options[0] == 1 or options[2] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
			}
			else if (options[1] == 1 or options[3] == 1)
			{
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		}
		goto loop3;
		break;
	case 5:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
		options[4] = 0;
	loop4:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		if (options[4] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 35 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 35 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		else if (options[4] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                                                    ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 35 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 35 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			else if (options[4] == 1)
			{
				return optionChoice = 5;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			break;
		case 115:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[3] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[4] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[4] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[0] = 1;
			}
			break;
		case 119:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[4] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[4] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[0] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[1] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[3] = 1;
			}
			break;
		}
		goto loop4;
		break;
	case 6:
		options[0] = 1;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
		options[4] = 0;
		options[5] = 0;
	loop5:
		if (options[0] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		else if (options[0] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 39);
			wcout << "                                  ";
			if ((wstring1.length() / 2) * 2 == wstring1.length()) gotoxy(26 + 17 - (wstring1.length() / 2), 39);
			else gotoxy(26 + 17 - (wstring1.length() / 2) - 1, 39);
			wcout << wstring1;
		}
		if (options[1] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		else if (options[1] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 39);
			wcout << "                                  ";
			if ((wstring2.length() / 2) * 2 == wstring2.length()) gotoxy(26 + 52 - (wstring2.length() / 2), 39);
			else gotoxy(26 + 52 - (wstring2.length() / 2) - 1, 39);
			wcout << wstring2;
		}
		if (options[2] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		else if (options[2] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 40);
			wcout << "                                  ";
			if ((wstring3.length() / 2) * 2 == wstring3.length()) gotoxy(26 + 17 - (wstring3.length() / 2), 40);
			else gotoxy(26 + 17 - (wstring3.length() / 2) - 1, 40);
			wcout << wstring3;
		}
		if (options[3] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		else if (options[3] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 40);
			wcout << "                                  ";
			if ((wstring4.length() / 2) * 2 == wstring4.length()) gotoxy(26 + 52 - (wstring4.length() / 2), 40);
			else gotoxy(26 + 52 - (wstring4.length() / 2) - 1, 40);
			wcout << wstring4;
		}
		if (options[4] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(26, 41);
			wcout << "                                  ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 17 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 17 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		else if (options[4] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(26, 41);
			wcout << "                                  ";
			if ((wstring5.length() / 2) * 2 == wstring5.length()) gotoxy(26 + 17 - (wstring5.length() / 2), 41);
			else gotoxy(26 + 17 - (wstring5.length() / 2) - 1, 41);
			wcout << wstring5;
		}
		if (options[5] == 0)
		{
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(60, 41);
			wcout << "                                  ";
			if ((wstring6.length() / 2) * 2 == wstring6.length()) gotoxy(26 + 52 - (wstring6.length() / 2), 41);
			else gotoxy(26 + 52 - (wstring6.length() / 2) - 1, 41);
			wcout << wstring6;
		}
		else if (options[5] == 1)
		{
			SetConsoleTextAttribute(hConsole, 143);
			gotoxy(60, 41);
			wcout << "                                  ";
			if ((wstring6.length() / 2) * 2 == wstring6.length()) gotoxy(26 + 52 - (wstring6.length() / 2), 41);
			else gotoxy(26 + 52 - (wstring6.length() / 2) - 1, 41);
			wcout << wstring6;
		}
		choice3 = _getch();
		switch (choice3)
		{
		case 13:
			if (options[0] == 1)
			{
				return optionChoice = 1;
			}
			else if (options[1] == 1)
			{
				return optionChoice = 2;
			}
			else if (options[2] == 1)
			{
				return optionChoice = 3;
			}
			else if (options[3] == 1)
			{
				return optionChoice = 4;
			}
			else if (options[4] == 1)
			{
				return optionChoice = 5;
			}
			else if (options[5] == 1)
			{
				return optionChoice = 6;
			}
			break;
		case 97:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			else if (options[4] == 1 or options[5] == 1)
			{
				if (options[4] == 0) options[4] = 1;
				else if (options[4] == 1) options[4] = 0;
				if (options[5] == 0) options[5] = 1;
				else if (options[5] == 1) options[5] = 0;
			}
			break;
		case 100:
			if (options[0] == 1 or options[1] == 1)
			{
				if (options[0] == 0) options[0] = 1;
				else if (options[0] == 1) options[0] = 0;
				if (options[1] == 0) options[1] = 1;
				else if (options[1] == 1) options[1] = 0;
			}
			else if (options[2] == 1 or options[3] == 1)
			{
				if (options[2] == 0) options[2] = 1;
				else if (options[2] == 1) options[2] = 0;
				if (options[3] == 0) options[3] = 1;
				else if (options[3] == 1) options[3] = 0;
			}
			else if (options[4] == 1 or options[5] == 1)
			{
				if (options[4] == 0) options[4] = 1;
				else if (options[4] == 1) options[4] = 0;
				if (options[5] == 0) options[5] = 1;
				else if (options[5] == 1) options[5] = 0;
			}
			break;
		case 115:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[2] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[3] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[4] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[5] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[0] = 1;
			}
			else if (options[5] == 1)
			{
				options[5] = 0;
				options[1] = 1;
			}
			break;
		case 119:
			if (options[0] == 1)
			{
				options[0] = 0;
				options[4] = 1;
			}
			else if (options[1] == 1)
			{
				options[1] = 0;
				options[5] = 1;
			}
			else if (options[2] == 1)
			{
				options[2] = 0;
				options[0] = 1;
			}
			else if (options[3] == 1)
			{
				options[3] = 0;
				options[1] = 1;
			}
			else if (options[4] == 1)
			{
				options[4] = 0;
				options[2] = 1;
			}
			else if (options[5] == 1)
			{
				options[5] = 0;
				options[3] = 1;
			}
			break;
		}
		goto loop5;
		break;
	}
	return optionChoice;
}