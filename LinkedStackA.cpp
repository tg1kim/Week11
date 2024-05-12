#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4326 4996 6001 6031)

typedef int Item;
typedef struct node {
	Item nData;
	struct node *link;
}	Node, *NodePtr, *StackPtr;

void main()
{
	int  IsEmptyStack(StackPtr pStack);
	// int  IsFullStack(StackPtr pStack);
	int  Push(StackPtr& pStack, Item nItem);
	int  Pop(StackPtr& pStack, Item& nItem);
	void PrintStack(StackPtr pStack);
	int  Error(const char *sMsg);

	/** Create Stack **/
	StackPtr pStack = NULL;
	while (1) {
		Item aItem;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &aItem);
		if (aItem < -1)
			break;
		else if (aItem == -1) {
			if (Pop(pStack, aItem) == false)
				Error("empty");
			else
				printf("%d is deleted\n", aItem);
		}
		else {
			if (Push(pStack, aItem) == false)
				Error("full");
			else
				printf("%d is inserted\n", aItem);
		}
		PrintStack(pStack);
	}
}

int IsEmptyStack(StackPtr pStack)
{
	return pStack == NULL;
}

int Push(StackPtr& pStack, Item nItem)
{
	NodePtr pNew = (NodePtr)malloc(sizeof(Node));
	if (pNew) {
		pNew->nData = nItem;
		pNew->link = pStack;
		pStack = pNew;
	}
	return pNew != NULL;
}

int Pop(StackPtr& pStack, Item& nItem)
{
	NodePtr pDel = NULL;
	if (!IsEmptyStack(pStack)) {
		pDel = pStack;
		nItem = pDel->nData;
		pStack = pStack->link;
		free(pDel);
	}
	return pDel != NULL;
}

void PrintStack(StackPtr pNode)
{
	printf("|    |\n");
	while (pNode) {
		printf("|%3d |\n", pNode->nData);
		pNode = pNode->link;
	}
	printf("+----+\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
