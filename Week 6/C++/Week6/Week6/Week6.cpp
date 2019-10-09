// Week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>

/*
using std::cout;
using std::cin;
using std::string;

struct C 
{
	int i;
};

int main()
{
	C * c = new C();
	c - i = 10;
	delete c;
	int * foo = nullptr;
	string s = "dfgflj UADEHcvkjghD";
	int i = 0;
    cout << "Hello World!\n"; 
	cin >> i;
	std::cerr << "Whoopsie!";
	return 0;
}
*/

/*
#include <vector>

int main() 
{
	std::vector<int> my_vect;
	my_vect.push_back(10);
	my_vect.push_back(20);

	for (std::vector<int>::iterator it = my_vect.begin(); it != my_vect.end(); it++) {
		std::cout << *it << std::endl;
	}

	for (int i : my_vect) {
		std::cout << i << std::endl;
	}

	return 0;
}
*/

#include <set>

int main() {
	std::set<int> my_set;
	my_set.emplace(10);
	my_set.emplace(1);
	my_set.emplace(2);
	my_set.emplace(1);

	for (int i : my_set) {
		std::cout << i << std::endl;
	}
	return 0;
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
