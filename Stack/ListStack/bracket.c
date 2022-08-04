#include "ListStack/linkedstack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool deleteAndIsMatching(LinkedStack *pStack, bool isMatching) {
	deleteLinkedStack(pStack);
	return (isMatching);
}

bool checkBracketMatching(char *str) {
	LinkedStack* pStack = createLinkedStack();
	char* openBracket = "([{";
	char* closeBracket = ")]}";

	int i = 0;
	while (str[i] != '\0') {
		if (strchr(openBracket, str[i]) != NULL) {
			pushLS(pStack, (StackNode){str[i], NULL});
		} else if (strchr(closeBracket, str[i]) != NULL) {
			StackNode* node = popLS(pStack);
			char tmp;
			if (node == NULL) {
				return (deleteAndIsMatching(pStack, false));
			}
			tmp = node->data;
			free(node);
			if (!(str[i] - tmp == 1 || str[i] - tmp == 2)) {
				return (deleteAndIsMatching(pStack, false));
			}
		}
		++i;
	}
	if (isLinkedStackEmpty(pStack)) {
		return (deleteAndIsMatching(pStack, true));
	} else {
		return (deleteAndIsMatching(pStack, false));
	}
}