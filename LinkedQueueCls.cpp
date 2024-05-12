[LinkedQueueMn.cpp]
#include "Queue.h"

void main()
{
	Queue aQueue = Queue(), *pQueue = &aQueue;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, *:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		else if (value == -1) {
			if (pQueue->Delete(value))
				printf("%d is deleted\n", value);
			else
				Error("empty");
		}
		else {
			if (pQueue->Add(value))
				printf("%d is inserted\n", value);
			else
				Error("full");
		}
		pQueue->Print();
	}
}

void Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
}

[Queue.h]
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4326 4996)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr;

class Queue {
	���� ����Ʈ m_pList
	���� ����Ʈ�� ������ ��忡 ���� ������ m_pLast;

public:
	������
	������  IsEmpty
	������  Add
	������  Delete
	������  Print
};

void Error(const char *sMsg);

[LinkedQueueCls.cpp]
#include "Queue.h"

int Queue::Add(Item nItem)
{	// queue�� nItem�� �߰��ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	return true;
}

int Queue::Delete(Item& nItem)
{	//queue���� �����Ͽ� nItem�� �����ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	return true;
}

void Queue::Print()
{
	NodePtr pNode = m_pList;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n");
	pNode = m_pList;
	while (pNode) {
		printf("%4d", pNode->nData);
		pNode = pNode->link;
	}
	printf("\n");
	pNode = m_pList;
	while (pNode) {
		printf("----");
		pNode = pNode->link;
	}
	printf("--\n\n");
}
