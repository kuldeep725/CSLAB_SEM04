#include<stdio.h>

int main() {

	int V;			//number of vertices in the graph
	int E;			//number of edges in the graph
	int u, v, weight;		//to take input vertices and weight
	Graph graph;
	getGraph(&graph, V);
	for(i = 0; i < E; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&graph, u, v, weight);
	}
	return 0;

}