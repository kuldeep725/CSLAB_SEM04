/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	
*/

#include<stdio.h>

int main () {

	int V;			//number of vertices in the graph
	int E;			//number of edges in the graph
	int u, v, weight;		//to take input vertices and weight
	int s; 			//source vertex
	int k;			//number of rounds
	scanf("%d%d",&V, &E);
	
	Graph graph;
	getGraph(&graph, V);
	int i;

	for(i = 0; i < E; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&graph, u, v, weight);

	}

	scanf("%d", &k);
	dijkstra(&graph, s);
	return 0;
}
