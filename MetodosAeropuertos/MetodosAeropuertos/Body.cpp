#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ProyectMethods::ProyectMethods() {
	cantV = 0;
}	

void ProyectMethods::Update_IDroute(const char *id, const char*nid) {
	ifstream ArchivoR("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt");

	if (!ArchivoR) { return; }

	string ID;
	string line;
	size_t a;
	string subline;
	if (Exist_Airport(id)) {
		while (getline(ArchivoR, line)) {

			a = line.find(";");
			ID = line.substr(0, a);

			subline = line.substr(a, line.length());

			if (id != ID) {
				fileB << line << "\n";
			}
			else {
				fileB << nid + subline << "\n";
			}


		}

	}
	else
	{
		fileB.close(); ArchivoR.close();
		remove("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt");
		return;
	}

	fileB.close(); ArchivoR.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");


}

void ProyectMethods::Delete_allIDroutes(const char *id) {
	ifstream ArchivoR("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt");

	if (!ArchivoR) { return; }

	string ID;
	string line;
	size_t a;
	while (getline(ArchivoR, line)) {

		a = line.find(";");
		ID = line.substr(0, a);

		if (id != ID) {
			fileB << line << "\n";
		}



	}
	fileB.close(); ArchivoR.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");

}

void ProyectMethods::Create_Airport(const char*name, double lat, double lon) {
	ofstream ArchivoAeropuertos("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt",ios::app);

	if (!ArchivoAeropuertos) { return; }
	
	

	ArchivoAeropuertos << name << ";" << lat << ";" << lon << "\n";
	ArchivoAeropuertos.close();
}

 void ProyectMethods::Read_Airport(char *buff,int posc) {
	ifstream ArchivoAeropuertos("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	if (!ArchivoAeropuertos) { return ; }

	string buffer;
	int i = 0;
	

	while (getline(ArchivoAeropuertos,buffer))
	{
		i++;
		if (i == posc) { break; }
	}
	

	strcpy_s(buff, sizeof buffer, buffer.c_str());
	
	ArchivoAeropuertos.close();
	
}

int ProyectMethods::Lenght_Arch() {
	ifstream ArchivoAeropuertos("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	if (!ArchivoAeropuertos) { return NULL; }
	int i = 0;
	string line;
	while (getline(ArchivoAeropuertos,line)) {
		i++;
	}
	ArchivoAeropuertos.close();
	return i;
}

void ProyectMethods::Delete_Airport(const char *nom) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\AeropuertosTMP.txt");

	string buffer;
	string name;
	size_t n;

	if (!fileA) { return; }

	while (getline(fileA,buffer))
	{
		n = buffer.find(";");
		name = buffer.substr(0, n);

		if (name!=nom)
		{
			fileB << buffer << "\n";
		}

	}

	fileA.close(); fileB.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\AeropuertosTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt");

	cantV--;
}

void ProyectMethods::Update_Airport(const char *name, const char *Newname, double lat, double lon) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\AeropuertosTMP.txt");

	string buffer;
	string nameA;
	size_t n;

	if (!fileA) { return; }

	while (getline(fileA, buffer))
	{
		n = buffer.find(";");
		nameA = buffer.substr(0, n);

		if (nameA != name)
		{
			fileB << buffer << "\n";
		}
		else {
			fileB << Newname << ";" << lat << ";" << lon << "\n";
		}

	}

	for (size_t i = 0; i < vertexes.size(); i++) {
		if (vertexes[i]->id == name) {
			vertexes[i]->id = Newname;
		}
	}

	fileA.close(); fileB.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\AeropuertosTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt");
}

//arreglar
bool ProyectMethods::Exist_Airport(const char * name) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	if (!fileA) { return false ; }

	string line, tmp;

	while (fileA >> line) {
		stringstream st(line);
		
		getline(st, tmp, ';');

		if (tmp == name) { return true; }
	}
	return false;
}

