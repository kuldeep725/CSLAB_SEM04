/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include"Graph.h"

void getGraph(Graph *graph, int v) {

	graph->V = v;
	graph->E = 0;
	graph->size = (int *) malloc(sizeof(int) * v);
	int i;
	graph->adj = (List *) malloc(sizeof(List) * v);

}

void addEdge(Graph *graph, int v, int w, int weight) {

	if(graph == NULL)	return;
	// printf("%d %d\n", v,w);
	push(&(graph->adj[v]), w, weight);
	push(&(graph->adj[w]), v, weight);
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

List getAdjacencyList(Graph *graph, int v) {
	return graph->adj[v];
}