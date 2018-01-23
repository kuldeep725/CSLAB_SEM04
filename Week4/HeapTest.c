#include<stdio.h>
#include"heap.h"

int main() {

	// int a[50] = {90, 60,  20, 40, 45, 42, 10, 80};
	int a[100];
	printf("Enter the size of the array : \n");
	int n;
	scanf("%d", &n);
	printf("Enter the array : \n");
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	buildHeap(a, 8);
	printf("The buildHeap is : \n");
	display(a);
	// int min = delete(a);
	// printf("min = %d\n", min);
	// display(a);
	// insert(a, 30);
	// display(a);
	// min = delete(a);
	// printf("min = %d\n", min);
	// display(a);
	// insert(a, 5);
	// display(a);
	// insert(a, 46);
	// display(a);
	// insert(a, 10);
	// display(a);
	printf("Sorted Array is \n");
	for(i = 0; i < n; i++) {
		printf("%d ", delete(a));
	}
	printf("\n");
	return 0;

}