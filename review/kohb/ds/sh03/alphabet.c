#include <stdio.h>

int main(void)
{
	char s[11] = {"ABCDEFGHIJ"};
	int i;

	for(i=0; i<11; i++)
 	{
		printf("s[%d] = %c\n", i, s[i]);
	}
	
	return 0;

}
		
