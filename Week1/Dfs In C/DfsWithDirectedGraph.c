/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
	* Aim		: (1) Implement Depth First Search of directed graphs using adjacency lists.
				  (2) Output the dfs exploration start and finish times of each vertex
				  (3) Output the category of each edge
*/				  
#include<stdio.h>
#include "Graph.h"
#include "DepthFirstPaths.h"

int main(){

	char fileName[32];
	int source;
	int n;
	int i;

	printf("------------------------------------------------\n");
	printf("Enter fileName : ");
	scanf("%s", fileName);
	FILE *fin = fopen(fileName, "r");
	fscanf(fin, "%d", &n);
	Graph *graph = getGraph(graph, n);		//for getting graph with n vertices
	for(i = 0; i < n; i++) {
		while(true) {
			int w;
			fscanf(fin, "%d", &w);
			if(w == -1) break;
			addEdge(graph, i, w);			//making an edge from i to w
		}
	}
	fclose(fin);
	printf("Enter the source vertex in the graph : ");
	scanf("%d", &source);
	printf("Dfs path for source %d : \n", source);
	Path *path = findPaths(graph, source);			//finding all paths from source to 
													//other vertices
	printf("\n");
	/* 
		getting an array containing pre (starting time)
		values of each vertex
	*/
	int *pre = getPre(path);	
	/* 
		getting an array containing post (finishing time)
		values of each vertex
	*/			
	int *post = getPost(path);
	printf("------------------------------------------------\n");
	printf("Starting and finishing time for each vertices : \n");
	printf("Vertex : (PreVisit, PostVisit)\n");
	for(i = 0; i < V(graph); i++) {
		printf("%-6d : (%8d, ",i, pre[i]);
		printf("%9d)\n",post[i]);
		// printf("pre[%d] = %d, ",i,  pre[i]);
		// printf("post[%d] = %d\n",i, post[i]);
	}
	int u;
	printf("------------------------------------------------\n");
	printf("EDGE 	: EDGETYPE\n");
	for(u = 0; u < V(graph); u++) {
		List *list = getAdjacencyList(graph, u);		//getting adjacency list for 
														//vertex 'u'
		Node *p = getFront(list);						//getting front pointer of list
		while(p != NULL) {
			int v = getData(p);
			if(pre[u] < pre[v]&& post[v] < post[u]) {	//condition for tree/forward edge
				if(getParent(path, v) == u) {			//if u is parent of v
					printf("%d-%d  	: %s\n", u, v, "Tree Edge");
				}
				else {									//otherwise
					printf("%d-%d  	: %s\n", u, v, "Forward Edge");
				}
			}
			else if(pre[v] < pre[u] && post[u] < post[v]) {		//condition for back edge
				printf("%d-%d  	: %s\n", u, v, "Back Edge");
			}
			else if(post[v] < pre[u]) {					//condition for cross edge
				printf("%d-%d  	: %s\n", u, v, "Cross Edge");
			}
			p = next(p);
		}
	}
	printf("------------------------------------------------\n");
	freePath(path);
	freeGraph(graph);
	return 0;

}