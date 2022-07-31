#include "linkedstack.h"
#include <stdlib.h>

char *reverseString(char *str) {
	LinkedStack* pStack = createLinkedStack();
	StackNode* node;

	char* p = str;
	while (*p != '\0') {
		pushLS(pStack, (StackNode){*p, NULL});
		p++;
	}
	p = str;
	while (!isLinkedStackEmpty(pStack)) {
		node = popLS(pStack);
		*p = node->data;
		free(node);
		p++;
	}
	deleteLinkedStack(pStack);
	return (str);
}

