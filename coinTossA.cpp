// �Լ�

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
    int toss;
    int heads = 0;
    int tails = 0;
    srand((unsigned)time(NULL)); 
    for (toss = 0; toss < 100; toss++) {
	int coinToss(void);
        if (coinToss( ) == 1)
            heads++;
        else
            tails++;
    }
    printf( "������ �ո�: %d \n", heads );
    printf( "������ �޸�: %d \n", tails );
}

int coinToss(void)
{
    int i = rand() % 2;
    if (i == 0)
        return 0;
    else
        return 1;
}