/*
	* Name 	 	: 	Kuldeep Singh Bhandari
	* Roll No.  :	111601009
	* Aim 	 	:	To implement heap data structure
					and perform heap sort
*/
#include<stdio.h>
#include"heap.h"

int main() {

	// int a[50] = {90, 60,  20, 40, 45, 42, 10, 80};
	int a[100];
	int x;
	printf("Enter the size of the array : \n");
	int n;
	scanf("%d", &n);
	printf("Enter the array : \n");
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	buildHeap(a, n);
	int choice;
	do {

		printf(" s====================MENU==========================\n");
		printf(" 1. Insert an element into the heap\n");
		printf(" 2. Delete minimum element from the heap\n");
		printf(" 3. Apply HeapSort to array\n");
		printf(" 4. Display \"Heap Tree\"\n");
		printf(" 5. Exit\n");
		printf("Your choice : ");
		scanf("%d", &choice);

		switch(choice) {

			case 1 :

				printf("Enter the value to be inserted : ");
				scanf("%d", &x);
				insert(a, x);
				break;

			case 2 :
				
				x = deleteMin(a);
				printf("The minimum element in the heap : %d\n", x);
				break;

			case 3 :

				printf("Sorted Array is \n");
				heapSort(a);
				break;

			case 4 :
				display(a);
				break;

			case 5 :
				break;

			default :
				printf("Please enter valid choice (1, 2, 3, 4 or 5).\n");

		}

	} while(choice != 5);

	return 0;

} 
// 20 12 70 60 50 16 30 44 40 14 (10)
// 10 20 30 23 42 37 70 44 40 60 90 55 54 77 (14)