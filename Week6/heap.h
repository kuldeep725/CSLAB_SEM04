/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
	int N;
	int *pos;
} Heap;

typedef struct VertexCost {
	int v;
	int cost;
} VertexCost;

void createHeap(Heap *, int);

int isHeapEmpty(Heap *);

void swim(Heap *, VertexCost **, int, int);

void minHeapify(Heap *, VertexCost **, int);

void swap(Heap *, VertexCost **, int, int);

void buildHeap(Heap *, VertexCost **, int);

void insert(Heap *, VertexCost **, int, int);

VertexCost deleteMin(Heap *, VertexCost **);

int getPosition(Heap *, int);

void decreaseKey(Heap *, VertexCost **, int, int);

void Push(char);

void Pop();

void print(VertexCost **, Heap *, int);

void display(VertexCost **, Heap *);

void heapSort(Heap *, VertexCost **);

int heapSize(Heap *);

#endif