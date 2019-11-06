// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Gameboard.h"
#include <iostream>
#include <time.h>
#include "Player.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

void showBoardState(Gameboard a, Gameboard b);

int main()
{
	srand(time(NULL));
	Gameboard b = Gameboard(50, 90);
	Gameboard a = Gameboard(50, 90);
	Player smart = Player();
	Player dumb = Player();
	int turns = 0;
	while (!a.allSunk() && !b.allSunk()) {
		if (turns % 2 == 0) {
			smart.smartShoot(&b);
		}
		else if (turns % 2 == 1 && smart.turns -1 <= dumb.turns) {
			dumb.simpleShoot(&a);
		}
		if (turns % 500 == 0) {
			showBoardState(a, b);
			cout << " " << smart.sunkShips() << " / " << b.getShips() << " Turns: " << smart.turns << endl;
			cout << " " << dumb.sunkShips() << " / " << a.getShips() << " Turns: " << dumb.turns << endl;
		}
		
		turns++;
	}
	showBoardState(a, b);
	cout << " " << smart.sunkShips() << " / " << b.getShips() << " Turns: " << smart.turns << endl;
	cout << " " << dumb.sunkShips() << " / " << a.getShips() << " Turns: " << dumb.turns << endl;
}

void showBoardState(Gameboard a, Gameboard b) {
	cout << "---------------------\n";
	a.display(true);
	b.display(true);
}