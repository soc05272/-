#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr;
	int i;

	// ptr = (int *)malloc(100); 

	ptr  = (int *)malloc(sizeof(int)*100);

	for(i=0; i<10; i++)
	{
		//포인터 표현
		
		*(ptr + i) = (1 + i);
		
		//배열 표현

		ptr[i] = (1+i);
		
		printf("*(ptr+%d) = %d   ptr[%d] = %d\n", i, *(ptr + i), i,  ptr[i]);
	}

	return 0;
}
