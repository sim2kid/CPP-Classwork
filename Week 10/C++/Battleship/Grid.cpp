#include "Grid.h"
#include <iostream>


Grid::Grid(int gridX, int gridY, bool boat) {
	Grid::state = -1;
	Grid::x = gridX;
	Grid::y = gridY;
	Grid::hasBoat = boat;
}

int Grid::getX() {
	return Grid::x;
}

int Grid::getY() {
	return Grid::y;
}

bool Grid::getHasBoat() {
	return hasBoat;
}