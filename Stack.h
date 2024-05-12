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
	NodePtr m_pList;

public:
	Stack() { m_pList = NULL; };
	int  IsEmpty() { return m_pList == NULL; }
	int  Push(Item nItem);
	int  Pop(Item& nItem);
	void Print();
};

void Error(const char *sMsg);
