#include <iostream>

using namespace std;

int stringLength(int a)
{
	if (a >= 0 and a < 10) return 1;
	else if (a >= 10 and a < 100) return 2;
	else if (a >= 100 and a < 1000) return 3;
	else if (a >= 1000 and a < 10000) return 4;
	else if (a >= 10000 and a < 100000) return 5;
	else if (a >= 100000 and a < 1000000) return 6;
	else if (a >= 1000000 and a < 10000000) return 7;
	else return 8;
}