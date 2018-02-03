/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

int N = -1;
char indent[50];
int j = 0;

void createHeap(Heap *heap, int capacity) {
	// heap->size = 0;
	heap->pos = (int *) malloc(sizeof(int)*capacity);
}

int isHeapEmpty(Heap *heap) {
	return N == -1;
}

//utility function to swap two elements in array
void swap(Heap *heap, VertexNode **q, int i, int j) {
	// printf("exchange %d and %d\n", (*q)[i], (*q)[j]);
	int temp = heap->pos[(*q)[i].v];
	heap->pos[(*q)[i].v] = heap->pos[(*q)[j].v];
	heap->pos[(*q)[j].v] = temp;

	int swap = (*q)[i].v;
	(*q)[i].v = (*q)[j].v;
	(*q)[j].v = swap;

	int distance = (*q)[i].dist;
	(*q)[i].dist = (*q)[j].dist;
	(*q)[j].dist = distance;
}

//function to send an element up the heap maintaining heap property
void swim(Heap *heap, VertexNode **q, int k, int ele) {

	while((k-1)/2 >= 0 && (*q)[k].dist < (*q)[(k-1)/2].dist) {
		swap(heap, q, k, (k-1)/2);
		k = (k-1)/2;
	}

}

//function to send an element down the heap maintaining heap property
void minHeapify(Heap *heap, VertexNode **q, int position) {

	if(N == 0)	return;				//nothing should be done

	int smallIndex = 2*position+1;
	// printf("================================\n");
	// printf("turn = %d\n", (*q)[position]);
	// printf("================================\n");
	// printf("smallIndex = %d\n", smallIndex);
	// printf("position = %d\n", position);
	while(position <= (N-1)/2) {
		if(smallIndex < N && (*q)[smallIndex].dist > (*q)[smallIndex+1].dist)	smallIndex++;
		// printf("smallIndex1 = %d\n", smallIndex);
		if((*q)[smallIndex].dist < (*q)[position].dist)				swap(heap, q, smallIndex, position);
		else									break;
		position = smallIndex;
		smallIndex = 2*position+1;
		// printf("pos1 = %d\n", position);
		// printf("smallIndex2 = %d\n", smallIndex);

	}	

}

//building heap using minHeapify
void buildHeap(Heap *heap, VertexNode **q, int n) {

	N = n-1;
	// printf("N=%d\n", N);
	int k = (N-1)/2;
	// printf("k = %d\n", k);
	while(k >= 0) {
		// printf("k = %d\n", k);
		// printf("(*q)[%d] = %d\n", k, (*q)[k].dist);
		minHeapify(heap, q, k);
		k--;
	}
	// heap->size = N;

}

//to insert an element in the heap
void insert(Heap *heap, VertexNode **q, int ele, int d) {

	(*q)[++N].v = ele;
	(*q)[N].dist = d;
	swim(heap, q, N, ele);
	// heap->size++;

}

//to delete the minimum element in the heap
VertexNode deleteMin(Heap *heap, VertexNode **q) {

	// printf("N = %d\n", N);
	// printf("(*q)[0] = %d\n", (*q)[0]);
	// printf("(*q)[N] = %d\n", (*q)[N]);
	/***********************
		storing minimum element which has to be returned
	************************/
	VertexNode vn;
	vn.v = (*q)[0].v;
	vn.dist = (*q)[0].dist;
	/***********************
		swaping elements in the indices 1 and N
	***********************/
	swap(heap, q, 0, N);
	/***********************
		reducing the size of the heap
	***********************/
	N--;
	/***********************
		calling function minHeapify to rearrange the tree 
		to become heap again
	***********************/
	// printf("N = %d\n", N);
	// display(q);
	minHeapify(heap, q, 0);
	// heap->size--;
	return vn;

}

int getPosition(Heap *heap, int vertex) {
	return heap->pos[vertex];
}

void decreaseKey(Heap *heap, VertexNode **q, int k, int key) {
	// int k = heap->pos[vertex];
	(*q)[k].dist = key;
	swim(heap, q, k, key);
}

//utility function to modify the array 'indent'
void Push(char c) {

	indent[j++] = ' ';
	indent[j++] = c;
	indent[j++] = ' ';
	indent[j++] = ' ';
	indent[j]   = '\0';

}

void Pop() {
	indent[j-4] = '\0';
	j = j-4;
}

//recursive function to print the heap in tree format
void print(VertexNode **q, int k) {

	printf("%-2d\n", (*q)[k].v);
	
	if(2*k+2 <= N) {
		printf("%s `--", indent);
		Push('|');
		print(q, 2*k+2);
		Pop();
	}
	if(2*k+1 <= N) {
		printf("%s `--", indent);
		Push(' ');
		print(q, 2*k+1);
		Pop();
	}

}

// to display the heap in tree format
void display(VertexNode **q) {

	print(q, 0);

} 

//function to sort the array 
void heapSort(Heap *heap, VertexNode **q) {

	int i;
	int n = N;
	for(i = 0; i <= n; i++) {
		VertexNode vn = deleteMin(heap, q);
		printf("%d ", vn.dist);
	}
	N = n;
	printf("\n");
}