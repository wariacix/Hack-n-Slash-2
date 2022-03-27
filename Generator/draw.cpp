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
#include <fcntl.h>
#include <io.h>
#include "gotoxy.h"
#include "draw.h"
#include "variables.h"

using namespace std;
void draw(int id, int collumn, int line)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0;
	switch (id)
	{
	case 1:
		gotoxy(collumn, line + k);
		wcout << "                                                                   /"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                  /|"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                 / |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                           /|   /  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                          | |__/|  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                          | | / |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                       WELCOME  TO                      /|/ |/  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |. |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       / | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "        *&&                                           /| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "       &\\\\&& &                                       *|| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "       *|*\\*& *                                      ||| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "_______\\\\*&/*/&&_____________________________________|||/-----\\ |  |"; k++; gotoxy(collumn, line + k);
		wcout << "        &\\*||/&                                      ||||     | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          &|/                                        ||||   ^ | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          | |                                        \\||| []| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          / |                                         \\||/&\\| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "*        // \\\\                                 *****  *\\| &&| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << " ****        \\       ***   ********       *****     **  \\ &&| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "     *****   ********   ***        *******               \\/\\| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          ***                                            /\\|| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                           \\| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                            \\ | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                               **     *******\\| |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                         *     ******      ****  *****        \\ |  |"; k++; gotoxy(collumn, line + k);
		wcout << "***            ********** *****      ******                    \\|  |"; k++; gotoxy(collumn, line + k);
		wcout << "   ************                                                 \\  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                 \\ |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                  \\|"; k++; gotoxy(collumn + 35, line + 6);
		wcout << cityName[cityID[x][y]];
		break;
	case 2:
		gotoxy(collumn, line + k);
		wcout << "                                                                   /"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                  /|"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                 / |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                           /|   /  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                          | |__/|  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                          | | / |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                       WELCOME  TO                      /|/ |/  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |. |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       | | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                       / | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "        *&&                                           /| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "       &\\\\&& &                                       *|| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "       *|*\\*& *                                      ||| | | |  |  |"; k++; gotoxy(collumn, line + k);
		wcout << "_______\\\\*&/*/&&_____________________________________|||/-----\\ |  |"; k++; gotoxy(collumn, line + k);
		wcout << "        &\\*||/&                                      ||||     | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          &|/                                        ||||     | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          | |                                        \\|||   | | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          / |                                         \\||   | | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "*        // \\\\                                 *****  *\\    | | |  |"; k++; gotoxy(collumn, line + k);
		wcout << " ****        \\       ***   ********       *****     **  \\   | | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "     *****   ********   ***        *******               \\  | | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "          ***                                             \\|| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                           \\| | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                            \\ | |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                               **     *******\\| |  |"; k++; gotoxy(collumn, line + k);
		wcout << "                         *     ******      ****  *****        \\ |  |"; k++; gotoxy(collumn, line + k);
		wcout << "***            ********** *****      ******                    \\|  |"; k++; gotoxy(collumn, line + k);
		wcout << "   ************                                                 \\  |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                 \\ |"; k++; gotoxy(collumn, line + k);
		wcout << "                                                                  \\|"; k++; gotoxy(collumn + 35, line + 6);
		wcout << cityName[cityID[x][y]];
		break;
	case 3:
		gotoxy(collumn, line + k);
		wcout << "    __  __               \\                ,        _____  .                 _            ___ "; k++; gotoxy(collumn, line + k);
		wcout << "    |   |    ___    ___  |   ,      , __  /       (       |     ___    ____ /           /   \\"; k++; gotoxy(collumn, line + k);
		wcout << "    |___|   /   ` .'   ` |  /       |'  `.         `--.   |    /   `  (     |,---.        _-'"; k++; gotoxy(collumn, line + k);
		wcout << "    |   |  |    | |      |-<        |    |            |   |   |    |  `--.  |'   |       /   "; k++; gotoxy(collumn, line + k);
		wcout << "    /   /  `.__/|  `._.' /  \\_      /    |       \\___.'  /\\__ `.__/| \\___.' /    |      /___,"; k = k + 3; gotoxy(collumn, line + k);
		wcout << "________________________________________________________________________________________________";
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, 15);
		gotoxy(collumn, line + k);
		wcout << L"═════╤════════════════╤════════════════╤════════════════╤═══╧════════════╤════════════════╤"; k++; gotoxy(collumn, line + k); SetConsoleTextAttribute(hConsole, 112);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     *────────────────*────────────────*────────────────*────────────────*────────────────*     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     *────────────────*────────────────*────────────────*────────────────*────────────────*     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     *────────────────*────────────────*────────────────*────────────────*────────────────*     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     *────────────────*────────────────*────────────────*────────────────*────────────────*     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"     │                │                │                │                │                │     "; k++; gotoxy(collumn, line + k);
		wcout << L"─────*────────────────*────────────────*────────────────*────────────────*────────────────*─────"; SetConsoleTextAttribute(hConsole, 15); wcout << L"╢"; SetConsoleTextAttribute(hConsole, 112); k++; gotoxy(collumn, line + k);
		wcout << L"                                                                                                ";
		break;
	case 5:
		gotoxy(collumn, line + k);
		wcout << L"--→"; k++; gotoxy(collumn, line + k);
		wcout << L"--→"; k++; gotoxy(collumn, line + k);
		wcout << L"--→"; k++; gotoxy(collumn, line + k);
		break;
	case 300:
		gotoxy(47, 10);
		wcout << "                    ,     ,";
		gotoxy(47, 11);
		wcout << "                    |\\---/|";
		gotoxy(47, 12);
		wcout << "                   /  , , |";
		gotoxy(47, 13);
		wcout << "              __.-'|  / \\ /";
		gotoxy(47, 14);
		wcout << "     __ ___.-'        ._O| ";
		gotoxy(47, 15);
		wcout << "  .-'  '        :      _/  ";
		gotoxy(47, 16);
		wcout << " / ,    .        .     |   ";
		gotoxy(47, 17);
		wcout << ":  ;    :        :   _/    ";
		gotoxy(47, 18);
		wcout << "|  |   .'     __:   /      ";
		gotoxy(47, 19);
		wcout << "|  :   /'----'| \\  |       ";
		gotoxy(47, 20);
		wcout << "\\  |\\  |      | /| |       ";
		gotoxy(47, 21);
		wcout << " | /|.'       '.l \\\\_      ";
		gotoxy(47, 22);
		wcout << " || ||             '-'     ";
		gotoxy(47, 23);
		wcout << " '-''-'                    ";
		break;
	case 301:
		gotoxy(49, 10);
		wcout << "   ..------~~~--._--q ";
		gotoxy(49, 11);
		wcout << " /               c~`;";
		gotoxy(49, 12);
		wcout << "  /             \\__ `\\";
		gotoxy(49, 13);
		wcout << "  |  /~~--__/  /'\\'~~'";
		gotoxy(49, 14);
		wcout << " /'/'\\ |    | |`\\ \\_  ";
		gotoxy(49, 15);
		wcout << "`-))  `-))  `-)) `-)) ";
		break;
	case 1000:
		gotoxy(collumn, line + k);
		wcout << L"       __     "; k++; gotoxy(collumn, line + k);
		wcout << L" +25  (__)    "; k++; gotoxy(collumn, line + k);
		wcout << L"  HP  )__(    "; k++; gotoxy(collumn, line + k);
		wcout << L"     /#^^#\\   "; k++; gotoxy(collumn, line + k);
		wcout << L"    {##\\/##}  "; k++; gotoxy(collumn, line + k);
		wcout << L"    '-####-'  ";
		break;
	case 1001:
		gotoxy(collumn, line + k);
		wcout << L"       __     "; k++; gotoxy(collumn, line + k);
		wcout << L" +50  (__)    "; k++; gotoxy(collumn, line + k);
		wcout << L"  HP  )__( <3 "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3 /#^^#\\   "; k++; gotoxy(collumn, line + k);
		wcout << L"<3  {##\\/##}  "; k++; gotoxy(collumn, line + k);
		wcout << L"    '-####-'  ";
		break;
	case 1002:
		gotoxy(collumn, line + k);
		wcout << L"  <3   __     "; k++; gotoxy(collumn, line + k);
		wcout << L" +100 (__)    "; k++; gotoxy(collumn, line + k);
		wcout << L"  HP  )__( <3 "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3 /#^^#\\   "; k++; gotoxy(collumn, line + k);
		wcout << L"<3  {##\\/##}  "; k++; gotoxy(collumn, line + k);
		wcout << L"    '-####-'<3";
		break;
	case 1003:
		gotoxy(collumn, line + k);
		wcout << L"  <3   __   <3"; k++; gotoxy(collumn, line + k);
		wcout << L" +200 (__)    "; k++; gotoxy(collumn, line + k);
		wcout << L"  HP  )__( <3 "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3 /#^^#\\   "; k++; gotoxy(collumn, line + k);
		wcout << L"<3  {##\\/##}  "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3'-####-'<3";
		break;
	case 1004:
		gotoxy(collumn, line + k);
		wcout << L"  <3 <3__   <3"; k++; gotoxy(collumn, line + k);
		wcout << L" +50% (__)<3  "; k++; gotoxy(collumn, line + k);
		wcout << L"  HP  )__( <3 "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3 /#^^#\\ <3"; k++; gotoxy(collumn, line + k);
		wcout << L"<3  {##\\/##}  "; k++; gotoxy(collumn, line + k);
		wcout << L"  <3'-####-'<3";
		break;
	case 1005:
		gotoxy(collumn, line + k);
		wcout << L"       __       "; k++; gotoxy(collumn, line + k);
		wcout << L" +10  (__)      "; k++; gotoxy(collumn, line + k);
		wcout << L"  MN  )__(      "; k++; gotoxy(collumn, line + k);
		wcout << L"     /#**#\\     "; k++; gotoxy(collumn, line + k);
		wcout << L"    {#****#}    "; k++; gotoxy(collumn, line + k);
		wcout << L"    '-####-'    ";
		break;
	case 1006:
		gotoxy(collumn, line + k);
		wcout << L"       __       "; k++; gotoxy(collumn, line + k);
		wcout << L" +20  (__)   *  "; k++; gotoxy(collumn, line + k);
		wcout << L"  MN  )__(      "; k++; gotoxy(collumn, line + k);
		wcout << L"     /#**#\\     "; k++; gotoxy(collumn, line + k);
		wcout << L"  * {#****#}    "; k++; gotoxy(collumn, line + k);
		wcout << L"    '-####-'    ";
		break;
	case 2000:
		gotoxy(collumn, line + k);
		wcout << L"      /    _/  "; k++; gotoxy(collumn, line + k);
		wcout << L"    \\/ //_/-/  "; k++; gotoxy(collumn, line + k);
		wcout << L"     \\/_/_# _/ "; k++; gotoxy(collumn, line + k);
		wcout << L" \\/ -////_-/ _-"; k++; gotoxy(collumn, line + k);
		wcout << L"  \\_/#/_/_--/  "; k++; gotoxy(collumn, line + k);
		wcout << L"  /-#//_-      "; k++; gotoxy(collumn, line + k);
		wcout << L" /_-/_/        "; k++; gotoxy(collumn, line + k);
		wcout << L" \\_/           "; k++; gotoxy(collumn, line + k);
		break;
	case 2001:
		gotoxy(collumn, line + k);
		wcout << L"        ^_-^-\\  "; k++; gotoxy(collumn, line + k);
		wcout << L"        / v v/  "; k++; gotoxy(collumn, line + k);
		wcout << L"       / --/*   "; k++; gotoxy(collumn, line + k);
		wcout << L"      / -/      "; k++; gotoxy(collumn, line + k);
		wcout << L"     / /        "; k++; gotoxy(collumn, line + k);
		wcout << L"   _/ /         "; k++; gotoxy(collumn, line + k);
		wcout << L"  / -/          "; k++; gotoxy(collumn, line + k);
		wcout << L" \\_/            "; k++; gotoxy(collumn, line + k);
		break;
	case 2002:
		gotoxy(collumn, line + k);
		wcout << L"          /^    "; k++; gotoxy(collumn, line + k);
		wcout << L"         /-\\    "; k++; gotoxy(collumn, line + k);
		wcout << L"        /$ |    "; k++; gotoxy(collumn, line + k);
		wcout << L"       /%*/     "; k++; gotoxy(collumn, line + k);
		wcout << L"      / _/      "; k++; gotoxy(collumn, line + k);
		wcout << L"     /-/        "; k++; gotoxy(collumn, line + k);
		wcout << L"    |_/         "; k++; gotoxy(collumn, line + k);
		wcout << L"                "; k++; gotoxy(collumn, line + k);
		break;
	case 3000:
		gotoxy(collumn, line + k);
		wcout << L"   ___      _   "; k++; gotoxy(collumn, line + k);
		wcout << L"   /; \\-_  //   "; k++; gotoxy(collumn, line + k);
		wcout << L"   \\ / * -//    "; k++; gotoxy(collumn, line + k);
		wcout << L"   /\\| -[ \\|    "; k++; gotoxy(collumn, line + k);
		wcout << L"   |-// -\\_|    "; k++; gotoxy(collumn, line + k);
		wcout << L"   \\_|_/-__/    "; k++; gotoxy(collumn, line + k);
		wcout << L"   / \\{   *     "; k++; gotoxy(collumn, line + k);
		break;
	case 3001:
		gotoxy(collumn, line + k);
		wcout << L"   ___     __ "; k++; gotoxy(collumn, line + k);
		wcout << L"   /; \\-_-/// "; k++; gotoxy(collumn, line + k);
		wcout << L"   \\ / *  //\\ "; k++; gotoxy(collumn, line + k);
		wcout << L"   /\\| -[ \\|| "; k++; gotoxy(collumn, line + k);
		wcout << L"   |-// -\\_|| "; k++; gotoxy(collumn, line + k);
		wcout << L"   \\_|_/-__// "; k++; gotoxy(collumn, line + k);
		break;
	case 3002:
		gotoxy(collumn, line + k);
		wcout << L"   _--_   _--_  "; k++; gotoxy(collumn, line + k);
		wcout << L"   /^^\\-_-/^^/  "; k++; gotoxy(collumn, line + k);
		wcout << L"   | / */  * |  "; k++; gotoxy(collumn, line + k);
		wcout << L"    \\( )( ) /   "; k++; gotoxy(collumn, line + k);
		wcout << L"    |( )( )||   "; k++; gotoxy(collumn, line + k);
		wcout << L"    \\(_)(-)_/   "; k++; gotoxy(collumn, line + k);
		wcout << L"     \\_---_/    "; k++; gotoxy(collumn, line + k);
		break;
	case 4000:
		gotoxy(collumn, line + k);
		wcout << L"  /-*---\\_/--\\  "; k++; gotoxy(collumn, line + k);
		wcout << L" [---_---_----]"; k++; gotoxy(collumn, line + k);
		wcout << L" [------_---]  "; k++; gotoxy(collumn, line + k);
		wcout << L" [--][----*---]"; k++; gotoxy(collumn, line + k);
		wcout << L"  [---_----&--]"; k++; gotoxy(collumn, line + k);
		wcout << L" [---_---*----]"; k++; gotoxy(collumn, line + k);
		wcout << L" \\--------__--/ "; k++; gotoxy(collumn, line + k);
		break;
	case 4001:
		gotoxy(collumn, line + k);
		wcout << L"  /----------\\  "; k++; gotoxy(collumn, line + k);
		wcout << L" [-o-_------o-] "; k++; gotoxy(collumn, line + k);
		wcout << L" [------_-----] "; k++; gotoxy(collumn, line + k);
		wcout << L" [-o------*-o-] "; k++; gotoxy(collumn, line + k);
		wcout << L" [------------] "; k++; gotoxy(collumn, line + k);
		wcout << L" [-o-_---*--o-] "; k++; gotoxy(collumn, line + k);
		wcout << L" \\------------/ "; k++; gotoxy(collumn, line + k);
		break;
	}
}