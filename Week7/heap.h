/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
	int N;			//size of heap
	int *pos;
} Heap;

typedef struct Edge {
	int u;
	int v;
	int weight;
} Edge;

void createHeap(Heap *, int);

int isHeapEmpty(Heap *);

void swim(Heap *, Edge **, int, int);

void minHeapify(Heap *, Edge **, int);

void swap(Heap *, Edge **, int, int);

void buildHeap(Heap *, Edge **, int);

void insert(Heap *, Edge **, int, int);

Edge deleteMin(Heap *, Edge **);

int getPosition(Heap *, int);

void decreaseKey(Heap *, Edge **, int, int);

void Push(char);

void Pop();

void print(Edge **, Heap*, int);

void display(Edge **, Heap *);

void heapSort(Heap *, Edge **);

int heapSize();

#endif