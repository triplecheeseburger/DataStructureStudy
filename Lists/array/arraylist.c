#include "arraylist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* arr;

	arr = (ArrayList*) calloc(1 ,sizeof(ArrayList));
	arr->maxElementCount = maxElementCount;
	arr->currentElementCount = 0;
	arr->pElement = (ArrayListNode*) calloc(maxElementCount, sizeof(ArrayListNode));

	return (arr);
}

void deleteArrayList(ArrayList* pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (position >= pList->maxElementCount || isArrayListFull(pList))
		return (FALSE);
	// pos <= current
	if (position <= pList->currentElementCount)
	{
		memmove((&pList->pElement[position] + 1), &pList->pElement[position], (pList->currentElementCount - position) * sizeof(ArrayListNode));
		pList->pElement[position] = element;
	}
	else // pos > current
		pList->pElement[pList->currentElementCount] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int removeALElement(ArrayList* pList, int position)
{
	if (position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	memmove((&pList->pElement[position]), &pList->pElement[position] + 1, (pList->currentElementCount - position - 1) * sizeof(ArrayListNode));
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (position >= pList->currentElementCount)
		return (0);
	return (&pList->pElement[position]);
}

void displayArrayList(ArrayList* pList)
{
	printf("====print start====\n");
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("element no %d: %d\n", i, pList->pElement[i].data);
	printf("current: %d, max: %d\n", pList->currentElementCount, pList->maxElementCount);
	printf("=====print end=====\n\n");
}

void clearArrayList(ArrayList* pList)
{
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	return pList->currentElementCount;
}
