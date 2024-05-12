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
	연결 리스트 m_pList
	연결 리스트의 마지막 노드에 대한 포인터 m_pLast;

public:
	생성자
	연산자  IsEmpty
	연산자  Add
	연산자  Delete
	연산자  Print
};

void Error(const char *sMsg);

[LinkedQueueCls.cpp]
#include "Queue.h"

int Queue::Add(Item nItem)
{	// queue에 nItem을 추가하고 성공하면 true 아니면 false를 반환한다.
	return true;
}

int Queue::Delete(Item& nItem)
{	//queue에서 삭제하여 nItem에 저장하고 성공하면 true 아니면 false를 반환한다.
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
