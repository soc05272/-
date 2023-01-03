#include <stdio.h>

int main(void)
{
	double d1 = 20.1, d2 = 30.1;

	double *ptr1 = &d1;
	double *ptr2 = &d2;

	printf("d1 : %lf\n", *ptr1);
	printf("d2 : %lf\n", *ptr2);

	printf("d1의 주소 : %p\n", ptr1);
	printf("d2의 주소 : %p\n", ptr2);

	printf("ptr1의 주소 : %p\n", &ptr1);
	printf("ptr2의 주소 : %p\n", &ptr2);

	return 0;
}	
