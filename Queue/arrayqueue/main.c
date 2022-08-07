#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void displayQueue(ArrayQueue* pQueue)
{
	int i;
	printf("front: %d, rear: %d\n[", pQueue->front, pQueue->rear);
	for (i = 0; i < pQueue->currentElementCount; i++) {
		int index = (pQueue->front + i + 1) % pQueue->maxElementCount;
		printf("%c", pQueue->pElement[index].data);
		if (i != pQueue->currentElementCount - 1) {
			printf(", ");
		}
	}
	printf("]\n\n");
}

int main()
{
	ArrayQueue *pQueue = createArrayQueue(SIZE);

	printf("Empty Queue\n");
	displayQueue(pQueue);

	for (int i = 0; i < SIZE; i++) {
		printf("Enqueue %d\n", i);
		enqueueAQ(pQueue, (ArrayQueueNode){i + '0'});
		displayQueue(pQueue);
	}

	printf("Full Queue\n");
	enqueueAQ(pQueue, (ArrayQueueNode){'A'}) ? printf("Enqueue Success\n\n") : printf("Enqueue Fail\n\n");

	printf("Peek!\n");
	printf("peek: %c\n\n", peekAQ(pQueue)->data);

	for (int i = 0; i < SIZE / 2; i++) {
		printf("Dequeue!\n");
		ArrayQueueNode *dequeued = dequeueAQ(pQueue);
		printf("dequeued: %c\n", dequeued->data);
		free(dequeued);
		displayQueue(pQueue);
	}

	for (int i = 0; i < SIZE / 2; i++) {
		printf("Enqueue %c\n", 101 - i);
		enqueueAQ(pQueue, (ArrayQueueNode){101 - i});
		displayQueue(pQueue);
	}

	printf("Full Queue\n");
	enqueueAQ(pQueue, (ArrayQueueNode){'A'}) ? printf("Enqueue Success\n\n") : printf("Enqueue Fail\n\n");

	deleteArrayQueue(pQueue);
	system("leaks arrayqueue");
	return 0;
}
