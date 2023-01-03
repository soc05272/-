#include <stdio.h>

int main(void)
{
	int s[5] = {10,20,30,40,50};
	int i;

	printf("s size : %ld\n", sizeof(s));
	s[4] = 100;

	for(i=0; i<5; i++)
	{
		s[i] = i+1;
		printf("s[%d] = %d\n", i, s[i]);
	}
	return 0;
}
