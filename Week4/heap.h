/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009

*/
#ifndef HEAP_H
#define HEAP_H

void swim(int *, int, int);

void minHeapify(int *, int);

void swap(int *, int, int);

void buildHeap(int *, int);

void insert(int *, int);

int deleteMin(int *);

void push(char);

void pop();

void print(int *, int);

void display(int *);

void heapSort(int *);

#endif