/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include"Graph.h"
#ifndef DEPTHFIRSTPATHS_H
#define DEPTHFIRSTPATHS_H

typedef struct Path {

	int *visited;
	int *parent;
	int s;
	int *pre;
	int *post;

} Path;

/*
	to find the paths of the given vertex
	from all the vertices in graph and return 
	pointer Path *
*/
Path * findPaths(Graph *, int );

/*
	to find depth first search path
*/
void dfs(Path *, Graph *, int );

/*
	to return pre array 
*/
int * getPre(Path *);
/*
	to return post array
*/
int * getPost(Path *);

/*
	to return parent of the vertex v
*/
int getParent(Path *p, int v);

void freePath(Path *p);
#endif