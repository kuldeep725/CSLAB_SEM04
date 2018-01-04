#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

// typedef struct LinkedList LinkedList;

typedef struct LinkedList {

	int data;
	struct LinkedList *next;
	struct LinkedList *prev;
	
} LinkedList;

typedef struct List {

	struct LinkedList *front;
	struct LinkedList *end;
	int length;

} List;

/*
	to create and return an empty linked list 
*/
LinkedList * getLinkedList(LinkedList *);

/*
	to push an element at the end of the list
*/
void push(LinkedList *, int );

/*
	to pop/delete the last element in the list
*/
int pop(LinkedList *);
/*
	to get the last element in the list
*/
int last (LinkedList *);

/*
	to get the first element in the list
*/
int first (LinkedList *);

/*
	to check if the list is empty 
*/
bool isEmpty(LinkedList *);

/*
	to get the size of the list
*/
int size(LinkedList *);

/*
	to go to the next pointer
*/
LinkedList * next (LinkedList *);

/*
	to get the data of the given pointer
*/
int getData (LinkedList *list);

/*
	to get the pointer to the first position in the list
*/
LinkedList * getFront (LinkedList *list);

/*
	to get the pointer to the last position in the list
*/
LinkedList * getEnd (LinkedList *list);