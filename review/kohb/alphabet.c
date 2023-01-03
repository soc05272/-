#include <stdio.h>

int main(void)
{
	char s[10] = {"ABCDEFGHIJ"};
	int i;

	printf("s size : %ld\n", sizeof(s));

	for(i=0; i<10; i++)
	{
		printf("s[%d] = %c\n", i, s[i]);
	}

	return 0;
}
