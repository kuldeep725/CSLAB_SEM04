/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#ifndef LINKEDLISTOFSTRUCTURES
#define LINKEDLISTOFSTRUCTURES_H

typedef struct Vertex {
	int data;
	int weight;
} Vertex;

typedef struct Node {

	Vertex v;
	struct Node *next;
	struct Node *prev;
	
} Node;

typedef struct List {

	struct Node *front;
	struct Node *rear;
	int length;

} List;

/*
	to create an empty linked list 
*/
void getList(List *);

/*
	to push an element at the end of the list
*/
void push(List *, int, int);

/*
	to pop/delete the last element in the list
*/
Vertex pop(List *);

/*
	to push an element at the front of the list
*/
void pushFront(List *, int, int);

/*
	to pop an element from the front in the list
*/
Vertex popFront(List *);
/*
	to get the last element in the list
*/
Vertex last (List *);

/*
	to get the first element in the list
*/
Vertex first (List *);

/*
	to check if the list is empty 
*/
bool isEmpty(List *);

/*
	to get the size of the list
*/
int size(List *);

/*
	to go to the previous pointer
*/
Node * prev (Node *);

/*
	to go to the next pointer
*/
Node * next (Node *);

/*
	to get the data of the given pointer
*/
Vertex getData (Node *);

/*
	to get the pointer to the first position in the list
*/
Node * getFront (List *list);

/*
	to get the pointer to the last position in the list
*/
Node * getRear (List *list);

/*
	to clear all the memory of the list
*/
void clear (List *list);

/*
	to reverse the elements in the list and return the list
*/
void reverse(List *list);

/*
	*	to search an element in the list and return its index
		in the list
	*	return INT_MIN if list is empty or element doesn't
		exist in the list
*/
int search(List *, Vertex );

/*
	check if element exists in the list or not
*/
bool contains(List *,Vertex );

#endif