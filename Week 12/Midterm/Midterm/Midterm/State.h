#pragma once
#ifndef STATE_H
#define STATE_H

#include <string>

class State {
private:
	std::string formula;
	int ans;
public:
	State(std::string _formula, int _ans);
	std::string getFormula();
	int getAns();
	std::string toString();
	~State();
};

#endif