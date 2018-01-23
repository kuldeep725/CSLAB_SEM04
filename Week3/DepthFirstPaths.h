/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include"Graph.h"
#ifndef DEPTHFIRSTPATHS_H
#define DEPTHFIRSTPATHS_H

typedef struct Vertex  {

	int *visited;
	int *parent;
	int s;
	int *pre;
	int *post;

} Vertex ;

/*
	to travel all the vertices of a graph using dfs
*/
void depthFirstSearch(Vertex *, Graph *, int );

/*
	to perform topological sorting of the given graph
*/
void topologicalSort(Vertex *, Graph *, List *);

/*
	to find dfs and create a stack of vertices in order of
	their post timing
*/
void dfsReversePost(Vertex *, Graph *, List *, int );

/*
	to make all the vertices of the graph unvisited
*/
void makeAllUnvisited(Vertex *, Graph *);

/*
	display the vertices of a cycle in the directed graph
*/
void displayDirectedCycle(Vertex *, Graph *, int);

/*
	to find depth first search path
*/
void dfs(Vertex *, Graph *, int );

/*
	to return pre array 
*/
int * getPre(Vertex *);
/*
	to return post array
*/
int * getPost(Vertex *);

/*
	to return parent of the Vertex  v
*/
int getParent(Vertex *p, int v);

/*
	to free the memory
*/
void freeVertex(Vertex *p);
#endif