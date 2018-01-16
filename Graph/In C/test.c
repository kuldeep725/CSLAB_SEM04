#include<stdio.h>
#include"Graph.h"

int main() {

	FILE *fin = fopen("input.txt", "r");
	int n;
	int i;
	fscanf(fin, "%d", &n);
	Graph graph;
	getGraph(&graph, n);
	for(i = 0; i < n; i++) {
		int j;
		while(true) {
			int w;
			fscanf(fin, "%d", &w);
			if(w == -1) break;
			addEdge(&graph, i, w);
		}
	}
	for(i = 0; i < n; i++) {
		printf("degree[%d] = %d\n", i, degree(&graph, i));
	}
	printf("maxDegree = %d\n", maxDegree(&graph));
	printf("V() = %d\n", V(&graph));
	printf("E() = %d\n", E(&graph));
	fclose(fin);
	return 0;
}