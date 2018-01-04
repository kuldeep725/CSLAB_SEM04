#include<stdio.h>
#include"LinkedList.h"

int main() {

	LinkedList *list = getLinkedList(list);
	// printf("before : %s\n", isEmpty(list)  ? "true" : "false");
	// printf("%d\n", list->data);
	push(list, 1);
	push(list, 2);
	push(list, 3);
	push(list, 4);
	LinkedList *listNew = getLinkedList(listNew);
	push(listNew, 15);
	push(listNew, 6);
	push(listNew, 7);
	push(listNew, 8);
	push(listNew, 19);
	// while(!isEmpty(list)) {
	// 	list.pop();
	// }
	// printf("after : %s\n", isEmpty(list)  ? "true" : "false");
	printf("list->last = %d ", last(list));
	printf("list->first = %d\n", first(list));
	printf("listNew->last = %d ", last(listNew));
	printf("listNew->first = %d\n", first(listNew));
	printf("size(list) = %d\n", size(list));
	printf("size(listNew) = %d\n", size(listNew));
	LinkedList *p = getFront(list);
	while(p != NULL) {
		printf("data = %d\n", getData(p));
		p = next(p);
	}
	while(!isEmpty(list)) {
		printf("%d ", pop(list));
	}
	printf("\n");
	// pop(list);
	// pop(list);
	// pop(listNew);
	// printf("\n");
	// printf("list->last = %d ", last(list));
	// printf("list->first = %d\n", first(list));
	// printf("listNew->last = %d ", last(listNew));
	// printf("listNew->first = %d\n", first(listNew));
	// printf("size(list) = %d\n", size(list));
	// printf("size(listNew) = %d\n", size(listNew));
	return 0;

}