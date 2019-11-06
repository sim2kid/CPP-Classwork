#include "Player.h"
#include "Gameboard.h"

Player::Player() {
	this->shipsSunk = 0;
	this->lastSpot = Grid();
	this->next = 0;
	this->amount = 1;
	this->shots = 0;
	this->turns = 0;
}

int Player::sunkShips() {
	return this->shipsSunk;
}

void Player::simpleShoot(Gameboard* board) {
	for (int x = (int)floor(shots / board->getSize()); x < board->getSize(); x += this->amount) {
		for (int y = shots % board->getSize(); y < board->getSize(); y += this->amount) {
			if (board->getSpot(x, y)->state < 0) {
				int hit = board->shoot(x, y, board);
				this->turns++;
				this->shots += amount;
				if (hit == 2) {
					shipsSunk++;
					this->lastSpot = Grid();
					this->next = 0;
					return;
				}
				else if (hit == 1) {
					this->lastSpot = Grid(x, y, false);
					this->next = 0;
				}
				else if (hit == 0) {
					this->lastSpot = Grid();
					this->next = 0;
				}
				return;
			}
			else 
			{
				this->shots += 1;
			}
		}
	}
}

void Player::smartShoot(Gameboard* board) {
	this->amount = 3;
	if (this->lastSpot.getX() == -1) {
		int size = board->getSize();
		while (true) {
			int x = (rand() % size);
			int y = (rand() % size);
			if (board->getSpot(x, y)->state == -1) {
				int hit = board->shoot(x, y, board);
				this->turns++;
				if (hit == 2) {
					shipsSunk++;
					this->lastSpot = Grid();
					this->next = 0;
				}
				else if (hit == 1) {
					this->lastSpot = Grid(x, y, false);
					this->next = 0;
				}
				else if (hit == 0) {
					this->lastSpot = Grid();
					this->next = 0;
				}
				break;
			}
		}
		return;
	} else {
		int x = this->lastSpot.getX();
		int y = this->lastSpot.getY();
		int max = board->getSize() - 1;
		if (this->next == 0 && !(x > 0 && y > 0)) {
			this->next++;
		}
		if (this->next == 1 && !(x > 0)) {
			this->next++;
		}
		if (this->next == 2 && !(x > 0 && y < max)) {
			this->next++;
		}
		if (this->next == 3 && !(y < max)) {
			this->next++;
		}
		if (this->next == 4 && !(x < max && y < max)) {
			this->next++;
		}
		if (this->next == 5 && !(x < max)) {
			this->next++;
		}
		if (this->next == 6 && !(x < max && y > 0)) {
			this->next++;
		}
		if (this->next == 7 && !(y > 0)) {
			this->lastSpot = Grid();
			this->next = 0;
			simpleShoot(board);
			return;
		}else if (this->next > 7) {
			this->lastSpot = Grid();
			this->next = 0;
			simpleShoot(board);
			return;
		}

		if (0 <= this->next && this->next <= 2) {
			x -= 1;
		} else if (4 <= this->next && this->next <= 6) {
			x += 1;
		}
		if (2 <= this->next && this->next <= 4) {
			y += 1;
		} else if ((6 <= this->next && this->next <= 7) || this->next == 0) {
			y -= 1;
		}
		int hit = board->shoot(x, y, board);
		this->turns++;
		if (hit == 2) {
			shipsSunk++;
			this->lastSpot = Grid();
			this->next = 0;
			return;
		}
		else if (hit == 1) {
			this->next++;
		}
		else if (hit == 0) {
			this->next++;
		}
		else if (hit == -2) 
		{
			this->next++;
		}
	}
}