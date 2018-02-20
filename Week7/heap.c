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
void swap(Heap *heap, Edge **e, int i, int j) {
	
	int swap = (*e)[i].u;
	(*e)[i].u = (*e)[j].u;
	(*e)[j].u = swap;

	swap = (*e)[i].v;
	(*e)[i].v = (*e)[j].v;
	(*e)[j].v = swap;

	int distance = (*e)[i].weight;
	(*e)[i].weight = (*e)[j].weight;
	(*e)[j].weight = distance;

}

//function to send an element up the heap maintaining heap property
void swim(Heap *heap, Edge **e, int k, int ele) {

	while((k-1)/2 >= 0 && (*e)[k].weight < (*e)[(k-1)/2].weight) {
		swap(heap, e, k, (k-1)/2);
		k = (k-1)/2;
	}

}

//function to send an element down the heap maintaining heap property
void minHeapify(Heap *heap, Edge **e, int position) {

	if(N == 0)	return;				//nothing should be done

	int smallIndex = 2*position+1;
	
	while(position <= (N-1)/2) {

		if(smallIndex < N && (*e)[smallIndex].weight > (*e)[smallIndex+1].weight)	smallIndex++;
		
		if((*e)[smallIndex].weight < (*e)[position].weight)	{
				swap(heap, e, smallIndex, position);
		}
		else	break;

		position = smallIndex;
		smallIndex = 2*position+1;

	}	

}

//building heap using minHeapify
void buildHeap(Heap *heap, Edge **e, int n) {

	N = n-1;
	int k = (N-1)/2;
	
	while(k >= 0) {
		minHeapify(heap, e, k);
		k--;
	}

}

//to insert an element in the heap
void insert(Heap *heap, Edge **e, int ele, int d) {

	(*e)[++N].v = ele;
	(*e)[N].weight = d;
	swim(heap, e, N, ele);

}

//to delete the minimum element in the heap
Edge deleteMin(Heap *heap, Edge **e) {

	/***********************
		storing minimum element which has to be returned
	************************/
	Edge vn;
	vn.u = (*e)[0].u;
	vn.v = (*e)[0].v;
	vn.weight = (*e)[0].weight;
	/***********************
		swaping elements in the indices 1 and N
	***********************/
	swap(heap, e, 0, N);
	/***********************
		reducing the size of the heap
	***********************/
	N--;
	/***********************
		calling function minHeapify to rearrange the tree 
		to become heap again
	***********************/
	minHeapify(heap, e, 0);
	return vn;

}

//to return the position of the 'vertex' in the heap
int getPosition(Heap *heap, int vertex) {
	return heap->pos[vertex];
}

//to decrease the key of the vertex and shift it up the tree (if possible)
void decreaseKey(Heap *heap, Edge **e, int k, int key) {
	if(key < (*e)[k].weight) {
		(*e)[k].weight = key;
		swim(heap, e, k, key);
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
void print(Edge **e, int k) {

	printf("%-2d\n", (*e)[k].v);
	
	if(2*k+2 <= N) {
		printf("%s `--", indent);
		Push('|');
		print(e, 2*k+2);
		Pop();
	}
	if(2*k+1 <= N) {
		printf("%s `--", indent);
		Push(' ');
		print(e, 2*k+1);
		Pop();
	}

}

// to display the heap in tree format
void display(Edge **e) {

	print(e, 0);

} 

//function to sort the array 
void heapSort(Heap *heap, Edge **e) {

	int i;
	int n = N;
	for(i = 0; i <= n; i++) {
		Edge vn = deleteMin(heap, e);
		printf("%d ", vn.weight);
	}
	N = n;
	printf("\n");
}

int heapSize() {
	return N;
}