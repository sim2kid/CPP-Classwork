#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:

public:
	Person();
	~Person();
	int age;
	std::string name;
	float weight;

	void greet();
};

#endif