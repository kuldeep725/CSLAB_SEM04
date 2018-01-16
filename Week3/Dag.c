#include<stdio.h>

int main() {

	int w, n, i, flag = 0;
	scanf("%d", &n);
	Graph graph;
	getGraph(&graph, n);		//for getting graph with n vertices
	for(i = 0; i < n; i++) {
		while(true) {
			int w;
			scanf("%d", &w);
			if(w == -1) break;
			addEdge(&graph, i, w);			//making an edge from i to w
		}
	}
	Path path;
	printf("DFS path is : \n");
	findPath(&path, &graph, 0);
	for(u = 0; u < V(graph); u++) {
		List *list = getAdjacencyList(graph, u);		//getting adjacency list for 
														//vertex 'u'
		Node *p = getFront(list);						//getting front pointer of list
		while(p != NULL) {
			int v = getData(p);
			if(pre[v] < pre[u] && post[u] < post[v]) {		//condition for back edge
				printf("%d-%d  	: %s\n", u, v, "Back Edge");
				flag = 1;
				break;
			}
			p = next(p);
		}
		if(flag == 1) break;
	}
	if(flag != 1) {
		
	}
	else {
		printf("The graph is cyclic.\n");
	}
	return 0;
}