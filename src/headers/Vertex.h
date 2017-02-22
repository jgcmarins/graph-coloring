
/*
*
* date: Sex Set 11 15:24:12 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vertex {

	private:

		T object;
		vector<Vertex<T> *> *adjacencyList;

	public:

		Vertex(T object);

		virtual ~Vertex();

		// setters

		virtual void setObject(T object);

		virtual void setNewAdjacent(Vertex<T> *adjacent);

		// getters

		virtual T getObject();

		virtual vector<Vertex<T> *> *getAdjacencyList();

		virtual Vertex<T> *getAdjacent(int position);

		// methods

		virtual int findAdjacent(Vertex<T> *adjacent, int compareFunction(T, T));

		virtual int removeAdjacent(Vertex<T> *adjacent, int compareFunction(T, T));

		virtual int removeAdjacent(int position);

		virtual void listAdjacents(void printFunction(T));

};

#endif
