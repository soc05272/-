#include <stdio.h>

int main(void)
{
	char string[] = "Dreams come true!";
	char *ptr = string; // char *ptr = &string[0];

	printf("string: %s\n", string);
	printf("ptr: %s\n", ptr);
	
	printf("string[7]: %c\n", string[7]);
	printf("*(ptr+7): %c\n",  *(ptr+7));

	return 0;
}	
