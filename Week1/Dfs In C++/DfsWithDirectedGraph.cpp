#include<iostream>
#include<string>
#include<fstream>
#include"DepthFirstPaths.h"

int main() {

	// char fileName[32];
	using namespace std;
	string fileName;
	int source;
	int n;

	cout<<"Enter fileName : ";
	// cin>>fileName;
	fileName = "input.txt";
	ifstream fin(fileName);
	if(!fin.is_open()) {
		cout<<"Error in file opening";
		return 0;
	}
	fin>>n;
	Graph graph(n);
	for(int i = 0; i < n; i++) {
		while(true) {
			int w;
			fin>>w;
			if(w == -1)	break;
			graph.addEdge(i, w);
		}
	}
	fin.close();
	cout<<"Enter the source vertex in the graph : ";
	// cin>>source;
	source = 0;
	cout<<"Dfs path for the source : "<<source<<endl;
	Path path(graph, source);
	cout<<endl;
	/* 
		getting an array containing pre (starting time)
		values of each vertex
	*/
	int *pre = path.getPre();	
	/* 
		getting an array containing post (finishing time)
		values of each vertex
	*/			
	int *post = path.getPost();
	cout<<"Starting and finishing time for each vertex"<<endl;
	for (int i =- 0; i < n; i++) {
		cout<<"("<<pre[i]<<","<<post[i]<<")"<<endl;
	}
	for(int u = 0; u < n; u++) {
		LinkedList ll = graph.getAdjacencyList(u);
		Node *p = ll.getFront();
		while(p != nullptr) {

			int v = p->getData();
			if(pre[u] < pre[v]&& post[v] < post[u]) {
				if(path.getParent(v) == u) {
					printf("%d-%d : %s\n", u, v, "Tree Edge");
				}
				else {
					printf("%d-%d : %s\n", u, v, "Forward Edge");
				}
			}
			else if(pre[v] < pre[u] && post[u] < post[v]) {
				printf("%d-%d : %s\n", u, v, "Back Edge");
			}
			else if(post[v] < pre[u]) {
				printf("%d-%d : %s\n", u, v, "Cross Edge");
			}
			p = p->next();

		}
	}

	return 0;

}