#include "pch.h"
#include "Caluc.h"
#include "State.h"
#include "Brain.h"
#include <iostream>
#include <string>

int main()
{
	bool online = true;
	Caluc c = Caluc();
	
	while (online) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		std::cout << "Don't Use Spaces. Operations: +, -, *, /, %. Only Ints. a = Last Ans." << std::endl;
		std::cout << "[u | un | undo] to undo. [r | re | redo] to redo." << std::endl;
		std::cout << "> a = " << c.lastAns() << std::endl;
		std::cout << std::endl;
		std::cout << "> " << c.lastState().toString() << std::endl;
		//std::cout << "Next > " << c.nextState().toString() << std::endl;
		std::cout << std::endl;
		std::string input = "";
		std::cin >> input;
		if (input == "u" || input == "un" || input == "undo") {
			c.Undo();
		}
		else if (input == "r" || input == "re" || input == "redo") {
			c.Redo();
		}
		else {
			Brain b = Brain(input, c.lastAns());
			State s = b.calculate();
			c.Commit(s);
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
