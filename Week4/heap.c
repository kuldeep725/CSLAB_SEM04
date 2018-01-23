/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>

int N = -1;

void swap(int *a, int p, int q) {
	// printf("exchange %d and %d\n", a[p], a[q]);
	int swap = a[p];
	a[p] = a[q];
	a[q] = swap;
}

void swim(int *a, int k, int ele) {

	while((k-1)/2 >= 0 && a[k] < a[(k-1)/2]) {
		swap(a, k, (k-1)/2);
		k = (k-1)/2;
	}

}

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

void insert(int *a, int ele) {

	a[++N] = ele;
	swim(a, N, ele);

}

int delete(int *a) {

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

void display(int *a) {

	int i;
	for(i = 0; i <= N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

}