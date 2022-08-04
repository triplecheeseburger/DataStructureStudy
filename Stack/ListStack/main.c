#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *reverseString(char *str);
bool checkBracketMatching(char *str);
int reversePolishNotationCalc(char *str);

void displayStack(LinkedStack* pStack)
{
	printf("====start====\n");
	StackNode* node = pStack->pTopElement;
	while (node != NULL)
	{
		printf("%c ", node->data);
		node = node->pLink;
	}
	printf("\n=====end=====\n");
}

void basicTest(void) {
	LinkedStack* pStack = createLinkedStack();
	pushLS(pStack, (StackNode){'1', NULL});
	pushLS(pStack, (StackNode){'2', NULL});
	pushLS(pStack, (StackNode){'3', NULL});
	pushLS(pStack, (StackNode){'4', NULL});
	pushLS(pStack, (StackNode){'5', NULL});
	displayStack(pStack);
	while (!isLinkedStackEmpty(pStack))
	{
		StackNode* tmp = popLS(pStack);
		printf("\nI popped %c\n\n", tmp->data);
		free(tmp);
		tmp = NULL;
		displayStack(pStack);
	}
	deleteLinkedStack(pStack);
}

void reverseStringTest(void) {
	char *str = strdup("Hello World");
	printf("%s\n", reverseString(str));
	free(str);
}

void bracketTest(void) {
	char group[5][25] = {"((()))", "{}{}()[]", "{([]){}{()}({})}", "(((()))", "{{(})}[]"};
	for (int i = 0; i < 4; i++) {
		printf("%s: ", group[i]);
		checkBracketMatching(group[i]) ? printf("Good\n") : printf("Bad\n");
	}
	printf("%s: ", group[4]);
	checkBracketMatching(group[4]) ? printf("Good\n") : printf("Bad\n");
}

void reversePolishNotationTest(void) {
	printf("1 + 2 * 3 (1 2 3 * +) = %d, expected = 7\n", reversePolishNotationCalc("1 2 3 * +")); // 1 + 2 * 3
	printf("2 * 4 (2 4 *) = %d, expected = 8\n", reversePolishNotationCalc("2 4 *")); // 2 * 4
	printf("9 - ( 2 + 3 ) * 2 (9 2 3 + 2 * -) = %d, expected = -1\n", reversePolishNotationCalc("9 2 3 + 2 * -")); // 9 - ( 2 + 3 ) * 2
}

int main(void) {
	basicTest();
	printf("\n\n====reverse string test====\n\n");
	reverseStringTest();
	printf("\n\n====bracket test====\n\n");
	bracketTest();
	printf("\n\n====reverse polish notation test====\n\n");
	reversePolishNotationTest();
	printf("\n\n====end====\n\n");
	system("leaks Stack");
	return (0);
}