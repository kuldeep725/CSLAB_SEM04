#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {

	int data;
	struct Node *next;
	struct Node *prev;
	
} Node;

typedef struct List {

	struct Node *front;
	struct Node *rear;
	int length;

} List;

/*
	to create and return an empty linked list 
*/
List * getList(List *);

/*
	to push an element at the end of the list
*/
void push(List *, int );

/*
	to pop/delete the last element in the list
*/
int pop(List *);

/*
	to push an element at the front of the list
*/
void pushFront(List *, int );

/*
	to pop an element from the front in the list
*/
int popFront(List *);
/*
	to get the last element in the list
*/
int last (List *);

/*
	to get the first element in the list
*/
int first (List *);

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
int getData (Node *);

/*
	to get the pointer to the first position in the list
*/
Node * getFront (List *list);

/*
	to get the pointer to the last position in the list
*/
Node * getEnd (List *list);

/*
	to clear all the memory of the list
*/
void clear (List *list);

/*
	to reverse the elements in the list and return the list
*/
List * reverse(List *list);

/*
	*	to search an element in the list and return its index
		in the list
	*	return INT_MIN if list is empty or element doesn't
		exist in the list
*/
int search(List *, int );

/*
	check if element exists in the list or not
*/
bool contains(List *,int );

#endif