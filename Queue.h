#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4326 4996 6001 6031)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr;

class Queue {
	NodePtr m_pList;
	NodePtr m_pLast;

public:
	Queue(){ m_pList = NULL; };
	int  IsEmpty() { return m_pList == NULL; }
	int  Add(Item nItem);
	int  Delete(Item& nItem);
	void Print();
};

void Error(const char *sMsg);
