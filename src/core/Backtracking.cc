
/*
*
* date: Sáb Out  3 13:39:57 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include "../headers/Backtracking.h"

void Backtracking::graphColoring(Graph<State *> *g, unsigned int k) {
	for(int c = AZUL ; c < MAX_COLOUR ; c++) {
		Vertex<State *> *v = g->getVertices()->at(k);
		if(isSafe(v, c)) {
			v->getObject()->setColour(c);
			if(k + 1 < g->getVertices()->size()) graphColoring(g, k + 1);
			else return;
		}
	}
}

bool Backtracking::isSafe(Vertex<State *> *v, int c) {
	for(unsigned int i = 0 ; i < v->getAdjacencyList()->size() ; i++) {
		Vertex<State *> *adjacent = v->getAdjacent(i);
		if(adjacent->getObject()->getColour() == c) return false;
	}
	return true;
}
