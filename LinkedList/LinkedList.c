/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include"LinkedList.h"

/*
	to create and return an empty linked list 
*/
LinkedList * getLinkedList(LinkedList *list) {

	list = (LinkedList *) malloc(sizeof(LinkedList));
	// list->data = INT_MIN;
	// list->prev = NULL;
	// list->next = NULL;
	list->front = NULL;
	list->end = NULL;
	list->length = 0;
	return list;

}

void push(LinkedList *list, int ele) {

	if(list == NULL)	return;		//checking whether list is NULL

	if(list->end == NULL) {
		// printf("%s\n", "list->end==null");
		list->end = list;
		list->end->data = ele;
		list->front = list->end;
		list->prev = NULL;
		list->next = NULL;
	}
	else {
		// printf("%s\n", "end!=null");
		LinkedList *p = (LinkedList *) malloc(sizeof(LinkedList));
		p->data = ele;
		p->prev = list->end;
		p->next = NULL;
		list->end->next = p;
		list->end = p;
	}
	list->length++;

}

int pop(LinkedList *list) {

	if(isEmpty(list))	return INT_MIN;

	LinkedList *p = list->end;
	// printf("list->end = %d\n", p->data);
	int ele = p->data;
	list->end = list->end->prev;
	if(list->end != NULL)	list->end->next = NULL;
	p->prev = NULL;
	p->next = NULL;
	free(p);
	if(list->end == NULL)		list->front = NULL;
	list->length--;
	return ele;

}

int last (LinkedList *list) {

	if(isEmpty(list))	return INT_MIN;
	return list->end->data;

}

int first (LinkedList *list) {

	if(isEmpty(list))	return INT_MIN;
	return list->front->data;

}

bool isEmpty(LinkedList *list) {

	if(list == NULL) {
		printf("list is null\n");
	}
	else {
		printf("list->length = %d\n", list->length);
	}
	if(list == NULL || list->length <= 0)	return false;
	return list->front == NULL;
}

int size(LinkedList *list) {

	if(isEmpty(list))	return INT_MIN;
	return list->length;

}

LinkedList * next (LinkedList *p) {

	if(p == NULL)	return NULL;
	return p->next;

}

int getData (LinkedList *list) {

	if(isEmpty(list))	return INT_MIN;
	printf("Giving data\n");
	return list->data;

}

LinkedList * getFront (LinkedList *list) {

	if(isEmpty(list))	return NULL;
	return list->front;

}

LinkedList * getEnd (LinkedList *list) {

	if(isEmpty(list))	return NULL;
	return list->end;

}