int ProyectMethods::Create_Route(const char *id, const char *dest, double dist) {
	ofstream ArchivoRutas("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::app);

	if (!ArchivoRutas) { return 0; }

	if (Exist_Airport(id)) {

		ArchivoRutas << id << ";" << dest << ";" << dist << "\n";
		ArchivoRutas.close();

		return 1;
	}
	else
	{
		return 0;
	}
}

void ProyectMethods::Read_Route( char *id, int pos) {
	ifstream ArchivoRutas("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	if (!ArchivoRutas) { return; }

	string buffer;
	int i = 0;


	while (getline(ArchivoRutas, buffer))
	{
		i++;
		if (i == pos) { break; }
	}


	strcpy_s(id, sizeof buffer, buffer.c_str());

	ArchivoRutas.close();

}

void ProyectMethods::Update_Route(const char *id,const char *Rou, const char *newR, double dis) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt");


	string buffer;
	string nameA;
	string nameB;
	size_t n=0;

	size_t f;

	char delimit = ';';

	if (!fileA) { return; }

	while (fileA>>buffer)
	{
		f = buffer.find(delimit);
		nameA = buffer.substr(0, f);

		int i = 0;
		stringstream ss(buffer);
		
		while (getline(ss,nameB,delimit)) {
			if (i <2) { break; }
			i++;
		}		

		if (nameA != id && nameB !=Rou)
		{
			fileB << buffer << "\n";
		}
		else {
			fileB << id << ";" << newR << ";" << dis << "\n";
		}
	}

	for (size_t i = 0; i < vertexes.size(); i++) {
		if (vertexes[i]->id == id) {
			for (size_t u = 0; u < vertexes[i]->edges.size(); u++) {
				if (vertexes[i]->edges[u]->destiny->id == Rou) {
					vertexes[i]->edges[u]->destiny->id = newR;
				}
			}
		}
	}

	fileA.close(); fileB.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
}

void ProyectMethods::Delete_Route(const char *id, const char *route) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	ofstream fileB("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt");

	string buffer;
	string nameA;
	string nameB;

	size_t n=0;
	size_t f;

	string delimit = ";";
	if (!fileA) { return; }

	while (getline(fileA, buffer))
	{
		f = buffer.find(delimit);
		nameA = buffer.substr(n, f);

		n = f + delimit.length();
		f = buffer.find(delimit, n);

		nameB = buffer.substr(n, f);

		if (nameA != id && nameB!=route)
		{
			fileB << buffer << "\n";
		}
	}

	for (size_t i = 0; i < vertexes.size(); i++) {
		if (vertexes[i]->id == id) {
			for (size_t u = 0; u < vertexes[i]->edges.size(); u++) {
				if (vertexes[i]->edges[u]->destiny->id == route) {
					vertexes[i]->edges.erase(vertexes[i]->edges.begin() + u);
				}
			}
		}
	}

	fileA.close(); fileB.close();

	remove("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
	rename("C:\\Users\\Usuario\\Desktop\\mapas\\RutasTMP.txt", "C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");
}

int ProyectMethods::Lenght_R() {
	ifstream ArchivoR("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);
	if (!ArchivoR) { return NULL; }
	int i = 0;
	string line;
	while (getline(ArchivoR, line)) {
		i++;
	}
	ArchivoR.close();
	return i;
}

int ProyectMethods::cantRutas(const char * origen, const char * destino) {
	return cantR(origen, destino, 0);
}

int ProyectMethods::cantR(const char * origen, const char * destino, int cant) {
	ifstream file("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt", ios::in);

	string buffer;
	string subs;
	string subD;
	const char * ori= "";
	const char * destin="";
	size_t n;

	if (!file) {
		return 0;
	}
	else {
		while (getline(file, buffer)) {
			n = buffer.find(";");
			subs = buffer.substr(0, n);

			if (subs == origen) {
				ori = origen;
			}

			subD = buffer.substr(n + 1);
			if (subD == destino) {
				destin = destino;
			}
		}

		if (ori == origen && destin == destino) {
			return cant;
			file.close();
		}
		else {
			cant = cant + 1;
			cantR(destin, destino, cant);
		}
		return cant;
	}
}

double ProyectMethods::getLat(const char * id) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);

	string latS;
	double lat;

	string buffer;
	string nameA;
	size_t n;
	size_t z;

	if (!fileA) {
		return 0; 
	}

	while (getline(fileA, buffer))
	{
		n = buffer.find(";");
		z = buffer.find(";", n + 1);
		nameA = buffer.substr(0, n);

		if (nameA == id)
		{
			latS = buffer.substr(n + 1, z);
			lat = stod(latS);
		}
	}
	return lat;
}

double ProyectMethods::getLng(const char * id) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);

	string lngS;
	double lng;

	string buffer;
	string nameA;
	size_t n;
	size_t z;

	if (!fileA) { 
		return 0; 
	}

	else {
		while (getline(fileA, buffer))
		{
			n = buffer.find(";");
			z = buffer.find(";", n + 1);
			nameA = buffer.substr(0, n);

			if (nameA == id)
			{
				lngS = buffer.substr(z+1);
				lng = stod(lngS);
			}
		}
	}
	return lng;
}

void ProyectMethods::dijkstra(const char * id) {
	ifstream fileA("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	if (!fileA) { 
		return; 
	}

	string line, tmp;

	while (fileA >> line) {
		stringstream st(line);

		getline(st, tmp, ';');

		if (tmp == id) { 
			for (size_t i = 0; i < vertexes.size(); i++) {
				if (vertexes[i]->id == id) {
					dijk(vertexes[i]);
				}
			}
		}
	}
}

