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

void findPaths(Path *path, Graph *g, int v) {

	/***********
		allocating memory to structure elements
	***********/
	// Path *path = (Path *) malloc(sizeof(Path));
	path->visited = (int *) malloc(sizeof(int) * V(g));
	path->parent = (int *) malloc(sizeof(int) * V(g));
	path->pre = (int *) malloc(sizeof(int) * V(g));
	path->post = (int *) malloc(sizeof(int) * V(g));
	path->s = v;
	int i;
	for(i = 0; i < V(g); i++) {
		path->visited[i] = 0;
		path->parent[i] = -1;
	}
	/******calling dfs to print the dfs path for source vertex v*******/
	dfs(path, g, path->s);
	for(i = 0; i < V(g); i++) {
		if(!path->visited[i])	dfs(path,g,i);
	}
	// return path;		//returning path pointer of structure Path

}

void dfs(Path *path, Graph *g, int v) {

	path->visited[v] = 1;		//marking vertex 'v' visited
	int i;
	List *list = getAdjacencyList(g, v);
	path->pre[v] = count++;					// pre array "start time of vertex 'v'"
	Node *p = getFront(list);
	printf("%d ", v);
	while(p != NULL) {
		// printf("data = %d\n", getData(p));
		int current = getData(p);
		if(!path->visited[current]) {
			path->visited[current] = 1;
			path->parent[current] = v;		//making 'v' to be parent of 'current'
			dfs(path, g, current);			//calling dfs for current vertex
		}
		p = next(p);
	}
	path->post[v] = count++;				// post array "end time of vertex 'v'"

}

int * getPre(Path *p) {
	if(p == NULL) return NULL;
	return p->pre;
}

int * getPost(Path *p) {
	if(p == NULL) return NULL;
	return p->post;
}

int getParent(Path *p, int v) {
	if(p == NULL) return INT_MIN;
	return p->parent[v];
}

void freePath(Path *p) {

	free(p->visited);
	free(p->parent);
	free(p->pre);
	free(p->post);
	free(p);

}