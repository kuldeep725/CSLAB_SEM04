/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<iostream>
#include"DepthFirstPaths.h"
#include"LinkedList.h"

static int count = 1;

Path::Path(Graph g, int source) {

	s = source;
	visited = new bool[g.getV()];
	parent = new int[g.getV()];
	pre = new int[g.getV()];
	post = new int[g.getV()];
	for(int i = 0; i < g.getV(); i++) {
		visited[i] = false;
		parent[i] = -1;
	}
	dfs(g, s);

}

Path::~Path() {
	// delete[] visited;
	// delete[] parent;
	// delete[] pre;
	// delete[] post;
}

void Path::dfs(Graph g, int v) {

	using namespace std;
	visited[v] = true;
	LinkedList ll = g.getAdjacencyList(v);
	Node *p = ll.getFront();
	pre[v] = count++;
	cout<<v<<" ";
	while(p != nullptr) {
		int currentNode = p->getData();
		if(!visited[currentNode]) {
			visited[v] = true;
			parent[currentNode] = v;
			dfs(g, currentNode);
		}
		p = p->next();
	}
	post[v] = count++;

}

int * Path::getPre() {
	return pre;
}

int * Path::getPost() {
	return post;
}

int Path::getParent(int v) {
	return parent[v];
}

void Path::freePath() {
	delete[] visited;
	delete[] parent;
	delete[] pre;
	delete[] post;
}
