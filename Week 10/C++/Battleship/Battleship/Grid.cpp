#include "Grid.h"


Grid::Grid(int gridX, int gridY, bool boat) {
	this->state = -1;
	this->x = gridX;
	this->y = gridY;
	this->hasBoat = boat;
}

Grid::Grid() {
	this->state = -1;
	this->x = -1;
	this->y = -1;
	this->hasBoat = false;
}

int Grid::getX() {
	return this->x;
}

int Grid::getY() {
	return this->y;
}

bool Grid::getHasBoat() {
	return this->hasBoat;
}