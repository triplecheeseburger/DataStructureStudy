#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void displayDeque(LinkedDeque* pDeque)
{
	printf("[");
	DequeNode* cur = pDeque->pFrontNode;
	while (cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->pRLink;
		if (cur != NULL)
		{
			printf(", ");
		}
	}
	printf("]\n\n");
}

int main()
{
	LinkedDeque* pDeque = createLinkedDeque();

	printf("Empty Queue\n");
	displayDeque(pDeque);

	for (int i = 0; i < SIZE; i++) {
		printf("insertFront %c\n", i);
		insertFrontLD(pDeque, (DequeNode){i + '0'});
		displayDeque(pDeque);
	}

	printf("Peek Front!\n");
	printf("peek front: %c\n\n", peekFrontLD(pDeque)->data);
	printf("Peek Rear!\n");
	printf("peek rear: %c\n\n", peekRearLD(pDeque)->data);

	for (int i = 0; i < SIZE / 2; i++) {
		printf("delete Front!\n");
		DequeNode *node = deleteFrontLD(pDeque);
		printf("dequeued: %c\n", node->data);
		free(node);
		displayDeque(pDeque);
	}

	for (int i = 0; i < SIZE / 2; i++) {
		printf("insert Rear %c\n", 101 - i);
		insertRearLD(pDeque, (DequeNode){101 - i});
		displayDeque(pDeque);
	}

	for (int i = 0; i < SIZE / 2; i++) {
		printf("delete Rear!\n");
		DequeNode *node = deleteRearLD(pDeque);
		printf("dequeued: %c\n", node->data);
		free(node);
		displayDeque(pDeque);
	}

	printf("All things gonna mess up\n\n");
	for (int i = 0; i < SIZE; i++) {
		printf("insert Front!\n");
		insertFrontLD(pDeque, (DequeNode){i * 2 + 'a'});
		displayDeque(pDeque);
		printf("delete Rear!\n");
		DequeNode *node = deleteRearLD(pDeque);
		printf("dequeued: %c\n", node->data);
		free(node);
		node = NULL;
		displayDeque(pDeque);
		printf("insert Rear!\n");
		insertRearLD(pDeque, (DequeNode){(i * 2) + 'b'});
		displayDeque(pDeque);
		printf("delete Front!\n");
		node = deleteFrontLD(pDeque);
		printf("dequeued: %c\n", node->data);
		free(node);
		displayDeque(pDeque);
	}

	deleteLinkedDeque(pDeque);
	system("leaks linkeddeque");
	return 0;
}