#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList* createDoublyList()
{
    DoublyList* arr = (DoublyList*)malloc(sizeof(DoublyList));
	
	arr->headerNode.pRLink = &arr->headerNode;
	arr->headerNode.pLLink = &arr->headerNode;

	return (arr);
}

void deleteDoublyList(DoublyList* pList)
{
    if (pList == NULL)
        return ;
    clearDoublyList(pList);
    free(pList);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode* new_node;
    DoublyListNode* nextNode;
    DoublyListNode* prevNode;

    if (pList == NULL || position < 0)
        return (FALSE);
    if (position > pList->currentElementCount)
        return (FALSE);

    new_node = (DoublyListNode*) malloc(sizeof(DoublyListNode));
    *new_node = element;
	nextNode = getDLElement(pList, position - 1)->pRLink;
	prevNode = nextNode->pLLink;
    new_node->pLLink = prevNode;
    new_node->pRLink = nextNode;
    prevNode->pRLink = new_node;
    nextNode->pLLink = new_node;
	pList->currentElementCount++;

    return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{

    if (pList == NULL || position < 0)
        return (FALSE);
	if (position >= pList->currentElementCount)
        return (FALSE);

    DoublyListNode* posNode = getDLElement(pList, position);
    DoublyListNode* prevNode = posNode->pLLink;
    DoublyListNode* nextNode = posNode->pRLink;
    //connect prev next
    prevNode->pRLink = nextNode;
    nextNode->pLLink = prevNode;
    //remove posNode
    posNode->data = 0;
    free(posNode);
    posNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
    if (pList == NULL)
        return ;
    while (pList->currentElementCount > 0)
        removeDLElement(pList, 0);
}

int getDoublyListLength(DoublyList* pList)
{
    if(!pList)
        return (FALSE);
    return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	int idx = 0;
	DoublyListNode* curr;
	if (pList == NULL || position < -1)
		return (NULL);
	if (position == -1)
		return (&pList->headerNode);
    if (position >= pList->currentElementCount)
        return (NULL);
	if (position < (pList->currentElementCount / 2))
    {
		curr = pList->headerNode.pRLink;
		while (idx++ < position)
			curr = curr->pRLink;
    }
	else
    {
        curr = pList->headerNode.pLLink;
        while (idx++ < pList->currentElementCount - 1 - position)
            curr = curr->pLLink;
    }
	return (curr);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	int 	i;

	if (pList == NULL) {
		printf("List is empty\n");
		return;
	}
	i = 0;
	node = pList->headerNode.pRLink;
	printf("====print start====\n");
	while(node && i < pList->currentElementCount)
	{	
		printf("element no %d: %d\n", i, node->data);
		node = node->pRLink;
		i++;
	}
	printf("current: %d\n", getDoublyListLength(pList));
	printf("=====print end=====\n\n");
}