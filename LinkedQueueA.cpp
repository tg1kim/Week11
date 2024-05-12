#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4326 4996 6001 6031)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr;

typedef struct {
	NodePtr pList;
	NodePtr pLast;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	//int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item& nItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.pList = NULL;
	while (1) {
		int aItem;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf("%d", &aItem);
		if (aItem < -1)
			break;
		else if (aItem == -1) {
			if (DeleteQueue(&aQueue, aItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", aItem);
		}
		else {
			if (AddQueue(&aQueue, aItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", aItem);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)
{
	return pQueue->pList == NULL;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{
	NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = NULL;
		if (pQueue->pList)
			pQueue->pLast->link = pNew;
		else
			pQueue->pList = pNew;
		pQueue->pLast = pNew;
	}
	return pNew != NULL;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{
	NodePtr pDel = NULL;
	if (!IsEmptyQueue(pQueue)) {
		pDel = pQueue->pList;
		nItem = pDel->nData;
		pQueue->pList = pDel->link;
		free(pDel);
	}
	return pDel != NULL;
}

void PrintQueue(QueuePtr pQueue)
{
	NodePtr pNode = pQueue->pList;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n");
	pNode = pQueue->pList;
	while (pNode) {
		printf("%4d", pNode->nData);
		pNode = pNode->link;
	}
	printf("\n");
	pNode = pQueue->pList;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
