#include "pch.h"
#include "Brain.h"

#include <string>
#include <vector>
#include <regex>
#include <iostream>

Brain::Brain(std::string line, int last) {
	Brain::mathline = new std::vector<std::string>();
	std::regex all("([-%+*/a]{1})|([0-9]{1,})");

	std::smatch m;
	std::string subject = line;

	while (std::regex_search(subject, m, all)) {
		if (m.str(0) == "a") {
			Brain::mathline->push_back(std::to_string(last));
		}
		else {
			Brain::mathline->push_back(m.str(0));
		}
		
		subject = m.suffix().str();
	}
}

State Brain::calculate() {
	std::string str = this->toString();
	std::regex nums("([0-9]{1,})");
	std::regex opps("([-%+*/{1}])");
	int i = 0;

	for (auto it = Brain::mathline->begin(); it != Brain::mathline->end(); it++, i++) {
		if (i % 2 == 0) {
			//Numbers
			if (!regex_match(*it, nums)) {
				return State("Error Non-Valid Equation: " + this->toString(), 0);
			} 
		}
		else {
			//Opertators
			if (!regex_match(*it, opps)) {
				return State("Error Non-Valid Equation: " + this->toString(), 0);
			}
		}
	}
	if (i <= 1 || i % 2 != 1) {
		return State("Error Non-Valid Equation: " + this->toString(), 0);
	}

	// / and * and %
	for (auto it = Brain::mathline->begin(); it != Brain::mathline->end(); it++) {
		if (*it == "/" || *it == "%" || *it == "*") {
			it--;
			int before = std::stoi(*it);
			it = Brain::mathline->erase(it);
			it++;
			int after = std::stoi(*it);
			it = Brain::mathline->erase(it);
			it--;
			if (*it == "/") {
				*it = std::to_string(before / after);
			}
			else if (*it == "%") {
				*it = std::to_string(before % after);
			}
			else if (*it == "*") {
				*it = std::to_string(before * after);
			}
			else {
				std::cerr << "Error in Multiplication! Sign unknown :" << *it << std::endl;
			}
		}
	}

	// For + and -

	for (auto it = Brain::mathline->begin(); it != Brain::mathline->end(); it++) {
		if (*it == "+" || *it == "-") {
			it--;
			int before = std::stoi(*it);
			it = Brain::mathline->erase(it);
			it++;
			int after = std::stoi(*it);
			it = Brain::mathline->erase(it);
			it--;
			if (*it == "+") {
				*it = std::to_string(before + after);
			}
			else if (*it == "-") {
				*it = std::to_string(before - after);
			}
			else {
				std::cerr << "Error in Addition! Sign unknown :" << *it << std::endl;
			}
		}
	}

	int ans = std::stoi(Brain::mathline->front());

	return State(str, ans);
}

std::string Brain::toString() {
	std::string retn = "";
	for (auto it = Brain::mathline->begin(); it != Brain::mathline->end(); it++) {
		retn += *it;
	}
	return retn;
}

Brain::~Brain() {
	delete Brain::mathline;
}