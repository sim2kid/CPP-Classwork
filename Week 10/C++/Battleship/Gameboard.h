#pragma once
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <string>
#include <vector>

class GameBoard {
private:
	int size;
	vector<Grid> myGrid;
public:
	GameBoard();
	~GameBoard();
};

#endif