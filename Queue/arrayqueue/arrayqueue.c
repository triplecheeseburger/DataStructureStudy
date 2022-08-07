#include "arrayqueue.h"
#include <stdlib.h>

ArrayQueue* createArrayQueue(int maxElementCount) {
	ArrayQueue* queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	queue->maxElementCount = maxElementCount;
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = 0;
	queue->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	return queue;
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
	if (isArrayQueueFull(pQueue)) {
		return FALSE;
	}
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) { // returned node has to be freed by caller
	if (isArrayQueueEmpty(pQueue)) {
		return NULL;
	}
	ArrayQueueNode *element = malloc(sizeof(ArrayQueueNode));
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	*element = pQueue->pElement[pQueue->front];
	pQueue->currentElementCount--;
	return element;
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue) {
	if (isArrayQueueEmpty(pQueue)) {
		return NULL;
	}
	return &pQueue->pElement[pQueue->front];
}

void deleteArrayQueue(ArrayQueue* pQueue) {
	free(pQueue->pElement);
	pQueue->pElement = NULL;
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue) {
	if (pQueue->currentElementCount == pQueue->maxElementCount) {
		return TRUE;
	}
	return FALSE;
}

int isArrayQueueEmpty(ArrayQueue* pQueue) {
	if (pQueue->currentElementCount == 0) {
		return TRUE;
	}
	return FALSE;
}
