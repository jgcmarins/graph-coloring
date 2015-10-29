
/*
*
* date: Sex Out  2 14:23:46 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#ifndef _BACKTRACKING_H_
#define _BACKTRACKING_H_

#include "../graph/Graph.cc"
#include "State.h"

class Backtracking {

	public:

		static void graphColoring(Graph<State *> *g, unsigned int k);

		static bool isSafe(Vertex<State *> *v, int c);

};

#endif
