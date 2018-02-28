/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	
*/

#include<stdio.h>
#include<limits.h>
#include"heap.h"
#include"Graph.h"

#define INF INT_MAX

void dijkstra(Graph *g, int k);

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
	dijkstra(&graph, k);
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

void dijkstra(Graph *g, int k) {

	// printf("dijkstra started...\n");
	int round = 1;
	while(k--) {

		printf("====================Round %d======================\n", round++);
		VertexNode *q = (VertexNode*) malloc(sizeof(VertexNode)*V(g));
		int repair[100][100] = {0};			//setting all elements to be 0 in 100*100 matrix
		
		int l;
		scanf("%d", &l);
		int i;
		int x;
		int y;
		for(i = 0; i < l; i++) {
			scanf("%d%d",&x,&y);
			repair[x][y] = 1;
		}
		int s;			//source
		int dest;		//destination
		scanf("%d%d",&s,&dest);
		int parent[V(g)];
		Heap heap;
		createHeap(&heap, V(g));

		for(i = 0; i < V(g); i++) {
			q[i].v = i;
			q[i].dist = INF;		//	INF is a macro for INT_MAX
			heap.pos[i] = i;
			parent[s] = -1;
		}
		
		buildHeap(&heap, &q, V(g));
		decreaseKey(&heap, &q, s, 0);
		int minDistance = 0;

		while(!isHeapEmpty(&heap)) {

			VertexNode minNode = deleteMin(&heap, &q);
			
			List list = getAdjacencyList(g, minNode.v);
			
			Node *p = getFront(&list);
			while(p != NULL) {
				// printf("data = %d\n", getData(p));
				Vertex vertex = getData(p);

				if(repair[minNode.v][vertex.data] == 1) {
					p = next(p);
					continue;
				}
				int position = getPosition(&heap, vertex.data);

				if(q[position].dist > minNode.dist + vertex.weight)
					parent[vertex.data] = minNode.v;
				
				decreaseKey(&heap, &q, position, minNode.dist+vertex.weight);
				p = next(p);
			}
			if(minNode.v == dest) {
				minDistance = minNode.dist;
				break;
			}
		}

		printf("Minimum distance = %d\n", minDistance);
		int index = getPosition(&heap, dest);
        printf("Path : %d ", s);
        printShortestPath(parent, dest);

		printf("\n");
	}
	
} 