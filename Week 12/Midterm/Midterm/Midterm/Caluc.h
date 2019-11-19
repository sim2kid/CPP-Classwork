#pragma once
#ifndef CALUC_H
#define CALUC_H

#include <stack>
#include "State.h"

class Caluc {
private:
	std::stack<State> * history;
	std::stack<State> * future;
public:
	Caluc();
	~Caluc();
	State lastState();
	State nextState();
	int lastAns();
	State Undo();
	State Redo();
	void Commit(State next);
};

#endif