void ProyectMethods::dijk(Vertex * origen) {
	double * dist = new double[vertexes.size()];
	Vertex ** parent = reinterpret_cast<Vertex**>(new Vertex[cantV]);
	bool * visit = new bool[vertexes.size()];

	for (int i = 0; i < cantV; i++) {
		dist[i] = INT_MAX;
		parent[i] = NULL;
		visit[i] = false;
	}

	dist[origen->num] = 0;
	queue<Edge*>priorityQ = sortedEdges(origen);

	while (!priorityQ.empty()) {
		Vertex * n = priorityQ.front()->destiny;
		double d = priorityQ.front()->dist;
		priorityQ.pop();
		visit[n->num] = true;
		dist[n->num] = d;

		vector<Vertex *>nAdj = n->getAdj();

		for (size_t i = 0; i < nAdj.size(); i++) {
			double w = dist[n->num] + weight(n, nAdj[i]);
			if (w < dist[nAdj[i]->num]) {
				dist[nAdj[i]->num] = w;
				parent[nAdj[i]->num] = n;
			}
		}
	}

	for (size_t i = 0; i < vertexes.size(); i++) {
		Edge * e = new Edge(dist[i]);
		e->origin = origen;
		e->destiny = vertexes[i];
	}
}

queue<Edge *> ProyectMethods::sortedEdges(Vertex *vertex) {
	vector<Edge *> edges = vertex->edges;
	Edge *temp = NULL;
	for (size_t i = 0; i < edges.size(); i++) {
		for (size_t j = 1; j < (edges.size() - i); j++) {
			if (edges[j - 1]->dist > edges[j - 1]->dist) {
				temp = edges[j - 1];
				edges[j - 1] = edges[j];
				edges[j] = temp;
			}
		}
	}
	queue<Edge *> priorityQueue;
	for (size_t i = 0; i < edges.size(); i++) {
		priorityQueue.push(edges[i]);
	}
	return priorityQueue;
}

double ProyectMethods::weight(Vertex *origin, Vertex *destiny) {
	double z;
	for (size_t i = 0; i < origin->edges.size(); i++) {
		if (origin->edges[i]->destiny == destiny) {
			z = origin->edges[i]->dist;
		}
	}
	return z;
}

void ProyectMethods::createRutasID(const char * origen, const char * destino) {
	ofstream fileO("C:\\Users\\Usuario\\Desktop\\mapas\\RutasID.txt", ios::app);
	ifstream fileI("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);

	string buffer;
	string write;
	string nameO;
	string nameD;
	size_t n;
	size_t z;

	if (!fileO) { return; }
	if ((Exist_Airport(origen) == true) && (Exist_Airport(destino)==true)) {

		while (getline(fileI, buffer)){
			n = buffer.find(";");
			write = buffer.substr(0, n);
			if (write == origen) {
				nameO = write;
			}
			else if (write == destino) {
				nameD = write;
			}
		}
		fileO << nameO << ";" << nameD << "\n";
	}
	fileO.close();
	fileI.close();
}

void ProyectMethods::crearVertices() {
	ifstream fileI("C:\\Users\\Usuario\\Desktop\\mapas\\Aeropuertos.txt", ios::in);
	
	string buffer;
	string nameV;
	const char * name = "";
	size_t n;

	if (!fileI) {
		return;
	}

	while (getline(fileI, buffer)) {
		n = buffer.find(";");
		nameV = buffer.substr(0, n);
		Vertex * v = new Vertex(nameV, cantV);
		cantV++;
		vertexes.push_back(v);
	}

}

void ProyectMethods::crearAristas() {
	ifstream fileI("C:\\Users\\Usuario\\Desktop\\mapas\\Rutas.txt");

	string buffer;
	string distS;
	double dist;
	string id;
	string dest;
	size_t n;
	size_t z;
	size_t y;

	if (!fileI) {
		return;
	}

	while (getline(fileI, buffer)) {
		n = buffer.find(";");
		z = buffer.find(";", n + 1);
		id = buffer.substr(0, n);
		dest = buffer.substr(n, z + 1);
		distS = buffer.substr(z+1);

		dist = stod(distS);

		Edge * n = new Edge(dist);
		for (size_t i = 0; i < vertexes.size(); i++) {
			if (vertexes[i]->id == id) {
				vertexes[i]->edges.push_back(n);
				n->origin = vertexes[i];
			}
			if (vertexes[i]->id == dest) {
				n->destiny = vertexes[i];
			}
		}
	}

	
}

void ProyectMethods::borrarVertice() {
	for (size_t i = 0; i < vertexes.size(); i++) {
		for (size_t u = 0; u < vertexes[i]->edges.size(); u++) {
			if (vertexes[i]->edges[u]->destiny->id == nom) {
				vertexes[i]->edges.erase(vertexes[i]->edges.begin() + u);
			}
		}
	}

	for (size_t z = 0; z < vertexes.size(); z++) {
		if (vertexes[z]->id == nom) {
			vertexes.erase(vertexes.begin() + z);
		}
	}
}

//int  ProyectMethods::Display_Airports() {
//
//}
//
//int  ProyectMethods::Update_Airport() {
//
//}
//
//int  ProyectMethods::Delete_Airport() {
//
//}