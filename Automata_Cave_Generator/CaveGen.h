#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <random>

class CaveGen {
public:
	CaveGen(int _map[], const int _width, const int _height) {
		this->map = _map;
		this->width = _width;
		this->height = _height;
		int liveChance = 40; // 40% chance to start open
		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < width; c++)
			{
				if (random() < liveChance)
					map[r*width + c] = 1;
				else
					map[r*width + c] = 0;
			}
		}
		print();
	}
	void print() {
		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < width; c++)
			{
				std::cout << iToChar[map[r*width + c]] << " ";
			}
			std::cout << "\n";
		}
	}
private:
	int* map;
	int width, height;
	int random() // return a value 1-100
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 99);
		return dist(gen) + 1;
	}
	char iToChar[2] = { '-' , '#' };
};