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

void createHeap(Heap *heap, int capacity){
	heap->pos = (int *) malloc(sizeof(int)*capacity);
}

int isHeapEmpty(Heap *heap) {
	return N == -1;
}

//utility function to swap two elements in array
void swap(Heap *heap, VertexNode **q, int i, int j) {
	
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
	
	while(position <= (N-1)/2) {

		if(smallIndex < N && (*q)[smallIndex].dist > (*q)[smallIndex+1].dist)	smallIndex++;
		
		if((*q)[smallIndex].dist < (*q)[position].dist)	{
				swap(heap, q, smallIndex, position);
		}
		else	break;

		position = smallIndex;
		smallIndex = 2*position+1;

	}	

}

//building heap using minHeapify
void buildHeap(Heap *heap, VertexNode **q, int n) {

	N = n-1;
	int k = (N-1)/2;
	
	while(k >= 0) {
		minHeapify(heap, q, k);
		k--;
	}

}

//to insert an element in the heap
void insert(Heap *heap, VertexNode **q, int ele, int d) {

	(*q)[++N].v = ele;
	(*q)[N].dist = d;
	swim(heap, q, N, ele);

}

//to delete the minimum element in the heap
VertexNode deleteMin(Heap *heap, VertexNode **q) {

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
	minHeapify(heap, q, 0);
	return vn;

}

//to return the position of the 'vertex' in the heap
int getPosition(Heap *heap, int vertex) {
	return heap->pos[vertex];
}

//to decrease the key of the vertex and shift it up the tree (if possible)
void decreaseKey(Heap *heap, VertexNode **q, int k, int key) {
	if(key < (*q)[k].dist) {
		(*q)[k].dist = key;
		swim(heap, q, k, key);
	}
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