#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

double sub1(double d)
{
        sub2(100.0);
}

double sub2(double d)
{
        sub1(20.0);
}

void main()
{
	sub1(10.0);
}