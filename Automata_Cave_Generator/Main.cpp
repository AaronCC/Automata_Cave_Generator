#include <stdio.h>
#include <sstream>
#include "CaveGen.h"

int main()
{
	const int width = 25, height = 25;
	int map[width * height];
	CaveGen gen = CaveGen(map, width, height);
	return 0;
}