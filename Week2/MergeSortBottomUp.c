#include<stdio.h>
#include<stdlib.h>

int main() {

	char fileName[32];
	// long x[];
	char x[32];
	printf("Enter fileName : ");
	scanf("%s", fileName);
	FILE *fin = fopen(fileName,"r");
	int n;
	if(!fin) {
		printf("Error in file opening\n");
		return 1;
	}
	fscanf(fin,"%d",&n);
	printf("BEFORE SORTING\n");
	int i = 0;
	fread(x, 8, n, fin);
	printf("%s\n", x);
	// while(fread(x, 8, n, fin)) {
	// 	printf("%ld\n", x[i]);
	// } 
	// while(fscanf(fin, "%ld", &x) != -1) {
	// 	printf("%ld\n", x);
	// }
	// rewind(fin);
	// fscanf(fin, "%ld", &x);
	// printf("rewinded : %ld\n", x);
	// int i;
	int size = 2;
	// printf("AFTER SORTING\n");
	// for(i = size; i < n-size; i=size+size) {
	// 	// printf("%ld\n", x);
	// 	mergeSort(fseek(fin, 1, SEEK_SET), size, n);
	// 	// printf("%d\n", fseek(fin,1,SEEK_SET));
	// 	size = size+size;
	// }
	fclose(fin);
	return 0;
}

// void mergeSort(FILE *fin, int size, int n) {

// 	int i;
// 	for (i = 0; i < n-size; i=size+size) {
// 		merge(fin, i, i+size-1);
// 		size = size + size;
// 	}

// }

// void merge(FILE *fin, int low, int high) {
// 	int mid = low + (high-low)/2;
// 	int l1 = low;
// 	int l2 = mid+1;
// 	int i;
// 	long x;
// 	FILE *f_aux = fopen("auxTextFile.txt","w");
// 	FILE *fLow = fseek(f_aux, low, SEEK_SET);
// 	FILE *fMid = fseek(f_aux, mid+1, SEEK_SET);
// 	FILE *i;
// 	for(i = fLow; i != fMid; i++) {
// 		fscanf(i, "%ld", &x);

// 		if(l1 > l2)	{
// 			fprintf(fin, "%ld\n", x);
// 		}
// 		else if(l2 > l1) {
// 			fscanf(fin, "%ld", &x);
// 			fprintf(f_aux, "%s\n", );
// 		}
// 	}
	// for(i = low; i <= high; i++) {
		// if(l1 > l2)	{
		// 	fscanf(fin, "%ld", &x);
		// 	fprintf(f, "%ld\n", x);
		// }
		// else if(l2 > l1) {
		// 	fscanf(fin, "%ld", &x);
		// 	fprintf(f_aux, "%s\n", );
		// }
	// }

// }