#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* createArrayStack(int size) {
	ArrayStack* pStack = (ArrayStack*)calloc(1, sizeof(ArrayStack));
	pStack->maxElementCount = size;
	pStack->pElement = calloc(size, sizeof(StackNode));
	pStack->top = -1;
	return (pStack);
}

int pushAS(ArrayStack* pStack, StackNode element) {
	if (pStack == NULL) {
		return (FALSE);
	}
	if (pStack->currentElementCount == pStack->maxElementCount) {
		return (FALSE);
	}
	++pStack->top;
	pStack->pElement[pStack->top] = element;
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

void displayStack(ArrayStack * pStack)
{
	printf("====start====\n");
	int i = pStack->top;
	while (i >= 0)
	{
		printf("%c ", pStack->pElement[i].data);
		--i;
	}
	printf("\n=====end=====\n");
}

int main(void) {
	ArrayStack * pStack = createArrayStack(4);
	pushAS(pStack, (StackNode){'1'});
	pushAS(pStack, (StackNode){'2'});
	pushAS(pStack, (StackNode){'3'});
	pushAS(pStack, (StackNode){'4'});
	pushAS(pStack, (StackNode){'5'}) ? printf("push success\n") : printf("push fail\n");
	displayStack(pStack);
	while (!isArrayStackEmpty(pStack))
	{
		StackNode* tmp = popAS(pStack);
		printf("\nI popped %c\n\n", tmp->data);
		displayStack(pStack);
	}
	deleteArrayStack(pStack);
	system("leaks ArrayStack");
}