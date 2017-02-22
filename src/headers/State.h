
/*
*
* date: Qua Set 30 20:46:08 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#ifndef _STATE_H_
#define _STATE_H_

#include <string>
#include <iostream>

using namespace std;

#define BRANCO 0
#define AZUL 1
#define AMARELO 2
#define VERDE 3
#define VERMELHO 4
#define MAX_COLOUR 5

#define BRANCO_ "Branco"
#define AZUL_ "Azul"
#define AMARELO_ "Amarelo"
#define VERDE_ "Verde"
#define VERMELHO_ "Vermelho"

class State {

	private:
		string *name;
		int colour;

	public:

		State(string *name);

		virtual ~State();

		// setters

		virtual void setName(string *name);

		virtual void setColour(int colour);

		// getters

		virtual string *getName();

		virtual int getColour();

		// methods

		virtual const char *colourToString();

		static void printStateName(State *s);

		static int compareState(State *s1, State *s2);
};

#endif
