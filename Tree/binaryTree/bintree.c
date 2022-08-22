#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"
#include "linkedstack.h"
#include "linkeddeque.h"

BinTree* makeBinTree(BinTreeNode rootNode) {
	BinTree* binTree = (BinTree*)calloc(1, sizeof(BinTree));
	binTree->pRootNode = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	*(binTree->pRootNode) = rootNode;
	return binTree;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
	return pBinTree == NULL ? NULL : pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	if (pParentNode == NULL)
		return NULL;
	BinTreeNode* pLeftChild = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	*pLeftChild = element;
	pParentNode->pLeftChild = pLeftChild;
	return pLeftChild;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	if (pParentNode == NULL)
		return NULL;
	BinTreeNode* pRightChild = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	*pRightChild = element;
	pParentNode->pRightChild = pRightChild;
	return pRightChild;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {
	return pNode == NULL ? NULL : pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {
	return pNode == NULL ? NULL : pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree) {
	if (pBinTree == NULL)
		return;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode) {
	if (pNode == NULL)
		return;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

void recursivePreorderTraverseBT(BinTreeNode* pNode, void (*f)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	f(pNode);
	recursivePreorderTraverseBT(pNode->pLeftChild, f);
	recursivePreorderTraverseBT(pNode->pRightChild, f);
}

void recursiveInorderTraverseBT(BinTreeNode* pNode, void (*f)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	recursiveInorderTraverseBT(pNode->pLeftChild, f);
	f(pNode);
	recursiveInorderTraverseBT(pNode->pRightChild, f);
}

void recursivePostorderTraverseBT(BinTreeNode* pNode, void (*f)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	recursivePostorderTraverseBT(pNode->pLeftChild, f);
	recursivePostorderTraverseBT(pNode->pRightChild, f);
	f(pNode);
}

void levelorderTraverseBT(BinTreeNode* pNode, void (*f)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	LinkedDeque *queue = createLinkedDeque();
	insertRearLD(queue, (DequeNode){pNode, NULL, NULL});
	while (!isLinkedDequeEmpty(queue)) {
		DequeNode *temp = deleteFrontLD(queue);
		BinTreeNode *node = temp->data;
		free(temp);
		f(node);
		if (node->pLeftChild != NULL)
			insertRearLD(queue, (DequeNode){node->pLeftChild, NULL, NULL});
		if (node->pRightChild != NULL)
			insertRearLD(queue, (DequeNode){node->pRightChild, NULL, NULL});
	}
	deleteLinkedDeque(queue);
}

//put alphabet 'A' to 'M' in BinTree
BinTree *AtoMTree(void) {
	BinTree *bintree = makeBinTree((BinTreeNode){'A', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getRootNodeBT(bintree), (BinTreeNode){'B', FALSE, NULL, NULL});
	insertRightChildNodeBT(getRootNodeBT(bintree), (BinTreeNode){'C', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getLeftChildNodeBT(getRootNodeBT(bintree)), (BinTreeNode){'D', FALSE, NULL, NULL});
	insertRightChildNodeBT(getLeftChildNodeBT(getRootNodeBT(bintree)), (BinTreeNode){'E', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree)), (BinTreeNode){'F', FALSE, NULL, NULL});
	insertRightChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree)), (BinTreeNode){'G', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getLeftChildNodeBT(getLeftChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'H', FALSE, NULL, NULL});
	insertRightChildNodeBT(getLeftChildNodeBT(getLeftChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'I', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getRightChildNodeBT(getLeftChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'J', FALSE, NULL, NULL});
	insertRightChildNodeBT(getLeftChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'K', FALSE, NULL, NULL});
	insertLeftChildNodeBT(getRightChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'L', FALSE, NULL, NULL});
	insertRightChildNodeBT(getRightChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree))), (BinTreeNode){'M', FALSE, NULL, NULL});
	insertRightChildNodeBT(getRightChildNodeBT(getRightChildNodeBT(getRightChildNodeBT(getRootNodeBT(bintree)))), (BinTreeNode){'N', FALSE, NULL, NULL});

	return bintree;
}

void printBinTreeNode(BinTreeNode* pNode) {
	if (pNode == NULL)
		return;
	printf("%c ", pNode->data);
}

int main(void)
{
	BinTree *binTree = AtoMTree();
	printf("Levelorder Traverse:\n");
	levelorderTraverseBT(getRootNodeBT(binTree), printBinTreeNode);
	printf("\n\n");
	printf("Preorder Traverse:\n");
	recursivePreorderTraverseBT(getRootNodeBT(binTree), printBinTreeNode);
	printf("\n\n");
	printf("Inorder Traverse:\n");
	recursiveInorderTraverseBT(getRootNodeBT(binTree), printBinTreeNode);
	printf("\n\n");
	printf("Postorder Traverse:\n");
	recursivePostorderTraverseBT(getRootNodeBT(binTree), printBinTreeNode);
	printf("\n\n");
	deleteBinTree(binTree);
	system("leaks binaryTree");
}
