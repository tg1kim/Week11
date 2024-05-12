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
	연결 리스트 m_pList

public:
	생성자
	연산자 IsEmpty
	연산자 Push
	연산자 Pop
	연산자 Print
};

void Error(const char *sMsg);

[LinkedStackCls.cpp]
#include "Stack.h"

int Stack::Push(Item nItem)
{	// stack에 nItem을 push하고 성공하면 true 아니면 false를 반환한다.
	return true;
}

int Stack::Pop(Item& nItem)
{	// stack에서 pop하여 nItem에 저장하고 성공하면 true 아니면 false를 반환한다.
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
