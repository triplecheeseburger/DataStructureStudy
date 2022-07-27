#include "polylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void displayCoefAndDegree(int place, float coef, int degree)
{
    if (degree == 0)
    {
        if (place == 0)
            printf("%.0f ", coef);
        else
            printf("%.0f ", (float)fabs(coef));
    }
    else
    {
		if (coef == 1)
		{
			printf("x^%d ", degree);
			return ;
		}
        if (place == 0)
            printf("%.0fx^%d ", coef, degree);
        else 
			printf("%.0fx^%d ", (float)fabs(coef), degree);
    }
}

void displayPoly(LinkedList* lst)
{
	ListNode *node;
	int 	i;
	
	i = 0;
	node = lst->headerNode.pLink;
	while(node && i < lst->currentElementCount)
	{
		displayCoefAndDegree(i, node->coef, node->degree);
		i++;
		node = node->pLink;
        if (i != lst->currentElementCount) 
            node->coef >= 0 ? printf("+ ") : printf("- ");
	}
	printf("\n");
}


int	getDegreePosition(LinkedList* pList, int degree)
{
	int position = 0;
    ListNode *curr = pList->headerNode.pLink;

    while (curr != NULL)
	{
        if (degree > curr->degree)
            break ;
        else if (degree == curr->degree)
            return (-position);
        curr = curr->pLink;
        ++position;
	}
    return (position);
}

int plusLLElement(LinkedList* pList, int position, float coef)
{
	ListNode *curr = getLLElement(pList, position);
	curr->coef += coef;
	if (curr->coef == 0)
		return (removeLLElement(pList, position));
    return (TRUE);
}

int addPolyNode(LinkedList* pList, float coef, int degree)
{
	int	ret = FALSE;
	int	i = 0;

	ListNode node = {0,};
    node.coef = coef;
    node.degree = degree;

    if (pList != NULL) 
    {
        int position = getDegreePosition(pList, degree);
        if (position >= 0)
            ret = addLLElement(pList, position, node);
        else
            ret = plusLLElement(pList, -position, coef); 
    }

    return ret;
}

void addTwoPoly(LinkedList* dst, LinkedList* src)
{
	ListNode* curr;

    curr = src->headerNode.pLink;
    while (curr != NULL) 
    {
        addPolyNode(dst, curr->coef, curr->degree);
        curr = curr->pLink;
    }
}

int main()
{
	LinkedList* poly1 = createLinkedList();
		
	addPolyNode(poly1, 3, 1);
	addPolyNode(poly1, -2, 2);
	addPolyNode(poly1, 12, 0);

	

    LinkedList* poly2 = createLinkedList();
    addPolyNode(poly2, 5, 0);
    addPolyNode(poly2, 3, 1);
    addPolyNode(poly2, 2, 2);
    addPolyNode(poly2, 1, 3);

	
	displayPoly(poly1);
    displayPoly(poly2);

	addTwoPoly(poly1, poly2);
	displayPoly(poly1);

	system("leaks poly");
}