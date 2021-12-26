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

using namespace std;

int main()
{
	system("color 0f");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout << i << " Kolor kolor kolor kolor kolor kolor kolor" << endl;
		Sleep(250);
		SetConsoleTextAttribute(hConsole, 15);
	}
}