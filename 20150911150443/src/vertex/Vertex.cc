
/*
*
* date: Sex Set 11 15:29:17 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include "../headers/Vertex.h"

template <class T>
Vertex<T>::Vertex(T object) {
	this->object = object;
	this->adjacencyList = new vector<Vertex<T> *>();
}

template <class T>
Vertex<T>::~Vertex() {
	this->object = NULL;
	this->adjacencyList->clear();
	delete this->adjacencyList;
}

// setters

template <class T>
void Vertex<T>::setObject(T object) { this->object = object; }

template <class T>
void Vertex<T>::setNewAdjacent(Vertex<T> *adjacent) { this->adjacencyList->push_back(adjacent); }

// getters

template <class T>
T Vertex<T>::getObject() { return this->object; }

template <class T>
vector<Vertex<T> *> *Vertex<T>::getAdjacencyList() { return this->adjacencyList; }

template <class T>
Vertex<T> *Vertex<T>::getAdjacent(int position) {
	if((position >= 0) && ((unsigned int)position < this->adjacencyList->size())) return this->adjacencyList->at(position);
	return NULL;	
}

// methods

template <class T>
int Vertex<T>::findAdjacent(Vertex<T> *adjacent, int compareFunction(T, T)) {
	for(unsigned int i = 0 ; i < this->adjacencyList->size() ; i++)
		if(compareFunction(adjacent->getObject(), this->adjacencyList->at(i)->getObject()) == 0) return i;
	return -1;
}

template <class T>
int Vertex<T>::removeAdjacent(Vertex<T> *adjacent, int compareFunction(T, T)) {
	int position = this->findAdjacent(adjacent, compareFunction);
	if(position == -1) return position;
	return this->removeAdjacent(position);
}

template <class T>
int Vertex<T>::removeAdjacent(int position) {
	if((position >= 0) && ((unsigned int)position < this->adjacencyList->size())) {
		this->adjacencyList->erase(this->adjacencyList->begin() + position);
		return position;
	}
	return -1;
}

template <class T>
void Vertex<T>::listAdjacents(void printFunction(T)) {
	printFunction(this->object);
	cout << ": ";
	for(unsigned int i = 0 ; i < this->adjacencyList->size() ; i++) {
		if(i < (this->adjacencyList->size() - 1)) {
			printFunction(this->adjacencyList->at(i)->getObject());
			cout << ", ";
		} else {
			printFunction(this->adjacencyList->at(i)->getObject());
			break;
		}
	}
	cout << endl;
}
