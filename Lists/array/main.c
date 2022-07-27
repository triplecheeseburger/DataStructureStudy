#include "array/arraylist.h"
#include "linked/linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

void arrayListMain(void)
{
	ArrayList* arr;

	arr = createArrayList(SIZE);
	addALElement(arr, 0, (ArrayListNode){3});
	displayArrayList(arr);
	addALElement(arr, 1, (ArrayListNode){9});
	displayArrayList(arr);
	deleteArrayList(arr);

	arr = createArrayList(SIZE);
	for (int i  = 0; i < SIZE; i++)
	{
		addALElement(arr, i, (ArrayListNode){i});
	}
	displayArrayList(arr);
	printf("is Array Full? ");
	isArrayListFull(arr) ? printf("TRUE\n") : printf("FALSE\n");

	printf("Add Element Successful? ");
	addALElement(arr, 1, (ArrayListNode){9}) ? printf("TRUE\n") : printf("FALSE\n");

	printf("Remove Element Successful? ");
	removeALElement(arr, 4) ? printf("TRUE\n") : printf("FALSE\n");
	displayArrayList(arr);

	//중간 삽입
	printf("Insert in middle Successful?");
	addALElement(arr, 2, (ArrayListNode){42}) ? printf("TRUE\n") : printf("FALSE\n");
	displayArrayList(arr);

	printf("Remove from middle Successful? ");
	removeALElement(arr, 2) ? printf("TRUE\n") : printf("FALSE\n");
	displayArrayList(arr);

	//getALElement Test
	ArrayListNode* node;

	node = getALElement(arr, 2);
	printf("node data: %d\n", node->data);

	node = getALElement(arr, 17);
	printf("node data: %p\n\n", node);

	printf("Before CLEAR Length: %d\n\n", getArrayListLength(arr));
	clearArrayList(arr);
	displayArrayList(arr);
	printf("After CLEAR Length: %d\n", getArrayListLength(arr));

	deleteArrayList(arr);
}

int main(void)
{
	arrayListMain();
	system("leaks array");
	return (0);
}

