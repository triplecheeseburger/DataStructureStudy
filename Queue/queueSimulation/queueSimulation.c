#include "queueSimulation.h"
#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>


void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
	DequeNode element;

	element.data.status = arrival;
	element.data.arrivalTime = arrivalTime;
	element.data.serviceTime = processTime;
	element.data.startTime = 0;
	element.data.endTime = 0;
	insertRearLD(pQueue, element);
}

void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
	if (!isLinkedDequeEmpty(pArrivalQueue) && peekFrontLD(pArrivalQueue)->data.arrivalTime <= currentTime)
	{
		insertCutomer(peekFrontLD(pArrivalQueue)->data.arrivalTime, peekFrontLD(pArrivalQueue)->data.serviceTime,
					  pWaitQueue);
		deleteFrontLD(pArrivalQueue);
	}
}

DequeNode *processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
	if (!isLinkedDequeEmpty(pWaitQueue))
	{
		DequeNode *pServiceNode = deleteFrontLD(pWaitQueue);
		pServiceNode->data.startTime = currentTime;
		pServiceNode->data.status = start;
		return pServiceNode;
	}
	return NULL;
}

DequeNode *processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode != NULL)
	{
		pServiceNode->data.endTime = currentTime;
		pServiceNode->data.status = end;
		(*pServiceUserCount)++;
		(*pTotalWaitTime) += pServiceNode->data.serviceTime;
		return pServiceNode;
	}
	return NULL;
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("======Customer======\n");
	if (customer.status == arrival)
		printf("Status : Arrival\n");
	else if (customer.status == start)
		printf("Status : Start\n");
	else if (customer.status == end)
		printf("Status : End\n");
	printf("arrivalTime : %d\n", customer.arrivalTime);
	printf("serviceTime : %d\n", customer.serviceTime);
	printf("startTime : %d\n", customer.startTime);
	printf("endTime : %d\n", customer.endTime);
	printf("====================\n");
}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
	printf("======WaitQueue======\n");
	printf("currentTime : %d\n", currentTime);
	printf("WaitQueue : ");
	if (isLinkedDequeEmpty(pWaitQueue))
		printf("Empty\n");
	else
	{
		DequeNode *pNode = pWaitQueue->pFrontNode;
		while (pNode != NULL)
		{
			printSimCustomer(currentTime, pNode->data);
			pNode = pNode->pRLink;
		}
		printf("\n");
	}
	printf("====================\n");
}

void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("======Report======\n");
	printWaitQueueStatus(0, pWaitQueue);
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("totalWaitTime : %d\n", totalWaitTime);
	printf("====================\n");
}

int simulation(void)
{
	int currentTime = 0;
	int serviceUserCount = 0;
	int totalWaitTime = 0;
	LinkedDeque *pArrivalQueue = createLinkedDeque();
	LinkedDeque *pWaitQueue = createLinkedDeque();
	DequeNode *pServiceNode = NULL;

	insertCutomer(0, 1, pArrivalQueue);
	insertCutomer(1, 2, pArrivalQueue);
	insertCutomer(2, 3, pArrivalQueue);
	insertCutomer(3, 4, pArrivalQueue);
	insertCutomer(4, 5, pArrivalQueue);
	insertCutomer(5, 6, pArrivalQueue);
	insertCutomer(6, 1, pArrivalQueue);
	insertCutomer(7, 2, pArrivalQueue);
	insertCutomer(8, 3, pArrivalQueue);
	insertCutomer(9, 4, pArrivalQueue);

	while (!isLinkedDequeEmpty(pArrivalQueue) || !isLinkedDequeEmpty(pWaitQueue) || pServiceNode != NULL)
	{
		processArrival(currentTime, pArrivalQueue, pWaitQueue);
		if (pServiceNode != NULL && currentTime - pServiceNode->data.startTime >= pServiceNode->data.serviceTime) {
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
			printSimCustomer(currentTime, pServiceNode->data);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (pServiceNode == NULL) {
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
			if (pServiceNode != NULL) {
				printf("======ServiceNode======\n");
				printSimCustomer(currentTime, pServiceNode->data);
				printf("====================\n");
			}
			if (pServiceNode == NULL) {
				printReport(pWaitQueue, serviceUserCount, totalWaitTime);
				break ;
			}
		}
		currentTime++;
		printf("CurrentTime: %d\n", currentTime);
	}

	return 0;
}

int main(void) {
	simulation();
	return 0;
}