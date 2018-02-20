#include<stdio.h>
#include"heap.h"
#include"Graph.h"

#define INF INT_MAX

void printMST(Heap *, VertexCost *, Graph *, int[]);
void prim(Graph *);

int main() {

	int n;					//number of vertices
	int m;					//number of edges
	scanf("%d%d", &n, &m);

	int u,v, weight;				
	Graph g;			//defining graph
	getGraph(&g, n);	//initializing graph
	int i;					//loop counter

	for(i = 0; i < m; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&g, u, v, weight);			//adding edge from u to v and v to u with weight 'weight'
	}

	prim(&g);
	return 0;
}

void printMST(Heap *heap, VertexCost *vc, Graph *g, int parent[]) {

	int i;

	printf("=========================MST=========================\n");
	printf("Edge\n");
	for(i = 0; i < V(g); i++) {
		if(parent[i] != -1) {
	      	printf("%d - %d\n", parent[i], i);
	    }
	}

}

void prim(Graph *g) {

	VertexCost *vc = (VertexCost *) malloc(sizeof(VertexCost)*V(g));
	int i;
	int parent[V(g)];
	Heap heap;
	createHeap(&heap, V(g));

	for(i = 0; i < V(g); i++) {
		vc[i].v = i;
		vc[i].cost = INF;
		heap.pos[i] = i;
		parent[i] = -1;
	}

	int s = 0;								//source vertex

	buildHeap(&heap, &vc, V(g));
	vc[s].cost = 0;
	decreaseKey(&heap, &vc, s, 0);			//decrease key of source vertex by setting it 0

	while(!isHeapEmpty(&heap)) {

		VertexCost minCost = deleteMin(&heap, &vc);
		List list = getAdjacencyList(g, minCost.v);

		while(!isEmpty(&list)) {

			Vertex vertex = popFront(&list);
			int pos = getPosition(&heap, vertex.data);
			int size = heapSize();

			if(pos <= size && vc[pos].cost > vertex.weight) {
				parent[vertex.data] = minCost.v;
				decreaseKey(&heap, &vc, pos, vertex.weight);
			}

		}

	}
	printMST(&heap, vc, g, parent);

}