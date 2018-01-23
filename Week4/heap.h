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

int delete(int *);

void display(int *);

#endif