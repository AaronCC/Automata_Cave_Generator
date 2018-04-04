#include <stdio.h>
#include <iostream>
#include <sstream>
#include "CaveGen.h"

int main()
{
	int death, birth, it, width, height;
	int* map;
	std::stringstream ss;
	std::string in = "";
	while (in != "q")
	{
		std::cout << "[q]uit\nEnter cave parameters (width height iterations deathLimit birthLimit): ";
		std::getline(std::cin, in);
		ss << in;
		ss >> width >> height >> it >> death >> birth;
		map = new int[width * height];
		CaveGen gen = CaveGen(map, width, height, death, birth, it);
		std::cout << "\n";
	}
	return 0;
}