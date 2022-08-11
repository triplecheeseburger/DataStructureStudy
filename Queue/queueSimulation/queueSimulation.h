#ifndef QUEUESIMULATION_H
#define QUEUESIMULATION_H

typedef struct LinkedDequeType LinkedDeque;
typedef struct DequeNodeType DequeNode;
typedef enum SimStatusType { arrival, start, end } SimStatus;
typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
} SimCustomer;

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue);
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue);
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif
