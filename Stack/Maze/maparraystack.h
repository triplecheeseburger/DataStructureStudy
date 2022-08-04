#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include "mapdef.h"

typedef struct StackNodeType
{
	MapPosition mp;
} StackNode;

typedef struct ArrayStackType
{
	int top;
	int maxElementCount;
	int currentElementCount;	// ���� ������ ����
	StackNode* pElement;		// Top ����� ������
} ArrayStack;

ArrayStack* createArrayStack(int size);
int pushAS(ArrayStack* pStack, int x, int y);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif