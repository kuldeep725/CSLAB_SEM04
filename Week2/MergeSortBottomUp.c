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

/***********************
	'main' function begins
***********************/
int main(int argc, char const *argv[]) {

	long x;
	char const *fileName = argv[1];			//taking name of file from terminal
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

	printf("---------------BEFORE SORTING--------------------\n");
	/*****************
		displaying values in the input file
	*****************/
	while(fread(&x, sizeof(x), 1, fin) ==  1) {
		printf("%ld ", x);
	}

	printf("\n---------------AFTER SORTING--------------------\n");
	/*****************
		calling function sort() which takes one parameter
		FILE pointer and sort the whole file using merge sort
	*****************/
	sort(fin);			
	
	while(fread(&x, sizeof(x), 1, fin) ==  1) {
		printf("%ld ", dec(x));
		fprintf(fout, "%ld ", dec(x));
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
	FILE *f_aux = fopen("auxTextFile.txt", "r+");		//opening a text file in
													//read and write mode
	for(i = low; i <= high; i++) {

		/****************
			sending pointer fin to l1th element from beginning
		****************/
		fseek(fin, l1*sizeof(long), SEEK_SET);		
		fread(&a, sizeof(long), 1, fin);
		/****************
			sending pointer fin to l2th element from beginning
		****************/
		fseek(fin, l2*sizeof(long), SEEK_SET);
		fread(&b, sizeof(long), 1, fin);
		// printf("a = %ld\n", a);
		// printf("b = %ld\n", b);
		if(l1 > mid) {			//when left half of file is over
			// printf("CASE 1\n");
			l2++;
			fprintf(f_aux, "%ld\n", b);
		}
		else if(l2 > high) {	//when right half of file is over
			// printf("CASE 2\n");
			l1++;
			fprintf(f_aux, "%ld\n", a);
		}
		else if(a <= b) {		
			// printf("CASE 3\n");
			l1++;
			fprintf(f_aux, "%ld\n", a);
		}
		else {
			// printf("CASE 4\n");
			l2++;
			fprintf(f_aux, "%ld\n", b);
		}
		// printf("------------------------\n");
	}
	fseek(fin, low*sizeof(long), SEEK_SET);		
	rewind(f_aux);
	// printf("--------------COPYING-----------------\n");
	for(i = low; i <= high; i++) {
		fscanf(f_aux, "%ld", &a);
		// printf("a = %ld\n", a);
		fwrite(&a, sizeof(long), 1, fin);
	}
	// printf("---------------DONE-----------------\n");
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