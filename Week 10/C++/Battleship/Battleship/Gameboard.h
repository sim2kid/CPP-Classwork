#pragma once
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <string>
#include <vector>
#include "Grid.h"

class Gameboard {
private:
	int size;
	int ships;
	std::vector<Grid> myGrid;
public:
	Gameboard(int boardSize, int shipAmount);
	int shoot(int x, int y, Gameboard *board);
	int getSize();
	int getShips();
	Grid* getSpot(int theX, int theY);
	void display(bool withShips);
	bool allSunk();
};

#endif