#include "maparraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* createArrayStack(int size) {
	ArrayStack* pStack = (ArrayStack*)calloc(1, sizeof(ArrayStack));
	pStack->maxElementCount = size;
	pStack->pElement = calloc(size, sizeof(StackNode));
	pStack->top = -1;
	return (pStack);
}

int pushAS(ArrayStack* pStack, int x, int y) {
	if (pStack == NULL) {
		return (FALSE);
	}
	if (pStack->currentElementCount == pStack->maxElementCount) {
		return (FALSE);
	}
	++pStack->top;
	pStack->pElement[pStack->top].mp.x = x;
	pStack->pElement[pStack->top].mp.y = y;
	pStack->pElement[pStack->top].mp.direction = 0;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack) {
	if (pStack == NULL) {
		return (NULL);
	}
	if (pStack->top == -1) {
		return (NULL);
	}
	StackNode* node = &pStack->pElement[pStack->top];
	--pStack->top;
	--pStack->currentElementCount;
	return (node);
}

StackNode* peekAS(ArrayStack* pStack) {
	if (pStack == NULL) {
		return (NULL);
	}
	if (pStack->top == -1) {
		return (NULL);
	}
	return (&pStack->pElement[pStack->top]);
}

void deleteArrayStack(ArrayStack* pStack) {
	if (pStack == NULL) {
		return ;
	}
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack) {
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack) {
	return (pStack->currentElementCount == 0);
}
