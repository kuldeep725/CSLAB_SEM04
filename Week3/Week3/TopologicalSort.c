/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: To sort a given graph in topological order if dag exists
				  otherwise print the cycle
*/
#include<stdio.h>
#include"DepthFirstPaths.h"

int main() {

	int w, n, i, flag = 0;
	scanf("%d", &n);
	Graph graph;
	List reversePost;
	getList(&reversePost);
	getGraph(&graph, n);		//for getting graph with n vertices
	printf("====================================================\n");
	for(i = 0; i < n; i++) {
		while(true) {
			int w;
			scanf("%d", &w);
			if(w == -1) break;
			addEdge(&graph, i, w);			//making an edge from i to w
		}
	}
	Vertex vertex;

	depthFirstSearch(&vertex, &graph, 0);
	/* 
		getting an array containing pre (starting time)
		values of each vertex
	*/
	int *pre = getPre(&vertex);	
	/* 
		getting an array containing post (finishing time)
		values of each vertex
	*/			
	int *post = getPost(&vertex);
	int u;
	int beginVertex;		//begin vertex of the cycle if it exists
	int endVertex;			//end vertex of the cycle if it exists
	for(u = 0; u < V(&graph); u++) {
		List list = getAdjacencyList(&graph, u);		//getting adjacency list for 
														//vertex 'u'
		Node *p = getFront(&list);						//getting front pointer of list
		while(p != NULL) {
			int v = getData(p);
			if(pre[v] < pre[u] && post[u] < post[v]) {		//condition for back edge
				printf("%d-%d  	: %s\n", u, v, "Back Edge");
				flag = 1;
				beginVertex = v;
				endVertex = u;
				break;
			}
			p = next(p);
		}
		if(flag == 1) break;
	}
	if(flag != 1) {
		printf("The graph is a DAG.\n");
		printf("The graph doesn't contain any cycles.\n");
		/****************
			making all vertices unvisited
		****************/
		makeAllUnvisited(&vertex, &graph);		
		/****************
			sorting the graph in topological ordering
		****************/
		topologicalSort(&vertex, &graph, &reversePost);
		printf("================Topological Sort====================\n");
		printf("START-->");
		while(!isEmpty(&reversePost)){
			printf("%d-->", pop(&reversePost));
		}
		printf("END\n");
		// printf("\n");
		
	}
	else {
		printf("beginVertex = %d\n", beginVertex);
		printf("endVertex = %d\n", endVertex);
		printf("The graph is not a DAG.\n");
		printf("The graph contains at least one cycle.\n");
		printf("===================CYCLE============================\n");
		/******************
			printing one of the cycle present in the graph
		******************/
		displayDirectedCycle(&vertex, &graph, beginVertex, endVertex);
	}
	printf("====================================================\n");
	freeVertex(&vertex);
	freeGraph(&graph);
	return 0;
}