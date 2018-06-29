#pragma once
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"



class ProyectMethods {
private:
	int cantV;
public:
	std::vector<Vertex*> vertexes;

	ProyectMethods();

	void Update_IDroute(const char *, const char *);
	void Delete_allIDroutes(const char *);

	void Create_Airport(const char *,double,double);
	void Read_Airport(char*,int);
	int Lenght_Arch();
	void Delete_Airport(const char *);
	void Update_Airport(const char*, const char*, double, double);
	bool Exist_Airport(const char *);

	double getLat(const char*);
	double getLng(const char*);

	int Create_Route(const char *, const char *, double);
	void Read_Route(char *, int);
	int Lenght_R();
	void Delete_Route(const char *,const char*);
	void Update_Route(const char*, const char *, const char *, double);

	void dijkstra(const char*);
	void dijk(Vertex * origen);

	int cantRutas(const char *, const char *);
	int cantR(const char*, const char*, int);

	double weight(Vertex *, Vertex *);
	queue<Edge *> sortedEdges(Vertex*);

	void createRutasID(const char*, const char*);

	void crearVertices();
	void crearAristas();
	void borrarVertice(string id);
	void borrarArista(string orig, string dest);
};