#pragma once
#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>

class Grid {
private:
	int x;
	int y;
	bool hasBoat;
public:
	int state;
	Grid(int gridX, int gridY, bool boat);
	Grid();
	int getX();
	int getY();
	bool getHasBoat();
};

#endif