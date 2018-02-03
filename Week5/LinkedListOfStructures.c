/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include "LinkedListOfStructures.h"

/*
	to create and return an empty linked list 
*/
void getList(List *list) {

	// list = (List *) malloc(sizeof(List));
	// list->data = INT_MIN;
	// list->prev = NULL;
	// list->next = NULL;
	list->front = NULL;
	list->rear = NULL;
	list->length = 0;
	// return list;

}

void push(List *list, int ele, int w) {

	if(list == NULL)	return;		//checking whether list is NULL

	Node *p = (Node *) malloc(sizeof(List));
	p->v.data = ele;
	p->v.weight = w;

	if(list->rear == NULL) {		//if list is empty 
		p->prev = NULL;
		p->next = NULL;
		/**************
			making rear and front pointing to same pointer 'p;
		**************/
		list->rear = p;
		list->front = p;
	}
	else {						//if list is not empty
		p->prev = list->rear;
		p->next = NULL;
		list->rear->next = p;
		list->rear = p;
	}
	list->length++;				//incrementing size of linked list

}

Vertex pop(List *list) {

	// if(isEmpty(list))	return INT_MIN;		//if list is empty return INT_MIN

	Node *p = list->rear;
	// printf("list->rear = %d\n", p->data);
	Vertex vertex = p->v;
	list->rear = list->rear->prev;			//shifting rear pointer to previous
											//pointer
	if(list->rear != NULL)	list->rear->next = NULL;
	p->prev = NULL;
	p->next = NULL;
	free(p);								//deleting the last node
	if(list->rear == NULL)		list->front = NULL;
	list->length--;			      			//decrementing size of linked list		
	return vertex;

}

void pushFront(List *list, int ele, int w) {

	if(isEmpty(list))	return;			//checking whether list is empty

	Node *p = (Node *) malloc(sizeof(List));
	p->v.data = ele;
	p->v.weight = w;
	if (list->front == NULL) {			//if list is empty 
		p->prev = NULL;
		p->next = NULL;
		list->front = p;
		list->rear = p;
	}
	else {								//if list is not empty
		p->prev = NULL;
		p->next = list->front;
		list->front->prev = p;
		list->front = p;
	}
	list->length++;						//incrementing size of linked list

}

Vertex popFront(List *list) {

	// if(isEmpty(list))	return INT_MIN;

	Node *p = list->front;
	// int ele = p->data;
	Vertex vertex = p->v;
	list->front = list->front->next;
	if(list->front != NULL)		list->front->prev = NULL;
	p->prev = NULL;
	p->next = NULL;
	free(p);
	list->length--;
	return vertex;
	
}

Vertex last (List *list) {

	// if(isEmpty(list))	return INT_MIN;
	return list->rear->v;

}

Vertex first (List *list) {

	// if(isEmpty(list))	return INT_MIN;
	return list->front->v;

}

bool isEmpty(List *list) {

	return list->length == 0;

}

int size(List *list) {

	if(isEmpty(list))	return INT_MIN;
	return list->length;

}

Node * prev (Node *p) {

	if(p == NULL)	return NULL;
	return p->prev;

}

Node * next (Node *p) {

	if(p == NULL)	return NULL;
	return p->next;

}

Vertex getData (Node *ll) {

	// if(ll == NULL)	return INT_MIN;
	return ll->v;

}

Node * getFront (List *list) {

	if(isEmpty(list))	return NULL;
	return list->front;

}

Node * getrear (List *list) {

	if(isEmpty(list))	return NULL;
	return list->rear;

}

void clear (List *list) {

	if (isEmpty(list))	return;

	Node *ll = list->front;
	while(ll != NULL) {
		Node *delLL = ll;
		ll = next(ll);
		delLL->prev = NULL;
		delLL->next = NULL;
		free(delLL);			//deleting each node one by one
	}

}

void reverse(List *list) {

	// if(isEmpty(list))	return NULL;

	Node *ll = list->front;
	Node *t_rear = list->front;
	Node *t = ll;
	do {

		t = ll;
		ll = next(ll);
		/***************
			swapping previous pointer with next pointer
		***************/
		Node *swap = t->prev;
		t->prev = t->next;
		t->next = swap;
		
	} while(ll != NULL);

	list->front = t;
	list->rear = t_rear;
	// return list;

}

int search(List *list, Vertex v) {

	if(isEmpty(list))	return INT_MIN;

	Node *ll = list->front;
	int i;
	for (i = 0; ll != NULL; ll = next(ll), i++) {
		Vertex p = getData(ll);
		if(p.data == v.data) {
			return i;			//return index of element
		}
	}
	return INT_MIN;
}

bool contains(List *list, Vertex v) {
	return search(list, v) != INT_MIN;		//search if element is 
											//present in the list
}

/* 
	How to traverse through linked list
*/
/*
Node *p = getFront(list);
	while(p != NULL) {
		printf("data = %d\n", getData(p));
		p = next(p);
	}
*/