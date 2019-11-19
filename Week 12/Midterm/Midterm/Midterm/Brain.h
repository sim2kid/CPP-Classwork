#pragma once
#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <vector>

class Brain {
private:
	std::vector<std::string> * mathline;
public:
	Brain(std::string line, int last);
	State calculate();
	std::string toString();
	~Brain();
};

#endif