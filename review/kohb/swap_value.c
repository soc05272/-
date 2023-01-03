#include <stdio.h>

// call by value
void swap(int, int);

int main(void)
{
	int a=10, b=20;

	printf("before : a = %d, b = %d\n", a, b);
	swap(a,b);
	printf("after : a = %d, b = %d\n", a, b);

	return 0;
}

void swap(int a, int b)
{
	int temp;
	a = temp;
	temp = b;
	a = b;
}	
