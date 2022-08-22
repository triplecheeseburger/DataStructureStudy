#ifndef TREE_HEAP_H
#define TREE_HEAP_H

#include<stdio.h>
#define MAX_SIZE 101

typedef enum {
	MIN, MAX
} HEAPTYPE;

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_SIZE];
	int size;
	HEAPTYPE type;
} heap;

heap* makeHeap(HEAPTYPE type);
void deleteHeap(heap *h);
void insertMaxHeap(heap *h, element data);
element deleteMaxHeap(heap *h);
void insertMinHeap(heap *h, element data);
element deleteMinHeap(heap *h);


#endif //TREE_HEAP_H
