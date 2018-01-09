#include<iostream>
#include"Graph.h"

int main() {

	FILE *fin = fopen("input.txt", "r");
	int n;
	int i;
	fscanf(fin, "%d", &n);
	Graph graph(n);
	for(i = 0; i < n; i++) {
		int j;
		while(true) {
			int w;
			fscanf(fin, "%d", &w);
			if(w == -1) break;
			graph.addEdge(i, w);
		}
	}
	for(i = 0; i < n; i++) {
		printf("degree[%d] = %d\n", i, graph.degree(i));
	}
	printf("maxDegree = %d\n", graph.maxDegree());
	printf("getV() = %d\n", graph.getV());
	printf("getE() = %d\n", graph.getE());
	fclose(fin);
	return 0;
}