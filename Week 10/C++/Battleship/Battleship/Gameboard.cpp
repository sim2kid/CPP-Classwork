#include "Gameboard.h"
#include "Grid.h"
//#include "pch.h"
#include <iostream>


Gameboard::Gameboard(int boardSize, int shipAmount) {
	this->size = boardSize;
	this->ships = shipAmount;
	int totalShips = 0;
	for (int x = 0; x < boardSize; x++) {
		for (int y = 0; y < boardSize; y++) {
			bool ship = false;
			if ((double)(rand() % 100) + 1 <= (double)100 * ((double) shipAmount / ((double)boardSize * boardSize)) && totalShips <= shipAmount) {
				ship = true;
				totalShips++;
			}
			this->myGrid.push_back(Grid(x, y, ship));
		}
	}
	this->ships = totalShips;
}

int Gameboard::getShips() {
	return this->ships;
}

int Gameboard::getSize() {
	return this->size;
}

Grid* Gameboard::getSpot(int theX, int theY) {
	
	if (theX < 0 || theX > this->getSize() || theY < 0 || theY > this->getSize()) {
		return nullptr;
	}
	long at = theY + (theX * this->getSize());
	if (at < (this->getSize() * this->getSize()) && at >= 0) {
		return &this->myGrid.at(at);
	}
}

int Gameboard::shoot(int x, int y, Gameboard *board) {
	int theState = 0;
	for (int xA = x - 1; xA <= x + 1; xA++) {
		for (int yA = y - 1; yA <= y + 1; yA++) {
			if (!(xA < 0 || yA < 0 || xA >= board->getSize() || yA >= board->getSize())) {
				Grid* spot = board->getSpot(xA, yA);
				if (spot != nullptr && theState < 2) {
					if (spot->getHasBoat()) {
						if (!spot->state > -1) {
							theState = 1;
						}
						if (xA == x && yA == y) {
							if (spot->state > -1) {
								theState = 3;
							}
						}
					}
					
				}
			}
		}
	}
	if (theState == 3)
	{
		board->getSpot(x, y)->state = 2;
		return -2;
	} 
	else
	{
		board->getSpot(x, y)->state = theState;
		return theState;
	}
}

bool Gameboard::allSunk() {
	for (auto it = this->myGrid.begin(); it != this->myGrid.end(); it++) {
		if (it->getHasBoat() && it->state == -1) {
			return false;
		}
	}
	return true;
}

void Gameboard::display(bool withShips) {
	std::cout << "\n" << std::endl;
	std::cout << " -- -- Size: " << this->getSize() << " -- --" << std::endl;
	int x = 0;
	std::cout << "     ";
	for (int y = 0; y < this->getSize(); y++) {
		if (y < 10) {
			std::cout << y << "   ";
		}
		else if (y < 100) {
			std::cout << y << "  ";
		}
	}
	std::cout << "\n0   ";
	for (auto it = this->myGrid.begin(); it != this->myGrid.end(); it++) {
		if (it->getX() > x) {
			x = it->getX();
			if (x < 10) {
				std::cout << "\n" << x << "   ";
			}
			else if (x < 100) {
				std::cout << "\n" << x << "  ";
			}
		}
		std::cout << "[";
		if (withShips) {
			if (it->state != -1) {
				if (it->getHasBoat()) {
					std::cout << "X";
				}
				else {
					std::cout << "-";
				}
			}
			else {
				if (it->getHasBoat()) {
					std::cout << "*";
				}
				else
				{
					std::cout << " ";
				}
			}
		} else if (it->state == -1) {
			std::cout << " ";
		} else if (it->state == 0) {
			std::cout << "-";
		} else if (it->state == 1) {
			std::cout << "+";
		} else if (it->state == 2) {
			std::cout << "X";
		}
		else if (it->state == -2) {
			std::cout << "X";
		}
		std::cout << "] ";
	}
	std::cout << "\n" << std::endl;
}