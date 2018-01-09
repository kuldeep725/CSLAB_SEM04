/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// typedef struct Node {

// 	int data;
// 	struct Node *next;
// 	struct Node *prev;
	
// } Node;

class Node {

	int data;
	Node *nextPtr;
	Node *prevPtr;
	friend class LinkedList;

	public :
		/*
			to go to the previous pointer
		*/
		Node * prev ();

		/*
			to go to the next pointer
		*/
		Node * next ();

		/*
			to get the data of the given pointer
		*/
		int getData ();
	
};

class LinkedList {

	Node *front;
	Node *rear;
	int length;

	public :
		/*
			constructor to create an empty linked list 
		*/
		// LinkedList getList(LinkedList);
		LinkedList();

		/*
			destructor to free all the memory
		*/
		~LinkedList();
		/*
			to push an element at the end of the list
		*/
		void push(int);

		/*
			to pop/delete the last element in the list
		*/
		int pop();

		/*
			to push an element at the front of the list
		*/
		void pushFront(int );

		/*
			to pop an element from the front in the list
		*/
		int popFront();
		/*
			to get the last element in the list
		*/
		int last ();

		/*
			to get the first element in the list
		*/
		int first ();

		/*
			to check if the list is empty 
		*/
		bool isEmpty();

		/*
			to get the size of the list
		*/
		int size();

		/*
			to get the pointer to the first position in the list
		*/
		Node * getFront ();

		/*
			to get the pointer to the last position in the list
		*/
		Node * getRear ();

		/*
			to reverse the elements in the list and return the list
		*/
		void reverse();
		/*
			*	to search an element in the list and return its index
				in the list
			*	return INT_MIN if list is empty or element doesn't
				exist in the list
		*/
		int indexOf(int);

		/*
			check if element exists in the list or not
		*/
		bool contains(int);

};

#endif