#include "Stack.h"

int Stack::Push(Item nItem)
{
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = m_pList;
		m_pList = pNew;
	}
	return pNew != NULL;
}

int Stack::Pop(Item& nItem)
{
	NodePtr pDel = NULL;
	if (!IsEmpty()) {
		pDel = m_pList;
		nItem = pDel->nData;
		m_pList = pDel->link;
		delete pDel;
	}
	return pDel != NULL;
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
