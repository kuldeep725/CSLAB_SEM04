/*
	* Name 	 	: 	Kuldeep Singh Bhandari
	* Roll No.  :	111601009
	* Aim 	 	:	Sorting a binary file using merge sort 
					bottom-up approach
	* Note 		:	Give first argument in the terminal to be the 
					name of the binary file which is to opened
					for sorting (eg ./a.out input.bin)
*/

#include<stdio.h>
#include<stdlib.h>

void mergeSort(FILE *, long , long);
void merge(FILE *, long , long , long);
long min(long, long);
long dec(long );
void sort(FILE *);
char const *fileName;
/***********************
	'main' function begins
***********************/
int main(int argc, char const *argv[]) {

	long x;
	fileName = argv[1];			//taking name of file from terminal
	// printf("Enter fileName : ");
	// scanf("%s", fileName);
	/*****************
		opening binary file in read + write mode
	*****************/
	FILE *fin = fopen(fileName,"rb+");
	/*****************
		opening output text file in write mode
	*****************/
	FILE *fout = fopen("output.txt", "w");

	//checking if the file is properly opened
	if(!fin) {			
		printf("Error in file opening\n");
		return 1;
	}

	printf("\n=======================BEFORE SORTING=======================\n\n");
	/*****************
		displaying values in the input file
	*****************/
	while(fread(&x, sizeof(x), 1, fin) ==  1) {
		printf("%ld ", x);
	}

	printf("\n\n=======================AFTER SORTING=======================\n\n");
	/*****************
		calling function sort() which takes one parameter
		FILE pointer and sort the whole file using merge sort
	*****************/
	sort(fin);			
	
	while(fread(&x, sizeof(x), 1, fin) ==  1) {
		printf("%ld ", x);
		// fprintf(fout, "%ld ", dec(x));
		fprintf(fout, "%ld ", x);
	}
	printf("\n");
	/****************
		closing all the opened files
	****************/
	fclose(fin);
	fclose(fout);
	return 0;			//returning 0 as program is successfully executed
}
/***********************
	'main' function ends
***********************/

/*****************
	function sort() which takes one parameter
	FILE pointer and sort the whole file using merge sort
*****************/
void sort(FILE *fin) {

	long size;			//decides the value of partition
	fseek(fin, 0, SEEK_END);		//making pointer 'fin' to point to end of file
	long lSize = ftell(fin);		//getting total number of characters in file
	long n;
	n = lSize/(sizeof(long));		//getting total number of long integers in file
	printf("Total Number of terms = %ld\n", n);		//displaying number of terms

	for(size = 1; size < n; size=size+size) {
		// printf("%ld\n", x);
		/******************
			calling mergesort() function to sort elements in blocks 
			of size '2*size'
		******************/
		mergeSort(fin, size, n);
	}
	rewind(fin);

}

/******************
	mergesort function to sort elements in blocks 
	of size '2*size'
******************/
void mergeSort(FILE *fin, long size, long n) {

	long i;
	for (i = 0; i < n-size; i+=size+size) {
		// printf("size = %ld\n", size);
		/*************
			calling merge() function to merge sorted blocks of interval
			(i, i+size-1) and (i+size, min(i+size+size-1, n-1))
		**************/
		merge(fin, i, i+size-1, min(i+size+size-1, n-1));
		// printf("<<<<<<<<<<<<<<<<<STATE>>>>>>>>>>>>>>>>>\n");
		// long x;
		rewind(fin);
		// while(fread(&x, sizeof(x), 1, fin) ==  1) {
		// 	printf("%ld ", x);
		// }
		// printf("\n=======================================\n");
	}

}
/*****************
	merge() function to merge sorted blocks of interval
	(i, i+size-1) and (i+size, min(i+size+size-1, n-1))
*****************/
void merge(FILE *fin, long low, long mid, long high) {

	long l1 = low;			//for pointing to left half of file
	long l2 = mid+1;		//for pointing to right half of file
	// printf("(low, mid, high)=(%ld, %ld, %ld)\n", low, mid, high);
	long i;
	long a;
	long b;
	FILE *fLow = fopen(fileName, "r");
	FILE *fMid = fopen(fileName, "r");
	fseek(fLow, l1*sizeof(long), SEEK_SET);
	fseek(fMid, l2*sizeof(long), SEEK_SET);

	FILE *f_aux = fopen("auxTextFile.txt", "w+");		//opening a text file in
													//read and write mode
	if(!f_aux) {
		printf("Error in opening file : auxTextFile.txt\n");
		return;
	}
	for(i = low; i <= high; i++) {

		/****************
			sending pointer fin to l1th element from beginning
		****************/
		// fseek(fin, l1*sizeof(long), SEEK_SET);		
		// fread(&a, sizeof(long), 1, fin);
		/****************
			sending pointer fin to l2th element from beginning
		****************/
		// fseek(fin, l2*sizeof(long), SEEK_SET);
		// fread(&b, sizeof(long), 1, fin);
		if(l1 <= mid) {
			fread(&a, sizeof(long), 1, fLow);
			// printf("a = %ld\n", a);
		}
		if(l2 <= high) {
			fread(&b, sizeof(long), 1, fMid);
			// printf("b = %ld\n", b);
		}
		
		// fseek(fLow, sizeof(long), SEEK_CUR);
		// fseek(fMid, sizeof(long), SEEK_CUR);
		
		
		if(l1 > mid) {			//when left half of file is over
			// printf("CASE 1\n");
			l2++;
			fprintf(f_aux, "%ld\n", b);
			// fseek(fMid, sizeof(long), SEEK_CUR);
			// fseek(fLow, -sizeof(long), SEEK_CUR);
		}
		else if(l2 > high) {	//when right half of file is over
			// printf("CASE 2\n");
			l1++;
			fprintf(f_aux, "%ld\n", a);
			// fseek(fLow, sizeof(long), SEEK_CUR);
			// fseek(fMid, -sizeof(long), SEEK_CUR);
		}
		else if(a <= b) {		
			// printf("CASE 3\n");
			l1++;
			fprintf(f_aux, "%ld\n", a);
			// fseek(fLow, sizeof(long), SEEK_CUR);
			fseek(fMid, -sizeof(long), SEEK_CUR);
		}
		else {
			// printf("CASE 4\n");
			l2++;
			fprintf(f_aux, "%ld\n", b);
			// fseek(fMid, sizeof(long), SEEK_CUR);
			fseek(fLow, -sizeof(long), SEEK_CUR);
		}
		// printf("------------------------\n");
	}
	fclose(fLow);
	fclose(fMid);
	fseek(fin, low*sizeof(long), SEEK_SET);		
	rewind(f_aux);
	// printf("--------------COPYING-----------------\n");
	for(i = low; i <= high; i++) {
		fscanf(f_aux, "%ld", &a);
		// printf("a = %ld\n", a);
		fwrite(&a, sizeof(long), 1, fin);
	}
	// printf("---------------DONE-------------------\n");
	fclose(f_aux);

}

/*******************
	utility function to fine minimum of two functions
*******************/
long min(long a, long b) {
	if(a<=b)	return a;
	else		return b;
}

/******************
	utility function to convert binary to decimal 
******************/
long dec(long binary) {

	long x = 0;
	long base = 1;
	while(binary > 0) {
		long digit = binary % 10;
		x += digit * base;
		binary = binary/10;
		base = base * 2;
	}
	return x;

}