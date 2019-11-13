// Week 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

class B {


};

class A {
private:
	B * m_b;
public:
	A() {
		m_b = new B();
	}
	~A() {
		delete m_b;
	}
};

int main()
{
	std::vector<int> * myVect = new std::vector<int>();
	int * myArray = new int[5]();
	//Dont Use free(). It won't call the deconstructor!
	//free(myVect);
	delete[] myArray;
	delete myVect;


	A * a = new A(); 
	// Do stuff
	delete a;
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
