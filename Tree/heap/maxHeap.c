#include "heap.h"
#include <stdlib.h>

heap* makeHeap(HEAPTYPE type) {
	heap *h = calloc(1, sizeof(heap));
	h->type = type;
	return h;
}

void deleteHeap(heap *h) {
	free(h);
}

void insertMaxHeap (heap *h, element data) {
	if (h->type != MAX) {
		printf("Error: insertMaxHeap() is called for min heap.\n");
		return;
	}
	if (h->size == MAX_SIZE - 1) {
		printf("heap is full\n");
		return;
	}
	++h->size;
	int i = h->size;
	while (i > 1 && h->heap[i / 2].key < data.key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = data;
}

element deleteMaxHeap(heap *h) {
	if (h->type != MAX) {
		printf("Error: deleteMaxHeap() is called for min heap.\n");
		return (element){0};
	}
	if (h->size == 0) {
		printf("heap is empty\n");
		return (element){0};
	}
	int i = h->size;
	element result = h->heap[1];
	element temp = h->heap[i];
	--h->size;
	int parent = 1;
	int child = 2;
	while (child <= h->size) {
		if (child < h->size && h->heap[child].key < h->heap[child + 1].key) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return result;
}

void insertMinHeap(heap *h, element data) {
	if (h->type != MIN) {
		printf("Error: insertMinHeap() is called for max heap.\n");
		return;
	}
	if (h->size == MAX_SIZE - 1) {
		printf("heap is full\n");
		return;
	}
	++h->size;
	int i = h->size;
	while (i > 1 && h->heap[i / 2].key > data.key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = data;
}

element deleteMinHeap(heap *h) {
	if (h->type != MIN) {
		printf("Error: deleteMinHeap() is called for max heap.\n");
		return (element){0};
	}
	if (h->size == 0) {
		printf("heap is empty\n");
		return (element){0};
	}
	int i = h->size;
	element result = h->heap[1];
	element temp = h->heap[i];
	--h->size;
	int parent = 1;
	int child = 2;
	while (child >= h->size) {
		if (child < h->size && h->heap[child].key > h->heap[child + 1].key) {
			child++;
		}
		if (temp.key <= h->heap[child].key) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return result;
}

int main(void) {
	heap *maxHeap = makeHeap(MAX);

	insertMaxHeap(maxHeap, (element){.key = 1});
	insertMaxHeap(maxHeap, (element){.key = 5});
	insertMaxHeap(maxHeap, (element){.key = 9});
	insertMaxHeap(maxHeap, (element){.key = 2});
	insertMaxHeap(maxHeap, (element){.key = 4});
	insertMaxHeap(maxHeap, (element){.key = 6});

	for (int i = 1; i <= maxHeap->size; i++) {
		printf("%d ", maxHeap->heap[i].key);
	}
	printf("\n");

	while (maxHeap->size > 0) {
		element temp = deleteMaxHeap(maxHeap);
		printf("%d\n", temp.key);
	}

	heap *minHeap = makeHeap(MIN);

	insertMinHeap(minHeap, (element){.key = 1});
	insertMinHeap(minHeap, (element){.key = 5});
	insertMinHeap(minHeap, (element){.key = 9});
	insertMinHeap(minHeap, (element){.key = 2});
	insertMinHeap(minHeap, (element){.key = 4});
	insertMinHeap(minHeap, (element){.key = 6});

	for (int i = 1; i <= minHeap->size; i++) {
		printf("%d ", minHeap->heap[i].key);
	}
	printf("\n");

	while (minHeap->size > 0) {
		element temp = deleteMinHeap(minHeap);
		printf("%d\n", temp.key);
	}


}