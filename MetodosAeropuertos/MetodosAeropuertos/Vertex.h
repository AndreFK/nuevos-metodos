#ifndef  VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "Edge.h"

#pragma once

using namespace std;

class Vertex
{
public:	
	int num;
	vector<Edge*> edges;
	string id;
	Vertex();
	Vertex(string, int);
	vector<Vertex*> getAdj();//obtiene las aristas conectadas a este vertice
	~Vertex();
};

#endif // ! VERTEX_H_INCLUDED