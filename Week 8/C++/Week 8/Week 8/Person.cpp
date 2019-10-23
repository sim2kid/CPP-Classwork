#include "Person.h"
#include <iostream>


void Person::greet() {
	std::cout << "Hello " << this->name << std::endl;
}

Person::Person() {
	this->age = 0;
	this->name = "Boobbie";
	this->weight = 155;
}