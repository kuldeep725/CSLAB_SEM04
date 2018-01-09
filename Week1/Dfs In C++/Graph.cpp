/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<iostream>
#include "Graph.h"

Graph::Graph(int v) {

	V = v;
	E = 0;
	size = new int[V];
	adj = new LinkedList[V];

}

Graph::~Graph() {

	// delete[] size;
	// delete[] adj;

}

void Graph::addEdge(int v, int w) {

	adj[v].push(w);
	size[v]++;
	E++;

}

int Graph::degree(int v) {
	return size[v];
}

int Graph::maxDegree() {

	int max = 0;
	for(int i = 0; i < getV(); i++) {
		if(degree(i) > max)	
			max = degree(i);
	}
	return max;
}

int Graph::getV() {
	return V;
}

int Graph::getE() {
	return E;
}

//return adjacency list for the vertex 'v' in parameter
LinkedList Graph::getAdjacencyList(int v) {
	return adj[v];
}
