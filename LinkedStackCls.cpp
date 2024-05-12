[LinkedStackMn.cpp]
#include "Stack.h"

void main()
{
	Stack aStack = Stack(), *pStack = &aStack;
	while (1) {
		Item aItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &aItem);
		if (aItem < -1)
			break;
		else if (aItem == -1) {
			if (pStack->Pop(aItem))
				printf("%d is deleted\n", aItem);
			else
				Error("empty");
		}
		else {
			if (pStack->Push(aItem))
				printf("%d is inserted\n", aItem);
			else
				Error("full");
		}
		pStack->Print();
	}
	printf("Bye, ...\n");
}

void Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
}

[Stack.h]
#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4326 4996 6001 6031)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr;

class Stack {
	���� ����Ʈ m_pList

public:
	������
	������ IsEmpty
	������ Push
	������ Pop
	������ Print
};

void Error(const char *sMsg);

[LinkedStackCls.cpp]
#include "Stack.h"

int Stack::Push(Item nItem)
{	// stack�� nItem�� push�ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	return true;
}

int Stack::Pop(Item& nItem)
{	// stack���� pop�Ͽ� nItem�� �����ϰ� �����ϸ� true �ƴϸ� false�� ��ȯ�Ѵ�.
	return true;
}

void Stack::Print()
{
	NodePtr pNode = m_pList;
	printf("|    |\n");
	while (pNode) {
		printf("|%3d |\n", pNode->nData);
		pNode = pNode->link;
	}
	printf("+----+\n\n");
}
