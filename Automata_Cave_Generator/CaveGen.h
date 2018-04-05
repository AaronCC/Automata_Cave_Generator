#include <stdio.h>
#include <iostream>
#include <random>
#include <map>

class CaveGen {
public:
	CaveGen(int _map[], const int _width, const int _height, int _dLimit, int _bLimit, int iterations) {
		this->map = _map;
		this->width = _width;
		this->height = _height;
		this->dLimit = _dLimit;
		this->bLimit = _bLimit;
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
		for (int i = 0; i < iterations; i++)
			iterate();
		print();
	}
	CaveGen()
	{

	}
	void print() {
		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < width; c++)
			{
				std::cout << iToChar(map[r*width + c]) << " ";
			}
			std::cout << "\n";
		}
	}
	void iterate() {
		const int size = width * height;
		newMap = new int[size];
		for (int c = 0; c < width; c++)
		{
			for (int r = 0; r < height; r++)
			{
				int nCount = getAliveNeighbors(c, r);
				if ((bool)map[r*width + c]) {
					if (nCount < dLimit)
						newMap[r*width + c] = 0;
					else
						newMap[r*width + c] = 1;
				}
				else
				{
					if (nCount > bLimit)
						newMap[r*width + c] = 1;
					else
						newMap[r*width + c] = 0;
				}
			}
		}
		std::memcpy(map, newMap, size * sizeof(int));
	}
	std::map<int,int> flood()
	{
		std::map<int, int> caves;
		int fcount = 2;
		for (int r = 0; r < height; r++)
			for (int c = 0; c < width; c++)
				if (map[r*width + c] == 1)
				{
					caves[fcount] = floodfill(c, r, fcount);
					fcount++;
				}
		return caves;
	}
	int floodfill(int c, int r, int fill)
	{
		if (c < 0 || r < 0 || c >= width || r >= height)
			return 0;
		int size = 0;
		int target = map[r*width + c];
		if (target == fill || target == 0)
			return 0;
		else
		{
			map[r*width + c] = fill;
			size++;
			size += floodfill(c - 1, r, fill);
			size += floodfill(c + 1, r, fill);
			size += floodfill(c, r - 1, fill);
			size += floodfill(c, r + 1, fill);
		}
		return size;
	}
private:
	int* map;
	int* newMap;
	int width, height, dLimit, bLimit;
	int random() // return a value 1-100
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 99);
		return dist(gen) + 1;
	}
	int getAliveNeighbors(int x, int y)
	{
		int count = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				int c = x + i;
				int r = y + j;
				if (i == 0 && j == 0) {
					continue;
				}
				else if (c < 0 || r < 0 || c >= width || r >= height) {
					count = count + 1;
				}
				else if ((bool)map[r*width + c]) {
					count = count + 1;
				}
			}
		}
		return count;
	}
	//char clist[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::string iToChar(int i)
	{
		switch (i)
		{
		case 1:
			return " ";
		case 0:
			return "#";
		default:
			return std::to_string(i);
			break;
		}
	}
};