#include "Caluc.h"
#include "pch.h"
#include <stack>
#include "State.h"

Caluc::Caluc() {
	Caluc::history = new std::stack<State>();
	Caluc::future = new std::stack<State>();
}

int Caluc::lastAns() {
	if (!Caluc::history->empty()) {
		return Caluc::history->top().getAns();
	}
	else {
		return 0;
	}
}

State Caluc::lastState() {
	if (!Caluc::history->empty()) {
		return Caluc::history->top();
	}
	else {
		return State("No Last Equation", -1);
	}
}

State Caluc::nextState() {
	if (!Caluc::future->empty()) {
		return Caluc::future->top();
	}
	else {
		return State("No Next Equation", -1);
	}
}

Caluc::~Caluc() {
	delete Caluc::history;
	delete Caluc::future;
}

State Caluc::Undo() {
	if (!Caluc::history->empty()) {
		Caluc::future->push(Caluc::history->top());
		State re = Caluc::history->top();
		Caluc::history->pop();
		return re;
	}
	else {
		return State("No Undos", -1);
	}
}

void Caluc::Commit(State next) {
	Caluc::history->push(next);
	delete Caluc::future;
	Caluc::future = new std::stack<State>();
}

State Caluc::Redo() {
	if (!Caluc::future->empty()) {
		Caluc::history->push(Caluc::future->top());
		State re = Caluc::future->top();
		Caluc::future->pop();
		return re;
	}
	else {
		return State("No Redos", -1);
	}
}