#include <stdio.h>
#include <iostream>
#include <sstream>
#include "CaveGen.h"

int main()
{
	int death, birth, it, width, height;
	int* map = nullptr;
	std::stringstream ss;
	CaveGen gen;
	std::string in = "";
	char c = ' ';
	while (c != 'q')
	{
		std::cout << "[q]uit [n]ew [i]terate\n";
		std::cin >> c;
		std::cin.ignore(1000, '\n');
		switch (c)
		{
		case 'q':
			continue;
		case 'i':
			if (map == nullptr)
			{
				std::cout << "\nNo current map\n";
				continue;
			}
			gen.iterate();
			gen.print();
			break;
		case 'n':
			std::cout << "\nEnter cave parameters(width height iterations deathLimit birthLimit): ";
			std::getline(std::cin, in);
			ss << in;
			ss >> width >> height >> it >> death >> birth;
			map = new int[width * height];	
			gen = CaveGen(map, width, height, death, birth, it);
			break;
		default:
			continue;
		}
		std::cout << "\n";
	}
	return 0;
}