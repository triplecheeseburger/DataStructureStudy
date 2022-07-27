#include "array/arraylist.h"
#include "linked/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

static void displayLinkedList(LinkedList* lst)
{
	ListNode *node;
	int 	i;
	
	i = 0;
	node = lst->headerNode.pLink;
	printf("====print start====\n");
	while(node && i < lst->currentElementCount)
	{	
		printf("element no %d: %d\n", i, node->data);
		i++;
		node = node->pLink;
	}
	printf("current: %d\n", getLinkedListLength(lst));
	printf("=====print end=====\n\n");
}

void linkedListMain(void)
{
	LinkedList *lst;

	printf("\n\nLinkedList Start");
	printf("create LinkedList\n");
	lst = createLinkedList();
	displayLinkedList(lst);

	printf("ADD LinkedList\n");
	addLLElement(lst, 99, (ListNode){10, NULL});
	displayLinkedList(lst);

	for (int i = 0; i < 10; i++) {
		addLLElement(lst, i, (ListNode){i, NULL});
		displayLinkedList(lst);
	}

	for (int i = 11; i < 21; i++) {
		addLLElement(lst, 2, (ListNode){i, NULL});
		displayLinkedList(lst);
	}

	printf("REMOVE LinkedList\n");
	removeLLElement(lst, 99);
	displayLinkedList(lst);

	for (int i = 0; i < 10; i++) {
		removeLLElement(lst, 2);
		displayLinkedList(lst);
	}

	removeLLElement(lst, 7);
	displayLinkedList(lst);

	removeLLElement(lst, 0);
	displayLinkedList(lst);

	removeLLElement(lst, -1);
	displayLinkedList(lst);

	displayLinkedList(lst);

	printf("clear list\n");
	clearLinkedList(lst);
	displayLinkedList(lst);

	printf("remove empty lst\n");
	removeLLElement(lst, 0);
	displayLinkedList(lst);

	printf("add elements again in empty lst\n");
	for (int i = 11; i < 21; i++)
	{
		addLLElement(lst, 2, (ListNode){i, NULL});
		displayLinkedList(lst);
	}

	for (int i = 0; i < getLinkedListLength(lst); i++)
	{
		printf("get no %d element: %d\n", i, getLLElement(lst, i)->data);
	}

	printf("get unreachable element: %p\n\n", getLLElement(lst, 99));
	printf("delete list\n");
	deleteLinkedList(lst);
}

int main(void)
{
	linkedListMain();
	system("leaks linked");
	return (0);
}

