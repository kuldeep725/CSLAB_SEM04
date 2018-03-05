/*

    * Name      		: Kuldeep Singh Bhandari
    * Roll No.  		: 111601009
	* Aim 				: To implement bellman-ford algorithm to find shortest distances
				  		  of all vertices from source vertex
	* Time Complexity 	: O(m*n), where m = number of edges and n = number of vertices
*/
#include<stdio.h>
#include<limits.h>
#include"Graph.h"

#define INF INT_MAX

int relax (int , Vertex , int []);
void printShortestPath(int[], int);
void bellmanFord(Graph *, int);

int main () {

	int V;			//number of vertices in the graph
	int E;			//number of edges in the graph
	int u, v, weight;		//to take input vertices and weight
	int s; 			//source vertex
	scanf("%d%d",&V, &E);
	
	Graph graph;
	getGraph(&graph, V);
	int i;

	for(i = 0; i < E; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&graph, u, v, weight);
	}

	scanf("%d", &s);
	bellmanFord(&graph, s);
	return 0;

}

int relax (int u, Vertex vertex, int dist[]) {

	int v = vertex.data;
	int w = vertex.weight;

	if(dist[u] == INT_MAX)	return 0;
	
	if(dist[v] > dist[u]+w) {
		dist[v] = dist[u]+w;
		return 1;
	}
	return 0;
}

/*********************
	function to print shortest path from source to j
	using parent array
*********************/
void printShortestPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;
    
    printShortestPath(parent, parent[j]);
 
    printf("%d ", j);
}

void printCycle(int parent[], int j, int negCycle) {

	if(j == negCycle)	return;

	printCycle(parent, parent[j], negCycle);
 
    printf("%d ", j);

}

void printNegativeCycle(int parent[], int negCycle) {

	printf("Cycle --> %d ", negCycle);
	printCycle(parent, parent[negCycle], negCycle);
	printf("%d ", negCycle);
}

void bellmanFord(Graph *g, int s) {

	int dist[V(g)];			//distance of all vertices from source s
	int parent[V(g)];
	int i, j;

	for(i = 0; i < V(g); i++) {
		dist[i] = INF;			//set distance of all vertices infinity from source s
		parent[i] = -1;
	}
	dist[s] = 0;			//distance of source from itself is 0
	int negCycle;
	int flag2 = 0;

	for(j = 0; j <= V(g); j++) {

		int flag = 0;
		for(i = 0; i < V(g); i++) {

			List list = getAdjacencyList(g, i);

			Node *p = getFront(&list);
			//traverse through all the neighbours of vertex i
			while(p != NULL) {

				Vertex vertex = getData(p);
				// printf("%d, %d, %d\n", i, vertex.data, vertex.weight);
				int check = relax(i, vertex, dist);
				// printf("check = %d\n", check);
				if(check == 1) {
					flag = 1;
					parent[vertex.data] = i;
					if(flag2 == 0 && j == V(g)) {
						negCycle = vertex.data;
						flag2 = 1;
					}
					
				}
				p = next(p);

			}

		}
		if(j == V(g) && flag) {
			printf("\n==============================================\n");
			printf("Negative Cycle exists.\n");
			printf("One such cycle is :\n");
			printNegativeCycle(parent, negCycle);
			printf("\n==============================================\n");
			return;
		}
		if(!flag) {
			break;
		}

	}

	printf("\n===========SHORTEST PATHS=====================\n");
	printf("%-10s%-12s%-12s","Vertex", "Distance", "Path");

	for (i = 0; i < V(g); i++) {

		if(dist[i] == INT_MAX)	{
			printf("\n %d->%d     %-10d  %s ",s, i, dist[i], "Unreachable");
		}
		else {

	        printf("\n %d->%d     %-10d  %d ",s, i, dist[i], s);
	        printShortestPath(parent, i);

		}
    }
	printf("\n==============================================\n");
	
}