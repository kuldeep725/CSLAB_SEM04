/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
	int N;				//size of heap
	int *pos;
} Heap;

typedef struct VertexNode {
	int v;
	int dist;
} VertexNode;

void createHeap(Heap *, int);

int isHeapEmpty(Heap *);

void swim(Heap *, VertexNode **, int, int);

void minHeapify(Heap *, VertexNode **, int);

void swap(Heap *, VertexNode **, int, int);

void buildHeap(Heap *, VertexNode **, int);

void insert(Heap *, VertexNode **, int, int);

VertexNode deleteMin(Heap *, VertexNode **);

int getPosition(Heap *, int);

void decreaseKey(Heap *, VertexNode **, int, int);

void Push(char);

void Pop();

void print(VertexNode **, Heap *, int);

void display(VertexNode **, Heap *);

void heapSort(Heap *, VertexNode **);

int heapSize(Heap *);

#endif