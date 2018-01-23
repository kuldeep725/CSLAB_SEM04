#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long bin(long num) {

	long base = 1;
	long remainder = 0;
	long binary = 0;
	while(num > 0) {
		remainder = num%2;
		binary += remainder * base;
		num = num/2;
		base = base * 10;
	}
	printf("%ld ", binary);
	return binary;

}

int main() {

	long num;
	long n;
	printf("Enter number of randoms numbers : ");
	scanf("%ld", &n);
	char fileName[32] = "random_";
	char ch[6];
	/*
		sprintf(str, "%d", value) converts 'value' to decimal base in string 'str'
		sprintf(str, "%x", value) converts 'value' to hexadecimal base in string 'str'
		sprintf(str, "%o", value) converts 'value' to octal base in string 'str'
	*/
	sprintf(ch, "%ld", n);

	printf("ch = %s\n", ch);
	strcat(fileName, ch);
	char textFile[32];
	strcpy(textFile, fileName);
	strcat(fileName, ".bin");
	strcat(textFile, ".txt");

	printf("fileName = %s\n", fileName);
	printf("textFile = %s\n", textFile);
	FILE *fbin = fopen(fileName, "wb");
	FILE *ftext = fopen(textFile, "w");
	int i;
	for(i = 0; i < n; i++) {
		num = rand()%100000+1;
		fprintf(ftext, "%ld ", num);
		printf("%ld ", num);
		// long binary = bin(num);
		fwrite(&num, sizeof(long), 1, fbin);

		// long x = fwrite(&binary, sizeof(binary), 1, fbin);
		// printf("x = %ld\n", x);
		/*
		**	size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		
		*	ptr − This is the pointer to the array of elements to be written.

		*	size − This is the size in bytes of each element to be written.

		*	nmemb − This is the number of elements, each one with a size of size bytes.

		*	stream − This is the pointer to a FILE object that specifies an output stream.

		*/
	}
	fclose(fbin);	
	fclose(ftext);

	return 0;
}