/*************

*************/
#include<stdio.h>
#include"heap.h"
#include"Graph.h"

void makeSet(Graph *, int[], int[]);
void kruskal(Graph *, Edge **);
int find(int u, int[]);
void Union(int, int, int[], int[]);

int main() {

	int n;					//number of vertices
	int m;					//number of edges
	scanf("%d%d", &n, &m);

	int u,v, weight;				
	Graph g;			//defining graph
	getGraph(&g, n);	//initializing graph
	int i;					//loop counter

	Edge *edge = (Edge *) malloc(sizeof(Edge)*m);

	for(i = 0; i < m; i++) {	
		scanf("%d%d%d", &u, &v, &weight);
		addEdge(&g, u, v, weight);			//adding edge from u to v and v to u with weight 'weight'
		edge[i].u = u;
		edge[i].v = v;
		edge[i].weight = weight;
	}

	kruskal(&g, &edge);
	free(edge);
	return 0;
}

void kruskal(Graph *g, Edge **e) {

	int i;
	int rank[V(g)];
	int parent[V(g)];

	Heap heap;
	createHeap(&heap, V(g));

	makeSet(g, parent, rank);

	buildHeap(&heap, e, E(g));
	int count = 0;
	int totalWeight = 0;
	printf("=========================MST=========================\n");
	printf("Edge\n");

	while(!isHeapEmpty(&heap) && count < V(g)-1) {

		Edge edge = deleteMin(&heap, e);
		int u = edge.u;
		int v = edge.v;

		if(find(u, parent) != find(v, parent)) {
			Union(u, v, rank, parent);
			printf("%d-%d\n", u, v);
			totalWeight += edge.weight;
			count++;
		}

	}
	printf("Total Weight = %d\n", totalWeight);

}

void makeSet(Graph *g, int parent[], int rank[]) {

	int i;
	for(i = 0; i < V(g); i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int u, int parent[]) {

	if(parent[u] == u)	return u;

	int v = find(parent[u], parent);
	parent[u] = v;
	return v;

}

void Union(int u, int v, int rank[], int parent[]) {

	int x = find(u, parent);				//root of u
	int y = find(v, parent);				//root of v

	if(x == y)		return;
	if(rank[x] == rank[y]) {
		parent[y] = x;
		rank[x]++;
	}
	else if(rank[x] > rank[y]) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}

}