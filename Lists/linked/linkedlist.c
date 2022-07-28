#include "linkedlist.h"
#include <stdlib.h>

LinkedList* createLinkedList()
{
	return ((LinkedList*)calloc(1, sizeof(LinkedList)));
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	if (pList == NULL || position < 0)
		return (FALSE);

	ListNode* tmp_element = calloc(1, sizeof(ListNode));
	ListNode* tmp;

	tmp_element->data = element.data;
	tmp_element->pLink = NULL;
	if (position > pList->currentElementCount)
		position = pList->currentElementCount;
	ListNode* cur = getLLElement(pList, position - 1);
	tmp = cur->pLink;
	cur->pLink = tmp_element;
	tmp_element->pLink = tmp;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	if (pList == NULL || position < 0)
		return (FALSE);
	if (pList->currentElementCount == 0 || pList->currentElementCount <= position)
		return (FALSE);
	ListNode *tmp;
	ListNode* cur = getLLElement(pList, position - 1);
	tmp = cur->pLink;
	cur->pLink = cur->pLink->pLink;
	free(tmp);
	tmp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	if (pList == NULL)
		return (NULL);
	if (pList->currentElementCount <= position)
		return (NULL);

	ListNode* cur;
	int index;

	cur = &pList->headerNode;
	index = -1;
	while (index++ < position)
		cur = cur->pLink;
	return (cur);
}

void clearLinkedList(LinkedList* pList)
{
	ListNode* curr;
	ListNode* tmp;

	curr = pList->headerNode.pLink;
	while(curr)
	{
		curr->data = 0;
		tmp = curr->pLink;
		free(curr);
		curr = tmp;
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}