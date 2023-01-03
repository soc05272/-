#include <stdio.h>

int main(void)
{
	char str[3][10];
	int i;
	
	for(i=0; i<3; i++)
	{
		printf("input str : ");
		scanf("%s", str[i]);
		printf("str %d==>%s\n", i+1, str[i]);
	
	}

	return 0;
}
