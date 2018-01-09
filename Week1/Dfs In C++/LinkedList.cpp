#include<iostream>
#include<cstdbool>
#include<climits>
#include"LinkedList.h"

using namespace std;


LinkedList::LinkedList() {

	this->front = nullptr;
	this->rear = nullptr;
	this->length = 0;

}

LinkedList::~LinkedList() {

	// while(!isEmpty()) {
	// 	popFront();
	// }

}
void LinkedList::push(int ele) {

	Node *p = new Node();
	p->data = ele;
	p->nextPtr = nullptr;
	// cout<<"length = "<<this->length<<endl;
	// cout<<"length = "<<length<<endl;
	if(isEmpty()) {

		// cout<<"rear is null"<<endl;
		p->prevPtr = nullptr;
		rear = p;
		front = p;
		// cout<<"rear->data = "<<rear->data<<endl;
		// cout<<"front->data = "<<front->data<<endl;
	}
	else {
		// cout<<"rear is not null"<<endl;
		p->prevPtr = rear;
		rear->nextPtr = p;
		rear = p;
		// cout<<"rear->data = "<<rear->data<<endl;
		// cout<<"front->data = "<<front->data<<endl;
	}

	length++;

}

int LinkedList::pop() {

	if(isEmpty())	return 	INT_MIN;

	Node *p = rear;
	int ele = p->data;
	rear = rear->prevPtr;
	if(rear != nullptr)		rear->nextPtr = nullptr;
	else 					front = nullptr;
	p->nextPtr = nullptr;
	p->prevPtr = nullptr;
	delete p;
	length--;
	return ele;

}

void LinkedList::pushFront(int ele) {

	Node *p = new Node();
	p->data = ele;
	p->prevPtr = nullptr;
	if(isEmpty()) {
		p->nextPtr = nullptr;
		front = p;
		rear = p;
	}
	else {
		p->nextPtr = front;
		front->prevPtr = p;
		front = p;
	}
	length++;

}

int LinkedList::popFront() {

	if(isEmpty())	return 	INT_MIN;

	Node *p = front;
	int ele = p->data;
	front = front->nextPtr;
	if(front != nullptr)	front->prevPtr = nullptr;
	else 					rear = nullptr;
	p->prevPtr = nullptr;
	p->nextPtr = nullptr;
	delete p;
	length--;
	return ele;

}

int LinkedList::last() {
	return rear->data;
}

int LinkedList::first() {
	return front->data;
}

bool LinkedList::isEmpty() {
	return length == 0;
}

int LinkedList::size() {
	return length;
}

Node * Node::prev() {
	return this->prevPtr;
}

Node * Node::next() {
	return this->nextPtr;
}

int Node::getData() {
	return this->data;
}

Node * LinkedList::getFront() {
	return this->front;
}

Node *LinkedList::getRear() {
	return this->rear;
}

void LinkedList::reverse() {

	if(this->isEmpty())	return;

	Node *node = front;
	Node *t_rear = front;
	Node *t;

	do {

		t = node;
		node = node->next();
		Node *swap = t->prevPtr;
		t->prevPtr = t->nextPtr;
		t->nextPtr = swap;

	} while(node != nullptr);

	front = t;
	rear = t_rear;
	return;

}

int LinkedList::indexOf(int ele) {

	if(isEmpty())	return -1;

	Node *node = front;

	for(int i = 0; node != nullptr; node = node->next(),i++) {
		if(node->getData() == ele) 
			return i;
	}
	return -1;

}

bool LinkedList::contains(int ele) {
	return indexOf(ele) != -1;
}



