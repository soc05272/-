#include <stdio.h>

void printStar(int); // 1. 부함수의 프로토타입 정의
int sum(int, int);

int main(void)
{
	int r;
	// 3. 부함수 호출
	printStar(5);
	sum(5, 10);
	r = sum(5, 10);
	printf("r = %d\n", r);
	
	return 0;
}

// 2. 부함수의 내용정의
void printStar(int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("*");
	}
	printf("\n");
}

int sum(int n, int m)
{
	return n+m;
}	
