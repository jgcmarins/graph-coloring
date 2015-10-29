
/*
*
* date: Qua Set 30 21:06:48 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include "../headers/State.h"

State::State(string *name) {
	this->name = name;
	this->colour = BRANCO;
}

State::~State() {
	this->name = NULL;
}

// setters

void State::setName(string *name) {	this->name = name; }

void State::setColour(int colour) {	this->colour = colour; }

// getters

string *State::getName() { return this->name; }

int State::getColour() { return this->colour; }

// methods

const char *State::colourToString() {
	if(this->colour == BRANCO) return BRANCO_;
	else if(this->colour == AZUL) return AZUL_;
	else if(this->colour == AMARELO) return AMARELO_;
	else if(this->colour == VERDE) return VERDE_;
	else if(this->colour == VERMELHO) return VERMELHO_;
	return NULL;
}

void State::printStateName(State *s) {	cout << s->getName()->data(); }

int State::compareState(State *s1, State *s2) { return s1->getName()->compare(s2->getName()->data()); }
