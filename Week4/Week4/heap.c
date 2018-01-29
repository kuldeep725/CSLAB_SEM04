/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>

int N = -1;
char indent[50];
int j = 0;

//utility function to swap two elements in array
void swap(int *a, int p, int q) {
	// printf("exchange %d and %d\n", a[p], a[q]);
	int swap = a[p];
	a[p] = a[q];
	a[q] = swap;
}

//function to send an element up the heap maintaining heap property
void swim(int *a, int k, int ele) {

	while((k-1)/2 >= 0 && a[k] < a[(k-1)/2]) {
		swap(a, k, (k-1)/2);
		k = (k-1)/2;
	}

}

//function to send an element down the heap maintaining heap property
void minHeapify(int *a, int pos) {

	if(N == 0)	return;				//nothing should be done

	int smallIndex = 2*pos+1;
	// printf("================================\n");
	// printf("turn = %d\n", a[pos]);
	// printf("================================\n");
	// printf("smallIndex = %d\n", smallIndex);
	// printf("pos = %d\n", pos);
	while(pos <= (N-1)/2) {

		if(smallIndex < N && a[smallIndex] > a[smallIndex+1])	smallIndex++;
		// printf("smallIndex1 = %d\n", smallIndex);
		if(a[smallIndex] < a[pos])				swap(a, smallIndex, pos);
		else									break;
		pos = smallIndex;
		smallIndex = 2*pos+1;
		// printf("pos1 = %d\n", pos);
		// printf("smallIndex2 = %d\n", smallIndex);

	}	

}

//building heap using minHeapify
void buildHeap(int *a, int n) {

	N = n-1;
	// printf("N=%d\n", N);
	int k = (N-1)/2;
	// printf("k = %d\n", k);
	while(k >= 0) {
		minHeapify(a, k);
		k--;
	}

}

//to insert an element in the heap
void insert(int *a, int ele) {

	a[++N] = ele;
	swim(a, N, ele);

}

//to delete the minimum element in the heap
int deleteMin(int *a) {

	// printf("N = %d\n", N);
	// printf("a[0] = %d\n", a[0]);
	// printf("a[N] = %d\n", a[N]);
	/***********************
		storing minimum element which has to be returned
	************************/
	int ele = a[0];
	/***********************
		swaping elements in the indices 1 and N
	***********************/
	swap(a, 0, N);
	/***********************
		reducing the size of the heap
	***********************/
	N--;
	/***********************
		calling function minHeapify to rearrange the tree 
		to become heap again
	***********************/
	minHeapify(a, 0);

	return ele;

}

//utility function to modify the array 'indent'
void push(char c) {

	indent[j++] = ' ';
	indent[j++] = c;
	indent[j++] = ' ';
	indent[j++] = ' ';
	indent[j]   = '\0';

}

void pop() {
	indent[j-4] = '\0';
	j = j-4;
}

//recursive function to print the heap in tree format
void print(int *a, int k) {

	printf("%-2d\n", a[k]);
	
	if(2*k+1 <= N) {
		printf("%s `--", indent);
		push('|');
		print(a, 2*k+1);
		pop();
	}
	if(2*k+2 <= N) {
		printf("%s `--", indent);
		push(' ');
		print(a, 2*k+2);
		pop();
	}

}

// to display the heap in tree format
void display(int *a) {

	print(a, 0);

}

//function to sort the array 
void heapSort(int *a) {

	int i;
	int b[100];
	int n = N;
	for(i = 0; i <= n; i++) {
		b[i] = deleteMin(a);
		printf("%d ", b[i]);
	}
	for(i = 0; i <= n; i++) {
		a[i] = b[i];
	}
	N = n;
	printf("\n");

}