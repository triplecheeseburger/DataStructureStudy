#include "ListStack/linkedstack.h"
#include <stdlib.h>

char *reverseString(char *str) {
	LinkedStack* pStack = createLinkedStack();
	StackNode* node;

	int i = 0;
	while (str[i] != '\0') {
		pushLS(pStack, (StackNode){str[i], NULL});
		++i;
	}
	i = 0;
	while (!isLinkedStackEmpty(pStack)) {
		node = popLS(pStack);
		str[i] = node->data;
		free(node);
		++i;
	}
	deleteLinkedStack(pStack);
	return (str);
}

