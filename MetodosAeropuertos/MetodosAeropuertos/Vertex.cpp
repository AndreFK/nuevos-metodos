#include "Vertex.h"


Vertex::Vertex() {}

Vertex::Vertex(string name, int num)
{
	this->id = name;
	this->num = num;
}

vector<Vertex*> Vertex::getAdj() {
	vector<Vertex*> Adj;
	for (size_t i = 0; i < edges.size(); i++) {
		Adj.push_back(edges[i]->destiny);
	}
	return Adj;
}

Vertex::~Vertex()
{
}
