/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include "LinkedList.h"
#ifndef GRAPH_H
#define GRAPH_H

class Graph {

	int V;
	LinkedList *adj;
	int E;
	int *size;

	public :

		/*
			constructor to create an empty graph
		*/
		Graph(int);

		/*
			destructor to free all memory taken in class graph
		*/
		~Graph();
		/*
			to add a directed edge from first vertex to second
		*/
		void addEdge(int , int );

		/*
			to find degree of the given vertex
		*/
		int degree(int );

		/*
			to find maximum degree in the graph and
			return maximum degree
		*/
		int maxDegree();

		/*
			to return number of vertices in graph
		*/
		int getV();
		/*
			to return number of edges in graph
		*/
		int getE();

		/*
			to return the adjacency list of given vertex
		*/
		LinkedList getAdjacencyList(int );


	};

#endif