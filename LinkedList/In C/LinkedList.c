/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include "LinkedList.h"

/*
	to create and return an empty linked list 
*/
void getList(List list) {

	// list.data = INT_MIN;
	// list.prev = NULL;
	// list.next = NULL;
	list.front = NULL;
	list.rear = NULL;
	list.length = 0;
	// return list;

}

void push(List list, int ele) {

	Node *p = (Node *) malloc(sizeof(List));
	p->data = ele;
	if(list.rear == NULL) {
		printf("%s\n", "list.rear==null");
		p->prev = NULL;
		p->next = NULL;
		list.rear = p;
		list.front = p;
	}
	else {
		printf("%s\n", "rear!=null");
		p->prev = list.rear;
		p->next = NULL;
		list.rear->next = p;
		list.rear = p;
	}
	list.length++;

}

int pop(List list) {

	if(isEmpty(list))	return INT_MIN;

	Node *p = list.rear;
	// printf("list.rear = %d\n", p->data);
	int ele = p->data;
	list.rear = list.rear->prev;
	if(list.rear != NULL)	list.rear->next = NULL;
	p->prev = NULL;
	p->next = NULL;
	free(p);
	if(list.rear == NULL)		list.front = NULL;
	list.length--;
	return ele;

}

void pushFront(List list, int ele) {

	if(isEmpty(list))	return;

	Node *p = (Node *) malloc(sizeof(List));
	p->data = ele;
	if (list.front == NULL) {
		p->prev = NULL;
		p->next = NULL;
		list.front = p;
		list.rear = p;
	}
	else {
		p->prev = NULL;
		p->next = list.front;
		list.front->prev = p;
		list.front = p;
	}
	list.length++;
}

int popFront(List list) {

	if(isEmpty(list))	return INT_MIN;

	Node *p = list.front;
	int ele = p->data;
	list.front = list.front->next;
	if(list.front != NULL)		list.front->prev = NULL;
	p->prev = NULL;
	p->next = NULL;
	free(p);
	list.length--;
	return ele;
}

int last (List list) {

	if(isEmpty(list))	return INT_MIN;
	return list.rear->data;

}

int first (List list) {

	if(isEmpty(list))	return INT_MIN;
	return list.front->data;

}

bool isEmpty(List list) {

	return list.length == 0;

}

int size(List list) {

	if(isEmpty(list))	return INT_MIN;
	return list.length;

}

Node * prev (Node *p) {

	if(p == NULL)	return NULL;
	return p->prev;

}

Node * next (Node *p) {

	if(p == NULL)	return NULL;
	return p->next;

}

int getData (Node *ll) {

	if(ll == NULL)	return INT_MIN;
	return ll->data;

}

Node * getFront (List list) {

	if(isEmpty(list))	return NULL;
	return list.front;

}

Node * getRear (List list) {

	if(isEmpty(list))	return NULL;
	return list.rear;

}

void clear (List list) {

	if (isEmpty(list))	return;

	Node *ll = list.front;
	while(ll != NULL) {
		Node *delLL = ll;
		ll = next(ll);
		delLL->prev = NULL;
		delLL->next = NULL;
		free(delLL);
	}
	free(ll);

}

List reverse(List list) {

	if(isEmpty(list))	return list;

	Node *ll = list.front;
	Node *t_rear = list.front;
	Node *t = ll;
	// Node *first = list.front;
	// Node *last = list.last;
	do {

		t = ll;
		ll = next(ll);
		Node *swap = t->prev;
		t->prev = t->next;
		t->next = swap;
		// swap(t->prev, t->next);
		
	} while(ll != NULL);

	list.front = t;
	list.rear = t_rear;
	return list;

}

int search(List list, int ele) {

	if(isEmpty(list))	return INT_MIN;

	Node *ll = list.front;
	int i;
	// printf("ele = %d\n", ele);
	for (i = 0; ll != NULL; ll = next(ll), i++) {
		if(getData(ll) == ele) {
			return i;
		}
		// printf("getData(ll) = %d\n", getData(ll));
	}
	return INT_MIN;
}

bool contains(List list,int ele) {
	return search(list, ele) != INT_MIN;
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
