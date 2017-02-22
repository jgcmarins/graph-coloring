
/*
*
* date: Sex Set 11 15:19:17 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include <cstring>
#include <cstdio>
#include <chrono>

#include "../headers/Backtracking.h"
#include "../headers/Tokenizer.h"

char *readString() {
	char *buffer = NULL;
	int c, i = 0;
	do {
		c = fgetc(stdin);
		buffer = (char *) realloc(buffer, sizeof(char)*(i+1));
		buffer[i++] = c;
	} while(!feof(stdin));

	buffer[i-1] = '\0';

	return buffer;
}

void createNode(Graph<State *> *g, vector<State *> *states) {
	State *s = new State(new string(states->at(0)->getName()->data()));
	Vertex<State *> *v = new Vertex<State *>(s);

	int first = g->findVertex(v, State::compareState);
	if(first == -1) {
		g->setNewVertex(v);
		first = g->findVertex(v, State::compareState);
	} else {
		delete v;
		string *name = s->getName();
		delete s;
		delete name;
	}

	for(unsigned int i = 1 ; i < states->size() ; i++) {
		State *s = new State(new string(states->at(i)->getName()->data()));
		Vertex<State *> *aux = new Vertex<State *>(s);

		int position = g->findVertex(aux, State::compareState);
		if(position == -1) {
			g->setNewVertex(aux);
			position = g->findVertex(aux, State::compareState);
		} else {
			delete aux;
			string *name = s->getName();
			delete s;
			delete name;
		}

		g->getVertices()->at(first)->setNewAdjacent(g->getVertices()->at(position));
	}
}

void organizeInformation(Graph<State *> *g, string *str) {
	vector<State *> *states = new vector<State *>();

	vector<string*> *node = Tokenizer::splitString(str, ":");

	states->push_back(new State(new string(node->at(0)->data()))); // saving first
	vector<string *> *adjacents = Tokenizer::splitString(node->at(1), ",");

	for(unsigned int i = 0 ; i < adjacents->size() ; i++) {
		string *adjacent = adjacents->at(i);
		if(adjacent->at(adjacent->length() - 1) == '.') adjacent->pop_back(); // releasing '.'
		string *sub = new string(adjacent->substr(1)); // releasing ' '
		states->push_back(new State(sub)); // saving adjacents
	}

	while(adjacents->size() > 0) {
		string *adjacent = adjacents->at(adjacents->size() - 1);
		adjacents->pop_back();
		delete adjacent;
	}
	delete adjacents;

	while(node->size() > 0) {
		string *adjacent = node->at(node->size() - 1);
		node->pop_back();
		delete adjacent;
	}
	delete node;

	createNode(g, states);

	while(states->size() > 0) {
		State *s = states->at(states->size() - 1);
		states->pop_back();
		string *name = s->getName();
		delete s;
		delete name;
	}
	delete states;
}

void readInput(Graph<State *> *g) {
	char *buffer = readString();
	string *input = new string(buffer);
	free(buffer);

	vector<string *> *lines = Tokenizer::splitString(input, "\n");
	delete input;

	for(unsigned int i = 0 ; i < lines->size() ; i++) {
		if(lines->at(i)->length() > 0) organizeInformation(g, lines->at(i));
	}

	while(lines->size() > 0) {
		string *str = lines->at(lines->size() - 1);
		lines->pop_back();
		delete str;
	}
	delete lines;
}

void clearGraph(Graph<State *> *g) {
	while(g->getVertices()->size() > 0) {
		Vertex<State *> *v = g->getVertices()->at(g->getVertices()->size() - 1);
		State *s = v->getObject();
		string *name = s->getName();

		g->removeVertex(v, State::compareState);
		delete v;
		delete s;
		delete name;
	}
}

void printResult(Graph<State *> *g) {
	for(unsigned int i = 0 ; i < g->getVertices()->size() ; i++) {
		Vertex<State *> *v = g->getVertices()->at(i);
		State *s = v->getObject();
		cout << s->getName()->data() << ": " << s->colourToString() << "." << endl;
	}
}

int main(int argc, char *argv[]) {

	int n;
	char type;
	scanf("%d %c\n", &n, &type);
	cout << n << " ";

	Graph<State *> *g = new Graph<State *>();

	readInput(g);

	chrono::time_point<chrono::system_clock> start, end;

	start = chrono::system_clock::now();
	Backtracking::graphColoring(g, 0);
	end = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end - start;

	//g->listVertices(State::printStateName);

	//printResult(g);

	clearGraph(g);

	delete g;

	cout << elapsed_seconds.count() << "s" << endl;

	return 0;
}
