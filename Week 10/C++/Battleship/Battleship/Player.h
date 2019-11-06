#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Gameboard.h"
#include "Grid.h"

class Player {
private:
	int shipsSunk;
	Grid lastSpot;
	int next;
	int amount;
	int shots;
public:
	Player();
	int turns;
	void simpleShoot(Gameboard* board);
	void smartShoot(Gameboard* board);
	int sunkShips();
};

#endif