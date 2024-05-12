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
