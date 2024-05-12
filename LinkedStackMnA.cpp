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

