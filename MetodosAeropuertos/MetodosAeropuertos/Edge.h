#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#pragma once

class Vertex;

class Edge
{
public:
	double dist;
	Vertex * origin;
	Vertex * destiny;
	Edge(double);
	~Edge();
};

#endif // !EDGE_H_INCLUDED