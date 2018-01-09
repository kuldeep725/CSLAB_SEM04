/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include"Graph.h"
#ifndef DEPTHFIRSTPATHS_H
#define DEPTHFIRSTPATHS_H

class Path {

	bool *visited;
	int *parent;
	int s;
	int *pre;
	int *post;

	public :
		/*
			constructor to find the paths of the given vertex
			from all the vertices in graph
		*/
		Path(Graph, int);

		/*
			destructor to free all memory in class Path
		*/
		~Path();

		/*
			to find depth first search path
		*/
		void dfs(Graph, int);

		/*
			to return pre array 
		*/
		int * getPre();
		/*
			to return post array
		*/
		int * getPost();

		/*
			to return parent of the vertex v
		*/
		int getParent(int v);

};
#endif