#include <stdio.h>

int main(void)
{
	float e[11] = {3.45,0,1,1.35,3.14,1.15,2.41,5.89,0.98,1.12};
	int i;

	for(i=0; i<10; i++)
	{
		printf("e[%d] = %f\n", i, e[i]);
	}

	return 0;
}
