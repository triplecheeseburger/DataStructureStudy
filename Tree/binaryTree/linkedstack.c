#include "linkedstack.h"
#include <stdlib.h>

LinkedStack* createLinkedStack() {
	return (calloc(1, sizeof(LinkedStack)));
}

int pushLS(LinkedStack* pStack, StackNode element) {
	if (pStack == NULL)
		return (FALSE);
	StackNode* tmp_element = malloc(sizeof(StackNode));
	tmp_element->data = element.data;
	tmp_element->pLink = pStack->pTopElement;
	pStack->pTopElement = tmp_element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack) {
	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	StackNode* tmp = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	tmp->pLink = NULL;
	pStack->currentElementCount--;
	return (tmp);
}

StackNode* peekLS(LinkedStack* pStack) {
	if (pStack == NULL)
		return (NULL);
	if (pStack->currentElementCount == 0)
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack) {
	if (pStack == NULL)
		return ;
	StackNode* tmp;
	while (pStack->pTopElement != NULL) {
		tmp = popLS(pStack);
		free(tmp);
		tmp = NULL;
	}
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack) {
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack) {
	return (pStack->currentElementCount == 0);
}

