#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

getInteger
{
	"정수를 입력하시오: "
	value에 입력
	value를 반환한다
}

두 수를 더 하는 함수 add
{
	두 수의 합을 반환한다
}

void main() 
{
	x에 getInteger가 반환한 값을 저장한다
	y에 getInteger가 반환한 값을 저장한다
	sum에 함수 add가 반환한 값을 저장한다
	"두수의 합은 %d입니다.\n"
}