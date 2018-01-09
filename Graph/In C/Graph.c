/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include"Graph.h"

Graph * getGraph(Graph *graph, int v) {

	graph = (Graph *) malloc(sizeof(Graph));
	// graph->adj = getList(list);
	graph->V = v;
	graph->E = 0;
	// printf("1\n");
	graph->size = (int *) malloc(sizeof(int) * v);
	int i;
	// printf("2\n");
	graph->adj = (List **) malloc(sizeof(List *) * v);
	for(i = 0; i < v; i++) {
		graph->adj[i] = getList(graph->adj[i]);
		// printf("3\n");
		graph->size[i] = 0;
		// printf("4\n");
	}
	// printf("5\n");
	return graph;

}

void addEdge(Graph *graph, int v, int w) {

	if(graph == NULL)	return;
	// printf("%d %d\n", v,w);
	push(graph->adj[v], w);
	graph->size[v]++;
	graph->E++;
	// printf("%d\n", graph->size[v]);

}

int degree(Graph *graph, int v) {

	if(graph == NULL) 	return INT_MIN;
	return graph->size[v];

}

int maxDegree(Graph *graph) {

	int i;
	int max = INT_MIN;
	for (i = 0; i < graph->V; i++) {
		if(degree(graph, i) > max)
			max = degree(graph, i);
	}
	return max;

}

int V(Graph *graph) {
	return graph->V;
}

int E(Graph *graph) {
	return graph->E;
}

List * getAdjacencyList(Graph *graph, int v) {
	return graph->adj[v];
}