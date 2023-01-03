#include <stdio.h>

int main(void)
{
	int a, b;

	int find_larger(int a, int b);

	printf("첫 번째 정수를 입력하시오 : ");
	scanf("%d", &a);

	printf("두번째 정수를 입려하시오 : ");
	scanf("%d" ,&b);

	printf("값 : %d\n", find_larger(a,b));

	return 0 ;
}

int find_larger(int a, int b)
{
	int larger;

	if (a > b)
	{
		larger = 1;
	}

	if (a < b)
	{
		larger = -1;
	}

	if (a == b)
	{
		larger = 0;
	}

	return larger;
}	
