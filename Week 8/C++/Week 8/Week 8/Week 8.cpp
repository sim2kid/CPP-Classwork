// Week 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Person.h"

const int i = 10;

namespace MyNameSpace {
	void foo() {}
	namespace MyNameSpace2 {
		void boo() {}
	}
}

void hoo(int k = 10) {

}

struct thing {
	int a;
	void poo() {
	
	}
};

struct Node {
	int data;
	Node * next;
};

struct LinkedList {
	void append(Node ** head, int data) {
		Node * new_node = new Node();
		Node * last = *head;
		new_node->data = data;
		new_node->next = nullptr;
		if (*head == nullptr) {
			*head = new_node;
			return;
		}

		while (last->next != nullptr) {
			last = last->next;
		}
		last->next = new_node;
	}
};

int main()
{
	std::string my_string;
	std::cin >> my_string;

	MyNameSpace::foo();
	MyNameSpace::MyNameSpace2::boo();
	
	hoo();

	Person p = Person();
}
/*

S - Single Purpose
O - Open to Extension/ Close to Modification
L - Liskov substitution principle (children must be able to sub for parent)
I - Interface Segrigation (lots of small io as opposed to one big one)
D - Dependency Inversion of control

D - Don't
R - Repeat
Y - Yourself

*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
