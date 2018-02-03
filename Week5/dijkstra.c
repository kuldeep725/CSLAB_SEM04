#include<stdio.h>
#include<limits.h>
#include"heap.h"
#include"Graph.h"

#define INF INT_MAX

void printAll(Heap *, VertexNode *, Graph *,int[], int);
void showDijkstraTree(VertexNode *, Graph *);
void dijkstra(Graph *, int);

int main() {

	int V;			//number of vertices in the graph
	int E;			//number of edges in the graph
	int u, v, weight;		//to take input vertices and weight
	int s; 			//source vertex
	scanf("%d%d",&V, &E);
	// printf("V = %d, E = %d\n", V, E);
	Graph graph;
	getGraph(&graph, V);
	int i;

	for(i = 0; i < E; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&graph, u, v, weight);
	}

	scanf("%d", &s);
	dijkstra(&graph, s);
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

void printAll(Heap *heap, VertexNode *q, Graph *g, int parent[], int s) {

	printf("%-9s%-11s%-12s","Vertex", "Distance", "Path");
	int i;

    for (i = 0; i < V(g); i++) {
        printf("\n %d->%d     %-10d %d ",s, i, q[getPosition(heap, i)].dist, s);
        printShortestPath(parent, i);
    }

}

void dijkstra(Graph *g, int s) {

	// printf("dijkstra started...\n");
	VertexNode *q = (VertexNode*) malloc(sizeof(VertexNode)*V(g));
	int i;
	int parent[V(g)];
	Heap heap;
	createHeap(&heap, V(g));

	for(i = 0; i < V(g); i++) {
		q[i].v = i;
		q[i].dist = INF;		//	INF is a macro for INT_MAX
		heap.pos[i] = i;
		// printf("q[%d] = %d\n", i, q[i].dist);
	}
	// insert(&q, s, 0);
	buildHeap(&heap, &q, V(g));
	decreaseKey(&heap, &q, s, 0);
	parent[s] = -1;

	while(!isHeapEmpty(&heap)) {

		VertexNode minNode = deleteMin(&heap, &q);
		// printAll(&heap, q, g, s);
		List list = getAdjacencyList(g, minNode.v);
		// printf("minNode.v = %d\n", minNode.v);
		// printf("minNode.dist = %d\n", minNode.dist);
		// printf("q[minNode.v].dist = %d\n", q[minNode.v].dist);

		while(!isEmpty(&list)) {

			Vertex vertex = popFront(&list);
			// printf("vertex.data = %d\n", vertex.data);
			// printf("vertex.weight = %d\n", vertex.weight);
			// printf("q[vertex.data].dist = %d\n", q[vertex.data].dist);
			int position = getPosition(&heap, vertex.data);

			if(q[position].dist > minNode.dist + vertex.weight){
				// printf("in\n");
				q[position].dist = minNode.dist + vertex.weight;
				decreaseKey(&heap, &q, position, q[position].dist);
				parent[vertex.data] = minNode.v;
			}

		}

	}
	printAll(&heap, q, g, parent, s);
	printf("\n");

}