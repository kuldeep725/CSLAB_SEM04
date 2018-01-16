/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include "LinkedList.h"
#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph {

	int V;
	List *adj;
	// List* adj[50];
	int E;
	int *size;

} Graph;

/*
	to create an empty graph and return it
*/
void getGraph(Graph *, int );

/*
	to add a directed edge from first vertex to second
*/
void addEdge(Graph *, int , int );

/*
	to find degree of the given vertex
*/
int degree(Graph *, int );

/*
	to find maximum degree in the graph and
	return maximum degree
*/
int maxDegree(Graph *);

/*
	to return number of vertices in graph
*/
int V(Graph *);
/*
	to return number of edges in graph
*/
int E(Graph *);

/*
	to return the adjacency list of given vertex
*/
List getAdjacencyList(Graph *, int );

#endif