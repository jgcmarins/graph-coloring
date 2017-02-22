
/*
*
* date: Sáb Set 12 19:21:04 BRT 2015
* author: Joao Gustavo Cabral de Marins
* e-mail: jgcmarins@gmail.com
*
*/

#include "../vertex/Vertex.cc"

template <class T>
class Graph {

	private:

		vector<Vertex<T> *> *vertices;

	public:

		Graph();

		virtual ~Graph();

		// setters

		virtual void setNewVertex(Vertex<T> *vertex);

		// getters

		virtual vector<Vertex<T> *> *getVertices();

		virtual Vertex<T> *getVertex(int position);

		// methods

		virtual int findVertex(Vertex<T> *vertex, int compareFunction(T, T));

		virtual int removeVertex(Vertex<T> *vertex, int compareFunction(T, T));

		virtual int removeVertex(int position);

		virtual void listVertices(void printFunction(T));
 
};
