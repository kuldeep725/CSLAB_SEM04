/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include"Graph.h"
#include"DepthFirstPaths.h"

static int count = 1;

void depthFirstSearch(Vertex *vertex, Graph *g, int v) {

	/***********
		allocating memory to structure elements
	***********/
	vertex->visited = (int *) malloc(sizeof(int) * V(g));
	vertex->parent = (int *) malloc(sizeof(int) * V(g));
	vertex->pre = (int *) malloc(sizeof(int) * V(g));
	vertex->post = (int *) malloc(sizeof(int) * V(g));
	vertex->s = v;
	int i;
	for(i = 0; i < V(g); i++) {
		vertex->visited[i] = 0;
		vertex->parent[i] = -1;
	}
	/******calling dfs to print the dfs Vertex starting from source vertex s*******/
	for(i = 0; i < V(g); i++) {
		if(!vertex->visited[i])	dfs(vertex,g,i);
	}

}

void topologicalSort(Vertex *vertex, Graph *g, List *reversePost) {

	int i;
	for(i = 0; i < V(g); i++) {
		if(!vertex->visited[i])	dfsReversePost(vertex, g, reversePost,i);
	}
}

void dfsReversePost(Vertex *vertex, Graph *g, List *reversePost, int v) {

	vertex->visited[v] = 1;		//marking vertex 'v' visited
	List list = getAdjacencyList(g, v);
	Node *p = getFront(&list);

	while(p != NULL) {
		int current = getData(p);
		if(!vertex->visited[current]) {
			vertex->parent[current] = v;		//making 'v' to be parent of 'current'
			dfsReversePost(vertex, g, reversePost, current);			//calling dfs for current vertex
		}
		p = next(p);
	}
	// printf("%d ", v);
	push(reversePost, v);

}


void dfs(Vertex *vertex, Graph *g, int v) {

	vertex->visited[v] = 1;		//marking vertex 'v' visited
	int i;
	List list = getAdjacencyList(g, v);
	vertex->pre[v] = count++;					// pre array "start time of vertex 'v'"
	Node *p = getFront(&list);
	// printf("%d ", v);
	while(p != NULL) {
		// printf("data = %d\n", getData(p));
		int current = getData(p);
		if(!vertex->visited[current]) {
			vertex->parent[current] = v;		//making 'v' to be parent of 'current'
			dfs(vertex, g, current);			//calling dfs for current vertex
		}
		p = next(p);
	}
	vertex->post[v] = count++;				// post array "end time of vertex 'v'"

}

void makeAllUnvisited(Vertex *vertex, Graph *g) {

	int i;
	for(i = 0; i < V(g); i++) {
		vertex->visited[i] = 0;
	}

}

void displayDirectedCycle(Vertex *vertex, Graph *graph, int cycleVertex) {

	int u;
	List cycleList;
	getList(&cycleList);

	int ele;
	for(u = cycleVertex; u != -1; u = vertex->parent[u]) {
		ele = u;
		push(&cycleList, u);
	}
	printf("START-->");
	while(!isEmpty(&cycleList)) {
		printf("%d-->", pop(&cycleList));
	}
	printf("%d-->", ele);
	printf("END\n");

}

int * getPre(Vertex *vertex) {
	if(vertex == NULL) return NULL;
	return vertex->pre;
}

int * getPost(Vertex *vertex) {
	if(vertex == NULL) return NULL;
	return vertex->post;
}

int getParent(Vertex *vertex, int v) {
	if(vertex == NULL) return INT_MIN;
	return vertex->parent[v];
}

void freeVertex(Vertex *vertex) {

	free(vertex->visited);
	free(vertex->parent);
	free(vertex->pre);
	free(vertex->post);
	// free(p);

}