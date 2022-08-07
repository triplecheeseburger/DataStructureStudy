#include "linkeddeque.h"
#include <stdlib.h>

LinkedDeque* createLinkedDeque() {
	return (calloc(1, sizeof(LinkedDeque)));
}

static int emptyDequeInsertion(LinkedDeque* pDeque, DequeNode element) {
	DequeNode* new = calloc(1, sizeof(DequeNode));
	if (new == NULL) {
		return FALSE;
	}
	new->data = element.data;
	pDeque->pFrontNode = new;
	pDeque->pRearNode = new;
	pDeque->currentElementCount = 1;
	return TRUE;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element) {
	if (isLinkedDequeEmpty(pDeque)) {
		return emptyDequeInsertion(pDeque, element);
	}
	DequeNode *new = calloc(1, sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pRLink = pDeque->pFrontNode;
	pDeque->pFrontNode->pLLink = new;
	pDeque->pFrontNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element) {
	if (isLinkedDequeEmpty(pDeque)) {
		return emptyDequeInsertion(pDeque, element);
	}
	DequeNode *new = calloc(1, sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pLLink = pDeque->pRearNode;
	pDeque->pRearNode->pRLink = new;
	pDeque->pRearNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

static DequeNode* deleteLastNode(LinkedDeque *pDeque) {
	DequeNode *last = pDeque->pRearNode;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	pDeque->currentElementCount = 0;
	last->pLLink = NULL;
	last->pRLink = NULL;
	return last;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	if (pDeque->currentElementCount == 1) {
		return deleteLastNode(pDeque);
	}
	DequeNode* pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	pReturn->pRLink = NULL;
	return pReturn;
}

DequeNode* deleteRearLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	if (pDeque->currentElementCount == 1) {
		return deleteLastNode(pDeque);
	}
	DequeNode* pReturn = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	pReturn->pLLink = NULL;
	return pReturn;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	return pDeque->pFrontNode;
}

DequeNode* peekRearLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	return pDeque->pRearNode;
}

void deleteLinkedDeque(LinkedDeque* pDeque) {
	while (isLinkedDequeEmpty(pDeque) == FALSE) {
		DequeNode *node = deleteFrontLD(pDeque);
		free(node);
		node = NULL;
	}
	free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque) {
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque) {
	if (pDeque->currentElementCount == 0) {
		return TRUE;
	}
	return FALSE;
}
