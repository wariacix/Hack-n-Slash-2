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
#include "variables.h"
#include "choice.h"
#include "Player.h"

using namespace std;

void menu()
{
	mainPlayer.heroName = L"NO NAME";
	wstring heroNameX;
	wcout << L"CHOOSE YOUR NAME: ";
	getline(wcin, heroNameX);
	mainPlayer.heroName = heroNameX;
}