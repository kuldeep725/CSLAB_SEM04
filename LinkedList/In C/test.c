#include<stdio.h>
#include"LinkedList.h"

int main() {

	List *list = getList(list);
	printf("before : %s\n", isEmpty(list)  ? "true" : "false");
	push(list, 1);
	push(list, 2);
	push(list, 3);
	push(list, 4);
	List *listNew = getList(listNew);
	push(listNew, 15);
	push(listNew, 6);
	push(listNew, 7);
	push(listNew, 8);
	push(listNew, 19);
	// while(!isEmpty(list)) {
	// 	list.pop();
	// }
	printf("after : %s\n", isEmpty(list)  ? "true" : "false");
	printf("list->last = %d ", last(list));
	printf("list->first = %d\n", first(list));
	printf("listNew->last = %d ", last(listNew));
	printf("listNew->first = %d\n", first(listNew));
	printf("size(list) = %d\n", size(list));
	printf("size(listNew) = %d\n", size(listNew));
	pushFront(list, 10);
	pushFront(list, 20);
	pushFront(list, 30);
	pushFront(list, 40);
	printf("after : %s\n", isEmpty(list)  ? "true" : "false");
	printf("list->last = %d ", last(list));
	printf("list->first = %d\n", first(list));
	printf("listNew->last = %d ", last(listNew));
	printf("listNew->first = %d\n", first(listNew));
	printf("size(list) = %d\n", size(list));
	printf("size(listNew) = %d\n", size(listNew));
	
	int indexOf = search(list, 10);
	int indexOf2 = search(list, 3);
	int indexOf3 = search(list, 40);
	// int indexOf4 = search(list, 121);
	// printf("%d %d %d %d\n", indexOf, indexOf2, indexOf3, indexOf4);
	printf("%s, %s\n", contains(list, 5) ? "true":"false", contains(list, 10) ? "true":"false");
	List *reverseList = reverse(list);

	// p = getEnd(list);
	// while(p != NULL) {
	// 	printf("ReverseData = %d\n", getData(p));
	// 	p = prev(p);
	// }
	// while(!isEmpty(list)) {
	// 	printf("%d ", pop(list));
	// }
	while(!isEmpty(reverseList)) {
		printf("%d ", popFront(reverseList));
	}
	printf("\n");
	clear(list);
	printf("after clear : %s\n", isEmpty(list)  ? "true" : "false");
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