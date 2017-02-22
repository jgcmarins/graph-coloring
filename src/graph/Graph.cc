
/*
*
* date: Dom Set 13 12:23:34 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include "../headers/Graph.h"

template <class T>
Graph<T>::Graph() {
	this->vertices = new vector<Vertex<T> *>();
}

template <class T>
Graph<T>::~Graph() {
	this->vertices->clear();
	delete this->vertices;
}

// setters

template <class T>
void Graph<T>::setNewVertex(Vertex<T> *vertex) { this->vertices->push_back(vertex); }

// getters

template <class T>
vector<Vertex<T> *> *Graph<T>::getVertices() { return this->vertices; }

template <class T>
Vertex<T> *Graph<T>::getVertex(int position) {
	if((position >= 0) && ((unsigned int)position < this->vertices->size())) return this->vertices->at(position);
	return NULL;
}

// methods

template <class T>
int Graph<T>::findVertex(Vertex<T> *vertex, int compareFunction(T, T)) {
	for(unsigned int i = 0 ; i < this->vertices->size() ; i++)
		if(compareFunction(vertex->getObject(), this->vertices->at(i)->getObject()) == 0) return i;
	return -1;
}

template <class T>
int Graph<T>::removeVertex(Vertex<T> *vertex, int compareFunction(T, T)) {
	int position = this->findVertex(vertex, compareFunction);
	for(unsigned int i = 0 ; i < this->vertices->size() ; i++) {
		if(i != (unsigned int) position) {
			Vertex<T> *adjacent = this->vertices->at(i);
			adjacent->removeAdjacent(vertex, compareFunction);
		}
	}
	if(position == -1) return position;
	return this->removeVertex(position);
}

template <class T>
int Graph<T>::removeVertex(int position) {
	if((position >= 0) && ((unsigned int)position < this->vertices->size())) {
		this->vertices->erase(this->vertices->begin() + position);
		return position;
	}
	return -1;
}

template <class T>
void Graph<T>::listVertices(void printFunction(T)) {
	for(unsigned int i = 0 ; i < this->vertices->size() ; i++) this->vertices->at(i)->listAdjacents(printFunction);
}
