#include "ListStack/linkedstack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char calcWithOperator(char operator, char num1, char num2) {
	switch (operator) {
	case '+':
		return (num1 + num2);
	case '-':
		return (num1 - num2);
	case '*':
		return (num1 * num2);
	case '/':
		if (num2 == 0) {
			perror("Error: Division by zero");
			return (0);
		} else {
			return (num1 / num2);
		}
	default:
		return (0);
	}
}

int inErrorCase(LinkedStack* pStack) {
	perror("Error");
	deleteLinkedStack(pStack);
	return (0);
}

int reversePolishNotationCalc(char *str) {
	LinkedStack* pStack = createLinkedStack();
	char* operators = "+-*/";
	char* numbers = "0123456789";
	char standard = '0';
	int i = 0;

	while (str[i] != '\0') {
		if (strchr(numbers, str[i]) != NULL) {
			pushLS(pStack, (StackNode){str[i], NULL});
		} else if (strchr(operators, str[i]) != NULL) {
			StackNode* num1 = popLS(pStack);
			if (num1 == NULL) {
				return (inErrorCase(pStack));
			}
			StackNode* num2 = popLS(pStack);
			if (num2 == NULL) {
				free(num1);
				return (inErrorCase(pStack));
			}
			char tmp = calcWithOperator(str[i], num1->data - standard, num2->data - standard);
			free(num1);
			free(num2);
			pushLS(pStack, (StackNode){tmp + standard, NULL});
		}
		++i;
	}
	if (pStack->currentElementCount != 1) {
		return (inErrorCase(pStack));
	} else {
		StackNode* node = popLS(pStack);
		if (node == NULL) {
			return (inErrorCase(pStack));
		}
		int result = node->data - standard;
		free(node);
		deleteLinkedStack(pStack);
		return (result);
	}
}