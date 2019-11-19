#include "State.h"
#include "pch.h"
#include <string>

State::State(std::string _formula, int _ans) {
	State::formula = _formula;
	State::ans = _ans;
}

std::string State::getFormula() {
	return State::formula;
}

std::string State::toString() {
	return State::formula + " = " + std::to_string(State::ans);
}

int State::getAns() {
	return State::ans;
}

State::~State() {
	
}