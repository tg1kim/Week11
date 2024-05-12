#include "Queue.h"

int Queue::Add(Item nItem)
{
	NodePtr pNew = new Node;
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = NULL;
		if (m_pList)
			m_pLast->link = pNew;
		else
			m_pList = pNew;
		m_pLast = pNew;
	}
	return pNew != NULL;
}

int Queue::Delete(Item& nItem)
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
